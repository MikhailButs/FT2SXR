//****************** File Adc210x1gSrvInfo.h **********************************
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADM210x1G service
//
// (C) InSys by Ekkore Aug 2008
//
//*******************************************************************************

#ifndef _ADC210x1GSRVINFO_H
 #define _ADC210x1GSRVINFO_H

#pragma pack(1)

// Struct info about device
typedef struct _ADC210X1GSRV_Info {
	USHORT		Size;					// sizeof(ADC210X1GSRV_INFO)
	ADCSRV_INFO *pAdcInfo;
	double		ExtClk;					// any external frequency of clock (����� �� ������� ������ ������������ (��))
	REAL64		aGainDb[MAX_CHAN];		// ������������ �������� ��� WB (LF � HF) � ������ ������ (��)
	REAL64		aGainTun[MAX_CHAN];		// ���������� ������������� �������� � ������ ������
	ULONG		StartSrc;				// �������� ������
	UCHAR		InvStart;				// �������� ������� ������
	double		StartLevel;				// ������� ������� ������
	ULONG		PllRefGen;				// frequency of PLL reference generator (�������� ����������� �������� ���������� ��� ���� (��))
	ULONG		PllFreq;				// frequency of PLL (�������, ���������� ���� (��))
	ULONG		ExtPllRef;				// frequency of external PLL reference (�������� ������� ������� ������� ��� ���� (��))
	UCHAR		InvClk;					// �������� ������� ������������
	UCHAR		Version;				// ������ ���������
	U32	nRefGen0;             // ������� ��������� 0 (��)
	U32	nRefGen1;             // ������� ��������� 1 (��)
	U32	nRefGen1Min;          // ������� ��������� 1 (��)
	U32	nRefGen1Max;          // ������� ��������� 1 (��)
	U32	nRefGen1Type;         // ��� �������� ���������� 1
	U32	nRefGen2;             // ������� ��������� 2 (��)
	U32	nRefGen2Type;         // ��� �������� ���������� 2
	U32	nLpfPassBand;         // ������� ����� ��� (��)
//	U32			nStartClkSl;
	double		adIcrRange[4];	// ����� �������������� ��� Standard (��) (default 10000, 2000, 500, 100)
	U32			nInputSource;	// ������� �������� �������: 1 - �� ��� ����� �������� �����
	U32			nStartSlave;	// 1 - ����� �� ������� SLSTRIN
	U32			nClockSlave;	// 1 - ���� �� ������� SLCLKIN
	U32			nSlclkinClk;	// ������� ������� �� ������� SLCLKIN (��)
	U32			aisInpFilter[2];// 1 - ��������� ��� ��� �����. ���
	U32			nDoubleFreq;	// ����� �������� �������: 0-���, 1-���� IN0, 2-���� IN1
	double		dDoubleFreqBias1; //��������� �������� ���� ��� ���1 (%): -100..+100
	double		dDoubleFreqRange1;//��������� ����� �������������� ��� ���1 (%): -100..+100
} ADC210X1GSRV_Info, *PADC210X1GSRV_Info;
//
#pragma pack()

#endif // _ADC210x1GSRVINFO_H

// ****************** End of file Adc210x1gSrvInfo.h ***************
