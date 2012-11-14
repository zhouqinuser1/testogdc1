// OgdcElemCurve.h: interface for the OgdcElemCurve class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemCurve.h
//!  \brief DGN Curve ����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMCURVE_H__B449596F_FA0F_4319_AF84_9E7B57FF0D0F__INCLUDED_)
#define AFX_OGDCELEMCURVE_H__B449596F_FA0F_4319_AF84_9E7B57FF0D0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief DGN Curve ������
class ELEMENT_API OgdcElemCurve : public OgdcElement  
{
public:
	//! \brief Curve����Ĭ�Ϲ��캯��
	OgdcElemCurve();
	//! \brief Curve����Ĭ����������
	virtual ~OgdcElemCurve();

public:
	//! \brief  �õ����߶������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �������߶���
	OgdcBool Make(const OgdcElemCurve* pElement);
		
	//! \brief  �������߶���
	//! \param  points �����顣
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points);			
	
public:
	//! \brief �õ��������洢��������ꡣ
	OgdcArray<OgdcPoint2D> m_points;			

};

}


#endif // !defined(AFX_OGDCELEMCURVE_H__B449596F_FA0F_4319_AF84_9E7B57FF0D0F__INCLUDED_)

