//****************** File Adc414x65mSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ��� �������� ������
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADC414x65M service
//
//	Copyright (c) 2002-2003, Instrumental Systems,Corp.
//	Written by Dorokhin Andrey
//
//  History:
//  21-08-06 - builded
//
//*******************************************************************************

#ifndef _ADC414X65MSRVINFO_H
 #define _ADC414X65MSRVINFO_H

#define MAX_ADC_CHAN 4

#pragma pack(1)

// Struct info about device
typedef struct _ADC414X65MSRV_INFO {
	USHORT		Size;					// sizeof(ADC212X200MSRV_INFO)
	PADCSRV_INFO pAdcInfo;
	ULONG		ClkLocation;			// �������������� ��������� �������� ������� (1 - �� ���������)
	double		Range[MAX_ADC_CHAN];	// ������� �������� ��� ������� ������
	double		Bias[MAX_ADC_CHAN];		// �������� ���� ��� ������� ������
	ULONG		RefGen[3];				// frequency of generators (�������� ������� ����������� (��))
	double		ExtClk;					// any external frequency of clock (����� �� ������� ������ ������������ (��))
	double		ThrClk;					// ����� ��������� �������
	double		ThrExtClk;				// ����� �������� ��������� �������
} ADC414X65MSRV_INFO, *PADC414X65MSRV_INFO;

#pragma pack()

#endif // _ADC414X65MSRVINFO_H

// ****************** End of file Adc414x65mSrvInfo.h ***************
