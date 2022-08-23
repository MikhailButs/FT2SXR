//****************** File Adc212x1gSrvInfo.h **********************************
//
//  Constants, structures & functions definitions
//	for API Property Dialog of ADM212x1G service
//
// (C) InSys by Ekkore Okt 2010
//
//*******************************************************************************

#ifndef _ADC212x1GSRVINFO_H
 #define _ADC212x1GSRVINFO_H

#pragma pack(1)

// Struct info about device
typedef struct _ADC212X1GSRV_Info {
	USHORT		Size;					// sizeof(ADC212X1GSRV_INFO)
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
	U32			nDoubleFreq;	// ����� �������� �������: 0-���, 1-����� 0, 2-����� 1
} ADC212X1GSRV_Info, *PADC212X1GSRV_Info;
//
#pragma pack()

#endif // _ADC212x1GSRVINFO_H

// ****************** End of file Adc212x1gSrvInfo.h ***************
