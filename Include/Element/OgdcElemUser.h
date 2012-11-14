// OgdcElemUser.h: interface for the OgdcElemUser class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemUser.h
//!  \brief �û����弸�ζ���
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMUSER_H__4364E4C7_CE3C_4D28_BCDD_435E9389DC7A__INCLUDED_)
#define AFX_OGDCELEMUSER_H__4364E4C7_CE3C_4D28_BCDD_435E9389DC7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief �û����弸�ζ�����
class ELEMENT_API OgdcElemUser : public OgdcElement  
{
public:
	//!  \brief �û����弸�ζ���Ĭ�Ϲ��캯��
	OgdcElemUser();
	//!  \brief �û����弸�ζ���Ĭ����������
	virtual ~OgdcElemUser();

public:
	//! \brief  �õ��û����弸�ζ�������
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����-1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �����û����弸�ζ���
	OgdcBool Make(const OgdcElemUser* pElement);		
	
public:
	//! \brief �û��������ݡ�
	OgdcArray<OgdcUchar> m_data;			

};

}

#endif // !defined(AFX_OGDCELEMUSER_H__4364E4C7_CE3C_4D28_BCDD_435E9389DC7A__INCLUDED_)

