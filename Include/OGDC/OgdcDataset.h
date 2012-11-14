//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcDataset.h
//!  \brief OgdcDataset �Ľӿڶ��塣
//!  \details Ogdc���ݼ��Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCDATASET_H
#define OGDCDATASET_H

#include "Base/OgdcVariant.h"
#include "Base/OgdcRect2D.h"
#include "Element/OgdcCoordSys.h"
#include "Element/OgdcFieldInfo.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{
class OgdcDataSource;

//! \brief Ogdc���ݼ��ࡣ
class OGDC_API OgdcDataset  
{
public:
	//! \brief ���ݼ����ͣ����ڵ��� 10001 Ϊ�û���չ
	enum Type
	{
		Unknown		=-1,
		//! \brief ֻ�����Ա�û�м��ζ���
		Tabular		=0,	
		//! \brief �����ݼ�
		Point		=1,	
		//! \brief �����ݼ�
		Line		=3,	
		//! \brief ��������ݼ�
		Region		=5,		 
		//! \brief �ı����ݼ�
		Text		=7,		 
		//! \brief ��Mesureά�����ݼ�
		LineM		=35,
		//! \brief Ӱ��
		Image		=81,
		//! \brief Grid���ݼ�
		Grid		=83,
		//! \brief ��ά��
		Point3D		=101,
		//! \brief ��ά��
		Line3D		=103,
		//! \brief ��ά��
		Region3D	=105,
		//! ����D���ݼ�
		Compound	=149,	
	};
	
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcDataset();
	//! \brief Ĭ����������
	virtual ~OgdcDataset();

public:
	//! \brief �����ݼ���
	//! \return �Ƿ�ɹ������ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool Open() = 0;	
	
	//! \brief �ر����ݼ���
	//! \return �Ƿ�ɹ��ر����ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual void Close() = 0;	

	//! \brief �ж����ݼ��Ƿ��Ѿ��򿪡�
	//! \return �򿪷���TRUE�����򷵻�FALSE��
	virtual OgdcBool IsOpen() const = 0;
	
	//! \brief ��ȡ���ݼ����͡�
	//! \return ���ݼ�����ö��ֵ��
	virtual OgdcInt GetType() const = 0;	
	
	//! \brief ��ȡ���ݼ�����
	//! \return ���ݼ�����
	//! \remarks ���ݼ������Ժͱ�����ͬ��
	virtual OgdcString GetName() =0;
	
	//! \brief ���������ݼ���
	//! \param strNewName �µ����ݼ���[in]��
	//! \return �Ƿ�ɹ����������ݼ����ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks ֻ�ı����ݼ���,�������䡣
	virtual OgdcBool Rename(const OgdcString& strNewName) = 0;		

	//! \brief �жϵ�ǰ���ݼ��Ƿ�ɱ༭��
	//! \return �ɱ༭����TRUE�����ɷ���FALSE��
	virtual OgdcBool CanUpdate() = 0;	
	
	//! \brief �������ݼ��ķ��ά����
	//! \return ���ݼ���ά�����㡢�ߡ�����Ϊ0��1��2ά����Ϊ-1ά
	virtual OgdcInt GetStyleDimension() =0;	
	
	//! \brief �ж����ݼ��Ƿ���դ�����ݼ�
	//! \return ���ݼ���դ�����ݼ�����TRUE�����򷵻�FALSE��
	virtual OgdcBool IsRaster() =0;	
	
	//! \brief ��ȡ���ݼ��ĵ���Χ��
	//! \return ���ݼ��ĵ���Χ��
	virtual OgdcRect2D GetBounds() =0;	
	
	//! \brief �������ݼ��ĵ���Χ��
	//! \param rc2Bounds ���ݼ��ĵ���Χ[in]��
	virtual void SetBounds(const OgdcRect2D& rc2Bounds) = 0;	
	
	//! \brief �����ݼ�������Ϣ���浽���ݿ��С�
	//! \return �Ƿ�ɹ����棬�ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool SaveInfo() = 0;	
	
	//! \brief ˢ�����ݼ���Ϣ��
	//! \return �Ƿ�ɹ�ˢ�£��ɹ�����TRUE��ʧ�ܷ���FALSE��
	//! \remarks �����ݿ��ж�ȡ���ݼ��ĸ������ԣ�ˢ�µ�ǰ���ݼ�����Ϣ��
	virtual OgdcBool RefreshInfo() = 0;	

	//! \brief ��������Դָ��
	virtual OgdcDataSource* GetDataSource() const = 0;

public:	
	//! \brief ��ȡ���ݼ���Ӧ����
	virtual OgdcString GetTableName();	
	
	//! \brief ��ȡ���������ݼ���ʱ�̡�
	//! \return ���������ݼ���ʱ�̡�
	virtual OgdcTime GetDateLastUpdated();	
	
	//! \brief ��ȡ�������ݼ���ʱ�̡�
	//! \return �������ݼ���ʱ�̡�
	virtual OgdcTime GetDateCreated();	
	
	//! \brief �ж����ݼ��Ƿ��ڴ򿪺��й��޸ġ�
	//! \return �й��޸ķ���TRUE��û�з���FALSE��
	virtual OgdcBool IsModified() const;
	
	//! \brief �������ݼ��Ƿ��й��޸ġ�
	//! \param bModified ���ݼ��Ƿ��й��޸ģ�Ĭ�����޸�[in]��
	virtual void SetModifiedFlag(OgdcBool bModified = TRUE);
	
	//! \brief �������ݼ��ַ����뷽ʽ
	//! \param textCodec ���ݼ��ַ����뷽ʽ[in]��
	virtual void SetCharset(OgdcString::Charset nCharset);

	//! \brief ��ȡ���ݼ��ַ����뷽ʽ��
	//! \return ���ݼ��ַ���ö�١�
	virtual OgdcString::Charset GetCharset() const;

	//! \brief ����ͶӰ����ϵ��
	//! \param coordSys [in]��
	virtual OgdcBool SetCoordSys(const OgdcCoordSys& coordSys);	

	//! \brief �õ�ͶӰ����ϵ��
	virtual OgdcBool GetCoordSys(OgdcCoordSys& coordSys) const;			
		
	//! \brief ��ȡ���ݼ�������Ϣ��
	//! \return ���ݼ�������Ϣ��
	virtual OgdcString GetDescription() const;				
	
	//! \brief �������ݼ�������Ϣ��
	//! \param strDescription ���ݼ�������Ϣ[in]��
	virtual void SetDescription(const OgdcString& strDescription);		
	
	//! \brief ����Ԫ����UUID
	//! \param strMetaUUID Ԫ����UUID
	//! \return �ɹ�����TRUE
	virtual OgdcBool SetMetaUUID(const OgdcString strMetaUUID);

	//! \brief ��ȡԪ����UUID
	//! \return ����Ԫ����UUID��ʧ�ܷ���""
	virtual OgdcString GetMetaUUID();
};

}
#endif // !defined(OGDCDATASET_H)


