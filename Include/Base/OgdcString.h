//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcString.h
//!  \brief �ַ�����  
//!  \details
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCSTRING_H__2CA5E3F6_86E2_4EA7_A56F_CE716B8B1E05__INCLUDED_)
#define AFX_OGDCSTRING_H__2CA5E3F6_86E2_4EA7_A56F_CE716B8B1E05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(_WIN32) || defined(WIN32)
/* This needs to come before any includes for MSVC compiler */
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <string>
#include "OgdcArray.h"

#ifdef _UGUNICODE
namespace icu_3_8
{
	class UnicodeString;
	class NumberFormat;
}
using namespace icu_3_8;
#endif

namespace OGDC {

class OgdcMBString;
class OgdcUnicodeString;

//! \brief OGDCPCTSTRΪ�˲���΢���LPCTSTR��ͻ����Ϊָ�������4λ����8λ��ȥ��L������OGDCǰ׺��
typedef const OgdcAchar* OGDCPCTSTR; 
typedef const OgdcWchar* OGDCPCWSTR;

typedef OgdcArray<OgdcUnicodeString> OgdcUnicodeStringArray; 
typedef OgdcArray<OgdcMBString> OgdcMBStringArray;

//! \brief �ַ����ַ�����
struct  OGDCCharset
{
public:
	enum Charset
	{   
		//! \brief ANSI����
		ANSI = 0,
		//! \brief Default����
		Default = 1,
		//! \brief Symbol����
		Symbol = 2,
		//! \brief MAC����
		MAC = 77,
		
		//! \brief ISO-2022-JP-2���룬���������ı���ת����ʱ����ISO2022JP2����
		//�������ı���ת����ʱ���� '\'��ShiftJISת���������⣬��ISO2022JP2��û��ʲô���⣬
		//�����������ı���ת����ʱ�����������
		ISO2022JP2 = 127,
		//! \brief ShiftJIS����
		ShiftJIS = 128,

		//! \brief Hangeul����
		Hangeul = 129,
		//! \brief Johab����
		Johab	= 130,
		
		//! \brief GB18030�������µĹ��ұ�׼,��������GB2312��GBK�Ⱥܶ�����, ���,����ͳһ��GB18030�������й�(��½)���ַ���
		GB18030 = 134, 
		//GB2312 ������ĵļ��������ַ���, ��GBK����GB2312�������չ,�����˺ܶ����ĺͷ�������
		//GB2312 = 134, 
		//! \brief Big5��̨�弸��5��������˾������ķ����ַ���, ���ڵ�ʱ���й�(��½)û�й�ͨ��Э��, ����Big5��GB�ǲ����ݵ�,
		//! ������¼�������нϴ���, �ұ����в����ص�, ��˼����ϵͳ���޷��Զ�ʶ�� ĳ�������� GB ���� Big5��.
		//! ��ۺͰ������ڷ����֣����Ҳ����Big5��ͬʱ��������������Ӱ��ϴ�, ��˺ܶ���������Ҳ����Ҫ��Big5����ʹ�ã�
		//! ��������Big5�����������չ, �����е�Ϊ BIG5-HKSCS:2001. ������ǲ���|BIG5-HKSCS:2001".
		ChineseBIG5 = 136, 
		//! \brief Greek����
		Greek = 161,
		//! \brief Turkish����
		Turkish = 162,
		//! \brief Vietnamese����
		Vietnamese = 163,
		//! \brief Hebrew����
		Hebrew = 177,
		//! \brief Arabic����
		Arabic = 178,
		//! \brief Baltic����
		Baltic = 186,
		//! \brief Russian����
		Russian = 204,
		//! \brief Thai����
		Thai = 222,
		//! \brief EastEurope����
		EastEurope = 238,
		//! \brief ���ϸ�������˵, UTF8,UCS2,UCS4�ȶ������ַ���,��ֻ��Unicode��һ�ֱ��뷽ʽ, 
		//! �������⼸��ʹ�ý�ΪƵ��, �Ҽ�����Ĵ����Ϻ������ַ����Ƚ�����, ���,��ͳһ����������.
		UTF8 = 250,
		//! \brief WindowsĬ�ϵ�Unicode����	����Ĭ���ǰ���UTF16LE�����
		UCS2LE = 251,
		//! \brief UCS2BE���� ����Ĭ���ǰ���UTF16BE�����
		UCS2BE = 252,
		//! \brief UCS4LE���� ����Ĭ���ǰ���UTF32LE�����
		UCS4LE = 253,
		//! \brief UCS4BE���� ����Ĭ���ǰ���UTF32BE�����
		UCS4BE = 254,
		//! \brief Unicode���� �������������Ҫ���ͷ����������ʷԭ����iconv��Ĭ�ϴ�˻�����UCS2BE С�˻�����UCS2LE
		Unicode = 132,
		//! \brief OEM����
		OEM = 255,
		//�����ΪWindowsϵͳ�ַ�����
		//! \brief Windows1252����
		Windows1252 = 137,
		//! \brief Korean����
		Korean = 131,
		//! \brief Cyrillic����
		Cyrillic = 135,
        //! \brief xIA5����
		xIA5 = 3,
		//! \brief xIA5German����
		xIA5German = 4,
		//! \brief xIA5Swedish����
		xIA5Swedish = 5,
		//! \brief xIA5Norwegian����
		xIA5Norwegian = 6,
		//! \brief UTF7����
		UTF7 = 7
		//! \brief UTF32����
// 		UTF32 = 8,
// 		//! \brief UTF32BE����
// 		UTF32BE = 9,
// 		//! \brief UTF32LE����
// 		UTF32LE = 10,
// 		//! \brief UTF16����
// 		UTF16BE = 11,
// 		UTF16LE = 12
//		UnicodeBE = 133,
	};                                                                                                                                                                      
};
//! \brief �ַ�����
//! \attention OgdcMBString��֧�ֶ��ֽڱ�����ַ�����
class BASE_API OgdcMBString : public OGDCCharset 
{

public:
	
	//! \brief Ĭ�Ϲ��캯����
	OgdcMBString();
	
	//! \brief �������캯����
	//! \param str �����������ַ���(OgdcMBString����)
	OgdcMBString(const OgdcMBString& str);	

	//! \brief �������캯��
	//! \param str �����������ַ���(std::string����)
	//! \remarks ��Ҫ���ں�Markup�Ƚ���ƥ��
	OgdcMBString(const std::string& str);	
	
	//! \brief �������캯����	
	//! \param pstr �����������ַ���(OgdcAchar*����)
	OgdcMBString(const OgdcAchar* pStr);
	
	//! \brief �������캯����
	//! \param pstr �����������ַ���(OgdcAchar*����)
	//! \param nSize ָ��ʹ�õ��ֽڳ���
	OgdcMBString(const OgdcAchar* pStr, OgdcInt nSize);
	
