// OgdcElemMultiPoint3D.h: interface for the OgdcElemMultiPoint3D class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcElemMultiPoint3D.h
//!  \brief ��ά���
//!  \details 
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMMULTIPOINT3D_H__07575210_9EAA_40E3_8E8E_7E326EC91765__INCLUDED_)
#define AFX_OGDCELEMMULTIPOINT3D_H__07575210_9EAA_40E3_8E8E_7E326EC91765__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"
#include "Base/OgdcPoint3D.h"

namespace OGDC {
//!  \brief ��ά������
class ELEMENT_API OgdcElemMultiPoint3D : public OgdcElement  
{
public:
	//!  \brief ��ά������Ĭ�Ϲ��캯��
	OgdcElemMultiPoint3D();
	//!  \brief ��ά������Ĭ����������
	virtual ~OgdcElemMultiPoint3D();

public:
	//! \brief  �õ���ά���������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����0ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ������ά������
	OgdcBool Make(const OgdcElemMultiPoint3D* pElement);
		
	//! \brief  ������ά������
	//! \param  points ��ά�����顣
	OgdcBool Make(const OgdcArray<OgdcPoint3D>& points);			
	
public:
	//! \brief �ڲ��õ��������洢��������ꡣ
	OgdcArray<OgdcPoint3D> m_points;			

};

}

#endif // !defined(AFX_OGDCELEMMULTIPOINT3D_H__07575210_9EAA_40E3_8E8E_7E326EC91765__INCLUDED_)

