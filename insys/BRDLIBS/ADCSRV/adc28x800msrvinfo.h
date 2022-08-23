//****************** File Adc28x800mSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ��� �������� ������
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADC28x800M service
//
//	Copyright (c) 2002-2004, Instrumental Systems,Corp.
//	Written by Dorokhin Andrey
//
//  History:
//  14-04-04 - builded
//
//*******************************************************************************

#ifndef _ADC28X800MSRVINFO_H
 #define _ADC28X800MSRVINFO_H

//#define MAX_CHAN 2

#pragma pack(1)

// Struct info about device
typedef struct _ADC28X800MSRV_INFO {
	USHORT		Size;					// sizeof(ADC28X800MSRV_INFO)
	PADCSRV_INFO pAdcInfo;
	ULONG		MainRefGen;				// frequency of main generator (�������� ��������� �������� ���������� (��))
	double		DacMainGen;				// DAC frequency trim for main generator (�������� ��� ���������� ������� ��� ��������� ���������� (��))
	ULONG		MaxVcoGenFreq;			// maximum frequency of auxiliary generator (������������ �������� ������� ��������������� ���������������� ���������� (��))
	ULONG		MinVcoGenFreq;			// minimum frequency of auxiliary generator (����������� �������� ������� ��������������� ���������������� ���������� (��))
	double		VcoClk;					// frequency of VCO (�������� ������� ��� (��))
	double		ExtClk;					// any external frequency of clock (����� �� ������� ������ ������������ (��))
	double		GainTuning[MAX_CHAN];	// ���������� �������� ������� ������ 
	ULONG		StartSrc;				// �������� ������
	UCHAR		InvStart;				// �������� ������� ������
	double		StartLevel;				// ������� ������� ������
} ADC28X800MSRV_INFO, *PADC28X800MSRV_INFO;

#pragma pack()

#endif // _ADC28X800MSRVINFO_H

// ****************** End of file Adc28x800mSrvInfo.h ***************
