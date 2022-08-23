/*
 ****************** File ddckitRegs.h *******************
 *
 *  Definitions of tetrad register
 *	structures and constants
 *	for DDC640
 *
 * (C) InSys by Sklyarov A. Feb. 2015
 *
 *************************************************************
*/

#ifndef _DDCKITREGS_H_
 #define _DDCKITREGS_H_

#pragma pack(push,1)

typedef union _CONTROL1 {
  ULONG AsWhole;	// Register as a Whole Word
  struct {			// Register as Bit Pattern
   ULONG mode		: 2,	// Mode 
	     startDdc	: 1,	// 
	     stream		: 2,	// 
	     adc		: 1,	// ������� � ���
	     sel_iq		: 1,	// Reserve
	     res		: 4,	// Reserve
	     coef_ld	: 1,	// 1- �������� ������������� �������
		 nco_enb	: 1,	// 1 - enable  DDS
	     nco_rst	: 1,	// 1 - ����� DDS
	     nco_reg	: 1,	// ����� �������� DDS: 0-������� ���� �������(�������� ����������), 1-������� ��������� ����
		 rstImit	: 1;
  } ByBits;
} REG_CONTROL1, *PREG_CONTROL1;


//-------------------------------------------------------------------------
// Numbers of Command Registers
typedef enum _DDC640_NUM_CMD_REGS {
	DDCKIT_NCO_NB_ADDR	= 0x15, // ����� NCO NB DDC
	DDCKIT_CONTROL1		= 0x17, // ������� ����������
	DDCKIT_NCO			= 0x18,	// ������� ��� ������ ���� ������� NCO 
	DDCKIT_NCO_MASK		= 0x19, // ������� ����� ��� ���������������� WB DDC 
	DDCKIT_WRNCO_WB		= 0x1A, // ������ ���� ������� � �������������� DDC
	DDCKIT_WRNCO_NB		= 0x1B, // ������ ���� ������� � ������������ DDC
	DDCKIT_GAIN			= 0x1C, // ������� ��� ������ ���� ��������
	DDCKIT_MASK			= 0x1D, // ������� ��� ������ ����� ������� DDC
} DDCKIT_READ_WRITE_REGS;

#define DDCKIT_STATISTIC	 0x240

#pragma pack(pop)

#endif //_DDCKITREGS_H_

//
// End of file
//