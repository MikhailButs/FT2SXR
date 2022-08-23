/*
 ****************** File ddc24Regs.h *******************
 *
 *  Definitions of tetrad register
 *	structures and constants
 *	for DDC24
 *
 * (C) InSys by Sklyarov A. Oct. 2013
 *
 *************************************************************
*/

#ifndef _DDC24REGS_H_
 #define _DDC24REGS_H_

#pragma pack(push,1)

typedef union _CONTROL1 {
  ULONG AsWhole;	// Register as a Whole Word
  struct {			// Register as Bit Pattern
   ULONG mode		: 2,	// Mode 
	     startDdc	: 1,	// 
	     nslot		: 2,	// 
	     disable_fir: 1,	// 
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
typedef enum _DDC24_NUM_CMD_REGS {
	DDC24_MASK			= 0x15, // ����� ���������� ������� : 0-0xffffffff
	DDC24_CONTROL1		= 0x17, // ������� ����������
	DDC24_NCO			= 0x18,		// ������� ��� ������ ���� ������� NCO 
	DDC24_WRNCO		= 0x1A, // ������ ���� ������� � DDC
//	DDC1G8_COEF			= 0x1B, // ������� ��� ������ ������
	DDC24_NCO_MASK		= 0x1B, // ������� ��� ������ ������������� Fir-������� 
	DDC24_COEF_WR		= 0x1C, // ������ ������������� Fir-�������
	DDC24_DEBUG1		= 0x1D, // ������� ��� ������ ���������� ����������
	DDC24_IMIT			= 0x1E, // ������� ������ ��������� ������� 
	DDC24_MAIMIT		= 0x1F, // ����� ������ ������ ���������
	DDC24_DDC_ID		= 0x208 // ������� ������ ������������ ���
} DDC24_READ_WRITE_REGS;


#pragma pack(pop)

#endif //_DDC1G8REGS_H_

//
// End of file
//