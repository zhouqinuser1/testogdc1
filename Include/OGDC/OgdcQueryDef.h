//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)             
//                                                           
//!  \file OgdcQueryDef.h
//!  \brief OgdcQueryDef �Ľӿڶ��塣
//!  \details Ogdc��ѯ����ӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCQUERYDEF_H
#define OGDCQUERYDEF_H

#include "Base/OgdcVariant.h"
#include "Base/OgdcRect2D.h"
#include "Base/OgdcArray.h"
#include "OGDC/OgdcDsConnection.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

class OgdcElement;
class OgdcRecordset;

//! \brief ������ѯ��
class OGDC_API OgdcJoinItem
{	
public:
	//! \brief ���ݱ���������ö�١�
	enum  JoinType
	{
		//! \brief �����ӡ�
		InnerJoin	=0,
		//! \brief ������
		LeftJoin	=1,
		//! \brief ������
		RightJoin	=2,
		//! \brief ȫ����
		FullJoin	=3 
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcJoinItem();
	//! \brief Ĭ����������
#ifdef SYMBIAN60
	~OgdcJoinItem();
#else
	virtual ~OgdcJoinItem();
#endif

	//! \brief �������캯����
	//! \param joinItem ������ѯ���������[in]��
	OgdcJoinItem(const OgdcJoinItem& joinItem);	

	//! \brief ���캯����
	//! \param strName ����[in]��
	//! \param nJoinType ��������[in]��
	//! \param strForeignTable �ⲿ������[in]��
	//! \param strJoinFilter ��������[in]��
	OgdcJoinItem(const OgdcString& strName,
				JoinType nJoinType,
				const OgdcString& strForeignTable,
				const OgdcString& strJoinFilter);	

public:
	//! \brief ���ز����� =
	const OgdcJoinItem& operator =(const OgdcJoinItem& joinItem);
	//! \brief ���ز����� ==
	OgdcBool operator ==(const OgdcJoinItem& joinItem);
	//! \brief ���ز����� !=
	OgdcBool operator !=(const OgdcJoinItem& joinItem);

public:	
	//! \brief ���ơ�
	OgdcString m_strName;	
	//! \brief ��������
	JoinType m_nJoinType;
	//! \brief �ⲿ������
	OgdcString m_strForeignTable;
	//! \brief ��������
	//! \remarks ��tb1��Field1�ֶ��� tb2��Field1�������������Ϊ:
	//! "tb1.Field1 = tb2.Field2"��	
	OgdcString m_strJoinFilter;
};
	
//! \brief ������ѯ��
class OGDC_API OgdcLinkItem
{	
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcLinkItem();
	//! \brief Ĭ����������
#ifdef SYMBIAN60
	~OgdcLinkItem();
#else
	virtual ~OgdcLinkItem();
#endif
	
	//! \brief �������캯��
	OgdcLinkItem(const OgdcLinkItem& linkItem);	

public:
	//! \brief ���ز����� =
	const OgdcLinkItem&  operator =(const OgdcLinkItem& linkItem);
	//! \brief ���ز����� ==
	OgdcBool operator ==(const OgdcLinkItem& linkItem);
	//! \brief ���ز����� !=
	OgdcBool operator !=(const OgdcLinkItem& linkItem);

public:	
	//! \brief ���ӵ����ơ�
	OgdcString m_strName;
	
	//! \brief �ⲿ���ӵ����Ӳ�����
	OgdcDsConnection m_dsForeignConnect;	

	//! \brief �ⲿ���Ա�����
	//! \remarks �����SuperMap�����ݼ�����ӦΪ���ݼ����֡�
	OgdcString m_strObjectName;
	
	//! \brief �����������ϡ�
	OgdcArray<OgdcString> m_aryPrimaryKeys;	

	//! \brief ������������ϡ�
	OgdcArray<OgdcString> m_aryForeignKeys;

	//! \brief ������ѯ������
	OgdcString m_strFilter;
	
