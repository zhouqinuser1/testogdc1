// OgdcRasterScanline.h: interface for the OgdcRasterScanline class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcRasterScanline.h
//!  \brief դ����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCRASTERSCANLINE_H__0F996C74_D952_4E97_BBF1_D9453140A029__INCLUDED_)
#define AFX_OGDCRASTERSCANLINE_H__0F996C74_D952_4E97_BBF1_D9453140A029__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcArray.h"

#define OGDC_NOVALUE -9999 

namespace OGDC {

//!  \brief դ��ɨ������
class ELEMENT_API OgdcRasterScanline:public OgdcArray<OgdcUchar>
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcRasterScanline();
	//! \brief Ĭ����������
	~OgdcRasterScanline();

public:

	//! \brief �õ�һ�����ص�λ����
	//! \param pf ���ظ�ʽ
	static OgdcInt GetBitCount(PixelFormat pf); 

	//! \brief ��������BYTE˳�򽻻�
	void SwapBlueRed();	
	
	//! \brief �����ҵ�BYTE˳�򽻻�
	void SwapLeftRight();
	
	//! \brief ��������
	//! \param x ����λ��
	//! \param nPixel ����ֵ
	OgdcBool SetPixel(OgdcInt x, OgdcInt nPixel);
	
	//! \brief ��ȡ����
	//! \param x ����λ��
	OgdcInt GetPixel(OgdcInt x);
	
	//! \brief ��������ֵ
	//! \param x ����λ��
	//! \param dValue ����ֵ
	OgdcBool SetValue(OgdcInt x, OgdcDouble dValue);
	
	//! \brief ��ȡ����ֵ
	//! \param x ����λ��
	OgdcDouble GetValue(OgdcInt x);

	//! \brief ��ȡ���ظ�ʽ
	PixelFormat GetPixelFormat() const;

	//! \brief �������ظ�ʽ
	//! \param nPixelFormat ���ظ�ʽ
	void SetPixelFormat(PixelFormat nPixelFormat);

	//! \brief ��ȡɨ������ռ�ֽ���
	OgdcInt GetWidthBytes() const;

	//! \brief ����ɨ������ռ�ֽ���
	//! \param nNewSize �ֽ���
	void SetWidthBytes(const OgdcInt nNewSize);

	//! \brief ��ȡɨ���߿��
	OgdcInt GetWidth() const;

	//! \brief ����ɨ���߿��
	//! \param nWidth ɨ���߿��
	void SetWidth(OgdcInt nWidth);
	
	//! \brief  ����ɨ���߼�ֵ
	//! \param dMaxValue ���ֵ[out]
	//! \param dMinValue ��Сֵ[out]
	//! \param nNoValue  ��ֵ[in]
	OgdcBool CalcuExtremum(OgdcDouble& dMaxValue, OgdcDouble& dMinValue, OgdcInt nNoValue = OGDC_NOVALUE);
		
private:
	//! \brief ���ظ�ʽ
	PixelFormat m_nPixelFormat;

	//! \brief ɨ���߿��
	OgdcInt m_nWidth;

};

}

#endif // !defined(AFX_OGDCRASTERSCANLINE_H__0F996C74_D952_4E97_BBF1_D9453140A029__INCLUDED_)

