//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcDatasetRaster.h
//!  \brief OgdcDatasetRaster �Ľӿڶ��塣
//!  \details Ogdc����Ӱ�����ݼ��Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCDATASETRASTER_H
#define OGDCDATASETRASTER_H

#include "OGDC/OgdcDatasetRasterInfo.h"
#include "Base/OgdcColorTable.h"
#include "Element/OgdcElemRegion.h"
#include "Element/OgdcRasterBlock.h"
#include "OGDC/OgdcDataset.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{

//! \brief Ogdcդ�����ݼ���
//! \remarks դ�����ݼ�����Image��Grid���ݼ���
class OGDC_API OgdcDatasetRaster : public OgdcDataset  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcDatasetRaster();
	//! \brief Ĭ����������
	virtual ~OgdcDatasetRaster();

public:
	//! \brief ����Ӱ���������
	//! \param bShhowProgress �Ƿ���ʾ������[in]��
	//! \return �Ƿ񴴽��ɹ����Ƿ���TRUE�����򷵻�FALSE��
	virtual OgdcBool BuildPyramid() =0;	

	//! \brief �Ƴ�Ӱ���������
	//! \return �Ƿ��Ƴ��ɹ����Ƿ���TRUE�����򷵻�FALSE��
	virtual OgdcBool DropPyramid() = 0;	
	//! \brief �ж��Ƿ��Ѿ�����Ӱ���������
	virtual OgdcBool IsBuildPyramid() const =0;
	
	//! \brief ��ȡӰ�����ݼ�ָ������ĳһ���ص����ɫֵ��
	//! \param nCol ���ص��к�[in]��
	//! \param nRow ���ص��к�[in]��
	//! \return ��ɫֵ��
	//! \remarks ��ɫֵ����ֵ�����ݼ������ظ�ʽ��ͬ����ͬ��
	virtual OgdcColor GetPixel(OgdcInt nCol, OgdcInt nRow) = 0;	
	
	//! \brief  ����Ӱ�����ݼ�ָ������ĳһ���ص����ɫֵ��
	//! \param nCol ���ص��к�[in]��
	//! \param nRow ���ص��к�[in]��
	//! \param nColor ��ɫֵ[in]��
	//! \remarks Ҫ�������ݼ������ظ�ʽ��ȷ�������ص����ɫֵ��
	virtual void SetPixel(OgdcInt nCol, OgdcInt nRow, OgdcColor nColor) = 0;	
	
	//! \brief ��ȡGrid���ݼ�ָ������ĳһ�������ֵ��
	//! \param nCol �����к�[in]��
	//! \param nRow �����к�[in]��
	//! \return ����ֵ��
	virtual OgdcDouble GetValue(OgdcInt nCol, OgdcInt nRow) = 0;
	
	//! \brief ����Grid���ݼ�ָ������ĳһ�������ֵ��
	//! \param nCol �����к�[in]��
	//! \param nRow �����к�[in]��
	//! \param dValue ����ֵ[in]��
	//! \remarks Ҫ�������ݼ��İ׻�ֵ��ȷ��������������ֵ��
	virtual void SetValue(OgdcInt nCol, OgdcInt nRow, OgdcDouble dValue) = 0;
	
	//! \brief ��ȡ�ɼ�դ���
	//! \param rcView �ɼ���Χ
	//! \param nDeviceWidth  ��ʾ�豸�Ŀ��
	//! \param nDeviceHeight ��ʾ�豸�ĸ߶�
	virtual OgdcRasterBlock* GetViewBlock(const OgdcRect2D& rcView, 
		OgdcInt nDeviceWidth, OgdcInt nDeviceHeight) = 0;