	//! \brief �������캯������ch�ظ�����nRepeat�Ρ�
	//! \param ch �����������ַ���(OgdcAchar����)
	//! \param nRepeat �ظ���������,Ĭ��Ϊ1
	//! \remarks explicit���ڷ�ֹ���ε�ת��
	//! \include Ogdcstring.cpp
	explicit OgdcMBString(OgdcAchar ch, OgdcInt nRepeat=1);
	
	//! \brief ׷���ַ���
	//! \param pch Ҫ׷�ӵ��ַ���
	//! \param nSize Ҫ׷�ӵ��ֽڸ���
	void Append(const OgdcAchar* pStr, OgdcInt nSize);

	//! \brief ��OgdcMBStringת��Ϊconst char*��
	operator OGDCPCTSTR() const;

	//! \brief ��OgdcMBStringת����std::string
	operator std::string() const;

	//! \brief ��ȡC�ַ���
	const OgdcAchar * Cstr() const;

	//! \brief ��ȡָ���������ַ���
	//! \param nIndex ָ��������
	//! \return ����ָ���������ַ���
	OgdcAchar GetAt(OgdcInt nIndex) const;		
	
	//! \brief ����ָ���������ַ�
	//! \param nIndex ָ��������
	//! \param ch Ҫ���õ��ַ�
	void SetAt(OgdcInt nIndex, OgdcAchar ch);

	//! \brief ��ȡָ���������ַ���
	//! \param  nIndex ָ��������
	//! \return ����ָ���������ַ�
	OgdcAchar operator[](OgdcInt nIndex) const;
	
	//! \brief ����ָ���������ַ������ã�֧��str[i]='a';
	//! \param nIndex ָ��������
	//! \return ����ָ���������ַ�������
	OgdcAchar& operator[](OgdcInt nIndex);

	//! \brief ����ָ���ֽڸ������ڴ�ռ�
	//! \param nCapacity �����ɵ��ֽڸ���
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ�����ӡ�
	//! ���ԭ�пռ��ָ���Ĵ�, Ҳ�����ͷſռ䡣
	void SetCapacity(OgdcInt nCapacity);
	
	//! \brief ��ȡĿǰ���пռ�(�����Ѿ�ʹ�õĺͱ�����)��ռ�õ��ֽڸ���
	OgdcInt GetCapacity() const; 

	//! \brief ��ȡ�ַ�������
	OgdcInt GetLength() const;	
	
	//! \brief �����ַ�������
	//! \param nLength �ֽڸ���
	//! \remarks ������ȱ�С,���Զ��ض�; 
	//!  ������ȱ��,�����0x00��
	void SetLength(OgdcInt nLength);
	

	//! \brief ���ַ�������ת��Ϊ��д�������޸ķ�ASCII�ַ�
	//! \return �������������,֧����д
	OgdcMBString& MakeUpper();
	
	//! \brief ���ַ�������ת��ΪСд�������޸ķ�ASCII�ַ�
	//! \return �������������,֧����д
	OgdcMBString& MakeLower();
	
	//! \brief ���ַ�����ת
	//! \return �������������,֧����д
	//! \remarks ֧���м�������ģ�MBCS����ת��
	//! \include str_MakeReverse.cpp
	OgdcMBString& MakeReverse();
	
	//! \brief ȡ���ַ���������ߵ�ָ�����ȵ����ַ���
	//! \param nCount �ֽڸ���
	//! \return �������ָ�����ȵ����ַ���
	//! \include str_left.cpp
	OgdcMBString Left(OgdcInt nCount) const;
	
	//! \brief ȡ���ַ����������ұߵ�ָ�����ȵ����ַ���
	//! \param nCount �ֽڸ���
	//! \return �����ұ�ָ�����ȵ����ַ���
	//! \include str_right.cpp
	OgdcMBString Right(OgdcInt nCount) const;
	
	//! \brief ���ַ���������ȡ����ָ������������ַ�������
	//! \param nFirst ָ�����м���������
	//! \return ���ش��м�ָ����������ʼ,���������ַ���
	OgdcMBString Mid(OgdcInt nFirst) const;
	
	//! \brief ���ַ��������л�ȡ��ָ��������ָ�����ȵ����ַ�������
	//! \param nFirst nFirst ����ֵ�����ڵ�����
	//! \param nCount Ҫȡ�����ֽڸ���
	//! \include str_mid.cpp
	OgdcMBString Mid(OgdcInt nFirst,OgdcInt nCount) const;

	//! \brief ɾ����ָ���������ָ�����ȵ��ַ���
	//! \param nIndex ��ʼɾ��������ֵ
	//! \param nCount Ҫɾ�����ֽڸ���
	//! \return ����ɾ���ַ�����Ľ���ַ�������ĳ���
	OgdcInt Delete(OgdcInt nIndex,OgdcInt nCount=1);
	
	//! \brief ��ָ��������֮ǰ�����ַ���
	//! \param nIndex ָ��������
	//! \param pstr Ҫ������ַ���
	//! \return �����,����ַ����ĳ���
	OgdcInt Insert(OgdcInt nIndex,const OgdcAchar * pStr);	
	
	//! \brief ��ָ��������֮ǰ����������Ŀ���ַ�
	//! \param nIndex ָ��������
	//! \param ch ָ�����ַ�
	//! \param nCount �ַ��ظ��Ĵ���
	//! \return �����,����ַ����ĳ���
	OgdcInt Insert(OgdcInt nIndex,OgdcAchar ch,OgdcInt nCount=1);
	
	//! \brief ɾ���ַ��������е���ָ���ַ����ַ�
	//! \param ch Ҫɾ�����ַ�
	//! \return ����ɾ�����ַ�����
	OgdcInt Remove(OgdcAchar ch);		

	//! \brief ɾ���ַ���������ߵĿո�\\t\\r\\n��
	//! \return ɾ����,�ַ������������
	OgdcMBString& TrimLeft();
	
	//! \brief ɾ���ַ���������ߵ�ָ���ַ�
	//! \param ch Ҫɾ�����ַ�
	//! \return ɾ����,�ַ������������
	OgdcMBString& TrimLeft(OgdcAchar ch);
	
	//! \brief ɾ���ַ��������������ָ���ַ����ϵ��ַ�
	//! \param pstr ָ�����ַ�������
	//! \return ɾ����,�ַ������������,��֧����д
	//! \remarks �����ַ�����,��Ҫɾ����ߵĴ������ַ������е�ÿһ���ַ�
	//! \include str_TrimLeft.cpp
	OgdcMBString& TrimLeft(const OgdcAchar* pStr);
	
	//! \brief ɾ���ַ��������ұߵĿո�\\t\\r\\n��
	//! \return ɾ����,�ַ������������
	OgdcMBString& TrimRight();
	
