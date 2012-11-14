// OgdcRasterBlock.h: interface for the OgdcRasterBlock class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)            
//                                                           
//!  \file OgdcRasterBlock.h
//!  \brief դ���
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCRASTERBLOCK_H__A17D0A45_99AE_4A52_94AD_DFC0C2727811__INCLUDED_)
#define AFX_OGDCRASTERBLOCK_H__A17D0A45_99AE_4A52_94AD_DFC0C2727811__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Element/OgdcRasterScanline.h"
#include "Base/OgdcRect2D.h"
#include "Base/OgdcColorset.h"


namespace OGDC {
//!  \brief դ�����
class ELEMENT_API OgdcRasterBlock
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcRasterBlock();
	//! \brief Ĭ����������
	virtual ~OgdcRasterBlock();
	
public:
	//! \brief ����һ��դ���
    //! \param nPixelFormat   ���ظ�ʽ
	//! \param nBlockRowIndex ����������
	//! \param nBlockColIndex ����������
	//! \param nPixelRowIndex ��ʼ������(���ص�λ)
	//! \param nPixelColIndex ��ʼ������(���ص�λ)
	//! \param nWidth		  ���
	//! \param nHeight		  �߶�
	//! \param nValidWidth	  ��Ч���
	//! \param nValidHeight	  ��Ч�߶�
	//! \param pColorset	  ��ɫ
	//! \param nWidthBytes �ֽڿ��
	void Create(PixelFormat nPixelFormat, 
					OgdcInt nBlockRowIndex, 
					OgdcInt nBlockColIndex, 
					OgdcInt nPixelRowIndex,
					OgdcInt nPixelColIndex,
					OgdcInt nWidth,
					OgdcInt nHeight,
					OgdcInt nValidWidth,
					OgdcInt nValidHeight,
					OgdcColorset * pColorset,
					OgdcBool bInited,
					OgdcInt nWidthBytes);

	//! \brief ��������BYTE˳�򽻻�
	void SwapBlueRed();

	//! \brief  ��ȡ�ֽڿ��
	OgdcInt GetWidthBytes();

	//! \brief  �Ƿ��޸ġ�
	OgdcBool IsModified() const;
	//! \brief �����޸ı��
	void SetModifiedFlag(OgdcBool bFlag = TRUE);

	//! \brief  ������ݣ��ͷ��ڴ�
	void Empty();

	//! \brief  �Ƿ���Ч
	OgdcBool IsValid() const;
	
	//! \brief  ��ȡ�����ڴ��С��
	OgdcInt GetByteSize() const;
	//! \brief �����ڴ��С
	//! \param nNewSize �µ��ڴ��С
	void SetByteSize(const OgdcInt nNewSize);
			
	//! \brief  ��ȡ�ֽ����ݡ�
	const OgdcByte* GetBlockData() const;

	//! \brief  ����������ɫ
	//! \param x		x����ֵ
	//! \param y		y����ֵ
	//! \param nPixel	������ɫֵ
	OgdcBool SetPixel(OgdcInt x,OgdcInt y,OgdcInt nPixel);
	
	//! \brief  ��ȡ������ɫ
	//! \param x		x����ֵ
	//! \param y		y����ֵ
	OgdcInt GetPixel(OgdcInt x,OgdcInt y);
	
	//! \brief  ��������ֵ
	//! \param x		x����ֵ
	//! \param y		y����ֵ
	//! \param dValue	����ֵ
	OgdcBool SetValue(OgdcInt x,OgdcInt y,OgdcDouble dValue);
	
	//! \brief  ��ȡ����ֵ
	//! \param x		x����ֵ
	//! \param y		y����ֵ
	OgdcDouble GetValue(OgdcInt x,OgdcInt y);
	
