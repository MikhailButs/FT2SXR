/*
 ****************** File ddc640Regs.h *******************
 *
 *  Definitions of tetrad register
 *	structures and constants
 *	for DDC640
 *
 * (C) InSys by Sklyarov A. Oct. 2014
 *
 *************************************************************
*/

#ifndef _DDC640REGS_H_
 #define _DDC640REGS_H_

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
	DDC640_NCO_NB_ADDR	= 0x15, // ����� NCO NB DDC
	DDC640_CONTROL1		= 0x17, // ������� ����������
	DDC640_NCO			= 0x18,	// ������� ��� ������ ���� ������� NCO 
	DDC640_NCO_MASK		= 0x19, // ������� ����� ��� ���������������� WB DDC 
	DDC640_WRNCO_WB		= 0x1A, // ������ ���� ������� � �������������� DDC
	DDC640_WRNCO_NB		= 0x1B, // ������ ���� ������� � ������������ DDC
	DDC640_GAIN			= 0x1C, // ������� ��� ������ ���� ��������
	DDC640_MASK			= 0x1D, // ������� ��� ������ ����� ������� DDC
} DDC640_READ_WRITE_REGS;

#define DDC640_STATISTIC	 0x240

#pragma pack(pop)

#endif //_DDC640REGS_H_

//
// End of file
//