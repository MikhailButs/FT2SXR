//****************** File Adc212x200mSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ��� �������� ������
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADC212x200M service
//
//	Copyright (c) 2002-2003, Instrumental Systems,Corp.
//	Written by Dorokhin Andrey
//
//  History:
//  14-04-04 - builded
//
//*******************************************************************************

#ifndef _ADC212X200MSRVINFO_H
 #define _ADC212X200MSRVINFO_H

//#define MAX_ADC_CHAN 2

#pragma pack(1)

// Struct info about device
typedef struct _ADC212X200MSRV_INFO {
	USHORT		Size;					// sizeof(ADC212X200MSRV_INFO)
	PADCSRV_INFO pAdcInfo;
	UCHAR		DblClockMode;			// ����� �������� �������� �������
	ULONG		RefGen;					// frequency of generators (�������� ������� ����������� (��))
	double		ExtClk;					// any external frequency of clock (����� �� ������� ������ ������������ (��))
	double		PhaseTuning[MAX_CHAN];	// ���������� ���� ��������� ������� ������ 0
	double		GainTuning0;			// ���������� �������� ������ 0
	UCHAR		Inp0Ch1;				// 1 - � ������ 1 ��������� ���� 0
	ULONG		StartSrc;				// �������� ������
	UCHAR		InvStart;				// �������� ������� ������
	double		StartLevel;				// ������� ������� ������
} ADC212X200MSRV_INFO, *PADC212X200MSRV_INFO;

#pragma pack()

#endif // _ADC212X200MSRVINFO_H

// ****************** End of file Adc212x200mSrvInfo.h ***************
