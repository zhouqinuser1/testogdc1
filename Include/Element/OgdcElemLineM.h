// OgdcElemLineM.h: interface for the OgdcElemLineM class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemLineM.h
//!  \brief �̶���
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMLINEM_H__5B4E67E5_EF29_4803_9D6B_975F03262FF9__INCLUDED_)
#define AFX_OGDCELEMLINEM_H__5B4E67E5_EF29_4803_9D6B_975F03262FF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief �̶��߶���
class ELEMENT_API OgdcElemLineM : public OgdcElement  
{
public:
	//!  \brief �̶��߶���Ĭ�Ϲ��캯��
	OgdcElemLineM();
	//!  \brief �̶��߶���Ĭ����������
	virtual ~OgdcElemLineM();

public:
	//! \brief  �õ��̶��߶������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �����̶��߶���
	OgdcBool Make(const OgdcElemLineM* pElement);
		
	//! \brief  �����̶��߶���
	//! \param  points �����顣
	//! \param  measures ������Ŀ̶ȡ�
	//! \param  polyCounts �Ӷ���������Ϣ��
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points, 
				const OgdcArray<OgdcDouble>& measures, 
				const OgdcArray<OgdcInt>& polyCounts);			
	
public:
	//! \brief �ڲ��õ��������洢��������ꡣ
	OgdcArray<OgdcPoint2D> m_points;
	//! \brief ��������Ŀ̶ȡ�
	OgdcArray<OgdcDouble> m_measures;
	//! \brief �����Ӷ���������Ϣ
	OgdcArray<OgdcInt> m_polyCounts;			

};

}

#endif // !defined(AFX_OGDCELEMLINEM_H__5B4E67E5_EF29_4803_9D6B_975F03262FF9__INCLUDED_)

