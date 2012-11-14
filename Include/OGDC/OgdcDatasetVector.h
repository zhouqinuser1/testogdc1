//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcDatasetVector.h
//!  \brief OgdcDatasetVector �Ľӿڶ��塣
//!  \details Ogdcʸ�����ݼ��ӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef OGDCDATASETVECTOR_H
#define OGDCDATASETVECTOR_H

#include "OGDC/OgdcDatasetVectorInfo.h"
#include "OGDC/OgdcRecordset.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

//! \brief Ogdcʸ�����ݼ���
class OGDC_API OgdcDatasetVector : public OgdcDataset
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcDatasetVector();
	//! \brief Ĭ����������
	virtual ~OgdcDatasetVector();

// ���麯��
public:
	//! \brief ��ȡ���ݼ��ж��������
	//! \param  [in]��
	//! \return ���������
	//! \remarks �ٶ���,��ֵ�Ƚ���ȷ��
	//! \attention ͨ��Register���ȡ��
	virtual OgdcInt GetObjectCount() = 0;

	//! \brief ���ؼ�¼��������
	//! \return ��¼��������
	virtual OgdcInt GetRecordsetCount() =0;	
	
	//! \brief ͨ����¼��ָ���ͷż�¼���ڴ�ռ䡣
	//! \param *pRecordset ��¼��ָ��[in]��
	//! \return �Ƿ��ͷųɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool ReleaseRecordset(OgdcRecordset *pRecordset) =0;	

	//! \brief �ͷ����м�¼��
	virtual void ReleaseAllRecordsets() = 0;	

	//! \brief ȡ�����ݼ���ĳ������Ҫ�ء�
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return ������Ҫ��ָ�롣
	virtual OgdcFeature* GetFeature(OgdcInt nID) = 0;	

	//! \brief ������Ҫ�ظ��µ����ݼ��С�
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ񱣴�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool UpdateFeature(const OgdcFeature* pFeature) = 0;
	
	//! \brief ������Ҫ��׷�ӵ����ݼ�δβ��
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ׷��ʱ����Ҫ�ع��������ݼ���¼ID���������á�
	virtual OgdcBool AddFeature(const OgdcFeature* pFeature) = 0;	

	//! \brief ������Ҫ�ش����ݼ���ɾ����
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DeleteFeature(OgdcInt nID) = 0;	
	
	//! \brief ͨ��ID����ɾ�����ݼ��еļ�¼��
	//! \param pIDs ID����ָ��[in]��
	//! \param nCount ID����Ԫ�ظ���[in]��
	//! \return �ɹ�ɾ������TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DeleteFeatures(const OgdcInt* pIDs, OgdcInt nCount) = 0;	
	
	//! \brief ɾ�������������ݡ�
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ��ձ����е��ֶ���Ȼ������
	virtual OgdcBool Truncate() =0;	

	//! \brief ���ݵ�ǰ����״̬�ؽ�����
	//! \return �Ƿ��ؽ��ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool BuildSpatialIndex() = 0;
	
	//! \brief ����ռ�����,Ϊû��������״̬
	//! \return �Ƿ�����ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DropSpatialIndex() = 0;
	
	//! \brief �Ƿ���Ҫ�ؽ��ռ�����
	//! \return ��Ҫ�ؽ�����TRUE������Ҫ����FALSE��
	//! \remarks �涨:���û����������FALSE,�����������������
	virtual OgdcBool IsSpatialIndexDirty() =0;

	//! \brief ��ѯͨ����ڣ��õ���¼����
	virtual OgdcRecordset* Query(const OgdcQueryDef& querydef) =0;
	
	//! \brief ͨ�����ʽ�����ֶ�ֵ��
	//! \param strFieldName ���µ��ֶ���[in]��
	//! \param strExpress ����������ʽ�ַ�����
	//! �ֶ�ֵ��ĳ������������ʽ��ֵ����strFieldName = Col1 + col2 * 2[in]��
	//! \param strFilter �����ֶ�ʱ�������еĹ���������
	//! Ĭ�Ϲ��������ÿգ��������м�¼[in]��
	//! \return �Ƿ�����ֶ�ֵ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool UpdateField(
		const OgdcString& strFieldName,
		const OgdcString& strExpress,
		const OgdcString& strFilter = _U("")) =0;	
	
	//! \brief �����ֶ�ֵ,strSrcField�͡�
	//! \param strSrcFieldName Դ�ֶ�����[in]��
	//! \param strDestFieldName Ŀ���ֶ�����[in]��
	//! \return �Ƿ����ֶγɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention Ŀ���ֶ������붼������Ŀ���ֶ�Ҫ��Դ�ֶ�����ƥ�䡣
	virtual OgdcBool CopyField(
		const OgdcString& strSrcFieldName,
		const OgdcString& strDestFieldName) =0;	
	
	//! \brief ������ͨ������
	//! \param strFieldNameList �����������ֶ��б�����ֶ��м���","����[in]��
	//! \param strIndexName ������[in]��
	//! \return ������ͨ�����Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool CreateFieldIndex(
		const OgdcString& strFieldNameList,
		const OgdcString& strIndexName) =0;	

	//! \brief ɾ��������
	//! \param strIndexName ������[in]��
	//! \return ɾ�������Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DropFieldIndex(const OgdcString& strIndexName) = 0;	

	//! \brief ���һ��������
	//! \param �ޡ�
	//! \return ����ֵ--���������ֶζ�ӦMap��
	virtual std::map<OgdcString,OgdcString> GetFieldIndexes();	
	
	//! \brief ��������ֶΡ�
	//! \param fieldInfos �ֶ�������Ϣ��������[in]��
	//! \return ��������ֶ��Ƿ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool CreateFields(const OgdcFieldInfos& fieldInfos) =0;	
		
	//! \brief ͨ���ֶ�����ɾ���ֶΡ�
	//! \param strFieldName �ֶ���[in]��
	//! \return �Ƿ�ɾ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DeleteField(const OgdcString& strFieldName) =0;
	
	//! \brief ��ȡ���ݱ��������ֶε�������Ϣ��
	//! \param fieldInfos ���ݱ��������ֶε�������Ϣ����[out]��
	//! \param bSystemFieldExcluded �Ƿ��ȡϵͳ�ֶΣ�Ĭ�ϲ�ȡ[in]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool GetFieldInfos(
		OgdcFieldInfos& fieldInfos,
		OgdcBool bSystemFieldExcluded = FALSE) =0;	
	
	//! \brief ͨ���ֶ�����ȡ�ֶ�������Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ[out]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool GetFieldInfo(
		const OgdcString& strFieldName,
		OgdcFieldInfo& fieldInfo) =0;
	
	//! \brief ͨ���ֶ��������ֶ���Ϣ��
	//! \param strFieldName �ֶ���[in]��
	//! \param fieldInfo �ֶ�������Ϣ��������[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool SetFieldInfo(
		const OgdcString& strFieldName,
		const OgdcFieldInfo& fieldInfo) =0;	
	
	//! \brief ͳ���ֶ�ֵ��
	//! \param strFieldName �ֶ���[in]��
	//! \param nMode ͳ��ģʽ[in]��
	//! \return ͳ��ֵ��
	virtual OgdcVariant Statistic(
		const OgdcString& strFieldName,
		OgdcRecordset::OgdcStatisticMode nMode) =0;	

