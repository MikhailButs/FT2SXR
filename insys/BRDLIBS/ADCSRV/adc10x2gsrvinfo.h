//****************** File Adc10x2gSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ��� �������� ������
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADC10x2G service
//
//	Copyright (c) 2002-2005, Instrumental Systems,Corp.
//	Written by Dorokhin Andrey
//
//  History:
//  16-06-05 - builded
//  15-03-06 - added by ver. 2.0
//
//*******************************************************************************

#ifndef _ADC10X2GSRVINFO_H
 #define _ADC10X2GSRVINFO_H

//#define MAX_CHAN 1

#pragma pack(1)

// Struct info about device
typedef struct _ADC10X2GSRV_INFO {
	USHORT		Size;					// sizeof(ADC10X2GSRV_INFO)
	PADCSRV_INFO pAdcInfo;
	UCHAR		TestMode;				// ������ ������������
	double		ExtClk;					// any external frequency of clock (����� �� ������� ������ ������������ (��))
	double		PhaseTuning;			// ���������� ���� ��������� �������
	double		GainTuning;				// ���������� �������� ������� ������ 
	ULONG		StartSrc;				// �������� ������
	UCHAR		InvStart;				// �������� ������� ������
	double		StartLevel;				// ������� ������� ������
	UCHAR		Version;				// ������ ������
	ULONG		PllRefGen;				// frequency of PLL reference generator (�������� ����������� �������� ���������� ��� ���� (��))
	ULONG		PllFreq;				// frequency of PLL (�������, ���������� ���� (��))
	ULONG		ExtPllRef;				// frequency of external PLL reference (�������� ������� ������� ������� ��� ���� (��))
	UCHAR		StartSl;				// 1 - ����� �� ������� START IN
	UCHAR		ClkSl;					// 1 - ����� �� ������� CLK IN
	UCHAR		TimerSync;				// 1 - ����� ������������� ������� �� ������� ������
} ADC10X2GSRV_INFO, *PADC10X2GSRV_INFO;

#pragma pack()

#endif // _ADC10X2GSRVINFO_H

// ****************** End of file Adc10x2gSrvInfo.h ***************
