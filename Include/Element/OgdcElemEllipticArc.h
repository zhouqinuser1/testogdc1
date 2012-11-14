// OgdcElemEllipticArc.h: interface for the OgdcElemEllipticArc class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemEllipticArc.h
//!  \brief ��Բ��
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMELLIPTICARC_H__F46DB9AC_143F_4A42_8753_E2B97A830BE3__INCLUDED_)
#define AFX_OGDCELEMELLIPTICARC_H__F46DB9AC_143F_4A42_8753_E2B97A830BE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ��Բ��������
class ELEMENT_API OgdcElemEllipticArc : public OgdcElement  
{
public:
	//! \brief ��Բ��Ĭ�Ϲ��캯��
	OgdcElemEllipticArc();
	//! \brief ��Բ��Ĭ�Ϲ��캯��
	virtual ~OgdcElemEllipticArc();

public:
	//! \brief  �õ���Բ���������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ���� ��Բ������
	OgdcBool Make(const OgdcElemEllipticArc* pElement);
		
	//! \brief  ���� ��Բ������
	//! \param  pntCenter Բ��
	//! \param  dSemiMajorAxis ������
	//! \param  dSemiMinorAxis �̰���
	//! \param  dAngle ��ת�Ƕ�
	//! \param  dStartAngle ���
	//! \param  dEndAngle �ս�
	OgdcBool Make(const OgdcPoint2D& pntCenter,			
					OgdcDouble dSemiMajorAxis,		
					OgdcDouble dSemiMinorAxis,		
					OgdcDouble dAngle,		
					OgdcDouble dStartAngle,			
					OgdcDouble dEndAngle);		

public:
	//! \brief Բ��
	OgdcPoint2D m_pntCenter;
	//! \brief ������
	OgdcDouble m_dSemiMajorAxis;
	//! \brief �̰���
	OgdcDouble m_dSemiMinorAxis;
	//! \brief ��ת�Ƕ�
	OgdcDouble m_dAngle;
	//! \brief ���			
	OgdcDouble m_dStartAngle;
	//! \brief �ս�
	OgdcDouble m_dEndAngle;				

};

}

#endif // !defined(AFX_OGDCELEMELLIPTICARC_H__F46DB9AC_143F_4A42_8753_E2B97A830BE3__INCLUDED_)