	//! \brief ɾ���ַ��������ұߵ�ָ���ַ�
	//! \param ch ָ�����ַ�
	//! \return ɾ����,�ַ������������
	OgdcMBString& TrimRight(OgdcAchar ch);
	
	//! \brief ɾ���ַ��������ұ�����ָ���ַ����ϵ��ַ�
	//! \param pstr ָ�����ַ�������
	//! \return ɾ����,�ַ������������,��֧����д
	//! \remarks �����ַ�����,��Ҫɾ���ұߵĴ������ַ������е�ÿһ���ַ�
	//! \include str_TrimRight.cpp
	OgdcMBString& TrimRight(const OgdcAchar* pStr);

	//! \brief ɾ���ַ��������ұߵ���ָ���ַ������ַ�
	//! \param &str ָ�����ַ���
	//! \return ɾ����,�ַ������������,��֧����д
	//! \include str_TrimRightString.cpp
	OgdcMBString& TrimRightString(const OgdcMBString &str);
	
	//! \brief ɾ���ַ���������ߵ���ָ���ַ������ַ�
	//! \param &str ָ�����ַ���
	//! \return ɾ����,�ַ������������,��֧����д
	//! \include str_TrimLeftString.cpp
	OgdcMBString& TrimLeftString(const OgdcMBString &str);
	
	//! \brief �ж��ַ����Ƿ�Ϊ��
	//! \return Ϊ��,����true;��Ϊ��,����false
	OgdcBool IsEmpty() const;	
	
	//! \brief ����ַ���
	void Empty();

	//! \brief �Ƚ������ַ����Ĵ�С
	//! \param lpsz Ҫ�Ƚϵ��ַ���ָ��
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������
	//! \remarks ���ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	OgdcInt Compare(const OgdcAchar* pStr) const;
	
	//! \brief �Ƚ������ַ����Ĵ�С
	//! \param lpsz Ҫ�Ƚϵ��ַ���ָ��
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������
	//! \remarks �����ִ�Сд�������ڲ�ֵ��˳��Ƚ�
 	OgdcInt CompareNoCase(const OgdcAchar* pStr) const;

	//! \brief �Ƚ������ַ����Ĵ�С
	//! \remarks �����ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	//! \param str Ҫ�Ƚϵ��ַ���
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ���������
	OgdcInt CompareNoCase(const OgdcMBString& str) const;
	
	//! \brief ��ָ��λ�ÿ�ʼ������ָ�����ַ�
	//!	\param ch Ҫ���ҵ��ַ�[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ���ַ��ᱻ����[in]��
	//!	\return �����ҵ����ַ�������ֵ����0�����Ҳ�������-1
	OgdcInt Find(OgdcAchar ch,OgdcInt nStart=0) const;		

	//! \brief ��ָ��λ�ÿ�ʼ��������ȫ��ȵ����ַ���
	//!	\param lpszSub Ҫ���ҵ����ַ���[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ����ᱻ����[in]��
	//!	\return �����ҵ������ַ���������ֵ����0�����Ҳ�������-1
	OgdcInt Find(const OgdcAchar* pStrSub, OgdcInt nStart=0) const;

	//! \brief �Ӻ���ǰ����ָ�����ַ�
	//!	\param ch Ҫ���ҵ��ַ�[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ��ᱻ����[in] -1�����ĩβ���ҡ�
	//!	\return �����ҵ����ַ�������ֵ����0����;�Ҳ�������-1
	OgdcInt ReverseFind(OgdcAchar ch,OgdcInt nStart=-1) const;	

	//! \brief �Ӻ���ǰ����ָ�����ַ�����
	//!	\param ch Ҫ���ҵ��ַ���[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ����ᱻ����[in] -1�����ĩβ���ҡ�
	//!	\return �����ҵ����ַ���������ֵ����0����;�Ҳ�������-1
	OgdcInt ReverseFind(const OgdcAchar* pStrSub,OgdcInt nStart=-1) const;
	
	//! \brief ���ҵ�һ���������ַ��������У�����ָ�����ַ������С����ַ���λ�á�
	//!	\param lpszCharSet ָ�����ַ�����[in]��
	//!	\return �����ҵ����ַ�����������0�����Ҳ�������-1
	OgdcInt FindOneOf(const OgdcAchar* pStrCharSet) const;	

	//! \brief �õ��ַ��������У��ӵ�0���ַ��𣬵�������ָ���ַ������е��ַ�Ϊֹ�����ַ�����
	//! \param lpszCharSet ָ�����ַ�����[in]��
	//!	\return ���ط������������ַ�����
	//!	include str_SpanIncluding.cpp
	OgdcMBString SpanIncluding(const OgdcAchar* pStrCharSet) const;		

	//! \brief �õ��ַ��������У��ӵ�0���ַ��𣬵�����ָ���ַ������е��ַ�Ϊֹ�����ַ�����
	//! \param lpszCharSet ָ�����ַ�����[in]��
	//!	\return ���ط������������ַ�����
	//!	include str_SpanExcluding.cpp
	OgdcMBString SpanExcluding(const OgdcAchar* pStrCharSet) const;
		
	//! \brief �滻���������ַ���������ָ�����ַ��滻Ϊ�µ��ַ���
	//! \param chOld ָ��Ҫ���滻���ַ�[in]��
	//!	\param chNew �µ��ַ�[in]��
	//!	\return �����滻�Ĵ�����
	//! \remarks �Ƚ�ʱ���ִ�Сд��
	OgdcInt Replace(OgdcAchar chOld,OgdcAchar chNew);

	//! \brief �滻���������ַ���������ָ�������ַ����滻Ϊ�µ��ַ���
	//! \param lpszOld ָ��Ҫ���滻�����ַ���[in]��
	//!	\param lpszNew �µ��ַ���[in]��
	//!	\return �����滻�Ĵ�����
	//!	\remarks �Ƚ�ʱ���ִ�Сд��
	OgdcInt Replace(const OgdcAchar* pStrOld,const OgdcAchar* pStrNew);

	

	//! \brief ��ʽ��������������sprintf��
	//!	\param fmt ��������ʽ���ַ���[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�OgdcMBString��Ϊ���������ú��������������OgdcMBString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�OgdcLong��OgdcUlong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ����
	void Format(const OgdcAchar* pStr,...);
	/*
	//! \brief ��ʽ��������������sprintf��
	//!	\param nID ��������ʽ���ַ�������Դ��ID[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�OgdcMBString��Ϊ���������ú��������������OgdcMBString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�OgdcLong��OgdcUlong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ���� 
	
	//����ĺ�������Ҫ����Ϊ����ҪLoadString(nID);
		void Format(OgdcUint nID,...);*/

	//! \brief �ַ�����ֵ������
	const OgdcMBString& operator=(const OgdcMBString& str);	
	
	//! \brief ��std::string����ֵ������
	//! \param str std::string���͵��ַ���,��Ҫ���ں�Markup�Ƚ���ƥ��
	const OgdcMBString& operator=(const std::string& str);	
	
