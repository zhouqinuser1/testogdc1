// OgdcElemFactory.h: interface for the OgdcElemFactory class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElemFactory.h
//!  \brief ���ζ��󹤳�
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMFACTORY_H__244F3B3F_FFBD_4586_B5E1_ABCF70E26CA6__INCLUDED_)
#define AFX_OGDCELEMFACTORY_H__244F3B3F_FFBD_4586_B5E1_ABCF70E26CA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {

//! \brief �ص�������������չ�������
//! \param 		pElement		�ⲿҪ��������չ����
//! \param 		nType		��չ���������
//! \param 		pVoid			ʵ�ָûص����������ָ��
typedef void (OGDCSTDCALL *CREATEELEMENTEXTENDCALLBACKPROC)
(OgdcElement** pElement, OgdcInt nType, void* pVoid);
//!  \brief ���ζ��󹤳���
class ELEMENT_API OgdcElemFactory  
{
public:
	//!  \brief ���ζ��󹤳���Ĭ�Ϲ��캯��
	OgdcElemFactory();
	//!  \brief ���ζ��󹤳���Ĭ����������
	virtual ~OgdcElemFactory();

public:
	//! \brief	����ָ�����͵ļ��ζ���
	//! \param	nType	���ζ������͡�
	static OgdcElement* CreateElement(OgdcInt nType);

	//! \brief  ��¡һ�����ζ���
	//! \param  pElement Ҫ����¡�ļ��ζ���ָ��, ����ΪNULL��
	static OgdcElement* CloneElement(const OgdcElement* pElement);

	//! \brief  ����һ�����ζ���
	//! \param  pElement ԭ���ζ���ָ��, ����ΪNULL��[in]
	//! \param  pResElement Ŀ�꼸�ζ���ָ��, ����ΪNULL��[out]	
	static OgdcBool CopyElement(const OgdcElement* pElement, OgdcElement* pResElement);

};

}

#endif // !defined(AFX_OGDCELEMFACTORY_H__244F3B3F_FFBD_4586_B5E1_ABCF70E26CA6__INCLUDED_)

