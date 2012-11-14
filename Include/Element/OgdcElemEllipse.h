// OgdcElemEllipse.h: interface for the OgdcElemEllipse class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemEllipse.h
//!  \brief ��Բ
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMELLIPSE_H__DDD92B30_88E8_46F8_8A23_6D1ED8B7CD9E__INCLUDED_)
#define AFX_OGDCELEMELLIPSE_H__DDD92B30_88E8_46F8_8A23_6D1ED8B7CD9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ��Բ������
class ELEMENT_API OgdcElemEllipse : public OgdcElement  
{
public:
	//! \brief ��ԲĬ�Ϲ��캯��
	OgdcElemEllipse();
	//! \brief ��ԲĬ����������
	virtual ~OgdcElemEllipse();

public:
	//! \brief  �õ���Բ�������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ������Բ����
	OgdcBool Make(const OgdcElemEllipse* pElement);
		
	//! \brief  ������Բ����
	//! \param  pntCenter Բ��
	//! \param  dSemiMajorAxis ������
	//! \param  dSemiMinorAxis �̰���
	//! \param  dAngle �Ƕ�
	OgdcBool Make(const OgdcPoint2D& pntCenter,			
					OgdcDouble dSemiMajorAxis,		
					OgdcDouble dSemiMinorAxis,		
					OgdcDouble dAngle);		

public:
	//! \brief Բ��
	OgdcPoint2D m_pntCenter;
	//! \brief ������
	OgdcDouble m_dSemiMajorAxis;
	//! \brief �̰���
	OgdcDouble m_dSemiMinorAxis;
	//! \brief �Ƕ�
	OgdcDouble m_dAngle;				

};

}

#endif // !defined(AFX_OGDCELEMELLIPSE_H__DDD92B30_88E8_46F8_8A23_6D1ED8B7CD9E__INCLUDED_)

