//****************** File Adc1612x1mSrvInfo.h **********************************
//
//  ����������� ��������, �������� � �������
//	��� API ������� ������� ������ ��� �������� ������
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADM1612x1M service
//
// (C) InSys by Ekkore Aug 2008
//
//*******************************************************************************

#ifndef _ADC1612x1MSRVINFO_H
 #define _ADC1612x1MSRVINFO_H

#pragma pack(1)

// Struct info about device
typedef struct _ADC1612x1MSRV_Info {
	USHORT		Size;					// sizeof(ADC1612x1MSRV_INFO)
	ADCSRV_INFO *pAdcInfo;
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
	U32			nSubType;				// ��� ���������: 1612x1M: 0x000-Standard, 0x001 -WB LF, 0x002-WB HF 
										//            ��� 212x500M: 0x100-Standard, 0x101 -WB LF, 0x102-WB HF
	U32			aRefGen[2];				// ������� ���������� 0 � 1 (��)
} ADC1612x1MSRV_Info, *PADC1612x1MSRV_Info;

#pragma pack()

#endif // _ADC1612x1MSRVINFO_H

// ****************** End of file Adc1612x1mSrvInfo.h ***************
