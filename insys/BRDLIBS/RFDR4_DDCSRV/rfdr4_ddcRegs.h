/*
 ****************** File rfdr4_ddcRegs.h *******************
 *
 *  Definitions of tetrad register
 *	structures and constants
 *	for RFDR4
 *
 * (C) InSys by Sklyarov A. Aug. 2014
 *
 *************************************************************
*/

#ifndef _RFDR4_DDCREGS_H_
 #define _RFDR4_DDCREGS_H_

#pragma pack(push,1)

typedef union _CONTROL0 {
  ULONG AsWhole;	// Register as a Whole Word
  struct {			// Register as Bit Pattern
   ULONG porog_det_clk	: 4,	// ����� ��������� ��������: 1 - 15
		 mode_det_clk	: 1,	// ����� ��������� ��������: 0 �����������(����� �������), 1- ������� (� �������� 100 ��
		 led_control	: 1,	// ����� ���������� �����������: 0 - �����������, 1 - �� ������ ��������� �������� 
		 led_level		: 1,	// ���������� ����������� � ����������� ������: 0 - "��������", 1 - "�������" 
		 res			: 9;	// ������
  } ByBits;
} REG_CONTROL0, *PREG_CONTROL0;


typedef union _CONTROL1 {
  ULONG AsWhole;	// Register as a Whole Word
  struct {			// Register as Bit Pattern
   ULONG startDdc	: 1,	// 1 - ����� DDC
		 nco_enb	: 1,	// �� ������������
	     nco_rst	: 1,	// �� ������������
	     frameOn	: 1,	// 1 - �������� �������� ����� �����
	     headerOn	: 1,	// 1 - ��������� ���������
		 res1		: 1,	// ������
		 correctOn	: 1,	// 1 - �������� ���������
		 start_rst_nco	: 1,	// 1 - ������������� ����������� reset NCO ��� ������
		 start_wr	: 1,	// �� ������������
	     scan_enb	: 1,	// 1 - �������� ����� ������������
		 rst_nco	: 1,	// �� ������������
	     start_rst_cic : 1,	// 1 - ������������� ����������� reset CIC ��� ������
	     start_rst_fir : 1,	// 1 - ������������� ����������� reset FIR ��� ������
	     wrscaner	: 1,	// ������ ������� ��� ������: 0 ��� 1
		 rdscaner	: 1,	// ������ ������� ��� ������: 0 ��� 1
		 res2		: 1;	// ������
  } ByBits;
} REG_CONTROL1, *PREG_CONTROL1;


//-------------------------------------------------------------------------
// Numbers of Command Registers
typedef enum _RFDR4_DDC_NUM_CMD_REGS {
	DDCnr_GETDETECT		= 0x15,		// ����� ��������� ����������� ��������
	DDCnr_CONTROL0		= 0x16,		// ������� ���������� 0
	DDCnr_CONTROL1		= 0x17,		// ������� ���������� 1
	DDCnr_NCO			= 0x18,		// ������� ��� ������ ���� ������� NCO 
	DDCnr_PROG			= 0x19,		// �� ������������
	DDCnr_WRNCO			= 0x1A,		// ������ ���� ������� � ������� �������� DDC
	DDCnr_NCO_MASK		= 0x1B,		// ����� �������  ��� ������ � ������� �������� DDC
	DDCnr_COR_COEF		= 0x1C,		// ������� ��� ������ �������������� ������������ 
	DDCnr_COEF_WR		= 0x1D,		// ������  �������������� ������������ 
	DDCnr_MEM_WR		= 0x1E,		// ������� ������ ������ ������ ������������ 
	DDCnr_MEM_RST		= 0x1F,		// ������� c�����  ������ ������ ������������ (��������� ������) 
} RFDR4_READ_WRITE_REGS;

// ������ ������������� ��������� ��������� �������
//
enum 
{
	DDCnr_SKIPSAMP		= 0x210,	// ����� �������� ������������ � ������ �����: 0...65535 
	DDCnr_GETSAMP		= 0x211,	// ����� �������� ���������� � �����:   0..65535
	DDCnr_SYNCWORD		= 0x212,	// ����������� ��������� 1: 0�0...0xFFFF
	DDCnr_DELAYSTART	= 0x213,	// �������� �������� �������� ������ � ������ ������� 50 ���(20 ����)
	DDCnr_USERWORD		= 0x214,	// ����������� ��������� 2:  0�0...0xFFFF
	DDCnr_NSCAN			= 0x215,	// ����� ������ ������������ ( ���� ���� - 8 �������)
};





#pragma pack(pop)

#endif //_RFDR4_DDCREGS_H_

//
// End of file
//