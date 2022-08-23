/*
 ****************** File Sync8chSrv.h ***************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : Sync8ch section
 *
 * (C) InSys by Dorokhin A. Apr 2009
 *
 ************************************************************
*/

#ifndef _SYNC8CH_SRV_H
 #define _SYNC8CH_SRV_H

#include "CtrlSync8ch.h"
#include "CtrlCmpSc.h"
#include "Service.h"
#include "Adm2If.h"
#include "MainRegs.h"
#include "Sync8chRegs.h"

#include "si571.h"
//#include "Sync8chSrvInfo.h"

#define DLGDLLNAME_SIZE 64

const int SYNC8CH_TETR_ID = 0x64; 

const int THRDACCNT = 8; // Number of threshold DACs

const double SYNC8CH_EXTSTARTLEVEL = 5.0; // 5.0 V

const double SYNC8CH_MINCHANLEVEL = -2.0; // -2.0 V
const double SYNC8CH_MAXCHANLEVEL = 6.0; // 6.0 V

// Threshold DAC number
enum {
	BRDtdn_SYNC8CH_HILVLCHA		= 1,	// high level of channel A
	BRDtdn_SYNC8CH_LOLVLCHA		= 2,	// low level of channel A
	BRDtdn_SYNC8CH_HILVLCHB		= 3,	// high level of channel B
	BRDtdn_SYNC8CH_LOLVLCHB		= 4,	// low level of channel B
	BRDtdn_SYNC8CH_HILVLCHD		= 5,	// high level of channel D
	BRDtdn_SYNC8CH_LOLVLCHD		= 6,	// low level of channel D
	BRDtdn_SYNC8CH_EXTSTARTLVL	= 7		// external start level
};

#define GENERATOR1_DEVID 0
#define GENERATORPLL_DEVID 1

#pragma pack(push,1)

typedef struct _SYNC8CHSRV_CFG {
	BRDCHAR	DlgDllName[DLGDLLNAME_SIZE];// �������� ���������� dll
	UCHAR	isAlreadyInit;				// ���� ������������� (����� ������ �� ����������)
	UCHAR	ClkChanCnt;					// ���������� �������� ������� ������������ (default 2)
	UCHAR	StrbChanCnt;				// ���������� �������� ������� c������������ (default 2)
	UCHAR	IsLF;						// �������� ������ �������� �������� ������������: 1 - LF (0.1-400 ���), 0 - HF(5-2500 ���)
	ULONG	SysGen;						// System generator in Hz (default 66 MHz)
	ULONG	Gen1;						// generator 1 in Hz (default 200 MHz)
	ULONG	Gen2;						// generator 2 in Hz (default 0 MHz)
	ULONG	OcxoGen;					// OCXO generator in Hz (default 0 MHz)
	ULONG	PllFreq;					// �������, ���������� ���� in Hz (default 0 GHz)
	ULONG	ExtClk;						// ������� ������� ������������ (��)
	UCHAR	IsClkE;						// ������� ��������������� ������ CLKE
	UCHAR	IsClkF;						// ������� ��������������� ������ CLKF
	UCHAR	IsStrbA;					// ������� ��������������� ������ STROA
	UCHAR	IsStrbB;					// ������� ��������������� ������ STROB
	UCHAR	IsStrbD;					// ������� ��������������� ������ STROD
	UCHAR	IsSync;						// ������� �������������� �������� ������������ �������������
	UCHAR	ThrDac[THRDACCNT];			// �������� ��������� ���
	U32		RefPVS;						// ������� ���������� ���������� ��������������� ���������� (������)
	REAL64	StCmpThr;					// ����� ������������ ����������� ������
	PLL_RCNT Pll_R_CNT;					//
	PLL_NCNT Pll_N_CNT;					//
	PLL_FUNC Pll_Func;					//
	UCHAR	Gen1Type;					// ��� ���������� 1 (0-�����������������, 1-Si571)
	ULONG	RefGen1;					// ������� ���������� 1, ���� �� �����������������, ��� ��������� ������� (default 50 MHz)
	ULONG	RefMaxGen1;					// ������������ ������� ���������� 1 (��)
	UCHAR	AdrGen1;					// �������� ��� ���������� 1: 0x49 �� ���������
	REAL64	dGen1Fxtal;					// ������� ������ (Fxtal) ���������� 1 Si570/571 (��)
	UCHAR	GenPllType;					// ��� ����������� ���������� ��� (0-�����������������, 1-Si571)
	ULONG	RefGenPll;					// ������� ���������� ���, ���� �� �����������������, ��� ��������� ������� (default 50 MHz)
	ULONG	RefMinGenPll;				// ����������� ������� ���������� ��� (��)
	ULONG	RefMaxGenPll;				// ������������ ������� ���������� ��� (��)
	UCHAR	AdrGenPll;					// �������� ��� ��� ����������: 0x49 �� ���������
	REAL64	dGenPllFxtal;				// ������� ������ (Fxtal) ���������� ��� Si570/571 (��)
	USHORT	DeviceID;					// DeviceID = 0x551B - SYNC8P
} SYNC8CHSRV_CFG, *PSYNC8CHSRV_CFG;