	//! \brief  ��ȡָ����������ɨ����
	//! \param nRowIndex ������ֵ[in]
	//! \param ScanLine  ��ȡ��ɨ����[out]
	//! \param nStartPosInSL ������ɨ�����е�λ��[in]
	//! \param nStartPosInBlk �����Ƶ������ڿ��е���ʼλ��[in]
	OgdcBool GetScanline(OgdcInt nRowIndex,OgdcRasterScanline& ScanLine, 
			OgdcInt nStartPosInSL,OgdcInt nStartPosInBlk = 0 );
	
	//! \brief  ͨ��������������ɨ����
	//! \param nRowIndex ������ֵ[in]
	//! \param ScanLine  ��ȡ��ɨ����[out]
	//! \param nStartPosInSL �����ɨ���ߵ���ʼλ��[in]
	//! \param nStartPosInBlk �����õ������ڿ��е���ʼλ��[in]
	OgdcBool SetScanline(OgdcInt nRowIndex,	const OgdcRasterScanline& scanline, 
			OgdcInt nStartPosInSL, OgdcInt nStartPosInBlk = 0 );

	//! \brief  ��ʼ��	
	OgdcBool Init();

	//! \brief  Image��Blockʹ�����ֵ����Сֵ��ʼ��
	OgdcBool InitImage(OgdcInt nValue);

	//! \brief  Grid��Blockʹ��NoValue��ʼ��
	OgdcBool InitGrid(OgdcInt nNoValue);
	//! \brief  ����դ��鼫ֵ��ָ������ֵ����������
	//! \param dMaxValue ���ֵ[out]
	//! \param dMinValue ��Сֵ[out]
	//! \param nNoValue ��ֵ[in]
	OgdcBool CalcuExtremum(OgdcDouble& dMaxValue, OgdcDouble& dMinValue, OgdcInt nNoValue = OGDC_NOVALUE);
	
	//! \brief  ����դ��鼫ֵ����ԭblock���ÿ��դ��ֵ����ֵҲ����Ϊһ����Ч��դ��ֵ��������
	//! \param dMaxValue ���ֵ[out]
	//! \param dMinValue ��Сֵ[out]
	OgdcBool CalcuExtremumWithNoValue(OgdcDouble& dMaxValue, OgdcDouble& dMinValue);

	//! \brief  ��ȡդ�����Сֵ
	//! \param nNoValue ��ֵ[in]
	OgdcDouble GetMinValue(OgdcInt nNoValue = OGDC_NOVALUE);
	//! \brief  ��ȡդ������ֵ
	//! \param nNoValue ��ֵ[in]
	OgdcDouble GetMaxValue(OgdcInt nNoValue = OGDC_NOVALUE);
	
	//{{�������û���,��ʹ��ImgBlockRef����ImgBlockʱ,��¼��ǰImgBlock�ı����ô���, 
	//! \brief �������û���
	//! \attention �������ⲿʹ�ø÷���,����ᵼ���ڴ�й©
	void AddRefCount(){ m_nRefCount++; }

	//! \brief ��ʹ��ImgBlockRef����ImgBlockʱ,��¼��ǰImgBlock�ı����ô���, �������û���
	void ReduceRefCount() { m_nRefCount--; }

	//! \brief ���û�����0
	void ResetRefCount() { m_nRefCount = 0; }

