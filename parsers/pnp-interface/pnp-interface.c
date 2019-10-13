
#include <stdint.h>
#include <windows.h>
#include <strsafe.h>
#include <initguid.h>
#include "general-types.h"
#include "pnp-interface.h"



#define IRP_MJ_PNP					0x1b
#define IRP_MN_QUERY_INTERFACE		0x08

typedef struct _PNP_INTERFACE {
	USHORT Size;
	USHORT Version;
	PVOID Context;
	PVOID InterfaceReference;
	PVOID InterfaceDereference;
} PNP_INTERFACE, *PPNP_INTERFACE;

DEFINE_GUID(GUID_BUS_INTERFACE_STANDARD, 0x496B8280L, 0x6F25, 0x11D0, 0xBE, 0xAF, 0x08, 0x00, 0x2B, 0xE2, 0x09, 0x2F);
DEFINE_GUID(GUID_PCI_BUS_INTERFACE_STANDARD, 0x496B8281L, 0x6F25, 0x11D0, 0xBE, 0xAF, 0x08, 0x00, 0x2B, 0xE2, 0x09, 0x2F);
DEFINE_GUID(GUID_PCI_BUS_INTERFACE_STANDARD2, 0xde94e966L, 0xfdff, 0x4c9c, 0x99, 0x98, 0x67, 0x47, 0xb1, 0x50, 0xe7, 0x4c);
DEFINE_GUID(GUID_ARBITER_INTERFACE_STANDARD, 0xe644f185L, 0x8c0e, 0x11d0, 0xbe, 0xcf, 0x08, 0x00, 0x2b, 0xe2, 0x09, 0x2f);
DEFINE_GUID(GUID_TRANSLATOR_INTERFACE_STANDARD, 0x6c154a92L, 0xaacf, 0x11d0, 0x8d, 0x2a, 0x00, 0xa0, 0xc9, 0x06, 0xb2, 0x44);
DEFINE_GUID(GUID_ACPI_INTERFACE_STANDARD, 0xb091a08aL, 0xba97, 0x11d0, 0xbd, 0x14, 0x00, 0xaa, 0x00, 0xb7, 0xb3, 0x2a);
DEFINE_GUID(GUID_INT_ROUTE_INTERFACE_STANDARD, 0x70941bf4L, 0x0073, 0x11d1, 0xa0, 0x9e, 0x00, 0xc0, 0x4f, 0xc3, 0x40, 0xb1);
DEFINE_GUID(GUID_PCMCIA_BUS_INTERFACE_STANDARD, 0x76173af0L, 0xc504, 0x11d1, 0x94, 0x7f, 0x00, 0xc0, 0x4f, 0xb9, 0x60, 0xee);
DEFINE_GUID(GUID_ACPI_REGS_INTERFACE_STANDARD, 0x06141966L, 0x7245, 0x6369, 0x46, 0x2e, 0x4e, 0x65, 0x6c, 0x73, 0x6f, 0x6e);
DEFINE_GUID(GUID_LEGACY_DEVICE_DETECTION_STANDARD, 0x50feb0deL, 0x596a, 0x11d2, 0xa5, 0xb8, 0x00, 0x00, 0xf8, 0x1a, 0x46, 0x19);
DEFINE_GUID(GUID_PCI_DEVICE_PRESENT_INTERFACE, 0xd1b82c26L, 0xbf49, 0x45ef, 0xb2, 0x16, 0x71, 0xcb, 0xd7, 0x88, 0x9b, 0x57);
DEFINE_GUID(GUID_MF_ENUMERATION_INTERFACE, 0xaeb895f0L, 0x5586, 0x11d1, 0x8d, 0x84, 0x00, 0xa0, 0xc9, 0x06, 0xb2, 0x44);
DEFINE_GUID(GUID_REENUMERATE_SELF_INTERFACE_STANDARD, 0x2aeb0243, 0x6a6e, 0x486b, 0x82, 0xfc, 0xd8, 0x15, 0xf6, 0xb9, 0x70, 0x06);
DEFINE_GUID(GUID_AGP_TARGET_BUS_INTERFACE_STANDARD, 0xB15CFCE8L, 0x06D1, 0x4D37, 0x9D, 0x4C, 0xBE, 0xDD, 0xE0, 0xC2, 0xA6, 0xFF);
DEFINE_GUID(GUID_ACPI_CMOS_INTERFACE_STANDARD, 0x3a8d0384L, 0x6505, 0x40ca, 0xbc, 0x39, 0x56, 0xc1, 0x5f, 0x8c, 0x5f, 0xed);
DEFINE_GUID(GUID_ACPI_PORT_RANGES_INTERFACE_STANDARD, 0xf14f609bL, 0xcbbd, 0x4957, 0xa6, 0x74, 0xbc, 0x0, 0x21, 0x3f, 0x1c, 0x97);
DEFINE_GUID(GUID_ACPI_INTERFACE_STANDARD2, 0xe8695f63L, 0x1831, 0x4870, 0xa8, 0xcf, 0x9c, 0x2f, 0x03, 0xf9, 0xdc, 0xb5);
DEFINE_GUID(GUID_PNP_LOCATION_INTERFACE, 0x70211b0e, 0x0afb, 0x47db, 0xaf, 0xc1, 0x41, 0x0b, 0xf8, 0x42, 0x49, 0x7a);
DEFINE_GUID(GUID_PCI_EXPRESS_LINK_QUIESCENT_INTERFACE, 0x146cd41cL, 0xdae3, 0x4437, 0x8a, 0xff, 0x2a, 0xf3, 0xf0, 0x38, 0x09, 0x9b);
DEFINE_GUID(GUID_PCI_EXPRESS_ROOT_PORT_INTERFACE, 0x83a7734aL, 0x84c7, 0x4161, 0x9a, 0x98, 0x60, 0x00, 0xed, 0x0c, 0x4a, 0x33);
DEFINE_GUID(GUID_MSIX_TABLE_CONFIG_INTERFACE, 0x1a6a460b, 0x194f, 0x455d, 0xb3, 0x4b, 0xb8, 0x4c, 0x5b, 0x05, 0x71, 0x2b);
DEFINE_GUID(GUID_D3COLD_SUPPORT_INTERFACE, 0xb38290e5, 0x3cd0, 0x4f9d, 0x99, 0x37, 0xf5, 0xfe, 0x2b, 0x44, 0xd4, 0x7a);
DEFINE_GUID(GUID_PROCESSOR_PCC_INTERFACE_STANDARD, 0x37b17e9a, 0xc21c, 0x4296, 0x97, 0x2d, 0x11, 0xc4, 0xb3, 0x2b, 0x28, 0xf0);
DEFINE_GUID(GUID_PCI_VIRTUALIZATION_INTERFACE, 0x64897b47, 0x3a4a, 0x4d75, 0xbc, 0x74, 0x89, 0xdd, 0x6c, 0x7, 0x82, 0x93);
DEFINE_GUID(GUID_PCC_INTERFACE_STANDARD, 0x3ee8ba63, 0x0f59, 0x4a24, 0x8a, 0x45, 0x35, 0x80, 0x8b, 0xdd, 0x12, 0x49);
DEFINE_GUID(GUID_PCC_INTERFACE_INTERNAL, 0x7cce62ce, 0xc189, 0x4814, 0xa6, 0xa7, 0x12, 0x11, 0x20, 0x89, 0xe9, 0x38);
DEFINE_GUID(GUID_THERMAL_COOLING_INTERFACE, 0xecbe47a8L, 0xc498, 0x4bb9, 0xbd, 0x70, 0xe8, 0x67, 0xe0, 0x94, 0x0d, 0x22);
DEFINE_GUID(GUID_DMA_CACHE_COHERENCY_INTERFACE, 0xb520f7fa, 0x8a5a, 0x4e40, 0xa3, 0xf6, 0x6b, 0xe1, 0xe1, 0x62, 0xd9, 0x35);
DEFINE_GUID(GUID_DEVICE_RESET_INTERFACE_STANDARD, 0x649fdf26, 0x3bc0, 0x4813, 0xad, 0x24, 0x7e, 0xc, 0x1e, 0xda, 0x3f, 0xa3);
DEFINE_GUID(GUID_IOMMU_BUS_INTERFACE, 0x1efee0b2, 0xd278, 0x4ae4, 0xbd, 0xdc, 0x1b, 0x34, 0xdd, 0x64, 0x80, 0x43);
DEFINE_GUID(GUID_PCI_SECURITY_INTERFACE, 0x6e7f1451, 0x199e, 0x4acc, 0xba, 0x2d, 0x76, 0x2b, 0x4e, 0xdf, 0x46, 0x74);
DEFINE_GUID(GUID_SCM_BUS_INTERFACE, 0x25944783, 0xce79, 0x4232, 0x81, 0x5e, 0x4a, 0x30, 0x1, 0x4e, 0x8e, 0xb4);
DEFINE_GUID(GUID_SECURE_DRIVER_INTERFACE, 0x370f67e1, 0x4ff5, 0x4a94, 0x9a, 0x35, 0x6, 0xc5, 0xd9, 0xcc, 0x30, 0xe2);
DEFINE_GUID(GUID_SCM_BUS_NVD_INTERFACE, 0x8de064ff, 0xb630, 0x42e4, 0x88, 0xea, 0x6f, 0x24, 0xc8, 0x64, 0x11, 0x75);
DEFINE_GUID(GUID_SCM_BUS_LD_INTERFACE, 0x9b89307d, 0xd76b, 0x4f48, 0xb1, 0x86, 0x54, 0x4, 0x1a, 0xe9, 0x2e, 0x8d);
DEFINE_GUID(GUID_SCM_PHYSICAL_NVDIMM_INTERFACE, 0x79c21b, 0x917e, 0x405e, 0xa9, 0xce, 0x7, 0x32, 0xb5, 0xbb, 0xce, 0xbd);
DEFINE_GUID(GUID_PNP_EXTENDED_ADDRESS_INTERFACE, 0xb8e992ec, 0xa797, 0x4dc4, 0x88, 0x46, 0x84, 0xd0, 0x41, 0x70, 0x74, 0x46);
DEFINE_GUID(USB_BUS_INTERFACE_USBDI_GUID, 0xb1a96a13, 0x3de0, 0x4574, 0x9b, 0x1, 0xc0, 0x8f, 0xea, 0xb3, 0x18, 0xd6);