	//! \brief ��C �ַ�����ֵ������	
	//! \param pstr C�ַ�������
	const OgdcMBString& operator=(const OgdcAchar* pStr);
	//! \brief ���� +
	OgdcMBString operator+(const OgdcAchar ch) const;
	//! \brief ���� +
	OgdcMBString operator+(const OgdcAchar* pStr) const;
	//! \brief ���� +
	OgdcMBString operator+(const OgdcMBString& str) const;
	
	//! \brief ���� +=
	const OgdcMBString& operator+=(const OgdcMBString& str);
	//! \brief ���� +=
	const OgdcMBString& operator+=(const OgdcAchar ch);
	//! \brief ���� +=
	const OgdcMBString& operator+=(const OgdcAchar* pStr);
	
	//! \brief ���� ==
	bool operator==(const OgdcAchar* pStr) const;
	//! \brief ���� ==
	bool operator==(const OgdcMBString& str) const;

	//! \brief ���� !=
	bool operator!=(const OgdcAchar* pStr) const;
	//! \brief ���� !=
	bool operator!=(const OgdcMBString& str) const;

	//! \brief ���� <
	bool operator<(const OgdcMBString& str) const;

	//! \brief ���� +
	friend BASE_API OgdcMBString operator+(OgdcAchar ch, const OgdcMBString &str);
	//! \brief ���� +
	friend BASE_API OgdcMBString operator+(const OgdcAchar* pStr, const OgdcMBString &str);	

	
	//! \brief ��OgdcLong�͵�����ת��ΪOgdcMBString���ַ���
	//! \param lVal Ҫת����OgdcLong������
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	//! \return ����ת������ַ���
	//! \remarks ��baseΪ16����ʱ,ת����Ľ��ǰ����0X,��ĸ��Ϊ��д��
	//! �����ַ�ʽ���֧��long�����ݵ�Format,����ת��ΪOgdcMBString,����%s���и�ʽ����
	//! ���þ�̬����������OgdcMBString�ķ�ʽ���Ա��ڵ��õĴ�����д��
	static OgdcMBString From(OgdcLong lVal, OgdcUint base=10);
	//! \brief ��OgdcUlong�͵�����ת��ΪOgdcMBString���ַ���
	static OgdcMBString From(OgdcUlong lVal, OgdcUint base=10);
	//! \brief ��OgdcInt�͵�����ת��ΪOgdcMBString���ַ���
	static OgdcMBString From(OgdcInt nVal, OgdcUint base=10);
	//! \brief ��OgdcUint�͵�����ת��ΪOgdcMBString���ַ���
	static OgdcMBString From(OgdcUint nVal, OgdcUint base=10);
	//! \brief ���ǵ�OgdcArray.GetSize(),������OgdcSizeT,��Linux�ϸ�����Ϊunsigned long,��Ϊ�����ת������
	static OgdcMBString From(unsigned long nVal, OgdcUint base=10);

	//Convert string to a integer number, assuming given number base
	//! \brief ���ַ���ת��ΪOgdcInt����ֵ
	OgdcInt ToInt(OgdcUint base=10) const;

	//! \brief ���ַ���ת��Ϊ�޷���OgdcUint����ֵ
	OgdcUint ToUInt(OgdcUint base=10) const;
	
	//! \brief ���ַ���ת��ΪOgdcLong����ֵ
	//! \param s Ҫת�����ַ���
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	OgdcLong ToLong(OgdcUint base=10) const;

	//! \brief ���ַ���ת��Ϊ�޷���OgdcUlong����ֵ
	//! \param s Ҫת�����ַ���
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	OgdcUlong ToULong(OgdcUint base=10) const;
	
	//Convert string into real number
	//! \brief ���ַ���ת��ΪOgdcFloat����ֵ
	OgdcFloat ToFloat() const;

	//! \brief ���ַ���ת��ΪOgdcDouble����ֵ	
	OgdcDouble ToDouble() const;
	
	//! \brief ���ַ�������ָ���ķָ����ָ�Ϊһ���ַ������顣
	//! \param dest ���ɵ��ַ�������[out]��
	//!	\param delims ָ���ķָ�����Ĭ��Ϊ�س�����[in]��
	//!	\param bKeepEmptyString �Ƿ����ָ�� �յ��ַ���, ���ַ���";"ͨ��';'�ָ��,dest�����size
	//! �ڱ������ַ�����ʱ��Ϊ2, ��������ʱ��Ϊ0; 
	//!	\return �ָ���ַ�������ĳ��ȡ�
	OgdcInt Split(OgdcMBStringArray &strDests,const OgdcMBString& strDelims="\r\n", OgdcBool bKeepEmptyString=FALSE) const;
	
	//! \brief �����ַ���������ַ����ַ���	 
	//�ǲ���OgdcInt Ҫ���OgdcMBString::Charset
	void SetCharset(OgdcInt nCharset);
	//! \brief ��ȡ�ַ���������ַ����ַ���	 
	OgdcMBString::Charset GetCharset() const;

	//! \brief �滻���������ַ���������ָ�������ַ����滻Ϊ�µ��ַ���		
	//!	\remarks �Ƚ�ʱ���ִ�Сд��
	void Replace(OgdcInt startIndex, OgdcInt length, const OgdcAchar* pStrNew);
public:
	//! \brief ����ǰStringת����std::string
	//! \param str Ŀ��std::string
	//!  \return str������,�ڲ����漰������ת�����򵥵�ת���������unicodestring�ĸ��̫һ�� 
	std::string& ToStd(std::string& str) const;
	//! \brief ��std::string ת���ɵ�ǰ��String
	//! \param str Դstd::string
	//!  \return ��ǰString������ �����unicodestring�ĸ��̫һ�� 
	OgdcMBString& FromStd(const std::string& str);


public:	
	//! \brief std���ַ���
	std::string m_string; // �ڲ�����std��stringʵ��
	//! \brief �ַ���
	OgdcMBString::Charset m_nCharset;
};

#ifdef _UGUNICODE
const OgdcWchar g_strNull[]={_U('\r'),_U('\n'),_U('\t'),_U(' '),_U('\0')};
class BASE_API OgdcUnicodeString : public OGDCCharset 
{

public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcUnicodeString();

	//! \breif ��������
	~OgdcUnicodeString();

	//! \brief �������캯��
	//! \param �����������ַ���OgdcUnicodeString
	OgdcUnicodeString(const OgdcUnicodeString& str);

// 	//! \brief �������캯��
// 	//! \param str �����������ַ���(std::string����)
// 	//! \remarks ��Ҫ���ں�Markup�Ƚ���ƥ��
// 	OgdcUnicodeString(const std::string& str);	

	//! \brief �������캯����	
	//! \param pstr �����������ַ���(OgdcWchar*����)
	OgdcUnicodeString(const OgdcWchar* pStr);

