//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcMetadata.h
//!  \brief OgdcMetadata��Ľӿڶ���
//!  \details MetadataΪһ��Ԫ���ݼ���Metadata������һ�����ݼ���Ԫ���ݣ�Ҳ������һ������Դ��Ԫ����
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCMETADATA_H__6100835C_9516_424B_9D85_CCDF0C281B3D__INCLUDED_)
#define AFX_OGDCMETADATA_H__6100835C_9516_424B_9D85_CCDF0C281B3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"
#include "Base/OgdcString.h"

namespace OGDC
{

class OgdcMetaDatabase;

class OgdcDataSource;
class OgdcDataset;

//! \brief OgdcԪ���ݼ��ࡣ
class OGDC_API OgdcMetadata  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcMetadata();

	//! \brief �������캯��
	OgdcMetadata(OgdcMetaDatabase * pMetaDatabase);

	//! \brief Ĭ����������
	virtual ~OgdcMetadata();

	//! \brief ������һ����ǩ
	//! \return �ɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool IntoTag();

	//! \brief ������һ����ǩ
	//! \return �ɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool OutOfTag();

	//! \brief �ڵ�ǰ�㼶�����Ƶ���һ����ǩ
	//! \return �ɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool MoveNext()= 0;

	//! \brief �ص���ǰ�����ǩ �Ķ���
	//! \return �ɹ�������TRUE, ���򷵻�FALSE��
	virtual OgdcBool ResetPos();

	//! \brief �Ƿ��Ѿ��������һ����ǩ
	virtual OgdcBool IsEof() const = 0 ;

	//! \brief ����ǩ�����ұ�ǩ��
	//! \return �ɹ�������TRUE������λ���ñ�ǩ�� ���򷵻�FALSE��
	virtual OgdcBool FindTag(const OgdcString &strTagName);

	//! \brief ��ȡ��ǩ��
	//! \return �ɹ������ر�ǩ��, ���򷵻�""��
	virtual OgdcString GetTagName() const = 0;

	//! \brief ��ȡ��ǩֵ
	//! \return �ɹ������ر�ǩֵ, ���򷵻�""��
	virtual OgdcString GetData() const = 0;

	//! \brief ���ñ�ǩֵ
	//! \return �ɹ������ر�ǩֵ, ���򷵻�""��
	virtual OgdcBool SetData(const OgdcString &strData)  = 0;

	//! \brief �����ݿ��ж�ȡָ���� m_strMetadataUUID ��Ԫ���ݵ���ϸ���ݡ�
	//! \return ��ȡ�ɹ�����TRUE�����򷵻�FALSE��
	virtual OgdcBool Fetch() = 0;	

	//! \brief ����ǰԪ���ݵ����ݸ��µ����ݿ��У����е��޸���Update֮ǰ���������ڴ���
	//! \return ���³ɹ�����TRUE�����򷵻�FALSE��
	virtual OgdcBool Update() = 0;

public:
	//! \brief ��ǰԪ���ݵ�UUID
	//! \remarks �� Import ��Ԫ���ݿ�ʱ�Զ����ɣ�Ҳ���Դ�����Դ�����ݼ���ȡ�������޸�
	OgdcString m_strMetadataUUID;

};

}

#endif // !defined(AFX_OGDCMETADATA_H__6100835C_9516_424B_9D85_CCDF0C281B3D__INCLUDED_)