typedef struct _INTERFACE_TABLE_ENTRY {
	const GUID *InterfaceGuid;
	const wchar_t *Name;
} INTERFACE_TABLE_ENTRY, *PINTERFACE_TABLE_ENTRY;

static INTERFACE_TABLE_ENTRY _interfaceTable[] = {
	{&GUID_BUS_INTERFACE_STANDARD, L"GUID_BUS_INTERFACE_STANDARD"},
	{&GUID_PCI_BUS_INTERFACE_STANDARD, L"GUID_PCI_BUS_INTERFACE_STANDARD"},
	{&GUID_PCI_BUS_INTERFACE_STANDARD2, L"GUID_PCI_BUS_INTERFACE_STANDARD2"},
	{&GUID_ARBITER_INTERFACE_STANDARD, L"GUID_ARBITER_INTERFACE_STANDARD"},
	{&GUID_TRANSLATOR_INTERFACE_STANDARD, L"GUID_TRANSLATOR_INTERFACE_STANDARD"},
	{&GUID_ACPI_INTERFACE_STANDARD, L"GUID_ACPI_INTERFACE_STANDARD"},
	{&GUID_INT_ROUTE_INTERFACE_STANDARD, L"GUID_INT_ROUTE_INTERFACE_STANDARD"},
	{&GUID_PCMCIA_BUS_INTERFACE_STANDARD, L"GUID_PCMCIA_BUS_INTERFACE_STANDARD"},
	{&GUID_ACPI_REGS_INTERFACE_STANDARD, L"GUID_ACPI_REGS_INTERFACE_STANDARD"},
	{&GUID_LEGACY_DEVICE_DETECTION_STANDARD, L"GUID_LEGACY_DEVICE_DETECTION_STANDARD"},
	{&GUID_PCI_DEVICE_PRESENT_INTERFACE, L"GUID_PCI_DEVICE_PRESENT_INTERFACE"},
	{&GUID_MF_ENUMERATION_INTERFACE, L"GUID_MF_ENUMERATION_INTERFACE"},
	{&GUID_REENUMERATE_SELF_INTERFACE_STANDARD, L"GUID_REENUMERATE_SELF_INTERFACE_STANDARD"},
	{&GUID_AGP_TARGET_BUS_INTERFACE_STANDARD, L"GUID_AGP_TARGET_BUS_INTERFACE_STANDARD"},
	{&GUID_ACPI_CMOS_INTERFACE_STANDARD, L"GUID_ACPI_CMOS_INTERFACE_STANDARD"},
	{&GUID_ACPI_PORT_RANGES_INTERFACE_STANDARD, L"GUID_ACPI_PORT_RANGES_INTERFACE_STANDARD"},
	{&GUID_ACPI_INTERFACE_STANDARD2, L"GUID_ACPI_INTERFACE_STANDARD2"},
	{&GUID_PNP_LOCATION_INTERFACE, L"GUID_PNP_LOCATION_INTERFACE"},
	{&GUID_PCI_EXPRESS_LINK_QUIESCENT_INTERFACE, L"GUID_PCI_EXPRESS_LINK_QUIESCENT_INTERFACE"},
	{&GUID_PCI_EXPRESS_ROOT_PORT_INTERFACE, L"GUID_PCI_EXPRESS_ROOT_PORT_INTERFACE"},
	{&GUID_MSIX_TABLE_CONFIG_INTERFACE, L"GUID_MSIX_TABLE_CONFIG_INTERFACE"},
	{&GUID_D3COLD_SUPPORT_INTERFACE, L"GUID_D3COLD_SUPPORT_INTERFACE"},
	{&GUID_PROCESSOR_PCC_INTERFACE_STANDARD, L"GUID_PROCESSOR_PCC_INTERFACE_STANDARD"},
	{&GUID_PCI_VIRTUALIZATION_INTERFACE, L"GUID_PCI_VIRTUALIZATION_INTERFACE"},
	{&GUID_PCC_INTERFACE_STANDARD, L"GUID_PCC_INTERFACE_STANDARD"},
	{&GUID_PCC_INTERFACE_INTERNAL, L"GUID_PCC_INTERFACE_INTERNAL"},
	{&GUID_THERMAL_COOLING_INTERFACE, L"GUID_THERMAL_COOLING_INTERFACE"},
	{&GUID_DMA_CACHE_COHERENCY_INTERFACE, L"GUID_DMA_CACHE_COHERENCY_INTERFACE"},
	{&GUID_DEVICE_RESET_INTERFACE_STANDARD, L"GUID_DEVICE_RESET_INTERFACE_STANDARD"},
	{&GUID_IOMMU_BUS_INTERFACE, L"GUID_IOMMU_BUS_INTERFACE"},
	{&GUID_PCI_SECURITY_INTERFACE, L"GUID_PCI_SECURITY_INTERFACE"},
	{&GUID_SCM_BUS_INTERFACE, L"GUID_SCM_BUS_INTERFACE"},
	{&GUID_SECURE_DRIVER_INTERFACE, L"GUID_SECURE_DRIVER_INTERFACE"},
	{&GUID_SCM_BUS_NVD_INTERFACE, L"GUID_SCM_BUS_NVD_INTERFACE"},
	{&GUID_SCM_BUS_LD_INTERFACE, L"GUID_SCM_BUS_LD_INTERFACE"},
	{&GUID_SCM_PHYSICAL_NVDIMM_INTERFACE, L"GUID_SCM_PHYSICAL_NVDIMM_INTERFACE"},
	{&GUID_PNP_EXTENDED_ADDRESS_INTERFACE, L"GUID_PNP_EXTENDED_ADDRESS_INTERFACE"},
	{&USB_BUS_INTERFACE_USBDI_GUID, L"USB_BUS_INTERFACE_USBDI"},
};



