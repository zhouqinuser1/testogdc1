//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcMetaDatabase.h
//!  \brief OgdcMetaDatabase��Ľӿڶ���
//!  \details MetaDatabaseΪԪ���ݿ�
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCMETADATABASE_H__2CD5B324_0654_4083_A783_CFA11A788A15__INCLUDED_)
#define AFX_OGDCMETADATABASE_H__2CD5B324_0654_4083_A783_CFA11A788A15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"
#include "Base/OgdcString.h"
#include "OGDC/OgdcDsConnection.h"
#include "OGDC/OgdcMetaData.h"

namespace OGDC
{

class OgdcDataSource;

// OgdcMetaQueryDefs ֧�ֵĲ�ѯģʽ��(��ǩ�� ���������� ��ǩֵ) ���� (��ǩ�� ���������� ��ǩֵ) ...
// ��֧�� ���ڱ�ǩ�� ����ѧ�������������� ��ǩA+��ǩB > 1000
// ����1: ��ѯ: Left>1000 and Right<2000 ���� OgdcMetaQueryDefs ����
// OgdcMetaQueryDef def1, def2;
// OgdcMetaQueryDefs defs;
// def1.strTag = "Left";
// def1.strValue = "1000";
// def1.strType = "number";
// def1.strOperator = ">";
// def1.strCondjuction = "and";
// def2.strTag = "Right";
// def2.strValue = "2000";
// def2.strType = "number";
// def2.strOperator = "<";
// def2.strCondjuction = "";
// defs.Add(def1);
// defs.Add(def2);

// ����2: ģ����ѯ: %��λ like '%SuperMap%' or %��λ% = 'IGSNRR', ���� OgdcMetaQueryDefs ����
// OgdcMetaQueryDef def1, def2;
// OgdcMetaQueryDefs defs;
// def1.strTag = "%��λ";
// def1.strValue = "%SuperMap%";
// def1.strType = "string";
// def1.strOperator = "like";
// def1.strCondjuction = "or";
// def2.strTag = "%��λ%";
// def2.strValue = "IGSNRR";
// def2.strType = "string";
// def2.strOperator = "=";
// def2.strCondjuction = "";
// defs.Add(def1);
// defs.Add(def2);

//! \brief Ԫ���ݲ�ѯ����ṹ�塣
struct OgdcMetaQueryDef
{
	//! \brief ��ǩ��
	OgdcString strTag;

	//! \brief ��ǩ����,"string" ���� "number"
	OgdcString strType;

	//! \brief ��ǩֵ
	OgdcString strValue;

	//! \brief ������
	OgdcString strOperator;

	//! \brief ����һ�� OgdcMetaQueryDef ����������,"and"����"or"
	OgdcString strCondjuction;
};

//! \brief �����ɶ�� OgdcMetaQueryDef ���ж��ǩ����ϲ�ѯ
typedef OgdcArray<OgdcMetaQueryDef> OgdcMetaQueryDefs; 

//! \brief OgdcԪ���ݿ��ࡣ
class OGDC_API OgdcMetaDatabase  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcMetaDatabase();
	//! \brief Ĭ����������
	virtual ~OgdcMetaDatabase();

	//! \brief ����һ���µ�Ԫ���ݿ�
	//! \return �����ɹ�����TRUE��ʧ���򷵻�FALSE
	virtual OgdcBool Create() = 0;
	
	//! \brief ��Ԫ���ݿ⡣
	//! \return ���ӳɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool Open() = 0;
	
	//! \brief �ر�Ԫ���ݿ⣬�Ͽ������ݿ�����ӡ�
	//! \return �رճɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool Close() = 0;

	//! \brief ���ӵ�Ԫ���ݿ⡣
	//! \return ���ӳɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool Connect();	

	//! \brief ����Դ�Ƿ���������ӡ�
	virtual OgdcBool IsConnected() const;
	
	//! \brief	����Ԫ����
	//! \param  strFilePath [in]Ԫ�����ļ�·��
	//! \return	OgdcString �ɹ����ص�����Ԫ����UUID,ʧ��Ϊ""
	virtual OgdcString ImportMetaData(const OgdcString &strFilePath) = 0;

	//! \brief ��ȡָ����Metadata����
	//! \return ��ȡ�ɹ�������TRUE, ���򷵻�FALSE����
	//! \remarks ��ָ����Ԫ���ݲ����ڣ�����FALSE������дmetadata��

	//! \brief	����Ԫ����
	//! \param &strPath [in] �������ļ�·��
	//! \param &strMetadataUUID [in]��Ԫ���ݵ�UUID��
	//! \return	OgdcBool �ɹ�����TRUE
	virtual OgdcBool ExportMetaData(const OgdcString& strPath, const OgdcString &strMetaUUID) = 0;

	//! \brief ��ȡָ����Metadata����
	//! \param &strMetadataUUID [in]��Ԫ���ݵ�UUID��
	//! \param metadata [in/out] Ԫ���ݶ���(�����ʹ���)��
	//! \return ��ȡ�ɹ�������TRUE, ���򷵻�FALSE����
	//! \remarks ��ָ����Ԫ���ݲ����ڣ�����FALSE������дmetadata��
	virtual OgdcBool GetMetadata(const OgdcString &strMetadataUUID, OgdcMetadata & metadata) = 0;

	//! \brief �Ƴ�ָ����Ԫ���ݡ�
	//! \param strMetadataUUID [in] Ҫɾ����Ԫ���ݵ�UUIDID��
	//! \return �ɹ�������TRUE, ���򷵻�FALSE��
	//! \remarks ��ָ����Ԫ���ݲ����ڣ��򷵻�FALSE��
	virtual OgdcBool DropMetadata(const OgdcString &strMetadataUUID) = 0;

	//! \brief ��ѯ����������Ԫ���ݶ����ID��
	//! \param &querydef [in] ��ϲ�ѯ������
	//! \param &aryMetadataUUIDs [out] �õ���Ԫ���ݿ������е�Ԫ���ݵ�UUID����
	//! \return ��ȡ�ɹ�������TRUE, ���򷵻�FALSE��
	//! \remarks aryMetadataUUIDs�����е����ݽ������
	virtual OgdcBool Query(const OgdcMetaQueryDefs &querydefs, OgdcStringArray &aryMetadataUUIDs) = 0;

	//! \brief ��ȡԪ���ݿ������е�Ԫ���ݵ�UUID��
	//! \param &aryMetadataUUIDs [out] �õ���Ԫ���ݿ������е�Ԫ���ݵ�UUID����
	//! \return ��ȡ�ɹ�������TRUE, ���򷵻�FALSE��
	//! \remarks aryMetadataUUIDs �����е����ݽ������
	virtual OgdcBool FetchMetadataIDs(OgdcStringArray &aryMetadataUUIDs);

public:
	//! \brief Ԫ���ݿ�������Ϣ
	OgdcConnection m_connection;
};

}

#endif // !defined(AFX_OGDCMETADATABASE_H__2CD5B324_0654_4083_A783_CFA11A788A15__INCLUDED_)