	//! \brief �������캯����
	//! \param pstr �����������ַ���(OgdcWchar*����)
	//! \param nSize ָ��ʹ�õ��ֽڳ���
	OgdcUnicodeString(const OgdcWchar* pStr, OgdcInt nSize);

// 	//! \brief �������캯����
// 	//! \param pstr �����������ַ���(OgdcAchar*����)
// 	//! \param nSize ָ��ʹ�õ��ֽڳ���
// 	OgdcUnicodeString(const OgdcAchar* pStr);
// 
// 	//! \brief �������캯����
// 	//! \param pstr �����������ַ���(OgdcAchar*����)
// 	//! \param nSize ָ��ʹ�õ��ֽڳ���
// 	OgdcUnicodeString(const OgdcAchar* pStr, OgdcInt nSize);

	//! \brief �������캯������ch�ظ�����nRepeat�Ρ�
	//! \param ch �����������ַ���(OgdcWchar����)
	//! \param nRepeat �ظ���������,Ĭ��Ϊ1
	//! \remarks explicit���ڷ�ֹ���ε�ת��
	//! \include Ogdcstring.cpp
	explicit OgdcUnicodeString(OgdcWchar ch, OgdcInt nRepeat=1);

	//! \brief ׷���ַ���
	//! \param pch Ҫ׷�ӵ��ַ���
	//! \param nSize Ҫ׷�ӵ��ֽڸ���
	void Append(const OgdcWchar* pStr, OgdcInt nSize);

	//! \brief ��OgdcUnicodeStringת��Ϊconst char*��
	operator OGDCPCWSTR() const;

	//! \brief ��OgdcUnicodeStringת����std::string
	//operator std::string() const;

	//! \brief ��OgdcUnicodeStringת��ΪUnicodeString
	operator UnicodeString() const;

	//! \brief ��ȡWchar�ַ���
	const OgdcWchar * Cstr() const;

	//! \brief ��ȡָ���������ַ���
	//! \param nIndex ָ��������
	//! \return ����ָ���������ַ���
	OgdcWchar GetAt(OgdcInt nIndex) const;		
	OgdcWchar32 GetWchar32At(OgdcInt nIndex) const;

	//! \brief ����ָ���������ַ�
	//! \param nIndex ָ��������
	//! \param ch Ҫ���õ��ַ�
	void SetAt(OgdcInt nIndex, OgdcWchar ch);

	//! \brief ��ȡָ���������ַ���
	//! \param  nIndex ָ��������
	//! \return ����ָ���������ַ�
	OgdcWchar operator[](OgdcInt nIndex) const;

	//! \brief ����ָ���������ַ������ã�֧��str[i]='a';
	//! \param nIndex ָ��������
	//! \return ����ָ���������ַ�������
	OgdcWchar& operator[](OgdcInt nIndex);

	//! \brief ����ָ���ֽڸ������ڴ�ռ�
	//! \param nCapacity �����ɵ��ֽڸ���
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ�����ӡ�
	//! ���ԭ�пռ��ָ���Ĵ�, Ҳ�����ͷſռ䡣
	void SetCapacity(OgdcInt nCapacity);

	//! \brief ��ȡĿǰ���пռ�(�����Ѿ�ʹ�õĺͱ�����)��ռ�õ��ֽڸ���
	OgdcInt GetCapacity() const; 

	//! \brief ��ȡ�ַ�������
	OgdcInt GetLength() const;	

	//! \brief ��ȡ�ַ�������
	//! \breif �����ṩChar32���ȣ�����д���2byte��С���ȵ��ַ����������
	//  ���GetLength����ȡ�ĳ��Ȳ��ȣ�
	OgdcInt GetWchar32Length() const;	

	//! \brief �����ַ�������
	//! \param nLength �ֽڸ���
	//! \remarks ������ȱ�С,���Զ��ض�; 
	//!  ������ȱ��,�����0x00��
	void SetLength(OgdcInt nLength);


	//! \brief ���ַ�������ת��Ϊ��д�������޸ķ�ASCII�ַ�
	//! \return �������������,֧����д
	OgdcUnicodeString& MakeUpper();

	//! \brief ���ַ�������ת��ΪСд�������޸ķ�ASCII�ַ�
	//! \return �������������,֧����д
	OgdcUnicodeString& MakeLower();

	//! \brief ���ַ�����ת
	//! \return �������������,֧����д
	//! \remarks ֧���м�������ģ�MBCS����ת��
	//! \include str_MakeReverse.cpp
	OgdcUnicodeString& MakeReverse();

	//! \brief ȡ���ַ���������ߵ�ָ�����ȵ����ַ���
	//! \param nCount �ֽڸ���
	//! \return �������ָ�����ȵ����ַ���
	//! \include str_left.cpp
	OgdcUnicodeString Left(OgdcInt nCount) const;

	//! \brief ȡ���ַ����������ұߵ�ָ�����ȵ����ַ���
	//! \param nCount �ֽڸ���
	//! \return �����ұ�ָ�����ȵ����ַ���
	//! \include str_right.cpp
	OgdcUnicodeString Right(OgdcInt nCount) const;

	//! \brief ���ַ���������ȡ����ָ������������ַ�������
	//! \param nFirst ָ�����м���������
	//! \return ���ش��м�ָ����������ʼ,���������ַ���
	OgdcUnicodeString Mid(OgdcInt nFirst) const;

	//! \brief ���ַ��������л�ȡ��ָ��������ָ�����ȵ����ַ�������
	//! \param nFirst nFirst ����ֵ�����ڵ�����
	//! \param nCount Ҫȡ�����ֽڸ���
	//! \include str_mid.cpp
	OgdcUnicodeString Mid(OgdcInt nFirst,OgdcInt nCount) const;

	//! \brief ɾ����ָ���������ָ�����ȵ��ַ���
	//! \param nIndex ��ʼɾ��������ֵ
	//! \param nCount Ҫɾ�����ֽڸ���
	//! \return ����ɾ���ַ�����Ľ���ַ�������ĳ���
	OgdcInt Delete(OgdcInt nIndex,OgdcInt nCount=1);

	//! \brief ��ָ��������֮ǰ�����ַ���
	//! \param nIndex ָ��������
	//! \param pstr Ҫ������ַ���
	//! \return �����,����ַ����ĳ���
	OgdcInt Insert(OgdcInt nIndex,const OgdcWchar * pStr);	

	//! \brief ��ָ��������֮ǰ����������Ŀ���ַ�
	//! \param nIndex ָ��������
	//! \param ch ָ�����ַ�
	//! \param nCount �ַ��ظ��Ĵ���
	//! \return �����,����ַ����ĳ���
	OgdcInt Insert(OgdcInt nIndex,OgdcWchar ch,OgdcInt nCount=1);
    