typedef struct _NV_PAIR {
	wchar_t **Names;
	wchar_t **Values;
	size_t Count;
} NV_PAIR, *PNV_PAIR;


static DWORD _AddNameValue(PNV_PAIR Pair, const wchar_t *Name, const wchar_t *Value)
{
	DWORD ret = ERROR_GEN_FAILURE;
	wchar_t *tmpName = NULL;
	wchar_t *tmpValue = NULL;
	size_t nameLen = 0;
	size_t valueLen = 0;
	size_t totalLen = 0;
	wchar_t **tmp = NULL;

	ret = StringCbLengthW(Name, STRSAFE_MAX_CCH, &nameLen);
	if (ret == S_OK) {
		ret = StringCbLengthW(Value, STRSAFE_MAX_CCH, &valueLen);
		if (ret == S_OK) {
			totalLen = nameLen + 1 + valueLen;
			tmpName = (wchar_t *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, (totalLen + 1) * sizeof(wchar_t));
			if (tmpName != NULL) {
				tmpValue = tmpName + nameLen + 1;
				CopyMemory(tmpName, Name, nameLen * sizeof(wchar_t));
				CopyMemory(tmpValue, Value, valueLen * sizeof(wchar_t));
				tmp = (wchar_t **)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 2 * (Pair->Count + 1) * sizeof(wchar_t *));
				if (tmp != NULL) {
					CopyMemory(tmp, Pair->Names, Pair->Count * sizeof(wchar_t *));
					tmp[Pair->Count] = tmpName;
					CopyMemory(tmp + Pair->Count + 1, Pair->Values, Pair->Count * sizeof(wchar_t *));
					tmp[Pair->Count * 2 + 1] = tmpValue;
					if (Pair->Count > 0)
						HeapFree(GetProcessHeap(), 0, Pair->Names);

					Pair->Names = tmp;
					Pair->Values = tmp + Pair->Count + 1;
					++Pair->Count;
				}
				else ret = GetLastError();

				if (ret != ERROR_SUCCESS)
					HeapFree(GetProcessHeap(), 0, tmpName);
			}
			else ret = GetLastError();
		}
	}

	return ret;
}


