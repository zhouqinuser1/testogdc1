//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcPoint2D.h
//!  \brief 2D�����
//!  \details  
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCPOINT2D_H__8AEE7D11_E2F3_447D_AE4B_CC31AA76F2E0__INCLUDED_)
#define AFX_OGDCPOINT2D_H__8AEE7D11_E2F3_447D_AE4B_CC31AA76F2E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcSize2D.h"
#include "Base/OgdcPoint.h"
#include "Base/OgdcArray.h"

namespace OGDC {
//!  \brief ��ά����㣬OgdcDouble�ͣ�һ������������������ĵ�
class BASE_API OgdcPoint2D  
{
public:
	//! \brief ��ĺ�����
	OgdcDouble x;
	//! \brief ���������
	OgdcDouble y;
public:
		
    //! \brief  	ȱʡ���캯��
	OgdcPoint2D();
		
	//! \brief  	Ĭ�����캯��
	~OgdcPoint2D();
		
	//! \brief 		���ι��캯��	
	//! \param 		dX			������
	//! \param 		dY			������
   	OgdcPoint2D(OgdcDouble dX,OgdcDouble dY);
		
	//! \brief 		�������캯��	
	//! \param 		sz			
	OgdcPoint2D(const OgdcSize2D& sz);
		
	//! \brief 		�������캯��	
	//! \param 		sz			
	OgdcPoint2D(const OgdcPoint& pnt);
		
	//! \brief 		�Ƶ���ת
	//! \param 		pntAnchor	���ĵ�
	//! \param 		dRadian		��ת�Ƕ�(����)	
	void Rotate(const OgdcPoint2D& pntAnchor, OgdcDouble dRadian);
       
	//! \brief 		�Ƶ���ת
	//! \param 		pntAnchor	���ĵ�
	//! \param 		dCos		����ֵ
	//! \param 		dSin		����ֵ
	void Rotate(const OgdcPoint2D& pntAnchor, OgdcDouble dCos, OgdcDouble dSin);
	
	//! \brief 		��ƫ��
	//! \return 	void
	//! \param 		szValue		ƫ���� 
	void Offset(const OgdcSize2D &szValue);

	//! \brief 		��ƫ��
	//! \param 		nOffsetX	������ƫ��
	//! \param 		nOffsetY	������ƫ��
	void Offset(OgdcDouble dOffsetX, OgdcDouble dOffsetY);
	    
	//! \brief 		�жϺ͵�ǰ���Ƿ����
	//! \param 		pntAnchor	Ҫ�жϵĵ�
	//! \param 		dTolerance	�ж�����
	OgdcBool EQ(const OgdcPoint2D& pntAnchor, OgdcDouble dTolerance)const;
		
	//! \brief 		���� == 
	//! \return 	�����Ƿ����
	friend BASE_API OgdcBool operator==(const OgdcPoint2D& pntStart,const OgdcPoint2D& pntEnd);
	
	//! \brief 		���� !=		
	//! \return 	�����Ƿ����
	friend BASE_API OgdcBool operator!=(const OgdcPoint2D& pntStart,const OgdcPoint2D& pntEnd);			
		
	//! \brief 		���� = 	
	OgdcPoint2D& operator=(const OgdcSize2D& sz);
	
	//! \brief 		���� = 	
	OgdcPoint2D& operator=(const OgdcPoint2D& pnt2);
		
	//! \brief 		���� = 
	OgdcPoint2D& operator=(const OgdcPoint& pnt);
		
	//! \brief 		���� += 
	OgdcPoint2D& operator+=(const OgdcPoint2D& pnt);
		
	//! \brief 		���� += 
	OgdcPoint2D& operator+=(const OgdcSize2D& sz);
		
	//! \brief 		���� -= 
	OgdcPoint2D& operator-=(const OgdcPoint2D& pnt);
        
	//! \brief 		���� -= 
	OgdcPoint2D& operator-=(const OgdcSize2D& sz);	
		
	//! \brief 		���� - ���� 
	OgdcPoint2D operator-() const;		
		
    //! \brief 		���� + 
	friend BASE_API OgdcPoint2D operator+(const OgdcPoint2D& pntStart,const OgdcPoint2D& pntEnd);
		
	//! \brief 		���� + 
	friend BASE_API OgdcPoint2D operator+(const OgdcPoint2D& pntStart,const OgdcSize2D& pntEnd);
		
    //! \brief 		���� + 
	friend BASE_API OgdcPoint2D operator+(const OgdcSize2D& sz,const OgdcPoint2D& pnt);	
		
	//! \brief 		���� - 
	friend BASE_API OgdcPoint2D operator-(const OgdcPoint2D& pntStart,const OgdcPoint2D& pntEnd);
		
    //! \brief 		���� - 
	friend BASE_API OgdcPoint2D operator-(const OgdcPoint2D& pntStart,const OgdcSize2D& sz);
		
	//! \brief 		���� - 
	friend BASE_API OgdcPoint2D operator-(const OgdcSize2D& sz,const OgdcPoint2D& pnt);	
				
	//! \brief 		���� < 
	friend BASE_API OgdcBool operator<(const OgdcPoint2D& pntStart,const OgdcPoint2D& pntEnd);
		
};
	
typedef OgdcArray<OgdcPoint2D> OgdcPoint2Ds;
	
}


#endif // !defined(AFX_OGDCPOINT2D_H__8AEE7D11_E2F3_447D_AE4B_CC31AA76F2E0__INCLUDED_)