	//add by cuiwz
	//! \brief ɾ���ַ��������е���ָ���ַ����ַ�
	//! \param ch Ҫɾ�����ַ�
	//! \return ����ɾ�����ַ�����
	OgdcInt Remove(OgdcWchar ch);

	//! \brief ɾ���ַ���������ߵĿո�\\t\\r\\n��
	//! \return ɾ����,�ַ������������
	OgdcUnicodeString& TrimLeft()
	{
		return TrimLeft(g_strNull);
	};
	
	//! \brief ɾ���ַ���������ߵ�ָ���ַ�
	//! \param ch Ҫɾ�����ַ�
	//! \return ɾ����,�ַ������������
	OgdcUnicodeString& TrimLeft(OgdcWchar ch);
	
	//! \brief ɾ���ַ��������������ָ���ַ����ϵ��ַ�
	//! \param pstr ָ�����ַ�������
	//! \return ɾ����,�ַ������������,��֧����д
	//! \remarks �����ַ�����,��Ҫɾ����ߵĴ������ַ������е�ÿһ���ַ�
	//! \include str_TrimLeft.cpp
	OgdcUnicodeString& TrimLeft(const OgdcWchar* pStr);
	
	//! \brief ɾ���ַ��������ұߵĿո�\\t\\r\\n��
	//! \return ɾ����,�ַ������������
	OgdcUnicodeString& TrimRight()
	{
		return TrimRight(g_strNull);
	};
	
	//! \brief ɾ���ַ��������ұߵ�ָ���ַ�
	//! \param ch ָ�����ַ�
	//! \return ɾ����,�ַ������������
	OgdcUnicodeString& TrimRight(OgdcWchar ch);
	
	//! \brief ɾ���ַ��������ұ�����ָ���ַ����ϵ��ַ�
	//! \param pstr ָ�����ַ�������
	//! \return ɾ����,�ַ������������,��֧����д
	//! \remarks �����ַ�����,��Ҫɾ���ұߵĴ������ַ������е�ÿһ���ַ�
	//! \include str_TrimRight.cpp
	OgdcUnicodeString& TrimRight(const OgdcWchar* pStr);

	//! \brief ɾ���ַ��������ұߵ���ָ���ַ������ַ�
	//! \param &str ָ�����ַ���
	//! \return ɾ����,�ַ������������,��֧����д
	//! \include str_TrimRightString.cpp
	OgdcUnicodeString& TrimRightString(const OgdcUnicodeString &str);
	
	//! \brief ɾ���ַ���������ߵ���ָ���ַ������ַ�
	//! \param &str ָ�����ַ���
	//! \return ɾ����,�ַ������������,��֧����д
	//! \include str_TrimLeftString.cpp
	OgdcUnicodeString& TrimLeftString(const OgdcUnicodeString &str);
	
	//! \brief �ж��ַ����Ƿ�Ϊ��
	//! \return Ϊ��,����true;��Ϊ��,����false
	OgdcBool IsEmpty() const;	
	
	//! \brief ����ַ���
	void Empty();

	//! \brief �Ƚ������ַ����Ĵ�С
	//! \param lpsz Ҫ�Ƚϵ��ַ���ָ��
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������
	//! \remarks ���ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	OgdcInt Compare(const OgdcWchar* pStr) const;
	
	//! \brief �Ƚ������ַ����Ĵ�С
	//! \param lpsz Ҫ�Ƚϵ��ַ���ָ��
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ�������
	//! \remarks �����ִ�Сд�������ڲ�ֵ��˳��Ƚ�
 	OgdcInt CompareNoCase(const OgdcWchar* pStr) const;

	//! \brief �Ƚ������ַ����Ĵ�С
	//! \remarks �����ִ�Сд�������ڲ�ֵ��˳��Ƚ�
	//! \param str Ҫ�Ƚϵ��ַ���
	//! \return С�ڷ��ظ��������ڷ���0�����ڷ���������
	OgdcInt CompareNoCase(const OgdcUnicodeString& str) const;
	
	//! \brief ��ָ��λ�ÿ�ʼ������ָ�����ַ�
	//!	\param ch Ҫ���ҵ��ַ�[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ���ַ��ᱻ����[in]��
	//!	\return �����ҵ����ַ�������ֵ����0�����Ҳ�������-1
	OgdcInt Find(OgdcWchar ch,OgdcInt nStart=0) const;		

	//! \brief ��ָ��λ�ÿ�ʼ��������ȫ��ȵ����ַ���
	//!	\param lpszSub Ҫ���ҵ����ַ���[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ����ᱻ����[in]��
	//!	\return �����ҵ������ַ���������ֵ����0�����Ҳ�������-1
	OgdcInt Find(const OgdcWchar* pStrSub, OgdcInt nStart=0) const;

	//! \brief �Ӻ���ǰ����ָ�����ַ�
	//!	\param ch Ҫ���ҵ��ַ�[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ��ᱻ����[in] -1�����ĩβ���ҡ�
	//!	\return �����ҵ����ַ�������ֵ����0����;�Ҳ�������-1
	OgdcInt ReverseFind(OgdcWchar ch,OgdcInt nStart=-1) const;	

	//! \brief �Ӻ���ǰ����ָ�����ַ�����
	//!	\param ch Ҫ���ҵ��ַ���[in]��
	//!	\param nStart ������ʼλ�ã���Ӧ�����ַ����ᱻ����[in] -1�����ĩβ���ҡ�
	//!	\return �����ҵ����ַ���������ֵ����0����;�Ҳ�������-1
	OgdcInt ReverseFind(const OgdcWchar* pStrSub,OgdcInt nStart=-1) const;
	
	//! \brief ���ҵ�һ���������ַ��������У�����ָ�����ַ������С����ַ���λ�á�
	//!	\param lpszCharSet ָ�����ַ�����[in]��
	//!	\return �����ҵ����ַ�����������0�����Ҳ�������-1
	OgdcInt FindOneOf(const OgdcWchar* pStrCharSet) const;	

	//! \brief �õ��ַ��������У��ӵ�0���ַ��𣬵�������ָ���ַ������е��ַ�Ϊֹ�����ַ�����
	//! \param lpszCharSet ָ�����ַ�����[in]��
	//!	\return ���ط������������ַ�����
	//!	include str_SpanIncluding.cpp
	OgdcUnicodeString SpanIncluding(const OgdcWchar* pStrCharSet) const;		

	//! \brief �õ��ַ��������У��ӵ�0���ַ��𣬵�����ָ���ַ������е��ַ�Ϊֹ�����ַ�����
	//! \param lpszCharSet ָ�����ַ�����[in]��
	//!	\return ���ط������������ַ�����
	//!	include str_SpanExcluding.cpp
	OgdcUnicodeString SpanExcluding(const OgdcWchar* pStrCharSet) const;
		
