
#include <stdint.h>
#include <windows.h>
#include <strsafe.h>
#include "general-types.h"
#include "parser-base.h"
#include "mouse-parser.h"



#define IRP_MJ_READ					0x03


typedef struct _MOUSE_INPUT_DATA {
	USHORT UnitId;
	USHORT Flags;
	union {
		ULONG Buttons;
		struct {
			USHORT  ButtonFlags;
			USHORT  ButtonData;
		};
	};
	ULONG RawButtons;
	LONG LastX;
	LONG LastY;
	ULONG ExtraInformation;
} MOUSE_INPUT_DATA, *PMOUSE_INPUT_DATA;


#define MOUSE_LEFT_BUTTON_DOWN   0x0001  // Left Button changed to down.
#define MOUSE_LEFT_BUTTON_UP     0x0002  // Left Button changed to up.
#define MOUSE_RIGHT_BUTTON_DOWN  0x0004  // Right Button changed to down.
#define MOUSE_RIGHT_BUTTON_UP    0x0008  // Right Button changed to up.
#define MOUSE_MIDDLE_BUTTON_DOWN 0x0010  // Middle Button changed to down.
#define MOUSE_MIDDLE_BUTTON_UP   0x0020  // Middle Button changed to up.

#define MOUSE_BUTTON_1_DOWN     MOUSE_LEFT_BUTTON_DOWN
#define MOUSE_BUTTON_1_UP       MOUSE_LEFT_BUTTON_UP
#define MOUSE_BUTTON_2_DOWN     MOUSE_RIGHT_BUTTON_DOWN
#define MOUSE_BUTTON_2_UP       MOUSE_RIGHT_BUTTON_UP
#define MOUSE_BUTTON_3_DOWN     MOUSE_MIDDLE_BUTTON_DOWN
#define MOUSE_BUTTON_3_UP       MOUSE_MIDDLE_BUTTON_UP

#define MOUSE_BUTTON_4_DOWN     0x0040
#define MOUSE_BUTTON_4_UP       0x0080
#define MOUSE_BUTTON_5_DOWN     0x0100
#define MOUSE_BUTTON_5_UP       0x0200

#define MOUSE_WHEEL             0x0400
#define MOUSE_HWHEEL			0x0800

#define MOUSE_MOVE_RELATIVE         0
#define MOUSE_MOVE_ABSOLUTE         1
#define MOUSE_VIRTUAL_DESKTOP    0x02  // the coordinates are mapped to the virtual desktop
#define MOUSE_ATTRIBUTES_CHANGED 0x04  // requery for mouse attributes
#define MOUSE_MOVE_NOCOALESCE    0x08  // do not coalesce WM_MOUSEMOVEs
#define MOUSE_TERMSRV_SRC_SHADOW 0x100




static BOOLEAN _hideZeroValues = TRUE;



