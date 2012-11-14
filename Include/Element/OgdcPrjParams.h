// OgdcPrjParams.h: interface for the OgdcPrjParams class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcPrjParams.h
//!  \brief ͶӰ����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCPRJPARAMS_H__FAB41755_9ABC_4FF5_A375_7637A7E95C7D__INCLUDED_)
#define AFX_OGDCPRJPARAMS_H__FAB41755_9ABC_4FF5_A375_7637A7E95C7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"

namespace OGDC {
//!  \brief ͶӰ������
class ELEMENT_API OgdcPrjParams  
{
public:
	//!  \brief ͶӰ����Ĭ�Ϲ��캯��
	OgdcPrjParams();
	//!  \brief ͶӰ����Ĭ����������
	virtual ~OgdcPrjParams();
	//!  \brief ͶӰ�����������캯��
	OgdcPrjParams(const OgdcPrjParams& prjParams);

public:
	//!  \brief ���ز����� =
	OgdcPrjParams& operator=(const OgdcPrjParams& prjParams);
	//!  \brief ���ز����� ==
	OgdcBool operator==(const OgdcPrjParams& prjParams);
	//!  \brief ���ز����� !=
	OgdcBool operator!=(const OgdcPrjParams& prjParams);

public:
	//! \brief ͶӰ��λ��
	OgdcDouble m_dAzimuth;
	//! \brief ���뾭�߾���			
	OgdcDouble m_dCentralMeridian;
	//! \brief ����γ��γ��
	OgdcDouble m_dCentralParallel;
	//! \brief ���궫ƫ
	OgdcDouble m_dFalseEasting;	
	//! \brief ���걱ƫ
	OgdcDouble m_dFalseNorthing;
	//! \brief ��һ�㾭��
	OgdcDouble m_dFirstPointLongitude;
	//! \brief �ڶ��㾭��
	OgdcDouble m_dSecondPointLongitude;
	//! \brief ��������
	OgdcDouble m_dScaleFactor;
	//! \brief ��һ��׼γ��
	OgdcDouble m_dStandardParallel1;
	//! \brief �ڶ���׼γ��
	OgdcDouble m_dStandardParallel2;	

};

}

#endif // !defined(AFX_OGDCPRJPARAMS_H__FAB41755_9ABC_4FF5_A375_7637A7E95C7D__INCLUDED_)