	//! \brief Ҫʹ�õ��ⲿ���Ա���ֶ��б�
	OgdcArray<OgdcString> m_aryFields;
};

//! \brief Ogdc��ѯ���塣
class OGDC_API OgdcQueryDef  
{
public:
	//! \brief ��ѯ����ö��
	enum QueryType
	{
		//! \brief һ�������������ѯ
		General		=0,
		//! \brief ʹ�õ���Χ���β�ѯ
		Bounds		=1,
		//! \brief ָ��ID�����ѯ
		IDs			=2,
		//! \brief �����ѯ
		Distance			=15,

		//! \brief �ռ��ѯ��ͬһ��\n
		//!���ر�����ͼ����������������ȫ��ͬ�Ķ��󣬰����������ͺ�����
		Identical			=20,

		//! \brief �ռ��ѯ�����롣\n
		//!���ر�����ͼ������������������Ķ���
		Disjoint			=21,
		
		//! \brief �ռ��ѯ��������\n
		//!��������������棬����ȫ���򲿷ֱ�������������Ķ����Լ�ȫ���򲿷ְ�����������Ķ�����������������棬����ȫ���򲿷ְ�����������Ķ����棩�� 
		Intersects			=22,
		
		//! \brief �ռ��ѯ���Ӵ���\n
		//!���ر�����ͼ������߽�����������߽��ഥ�Ķ��� 
		Touches				=23,
		
		//! \brief �ռ��ѯ���ص���\n
		//!���ر�����ͼ�������������󲿷����ص��Ķ���
		Overlaps			=24,
		
		//! \brief �ռ��ѯ���ཻ��\n
		//!���ر�����ͼ���������������߻��棩�ཻ�����ж��󣨵㡢�߻��棩�� 
		Crosses				=25,	
		
		//! \brief �ռ��ѯ��������\n
		//!���ر�����ͼ���а�����������Ķ���\n
		//!������صĶ������棬�����ȫ�������������߽Ӵ�����������
		//!������صĶ������ߣ��������ȫ������������\n
		//!������صĶ����ǵ㣬����������������غϡ� 
		Within				=26,	
		
		//! \brief �ռ��ѯ������\n
		//!���ر�����ͼ���б�������������Ķ��󡣰�������������߽��ϵ������ 
		Contains			=27,	
		
		//! \brief �ռ��ѯ���߽�����ཻ\n
		//!���ر�����ͼ������߽��������������ı߽�����ཻ�������������������ཻ�����ж��� 
		ExtentIntersect		=28,	
		
		//! \brief �ռ��ѯ���Զ�������
		Relate				=29,			
		
		//! \brief �ռ��ѯ����\n
		//!���ر�����ͼ��������������������һ�������ڵ�����ж���
		CommonPoint			=30,
		
		//! \brief �ռ��ѯ����\n
		//!���ر�����ͼ��������������������һ�������ߣ���ȫ�غϣ������غϵı��Ϲ����нڵ㣨����Vertex��˵�Endpoint���������ж���
		CommonSegment		=31,
		
		//! \brief �ռ��ѯ����\n
		//!���ر�����ͼ�����ڵ������������ڲ�������� 
		CentroidInPolygon	=32,
	};	
	
	//! \brief ��ѯѡ��ö��
	enum QueryOption
	{		
		//! \brief ��ѯ���ζ���
		Geometry	= 1,
		//! \brief ֻ��ѯ������Ϣ
		Attribute	= 2,
		//! \brief ���ζ�������Զ���ѯ
		Both		= 3 
	};
	
	//! \brief ��ѯģʽö��
	enum QueryMode
	{
		//! \brief һ���ѯ
		GeneralQuery	=0x00000000, 
		//! \brief ģ����ѯ
		FuzzyQuery		=0x00000001
	};
	
	//! \brief �α�����ö��
	enum CursorType
	{
		//! \brief δ������α�����
		OpenUnspecified		=-1,		
		//! \brief ֻ��ǰ�α�
		OpenForwardOnly		=0, 
		//! \brief �ؼ����α�
		OpenKeyset			=1, 
		//! \brief ��̬�α�
		OpenDynamic			=2, 
		//! \brief ��̬�α�
		OpenStatic			=3, 
	};
	