static DWORD _AddNameFormat(PNV_PAIR Pair, const wchar_t *Name, const wchar_t *Format, ...)
{
	wchar_t buf[1024];
	DWORD ret = ERROR_GEN_FAILURE;
	va_list args;

	va_start(args, Format);
	RtlSecureZeroMemory(buf, sizeof(buf));
	ret = StringCbVPrintf(buf, sizeof(buf) / sizeof(buf[0]), Format, args);
	if (ret == S_OK)
		ret = _AddNameValue(Pair, Name, buf);

	va_end(args);

	return ret;
}


static DWORD cdecl _ParseRoutine(const REQUEST_HEADER *Request, const DP_REQUEST_EXTRA_INFO *ExtraInfo, PBOOLEAN Handled, wchar_t ***Names, wchar_t ***Values, size_t *RowCount)
{
	NV_PAIR p;
	DWORD ret = ERROR_GEN_FAILURE;
	const REQUEST_IRP *irp = NULL;
	const PNP_INTERFACE *intfc = NULL;
	const REQUEST_IRP_COMPLETION *irpComp = NULL;
	const GUID *interfaceType = NULL;
	wchar_t guidString[100];
	const INTERFACE_TABLE_ENTRY *entry = NULL;

	ret = ERROR_SUCCESS;
	switch (Request->Type) {
		case ertIRPCompletion:
			irpComp = CONTAINING_RECORD(Request, REQUEST_IRP_COMPLETION, Header);
			if (irpComp->MajorFunction == IRP_MJ_PNP &&
				irpComp->MinorFunction == IRP_MN_QUERY_INTERFACE &&
				irpComp->DataSize > 0) {
				intfc = (PPNP_INTERFACE)(irpComp + 1);
			}
			break;
		case ertIRP:
			irp = CONTAINING_RECORD(Request, REQUEST_IRP, Header);
			if (irp->MajorFunction == IRP_MJ_PNP &&
				irp->MinorFunction == IRP_MN_QUERY_INTERFACE &&
				irp->DataSize > 0)
				interfaceType = (GUID *)(irp + 1);
			break;
	}

	if (intfc != NULL || interfaceType != NULL) {
		memset(&p, 0, sizeof(p));
		if (intfc != NULL) {
			ret = _AddNameFormat(&p, L"Size", L"%u", intfc->Size);
			if (ret == ERROR_SUCCESS)
				ret = _AddNameFormat(&p, L"Version", L"%u", intfc->Version);
			
			if (ret == ERROR_SUCCESS)
				ret = _AddNameFormat(&p, L"Reference", L"0x%p", intfc->InterfaceReference);
			
			if (ret == ERROR_SUCCESS)
				ret = _AddNameFormat(&p, L"Dereference", L"0x%p", intfc->InterfaceDereference);
		} else {
			memset(guidString, 0, sizeof(guidString));
			StringFromGUID2(interfaceType, guidString, sizeof(guidString) / sizeof(guidString[0]));
			ret = _AddNameValue(&p, L"Interface type", guidString);
			if (ret == ERROR_SUCCESS) {
				entry = _interfaceTable;
				for (size_t i = 0; i < sizeof(_interfaceTable) / sizeof(_interfaceTable[0]); ++i) {
					if (memcmp(entry->InterfaceGuid, interfaceType, sizeof(GUID)) == 0) {
						ret = _AddNameValue(&p, L"Interface name", entry->Name);
						break;
					}

					++entry;
				}
			}
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
	}  else {
		*Names = NULL;
		*Values = NULL;
		*RowCount = 0;
		*Handled = FALSE;
	}

	return ret;
}


static void cdecl _FreeRoutine(wchar_t **Names, wchar_t **Values, size_t Count)
{
	for (size_t i = 0; i < Count; ++i)
		HeapFree(GetProcessHeap(), 0, Names[i]);

	HeapFree(GetProcessHeap(), 0, Names);

	return;
}


DWORD cdecl DP_INIT_ROUTINE_NAME(PIRPMON_DATA_PARSER Parser)
{
	RtlSecureZeroMemory(Parser, sizeof(IRPMON_DATA_PARSER));
	Parser->MajorVersion = 1;
	Parser->MinorVersion = 0;
	Parser->BuildVersion = 0;
	Parser->Name = L"PnPInterface";
	Parser->Priority = 1;
	Parser->ParseRoutine = _ParseRoutine;
	Parser->FreeRoutine = _FreeRoutine;

	return ERROR_SUCCESS;
}