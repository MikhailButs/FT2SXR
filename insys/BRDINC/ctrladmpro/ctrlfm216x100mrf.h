/*
 ****************** File CtrlFm216x100mrf.h *************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : FM216x100MRF section
 *
 * (C) InSys by Egorov Nov, 2019
 *
 *
 ************************************************************
*/

#ifndef _CTRL_FM216x100MRF_H
 #define _CTRL_FM216x100MRF_H

#include "ctrladc.h"

#pragma pack(push, 1)    

#define BRD_CHANCNT			8	// Number of channels
#define	BRD_GAINCNT			1	// Number of gains

const int BRD_CLKDIVCNT	= 1; // Number of clock dividers = 1 (1)

// FM216x100mrf Clock sources
enum {
	BRDclks_ADC_DISABLED	= 0,	// 
	BRDclks_ADC_SUBGEN		= 1,	// SubModule Generator 0
	BRDclks_ADC_EXTCLK		= 0x81,	// External SubModule Clock
	BRDclks_ADC_BASEGEN		= 0x85,	// Base Module Generator
};

// FM216x100mrf start sources
enum {
	BRDsts_ADC_CHAN0	= 0,	// Start from channel 0
	BRDsts_ADC_EXT		= 2,	// Start from START IN (external)
	BRDsts_ADC_PRG		= 3,	// Program start
};



// Numbers of Specific Command
typedef enum _FM216x100MRF_NUM_CMD
{
	FM216x100MRFcmd_SETDITHER	= 64,
	FM216x100MRFcmd_GETDITHER	= 65,
	FM216x100MRFcmd_SETMU		= 66,
	FM216x100MRFcmd_GETMU		= 67,
	FM216x100MRFcmd_SETDDSFREQ = 68,
	FM216x100MRFcmd_GETDDSFREQ = 69,
	FM216x100MRFcmd_SETDDSATT = 70,
	FM216x100MRFcmd_GETDDSATT = 71,
	FM216x100MRFcmd_SETDDSMODE = 72,
	FM216x100MRFcmd_GETDDSMODE = 73,
	FM216x100MRFcmd_SETADCATT = 74,
	FM216x100MRFcmd_GETADCATT = 75,
} FM216x100MRF_NUM_CMD;

typedef struct _FM216x100MRF_DDS_FREQ {
	double dFreq;
	double dPhase;
}FM216x100MRF_DDS_FREQ, * PFM216x100MRF_DDS_FREQ;

typedef struct _FM216x100MRF_ADC_ATT {
	double dAtt0;
	double dAtt1;
}FM216x100MRF_ADC_ATT, *PFM216x100MRF_ADC_ATT;

typedef struct _FM216x100MRFSRV_MU {
	U32		size;					// sizeof(FM216x100mrfSRV_MU)
	ULONG		chanMask;				// ����� ��������� �������
	ULONG		syncMode;				// ����� ������������� (2 - Master, 1 - Single, 0 - Slave) ������ 1
	double	samplingRate;			// ������� ������������� (��): 10 ��� .. 125 ���
	double	clockValue;				// �������� ������� ���������� �������� ��������� (��)
	ULONG		clockSrc;				// �������� �������� ������� (0 - ��������, 1 - ��������� �� ���������, 0x81 - �������)
	double	range[BRD_CHANCNT];		// ����� �������������� ��� ������� ������ (�����): 4.0, 2.0, 1.0, 0.5, 0.25
	double	bias[BRD_CHANCNT];		// �������� ���� ��� ������� ������ (�����): -2*�� .. +2*��
	ULONG		inpResist[BRD_CHANCNT];	// ������� ������������� ��� ������� ������ (0 - 1 �O�, 1 - 50 O�)
	ULONG		dcCoupling[BRD_CHANCNT];// ���������� (1) / ���������� (0) ����� �� ���������� ������������ ��� ������� ������
	U32		format;					// 0 - 16 ���, 1 - 8 ���

	U32		startSrc;				// ������������ �������� ������: 0 - ����� 0, 1 - ����� 1, 3 - �����������
	double	startLevel;				// ������� ������ � ������� (�� -2.5 � �� +2.5 � � ��� ������� ������)
	double	clockLevel;				// ����� ����������� ������� �������� ������� (�): -2.5 .. +2.5
	ULONG		dither;					// �������� 0/1
	double	dADCatt0;				// �������� ����������� ���0 0 .. 31,5 �� � ����� 0,5
	double	dADCatt1;				// �������� ����������� ���1
	double	dDDSfreq;				// ������� DDS, ���
	double  dDDSphase;				// ���� DDS, �������
	U32		nDDSmode;				// ����� DDS: 0 - ��������, 1 - internal, 2 - external, 3 - termindated
	double	dDDSatt;				// �������� ����������� DDS
} FM216x100MRFSRV_MU, *PFM216x100MRFSRV_MU;

#pragma pack(pop)    

#endif // _CTRL_FM216x100MRF_H

//
// End of file
//