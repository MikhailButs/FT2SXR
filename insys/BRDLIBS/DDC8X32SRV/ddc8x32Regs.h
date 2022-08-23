/*
 ****************** File ddc8x32Regs.h *******************
 *
 *  Definitions of tetrad register
 *	structures and constants
 *	for DDC8X32
 *
 * (C) InSys by Sklyarov A. Jul. 2012
 *
 *************************************************************
*/

#ifndef _DDC8X32REGS_H_
 #define _DDC8X32REGS_H_

#pragma pack(push,1)

typedef union _CONTROL1 {
  ULONG AsWhole;	// Register as a Whole Word
  struct {			// Register as Bit Pattern
   ULONG mode		: 2,	// Mode 
	     startDdc	: 1,	// 
	     nslot		: 2,	// 
	     res1		: 8,	// Reserve
	     enbframe	: 1,	// Reserve
	     fixover	: 1,	// Reserve
		 rstover	: 1;
  } ByBits;
} REG_CONTROL1, *PREG_CONTROL1;

//-------------------------------------------------------------------------
// Numbers of Command Registers
typedef enum _DDC8X32_NUM_CMD_REGS {
	DDC8X32_MASK		= 0x15, // ����� ���������� ������� : 0-0xffffffff
//	DDC8X32_MASK_NB		= 0x15,	// ����� ���������� ������� ��� ������������� ������: 0-0xff
//	DDC8X32_MASK_WB		= 0x16, // ����� ���������� ������� ��� ������������� ������: 0-0xffffffff
	DDC8X32_CONTROL1	= 0x17, // ������� ����������
	DDC8X32_NCO			= 0x18,		// ������� ��� ������ ���� ������� NCO 
//	DDC8X32_NCO_NB		= 0x18, // ������� ��� ������ ���� ������� NCO ��� ������������� ������
//	DDC8X32_NCO_WB		= 0x19, // ������� ��� ������ ���� ������� NCO ��� ��������������� ������
	DDC8X32_WRNCO		= 0x1A, // ������ ���� ������� � DDC
	DDC8X32_FIR			= 0x1B, // ������� ��� ������ ������������� Fir-������� 
	DDC8X32_DEBUG0		= 0x1C, // ������� ��� ������ ���������� ����������
	DDC8X32_DEBUG1		= 0x1D, // ������� ��� ������ ���������� ����������
	DDC8X32_DECIM		= 0x1E, // ������� ������������ ��������� DDC 
	DDC8X32_POROG		= 0x1F, // ������� ������� ��������� ������������
	DDC8X32_ADC_OVER	= 0x208 // ������� ������ ������������ ���
} DDC8X32_READ_WRITE_REGS;


#pragma pack(pop)

#endif //_DDC8X32REGS_H_

//
// End of file
//