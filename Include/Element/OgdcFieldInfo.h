//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcFieldInfo.h
//!  \brief OgdcFieldInfo �Ľӿڶ��塣
//!  \details Ogdcʸ�����ݼ��ֶ�������Ϣ���塣
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef OGDCFIELDINFO_H
#define OGDCFIELDINFO_H

#include "Base/OgdcString.h"
#include "Base/OgdcArray.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

//! \brief Ogdcʸ�����ݼ��ֶ�������Ϣ��
class ELEMENT_API OgdcFieldInfo  
{
public:
	//! \brief �ֶ�����
	enum FieldType
	{		
		//! \brief ��Ч���ֶ����͡�
		UnKnown	= 0,
		//! \brief ����ֵ�����ֽڣ�TRUE,FALSE��
		Boolean = 1,
		//! \brief �޷��ŵ����0-255�� 
		Byte = 2,
		//! \brief �����ͣ�2�ֽڡ�
		INT16 = 3,
		//! \brief �����ͣ�4�ֽڡ�
		INT32 = 4,
		//! \brief �����ͣ�8�ֽڡ�
		INT64 = 16, 
		//! \brief �����ȸ����ͣ�4�ֽڡ�
		Float = 6,
		//! \brief ˫���ȸ����ͣ�8�ֽڡ�
		Double = 7,
		//! \brief �����ͣ��ꡢ�¡��գ�����ʱ�䡣
		Date = 8,
		//! \brief �̶����ȶ������ͣ���ָ�����ȡ�
		Binary = 9,
		//! \brief �������ַ����͡�
		Text = 10,
		//! \brief ���������������͡�
		LongBinary = 11,
		//! \brief �����ַ����ͣ���ָ�����ȡ�
		Char = 18, 
		//! \brief ʱ���ͣ�Сʱ���֡��룬�������ڡ�
		Time = 22,
		//! \brief ʱ����ͣ��ꡢ�¡��ա�Сʱ���֡��롣
		TimeStamp = 23,
		//! \brief ���ֽڲ������ַ������͡�
		NText =127,
		//! \brief �����������͡�
		Geometry = 128
	};
	
	//! \brief ����ϵͳ�ֶα�ʶ��
	enum FieldSign  
	{
		signNone	= 0, 
		//! \brief �������ݼ��Ľڵ�ID��Ĭ����SmNodeID�ֶΡ�
		signNodeID	= 1, 
		//! \brief �������ݼ�����ֶ�, Ĭ����SmFNode��
		signFNode	= 2, 
		//! \brief �������ݼ��յ��ֶ�, Ĭ����SmTNode��
		signTNode	= 3, 
		//! \brief �������ݼ��ߵ�ID�ֶΡ�
		signEdgeID	= 4, 
		//! \brief ·�����ݼ���RouteID�ֶΡ�
		signRouteID	= 5, 		
		//! \brief ����ID�ֶΡ�
		signID		= 11, 			
		//! \brief ���ζ����ֶΡ�
		signGeometry= 12, 	
		//! \brief �û��Զ����ֶα�ʶ��ʼֵ��
		signStart	= 50 
	};

public:
	//! \brief Ogdcʸ�����ݼ��ֶ�������Ϣ���캯��
	OgdcFieldInfo();
    //! \brief Ogdcʸ�����ݼ��ֶ�������Ϣ���캯��
	OgdcFieldInfo(const OgdcFieldInfo& fieldInfo);
    //! \brief Ogdcʸ�����ݼ��ֶ�������Ϣ��������
	~OgdcFieldInfo();
public:
	//! \brief ���� = 
	const OgdcFieldInfo& operator =(const OgdcFieldInfo& fieldInfo);
    //! \brief ���� ==
	OgdcBool operator ==(const OgdcFieldInfo& fieldInfo);
    //! \brief ���� != 
	OgdcBool operator !=(const OgdcFieldInfo& fieldInfo);
public:	
	//! \brief  �ж��ֶ��Ƿ�ɸ��¡�
	//! \return �Ƿ���Ը��£����Է���TRUE�������Է���FALSE��
	OgdcBool CanUpdate();	
	
	//! \brief �ж��Ƿ���ϵͳ�ֶ�
	//! \return �Ƿ���ϵͳ�ֶΣ��Ƿ���TRUE�����Ƿ���FALSE��
	OgdcBool IsSystemField();
	
	//! \brief �ж��Ƿ��Ǽ��ζ����ֶ�
	//! \return �Ƿ��Ǽ��ζ����ֶΣ��Ƿ���TRUE�����Ƿ���FALSE��
	OgdcBool IsGeoField();
	
	//! \brief �ж��Ƿ��������
	//! \return �Ƿ�����������Ƿ���TRUE�����Ƿ���FALSE��
	OgdcBool IsContainIndex();
	//! \brief �ж��ֶ��Ƿ�ΪUUID
	OgdcBool IsUUIDField();

public:
	//! \brief ����Ĭ��ֵ
	void SetDefaultValue(const OgdcString& strDefaultValue);

