// OgdcElemRegion.h: interface for the OgdcElemRegion class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcElemRegion.h
//!  \brief �����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMREGION_H__9897F4E4_DA45_4B79_A486_97DEFCA99415__INCLUDED_)
#define AFX_OGDCELEMREGION_H__9897F4E4_DA45_4B79_A486_97DEFCA99415__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"

namespace OGDC {
//!  \brief ����ζ�����
class ELEMENT_API OgdcElemRegion : public OgdcElement  
{
public:
	//!  \brief ����ζ���Ĭ�Ϲ��캯��
	OgdcElemRegion();
	//!  \brief ����ζ���Ĭ����������
	virtual ~OgdcElemRegion();

public:
	//! \brief  �õ�����ζ������͡�
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;

	//! \brief  ��������ζ���
	OgdcBool Make(const OgdcElemRegion* pElement);
		
	//! \brief  ��������ζ���
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

#endif // !defined(AFX_OGDCELEMREGION_H__9897F4E4_DA45_4B79_A486_97DEFCA99415__INCLUDED_)

