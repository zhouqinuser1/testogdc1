//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcPoint3D.h
//!  \brief 3D����� 
//!  \details  
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCPOINT3D_H__4F7FE3AF_CB0E_4831_98B1_1512914807A3__INCLUDED_)
#define AFX_OGDCPOINT3D_H__4F7FE3AF_CB0E_4831_98B1_1512914807A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcSize3D.h"
#include "Base/OgdcPoint.h"
#include "Base/OgdcArray.h"

namespace OGDC {
//!  \brief ��ά����㣬OgdcDouble�ͣ�һ���������������������ά�㡣
class BASE_API OgdcPoint3D  
{
public:
    //! \brief ���x������
	OgdcDouble x;
	//! \brief ���y������
	OgdcDouble y;
	//! \brief ���z������
	OgdcDouble z;
public:
	//! \brief  	Ĭ�Ϲ��캯��
	OgdcPoint3D();
	//! \brief  	ȱʡ��������
	~OgdcPoint3D();

	//! \brief  ���������캯��
	OgdcPoint3D(OgdcDouble xx,OgdcDouble yy,OgdcDouble zz);	

public:	
	//! \brief 		���� = 
	OgdcPoint3D& operator=(const OgdcPoint3D& s);
	//! \brief 		���� += 
	OgdcPoint3D& operator+=(const OgdcPoint3D& p);
	//! \brief 		���� -= 
	OgdcPoint3D& operator-=(const OgdcPoint3D& p);
	//! \brief 		���� *= 
	OgdcPoint3D& operator*=(OgdcDouble c);
	//! \brief 		���� /= 
	OgdcPoint3D& operator/=(OgdcDouble c);
	//! \brief 		���� - ����
	OgdcPoint3D operator-() const;
	//! \brief 		���� == 
	friend BASE_API OgdcBool operator==(const OgdcPoint3D& p,const OgdcPoint3D& q);
	//! \brief 		���� !=
	friend BASE_API OgdcBool operator!=(const OgdcPoint3D& p,const OgdcPoint3D& q);			
		
};
	
typedef OgdcArray<OgdcPoint3D> OgdcPoint3Ds;
}

#endif // !defined(AFX_OGDCPOINT3D_H__4F7FE3AF_CB0E_4831_98B1_1512914807A3__INCLUDED_)

