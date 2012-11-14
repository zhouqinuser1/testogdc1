//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcRecordset.h
//!  \brief OgdcRecordset �Ľӿڶ��塣
//!  \details Ogdc��¼���Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef OGDCRECORDSET_H
#define OGDCRECORDSET_H

#include "OGDC/OgdcQueryDef.h"
#include "Element/OgdcFeature.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{
class OgdcDatasetVector;

//! \brief Ogdc��¼����
class OGDC_API OgdcRecordset
{
public:	
	//! \brief �ֶ�ͳ��ģʽ
	enum OgdcStatisticMode
	{
		//! \brief ���ֵ��
		smMax				= 1,
		//! \brief ��Сֵ��
		smMin				= 2,
		//! \brief ƽ��ֵ��
		smAvg				= 3,
		//! \brief �ܺ͡�
		smSum				= 4,
		//! \brief ��׼�
		smStdev				= 5,
		//! \brief ���
		smVar				= 6	
	};

	//! \brief ���ݼ��༭ģʽ��
	enum EditMode 
	{
		//! \brief δ���κα༭
		EditNone			= 0x00000000,
		//! \brief ��ִ�й�AddNew����
		EditAdd				= 0x00000001,
		//! \brief ���ڱ༭
		EditInProgress		= 0x00000002,
		//! \brief �Ѹ�����������
		EditSetFieldValue	= 0x00000004, 
		//! \brief ��ִ�й�SetGeometry����
		EditSetGeometry		= 0x00000008,
		//! \brief ��ɾ����¼
		EditDeleted			= 0x00000010 
	};

	//! \brief ����ģʽ
	enum FindMode 
	{
		//! \brief ��һ��
		First			= 0,
		//! \brief ���һ��
		Last			= 1,
		//! \brief ��һ��
		Next			= 2,
		//! \brief ǰһ��
		Prev			= 3, 
	};

	//! \brief Moveλ��
	enum MovePosition 
	{
		//! \brief ��ǰλ��
		Current			= 0,
		//! \brief ��ͷ
		Begin			= 1,
		//! \brief ĩβ
		End				= 2,
	};
	
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcRecordset();
	//! \brief Ĭ����������
	virtual ~OgdcRecordset();

public:
	//! \brief �Ƿ��¼��Ϊ��(û�м�¼)��
	//! \return ��¼��Ϊ�շ���TRUE���ǿշ���FALSE��
	virtual OgdcBool IsEmpty() = 0; 	
	
	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��ͷ��
	//! \return ָ��ָ��ͷ����TRUE�����򷵻�FALSE��
	virtual OgdcBool IsBOF() =0;	
	
	//! \brief �жϵ�ǰ��¼ָ���Ƿ�ָ��β��
	//! \return ָ��ָ��β����TRUE�����򷵻�FALSE��
	virtual OgdcBool IsEOF() =0;	
	
	//! \brief �رռ�¼��
	virtual void Close() =0;
	
	//! \brief ͨ���ֶ�����ȡ�ֶ�ֵ��
	//! \param strName �ֶ���[in]��
	//! \param varVal �ֶ�ֵ[out]��
	//! \return �Ƿ�ɹ���ȡ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool GetFieldValue(const OgdcString& strName, OgdcVariant& varVal) =0;	
	
	//! \brief ͨ���ֶ���Ż�ȡ�ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varVal �ֶ�ֵ[out]��
	//! \return �Ƿ�ɹ���ȡ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool GetFieldValue(OgdcInt nIndex,OgdcVariant& varVal) =0;	
	
	//! \brief ͨ���ֶ������õ�ǰ��¼���ֶ�ֵ��
	//! \param strName �ֶ���[in]��
	//! \param varVal �ֶ�ֵ[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �ֶ�ֵΪ��������
	virtual OgdcBool SetFieldValue(const OgdcString& strName,const OgdcVariant& varVal) =0;	
	
	//! \brief ͨ���ֶ�������õ�ǰ��¼���ֶ�ֵ��
	//! \param nIndex �ֶ����[in]��
	//! \param varVal �ֶ�ֵ[in]��
	//! \return �Ƿ����óɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �ֶ�ֵΪ�������͡�
	virtual OgdcBool SetFieldValue(OgdcInt nIndex,const OgdcVariant& varVal) =0;
	
	//! \brief ����ָ�������ļ�¼��
	//! \param strFilter Ϊ��ѯ���������� ��ID = 5",����IDΪ5�ļ�¼[in]��
	//! \param nFindMode Ϊ����ģʽ�����ҵ�ǰģʽ�����������ļ�¼��Ĭ��ΪFirst[in]��
	//! \return �Ƿ���ҳɹ���
	//! \remarks ����ģʽ First--��һ����Last--���һ����Next--��һ����Prev--ǰһ��  
	virtual OgdcBool Find(const OgdcString& strFilter, 
		OgdcRecordset::FindMode nFindMode = OgdcRecordset::First) =0;
	
	//! \brief ��¼���α��ƶ���ָ��λ�á�
	//! \param nFromPosition Moveλ�ã�Ĭ��ΪCurrent[in]��
	//! \param �ƶ��Ĵ���[in]��
	//! \return �Ƿ��Ѿ��ƶ���ָ��λ�á�
	//! \remarks Moveλ�ã�Current--��ǰλ�ã�Begin--��ͷ��End--ĩβ
	virtual OgdcBool Move(OgdcRecordset::MovePosition nFromPosition = OgdcRecordset::Current, 
		OgdcInt nRows = 1) =0;	
	
	//! \brief ��ȡ��¼������
	//! \return ��¼������
	virtual OgdcInt GetRecordCount() =0;	
	