	//! \brief ��ȡ��ǰ���û���
	OgdcInt GetRefCount() { return m_nRefCount; }
	//}}
protected:
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��1λ����ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel1(OgdcInt x, OgdcInt y);
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��4λ��16ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel4(OgdcInt x, OgdcInt y);
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��8λ��256ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel8(OgdcInt x, OgdcInt y);
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��16λ����ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel16(OgdcInt x, OgdcInt y);
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��24λ�����ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel24(OgdcInt x, OgdcInt y);
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��32λ����ǿ���ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel32(OgdcInt x, OgdcInt y);
	//! \brief ��ȡ������ɫֵ�����ظ�ʽ��32λ�����ͣ�
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixel32UGint(OgdcInt x, OgdcInt y);
    //! \brief ��ȡ������ɫֵ�����ظ�ʽ��64λDoouble��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	OgdcColor GetPixelDouble(OgdcInt x, OgdcInt y);
	//! \brief ����������ɫֵ�����ظ�ʽ��1λ����ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel1(OgdcInt x, OgdcInt y, OgdcColor color);
	//! \brief ����������ɫֵ�����ظ�ʽ��4λ��16ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel4(OgdcInt x, OgdcInt y, OgdcColor color);
	//! \brief ����������ɫֵ�����ظ�ʽ��8λ��256ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel8(OgdcInt x, OgdcInt y, OgdcColor color);
	//! \brief ����������ɫֵ�����ظ�ʽ��16λ����ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel16(OgdcInt x, OgdcInt y, OgdcColor color);
	//! \brief ����������ɫֵ�����ظ�ʽ��24λ�����ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel24(OgdcInt x, OgdcInt y, OgdcColor color);
	//! \brief ����������ɫֵ�����ظ�ʽ��32λ����ǿ���ɫ��
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel32(OgdcInt x, OgdcInt y, OgdcColor color);
	//! \brief ����������ɫֵ�����ظ�ʽ��32λ�����ͣ�
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixel32UGint(OgdcInt x, OgdcInt y, OgdcColor color);	
	//! \brief ����������ɫֵ�����ظ�ʽ��64λDoouble)
	//! \param x	x����ֵ
	//! \param y	y����ֵ
	//! \param color ��ɫֵ
	OgdcBool SetPixelDouble(OgdcInt x, OgdcInt y, OgdcColor color);	


public:
	//! \brief  ���صĸ�ʽ
	PixelFormat m_nPixelFormat;

	//! \brief  ������������
	OgdcInt m_nBlockRowIndex;

	//! \brief  ������������
	OgdcInt m_nBlockColIndex;

	//! \brief  ��ʼ������(���ص�λ)
	OgdcInt m_nPixelColIndex;
	
	//! \brief  ��ʼ������(���ص�λ)
	OgdcInt m_nPixelRowIndex;

	//! \brief  ���
	OgdcInt m_nWidth;

	//! \brief  �߶�
	OgdcInt m_nHeight;

	//! \brief  �ֽڿ��
	OgdcInt m_nWidthBytes;

	//! \brief  ��Ч���
	OgdcInt m_nValidWidth;

	//! \brief  ��Ч�߶�
	OgdcInt m_nValidHeight;

	//! \brief  ����Χ
	OgdcRect2D m_rcBounds;

	//! \brief  ��Сֵ
	OgdcDouble m_dMinValue;

	//! \brief  ���ֵ
	OgdcDouble m_dMaxValue;

	//! \brief  ��������Сֵ�Ƿ���Ҫ���¼���
	OgdcBool m_bIsExtremumDirty;	

	//! \brief  ��ɫ�壬ֻ��һ�����ã�����Ҫ�ͷš�
	OgdcColorset* m_pColorset;	

	//! \brief  �Ƿ��Ѿ���ʼ��
	OgdcBool m_bInited;	

	//! \brief  ��Ǹÿ��Ǵ����ݼ��л�ȡ����������ӵġ�
	OgdcBool m_bNewBlock;

	//! \brief ��ʾ��Bitsת����Valueֵʱ�Ƿ����޷��ŵġ������ڶನ��Ӱ��ĸ����ο飬��ֵΪTRUE������GRID/DEM��ֵΪFALSE�����ڵ�����Ӱ��Ŀǰû��Ӱ�죩
	OgdcBool m_bIsUnsign;
	
private:
	//! \brief  ��������
	OgdcArray<OgdcUchar> m_data;	

	//! \brief  �ж��Ƿ��޸�
	OgdcBool m_bModified;    

	//! \brief ���ݿ����û���
	OgdcInt m_nRefCount;
  };

}

#endif // !defined(AFX_OGDCRASTERBLOCK_H__A17D0A45_99AE_4A52_94AD_DFC0C2727811__INCLUDED_)

