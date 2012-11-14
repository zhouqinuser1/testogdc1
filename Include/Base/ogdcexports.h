//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file ogdcexport.h
//!  \brief OGDC ��ÿ����������ӵ��뵼������
//!  \details Ϊÿ��������ӵ��뵼����,�Ѿ�����ĸ�����У��������밴��ĸ�����С�
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////
#ifndef SYMBIAN60

#ifndef OGDCEXPORT_H
#define OGDCEXPORT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
	#define OGDCEXPORT __declspec(dllexport)
	#define OGDCIMPORT __declspec(dllimport)
#else
#ifdef SYMBIAN60
	#define OGDCEXPORT __declspec(dllexport)
	#define OGDCIMPORT __declspec(dllimport)
#else
	#define OGDCEXPORT
	#define OGDCIMPORT
#endif
#endif

#ifdef BASE_EXPORTS
	#define BASE_API OGDCEXPORT
#else
	#define BASE_API OGDCIMPORT
#endif

#ifdef ELEMENT_EXPORTS
	#define ELEMENT_API OGDCEXPORT
#else
	#define ELEMENT_API OGDCIMPORT
#endif

#ifdef OGDC_EXPORTS
	#define OGDC_API OGDCEXPORT
#else
	#define OGDC_API OGDCIMPORT
#endif


#endif // !defined(OGDCEXPORT_H)

#define  ELEMENT_APIF

#else // ifndef SYMBIAN60
#include "Base/ugexports_symbian.h"
#endif // ifndef SYMBIAN60