	//! \brief �ռ������ֶε���Ϣ��
	//! \param fieldInfos �����ռ������ֶε��ֶ���Ϣ���������[out]��
	//! \return �Ƿ��ռ��ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool GetFieldInfos(OgdcFieldInfos& fieldInfos) =0;	
	
	//! \brief ͨ���ֶ�����ȡ�ֶ���Ϣ��
	//! \param strName �ֶ���[in]��
	//! \param fieldInfo �ֶ���Ϣ����[out]��
	//! \return �Ƿ��ȡ�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool GetFieldInfo(const OgdcString& strName,OgdcFieldInfo& fieldInfo)  =0;			

	//! \brief ��ĳ��ͳ�Ʒ���ͳ��ĳ���ֶΡ�
	//! \param strFieldName ͳ�Ƶ��ֶ���[in]��
	//! \param nMode ͳ��ģʽ[in]��
	//! \return ͳ��ֵ��
	virtual OgdcVariant Statistic(const OgdcString& strFieldName,
		OgdcStatisticMode nMode) =0;	

	//! \brief ���²�ѯ��ˢ�¼�¼����
	//! \return �Ƿ�ɹ���ѯ���ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool ReQuery() =0;	

	//! \brief �����¼���ĵ���Χ��
	//! \param rc2Bounds ��¼���ĵ���Χ[out]��
	//! \param &dMinZ ��¼����С�߳�[in]��
	//! \param &dMaxZ ��¼�����߳�[in]��
	//! \return �Ƿ����ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool ComputeBounds(OgdcRect2D &rc2Bounds,
		OgdcDouble &dMinZ, OgdcDouble &dMaxZ) =0;	

public:
	//! \brief �����ֶ�ֵ��
	//! \param strSrcField Դ�ֶ���[in]��
	//! \param strDestField Ŀ���ֶ���[in]��
	//! \return �Ƿ�ɹ����ƣ��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention strSrcField��trDestField���붼�������ֶ�����ƥ�䡣
	virtual OgdcBool CopyField(const OgdcString& strSrcExpression,
		const OgdcString& strDestFieldName) =0;	
	
	//! \brief ��ȡ��ǰ��¼��ID��
	//! \return ��ǰ��¼��ID��
	virtual OgdcInt GetID() = 0;	

	//! \brief ��ȡ���ζ��󣬷��صļ��ζ���ָ���ں����ڷ����ڴ棬��
	//! \param pElement �ռ��ζ���ָ������ȡ�����ζ���[in]��
	//! \return �Ƿ�ȡ���ζ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \attention ���渺��ɾ������������ڴ�й©��
	virtual OgdcBool GetElement(OgdcElement*& pElement) =0;	

	//! \brief ���õ�ǰ��¼�ļ��ζ���
	//! \param pElement ���ζ���ָ��[in]��
	//! \return �Ƿ����ü��ζ���ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool SetElement(OgdcElement* pElement) =0;	

	//! \brief �����¼�¼,�ɹ�������TRUEֵ��ʧ�ܷ���FALSEֵ��
	//! \param *pGeometry [in] ��ӵ�Geometryָ��
	//! \param bReturnID=FALSE [in] �˲����Ѿ��������á�
	//! \return True �� False ��ֵ
	//! \remarks �����õ��¶����ID����ô���ϵ���GetId����
	virtual OgdcInt AddNew(OgdcElement *pElement, OgdcBool bReturnID=FALSE) =0;

	//! \brief ȡ�����ݼ���ĳ������Ҫ�ء�
	//! \param nID ���ݼ���¼ID��[in]��
	//! \return ����Ҫ��ָ�롣
	virtual OgdcFeature* GetFeature() = 0;	

	//! \brief ������Ҫ�ظ��µ����ݼ��С�
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ񱣴�ɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool UpdateFeature(const OgdcFeature* pFeature) = 0;
	
	//! \brief ������Ҫ��׷�ӵ����ݼ�δβ��
	//! \param pFeature ����Ҫ��ָ��[in]��
	//! \return �Ƿ�׷�ӳɹ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ׷��ʱ����Ҫ�ع��������ݼ���¼ID���������á�
	virtual OgdcBool AddFeature(const OgdcFeature* pFeature) = 0;

	//! \brief ͨ��ID��λ��¼ָ�롣
	//! \param nID ��¼ID[in]��
	//! \return ��λ�ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool SeekID(OgdcInt nID) =0;	

	//! \brief ����¼�����µ����ݼ���
	//! \return ���¼�¼��ID��
	virtual OgdcInt Update() =0;	

	//! \brief ȡ���޸ġ�
	//! \return �ɹ�ȡ������TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool CancelUpdate() =0;	
	
	//! \brief ��ʼ�޸����ݡ�
	//! \return �ɹ���ʼ����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool Edit() =0;	

	//! \brief �Ƿ�ɸ���
	//! \return �ɸ��·���TRUE�����򷵻�FALSE��
	virtual OgdcBool CanUpdate() =0;	
	
	//! \brief ɾ����ǰ��¼��
	//! \return �Ƿ�ɹ�ɾ�����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool Delete() =0;	

	//! \brief ɾ�����м�¼��
	//! \return ɾ���ɹ�����TRRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool DeleteAll() =0;
	
	//! \brief ��ȡ��ǰ���ݼ�ָ�롣
	//! \return ָ��ǰ���ݼ���ָ�롣
	virtual OgdcDatasetVector* GetDataset() =0;		

public:
	//! \brief ��ѯ����
	OgdcQueryDef m_QueryDef;

};

}
#endif // !defined(OGDCRECORDSET_H)

