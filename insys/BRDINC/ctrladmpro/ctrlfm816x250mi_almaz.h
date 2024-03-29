/*
 ****************** File ctrlfm816x250mi_almaz.h *************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : FM816x250MI section
 *
 * (C) InSys 2020
 *
 *
 ************************************************************
*/

#ifndef _CTRL_FM816x250MIZ_H
 #define _CTRL_FM816x250MIZ_H

#include "ctrladc.h"

#pragma pack(push, 1)    

#define BRD_CHANCNT			8	// Number of channels
#define	BRD_GAINCNT			6	// Number of gains

const int BRD_CLKDIVCNT	= 5; // Number of clock dividers = 9 (1, 2, 4, 8, 16)

// FM816x250MI Clock sources
enum {
	BRDclks_ADC_DISABLED	= 0,	// 
	BRDclks_ADC_SUBGEN		= 1,	// SubModule Generator 0
	BRDclks_ADC_EXTCLK		= 0x81,	// External SubModule Clock
	BRDclks_ADC_CLK0_C2M	= 0x85,	// Base Unit Clock CLK0_C2M
	BRDclks_ADC_CLK1_C2M	= 0x86,	// Base Unit Clock CLK1_C2M
};

// FM816x250MI start sources
enum {
	BRDsts_ADC_CHAN0	= 0,	// Start from channel 0
	BRDsts_ADC_CHAN1	= 1,	// Start from channel 1
	BRDsts_ADC_EXT		= 2,	// Start from START IN (external)
	BRDsts_ADC_PRG		= 3,	// Program start
};


// Numbers of Specific Command
typedef enum _FM816x250MI_NUM_CMD
{
	FM816x250MIcmd_SETMU		= 64,
	FM816x250MIcmd_GETMU		= 65,
	FM816x250MIcmd_SUBSYNC	= 66,
	
	//FM816x250MIcmd_DDCENABLE = 67,
	FM816x250MIcmd_SETDDC = 67,			// set DDC parameters (FM816x250MIZ_DDCPARAM*)
	FM816x250MIcmd_GETDDC = 68,			// set DDC parameters (FM816x250MIZ_DDCPARAM*)
	FM816x250MIcmd_TSTMODE = 69,		// enable test mode (NULL)
	FM816x250MIcmd_SENDTASKPKG = 70,	// send task package by enabled test mode (U32 array[5])
} FM816x250MI_NUM_CMD;

typedef struct _FM816x250MISRV_MU {
	U32		size;					// sizeof(FM816x250MISRV_MU)
	U32		chanMask;				// ����� ��������� �������
	U32		syncMode;				// ����� ������������� (2 - Master, 1 - Single, 0 - Slave) ������ 1
	double	samplingRate;			// ������� ������������� (��): 10 ��� .. 125 ���
	double	clockValue;				// �������� ������� ���������� �������� ��������� (��)
	U32		clockSrc;				// �������� �������� ������� (0 - ��������, 1 - ��������� �� ���������, 0x81 - �������)
	double	range[BRD_CHANCNT];		// ����� �������������� ��� ������� ������ (�����): 4.0, 2.0, 1.0, 0.5, 0.25
	double	bias[BRD_CHANCNT];		// �������� ���� ��� ������� ������ (�����): -2*�� .. +2*��
	U32		inpResist[BRD_CHANCNT];	// ������� ������������� ��� ������� ������ (0 - 1 �O�, 1 - 50 O�)
	U32		dcCoupling[BRD_CHANCNT];// ���������� (1) / ���������� (0) ����� �� ���������� ������������ ��� ������� ������
	U32		format;					// 0 - 16 ���, 1 - 8 ���
	U32		startSrc;				// ������������ �������� ������: 0 - ����� 0, 1 - ����� 1, 3 - �����������
	double	startLevel;				// ������� ������ � ������� (�� -2.5 � �� +2.5 � � ��� ������� ������)
	double	clockLevel;				// ����� ����������� ������� �������� ������� (�): -2.5 .. +2.5
} FM816x250MISRV_MU, *PFM816x250MISRV_MU;

#define BRD_DDCCHANCNT	8	// Number of DDC channels
#define BRD_DDCFIRCNT	16	// Number of FIR-filters
#define BRD_DDCCOECNT	128	// Number of FIR-filter coefficients

typedef struct _FM816x250MIZ_DDCPARAM {
	U32		DdcEnable;				 // ���������� DDC: 0-�������� ���, 1-�������� DDC
	U32		DdsChan[BRD_DDCCHANCNT]; // �������� ������� DDS ������� ������ (��)
	U32		Fir2Gain[BRD_DDCFIRCNT]; // ��������
	S32		Fir2Coe[BRD_DDCFIRCNT][BRD_DDCCOECNT]; // ������������ ���-��������
} FM816x250MIZ_DDCPARAM, *PFM816x250MIZ_DDCPARAM;

#pragma pack(pop)    

#endif // _CTRL_FM816x250MIZ_H

//
// End of file
//