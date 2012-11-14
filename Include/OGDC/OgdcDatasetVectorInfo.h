//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcDatasetVectorInfo.h
//!  \brief OgdcDatasetVectorInfo �Ľӿڶ��塣
//!  \details Ogdcʸ�����ݼ���Ϣ�Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef OGDCDATASETVECTORINFO_H
#define OGDCDATASETVECTORINFO_H

#include "OGDC/OgdcDataset.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

//! \brief Ogdcʸ�����ݼ�������Ϣ�ࡣ
class OGDC_API OgdcDatasetVectorInfo  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcDatasetVectorInfo();
	//! \brief �������캯��
	OgdcDatasetVectorInfo(const OgdcDatasetVectorInfo& vectorInfo);
	//! \brief Ĭ����������
	virtual ~OgdcDatasetVectorInfo();

public:
	//! \brief ���ز����� =
	const OgdcDatasetVectorInfo& operator =(const OgdcDatasetVectorInfo& vectorInfo);
	//! \brief ���ز����� ==
	OgdcBool operator ==(const OgdcDatasetVectorInfo& vectorInfo);
	//! \brief ���ز����� !=
	OgdcBool operator !=(const OgdcDatasetVectorInfo& vectorInfo);

public:
	//! \brief ���ݼ����ơ�
	OgdcString m_strName;
	
	//! \brief ���ݼ����͡�
	OgdcDataset::Type m_nType;		

	//! \brief ���ݼ��ĵ���Χ��
	OgdcRect2D m_rcBounds;	
	
	//! \brief �����ݼ���������Ϣ��
	OgdcString m_strDescription;

	OgdcInt m_nSpatialIndexType;	
};

}
#endif // !defined(OGDCDATASETVECTORINFO_H)

