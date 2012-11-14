//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcTime.h
//!  \brief ʱ���࣬ʱ������
//!  \details   
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCTIME_H__F8775450_4889_4D7E_A042_7E61AF93876D__INCLUDED_)
#define AFX_OGDCTIME_H__F8775450_4889_4D7E_A042_7E61AF93876D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifdef WIN32
/* This needs to come before any includes for MSVC compiler */
#define _CRT_SECURE_NO_WARNINGS
//#include <Windows.h>
#endif


#include "OgdcString.h"

namespace OGDC {

//! \brief ʱ������
class BASE_API OgdcTimeSpan 
{
public:
	
	//! \brief Ĭ�Ϲ��캯��,ʱ����Ϊ0
	OgdcTimeSpan();
	//! \brief ָ��ʱ�������й���
	OgdcTimeSpan(OgdcInt nDays, OgdcInt nHours, OgdcInt nMins, OgdcInt nSecs);
	//! \brief ָ��doubleʱ����й���
	OgdcTimeSpan(double dTime);
	
	//! \brief �������캯��
	OgdcTimeSpan(const OgdcTimeSpan& tmsSrc);
	//! \brief ������ֵ����
	const OgdcTimeSpan& operator=(const OgdcTimeSpan& tmsSrc);
	
	//! \brief ��ȡ��
	OgdcInt GetDays() const;
	//! \brief ��ȡСʱ,��ת��Ϊ24Сʱ
	OgdcInt GetTotalHours() const;
	//! \brief ��ȡСʱ,�ղ���������
	OgdcInt GetHours() const;
	//! \brief ��ȡ����,�պ�ʱ��ת��Ϊ��
	OgdcInt GetTotalMinutes() const;
	//! \brief ��ȡ����,�պ�ʱ����������
	OgdcInt GetMinutes() const;
	//! \brief ��ȡ��,��ʱ�ֶ�ת��Ϊ��
	OgdcInt GetTotalSeconds() const;
	//! \brief ��ȡ��,��ʱ�ֲ���������
	OgdcInt GetSeconds() const;
	