	//! \brief �滻���������ַ���������ָ�����ַ��滻Ϊ�µ��ַ���
	//! \param chOld ָ��Ҫ���滻���ַ�[in]��
	//!	\param chNew �µ��ַ�[in]��
	//!	\return �����滻�Ĵ�����
	//! \remarks �Ƚ�ʱ���ִ�Сд��
	OgdcInt Replace(OgdcWchar chOld,OgdcWchar chNew);

	//! \brief �滻���������ַ���������ָ�������ַ����滻Ϊ�µ��ַ���
	//! \param lpszOld ָ��Ҫ���滻�����ַ���[in]��
	//!	\param lpszNew �µ��ַ���[in]��
	//!	\return �����滻�Ĵ�����
	//!	\remarks �Ƚ�ʱ���ִ�Сд��
	OgdcInt Replace(const OgdcWchar* pStrOld,const OgdcWchar* pStrNew);

	

	//! \brief ��ʽ��������������sprintf��
	//!	\param fmt ��������ʽ���ַ���[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�OgdcUnicodeString��Ϊ���������ú��������������OgdcUnicodeString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�OgdcLong��OgdcUlong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ����
	void Format(const OgdcWchar* pStr,...);
	/*
	//! \brief ��ʽ��������������sprintf��
	//!	\param nID ��������ʽ���ַ�������Դ��ID[in]��
	//!	\param ... ��ѡ����[in]��
	//!	\remarks ���ܽ�OgdcUnicodeString��Ϊ���������ú��������������OgdcUnicodeString��Cstr�����õ�C�ַ�����
	//!			 ���ܽ�OgdcLong��OgdcUlong��64λ������Ϊ��������ú���,��Ӧ����ǿ��ת��Ϊ32λ���� 
	
	//����ĺ�������Ҫ����Ϊ����ҪLoadString(nID);
		void Format(OgdcUint nID,...);*/

	//! \brief �ַ�����ֵ������
	const OgdcUnicodeString& operator=(const OgdcUnicodeString& str);	
	
// 	//! \brief ��std::string����ֵ������
// 	//! \param str std::string���͵��ַ���,��Ҫ���ں�Markup�Ƚ���ƥ��
// 	const OgdcUnicodeString& operator=(const std::string& str);	
	
	//! \brief ��C �ַ�����ֵ������	
	//! \param pstr C�ַ�������
	const OgdcUnicodeString& operator=(const OgdcWchar* pStr);




	//add by jiangzb
	//! \brief ���� +
	OgdcUnicodeString operator+(const OgdcWchar ch) const;
	//! \brief ���� +
	OgdcUnicodeString operator+(const OgdcWchar* pStr) const;
	//! \brief ���� +
	OgdcUnicodeString operator+(const OgdcUnicodeString& str) const;
	
	//! \brief ���� +=
	const OgdcUnicodeString& operator+=(const OgdcUnicodeString& str);
	//! \brief ���� +=
	const OgdcUnicodeString& operator+=(const OgdcWchar ch);
	//! \brief ���� +=
	const OgdcUnicodeString& operator+=(const OgdcWchar* pStr);
	
	//! \brief ���� ==
	bool operator==(const OgdcWchar* pStr) const;
	//! \brief ���� ==
	bool operator==(const OgdcUnicodeString& str) const;

	//! \brief ���� !=
	bool operator!=(const OgdcWchar* pStr) const;
	//! \brief ���� !=
	bool operator!=(const OgdcUnicodeString& str) const;

	//! \brief ���� <
	bool operator<(const OgdcUnicodeString& str) const;

	//! \brief ���� +
	friend BASE_API OgdcUnicodeString operator+(OgdcWchar ch, const OgdcUnicodeString &str);
	//! \brief ���� +
	friend BASE_API OgdcUnicodeString operator+(const OgdcWchar* pStr, const OgdcUnicodeString &str);	

	//! \brief ���� ==
	friend BASE_API bool operator==(const OgdcWchar* pStr, const OgdcUnicodeString& str);
	
	//! \brief ��OgdcLong�͵�����ת��ΪOgdcUnicodeString���ַ���
	//! \param lVal Ҫת����OgdcLong������
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	//! \return ����ת������ַ���
	//! \remarks ��baseΪ16����ʱ,ת����Ľ��ǰ����0X,��ĸ��Ϊ��д��
	//! �����ַ�ʽ���֧��long�����ݵ�Format,����ת��ΪOgdcUnicodeString,����%s���и�ʽ����
	//! ���þ�̬����������OgdcUnicodeString�ķ�ʽ���Ա��ڵ��õĴ�����д��
	static OgdcUnicodeString From(OgdcLong lVal, OgdcUint base=10);
	//! \brief ��OgdcUlong�͵�����ת��ΪOgdcUnicodeString���ַ���
	static OgdcUnicodeString From(OgdcUlong lVal, OgdcUint base=10);
	//! \brief ��OgdcInt�͵�����ת��ΪOgdcUnicodeString���ַ���
	static OgdcUnicodeString From(OgdcInt nVal, OgdcUint base=10);
	//! \brief ��OgdcUint�͵�����ת��ΪOgdcUnicodeString���ַ���
	static OgdcUnicodeString From(OgdcUint nVal, OgdcUint base=10);
	//! \brief ���ǵ�OgdcArray.GetSize(),������OgdcSizeT,��Linux�ϸ�����Ϊunsigned long,��Ϊ�����ת������
	static OgdcUnicodeString From(unsigned long nVal, OgdcUint base=10);

	//Convert string to a integer number, assuming given number base
	//! \brief ���ַ���ת��ΪOgdcInt����ֵ
	OgdcInt ToInt(OgdcUint base=10) const;

	//! \brief ���ַ���ת��Ϊ�޷���OgdcUint����ֵ
	OgdcUint ToUInt(OgdcUint base=10) const;
	
	//! \brief ���ַ���ת��ΪOgdcLong����ֵ
	//! \param s Ҫת�����ַ���
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	OgdcLong ToLong(OgdcUint base=10) const;

	//! \brief ���ַ���ת��Ϊ�޷���OgdcUlong����ֵ
	//! \param s Ҫת�����ַ���
	//! \param base ����,Ĭ��Ϊ10����,��֧��16����;������ʱ��֧��
	OgdcUlong ToULong(OgdcUint base=10) const;
	
	//Convert string into real number
	//! \brief ���ַ���ת��ΪOgdcFloat����ֵ
	OgdcFloat ToFloat() const;

	//! \brief ���ַ���ת��ΪOgdcDouble����ֵ	
	OgdcDouble ToDouble() const;
	
