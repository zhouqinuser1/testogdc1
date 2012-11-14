//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcDataSource.h
//!  \brief OgdcDataSource �Ľӿڶ��塣
//!  \details Ogdc����Դ�Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCDATASOURCE_H
#define OGDCDATASOURCE_H

#include "OGDC/OgdcDsConnection.h"
#include "OGDC/OgdcDatasetVector.h"
#include "OGDC/OgdcDatasetRaster.h"
#include "OgdcMetaDatabase.h"

namespace OGDC
{

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//! \brief Ogdc����Դ��
class OGDC_API OgdcDataSource  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcDataSource();
	//! \brief Ĭ����������
	virtual ~OgdcDataSource();

// ���麯��
public:
	//! \brief ��������Դ,��ҪԤ�����ú�������Ϣ��
	virtual OgdcBool Create() =0;
	
	//! \brief ������Դ,��ҪԤ�����ú�������Ϣ��
	virtual OgdcBool Open() =0;

	//! \brief �ر�����Դ��
	virtual void Close() = 0;

	//! \brief �ж�����Դ�Ƿ��Ѿ��򿪡�
	//! \return �򿪷���TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool IsOpen() const = 0;

	//! \brief ��ȡ���ݼ�������
	//! \return ���ݼ�������
	virtual OgdcInt GetDatasetCount() const = 0;

	//! \brief ͨ����Ż�ȡ���ݼ�ָ�롣
	//! \return ���ݼ�ָ�롣
	virtual OgdcDataset* GetDataset(OgdcInt nIndex) const = 0;

	//! \brief ��ȡָ�����Ƶ����ݼ�ָ�롣
	//! \param strDatasetName ���ݼ���[in]��
	//! \return ���ݼ�ָ�롣
	virtual OgdcDataset* GetDataset(const OgdcString& strDatasetName) const = 0;
	
	//! \brief ͨ�����ݼ�����ɾ�����ݼ���
	//! \param strDatasetName ���ݼ�����[in]��
	//! \return �Ƿ�ɹ�ɾ�����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DeleteDataset(const OgdcString& strDatasetName) =0;
	
	//! \brief ͨ��ʸ�����ݼ�������Ϣ�������ݡ�
	//! \param vInfo ʸ�����ݼ�������Ϣ����[in]��
	//! \return ʸ�����ݼ�ָ�롣
	virtual OgdcDatasetVector* CreateDatasetVector(const OgdcDatasetVectorInfo& vInfo) =0;	
	
	//! \brief ͨ��դ�����ݼ�������Ϣ�������ݼ���
	//! \param rInfo դ�����ݼ�������Ϣ����[in]��
	//! \param bIsMBRaster �Ƿ��Զನ�η�ʽ�������ݼ�[in]��
	//! \return դ�����ݼ�ָ�롣
	virtual OgdcDatasetRaster* CreateDatasetRaster(const OgdcDatasetRasterInfo& rInfo,OgdcBool bIsMBRaster = FALSE) =0;	

	//! \brief ͨ���������ݼ�ģ�崴�����ݼ���
	//! \param &strNewName �����ݼ���[in]��
	//! \param pReferenceDataset �ο����ݼ�ָ�룬��ģ�崴�����ݼ�ָ��[in]��
	//! \return �����ݼ�ָ�롣
	virtual OgdcDataset* CreateDatasetFrom(const OgdcString &strNewName, OgdcDataset* pReferenceDataset) = 0;

	//! \brief �������ݼ���
	//! \param pSrcDataset Դ���ݼ�ָ��[in]��
	//! \param strDestDatasetName Ŀ�����ݼ���[in]��
	//! \param bBuildIndexOrPyramid �Ƿ��դ�����ݼ�������������Ĭ�ϲ���[in]��
	//! \return Ŀ�����ݼ�ָ�롣
	virtual OgdcDataset* CopyDataset(OgdcDataset* pSrcDataset, 
		const OgdcString& strDestDatasetName, OgdcBool bBuildIndexOrPyramid = FALSE) = 0;

	//! \brief ����������Ϣ��
	virtual OgdcBool SaveInfo() = 0;

public:	
	//! \brief ����ͶӰ����ϵ��
	//! \param coordSys [in]��
	virtual OgdcBool SetCoordSys(const OgdcCoordSys& coordSys);	

	//! \brief �õ�ͶӰ����ϵ��
	virtual OgdcBool GetCoordSys(OgdcCoordSys& coordSys);	

	//! \brief ִ��SQL��䡣
	//! \param strSQL SQL���[in]��
	//! \return �Ƿ�ɹ�ִ�У��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��Ҫ���������ݿ⼶ִ�е����ݲ�����
	virtual OgdcBool Execute(const OgdcString& strSQL);	
	
	//! \brief ����Դ�Ƿ���������ӡ�
	virtual OgdcBool IsConnected();
	
	//! \brief �����������ݿ�,��ˢ�����ݼ��ȡ�
	virtual OgdcBool Connect();	
	
	//! \brief ��ȡ������ʱ�䡣
	virtual OgdcTime GetDateLastUpdated();
	
	//! \brief ��ȡ����ʱ�䡣
	virtual OgdcTime GetDateCreated();	
	
	//! \brief �޸����롣
	//! \param strNewPassword ������[in]��
	//! \return �޸ĳɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool ChangePassword(const OgdcString& strNewPassword);
	
	//! \brief ��ȡ�������ơ�
	//! \return �������ơ�
	virtual OgdcString GetEngineName() const ;
	
