// OgdcElemRectRound.h: interface for the OgdcElemRectRound class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcElemRectRound.h
//!  \brief Բ�Ǿ���
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMRECTROUND_H__D1E033A1_CC4B_4107_948D_07C77C85D8F0__INCLUDED_)
#define AFX_OGDCELEMRECTROUND_H__D1E033A1_CC4B_4107_948D_07C77C85D8F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief Բ�Ǿ��ζ�����
class ELEMENT_API OgdcElemRectRound : public OgdcElement  
{
public:
	//!  \brief Բ�Ǿ��ζ���Ĭ�Ϲ��캯��
	OgdcElemRectRound();
	//!  \brief Բ�Ǿ��ζ���Ĭ����������
	virtual ~OgdcElemRectRound();

public:
	//! \brief  �õ�Բ�Ǿ��ζ������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;

	//! \brief  ����Բ�Ǿ��ζ���
	OgdcBool Make(const OgdcElemRectRound* pElement);
		
	//! \brief  ����Բ�Ǿ��ζ���
	//! \param  pntCenter Բ��
	//! \param  dWidth ���
	//! \param  dHeight �߶�
	//! \param  dAngle �Ƕ�
	//! \param  dRadiusX Բ�ǳ�����
	//! \param  dRadiusY Բ�Ƕ̰���
	OgdcBool Make(const OgdcPoint2D& pntCenter,			
					OgdcDouble dWidth,		
					OgdcDouble dHeight,		
					OgdcDouble dAngle,		
					OgdcDouble dRadiusX,		
					OgdcDouble dRadiusY);		

public:
	//! \brief ���ĵ�
	OgdcPoint2D m_pntCenter;
	//! \brief ���
	OgdcDouble m_dWidth;
	//! \brief �߶�			
	OgdcDouble m_dHeight;
	//! \brief ��ת�Ƕ�			
	OgdcDouble m_dAngle;
	//! \brief Բ�ǳ�����
	OgdcDouble m_dRadiusX;
	//! \brief Բ�Ƕ̰���			
	OgdcDouble m_dRadiusY;				


};

}

#endif // !defined(AFX_OGDCELEMRECTROUND_H__D1E033A1_CC4B_4107_948D_07C77C85D8F0__INCLUDED_)

