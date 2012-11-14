//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcDatasetRasterInfo.h
//!  \brief OgdcDatasetRasterInfo �Ľӿڶ��塣
//!  \details Ogdcդ�����ݼ���Ϣ�Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef OGDCDATASETRASTERINFO_H
#define OGDCDATASETRASTERINFO_H

#include "Base/OgdcColorset.h"
#include "OGDC/OgdcDataset.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{


class OGDC_API OgdcBandInfo
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcBandInfo();
	//! \brief ��������
	virtual ~OgdcBandInfo();

public:
	//! \brief �������캯��
	void operator=(const OgdcBandInfo& bInfo);
	//! \brief �������ݼ��Ĳ�����ţ�Base 0��
	OgdcInt m_nBandIndex;
	//! \brief ���ε�����
	OgdcString m_strName;
	//! \brief �������ڵ�����
	OgdcString m_strFieldName;
	//! \brief ���ε�������Ϣ
	OgdcString m_strDescription;
	//! \brief ���ε����ظ�ʽ
	PixelFormat m_nPixelFormat;
	//! \brief ���ε�Ӱ�����ֽ���
	OgdcInt m_nWidthBytes;
	//! \brief ��άBounds����Сֵ
	OgdcDouble m_dMinZ;
	//! \brief ��άBounds�����ֵ
	OgdcDouble m_dMaxZ;
	//! \brief ��ɫ��
	OgdcColorset m_colorset;
	//! \brief ��Чֵ�����ĳһ���ֵ��m_NoValue,����Ϊ��һ��û��ֵ
	OgdcDouble m_dNoValue;
};

//! \brief Ogdcդ�����ݼ�������Ϣ�ࡣ
class OGDC_API OgdcDatasetRasterInfo  
{
public:
	//! \brief դ�����ݼ���λ���С��
	enum IBSizeOption 
	{
		//! \brief 64*64
		IBS_64				= 64,
		//! \brief 128*128
		IBS_128				= 128,
		//! \brief 256*256
		IBS_256				= 256,
		//! \brief 512*512
		IBS_512				= 512,
		//! \brief 1024*1024
		IBS_1024			= 1024,
		//! \brief 2048*2048
		IBS_2048			= 2048,
		//! \brief 4096*4096
		IBS_4096			= 4096,
		//! \brief 8192*8192
		IBS_8192			= 8192
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcDatasetRasterInfo();

	//! \brief �������캯��
	//! \param rInfo ����դ�����ݼ���������[in]��
	OgdcDatasetRasterInfo(const OgdcDatasetRasterInfo& rasterInfo);	
	//! \brief Ĭ����������
	virtual ~OgdcDatasetRasterInfo();
public:
	//! \brief ��ֵդ�����ݼ���������
	//! \param rInfo ����դ�����ݼ���������[in]��
	const OgdcDatasetRasterInfo& operator =(const OgdcDatasetRasterInfo& rasterInfo);	

	//! \brief ��ǰ������Ŀ�������бȽ��Ƿ���ȫ��ͬ��
	//! \param rInfo Ŀ��դ�����ݼ���������[in]��
	//! \return �Ƿ���ͬ����ͬ����TRUE����ͬ����FALSE��
	OgdcBool operator ==(const OgdcDatasetRasterInfo& rasterInfo);	

	//! \brief ��ǰ������Ŀ�������бȽ��Ƿ���ͬ��
	//! \param rInfo Ŀ��դ�����ݼ���������[in]��
	//! \return �Ƿ�ͬ����ͬ����TRUE����ͬ����FALSE��
	OgdcBool operator !=(const OgdcDatasetRasterInfo& rasterInfo);		

public:
	//! \brief ���ݼ����ơ�
	OgdcString m_strName;
	
	//! \brief ���ݼ����͡�
	OgdcDataset::Type m_nType;
		
	//! \brief ���ظ�ʽ��
	PixelFormat m_nPixelFormat;
	
	//! \brief Ӱ���ȣ���λ������ֵ��
	OgdcInt m_nWidth;
	
	//! \brief Ӱ��߶ȣ���λ������ֵ��
	OgdcInt m_nHeight;
	
	//! \brief Ӱ��ÿһ�е��ֽ�����
	OgdcInt m_nWidthBytes;
	
	//! \brief ��λӰ���߳���
	OgdcDatasetRasterInfo::IBSizeOption m_nBlockSize;
	
	//! \brief ���ݼ��ĵ���Χ��
	OgdcRect2D m_rcBounds;	
	
	//! \brief ����ֿ�����(��������)��
	OgdcInt m_nColBlocks;		
	
	//! \brief ����ֿ�����(��������)��
	OgdcInt m_nRowBlocks;	

	//! \brief ��ɫ��
	OgdcColorset m_colorset;
	
	//! \brief ��Чֵ�����ĳһ���ֵ��m_NoValue,����Ϊ��һ��û��ֵ��
	OgdcDouble m_dNoValue;
	//! \brief ������
	OgdcInt m_nBandCount;

	//! \brief �������ݼ��Ĳ�����ţ�Base 0��
	OgdcInt m_nBandIndex;
	
	//! \brief �����������ݱ�������ơ�
	OgdcString m_strFieldName;

	//! \brief �����ݼ���������Ϣ��
	OgdcString m_strDescription;

	//! \brief ��С�߳�ֵ 
	OgdcDouble m_dMinZ;
	
	//! \brief ���߳�ֵ
	OgdcDouble m_dMaxZ;

	//������Ϣ
	OgdcArray<OgdcBandInfo> m_arrBandInfo;
};

}
#endif // !defined(OGDCDATASETRASTERINFO_H)

