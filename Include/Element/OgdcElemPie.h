// OgdcElemPie.h: interface for the OgdcElemPie class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemPie.h
//!  \brief ����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMPIE_H__DF3EE547_4B7C_4130_9E03_3EB1B44CD068__INCLUDED_)
#define AFX_OGDCELEMPIE_H__DF3EE547_4B7C_4130_9E03_3EB1B44CD068__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ���ζ�����
class ELEMENT_API OgdcElemPie : public OgdcElement  
{
public:
	//!  \brief ���ζ���Ĭ�Ϲ��캯��
	OgdcElemPie();
	//!  \brief ���ζ�����Ĭ����������
	virtual ~OgdcElemPie();

public:
	//! \brief  �õ����ζ������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �������ζ���
	OgdcBool Make(const OgdcElemPie* pElement);
		
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

#endif // !defined(AFX_OGDCELEMPIE_H__DF3EE547_4B7C_4130_9E03_3EB1B44CD068__INCLUDED_)

