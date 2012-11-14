//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcPoint.h
//!  \brief �����
//!  \details  
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCPOINT_H__2388B98A_6C57_4E01_B775_57C22DD6CEC6__INCLUDED_)
#define AFX_OGDCPOINT_H__2388B98A_6C57_4E01_B775_57C22DD6CEC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcSize.h"
#include "Base/OgdcArray.h"

namespace OGDC {

class OgdcSize;
//!  \brief ��ά����㣬OgdcInt�ͣ������������Ļ�������豸�����
class BASE_API OgdcPoint  
{
public:
	//! \brief ��ĺ�����
	OgdcInt x;
	//! \brief ���������
	OgdcInt y;
public:

	//! \brief 		ȱʡ���캯��
	OgdcPoint();
	
	//! \brief 		Ĭ����������
	~OgdcPoint();

	//! \brief 		���ι��캯��	
	//! \param 		nX			������
	//! \param 		nY			������		
	OgdcPoint(OgdcInt nX,OgdcInt nY);	

	//! \brief 		�������캯��	
	//! \param 		sz					
	OgdcPoint(const OgdcSize& sz);

	//! \brief 		�Ƶ���ת
	//! \param 		pntAnchor	���ĵ�
	//! \param 		dRadian		˳ʱ����ת�Ƕ�(����)	
	void Rotate(const OgdcPoint& pntAnchor, double dRadian);

	//! \brief 		�Ƶ���ת
	//! \param 		pntAnchor	���ĵ�
	//! \param 		dCos		����ֵ
	//! \param 		dSin		����ֵ	
	void Rotate(const OgdcPoint& pntAnchor, double dCos, double dSin);

	//! \brief 		��ƫ��
	//! \param 		szValue		ƫ����	
	void Offset(const OgdcSize &szValue);

	//! \brief 		��ƫ��
	//! \param 		nOffsetX	������ƫ��
	//! \param 		nOffsetY	������ƫ��	
	void Offset(OgdcInt nOffsetX, OgdcInt nOffsetY);

	//! \brief 		���� == 
	//! \return 	����pntStart��pntEnd�ıȽϽ������ȷ���true�����ȷ���false��
	friend BASE_API OgdcBool operator==(const OgdcPoint& pntStart,const OgdcPoint& pntEnd);

	//! \brief 		���� != 
	//! \return 	����pntStart��pntEnd�ıȽϽ�������ȷ���true����ȷ���false��	
	friend BASE_API OgdcBool operator!=(const OgdcPoint& pntStart,const OgdcPoint& pntEnd);			

	//! \brief 		���� = 	
	OgdcPoint& operator=(const OgdcSize& sz);
	
	//! \brief 		���� = 	
	OgdcPoint& operator=(const OgdcPoint& pnt);

	//! \brief 		���� += 
	OgdcPoint& operator+=(const OgdcPoint& pnt);

	//! \brief 		���� += 	
	OgdcPoint& operator+=(const OgdcSize& sz);

	//! \brief 		���� -= 	
	OgdcPoint& operator-=(const OgdcPoint& pnt);

	//! \brief 		���� -= 
	OgdcPoint& operator-=(const OgdcSize& sz);	

	//! \brief 		���� -(ȡ�෴��) 
	//! \return 	OgdcPoint
	//! \remarks 	
	OgdcPoint operator-() const;		

	//! \brief 		���� +
	friend BASE_API OgdcPoint operator+(const OgdcPoint& pntStart,const OgdcPoint& pntEnd);

	//! \brief 		���� +	
	friend BASE_API OgdcPoint operator+(const OgdcPoint& pnt,const OgdcSize& sz);
	
	//! \brief 		���� +	
	friend BASE_API OgdcPoint operator+(const OgdcSize& sz,const OgdcPoint& pnt);	
	
	//! \brief 		���� -	
	friend BASE_API OgdcPoint operator-(const OgdcPoint& pntStart,const OgdcPoint& pntEnd);

	//! \brief 		���� -
	friend BASE_API OgdcPoint operator-(const OgdcPoint& pnt,const OgdcSize& sz);

	//! \brief 		���� -
	friend BASE_API OgdcPoint operator-(const OgdcSize& sz,const OgdcPoint& pnt);
	
	
};

typedef OgdcArray<OgdcPoint> OgdcPoints;
	
}

#endif // !defined(AFX_OGDCPOINT_H__2388B98A_6C57_4E01_B775_57C22DD6CEC6__INCLUDED_)

