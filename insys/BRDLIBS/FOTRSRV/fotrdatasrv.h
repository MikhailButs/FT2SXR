/******************* File FotrDataSrv.h *************************
 *
 *  Definitions of user application interface
 *	structures and constants
 *	for BRD_ctrl : FOTR section
 *
 * (C) InSys by Dorokhin Andrey Jun, 2006
 *
 * - support ADMFOTR3G
 *
 ************************************************************/

#ifndef _FOTRDATASRV_H
 #define _FOTRDATASRV_H

#include "ctrlfotr.h"
#include "ctrlcmpsc.h"
#include "service.h"
#include "adm2if.h"
#include "fotrregs.h"

#define FOTR_TETR_ID		0x2E	// ADMFOTR2G
#define FOTR3G_TETR_ID		0x49	// ADMFOTR3G
#define DATA32IN_TETR_ID	0x34	// DATA32_IN
#define DATA32OUT_TETR_ID	0x35	// DATA32_OUT
#define DATA64IN_TETR_ID	0x13	// DATA64_IN
#define DATA64OUT_TETR_ID	0x12	// DATA64_OUT

#define DLGDLLNAME_SIZE 64

#pragma pack(push,1)

typedef struct _FOTRDATASRV_CFG {
	TCHAR	DlgDllName[DLGDLLNAME_SIZE];// �������� ���������� dll
//	DEVS_API_PropDlg* pPropDlg;			// ����� �������, ������� ����� ���������� �� ���������� dll ��� ��������� ����������
	UCHAR	isAlreadyInit;				// ���� ������������� (����� ������ �� ����������)
	UCHAR	Res[3];						// ������
	U32		RefGen;						// frequency of generator (�������� �������� ���������� (��))
	U08		MaxChan;					// ������������ ����� �������
	U08		TrancieverType;				// ��� ������-�����������
	U32		DataInFifoSize;				// ������ DATA32_IN FIFO (� ������)
	U32		DataOutFifoSize;			// ������ DATA32_OUT FIFO (� ������)
} FOTRDATASRV_CFG, *PFOTRDATASRV_CFG;

#pragma pack(pop)

class CFotrDataSrv: public CService
{

protected:

	long m_MainTetrNum;
	long m_FotrTetrNum;
	long m_DataInTetrNum;
	long m_DataOutTetrNum;

public:

	CFotrDataSrv(int idx, int srv_num, CModule* pModule, PFOTRDATASRV_CFG pCfg); // constructor

	int CtrlIsAvailable(
					void		*pDev,		// InfoSM or InfoBM
					void		*pServData,	// Specific Service Data
					ULONG		cmd,		// Command Code (from BRD_ctrl())
					void		*args 		// Command Arguments (from BRD_ctrl())
				   );
	int CtrlGetAddrData(
					void			*pDev,		// InfoSM or InfoBM
					void			*pServData,	// Specific Service Data
					ULONG			cmd,		// Command Code (from BRD_ctrl())
					void			*args 		// Command Arguments (from BRD_ctrl())
					);
	//int CtrlCfg(
	//			void		*pDev,		// InfoSM or InfoBM
	//			void		*pServData,	// Specific Service Data
	//			ULONG		cmd,		// Command Code (from BRD_ctrl())
	//			void		*args 		// Command Arguments (from BRD_ctrl())
	//			);
	int CtrlFifoReset(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlEnable(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlFifoStatus(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlGetData(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
	int CtrlPutData(
				void		*pDev,		// InfoSM or InfoBM
				void		*pServData,	// Specific Service Data
				ULONG		cmd,		// Command Code (from BRD_ctrl())
				void		*args 		// Command Arguments (from BRD_ctrl())
				);
};

#endif // _FOTRDATASRV_H

//
// End of file
//