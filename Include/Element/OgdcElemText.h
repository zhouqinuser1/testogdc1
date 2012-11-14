// OgdcElemText.h: interface for the OgdcElemText class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemText.h
//!  \brief �ı�
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMTEXT_H__77E3E80E_0DC6_4BDD_A383_953B585BC8BA__INCLUDED_)
#define AFX_OGDCELEMTEXT_H__77E3E80E_0DC6_4BDD_A383_953B585BC8BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"
#include "Base/OgdcTextStyle.h"

namespace OGDC {
//!  \brief �ı�������
class ELEMENT_API OgdcElemText : public OgdcElement  
{
public:
	//!  \brief �ı�����Ĭ�Ϲ��캯��
	OgdcElemText();
	//!  \brief �ı�����Ĭ����������
	virtual ~OgdcElemText();

public:
	//! \brief  �õ��ı���������
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����-1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �����ı�����
	OgdcBool Make(const OgdcElemText* pElement);
		
	//! \brief  �����ı�����
	//! \param  points ���ı����������顣
	//! \param  strTexts ���ı����顣
	//! \param  angles �Ӷ�����ת�Ƕ�����
	//! \param  pTextStyle �ı����
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points,
				const OgdcStringArray& strTexts,
				const OgdcArray<OgdcDouble>& angles,
				const OgdcTextStyle& textStyle);			
	
public:
	//! \brief ���ı����������顣
	OgdcArray<OgdcPoint2D> m_points;
	//! \brief ���ı����顣
	OgdcStringArray m_strTexts;
	//! \brief �Ӷ�����ת�Ƕ�����
	OgdcArray<OgdcDouble> m_angles;	
	//! \brief �ı����
	OgdcTextStyle m_textStyle;					

};

}

#endif // !defined(AFX_OGDCELEMTEXT_H__77E3E80E_0DC6_4BDD_A383_953B585BC8BA__INCLUDED_)

