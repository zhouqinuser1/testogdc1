//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcTextStyle.h
//!  \brief �ı������ 
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCTEXTSTYLE_H__AD2CEE70_B618_484B_B4AD_ABF76D28DF21__INCLUDED_)
#define AFX_OGDCTEXTSTYLE_H__AD2CEE70_B618_484B_B4AD_ABF76D28DF21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcString.h"

namespace OGDC{
//!  \brief �ı������ 
class BASE_API OgdcTextStyle  
{

public:
	//! \brief ������ɫ
	OgdcColor	m_clrFore;
	//! \brief ����ɫ����Ӱɫ�����ɫ
	OgdcColor	m_clrBack;
	//! \brief ��ת�Ƕȣ��Զ�Ϊ��λ,x����������Ϊ��ʼ����ʱ�뷽��
	OgdcDouble	m_dAngle;	
	//! \brief ��ת�Ƕȣ��Զ�Ϊ��λ,x����������Ϊ��ʼ����ʱ�뷽��
	OgdcDouble	m_dItalicAngle;	
	//! \brief �����ȣ�����λ
	OgdcDouble	m_dWidth;
	//! \brief ����߶ȣ�����λ			
	OgdcDouble	m_dHeight;	
	//! \brief �ʻ���ȣ� 100��200��300��400��500��600��700
	OgdcInt		m_nWeight;	
	//! ���:���壬б�壬͸��������,���е�
	OgdcInt		m_nStyle;
	//! \brief ���뷽ʽ	0-11��ֵ����뷽ʽ�Ĺ�ϵ����ͼ
	//! \image html TextStyle_m_nAlign.png                         
	OgdcByte m_nAlign;
	//! \brief �Ƿ����
	OgdcBool m_bBold;
	//! \brief �Ƿ��»���
	OgdcBool m_bUnderline;	
	//! \brief �Ƿ�б��
	OgdcBool m_bItalic;	
	//! \brief �Ƿ�ɾ����
	OgdcBool m_bStrikeOut;	
	//! \brief �Ƿ�̶���С
	OgdcBool m_bFixedSize;	
	//! \brief �Ƿ񱳾���͸��
	OgdcBool m_bBackOpaque;	
	//! \brief �Ƿ���ʾ���
	OgdcBool m_bHalo;
	//! \brief �Ƿ���ʾ��Ӱ
	OgdcBool m_bShadow;	
	//! \brief ��������			
	OgdcString	m_strFaceName;			
	
public:
	//! \brief ����һ���ı�������
	OgdcTextStyle();
    
	//! \brief Ĭ����������
	~OgdcTextStyle();
	//! \brief �������캯��
    OgdcTextStyle& operator = (const OgdcTextStyle& textStyle);

};


}

#endif // !defined(AFX_OGDCTEXTSTYLE_H__AD2CEE70_B618_484B_B4AD_ABF76D28DF21__INCLUDED_)

