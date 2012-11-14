// OgdcElemCompound.h: interface for the OgdcElemCompound class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemCompound.h
//!  \brief ���϶���
//!  \details ����������ж���
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMCOMPOUND_H__BD229B91_EDA3_4357_9EC1_57E490A35122__INCLUDED_)
#define AFX_OGDCELEMCOMPOUND_H__BD229B91_EDA3_4357_9EC1_57E490A35122__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ���϶�����
class ELEMENT_API OgdcElemCompound : public OgdcElement  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcElemCompound();
	//! \brief Ĭ����������
	virtual ~OgdcElemCompound();

public:
	//! \brief  �õ����϶������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����-1ά��
	virtual OgdcInt GetStyleDimension() const;

	//! \brief  �������϶���
	OgdcBool Make(const OgdcElemCompound* pElement);	
	
	//! \brief  ��ն���
	void Clear();	
	
public:
	//! \brief ���϶����а����ļ��ζ������顣
	OgdcArray<OgdcElement*> m_elements;			

};

}

#endif // !defined(AFX_OGDCELEMCOMPOUND_H__BD229B91_EDA3_4357_9EC1_57E490A35122__INCLUDED_)

