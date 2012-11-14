//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcSystem.h
//!  \brief ϵͳ������
//!  \details   
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCSYSTEM_H__980E850B_7989_4E01_A079_7B18C9B132D5__INCLUDED_)
#define AFX_OGDCSYSTEM_H__980E850B_7989_4E01_A079_7B18C9B132D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base/OgdcString.h"
namespace OGDC{
//!  \brief ϵͳ������
class BASE_API OgdcSystem  
{
private:
	OgdcSystem();
    ~OgdcSystem();
public:

	//! \brief ͨ����̬�����ƣ����ض�̬��
	//! \param strLibName ��̬������
	static void* LoadDll(const OgdcString& strLibName);

	//! \brief ͨ����ľ���ͺ�������,�õ�����ָ��
	//! \param hModule ��̬����
	//! \param strProName ��������
	static void* GetProcAddress(void* hModule, const OgdcString& strProName);

	//! \brief �ͷŶ�̬��
	//! \param hModule ��̬����
	static OgdcBool FreeDll(void* hModule);


	//! \brief �ж��ַ��Ƿ����ڿ�ASCII�ַ�, �������ո�,\\t\\r\\n��
	static OgdcBool IsSpaceChar(OgdcAchar ch);

	//! \brief �ж��ַ��Ƿ����ڿ�ASCII�ַ�, �������ո�,\\t\\r\\n��
	static OgdcBool IsSpaceChar(OgdcWchar wch);

	//! \brief �ж��ַ��Ƿ����������ַ�, �� '0' �� '9'
	static OgdcBool IsDigit(OgdcAchar ch);

	//! \brief �ж��ַ��Ƿ�����ʮ�������ַ�, ������ '0' �� '9', 'A'��'F', 'a'��'f'
	static OgdcBool IsHexDigit(OgdcAchar ch);

	//! \brief �ж��ַ��Ƿ����ڴ�д�ַ�, �� 'A' �� 'Z'
	static OgdcBool IsBigLetter(OgdcAchar ch);

	//! \brief �ж��ַ��Ƿ�����Сд�ַ�, �� 'a' �� 'z'
	static OgdcBool IsLittleLetter(OgdcAchar ch);
	
	//! \brief �жϸ��ֽ��Ƿ���lead byte�������ֽںͺ����ֽ�������һ�𹹳�һ��˫�ֽڵ��ַ��������ġ����ĵȣ�
	static OgdcBool IsLeadByte(OgdcAchar ch);
	
	//! \brief �ж�һ��UCS2���ַ��Ƿ���Ӣ���ַ�
	//! \return ��������Ļ����ĵ��ַ�������false����Ӣ���ַ�������true
	static OgdcBool IsAscii(OgdcUshort ch);

#ifdef _UGUNICODE
	//! \brief �ж��ַ��Ƿ����������ַ�, �� '0' �� '9'
	static OgdcBool IsDigit(OgdcWchar32 ch);

	//! \brief �ж��ַ��Ƿ�����ʮ�������ַ�, ������ '0' �� '9', 'A'��'F', 'a'��'f'
	static OgdcBool IsHexDigit(OgdcWchar32 ch);

	//! \brief �ж��ַ��Ƿ����ڴ�д�ַ�, �� 'A' �� 'Z'
	static OgdcBool IsBigLetter(OgdcWchar32 ch);

	//! \brief �ж��ַ��Ƿ�����Сд�ַ�, �� 'a' �� 'z'
	static OgdcBool IsLittleLetter(OgdcWchar32 ch);
#endif

	//! \brief ��ȡ����·��
	static OgdcString GetAppPath();
	//! \brief ��ȡģ��·��
	static OgdcString GetModulePath(const OgdcString& strModultTitle);
	//! \brief ��ȡĿ¼
	static OgdcString GetDir(const OgdcString& strFile);
	//! \brief ��ȡ�ļ���׺��
	static OgdcString GetExtName(const OgdcString& strFile);
	//! \brief ��ȡ�ļ���׺��
	static OgdcBool FindFileExtPaths(const OgdcString& strPath, const OgdcString& strExtName, 
								  OgdcArray<OgdcString>& strFileNames, OgdcBool bAddPath);

	//! \brief �жϵ�ǰdll���ط�ʽ�Ƿ���Ҫ�޸�ϵͳ·����Ĭ�ϲ���Ҫ�޸ģ�web��άӦ��ʱ��Ҫ���⴦��
	static OgdcBool ms_bNeedResetCurrentDirectory;
	
	//!  \brief ��ȡ��Ӧ�ַ���String 
	static OgdcString GetCharsetName(OGDCCharset::Charset charset);
	//!  \brief ��ȡString�Ķ�Ӧ���ַ���
	static OGDCCharset::Charset GetCharset(const OgdcString &strCharsetName);
	//! \brief �õ��ַ���������
	//! param charset[in] �ַ���
	//! return ICU��ʹ�õ��ַ���������
	//! remark �����������OgdcUnicodeString���б���ת����ʱ��ʹ�ã�����OgdcUnicodeString��FromMBString��ToMBString�е��ã�
	//! IA5���벿�ֲ���windows-1252���д����μ�ICU����,Converter Explorer
	static OgdcString GetCharsetNameICU(OGDCCharset::Charset charset);
	static OGDCCharset::Charset GetCurCharset();

#ifdef _UGUNICODE
	static OgdcInt GetModulePath(const OgdcChar* pModuleTitle, OgdcChar* pModulePath, OgdcInt nLength);
#endif
};

}

#endif // !defined(AFX_OGDCSYSTEM_H__980E850B_7989_4E01_A079_7B18C9B132D5__INCLUDED_)

