//****************** File DacSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ���
//
//  Constants, structures & functions definitions
//	for API Property Dialog of DAC service
//
//	Copyright (c) 2002-2003, Instrumental Systems,Corp.
//	Written by Dorokhin Andrey
//
//  History:
//  11-10-05 - builded
//
//*******************************************************************************

#ifndef _DACSRVINFO_H
 #define _DACSRVINFO_H

#ifdef SRVINFO_API_EXPORTS
 #define SRVINFO_API __declspec(dllexport)
#else
 #define SRVINFO_API __declspec(dllimport)
#endif

#define MAX_CHAN 2
#define NAME_SIZE 64

#pragma pack(1)

// Struct info about device
typedef struct _DACSRV_INFO {
	USHORT		Size;					// sizeof(DACSRV_INFO)
	TCHAR		Name[NAME_SIZE];		// �������� ������ � ������
	UCHAR		Bits;					// �����������
	UCHAR		Encoding;				// ��� ��������� (0 - ������, 1 - �������-��������������, 2 - ��� ����)
//	UCHAR		Code;					// 0 - two's complement, 1 - floating point, 2 - straight binary, 7 - Gray code
	ULONG		FifoSize;				// ������ FIFO ��� (� ������)
	UCHAR		ChanCnt;				// ���������� ������� ��� (���������������� ��������)
	ULONG		ChanMask;				// ����� ��������� �������
	ULONG		SyncMode;				// ����� ������������� (Master/Single/Slave)
	double		SamplingRate;			// ������� �������������
	ULONG		MinRate;				// ���. ������� �������������
	ULONG		MaxRate;				// ����. ������� �������������
	double		ClockValue;				// �������� �������
	ULONG		ClockSrc;				// �������� �������� �������
	ULONG		SysRefGen;				// system generator (�������� ���������� �������� ���������� (��))
	ULONG		BaseRefGen[2];			// frequency of generators (�������� ������� ����������� (��))
	double		BaseExtClk;				// any external frequency of clock (����� �� ������� ������ ������������ (��))
	double		Range[MAX_CHAN];		// �������� �������� ��� ������� ������
	double		Bias[MAX_CHAN];			// �������� ���� ��� ������� ������
	UCHAR		Format;					// 0 - 16 ���, 1 - 8 ���
	USHORT		StartDelayCnt;			// ������� ��������� ��������
	USHORT		OutCnt;					// ������� ���������� ������
	USHORT		SkipCnt;				// ������� ����������� ������
	UCHAR		Cnt0Enable;				// ���������� �������� ��������� ��������
	UCHAR		Cnt1Enable;				// ���������� �������� ���������� ������
	UCHAR		Cnt2Enable;				// ���������� �������� ����������� ������
	ULONG		StartSrc;				// �������� ������
	UCHAR		StartInv;				// �������� ������� ������
	ULONG		StopSrc;				// �������� ��������
	UCHAR		StopInv;				// �������� ������� ��������
	UCHAR		StartStopMode;			// 1 - ����� ����������� ������-��������, 0 - ����� �������������� ������-��������
} DACSRV_INFO, *PDACSRV_INFO;

#pragma pack()

// Functions Declaration

#ifdef	__cplusplus
extern "C" {
#endif

//typedef int __stdcall INFO_DlgProp_Type(void* pDev, void* pServ, ULONG dlgMode, PVOID pSrvInfo); 
typedef int __stdcall INFO_InitPages_Type(void* pDev, DEVS_API_PropDlg* pPropDlg, void* pServ, ULONG* pNumDlg, PVOID pSrvInfo); 
typedef int __stdcall INFO_DeletePages_Type(ULONG numDlg); 
typedef int __stdcall INFO_AddPages_Type(ULONG numDlg, HWND hParentWnd, ULONG viewMode, ULONG numPage, PVOID pPages); 
typedef int __stdcall INFO_SetProperty_Type(ULONG numDlg); 
typedef int __stdcall INFO_UpdateData_Type(ULONG numDlg, ULONG mode); 

//SRVINFO_API int __stdcall INFO_DialogProperty(void* pDev, void* pServ, ULONG dlgMode, PVOID pSrvInfo);
SRVINFO_API int __stdcall INFO_InitPages(void* pDev, DEVS_API_PropDlg* pPropDlg, void* pServ, ULONG* pNumDlg, PVOID pSrvInfo);
SRVINFO_API int __stdcall INFO_DeletePages(ULONG numDlg);
SRVINFO_API int __stdcall INFO_AddPages(ULONG numDlg, HWND hParentWnd, ULONG viewMode, ULONG numPage, PVOID pPages);
SRVINFO_API int __stdcall INFO_SetProperty(ULONG numDlg);
SRVINFO_API int __stdcall INFO_UpdateData(ULONG numDlg, ULONG mode);

#ifdef	__cplusplus
};
#endif

#endif // _DACSRVINFO_H

// ****************** End of file DacSrvInfo.h ***************
