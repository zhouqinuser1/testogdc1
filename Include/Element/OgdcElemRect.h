// OgdcElemRect.h: interface for the OgdcElemRect class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemRect.h
//!  \brief ����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMRECT_H__FE530EC5_4893_49D7_B990_7DF785015E2B__INCLUDED_)
#define AFX_OGDCELEMRECT_H__FE530EC5_4893_49D7_B990_7DF785015E2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ���ζ�����
class ELEMENT_API OgdcElemRect : public OgdcElement  
{
public:
	//!  \brief ���ζ����캯��
	OgdcElemRect();
	//!  \brief ���ζ�����������
	virtual ~OgdcElemRect();

public:
	//! \brief  �õ����ζ������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �������ζ���
	OgdcBool Make(const OgdcElemRect* pElement);
		
	//! \brief  �������ζ���
	//! \param  pntCenter Բ��
	//! \param  dWidth ���
	//! \param  dHeight �߶�
	//! \param  dAngle �Ƕ�
	OgdcBool Make(const OgdcPoint2D& pntCenter,			
					OgdcDouble dWidth,		
					OgdcDouble dHeight,		
					OgdcDouble dAngle);		

public:
	//! \brief ���ĵ�
	OgdcPoint2D m_pntCenter;
	//! \brief ���
	OgdcDouble m_dWidth;
	//! \brief �߶�			
	OgdcDouble m_dHeight;
	//! \brief ��ת�Ƕ�			
	OgdcDouble m_dAngle;				

};

}

#endif // !defined(AFX_OGDCELEMRECT_H__FE530EC5_4893_49D7_B990_7DF785015E2B__INCLUDED_)

