//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcSize2D.h
//!  \brief ��ά���δ�С�ࡣ����洢�˾��εĳ���cx�Ϳ��cy������ΪOgdcDouble�͡�
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCSIZE2D_H__C6D5EB89_6542_4FE3_9B39_C2B292F51D6D__INCLUDED_)
#define AFX_OGDCSIZE2D_H__C6D5EB89_6542_4FE3_9B39_C2B292F51D6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"

namespace OGDC {
//!  \brief ��ά���δ�С�ࡣ����洢�˾��εĳ���cx�Ϳ��cy������ΪOgdcDouble�͡�
class BASE_API OgdcSize2D  
{
public:
	//! \brief 		����
	OgdcDouble cx;
	//! \brief 		���
	OgdcDouble cy;
public:
	
	//! \brief 		ȱʡ���캯��
	OgdcSize2D();
	
	//! \brief 		ȱʡ���캯��
	~OgdcSize2D();
	
	//! \brief 		���ι��캯��
	//! \param 		cx		����
	//! \param 		cy		���
	OgdcSize2D(OgdcDouble dX,OgdcDouble dY);
	
	//! \brief 		����==
	friend BASE_API OgdcBool operator==(const OgdcSize2D& szSrc,const OgdcSize2D& sztag);
	
	//! \brief 		����!=
	friend BASE_API OgdcBool operator!=(const OgdcSize2D& szSrc,const OgdcSize2D& szTag);	
	
	//! \brief 		���� +=
	OgdcSize2D& operator+=(const OgdcSize2D& sz);
	
	//! \brief 		���� -=
	OgdcSize2D& operator-=(const OgdcSize2D& sz);	
		
	//! \brief 		���� -
	OgdcSize2D operator-() const;	
	
	//! \brief 		���� +
	friend BASE_API OgdcSize2D operator+(const OgdcSize2D& szSrc,const OgdcSize2D& szTag);
	
	//! \brief 		���� -
	friend BASE_API OgdcSize2D operator-(const OgdcSize2D& szSrc,const OgdcSize2D& szTag);	
};

}

#endif // !defined(AFX_OGDCSIZE2D_H__C6D5EB89_6542_4FE3_9B39_C2B292F51D6D__INCLUDED_)