#pragma pack(pop)

class CSync8chSrv: public CService
{

protected:

	HINSTANCE m_hLib;
	
	long m_SyncTetrNum;
	long m_MainTetrNum;

	virtual int CtrlRelease(void* pDev, void* pServData, ULONG cmd, void* args);
	virtual int SetClkMode(CModule* pModule, PBRD_SyncClkMode pClkMode);
	virtual int GetClkMode(CModule* pModule, PBRD_SyncClkMode pClkMode);
	virtual int SetOutClk(CModule* pModule, PBRD_SyncOutClk pOutClk);
	virtual int GetOutClk(CModule* pModule, PBRD_SyncOutClk pOutClk);
	virtual int SetStbMode(CModule* pModule, PBRD_SyncStbMode pStbMode);
	virtual int GetStbMode(CModule* pModule, PBRD_SyncStbMode pStbMode);
	virtual int SetOutStb(CModule* pModule, PBRD_SyncOutStb pOutStb);
	virtual int GetOutStb(CModule* pModule, PBRD_SyncOutStb pOutStb);
	virtual int SetStartMode(CModule* pModule, PBRD_SyncStartMode pStartMode);
	virtual int GetStartMode(CModule* pModule, PBRD_SyncStartMode pStartMode);
	virtual int StartStb(CModule* pModule);
	virtual int StopStb(CModule* pModule);
	virtual int StartClk(CModule* pModule);
	virtual int StopClk(CModule* pModule);

	int InitPLL(CModule* pModule);
	int OnPll(CModule* pModule, double& ClkValue, double PllRefValue);
	int SetPllMode(CModule* pModule, PBRD_PllMode pPllMode);

	int writePllData(CModule* pModule, USHORT HiWord, USHORT LoWord);

	int writeSpdDev(CModule* pModule, ULONG dev, ULONG num, ULONG synchr, ULONG reg, ULONG val);
	int readSpdDev(CModule* pModule, ULONG dev, ULONG num, ULONG synchr, ULONG reg, ULONG* pVal);

	int	Si571GetClkVal( CModule* pModule, double *pRate );
	int	Si571SetClkVal( CModule* pModule, double *pRate );

public:

	CSync8chSrv(int idx, int srv_num, CModule* pModule, PSYNC8CHSRV_CFG pCfg); // constructor

	int CtrlMaster(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlClkMode(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlOutClk(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlStbMode(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlOutStb(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlStartStopStb(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlStartStopClk(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlStartMode(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlPllMode(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
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
};

#endif // _SYNC8CH_SRV_H

//
// End of file
//