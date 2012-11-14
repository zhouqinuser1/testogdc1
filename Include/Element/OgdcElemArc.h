// OgdcElemArc.h: interface for the OgdcElemArc class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)            
//                                                           
//!  \file OgdcElemArc.h
//!  \brief Բ��
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMARC_H__C5139B5D_ECF1_4F93_AB99_C5718FBEE7EC__INCLUDED_)
#define AFX_OGDCELEMARC_H__C5139B5D_ECF1_4F93_AB99_C5718FBEE7EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief Բ�������࣬�洢��Բ������ʼ�㣬�м�����ֹ�㡣
class ELEMENT_API OgdcElemArc : public OgdcElement  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcElemArc();
	//! \brief Ĭ����������
	virtual ~OgdcElemArc();

public:
	//! \brief  �õ�ElemArc���͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ����OgdcElemArc����
	OgdcBool Make(const OgdcElemArc* pElement);

	 //! \brief  ����OgdcElemArc����
	 //! \param  pntStart ��ʼ�㡣
	 //! \param  pntMiddle �м�㡣
	 //! \param  pntEnd ��ֹ�㡣
	OgdcBool Make(const OgdcPoint2D& pntStart,
				const OgdcPoint2D& pntMiddle,			
				const OgdcPoint2D& pntEnd);	

public:
	//! \brief ��ʼ��
	OgdcPoint2D m_pntStart;	
	//! \brief �м��			
	OgdcPoint2D m_pntMiddle;
	//! \brief ��ֹ��			
	OgdcPoint2D m_pntEnd;					

};

}

#endif // !defined(AFX_OGDCELEMARC_H__C5139B5D_ECF1_4F93_AB99_C5718FBEE7EC__INCLUDED_)

