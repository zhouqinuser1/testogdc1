// OgdcElemChord.h: interface for the OgdcElemChord class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemChord.h
//!  \brief ����
//!  \details 
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMCHORD_H__EFFF9CB0_D7D2_4654_A4B8_E623CEDC8B8F__INCLUDED_)
#define AFX_OGDCELEMCHORD_H__EFFF9CB0_D7D2_4654_A4B8_E623CEDC8B8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ���ζ�����
class ELEMENT_API OgdcElemChord : public OgdcElement  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcElemChord();
	//! \brief Ĭ����������
	virtual ~OgdcElemChord();

public:
	//! \brief  �õ�ElemChord���͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;

	//! \brief  �������ζ���
	OgdcBool Make(const OgdcElemChord* pElement);
		
	//! \brief  �������ζ���
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

#endif // !defined(AFX_OGDCELEMCHORD_H__EFFF9CB0_D7D2_4654_A4B8_E623CEDC8B8F__INCLUDED_)