	//! \brief ����һ������Դ��Ŀǰû�е����ݼ����֡�
	//! \param strDatasetName ָ��һ�����ݼ���[in]��
	//! \return ����ָ�������ɵļ���Ψһʶ������ݼ�����
	virtual OgdcString GetUnoccupiedDatasetName(const OgdcString& strDatasetName);	
	
	//! \brief �ж����ݼ������Ƿ�Ϸ���
	//! \param strDatasetName ���ݼ���[in]��
	//! \param nState ���ݼ����ֶ�������������[out]��
	//! \return �����Ƿ�Ϸ����Ƿ���TRUE�����򷵻�FALSE��
	virtual OgdcBool IsAvailableDatasetName(const OgdcString& strDatasetName);

	//! \brief ��ȡ����Դ�汾�š�
	//! \return ����Դ�汾�š�
	virtual OgdcInt GetVersion();		
	
	//! \brief ��ʼ����
	//! \return �Ƿ�ɹ���ʼ���񣬳ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool BeginTrans();
	
	//! \brief �ύ����
	//! \return �Ƿ�ɹ��ύ���񣬳ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual void Commit();
	
	//! \brief ��������
	//! \return �Ƿ�ɹ��������񣬳ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual void Rollback();
	
	//! \brief �ж������Ƿ�ʼ 
	virtual OgdcBool IsTransStarted() const ;

	//! \brief �ж�����Դ�Ƿ�֧�ֶ��������
	//! \return ֧�ַ���TRUE����֧�ַ���FALSE��
	virtual OgdcBool IsTransacted() const;
	
	//! \brief ��ȡ���롣
	//! \remarks ͨ����ȡ������ϢҲ���Եõ����롣
	virtual OgdcString GetPassword() const;

	//! \brief ��ȡ����Դ���ơ�
	virtual OgdcString GetName() const ;

	//! \brief ��ȡ��������
	virtual OgdcInt GetEngineType() const;

	//! \brief ��ȡ�������
	virtual  OgdcInt GetEngineClass() const;

	//! \brief ��ȡ�ļ�������ĺ�׺��
	virtual OgdcString GetEnginePostfix() const;

	//! \brief �ж�����Դ�Ƿ��޸ġ�
	//! \return ���޸ķ���TRUE�����򷵻�FALSE��
	virtual OgdcBool IsModified();

	//! \brief ��������Դ�Ƿ��޸ġ�
	//! \param bModified ����Դ�Ƿ��޸Ĳ���ֵ��Ĭ��Ϊ�޸�[in]��
	virtual void SetModifiedFlag(OgdcBool bModified = TRUE);
	
	//! \brief ��ȡ����Դ�ı�����
	//! \return ����Դ�ı�����
	virtual OgdcString GetAlias() const;

	//! \brief ��������Դ�ı���
	//! \param strAlias ����Դ�ı���[in]��
	virtual void SetAlias(const OgdcString& strAlias);
	
	//! \brief �жϴ�����ֶ���������Ƿ���á�
	//! \param strFieldOrTableName �ֶ��������
	//! \return	���÷���TRUE�������÷���FALSE��
	virtual OgdcBool IsValidFieldOrTableName(const OgdcString& strFieldOrTableName);
	
	//! \brief ��������Դ������Ϣ��
	//! \param strDescription ����Դ������Ϣ[in]��
	virtual void SetDescription(OgdcString strDescription);
	
	//! \brief ��ȡ����Դ������Ϣ��
	//! \return ����Դ������Ϣ��
	virtual OgdcString GetDescription();

	//! \brief ɾ����ǰ������Դ(���Զ�ɾ���������ݼ������ɾ������ϵͳ���ϵͳ����)
	//! \remarks ���ô˷����󣬿����ٴδ���ͬ����������Դ
	//! \attention �����ݿ����͵�����Դ��Ҫʵ�ִ˷������ļ�������Դ������
	virtual OgdcBool DropDataSource();

	//! \brief ��ʼ��Ԫ���ݿ���
	//! \return Ԫ���ݿ����ָ��
	virtual OgdcMetaDatabase * InitMetaDatabase();

	//! \brief ��ȡԪ���ݿ���
	//! \return Ԫ���ݿ����ָ��
	//! \remarks ���ڵ��ô˺���֮ǰû�е���InitMetaDatabase���򷵻�ΪNULL
	virtual OgdcMetaDatabase * GetMetaDatabase();

	//! \brief ����Ԫ����UUID
	//! \param strMetaUUID Ԫ����UUID
	//! \return �ɹ�����TRUE
	virtual OgdcBool SetMetaUUID(const OgdcString strMetaUUID);

	//! \brief ��ȡԪ����UUID
	//! \return ����Ԫ����UUID��ʧ�ܷ���""
	virtual OgdcString GetMetaUUID();

	//! \brief ͨ��Ԫ���ݵ� UUID ��ȡ���ݼ�
	//! \param strMetaUUID[in] Ԫ���ݵ� UUID
	//! \return ���ص����ݼ�ָ�룬���������Դ�����ڷ������������ݼ����򷵻�NULL
	virtual OgdcDataset* FindDatasetByMetaData(OgdcString strMetaUUID);

public:
	//! \brief ����Դ������Ϣ
	OgdcDsConnection m_connection;

	//! \brief ������࣬1.�������ݿ⣬2.�����ļ��ͣ�3.Web�����͡�
	OgdcInt m_nEngineClass;

	//! \brief 2�����ļ�������Դ���ļ���׺����
	OgdcString m_strPostfix;
};

}
#endif // !defined(OGDCDATASOURCE_H)