	//! \brief ���ز����� -
	OgdcTimeSpan operator-(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� +
	OgdcTimeSpan operator+(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� +=
	const OgdcTimeSpan& operator+=(const OgdcTimeSpan &tms);
	//! \brief ���ز����� -=
	const OgdcTimeSpan& operator-=(const OgdcTimeSpan &tms);
	//! \brief ���ز����� ==
	OgdcBool operator==(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� !=
	OgdcBool operator!=(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� <
	OgdcBool operator<(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� >
	OgdcBool operator>(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� <=
	OgdcBool operator<=(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� >=
	OgdcBool operator>=(const OgdcTimeSpan &tms) const;
		
private:
	//! \brief ʱ������������
	double m_timeSpan; 
	//! \brief ʱ����
	friend class OgdcTime;
};

//! \brief ʱ����
// ����COleDateTimeʵ��
// implemented as a floating-point value, measuring days from midnight, 
// 30 December 1899. So, midnight, 31 December 1899 is represented by 1.0. 
// Similarly, 6 AM, 1 January 1900 is represented by 2.25, 
// and midnight, 29 December 1899 is �C 1.0. 
// However, 6 AM, 29 December 1899 is �C 1.25.
// Now, OgdcTime can handle dates from 1 January 100 �C 31 December 9999
class BASE_API OgdcTime  
{
public:
	

	//! \brief ��ȡ�Ժ���Ϊ������ʱ��; ������ȷ�������ܵ�; 
	static OgdcUint GetMillisecond();
	
	//! \brief Ĭ�Ϲ��캯��
	OgdcTime();

	//! \brief �������캯��
	OgdcTime(const OgdcTime& tmSrc);

	//! \brief �������캯��
	OgdcTime(time_t t);

	//! \brief �������캯��
	OgdcTime(double dValue);
	
	//! \brief �����չ��캯��
	OgdcTime(OgdcInt nYear,OgdcInt nMonth,OgdcInt nDay);
	
	//! \brief ������ʱ���빹�캯��
	OgdcTime(OgdcInt nYear, OgdcInt nMonth, OgdcInt nDay, OgdcInt nHour, OgdcInt nMin, OgdcInt nSec);
	//! \brief ���ز�����=
	const OgdcTime& operator=(const OgdcTime& tmSrc);
	//! \brief ���ز�����=
	const OgdcTime& operator=(time_t t);

//	struct tm* GetGmtTm(struct tm* ptm = NULL) const;
//	struct tm* GetLocalTm(struct tm* ptm = NULL) const;

	//! \brief ��ȡʱ��
	double GetTime() const;

	//! \brief ��ȡ��(��Ԫ)��
	OgdcInt GetYear() const;	
	//! \brief ��ȡһ��������(1~12)
	//! \remarks 1��=1,2��=2,...,12��=12.
	OgdcInt GetMonth() const;
	//! \brief ��ȡÿ���е�����(1~31)
	//! \remarks 1��=1,2��=2,...,31��=31.
	OgdcInt GetDay() const;         
	//! \brief ��ȡһ���е�Сʱ��(0~23)
	//! \remarks 0��=0��1��=1��...23��=23.
	OgdcInt GetHour() const;
	//! \brief ��ȡһСʱ�ڵķ�����(0~59)
	OgdcInt GetMinute() const;
	//! \brief ��ȡһ�����е�����(��0~59)
	OgdcInt GetSecond() const;
	//! \brief ��ȡһ�����ڵ�����
	//! \remarks ����=1,��һ=2���ܶ�=3������=4������=5������=6������=7
	OgdcInt GetDayOfWeek() const; 
	//! \brief ��ȡÿ�������(1~366)
	//! \remarks 1��1��Ϊ1,1��2��Ϊ2,...,12��31��Ϊ365��366
	OgdcInt GetDayOfYear() const;   
	//! \brief ���ز����� -
	OgdcTimeSpan operator-(const OgdcTime &tmTime) const;
	//! \brief ���ز����� -
	OgdcTime operator-(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� +
	OgdcTime operator+(const OgdcTimeSpan &tms) const;
	//! \brief ���ز����� +=
	const OgdcTime& operator+=(const OgdcTimeSpan &tms);
	//! \brief ���ز�����-=
	const OgdcTime& operator-=(const OgdcTimeSpan &tms);
	//! \brief ���ز����� ==
	OgdcBool operator==(const OgdcTime &tmTime) const;
	//! \brief ���ز����� !=
	OgdcBool operator!=(const OgdcTime &tmTime) const;
	//! \brief ���ز����� <
	OgdcBool operator< (const OgdcTime &tmTime) const;
	//! \brief ���ز����� >
	OgdcBool operator> (const OgdcTime &tmTime) const;
	//! \brief ���ز����� <=
	OgdcBool operator<=(const OgdcTime &tmTime) const;
	//! \brief ���ز����� >=
	OgdcBool operator>=(const OgdcTime &tmTime) const;

	//! \brief ����һ����ʽ���ַ���,��OgdcTime����Ϣ����һ�������Ķ����ַ���
	//! \remarks 
	//! %d Day of month as decimal number (01 �C 31);
	//! %H Hour in 24-hour format (00 �C 23);
	//! %m Month as decimal number (01 �C 12)
	//! %M Minute as decimal number (00 �C 59)
	//! %S Second as decimal number (00 �C 59)
	//! %y Year without century, as decimal number (00 �C 99)
	//! %Y Year with century, as decimal number
	OgdcString Format(const OgdcChar *pFormat) const;

	// deleted by zengzm 2007-4-12 ToString��ǰ����ctimeʵ��, ����OgdcTime֧�ָ��㷺ʱ��,�Ͳ�����ToString��.
	// ������Format("%Y-%m-%d %X")����
	// ��ͬ�� ctime(), MSDN�ϵ�˵������, ��:Fri Apr 29 12:25:12 1994
	// Convert a time value to a string and adjust for local time zone settings.
	// OgdcString ToString() const;

	//! \brief ����ָ����ʽ�������ں�ʱ��
	//! \param strDateTime ���ں�ʱ��ֵ
	//! \param strFormat ���ں�ʱ��ĸ�ʽ
	//! \remarks ����: strFormatΪ"%Y-%m-%d %H:%M:%S", strDateTimeΪ"1487-05-29 14:25:59", 
	//! ����ȡ��OgdcTimeΪ: 1487��05��29�� 14ʱ25��59��
	//! \attention OgdcTime��ParseDateTimeԶû��MFC��COleDateTime��ParseDateTimeǿ��, 
	//! COleDateTime��ParseDateTime�е�����Win32 API VarDateFromStr,���ڲ�ʵ�ֿ�����,
	//! ʵ����, OgdcC��Ҳ������ôǿ��. ���,���ϸ������������е��÷�, ����ע������0ҲҪд��
	OgdcBool ParseDateTime(OgdcString strDateTime,OgdcString strFormat);
	
	//! \brief ��ȡ��ǰʱ��
	static OgdcTime GetCurTime();

	//!\brief �����뵱��ʱ�����һ��ʱ��ĵط�ʱ
	//!\param t ����ʱ��
    //!\param bias,�����ʱ��t��ƫ���λ�Ƿ���
	//!\param return�����µĵط�ʱ
	static OgdcTime ConvertToRegionalTime(OgdcTime t, OgdcInt bias);
public: 
	//! \brief ��������ʱ����ת��Ϊ�ڲ���double��ֵ
	//! \param nYear ��
	//! \param nMonth ��
	//! \param nDay ��
	//! \param nHour Сʱ
	//! \param nMin ����
	//! \param nSec ��
	void SetDateTime(OgdcInt nYear, OgdcInt nMonth, OgdcInt nDay, OgdcInt nHour, OgdcInt nMin, OgdcInt nSec);
	//! \brief ��double��ֵת��Ϊtm�ṹ
	void GetDateTime(struct tm& tmDest) const;
private:
	//! \brief ��ȡ��׼��tm�ṹ
	void GetStandardTm(struct tm& tmDest) const;

	//! \brief ��ȡ������doubleֵ
	//! \remarks ��ͬ��MFC�е�_AfxDoubleFromDate
	OgdcDouble GetDoubleValue() const;
	//! \brief �Ӵ�����doubleֵ�еõ�ʱ��
	//! \remarks ��ͬ��MFC�е�_AfxDateFromDouble
	void FromDoubleValue(OgdcDouble dValue);
	//! \brief �ӵ�ǰλ�ü����һ������Number�ĳ���
	OgdcInt GetNumberPos(const OgdcString& strDateTime , OgdcInt nCurrentPos);

	//time_t m_time;
	double m_time;
};

}


#endif // !defined(AFX_OGDCTIME_H__F8775450_4889_4D7E_A042_7E61AF93876D__INCLUDED_)