public:
	//! \brief ��ȡ���ݼ�����
	//! \return ���ݼ����͡�
	virtual OgdcInt GetType() const;
	
	//! \brief ��ȡ���ݼ���ά��
	//! \return ���ݼ���ά����
	virtual OgdcInt GetStyleDimension();	
	
	//! \brief ��ȡ���ݼ���(���Ժͱ�����ͬ)
	//! \return ���ݼ�����
	virtual OgdcString GetName();	
	
	//! \brief ��ȡ���ݼ�������Ϣ��
	//! \return ���ݼ�������Ϣ��
	virtual OgdcString GetDescription() const;	
	
	//! \brief �������ݼ�������Ϣ
	//! \param strDesc [���ݼ�������Ϣin]��
	virtual void SetDescription(const OgdcString& strDesc);	
	
	//! \brief �ж����ݼ��Ƿ���դ�����ݼ�
	//! \return ��դ�����ݼ�����TRUE�����Ƿ���FALSE��
	virtual OgdcBool IsRaster();
	
	//! \brief ��ȡ���ݼ��ĵ���Χ��
	//! \return ���ݼ��ĵ���Χ���Ρ�
	virtual const OgdcRect2D& GetBounds() const;
	
	//! \brief �������ݼ��ķ�Χ��
	//! \param rcBounds ���ݼ��ĵ���Χ����[in]��
	virtual void SetBounds(const OgdcRect2D& rcBounds);
	
	//! \brief �õ�δ��ռ�õ��ֶ�����
	//! \param strFieldName ָ����һ���ֶ���[in]��
	//! \return δ��ռ�õ��ֶ�����
	virtual OgdcString GetUnoccupiedFieldName(const OgdcString& strFieldName);

	//! \brief �ж��ֶ����Ƿ���Ч��
	//! \param strFieldName �ֶ���[in]��
	//! \return ��Ч����TRUE����Ч����FALSE��
	virtual OgdcBool IsAvailableFieldName(const OgdcString& strFieldName);

	//! \brief ��ȡ�����ݼ�
	//! \return ����������ݼ���������ݼ�ָ�����飬��������Ϊ��
	virtual OgdcBool GetChildDataset(OgdcArray<OgdcDatasetVector *>& arrSubDatasets) const;

	//! \brief  ��ȡ�����ݼ�ָ��
	//! \return ����и����ݼ����򷵻ظ����ݼ�ָ�룻���򷵻�NULL
	virtual OgdcDatasetVector* GetParentDataset() const;
	
	//! \brief ʸ�����ݼ�����������Provider�����Ƿ�֧����ز�ѯ
	virtual OgdcBool IsSupportQueryType(OgdcQueryDef::QueryType queryType) const;

public:
	//! \brief ʸ�����ݼ�������Ϣ
	OgdcDatasetVectorInfo m_info;	
};

}
#endif // !defined(OGDCDATASETVECTOR_H)

