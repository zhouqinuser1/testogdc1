//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file ogdcdefs.h
//!  \brief �ṩһЩ�������͵ĺ� 
//!  \details  
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCDEFS_H__EB930378_2B6A_4DDE_891C_41996E06B5EC__INCLUDED_)
#define AFX_OGDCDEFS_H__EB930378_2B6A_4DDE_891C_41996E06B5EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

#include <string>

#ifdef SYMBIAN60
#include <_map.h>
#include <_algo.h>
#else
#include <map>
#include <algorithm>
#endif 

#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <set>		//add by shuxl	10.7.1

#ifdef WIN32
	#pragma warning(disable: 4251)
	#pragma warning(disable: 4275)
	#pragma warning(disable: 4786)
#endif

#ifndef WIN32
// commited by zengzm 2007-3-30 ��link.h�������������Solaris�б��벻����
// ��Ϊ����ᶨ��_FILE_OFFSET_BITSΪ64����link.h��include��libelf.h��
// �ж�_FILE_OFFSET_BITS������32����_ILP32Ҳ�Ѿ������壬�ͻ�����������
// �������м��ĳ��ͷ�ļ��ж�����_ILP32����˰�link.h�ŵ���ǰ���У��Ա���˱������
// modified by yanbg 08.1.6 ���Ӷ�HP UNIXϵͳ���ж�
//#ifdef _AIX
#if !defined(OS_ANDROID) && !defined IOS
#if defined(_AIX) || defined(hpux)
	#include <dlfcn.h> // for dlopen() & dlsym()
#else 
	#include <link.h>  // for dlopen() & dlsym()
#endif
#endif               

// ͷ�ļ�����
// ����꣬ʹ�ÿ��Դ�����ļ���>4GB��
	#undef _FILE_OFFSET_BITS
	#define _FILE_OFFSET_BITS 64
	#include <unistd.h>
	#include <dirent.h>	
	#include <fcntl.h>
//modified by xielin ���ͷ�ļ�����Ҫ�ŵ�ǰ������������solaris��readdir�����Ĳ��ԣ�����Ը�ⲻ��
	#include <dirent.h> // for opendir(), readdir(), closedir() 
	#include <sys/types.h> // for lstat
	#include <sys/stat.h> // for lstat
	#include <sys/time.h>
	#include <assert.h>
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined IOS
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
	#include <X11/cursorfont.h>
#endif

#ifdef APPLE
	#include <mach/mach_init.h>
	#include <mach/semaphore.h>
	#include <mach/task.h>
	#include <pthread.h>
#else
	#include <pthread.h>
	#include <semaphore.h>
#endif

	#include <unistd.h> // for getwcd()
	#include <dlfcn.h> // for dlopen() & dlsym()
// commited by zengzm 2007-3-30 ��������ᵼ����Solaris�б��벻����
// ��Ϊ�Ѿ�������_FILE_OFFSET_BITSΪ64����link.h��include��libelf.h��
// �ж�_FILE_OFFSET_BITS������32����_ILP32Ҳ�Ѿ������壬�ͻ�����������
// �������м��ĳ��ͷ�ļ��ж�����_ILP32����˰�link.h�ŵ�ugnowin.h�У��Ա���˱������
// #include <link.h> // for dlopen() & dlsym()
#if !defined SYMBIAN60 && !defined OS_ANDROID && !defined IOS
	#include <X11/Xlib.h>
#endif 
	#include <cstring>
	#include <time.h>
	#include <fstream>
	#include "Base/prefix.h"
#endif

#include "Base/ogdcexports.h"
#include "Base/ogdccolordef.h"

// Truth values
#ifndef TRUE
	#define TRUE 1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

#ifndef NULL
	#define NULL 0
#endif


#ifdef _UGUNICODE
#define _U(x)  L ## x
#else
#define _U(x)	x
#endif
#define OGDC_DLL_VERSION		_U("600")		//! \brief  dll�汾��6.0.0
		      
//! \brief  ��Сֵ����
#define EP 1e-10
#define NEP -1e-10
//!  ����������͵ļ�ֵ caogf
#define OGDC_DBLMAX 1.7976931348623158e+308 /* max value */
#define OGDC_DBLMIN 2.2250738585072014e-308 /* min positive value */
#define OGDC_FLTMAX 3.402823466e+38F  /* max value */
#define OGDC_FLTMIN 1.175494351e-38F  /* min positive value */

// For Windows
#if defined(_DEBUG)
#if !defined(DEBUG)
	#define DEBUG
#endif
#endif

