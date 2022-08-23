/*
 ****************** File emacsrv.h *************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : EMAC (Ethernet) section
 *
 * (C) InSys by Dorokhin Andrey Jan 2016
 *
 ************************************************************
*/

#ifndef _EMACSRV_H
 #define _EMACSRV_H

#include "ctrlemac.h"
#include "service.h"
#include "adm2if.h"
#include "mainregs.h"

const int EMAC_TETR_ID = 0x91; // tetrad id

#pragma pack(push,1)

typedef struct _EMACSRV_CFG {
	//U08		SwitchType;			// type of switch (0-non, 1-���1(FMC105P), 2-���2(FMC106P))
	//U08		AdrSwitch;			// �������� ��� �����������: 0x48 �� ���������
	//U08		Gen0Type;			// ��� ����������� ���������� 0 (0-�����������������, 1-Si571)
	//U32		RefGen0;			// ������� ���������� 0, ���� �� �����������������, ��� ��������� ������� (default 50 MHz)
	//U32		RefMaxGen0;			// ������������ ������� �����. ���������� (��)
	//U08		AdrGen0;			// �������� ��� �����. ����������: 0x49 �� ���������
	//REAL64	dGenFxtal;			// ������� ������ (Fxtal) ����������� ���������� Si570/571 (��)
	UCHAR	isAlreadyInit;		// ���� ������������� (����� ������ �� ����������)
	//U08		SwitchDevId;		// ����� ���������� ��� ���������������� �����������
} EMACSRV_CFG, *PEMACSRV_CFG;

// Numbers of Command Registers
typedef enum _EMAC_NUM_CMD_REGS {
	EMACnr_MODE0	= 0,
	EMACnr_MODE2	= 10,
	EMACnr_TXCTRL	= 16,
	EMACnr_RXCTRL	= 17,
} EMAC_NUM_CMD_REGS;

// Numbers of Direct Registers
typedef enum _EMAC_NUM_DIRECT_REGS {
	EMACnr_REG200		= 0x200,
	EMACnr_SYNXIN		= 0x202,
	EMACnr_SPDDEVICE	= 0x203,
	EMACnr_SPDCTRL		= 0x204,
	EMACnr_SPDADDR		= 0x205,
	EMACnr_SPDDATAL		= 0x206,
	EMACnr_SPDDATAH		= 0x207,
	EMACnr_RXCNT		= 0x208,
} EMAC_NUM_DIRECT_REGS;

#pragma pack(pop)

class CEmacSrv: public CService
{
protected:

	long m_MainTetrNum;
	long m_EmacTetrNum;

	int writeRegDev(CModule* pModule, U32 reg, U32 val);
	int readRegDev(CModule* pModule, U32 reg, U32* pVal);

	void writeMDIO(CModule* pModule, U32 adr, U32 data);
	U32 readMDIO(CModule* pModule, U32 adr);

public:

	CEmacSrv(int idx, int srv_num, CModule* pModule, PEMACSRV_CFG pCfg); // constructor

	int CtrlIsAvailable(
					void		*pDev,		// InfoSM or InfoBM
					void		*pServData,	// Specific Service Data
					ULONG		cmd,		// Command Code (from BRD_ctrl())
					void		*args 		// Command Arguments (from BRD_ctrl())
				   );
	int CtrlCapture(
					void		*pDev,		// InfoSM or InfoBM
					void		*pServData,	// Specific Service Data
					ULONG		cmd,		// Command Code (from BRD_ctrl())
					void		*args 		// Command Arguments (from BRD_ctrl())
				   );
	int CtrlIsComplete(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlWriteReg(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlReadReg(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlWriteMdio(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlReadMdio(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int	CtrlTransmit(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int	CtrlReceive(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
};

#endif // _EMACSRV_H

//
// End of file
//