//****************** File Adc214x200mSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ��� �������� ������
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADC214x200M service
//
//	Copyright (c) 2002-2007, Instrumental Systems,Corp.
//	Written by Dorokhin Andrey
//
//  History:
//  11-01-07 - builded
//
//*******************************************************************************

#ifndef _ADC214X200MSRVINFO_H
 #define _ADC214X200MSRVINFO_H

#pragma pack(1)

// Struct info about device
typedef struct _ADC214X200MSRV_INFO {
	USHORT		Size;					// sizeof(ADC214X200MSRV_INFO)
	PADCSRV_INFO pAdcInfo;
	double		ExtClk;					// any external frequency of clock (����� �� ������� ������ ������������ (��))
	double		GainTuning[MAX_CHAN];	// ���������� �������� ������� ������
	ULONG		StartSrc;				// �������� ������
	UCHAR		InvStart;				// �������� ������� ������
	double		StartLevel;				// ������� ������� ������
	ULONG		PllRefGen;				// frequency of PLL reference generator (�������� ����������� �������� ���������� ��� ���� (��))
	ULONG		PllFreq;				// frequency of PLL (�������, ���������� ���� (��))
	ULONG		ExtPllRef;				// frequency of external PLL reference (�������� ������� ������� ������� ��� ���� (��))
	UCHAR		InvClk;					// �������� ������� ������������
	UCHAR		Version;				// ������ ���������
	UCHAR		IsRF;					// 1 - �������������� �����
	double		dBGain[MAX_CHAN];		// �������� ������� ������ (��) - ���� IsRF = 1
} ADC214X200MSRV_INFO, *PADC214X200MSRV_INFO;

#pragma pack()

#endif // _ADC214X200MSRVINFO_H

// ****************** End of file Adc214x200mSrvInfo.h ***************
