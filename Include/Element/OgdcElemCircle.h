// OgdcElemCircle.h: interface for the OgdcElemCircle class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemCircle.h
//!  \brief Բ
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMCIRCLE_H__13731CE5_B3E4_4595_A353_4B4164F8A434__INCLUDED_)
#define AFX_OGDCELEMCIRCLE_H__13731CE5_B3E4_4595_A353_4B4164F8A434__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief Բ������
class ELEMENT_API OgdcElemCircle : public OgdcElement  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcElemCircle();
	//! \brief Ĭ����������
	virtual ~OgdcElemCircle();

public:
	//! \brief  �õ�Բ�������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ����Բ����
	OgdcBool Make(const OgdcElemCircle* pElement);
		
	//! \brief  ����Բ����
	//! \param  pntCenter Բ��
	//! \param  dRadius �뾶
	OgdcBool Make(const OgdcPoint2D& pntCenter,	OgdcDouble dRadius);		

public:
	//! \brief Բ��
	OgdcPoint2D m_pntCenter;
	//! \brief �뾶
	OgdcDouble m_dRadius;				

};

}


#endif // !defined(AFX_OGDCELEMCIRCLE_H__13731CE5_B3E4_4595_A353_4B4164F8A434__INCLUDED_)

