//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | \ | | | __  | | \ | | |                       
//                   | |_/ | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcDsConnection.h
//!  \brief OgdcDsConnection �Ľӿڶ��塣
//!  \details Ogdc���� ���ݿ�/����Դ ���Ӳ����Ľӿڶ��塣
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#ifndef OGDCDSCONNECTION_H 
#define OGDCDSCONNECTION_H

#include "Base/OgdcString.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

namespace OGDC
{
//! \brief ������������, >= 1001 Ϊ�û���չ��
enum OgdcEngineType
{	
	//! \brief δ֪��������
	oeNone			=-1,
	//! \brief Oracle�ռ���������	
	oeOracle			=12,
	//! \brief SyBase�ռ���������	
	oeSybase		    =15,
	//! \brief Micresoft SQL server�ռ���������	
	oeSQLServer		=16,
	//! \brief ���οռ���������	
	oeDM				=17,
	//! \brief IMB DB2�ռ���������	
	oeDB2             =18,
	//! \brief �˴��ֿռ���������	
	oeKingbase		=19,
	//! \brief ���Է���OGC WMS/WFS/WCS�ȷ������������	
	oeOGC				=23,
	//! \brief ��ƽ̨�ļ�����	
// 	oeFile			=30, 
	oeFile			= 219,		//��������ֵ����Ᵽ��һ��,��ӦUDB
	//! \brief MySQL�ռ���������	
//	oeMySQL			=31,
	oeMySQL			=32,		//��������ֵ����Ᵽ��һ��
};

//! \brief ��������Դ������Ϣ
#define OgdcConnection OgdcDsConnection

//! \brief ���ݿ�������Ϣ��
class OGDC_API OgdcConnection  
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcConnection();

	//! \brief �������캯����
	//! \param conn �������ö���[in]��
	OgdcConnection(const OgdcConnection& conn);	

	//! \brief Ĭ������������
#ifdef SYMBIAN60
	~OgdcConnection();
#else
	virtual ~OgdcConnection();
#endif
	

public:
	//! \brief ��ֵ���ݿ����Ӷ���
	//! \param &conn �������Ӷ���ֵ[in]��
	const OgdcConnection& operator =(const OgdcConnection &conn);	
	
	//! \brief ��ǰ������Ŀ�������бȽ��Ƿ���ȫ��ͬ��
	//! \param &conn Ŀ�����Ӷ���[in]��
	//! \return �Ƿ���ͬ����ͬ����TRUE����ͬ����FALSE��
	OgdcBool operator ==(const OgdcConnection &conn);	

	//! \brief ��ǰ������Ŀ�������бȽ��Ƿ���ͬ��
	//! \param &conn Ŀ�����Ӷ���[in]��
	//! \return �Ƿ�ͬ����ͬ����TRUE����ͬ����FALSE��
	OgdcBool operator !=(const OgdcConnection &conn);	

public:
	//! \brief ���ݿ����͡�
	OgdcInt	m_nType;

	//! \brief ��������
	//! \remarks ���磺Oracle ���ݿ��ʵ������SSQL Sever�ķ���������
	OgdcString	m_strServer;
	
	//! \brief �û�����
	OgdcString	m_strUser;
	
	//! \brief ���롣
	OgdcString	m_strPassword;
	
	//! \brief �Ƿ�ֻ���򿪡�
	OgdcBool	m_bReadOnly;

	//! \brief �Ƿ�������ʽ�򿪡�
	OgdcBool	m_bTransacted;
	
	//! \brief �Ƿ��ռ�򿪡�
	OgdcBool	m_bExclusive;
	
	//! \brief ���ݿ��Ƿ���Ҫ����򿪡�
	OgdcBool	m_bEncrypt;
	
	//! \brief ���ݿ�����
	OgdcString	m_strDatabase;
	
	//! \brief ODBC Driver��
	OgdcString	m_strDriver;

	//! \brief  MySQL���Ƿ��������ܵ������ӷ�ʽ
	OgdcBool   m_bPipe;

	//! \brief MySQL����ͨ���ӷ�ʽ�Ķ˿�
	OgdcInt    m_nPort;
	
	//! \brief ���ݿ������
	OgdcString	m_strAlias;
	
	//! \brief ���ݿ��Ƿ��ڴ򿪹����ռ�ʱ�Զ��򿪡�
	OgdcBool	m_bAutoConnect;
	
	//! \brief ���ݿ����ӳص����������
	OgdcInt		m_nConnMaxNum;
	
	//! \brief ���ݿ����ӳص���С������
	OgdcInt		m_nConnMinNum;
	
	//! \brief ���ݿ����ӳص�����������
	OgdcInt		m_nConnIncNum;
	
	//! \brief ���ݿ��Ƿ���չ��	
	OgdcBool	m_bExpandOpen;	
};
}
#endif // !defined(OGDCDSCONNECTION_H)

