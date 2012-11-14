// OgdcElemPoint3D.h: interface for the OgdcElemPoint3D class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemPoint3D.h
//!  \brief ��ά�򵥵�
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMPOINT3D_H__C43B8D48_A64B_4C05_8F08_00EC6B753EA8__INCLUDED_)
#define AFX_OGDCELEMPOINT3D_H__C43B8D48_A64B_4C05_8F08_00EC6B753EA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"
#include "Base/OgdcPoint3D.h"

namespace OGDC {
//!  \brief ��ά�򵥵������
class ELEMENT_API OgdcElemPoint3D : public OgdcElement  
{
public:
	//!  \brief ��ά�򵥵����Ĭ�Ϲ��캯��
	OgdcElemPoint3D();
	//!  \brief ��ά�򵥵����Ĭ����������
	virtual ~OgdcElemPoint3D();

public:
	//! \brief  �õ���ά�򵥵�������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����0ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ������ά�򵥵����
	OgdcBool Make(const OgdcElemPoint3D* pElement);
		
	//! \brief  ������ά�򵥵����
	//! \param  point ��ά�����ꡣ
	OgdcBool Make(const OgdcPoint3D& point);			
	
public:
	//! \brief ��ά�����ꡣ
	OgdcPoint3D m_point;			

};

}

#endif // !defined(AFX_OGDCELEMPOINT3D_H__C43B8D48_A64B_4C05_8F08_00EC6B753EA8__INCLUDED_)

