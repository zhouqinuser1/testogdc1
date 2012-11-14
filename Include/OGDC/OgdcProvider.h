//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcProvider.h
//!  \brief OgdcProvider �Ľӿڶ��塣
//!  \details Ogdc�����������ࡣ
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCPROVIDER_H
#define OGDCPROVIDER_H

#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined IOS
#include "OgdcDataSource.h"
#else
#include "Engine/UGDataSource.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

//! \brief Ogdc�����������ࡣ
class OGDC_API OgdcProvider  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcProvider();
	//! \brief �������캯��
	OgdcProvider(const OgdcProvider& provider);
	//! \brief Ĭ����������
#ifdef SYMBIAN60
	~OgdcProvider();
#else
	virtual ~OgdcProvider();
#endif

public:
	//! \brief ���ز����� =
	const OgdcProvider& operator=(const OgdcProvider& provider);
	//! \brief ���ز����� ==
	OgdcBool operator ==(const OgdcProvider& provider);
	//! \brief ���ز����� !=
	OgdcBool operator !=(const OgdcProvider& provider);

	//! \brief 	��������Դʵ����
	//! \return new����������Դָ�룬����������ɹ��ͷ���NULL��
	//! \remarks ��������������������һ������Դ�������������ݿ⣬
	//!	��������ָ��������Դ���ʹ���һ��UGDataSourceʵ������������ָ�롣
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined IOS
	OgdcDataSource* CreateOgdcDataSource();
	
	//! \brief ��������Ҫ��Feature��
	//! \return new����������Ҫ��ָ�룬����������ɹ��ͷ���NULL��
	OgdcFeature* CreateOgdcFeature();
#else
	UGC::UGDataSource* CreateDataSource();
#endif

	//! \brief ��ȡ�ļ�������ĺ�׺��
	OgdcString GetPostfix();

	//! \brief ��ȡ����ķ���
	OgdcInt GetEngineClass();
public:
	//! \brief �������͡�
	OgdcInt m_nType;

	//! \brief �������ơ�
	OgdcString m_strName;

	//! \brief ������࣬1�������ݿ⣬2�����ļ��ͣ�3��������͡�
	OgdcInt m_nEngineClass;

	//! \brief 2�����ļ�������Դ���ļ���׺����
	OgdcString m_strPostfix;

	//! \brief �����ָ�롣
	void* m_hHandle;
};

}
#endif // !defined(OGDCPROVIDER_H)