public:
	//! \brief ��ȡ���ݼ����͡�
	virtual OgdcInt GetType() const;

	//! \brief ��ȡ���ݼ�����
	//! \return ���ݼ����ַ�����
	virtual OgdcString GetName();

	//! \brief �ж��Ƿ�Ϊդ�����ݼ�
	OgdcBool IsRaster();

	//! \brief ��ȡ���ݼ�������Ϣ��
	//! \return ���ݼ���������Ϣ�ַ�����
	virtual OgdcString GetDescription() const;

	//! \brief �������ݼ�������Ϣ��
	//! \param strtDescription ���ݼ�������Ϣ�ַ���[in]��
	virtual void SetDescription(const OgdcString& strtDescription);	

	//! \brief �������ݼ���ά����
	//! \return ���ݼ��Ŀռ�ά��, դ��Ϊ-1ά��
	virtual OgdcInt GetStyleDimension();		
	
	//! \brief �������ݼ��ĵ���Χ��
	//! \return ���ݼ�����Χ���Ρ�
	virtual OgdcRect2D GetBounds();	
	
	//! \brief �������ݼ��ĵ���Χ��
	//! \param rcBunds ���ݼ�����Χ����[in]��
	virtual void SetBounds(const OgdcRect2D& rcBounds);	
	//! \brief ��ȡ������
	virtual OgdcInt GetBandCount() const;
	//! \brief ���ò�������
	//! \param nBandIndex ��������ֵ
	virtual void SetBandIndex(OgdcInt nBandIndex);
	//! \brief ��ȡ��������
	virtual OgdcInt GetBandIndex() const;
	//! \brief ���ò��κϳɷ�ʽ
	//! \param aryBand		�ನ��
	//! \param nColorSpace	ɫ�ʿռ��ʽ
	virtual void SetBandCombineMode(const OgdcArray<OgdcInt>& aryBand, ImgColorSpace nColorSpace);
	//! \brief ��ȡ���κϳɷ�ʽ
	//! \param aryBand		�ನ��
	//! \param nColorSpace	ɫ�ʿռ��ʽ
	virtual OgdcBool GetBandCombineMode(OgdcArray<OgdcInt>& aryBand, ImgColorSpace& nColorSpace) const;
	
	//! \brief ��ȡդ�����ݼ���ȡ�
	//! \return դ�����ݼ���ȣ�������ֵΪ��λ��
	virtual OgdcInt GetWidth() const;	
	
	//! \brief ��ȡդ�����ݼ��߶ȣ�������ֵΪ��λ��
	//! \return դ�����ݼ��߶ȣ�������ֵΪ��λ��
	virtual OgdcInt GetHeight() const;	

	//! \brief ��ȡդ�����ݼ��������Чֵ��
	//! \return ��Чֵ
	//! \remarks Grid���ݼ��İ׻�ֵ��Ҳ�ɴ˽ӿڻ�ȡ��
	virtual OgdcDouble GetNoValue() const;	
	
	//! \brief ����դ�����ݼ�����Чֵ��
	//! \param dbNoValue [in]��
	//! \remarks Grid���ݼ��İ׻�ֵ��Ҳ�ɴ˽ӿ����á�
	virtual void SetNoValue(OgdcDouble dbNoValue);
	
	//! \brief ��ȡӰ������ظ�ʽ��
	//! \return ���ظ�ʽö��ֵ��
	virtual PixelFormat GetPixelFormat() const;	

	//! \brief �õ�ɨ���ߡ�
	//! \param nRowIndex ɨ����������[in]��
	//! \param scanLine ɨ��������[out]��
	//! \param nStartCol ɨ������ʼ��[in]��
	//! \return �Ƿ��ȡ�ɹ���
	virtual OgdcBool GetScanline(OgdcInt nRowIndex,OgdcRasterScanline& scanLine, OgdcInt nStartCol = 0);

	//! \brief ͨ��������������ɨ���ߡ�
	//! \param nRowIndex ɨ����������[in]��
	//! \param nColIndex ɨ����������[in]��
	//! \param scanLine ɨ��������[in]��
	//! \return �Ƿ����óɹ���
	virtual OgdcBool SetScanline(OgdcInt nRowIndex,OgdcInt nColIndex, const OgdcRasterScanline& scanLine);

	//! \brief ����ָ�������ݡ�
	//! \param nRowBlock Ӱ����к�[in]��
	//! \param nColBlock Ӱ����к�[in]��
	//! \return Ӱ���ָ�롣
	virtual OgdcRasterBlock* LoadBlock(OgdcInt nRowBlock, OgdcInt nColBlock);	
    
	//! \brief ��һ�ڴ��е�Ӱ��������̡�
	//! \param pImgBlock Ӱ���ָ��[in]��
	//! \return �Ƿ�ɹ����棬�ɹ�����TRUE��ʧ�ܷ���FALSE��
	virtual OgdcBool SaveBlock(OgdcRasterBlock* pImgBlock);	
	
	//! \brief �ͷ�Ӱ������ݡ�
	virtual void ReleaseAllBlocks();	

	// �޸ĳ�Ա������Ҫ����SetModified
public:
	//! \brief ����μ�������
	OgdcElemRegion* m_pClipRgn;
    //! \brief դ�����ݼ���Ϣ
	OgdcDatasetRasterInfo m_info;
	//! \brief ��ɫ��
	OgdcColorTable m_colorTable;	
};
}
#endif // !defined(OGDCDATASETRASTER_H)

