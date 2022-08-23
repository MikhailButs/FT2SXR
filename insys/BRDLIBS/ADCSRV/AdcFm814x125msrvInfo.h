//****************** File Fm814x125mSrvInfo.h **********************************
//
//  Constants, structures & functions definitions
//	for API Property Dialog of FM814x125M service
//
// (C) InSys by Ekkore Aug 2011
//
//*******************************************************************************

#ifndef _FM814x125MSRVINFO_H
 #define _FM814x125MSRVINFO_H

#define MAX_ADC_CHAN		8

#pragma pack(1)

// Struct info about device
typedef struct _FM814X125MSRV_Info {
	USHORT		Size;					// sizeof(FM814X125MSRV_Info)
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

	U32	nAdcType;	// ��� ��������� ���: 0-������
	U32	nDacType;	// ��� ��������� ���: 0-������
	U32	nDacRange;	// ����� �������������� ���: (��)
	U32	nGenType;	// ��� ��������� �����. ����������: 0-�� �������-��, 1-Si571
	U32	nGenAdr;	// �������� ��� �����. ����������: 0x49 �� ���������
	U32	nGenRef;    // ��������� ��������� ������� �����. ���������� (��)
	U32	nGenRefMax; // ������������ ������� �����. ���������� (��)
	U32	anRange[8];	// ����� �������������� ��� (��)
	//U32	nRefGen0;             // ������� ��������� 0 (��)
	//U32	nRefGen1;             // ������� ��������� 1 (��)
	//U32	nRefGen1Min;          // ������� ��������� 1 (��)
	//U32	nRefGen1Max;          // ������� ��������� 1 (��)
	//U32	nRefGen1Type;         // ��� �������� ���������� 1
	//U32	nRefGen2;             // ������� ��������� 2 (��)
	//U32	nRefGen2Type;         // ��� �������� ���������� 2
	//U32	nLpfPassBand;         // ������� ����� ��� (��)

	double		adRange[8];		// ����� �������������� (�)
	U32			nInputSource;	// ������� �������� �������: 1 - �� ��� ����� �������� �����
	U32			nStartSlave;	// 1 - ����� �� ������� SLSTRIN
	U32			nClockSlave;	// 1 - ���� �� ������� SLCLKIN
	U32			nSlclkinClk;	// ������� ������� �� ������� SLCLKIN (��)
	U32			aisInpFilter[2];// 1 - ��������� ��� ��� �����. ���
	//U32			nDoubleFreq;	// ����� �������� �������: 0-���, 1-���� IN0, 2-���� IN1
	//double		dDoubleFreqBias1; //��������� �������� ���� ��� ���1 (%): -100..+100
	//double		dDoubleFreqRange1;//��������� ����� �������������� ��� ���1 (%): -100..+100
} FM814X125MSRV_Info, *PFM814X125MSRV_Info;
//
#pragma pack()

#endif // _FM814x125MSRVINFO_H

// ****************** End of file Adc210x1gSrvInfo.h ***************
