//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcSize3D.h
//!  \brief 3D��С�� 
//!  \details   
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCSIZE3D_H__75C436AA_5720_4F3A_85BF_67F31C43FB28__INCLUDED_)
#define AFX_OGDCSIZE3D_H__75C436AA_5720_4F3A_85BF_67F31C43FB28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"

namespace OGDC {
//!  \brief �������С�࣬�洢�˳�����ĳ���cx�����cy�͸߶�cz��ΪOgdcDouble�͡�
class BASE_API OgdcSize3D  
{
public:
	//! \brief 		����
	OgdcDouble cx;
	//! \brief 		���
	OgdcDouble cy;
	//! \brief 		�߶�
	OgdcDouble cz;
public:
	
	//! \brief 		ȱʡ���캯��
	OgdcSize3D();
	
	//! \brief 		ȱʡ���캯��
	~OgdcSize3D();
	
	//! \brief 		���ι��캯��
	//! \param 		cx		����
	//! \param 		cy		���
	//! \param 		cz		�߶�
	OgdcSize3D(OgdcDouble dX,OgdcDouble dY,OgdcDouble dZ);
	
	//! \brief 		����==
	friend BASE_API OgdcBool operator==(const OgdcSize3D& szSrc,const OgdcSize3D& sztag);
	
	//! \brief 		����!=
	friend BASE_API OgdcBool operator!=(const OgdcSize3D& szSrc,const OgdcSize3D& szTag);	
	
	//! \brief 		���� +=
	OgdcSize3D& operator+=(const OgdcSize3D& sz);
	
	//! \brief 		���� -=
	OgdcSize3D& operator-=(const OgdcSize3D& sz);	
	
	//! \brief 		���� -
	OgdcSize3D operator-();	
	
	//! \brief 		���� +
	friend BASE_API OgdcSize3D operator+(const OgdcSize3D& szSrc,const OgdcSize3D& szTag);
	
	//! \brief 		���� -
	friend BASE_API OgdcSize3D operator-(const OgdcSize3D& szSrc,const OgdcSize3D& szTag);	
};

}

#endif // !defined(AFX_OGDCSIZE3D_H__75C436AA_5720_4F3A_85BF_67F31C43FB28__INCLUDED_)

