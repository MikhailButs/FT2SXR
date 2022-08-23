/*
 ****************** File fmc127srv.h *************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : BASE of FMC-modules section
 *
 * (C) InSys by Dorokhin Andrey Dec 2015
 *
 ************************************************************
*/

#ifndef _FMC127SRV_H
 #define _FMC127SRV_H

#include "ctrlfmc127p.h"
#include "service.h"
#include "adm2if.h"
#include "mainregs.h"

#include "si571.h"

#define GENERATOR_DEVID 0
//#define SWITCH_DEVID 1
#define SENSMON_DEVID 8
#define EEPROM_DEVID 16
//#define SYNC_SWITCH_DEVID 2

#define GENERATOR_NUMB 0x49
//#define SWITCH_NUMB 0x48
#define MONITOR0_NUMB 0x48
#define MONITOR1_NUMB 0x49
#define MONITOR2_NUMB 0x4A
#define EEPROM_NUMB 0x50

#pragma pack(push,1)

typedef struct _FMC127SRV_CFG {
//	U32		SysGen;				// system generator frequency (������� ���������� ���������� (��))
	U08		SwitchType;			// type of switch (0-non, 1-���1(FMC105P), 2-���2(FMC106P))
//	U08		AdrSwitch;			// �������� ��� �����������: 0x48 �� ���������
	U08		Gen0Type;			// ��� ����������� ���������� 0 (0-�����������������, 1-Si571)
	U32		RefGen0;			// ������� ���������� 0, ���� �� �����������������, ��� ��������� ������� (default 50 MHz)
	U32		RefMaxGen0;			// ������������ ������� �����. ���������� (��)
	U08		AdrGen0;			// �������� ��� �����. ����������: 0x49 �� ���������
	REAL64	dGenFxtal;			// ������� ������ (Fxtal) ����������� ���������� Si570/571 (��)
	UCHAR	isAlreadyInit;		// ���� ������������� (����� ������ �� ����������)
	U08		isMonitor;			// ������� �������� �������
	U08		AdrMonitor;			// �������� ��� �������� �������: 0x48 �� ���������
	U08		SwichtInp[8];		// �������� ������ ��� 8 ������� �����������
	U08		ModeMonitor[3];		// ����� ������ ��������
	U08		isUserEeprom;		// ������� ����������������� ����
} FMC127SRV_CFG, *PFMC127SRV_CFG;

//const BASEFSRV_CFG BaseSrvCfg_dflt = {
//	2,			// SwitchType
//	0x48,		// AdrSwitch
//	0,			// Gen0Type
//	50000000,	// RefGen0
//	50000000,	// RefMaxGen0
//	0x49,		// AdrGen0
//	50000000.,	// dGenFxtal
//	0			// 
//};

#pragma pack(pop)

class Cfmc127srv: public CService
{
protected:

	long m_MainTetrNum;
	int writeSpdDev(CModule* pModule, ULONG dev, ULONG num, ULONG syncr, ULONG reg, U32 val);
	int readSpdDev(CModule* pModule, ULONG dev, ULONG num, ULONG syncr, ULONG reg, U32* pVal);

	void setModeSensors(CModule* pModule, U32 numb, U32 flt, U32 ctrl_reg6, U32 ctrl_reg7);
	void readSensors(CModule* pModule, U32 numb, U32 ctrlmode, double* vchan, double* tempr, double* vcc, double* curchan);

	int	Si571SetClkVal( CModule* pModule, double *pRate );
	int	Si571GetClkVal( CModule* pModule, double *pRate );

	int	WriteUserEeprom( CModule* pModule, PVOID pBuffer, ULONG BufferSize, ULONG Offset);
	int	ReadUserEeprom( CModule* pModule, PVOID pBuffer, ULONG BufferSize, ULONG Offset);

public:

	Cfmc127srv(int idx, int srv_num, CModule* pModule, PFMC127SRV_CFG pCfg); // constructor

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
	int CtrlSensMon(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );
	int CtrlClkSwitch(
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
	
	int CtrlUserEeprom(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
			   );

};

#endif // _FMC127SRV_H

//
// End of file
//