	//! \brief ���ַ�������ָ���ķָ����ָ�Ϊһ���ַ������顣
	//! \param dest ���ɵ��ַ�������[out]��
	//!	\param delims ָ���ķָ�����Ĭ��Ϊ�س�����[in]��
	//!	\param bKeepEmptyString �Ƿ����ָ�� �յ��ַ���, ���ַ���";"ͨ��';'�ָ��,dest�����size
	//! �ڱ������ַ�����ʱ��Ϊ2, ��������ʱ��Ϊ0; 
	//!	\return �ָ���ַ�������ĳ��ȡ�
	OgdcInt Split(OgdcUnicodeStringArray &strDests,const OgdcWchar* pStrDelims=_U("\r\n"), OgdcBool bKeepEmptyString=FALSE) const;
	
	//! \brief �����ַ���������ַ����ַ���	 
	//�ǲ���OgdcInt Ҫ���OgdcUnicodeString::Charset
	void SetCharset(OgdcInt nCharset);
	//! \brief ��ȡ�ַ���������ַ����ַ���	 
	OgdcMBString::Charset GetCharset() const;

	//! \brief �滻���������ַ���������ָ�������ַ����滻Ϊ�µ��ַ���		
	//!	\remarks �Ƚ�ʱ���ִ�Сд��
	void Replace(OgdcInt startIndex, OgdcInt length, const OgdcWchar* pStrNew);

	OgdcUnicodeString& FromUTF8(const OgdcAchar *pSrc, OgdcInt nSrcLength);
	OgdcMBString& ToUTF8(OgdcMBString& strResult) const;
public:
	//! \brief ����ǰStringת����std::string
	//! \param str Ŀ��std::string
	//! \param charset Ŀ��std::string�ı���
	//!  \return str������,
	std::string& ToStd(std::string& str,OGDCCharset::Charset charset = OGDCCharset::UTF8) const;

	//! \brief ת����ָ�������MBString,����Ϊstr�ı���
	OgdcMBString& ToMBString(OgdcMBString& str) const
	{
		ToStd(str.m_string,str.m_nCharset);
		return str;
	}

	//! \brief ��std::string ת���ɵ�ǰ��String
	//! \param str Դstd::string
	//! \param charset Դstd::string ����
	//!  \return ��ǰString������ 
	OgdcUnicodeString& FromStd(const std::string& str,OGDCCharset::Charset charset = OGDCCharset::UTF8)
	{
		return FromMBString(str.c_str(),str.length(),charset);
	}

	//! \brief ��strת���ɵ�ǰUnicodeString,str�������������
	OgdcUnicodeString& FromMBString(const OgdcMBString& str)
	{
		return  FromStd(str.m_string,str.m_nCharset);
	}
	OgdcUnicodeString& FromMBString(const OgdcAchar *pSrc, OgdcInt nSrcLength,OGDCCharset::Charset charset = OGDCCharset::Default);

public:
	static OgdcInt u_str32len(const OgdcWchar32* pStr)
	{
		const OgdcWchar32 *eos = pStr;
		while( *eos++ ) ;
		return( (OgdcInt)(eos - pStr - 1) );
	};

	static OgdcInt WcharToAchar(const OgdcWchar* pWchar, OgdcAchar *pAchar, OgdcInt nAcharLength);
	static OgdcInt AcharToWchar(const OgdcAchar* pAchar, OgdcWchar *pWchar, OgdcInt nWcharLength);
	static OgdcInt WcharToWchar32(const OgdcWchar* pWchar, OgdcWchar32* pWchar32, OgdcInt nWchar32Length);
	static OgdcInt Wchar32ToWchar( const OgdcWchar32* pWchar32, OgdcWchar* pWchar, OgdcInt nWcharLength );
	
	struct ShowUnicodeString	// ����ṹ�������˼�����ܽ��UnicodeString���ݵ���ʾ���⣬����ΪUnicodeString��ʼ�����ڴ�
	{
		void		*pString;
		void		*pVftable;
		OgdcInt		fLength;
		OgdcInt		fCapacity;     
		OgdcWchar	*fArray; 
		OgdcShort	fFlags;
		OgdcWchar	fStackBuffer[7];
	};
	
private:
	OgdcInt FindNotOneOf(const OgdcWchar* pStrCharSet) const;
    OgdcInt GetStrLength(const OgdcWchar* pStr) const ;
	inline OgdcWchar* UG_memchr(const OgdcWchar *s, OgdcWchar c, OgdcInt count) 
	{
		if(count>0) 
		{
			/* trivial search for a BMP code point */
			const OgdcWchar *limit=s+count;
			do 
			{
				if(*s==c) 
				{
					return (OgdcWchar *)s;
				}
			} while(++s!=limit);
			 return NULL;
		} 
		else 
		{
			return NULL; /* no string */
		}
	}

	inline OgdcInt UG_memcmp(const OgdcWchar *buf1, const OgdcWchar *buf2, OgdcInt count) 
	{
		if(count > 0) 
		{
			const OgdcWchar *limit = buf1 + count;
			OgdcInt result;

			while (buf1 < limit) {
				result = (OgdcInt)*buf1 - (OgdcInt)*buf2;
				if (result != 0) {
					return result;
				}
				buf1++;
				buf2++;
			}
		}
		return 0;
	}
	inline OgdcWchar* UG_memcpy(OgdcWchar  *dst,const OgdcWchar  *src, OgdcInt n) 
	{
		OgdcWchar *anchor = dst;            /* save a pointer to start of dst */
		while(n > 0 )  
		{
			*dst= *src;
			dst++;
			src++;
			--n;
		}

		return anchor;
	}
private:
	// UnicodeString����icu��UnicodeStringʵ��
	union   //��������ö��,������ʾUnicodeString����ʵ����,�������struct ShowUnicodeString�е�����,�ṹ��ľ���������Ҫ��ICU�����Աͬ������  add by zhangkai!
	{		
		UnicodeString* m_pString;
		struct ShowUnicodeString m_innerUnicodeString;
	};
	//! \brief �ַ���
public:
	OgdcMBString::Charset m_nCharset;

private:
	inline void InitCharset()
	{
		if (OGDC_ISBIGENDIAN)
		{
			m_nCharset = OgdcMBString::UCS2BE;
		}
		else
		{
			m_nCharset = OgdcMBString::UCS2LE;
		}
		//pChar = NULL;
	}
};
#endif

#ifdef _UGUNICODE
typedef OgdcUnicodeString OgdcString;
#else
typedef OgdcMBString OgdcString;
#endif //  _UNICODE

EXTERN_C BASE_API  void Unicode2MBString(const OgdcString& strUnicode, OgdcMBString& strMB);
#define UNICODE2MBSTRING(strU,strMB) Unicode2MBString(strU,strMB)

EXTERN_C BASE_API  void MBString2Unicode(const OgdcMBString& strMB, OgdcString& strUnicode);
#define MBSTRING2UNICODE(strMB,strU) MBString2Unicode(strMB,strU)

typedef OgdcArray<OgdcString> OgdcStringArray;
}

#endif // !defined(AFX_OGDCSTRING_H__2CA5E3F6_86E2_4EA7_A56F_CE716B8B1E05__INCLUDED_)

