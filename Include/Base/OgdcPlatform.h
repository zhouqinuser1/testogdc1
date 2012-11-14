/* 
\file ogdcplatform.h
\brief ��ϵͳ�������õķ�գ�����Unicode�汾�ͷ�Unicode�汾 
\author 
\attention
Copyright(c) 2000-2010 SuperMap Software Co., Ltd.<br>
All Rights Reserved
<b>����˵������</b>
<em>1����һ��˵����</em>
<em>2���ڶ���˵����</em>
*/

#ifndef _OGDCSYSTEMCALLS_H
#define _OGDCSYSTEMCALLS_H

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif
#include "Base/ogdcdefs.h"

#ifdef _UGUNICODE
#include "unicode/ustring.h"
#endif

#ifdef _UGUNICODE
#define OGDCstrcpy	u_strcpy
#define OGDCstrlen(x)	u_strlen((const UChar*)(x))
#define OGDCstrcat	u_strcat 
#define OGDCstrcmp	u_strcmp
//#define OGDCstrftime	wcsftime
#else
#define OGDCstrcpy	strcpy
#define OGDCstrlen	strlen
#define OGDCstrcat	strcat 
#define OGDCstrcmp	strcmp
//#define OGDCstrftime	strftime
#endif

using namespace OGDC;
#ifdef _UGUNICODE
extern size_t BASE_API OGDC_vsnprintf(OgdcWchar *buf, size_t size, const OgdcWchar *fmt, va_list args);
#endif
extern BASE_API size_t OGDCstrftime(OgdcChar* szBuffer, size_t maxsize, const OgdcChar* Format, const struct tm *timeptr);

#ifndef WIN32
#define _MAX_PATH 260
#endif

#endif	//_OGDCSYSTEMCALLS_H

