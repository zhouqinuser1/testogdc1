// OgdcElemLine3D.h: interface for the OgdcElemLine3D class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemLine3D.h
//!  \brief ��ά��
//!  \details 
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMLINE3D_H__3FDC161E_DC64_4DA0_B7A9_ABDC20F9AFD2__INCLUDED_)
#define AFX_OGDCELEMLINE3D_H__3FDC161E_DC64_4DA0_B7A9_ABDC20F9AFD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"
#include "Base/OgdcPoint3D.h"

namespace OGDC {
//!  \brief ��ά�߶�����
class ELEMENT_API OgdcElemLine3D : public OgdcElement  
{
public:
	//!  \brief ��ά�߶�����Ĭ�Ϲ��캯��
	OgdcElemLine3D();
	//!  \brief ��ά�߶�����Ĭ����������
	virtual ~OgdcElemLine3D();

public:
	//! \brief  �õ���ά�߶������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ������ά�߶���
	OgdcBool Make(const OgdcElemLine3D* pElement);
		
	//! \brief  ������ά�߶���
	//! \param  points ��ά�����顣
	//! \param  polyCounts �Ӷ���������Ϣ��
	OgdcBool Make(const OgdcArray<OgdcPoint3D>& points, 
				const OgdcArray<OgdcInt>& polyCounts);			
	
public:
	//! \brief �ڲ��õ��������洢��������ꡣ
	OgdcArray<OgdcPoint3D> m_points;
	//! \brief �����Ӷ���������Ϣ
	OgdcArray<OgdcInt> m_polyCounts;			

};

}

#endif // !defined(AFX_OGDCELEMLINE3D_H__3FDC161E_DC64_4DA0_B7A9_ABDC20F9AFD2__INCLUDED_)

