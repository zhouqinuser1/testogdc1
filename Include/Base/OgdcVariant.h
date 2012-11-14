//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcVariant.h
//!  \brief ������
//!  \details  
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCVARIANT_H__3DD52A73_5F64_43C1_9374_D128DF18117E__INCLUDED_)
#define AFX_OGDCVARIANT_H__3DD52A73_5F64_43C1_9374_D128DF18117E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcTime.h"

namespace OGDC{
//!  \brief ������
class BASE_API OgdcVariant  
{
public:
	//! \brief ֧�ֵ�����
	enum VarType
	{ 
		//! \brief δ���������
		Null			=	0, 
		//! \brief ���ֽ�����
		Byte			=	1,
		//! \brief ˫�ֽ���������
		Short			=	2,
		//! \brief ���ֽ���������
		Integer			=	3,
		//! \brief ���ֽ���������
		Long			=	4,
		//! \brief ���ֽڸ�������
		Float			=	5, 
		//! \brief ���ֽڸ�������
		Double			=	6,
		//! \brief ʱ������
		Time			=	7,
		//! \brief ����������
		Binary			=	8, 
		//! \brief �ַ���
		String			=   9,
		//! \brief ��������
		Date			=  10,
		//! \brief ʱ������� 
		TimeStamp		=  11,
		//! \brief ��������
		Boolean			= 12
	};//Ϊ����UGFieldInfo�е���������ʱ���������ֿ�����ԭ����time������չΪtime date timestamp������ο�UGFieldInfo�ж�Ӧ������

	struct binaryVal{   
		//! \brief �洢 Binary ָ����� Stringָ��
		void* pVal;	      
		//! \brief �洢Binary �������Ĵ�С ���ֽ�Ϊ��λ��
		OgdcUint nSize;   
	};
	
	//! \brief ��������
	union VarValue
	{
		OgdcUchar bVal;
		OgdcShort sVal;
		OgdcInt	iVal;
		OgdcLong  lVal;
		OgdcFloat fVal;
		OgdcDouble dVal;
		OgdcDouble   tmVal; // OgdcTime���ڲ�ʵ��
		struct binaryVal binVal;
	};
	
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcVariant();

	//! \brief ��������
	~OgdcVariant();

	//! \brief �������캯��
	OgdcVariant(const OgdcVariant& varSrc);

	//! \brief OgdcUchar���͹��캯��
	OgdcVariant(OgdcUchar bVal);
	//! \brief OgdcShort���͹��캯��
	OgdcVariant(OgdcShort sVal);
	//! \brief OgdcInt���͹��캯��
	OgdcVariant(OgdcInt iVal);
	//! \brief OgdcLong���͹��캯��
	OgdcVariant(OgdcLong lVal);
	//! \brief OgdcFloat���͹��캯��
	OgdcVariant(OgdcFloat fVal);
	//! \brief OgdcDouble���͹��캯��
	OgdcVariant(OgdcDouble dVal);
	//! \brief OgdcTime���͹��캯��
	OgdcVariant(const OgdcTime& tmVal);
	//! \brief OgdcUchar* ���͹��캯��
	//! \remarks �ڲ�Ϊ�ڴ濽�������ע���ͷ�pData;
	OgdcVariant(const OgdcUchar* pData,OgdcInt nSize);
	//! \brief OgdcString ���͹��캯��
	OgdcVariant(const OgdcString& str);	

	//! \brief �� varSrc ��ֵ���塣
	const OgdcVariant& operator=(const OgdcVariant& varSrc);
	//! \brief �� bVal ��ֵ����
	const OgdcVariant& operator=(OgdcUchar bVal);
	//! \brief �� sVal ��ֵ����
	const OgdcVariant& operator=(OgdcShort sVal);
	//! \brief �� iVal ��ֵ����
	const OgdcVariant& operator=(OgdcInt iVal);
	//! \brief �� lVal ��ֵ����
	const OgdcVariant& operator=(OgdcLong lVal);
	//! \brief �� fVal ��ֵ����
	const OgdcVariant& operator=(OgdcFloat fVal);
	//! \brief �� dVal ��ֵ����
	const OgdcVariant& operator=(OgdcDouble dVal);
	//! \brief �� tmVal ��ֵ����
	const OgdcVariant& operator=(const OgdcTime& tmVal);
	//! \brief �� str ��ֵ����
	const OgdcVariant& operator=(const OgdcString& str);

	//! \brief ���ñ���ֵΪbVal 
	void Set(OgdcUchar bVal);
    //! \brief ���ñ���ֵΪsVal 
	void Set(OgdcShort sVal);
	//! \brief ���ñ���ֵΪnVal 
	void Set(OgdcInt nVal);
	//! \brief ���ñ���ֵΪnVal 
	void Set(OgdcLong lVal);
	//! \brief ���ñ���ֵΪdVal 
	void Set(OgdcFloat dVal);
	//! \brief ���ñ���ֵΪdVal 
	void Set(OgdcDouble dVal);
	//! \brief ���ñ���ֵΪtmVal 
	void Set(const OgdcTime& tmVal);
	//! \brief ���ñ���ֵΪpDataָ����ַ���
	void Set(const OgdcUchar* pData,OgdcUint nSize);	
    //! \brief ���ñ���ֵΪstr 
	void Set(const OgdcString& str);	
	//! \brief ����Ϊ��
	void SetNull();
	
	//! \brief �ж��Ƿ����
	//! \remarks ���Ͳ����, ����Ϊ�����(COleVariant�Ĵ���ʽ)
	OgdcBool operator==(const OgdcVariant& varSrc) const;

	//! \brief �ж��Ƿ����
	//! \remarks ���Ͳ����, ����Ϊ�����(COleVariant�Ĵ���ʽ)
	OgdcBool operator!=(const OgdcVariant& varSrc) const;

	//! \brief �жϴ�С
	//! \remarks ���Ͳ����, ����Ϊ�����(COleVariant�Ĵ���ʽ)
	OgdcBool operator<(const OgdcVariant& varSrc) const;

	//! \brief ���
	void Clear();	

	//! \brief ��ȡ��������
	VarType GetType() const 
	{
		return m_nType;
	}

	//! \brief ��ȡ����ֵ
	VarValue& GetValue() 
	{
		return m_value;
	}
    
	//! \brief ��ȡ����ֵ
	const VarValue& GetValue() const 
	{
		return m_value;
	}

	//! \brief ת��Ϊdouble����
	OgdcDouble ToDouble() const;
	//! \brief ת��Ϊint32 ����
	OgdcInt ToInt() const;
	//! \brief ת��Ϊint64 ����
	OgdcLong ToLong() const;
	//! \brief ת��ΪString����
	//! \remarks ����UGTime���ͣ�ת�������ݿ�ʶ��ĸ�ʽҲ���� %Y-%m-%d %H:%M:%S ��
	OgdcString ToString() const;
	//! \brief ת��ΪString����
	//! \remarks ����UGTime���ͣ�ת���ɱ��ص�ǰ��ʱ����,�����������ͺ�ToString()����һ����
	OgdcString ToStringLocal() const;
	
public:		
	//! \brief ��������
	VarType m_nType;
	
	//! \brief ����ֵ
	VarValue m_value;	

};

}

#endif // !defined(AFX_OGDCVARIANT_H__3DD52A73_5F64_43C1_9374_D128DF18117E__INCLUDED_)