#ifdef _NDEBUG
	#ifndef NDEBUG
	#define NDEBUG
#endif
#endif

#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : "

#if (_MSC_VER >= 800)
    #define CALLBACK    __stdcall
#else
    #define CALLBACK
#endif

//!  1200, VC6
//! 1310 for Microsoft Visual C++ .NET 2003. 1310 represents version 13 and a 1.0 point release. 
//! The Visual C++ 2005 compiler version is 1400.
#ifdef WIN32
#if (_MSC_VER<=1400)
	#ifndef vsnprintf
		#define vsnprintf _vsnprintf
	#endif
#endif
#endif

#define OGDCCALLBACK CALLBACK

#ifdef WIN32
#define OGDCSTDCALL __stdcall
#else
#define OGDCSTDCALL
#endif

//! \brief ��Ϊ��ͬƽ̨SYSTEM_WCHAR_SIZE ��ͬ��ͨ������ȷ�ϣ�
//Ĭ�Ͽ��Ϊ 2
#if !defined(SYSTEM_WCHAR_SIZE)
#define SYSTEM_WCHAR_SIZE 2
#endif


#ifdef WIN32
#define ISPATHSEP(c) ((c)==_U('/') || (c)==_U('\\'))
#else
#define ISPATHSEP(c) ((c)==_U('/'))
#endif

namespace OGDC {

//! \brief Streamable types; these are fixed size!
typedef unsigned char          OgdcUchar;
typedef OgdcUchar			   OgdcByte;
typedef OgdcUchar			   OgdcBool;
typedef unsigned short         OgdcUshort;
typedef short                  OgdcShort;
typedef unsigned int           OgdcUint;
//#if SYSTEM_WCHAR_SIZE==4
//typedef unsigned int           OgdcWchar;
//#else
//typedef wchar_t                OgdcWchar;
//#endif
typedef wchar_t		       OgdcWchar;
typedef char				   OgdcAchar;
typedef unsigned int		   OgdcWchar32;
typedef int                    OgdcInt;
typedef float                  OgdcFloat;
typedef double                 OgdcDouble;

#ifdef _UGUNICODE
typedef OgdcWchar OgdcChar;
#else
typedef OgdcAchar OgdcChar;
#endif

#if defined(_MSC_VER) || (defined(__BCPLUSPLUS__) && __BORLANDC__ > 0x500) || defined(__WATCOM_INT64__)
	typedef unsigned __int64       OgdcUlong;
	typedef __int64                OgdcLong;	

#elif defined(__GNUG__) || defined(__GNUC__) || defined(__SUNPRO_CC) || defined(__MWERKS__) || defined(__SC__) || defined(__xlC__)

