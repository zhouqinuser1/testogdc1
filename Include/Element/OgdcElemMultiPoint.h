// OgdcElemMultiPoint.h: interface for the OgdcElemMultiPoint class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemMultiPoint.h
//!  \brief ���
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMMULTIPOINT_H__A103F871_584F_46BD_BAEB_0423BA288815__INCLUDED_)
#define AFX_OGDCELEMMULTIPOINT_H__A103F871_584F_46BD_BAEB_0423BA288815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ��������
class ELEMENT_API OgdcElemMultiPoint : public OgdcElement  
{
public:
	//!  \brief ������Ĭ�Ϲ��캯��
	OgdcElemMultiPoint();
	//!  \brief ������Ĭ����������
	virtual ~OgdcElemMultiPoint();

public:
	//! \brief  �õ����������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����0ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ����������
	OgdcBool Make(const OgdcElemMultiPoint* pElement);
		
	//! \brief  ����������
	//! \param  points �����顣
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points);			
	
public:
	//! \brief �ڲ��õ��������洢��������ꡣ
	OgdcArray<OgdcPoint2D> m_points;			

};

}

#endif // !defined(AFX_OGDCELEMMULTIPOINT_H__A103F871_584F_46BD_BAEB_0423BA288815__INCLUDED_)

