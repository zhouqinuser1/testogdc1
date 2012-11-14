//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcSize.h
//!  \brief ��ά���δ�С�ࡣ����洢�˾��εĳ���cx�Ϳ��cy������ΪOgdcInt�͡�
//!  \details   
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCSIZE_H__ED613AC5_ED5E_4B31_846E_3768AF9C4BA6__INCLUDED_)
#define AFX_OGDCSIZE_H__ED613AC5_ED5E_4B31_846E_3768AF9C4BA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"

namespace OGDC {
//!  \brief ���δ�С�࣬�洢�˾��εĳ���cx�Ϳ��cy��ΪOgdcInt�͡�
class BASE_API OgdcSize  
{
public:
	//! \brief 		����
	OgdcInt cx;
	//! \brief 		���
	OgdcInt cy;
public:
	
	//! \brief 		ȱʡ���캯��
	OgdcSize();	

	//! \brief 		ȱʡ��������
	~OgdcSize();	
	
	//! \brief 		���ι��캯��
	//! \param 		nX		����
	//! \param 		nY		���
	OgdcSize(OgdcInt nX,OgdcInt nY);
	
	//! \brief 		����==
	friend BASE_API OgdcBool operator==(const OgdcSize& szSrc,const OgdcSize& szTag);
	
	//! \brief 		����!=
	friend BASE_API OgdcBool operator!=(const OgdcSize& szSrc,const OgdcSize& szTag);	
	
	//! \brief 		���� +=
	OgdcSize& operator+=(const OgdcSize& sz);
	
	//! \brief 		���� -=
	OgdcSize& operator-=(const OgdcSize& sz);	
	
	//! \brief 		���� -
	OgdcSize operator-() const;	
	
	//! \brief 		���� +
	friend BASE_API OgdcSize operator+(const OgdcSize& szSrc,const OgdcSize& szTab);
	
	//! \brief 		���� -
	friend BASE_API OgdcSize operator-(const OgdcSize& szSrc,const OgdcSize& szTab);
	
};
	
}

#endif // !defined(AFX_OGDCSIZE_H__ED613AC5_ED5E_4B31_846E_3768AF9C4BA6__INCLUDED_)