	typedef unsigned long long int OgdcUlong;
	typedef long long int          OgdcLong;
	
#endif

typedef OgdcUint                 OgdcColor;
typedef size_t                   OgdcSizeT;


#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C    extern "C"
#else
#define EXTERN_C    extern
#endif
#endif

#ifndef __FILEW__
#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define __FILEW__ WIDEN(__FILE__)
#endif

//! \brief ��������뵥λ���� - ��׼��ʽ
//! \brief ����
#define AU_MILIMETER	10
//! \brief ����			
#define AU_CENTIMETER	100
//! \brief ����			
#define AU_DECIMETER	1000
//! \brief ��		
#define AU_METER		10000
//! \brief ����		
#define AU_KILOMETER	10000000
//! \brief Ӣ��	
#define AU_MILE			16090000
//! \brief Ӣ��??	
#define AU_INCH			254	
//! \brief Yard��		
#define AU_YARD			9144
//! \brief FeetӢ��		 
#define AU_FOOT			3048
//! \brief Yard��		
#define	AU_YARD_SEARS   9144		 

//! \remarks �Ƕȵ�λ�� (10e8)��֮һ����Ϊ ��λ1Ϊ����ͳ��ȵ�λ������������10e10
//   ����ڼ���ʱ��Ӧ��ȥ10e10��Ȼ���ټ���
#define AU_DIFF              1000000000
#define AU_RADIAN            (100000000 + 1000000000)	//  Radian                                 
#define AU_DEGREE			 (1745329   + 1000000000)	//  Degree                                 
#define AU_MINUTE            (29089     + 1000000000)	//  Arc-minute                             
#define AU_SECOND            (485       + 1000000000)	//  Arc-second                             
#define AU_GRAD              (1570796   + 1000000000)	//  Grad (angle subtended by 1/400 circle) 
#define AU_MICRORADIAN       (100       + 1000000000)	//  Microradian ( 1e-6 radian )            
#define AU_MINUTE_CENTESIMAL (15708     + 1000000000)	//  Centesimal minute (1/100th Gon (Grad)) 
#define AU_SECOND_CENTESIMAL (157       + 1000000000)	//  Centesimal second(1/10000th Gon (Grad))
#define AU_MIL_6400          (98175     + 1000000000)	//  Mil (angle subtended by 1/6400 circle) 


//! \brief Abolute value
#define OGDCABS(val) (((val)>=0)?(val):-(val))

//�Ƿ�Ϊ��ֵ
#define OGDCEXTREFLT(x) (OGDCABS(OGDCABS(x)-OGDC_FLTMAX)<=0.000000001e+38F)
#define OGDCEXTREDBL(x) (OGDCABS(OGDCABS(x)-OGDC_DBLMAX)<=0.0000000000000001e+308)

//! \brief Return the maximum of a or b
#define OGDCMAX(a,b) (((a)>(b))?(a):(b))

//! \brief Return the minimum of a or b
#define OGDCMIN(a,b) (((a)>(b))?(b):(a))


//! \brief Swap a pair of numbers
#define OGDCSWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

//! \brief Clamp value x to range [lo..hi]
#define OGDCCLAMP(lo,x,hi) ((x)<(lo)?(lo):((x)>(hi)?(hi):(x)))

#define OGDCROUND(x) (((x)>0)?OgdcInt((x)+0.5):(OgdcInt((x)-0.5)))
//OGDCQuickRound�ٶȿ쵫�Ǿ��ȷ�Χ���ܴ��ڶ�1������,������ɫʱ�������������ΪOGDCROUND2
//��Ҫʹ�ÿ��������
#define OGDCROUND2(x) OGDC::OGDCQuickRound(x)

//! \brief �������Ƿ���ȵ��ж�
#define OGDCEQUAL(x,y) OGDC::ogdcequal(x,y)
#define OGDCEQ(x,y,d) OGDC::ogdcequal(x,y,d)

//! \brief һ�����Ƿ�Ϊ0 (����0�����ļ�С��) ���ж�
//! \brief ��Ҫ��ʾ: �������Ƿ���ȵıȽ� ����ʹ�� OgdcIS0(a-b) , ��Ӧ��ֱ��ʹ��OgdcEQUAL(a,b)
#define  OGDCIS0(x)	(((x)<EP) && ((x)>NEP))

#ifdef OS_ANDROID
#include <Android/log.h>
#define ANDROID_PRINT(TAG,...) __android_log_print(ANDROID_LOG_DEBUG, TAG,__VA_ARGS__)
#endif

#ifndef NDEBUG
#ifdef IOS
    #define OGDCASSERT(exp) ((exp)?((void)0):(void)ogdcassert(#exp,__FILE__,__LINE__))
#else
	#define OGDCASSERT(exp) ((exp)?((void)0):(void)OGDC::ogdcassert(#exp,__FILE__,__LINE__))
#endif
#else
	#define OGDCASSERT(exp) ((void)0)
#endif

#define OGDCIsLeadByte(ch) (ch & 0x80)

extern BASE_API void ogdcassert(const char* pExpression,const char* pFilename,unsigned int nLineno);

extern BASE_API OgdcBool ogdcequal(OgdcDouble dX, OgdcDouble dY);

extern BASE_API OgdcBool ogdcequal(OgdcDouble dX, OgdcDouble dY, OgdcDouble dTolerance);

//! \brief ��ɫ���
extern BASE_API OgdcColor OGDCRGB(OgdcByte chR,OgdcByte chG,OgdcByte chB);

extern BASE_API OgdcColor OGDCRGBA(OgdcUchar r,OgdcUchar g,OgdcUchar b,OgdcUchar a);

extern BASE_API OgdcUchar OGDCREDVAL(OgdcColor clr);

extern BASE_API OgdcUchar OGDCGREENVAL(OgdcColor clr);

extern BASE_API OgdcUchar OGDCBLUEVAL(OgdcColor clr);

extern BASE_API OgdcUchar OGDCALPHAVAL(OgdcColor clr);

extern BASE_API OgdcInt OGDCQuickRound(OgdcDouble dX);

static union
{
	int nTest;
	char cTest[sizeof(int)];
}un_bigendina = {1};
#define  OGDC_ISBIGENDIAN (un_bigendina.cTest[0] != 1)

}

#endif // !defined(AFX_OGDCDEFS_H__EB930378_2B6A_4DDE_891C_41996E06B5EC__INCLUDED_)