static DWORD cdecl _ParseRoutine(const REQUEST_HEADER *Request, const DP_REQUEST_EXTRA_INFO *ExtraInfo, PBOOLEAN Handled, wchar_t ***Names, wchar_t ***Values, size_t *RowCount)
{
	NV_PAIR p;
	const wchar_t *driverName = L"\\Driver\\mouclass";
	const wchar_t *deviceName = L"\\Device\\PointerdClass0";
	DWORD ret = ERROR_GEN_FAILURE;
	const REQUEST_IRP_COMPLETION *irpComp = NULL;
	const MOUSE_INPUT_DATA *mouInput = NULL;
	size_t inputCount = 0;
	uint32_t flagBits[] = {
		MOUSE_MOVE_ABSOLUTE,
		MOUSE_VIRTUAL_DESKTOP, 
		MOUSE_ATTRIBUTES_CHANGED,
		MOUSE_MOVE_NOCOALESCE,
		MOUSE_TERMSRV_SRC_SHADOW,
	};
	const wchar_t *flagNames[] = {
		L"    Absolute position",
		L"    Virtual desktop",
		L"    Attributes changed",
		L"    No move colesce",
		L"    Source shadow",
	};
	uint32_t buttonBits[] = {
		MOUSE_LEFT_BUTTON_DOWN,
		MOUSE_LEFT_BUTTON_UP,
		MOUSE_RIGHT_BUTTON_DOWN,
		MOUSE_RIGHT_BUTTON_UP,
		MOUSE_MIDDLE_BUTTON_DOWN,
		MOUSE_MIDDLE_BUTTON_UP,
		MOUSE_BUTTON_4_DOWN,     
		MOUSE_BUTTON_4_UP,       
		MOUSE_BUTTON_5_DOWN,     
		MOUSE_BUTTON_5_UP,       
		MOUSE_WHEEL,             
		MOUSE_HWHEEL,			
	};
	const wchar_t *buttonNames[] = {
		L"    Left down",
		L"    Left up",
		L"    Right down",
		L"    Right up",
		L"    Middle down",
		L"    Middle up",
		L"    #4 down",
		L"    #4 up",
		L"    #5 down",
		L"    #5 up",
		L"    V wheel",
		L"    H wheel",
	};

	ret = ERROR_SUCCESS;
	if (Request->Type == ertIRPCompletion) {
		irpComp = CONTAINING_RECORD(Request, REQUEST_IRP_COMPLETION, Header);
		if (irpComp->MajorFunction == IRP_MJ_READ &&
			irpComp->DataSize > 0 &&
			ExtraInfo->DriverName != NULL && _wcsicmp(ExtraInfo->DriverName, driverName) == 0 &&
			ExtraInfo->DeviceName != NULL && wcslen(ExtraInfo->DeviceName) > wcslen(deviceName) &&
			memcmp(ExtraInfo->DeviceName, deviceName, wcslen(deviceName) * sizeof(wchar_t)) == 0) {
			mouInput = (MOUSE_INPUT_DATA *)(irpComp + 1);
			inputCount = irpComp->DataSize / sizeof(MOUSE_INPUT_DATA);
		}
	}

	if (mouInput != NULL) {
		memset(&p, 0, sizeof(p));
		for (size_t i = 0; i < inputCount; ++i) {
			ret = PBaseAddNameFormat(&p, L"Record ", L"%zu", i);
			if (ret == ERROR_SUCCESS)
				ret = PBaseAddNameFormat(&p, L"  Device", L"%u", mouInput->UnitId);

			if (ret == ERROR_SUCCESS && (!_hideZeroValues || mouInput->Flags))
				ret = PBaseAddNameFormat(&p, L"  Flags", L"0x%x", mouInput->Flags);

			if (ret == ERROR_SUCCESS)
				ret = PBaseAddFlags(&p, mouInput->Flags, flagBits, flagNames, sizeof(flagBits) / sizeof(flagBits[0]), _hideZeroValues);

			if (ret == ERROR_SUCCESS && (!_hideZeroValues || mouInput->Flags))
				ret = PBaseAddNameFormat(&p, L"  Buttons", L"0x%x", mouInput->ButtonFlags);

			if (ret == ERROR_SUCCESS)
				ret = PBaseAddFlags(&p, mouInput->ButtonFlags, buttonBits, buttonNames, sizeof(buttonBits) / sizeof(buttonBits[0]), _hideZeroValues);

			if (ret == ERROR_SUCCESS && (!_hideZeroValues || mouInput->ButtonData != 0))
				ret = PBaseAddNameFormat(&p, L"  Wheel data", L"0x%x", mouInput->ButtonData);

			if (ret == ERROR_SUCCESS && (!_hideZeroValues || mouInput->RawButtons != 0))
				ret = PBaseAddNameFormat(&p, L"  Raw buttons", L"0x%x", mouInput->RawButtons);

			if (ret == ERROR_SUCCESS)
				ret = PBaseAddNameFormat(&p, L"  X", L"%i", mouInput->LastX);

			if (ret == ERROR_SUCCESS)
				ret = PBaseAddNameFormat(&p, L"  Y", L"%i", mouInput->LastY);
					
			if (ret == ERROR_SUCCESS && (!_hideZeroValues || mouInput->ExtraInformation != 0))
				ret = PBaseAddNameFormat(&p, L"  Extra", L"0x%x", mouInput->ExtraInformation);

			if (ret != ERROR_SUCCESS)
				break;

			++mouInput;
		}

		if (ret == ERROR_SUCCESS) {
			*Handled = TRUE;
			*RowCount = p.Count;
			*Names = p.Names;
			*Values = p.Values;
		}

		if (ret != ERROR_SUCCESS) {
			for (size_t i = 0; i < p.Count; ++i)
				HeapFree(GetProcessHeap(), 0, p.Names[i]);

			HeapFree(GetProcessHeap(), 0, p.Names);
		}
	}
	else {
		*Names = NULL;
		*Values = NULL;
		*RowCount = 0;
		*Handled = FALSE;
	}

	return ret;
}


static void cdecl _FreeRoutine(wchar_t **Names, wchar_t **Values, size_t Count)
{
	PBaseFreeNameValue(Names, Values, Count);

	return;
}


DWORD cdecl DP_INIT_ROUTINE_NAME(uint32_t RequestedVersion, PIRPMON_DATA_PARSER *Parser)
{
	DWORD ret = ERROR_GEN_FAILURE;
	PIRPMON_DATA_PARSER tmpParser = NULL;

	ret = ERROR_SUCCESS;
	if (RequestedVersion >= IRPMON_DATA_PARSER_VERSION_1) {
		ret = PBaseDataParserAlloc(IRPMON_DATA_PARSER_VERSION_1, &tmpParser);
		if (ret == ERROR_SUCCESS) {
			tmpParser->MajorVersion = 1;
			tmpParser->MinorVersion = 0;
			tmpParser->BuildVersion = 0;
			tmpParser->Name = L"MouClass";
			tmpParser->Description = L"MOUSE_INPUT_DATA structure parsing";
			tmpParser->Priority = 1;
			tmpParser->ParseRoutine = _ParseRoutine;
			tmpParser->FreeRoutine = _FreeRoutine;
			*Parser = tmpParser;
		}
	} else ret = ERROR_NOT_SUPPORTED;

	return ret;
}