	//! \brief ��ȡĬ��ֵ
	//! \return Ĭ��ֵ���ַ�����ʽ
	OgdcString & GetDefaultValue();
	

public:	
	//! \brief �Ƿ���ϵͳUUID�ֶ�
	OgdcBool m_bUUID;

	//! \brief �Ƿ���ϵͳ�ֶΡ�
	OgdcBool m_bSystem;
	
	//! \brief �Ƿ��Ǳ����ֶΡ�
	OgdcBool m_bRequired;
	
	//! \brief �ֶγ����Ƿ������㳤�ȡ�
	OgdcBool m_bAllowZeroLength;

	//! \brief �̶�
	OgdcInt m_nScale;
	
	//! \brief ����
	OgdcInt m_nPrecision;
	
	//! \brief �ֶγ��ȡ�
	OgdcInt m_nSize;
	
	//! \brief �ֶ����ԡ�
	OgdcInt m_nAttributes;
	
	//! \brief �ֶ����λ�á�
	OgdcInt m_nOrdinalPosition;
	//! \brief �Ƚ�����
	OgdcInt m_nCollatingOrder;

	//! \brief �ֶ����͡�
	FieldType m_nType;
	//! \brief �ֶα�ʶ��
	FieldSign  m_nFieldSign;
	
	//! \brief �ֶ����ơ�
	OgdcString m_strName;
	
	//! \brief �ֶε��������
	OgdcString m_strForeignName;
	
	//! \brief Դ�ֶ���
	OgdcString m_strSourceField;
	
	//! \brief Դ����
	OgdcString m_strSourceTable;
	
	//! \brief ��֤����
	OgdcString m_strValidationRule;
	
	//! \brief ��֤����
	OgdcString m_strValidationText;
	
private:
	//! \brief �ֶ�Ĭ��ֵ
	OgdcString m_strDefaultValue;
	
public:
	//! \brief ��ʽ
	OgdcString m_strFormat;
	
	//! \brief ������Ϣ
	OgdcString m_strDomain;
	
	//! \brief �Ƿ�ɱ༭
	OgdcBool m_bUpdatable;
	
	//! \brief ����������
    OgdcString m_strIndexTab;
};

//! \brief ʸ�����ݼ��ֶ�������Ϣ�����ࡣ
//! \remarks ʸ�����ݼ��ֶ�������Ϣ�����顣
class ELEMENT_API OgdcFieldInfos :public OgdcArray<OgdcFieldInfo> 
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcFieldInfos();
	//! \brief Ĭ����������
	~OgdcFieldInfos();
public:
	//! \brief ���ֶ��ż�����������ֶΡ�
	//! \param strName �ֶ�����[in]��
	//! \param nType �ֶ�����[in]��
	//! \param nSize �ֶ��ֽڳ���[in]��
	//! \param nAttributes ����[in]��
	//! \param bRequired �Ƿ���븳ֵ��Ĭ��Ϊ��[in]��
	//! \param bAllowZeroLength �ֶγ����Ƿ����Ϊ0��Ĭ��Ϊ����[in]��
	//! \param strDefaultValue Ĭ��ֵ�ַ�����Ĭ��Ϊ��[in]��
	//! \param strIndexTabName ���������ַ�����Ĭ��Ϊ��[in]��
	//! \return �Ƿ���ӳɹ����ɹ�����TRUE�����ɹ�����FALSE��
	//! \attention �ֶ����Ƶ�ǰ�����ַ�����ʹ�á�Sm���������κδ�Сд��ʽ��
	//! ���򱾺����ܾ����벢����FALSE��
	OgdcBool AddField(
		const OgdcString& strName,
		OgdcFieldInfo::FieldType nType,
		OgdcInt lSize,
		OgdcInt lAttributes = 0,
		OgdcBool bRequired = FALSE,
		OgdcBool bAllowZeroLength = TRUE,
		OgdcString strDefaultValue = _U(""),
		OgdcString strIndexTabName = _U(""));	
	
	//! \brief ��ȡ�ֶ��ż�������ָ����ǵ��ֶ����ơ���
	//! \param nFieldSign �ֶα��[in]��
	//! \return �ֶ����ƣ����ֶ��ż���������û�д��ֶΣ��򷵻ؿ��ַ�����
	OgdcString GetSignField(OgdcFieldInfo::FieldSign nFieldSign);

	//! \brief ��ȡ�ֶ��ż�������ָ����ǵ��ֶ����ơ�
	//! \param strFieldName �ֶ�����[out]��
	//! \param nFieldSign �ֶα��[in]��
	//! \return �ֶ��ż��������Ƿ��д��ֶΣ����򷵻�TRUE��û�з���FALSE��
	OgdcBool GetSignField(OgdcString& strFieldName, OgdcFieldInfo::FieldSign nFieldSign);

	//! \brief 		�����ֶ���
	OgdcBool AdjustFieldNames();
};

}
#endif // !defined(OGDCFIELDINFO_H)

