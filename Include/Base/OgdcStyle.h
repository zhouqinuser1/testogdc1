//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcStyle.h
//!  \brief ���ζ�������
//!  \details
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCSTYLE_H__9D5373BD_BA56_420C_8D25_C46E8D809C90__INCLUDED_)
#define AFX_OGDCSTYLE_H__9D5373BD_BA56_420C_8D25_C46E8D809C90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"

namespace OGDC{
//! \brief ��ˢ����
typedef enum tagBrushGradientMode
{
	//! \brief һ������
	scbGradientNone	    = 0,
	//! \brief ����
	scbGradientLinear	= 1,
	//! \brief ����״
	scbGradientRadial	= 2,
    //! \brief Բ׶��
	scbGradientConical	= 3,
    //! \brief ֱ����
	scbGradientSquare	= 4,    
		
}OGDCBrushGradientMode;

//!  \brief ���ζ�������
class BASE_API OgdcStyle  
{
public:	
	//! \brief �������ͣ����Ͷ������û��ķ��ſ���
	OgdcInt    m_nMarkerStyle; 
    //! \brief ���ŵ���ת�Ƕ�  ��λ����
	OgdcDouble m_dMarkerAngle;
	//! \brief ���Ŵ�С   
	OgdcInt    m_nMarkerSize;
	//! \brief ���ſ��
	OgdcInt m_nMarkerWidth;
	//! \brief ���Ÿ߶�
	OgdcInt m_nMarkerHeight;
	//! \brief �������ͣ����Ͷ������û������Կ���
	OgdcInt    m_nLineStyle;  
	//! \brief ������ɫ 
	OgdcColor  m_clrLine;
	//! \brief ���Ϳ��
	OgdcInt    m_nLineWidth;  
	
	//! \brief ������ͣ����Ͷ������û���������
	OgdcInt    m_nFillStyle; 
	//! \brief ������͵ı���ɫ
	OgdcColor  m_clrFillBack; 
	//! \brief ������͵�ǰ��ɫ
	OgdcColor  m_clrFillFore;  
    //! \brief ������ͱ����Ƿ�͸��
	OgdcBool   m_bFillBackOpaque;
	//! \brief ������͵�͸����
	OgdcByte   m_btFillOpaqueRate;
	//! \brief ���Ľ�������
	OgdcByte   m_btFillGradientType;
	//! \brief ���Ƕ�
	OgdcDouble m_dFillAngle;
	//! \brief ������ͺ�����λ�õ�Xƫ����	  
	OgdcShort  m_nFillCenterOffsetX;
	//! \brief ������ͺ�����λ�õ�Yƫ����
	OgdcShort  m_nFillCenterOffsetY; 
	//! \brief ����ŵĴ�С
	OgdcBool	m_bSymbolScale;	
public:

	//! \brief Ĭ�Ϲ��캯��
	OgdcStyle();
	//! \brief Ĭ����������
	~OgdcStyle();
	//! \brief ���� =
	OgdcStyle& operator = (const OgdcStyle &style);

};

}

#endif // !defined(AFX_OGDCSTYLE_H__9D5373BD_BA56_420C_8D25_C46E8D809C90__INCLUDED_)

