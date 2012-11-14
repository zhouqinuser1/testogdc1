// OgdcElemPoint.h: interface for the OgdcElemPoint class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemPoint.h
//!  \brief �򵥵�
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMPOINT_H__8CEB9DD6_0A81_4F28_BD35_FFBBC3D1831B__INCLUDED_)
#define AFX_OGDCELEMPOINT_H__8CEB9DD6_0A81_4F28_BD35_FFBBC3D1831B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief �򵥵������
class ELEMENT_API OgdcElemPoint : public OgdcElement  
{
public:
	//!  \brief �����Ĭ�Ϲ��캯��
	OgdcElemPoint();
	//!  \brief �����Ĭ����������
	virtual ~OgdcElemPoint();

public:
	//! \brief  �õ��򵥵�������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����0ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �����򵥵����
	OgdcBool Make(const OgdcElemPoint* pElement);
		
	//! \brief  �����򵥵����
	//! \param  point �����ꡣ
	OgdcBool Make(const OgdcPoint2D& point);			
	
public:
	//! \brief �����ꡣ
	OgdcPoint2D m_point;			

};

}

#endif // !defined(AFX_OGDCELEMPOINT_H__8CEB9DD6_0A81_4F28_BD35_FFBBC3D1831B__INCLUDED_)

