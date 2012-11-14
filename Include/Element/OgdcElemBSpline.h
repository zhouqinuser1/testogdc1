// OgdcElemBSpline.h: interface for the OgdcElemBSpline class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemBSpline.h
//!  \brief ����B����
//!  \details 
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMBSPLINE_H__5ACC78F4_E7F6_4E1C_881B_CB02BFC714A9__INCLUDED_)
#define AFX_OGDCELEMBSPLINE_H__5ACC78F4_E7F6_4E1C_881B_CB02BFC714A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ����B���������࣬�洢�˹���B�������ߵ�����㴮��
class ELEMENT_API OgdcElemBSpline : public OgdcElement  
{
public:
	//! \brief Ĭ�Ϲ��캯��������B�������߶���
	OgdcElemBSpline();
	//! \brief Ĭ����������
	virtual ~OgdcElemBSpline();

public:
	//! \brief  �õ�ElemBSpline���͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ����OgdcElemBSpline����
	OgdcBool Make(const OgdcElemBSpline* pElement);
		
	//! \brief  ����OgdcElemBSpline����
	//! \param  points �����顣
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points);			
	
public:
	//! \brief �õ��������洢��������ꡣ
	OgdcArray<OgdcPoint2D> m_points;			

};

}

#endif // !defined(AFX_OGDCELEMBSPLINE_H__5ACC78F4_E7F6_4E1C_881B_CB02BFC714A9__INCLUDED_)

