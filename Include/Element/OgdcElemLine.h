// OgdcElemLine.h: interface for the OgdcElemLine class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcElemLine.h
//!  \brief ��
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMLINE_H__D3B68FE6_4851_4125_B584_EB53F60F784C__INCLUDED_)
#define AFX_OGDCELEMLINE_H__D3B68FE6_4851_4125_B584_EB53F60F784C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief �߶�����
class ELEMENT_API OgdcElemLine : public OgdcElement  
{
public:
	//!  \brief �߶�����Ĭ�Ϲ��캯��
	OgdcElemLine();
	//!  \brief �߶�����Ĭ����������
	virtual ~OgdcElemLine();

public:
	//! \brief  �õ��߶������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����1ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  �����߶���
	OgdcBool Make(const OgdcElemLine* pElement);
		
	//! \brief  �����߶���
	//! \param  points �����顣
	//! \param  polyCounts �Ӷ���������Ϣ��
	OgdcBool Make(const OgdcArray<OgdcPoint2D>& points, 
				const OgdcArray<OgdcInt>& polyCounts);			
	
public:
	//! \brief �ڲ��õ��������洢��������ꡣ
	OgdcArray<OgdcPoint2D> m_points;
	//! \brief �����Ӷ���������Ϣ
	OgdcArray<OgdcInt> m_polyCounts;			

};

}

#endif // !defined(AFX_OGDCELEMLINE_H__D3B68FE6_4851_4125_B584_EB53F60F784C__INCLUDED_)

