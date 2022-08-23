/*
 ****************** File rfdr4_adcRegs.h *******************
 *
 *  Definitions of tetrad register
 *	structures and constants
 *	for RFDR4_ADC
 *
 * (C) InSys by Sklyarov A. Aug 2014
 *
 *************************************************************
*/

#ifndef _RFDR4_ADCREGS_H_
 #define _RFDR4_ADCREGS_H_

#pragma pack(push,1)

typedef union _CONTROL1 {
  ULONG AsWhole;	// Register as a Whole Word
  struct {			// Register as Bit Pattern
   ULONG calibr			: 1,	// ���������� ������������
		 clkSource		: 1,	// �������� ��������: 0 - ����������, 1 - �������
		 enbblkrf		: 1,	// ���������� ���������� ����� ���
		 res			: 13;	// ������
  } ByBits;
} REG_CONTROL1, *PREG_CONTROL1;

// ������ �������������� ��������� ��������� �������
enum 
{
	ADCnr_CONTROL1		= 0x17, 
};

// ������ ������������� ��������� ��������� �������
//
enum 
{
	ADCnr_ADCMASK		= 13, // 0x0D
	ADCnr_CLRFLG		= 0x200,
	ADCnr_SPD_DEVICE	= 0x203,
	ADCnr_SPD_CTRL		= 0x204,
	ADCnr_SPD_ADDR		= 0x205,
	ADCnr_SPD_DATA		= 0x206,
	ADCnr_ADC_OVR		= 0x208,
	
	ADCnr_EXTSTART		= 0x209,
	ADCnr_STD_DELAY		= 0x2f0,
};
enum 
{
	ADCnr_ATTEN0		= 0x210,
	ADCnr_ATTEN1		= 0x211,
	ADCnr_ATTEN2		= 0x212,
	ADCnr_ATTEN3		= 0x213,
};



#pragma pack(pop)

#endif //_RFDR4_ADCREGS_H_

//
// End of file
//