//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcProviderManager.h
//!  \brief OgdcProviderManager �Ľӿڶ��塣
//!  \details Ogdc���涯̬���ع������Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef OGDCPROVIDERMANAGER_H
#define OGDCPROVIDERMANAGER_H

#include "OGDC/OgdcProvider.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace  OGDC
{


//! \brief BeforeLoadSDX �¼��ص�����
typedef void (OGDCSTDCALL *BeforeLoadSDXProc)(OgdcInt nType,OgdcBool& bCancel);


//! \brief Ogdc���涯̬���ع�������
class OGDC_API OgdcProviderManager  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcProviderManager();
	//! \brief Ĭ����������
#ifdef SYMBIAN60
	~OgdcProviderManager();
#else
	virtual ~OgdcProviderManager();
#endif

public:
	//! \brief 	��������Դʵ����
	//! \param 	nEngineType �����������ͣ��������û���չ���������͡�
	//! \return new����������Դָ�룬����������ɹ��ͷ���NULL��
	//! \remarks ��������������������һ������Դ�������������ݿ⣬
	//!	��������ָ��������Դ���ʹ���һ��UGDataSourceʵ������������ָ�롣
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined IOS
	static OgdcDataSource* CreateOgdcDataSource(OgdcInt nEngineType);

	//! \brief 	����Featureʵ����
	//! \param 	nEngineType �����������ͣ��������û���չ���������͡�
	//! \return new������Featureָ�룬����������ɹ��ͷ���NULL��
	static OgdcFeature* CreateOgdcFeature(OgdcInt nEngineType);
#endif 

	//! \brief �õ���������Ŀ��
	static OgdcInt GetProviderCount();	

	//! \brief �õ����������塣
	//! \param nIndex [in] ������
	static OgdcProvider GetAt(OgdcInt nIndex);	

	//! \brief ��ȡ����������
	//! \param nType �������������
	static OgdcString GetProviderName(OgdcInt nEngineType);	

	//! \brief ��̬�������к�׺��Ϊsdx��odx��OGDC��������̬�⡣
	static void LoadAllProvider();

	//! \brief ж�������صĶ�̬��
	static void UnloadAllProvider();

	//! \brief ����һ����׺��Ϊsdxָ���ļ�����OGDC��������̬�⡣
	//! \param strPathName [in]��
	//! \return ���سɹ�����true��
	static OgdcBool LoadProvider(const OgdcString& strPathName);	

	//! \brief ж�غ�׺��Ϊsdx��OGDC��������̬�⡣
	//! \param hHandle [in] ��̬������
	//! \return �ɹ�ж�ط���true��
	static OgdcBool UnloadProvider(void* hHandle);	

	//! \brief ���ûص�����
	static void SetBeforeLoadSDXCallBack(BeforeLoadSDXProc pBeforeLoadSDXCallBack);

public:
	//! \brief ��������Դ�������Ͳ���һ�����������塣
	//! \param nEngineType ����Դ��������[in]��
	//! \param provider ����������[in]��
	//! \return ����ҵ��ͷ���true������ͷ���false��
	OgdcBool FindProvider(OgdcInt nEngineType, OgdcProvider& provider);		

protected:

	//! \brief ��̬�������к�׺��Ϊsdx��odx��OGDC��������̬�⡣
	void LoadProvider();

	//! \brief �ͷŶ�̬���ص�OGDC�������涯̬�⡣
	void UnloadProvider();
	
	//! \brief �ж�OGDC��������������Ƿ���Ч�������Ч�͹���һ�����������塣
	//! \param hHandle ���������[in]��
	//! \param provider ����������[in]��
	//! \return �����������Ч�ͷ���true������ͷ���false����
	OgdcBool CheckProvider(void* hHandle, OgdcProvider& provider);	
	
protected:
	//! \brief ��̬���ص�OGDC���������顣
	OgdcArray<OgdcProvider> m_providers;

	//! \brief �ص�������ʶ
	static BeforeLoadSDXProc ms_BeforeLoadSDXCallBack;
};

extern OGDC_API OgdcProviderManager g_providerManager;

}
#endif // !defined(OGDCPROVIDERMANAGER_H)

