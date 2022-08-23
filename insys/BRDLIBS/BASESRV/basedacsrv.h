/*
 ****************** File BaseDacSrv.h *************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : BASEDAC section
 *
 * (C) InSys by Dorokhin Andrey Jul, 2006
 *
 ************************************************************
*/

#ifndef _BASEDACSRV_H
 #define _BASEDACSRV_H

#include "ctrlbasedac.h"
#include "ctrlcmpsc.h"
#include "service.h"
#include "adm2if.h"
#include "dacsrv.h"
#include "mainregs.h"
#include "basedacregs.h"

#include "basedacsrvinfo.h"

const int BASEDAC_TETR_ID = 0x02; // tetrad id

typedef struct _BASEDACSRV_CFG {
	DACSRV_CFG DacCfg;
//	U08		IsCycle;		// 1 - FIFO ��� ����� ���� ���������
	U08		OnFilter;		// ��� ����������� ������� 
	U16		AFRange;		// DAC range for active filter (�������� ��� ��� ������ ��������� ������� (�������))
//	U16		PFRange;		// DAC range for passive filter (�������� ��� ��� ������ ���������� ������� (�������))
	U16		AFCutoff;		// cufoff frequence of active filter (������� ����� ��������� ������� (����� ��))
//	U16		PFCutoffLo;		// cutoff lowest frequence of passive filter (������ ������� ����� ���������� ������� (���))
//	U16		PFCutoffHi;		// cutoff highest frequence of passive filter (������� ������� ����� ���������� ������� (���))
} BASEDACSRV_CFG, *PBASEDACSRV_CFG;

class CBaseDacSrv: public CDacSrv
{

protected:

	virtual int CtrlRelease(void* pDev, void* pServData, ULONG cmd, void* args);
	virtual ULONG GetParamForStream(CModule* pModule);
	virtual void GetDacTetrNum(CModule* pModule);
	virtual void* GetInfoForDialog(CModule* pModule);
	virtual int SetPropertyFromDialog(void	*pDev, void	*args);

	virtual int SetProperties(CModule* pDev, BRDCHAR* iniFilePath, BRDCHAR* SectionName);
	virtual int SaveProperties(CModule* pDev, BRDCHAR* iniFilePath, BRDCHAR* SectionName);
//	virtual int SetClkSource(CModule* pModule, ULONG ClkSrc);
//	virtual int SetRate(CModule* pModule, double& Rate, ULONG ClkSrc, double ClkValue);
//	virtual int GetRate(CModule* pModule, double& Rate, double ClkValue);
	virtual int SetChanMask(CModule* pModule, ULONG mask);
	virtual int GetChanMask(CModule* pModule, ULONG& mask);
	virtual int SetCode(CModule* pModule, ULONG type);
	virtual int GetCode(CModule* pModule, ULONG& type);
	virtual int GetCfg(PVOID pCfg);

public:

	CBaseDacSrv(int idx, int srv_num, CModule* pModule, PBASEDACSRV_CFG pCfg); // constructor

};

#endif // _BASEDACSRV_H

//
// End of file
//