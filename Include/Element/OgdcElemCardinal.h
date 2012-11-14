// OgdcElemCardinal.h: interface for the OgdcElemCardinal class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemCardinal.h
//!  \brief Cardinal����
//!  \details 
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMCARDINAL_H__A491E56C_2000_4A40_B48E_C765927B73BF__INCLUDED_)
#define AFX_OGDCELEMCARDINAL_H__A491E56C_2000_4A40_B48E_C765927B73BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief Cardinal����
class ELEMENT_API OgdcElemCardinal : public OgdcElement  
{
public:
	//! \brief Ĭ�Ϲ��캯��������Cardinal���߶���
	OgdcElemCardinal();
	//! \brief Ĭ����������
	virtual ~OgdcElemCardinal();

public:
	//! \brief  �õ�Cardinal���ߵ����͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ����Cardinal���߶���
	OgdcBool Make(const OgdcElemCardinal* pElement);
		
	//! \brief  ����Cardinal���߶���
	//! \param  points �����顣
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points);			
	
public:
	//! \brief �õ��������洢��������ꡣ
	OgdcArray<OgdcPoint2D> m_points;			

};

}

#endif // !defined(AFX_OGDCELEMCARDINAL_H__A491E56C_2000_4A40_B48E_C765927B73BF__INCLUDED_)

