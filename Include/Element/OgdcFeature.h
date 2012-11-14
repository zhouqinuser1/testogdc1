//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcFeature.h
//!  \brief OgdcFeature �Ľӿڶ��塣
//!  \details Ogdc ����Ҫ���ࡣ
//!  \author duxiaomin��
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCFEATURE_H
#define OGDCFEATURE_H

#include "Base/OgdcVariant.h"
#include "Element/OgdcFieldInfo.h"

#if !defined SYMBIAN60 && !defined OS_ANDROID
#include "Element/OgdcElement.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

class OgdcDatasetVector;

//! \brief Ogdc ����Ҫ���ࡣ
#ifdef SYMBIAN60
class ELEMENT_APIC OgdcFeature
#else
class ELEMENT_API OgdcFeature
#endif
{
public:
#ifdef SYMBIAN60
	struct ELEMENT_APIC OgdcFieldDefine 
#else
	struct ELEMENT_API OgdcFieldDefine
#endif
	{
		//! \brief �ֶ����ơ�
		OgdcString m_strName;
		
		//! \brief �ֶ����͡�
		OgdcFieldInfo::FieldType m_nType;
		
		//! \brief �ֶγ��ȡ�
		OgdcInt m_nSize;

		//! \brief �Ƿ��Ǳ����ֶΡ�
		OgdcBool m_bRequired;

		//! \brief Ĭ�Ϲ��캯��
		OgdcFieldDefine();
		//! \brief ����=
		const OgdcFieldDefine& operator =(const OgdcFieldDefine& fieldDefine);
	};

public:
	//!  \brief ����Ҫ��Ĭ�Ϲ��캯��
	ELEMENT_APIF OgdcFeature();
	//!  \brief ����Ҫ��Ĭ����������
	virtual ELEMENT_APIF ~OgdcFeature();

public:
	//! \brief ��ȡ���ζ���ID��
	virtual ELEMENT_APIF OgdcInt GetID() const = 0;	
	
	//! \brief ���ü��ζ���ID��
	//! \param nID ���ζ���ID[in]��
	virtual ELEMENT_APIF void SetID(OgdcInt nID) = 0;	

#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined IOS
	//! \brief ��ȡ���ζ���
	//! \return �Ƿ�ȡ���ζ���ɹ����ɹ����ػ�ȡ���ļ��ζ���ʧ�ܷ���NULL��
	virtual ELEMENT_APIF OgdcElement* GetElement() = 0;	
	
	//! \brief ���õ�ǰ����Ҫ�صļ��ζ���
	//! \param pElement ���ζ���ָ��[in]��
	virtual ELEMENT_APIF void SetElement(OgdcElement* pElement) = 0;
#endif

	//! \brief �����ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varValue �ֶ�ֵ[out]��
	virtual ELEMENT_APIF OgdcBool GetValue(OgdcInt nIndex, OgdcVariant& varValue) = 0;

	//! \brief �����ֶ�����ȡ�ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param varValue �ֶ�ֵ[out]��
	virtual ELEMENT_APIF OgdcBool GetValue(const OgdcString& strFieldName, OgdcVariant& varValue) = 0;	

	//! \brief �����ֶ���������ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual ELEMENT_APIF OgdcBool SetValue(OgdcInt nIndex, const OgdcVariant& varValue) = 0;    

	//! \brief �����ֶ��������ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param varValue �ֶ�ֵ [in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual ELEMENT_APIF OgdcBool SetValue(const OgdcString& strFieldName, const OgdcVariant& varValue) = 0;		

public:
	//! \brief �����ֶ���Ϣ��
	//! \param fieldInfos �ֶ���Ϣ����[in]��
	virtual ELEMENT_APIF void SetFieldInfos(const OgdcFieldInfos& fieldInfos);	
	//! \brief ��ȡ�ַ���
	virtual ELEMENT_APIF OgdcString::Charset GetCharset() const;
	//! \brief �����ַ���
	virtual ELEMENT_APIF void SetCharset(OgdcString::Charset nCharset);

public:
	//! \brief ����Ҫ������ʸ�����ݼ������ֶ��б�
	OgdcArray<OgdcFieldDefine> m_fieldDefines;
};

}
#endif // !defined(OGDCFEATURE_H)