	//! \brief �α�λ��ö��
	enum CursorLocation
	{
		//! \brief ��ָ���α�λ��
		UseDefault		=1, 
		//! \brief ���������α�
		UseServer		=2, 
		//! \brief ʹ�ÿͻ����α�
		UseClient		=3  
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcQueryDef();
	//! \brief Ĭ����������
	~OgdcQueryDef();
	//! \brief �������캯��
	OgdcQueryDef(const OgdcQueryDef& queryDef);

public:
	//! \brief ���ز����� =
	const OgdcQueryDef& operator=(const OgdcQueryDef& queryDef);
	//! \brief ���ز����� ==
	OgdcBool operator==(const OgdcQueryDef& queryDef);
	//! \brief ���ز����� !=
	OgdcBool operator!=(const OgdcQueryDef& queryDef);

public:
	//! \brief ��ѯ����(General,Bounds,IDs�����ֿռ��ѯ�ȣ�
	//! \remarks ���� (Ĭ�� General)
    QueryType	m_nType;
	
	//! \brief ��ѯѡ��(�Ƿ񷵻�Geometry��Attribute,�����߶��еȣ�
	//! \remarks ���� ��Ĭ�� Both��
	QueryOption	m_nOptions;
	
	//! \brief ��ѯ��ʽ(GeneralQuery��FuzzyQuery)
	//! \remarks ��ѡ Ĭ���أ�GeneralQuery
	QueryMode	m_nMode;
	
	//! \brief �������ݲ�ѯ����
	//! \remarks ��ѡ Ĭ�� ""
	OgdcString	m_strFilter;
	
	//! \brief �������ݲ�ѯ����
	//! \remarks ��ѡ Ĭ�� ""
	OgdcString	m_strSort;

	//! \brief �������ݷ������
	//! \remarks ��ѡ Ĭ�� ""
	OgdcString	m_strGroup;

	//! \brief �������ݲ�ѯ�ֶ���
	//! \remarks ��ѡ Ĭ�� ""
	OgdcArray<OgdcString>	m_Fields;
	
	//! \brief �洢�ⲿ��������
	//! \remarks ��ѡ Ĭ�� ""
	OgdcArray<OgdcJoinItem>	m_JoinItems;
	
	//! \brief ��ҹ������Ա�
	OgdcArray<OgdcLinkItem>	m_aryLinkItems;
	
	//! \brief Bounds��ѯʱ����Ӿ���
	//! \remarks ��ѡ Ĭ�� empty
	OgdcRect2D	m_rc2Bounds;
	
	//! \brief ID��ѯʱ��ID����
	//! ��ѡ Ĭ��Ϊ������
	OgdcArray<OgdcInt>	m_IDs;
	
	//! \brief ID��ѯʱ��ID����,Ŀǰֻ֧����ֵ���ֶ�
	//! \remarks ��ѡ Ĭ��Ϊ��
	OgdcString	m_strIDFieldName;
	
	//! \brief �α�(���)����
	//! \remarks ��ѡ Ĭ�� OpenDynamic
	CursorType	m_nCursorType;
	
	//! \brief �α�λ��
	CursorLocation	m_nCursorLocation;

	//! \brief ��ѯ��������, ����ѯģʽΪģ����ѯʱ,Ϊ����С�������� Ĭ�� 0��
	//! �ռ��ѯʱ,Ϊ�ռ��ѯ���ޣ�Ĭ��Ϊ10�ĸ�10�η��������ѯʱ��Ϊ��ѯ���룬���û�ָ����
	OgdcDouble m_dGranule;
	
	//! \brief �ռ��ѯ������ѯ���ζ���
	OgdcElement* m_pElement;

	//! \brief �ռ��ѯ������ѯ��¼����
	OgdcRecordset* m_pRecordset;

	//! \brief �ռ��ѯģʽΪRelateʱʹ�á�
	OgdcString m_strSpatialRelate;
	
	//! \brief �����ѯ��λ����γ�������¿��Բ�����(AU_METER)�ȵ�λ��
	OgdcInt m_nDistUnit;
};

}
#endif // !defined(OGDCQUERYDEF_H)

