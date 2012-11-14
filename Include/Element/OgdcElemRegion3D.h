// OgdcElemRegion3D.h: interface for the OgdcElemRegion3D class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcElemRegion3D.h
//!  \brief ��ά�����
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMREGION3D_H__8154B56F_4FD0_4F26_A4EA_FF0D2C696F35__INCLUDED_)
#define AFX_OGDCELEMREGION3D_H__8154B56F_4FD0_4F26_A4EA_FF0D2C696F35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcElement.h"
#include "Base/OgdcPoint3D.h"

namespace OGDC {
//!  \brief ��ά����ζ�����
class ELEMENT_API OgdcElemRegion3D : public OgdcElement  
{
public:
	//!  \brief ��ά�����Ĭ�Ϲ��캯��
	OgdcElemRegion3D();
	//!  \brief ��ά�����Ĭ����������
	virtual ~OgdcElemRegion3D();

public:
	//! \brief  �õ���ά����ζ�������
	virtual OgdcInt GetType() const;

	//! \brief  �õ�������ά����2ά��
	virtual OgdcInt GetStyleDimension() const;	

	//! \brief  ������ά����ζ���
	OgdcBool Make(const OgdcElemRegion3D* pElement);
		
	//! \brief  ������ά����ζ���
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

#endif // !defined(AFX_OGDCELEMREGION3D_H__8154B56F_4FD0_4F26_A4EA_FF0D2C696F35__INCLUDED_)

