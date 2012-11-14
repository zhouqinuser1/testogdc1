//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcDict.h
//!  \brief �ֵ��� 
//!  \details  �ڲ�����STL��mapʵ��
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCDICT_H__EA6AD17F_452A_4C4B_9FA0_F79418967EB8__INCLUDED_)
#define AFX_OGDCDICT_H__EA6AD17F_452A_4C4B_9FA0_F79418967EB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"

namespace OGDC {

#define OgdcLess std::less
#define OgdcGreater std::greater

//! \brief �ֵ��ࡣ
//! ������MFC�е�CMap,�ڲ�����stl��mapʵ�֡�
template<typename Key, typename T, class Compare = std::less<Key> >
class OGDCEXPORT OgdcDict 
{
public:
	//! \brief ����ָʾԪ�����ֵ���λ�õ�ֵ
	typedef typename std::map<Key,T,Compare>::const_iterator POSITION;
	
public:
	//! \brief Ĭ�Ϲ��캯����
	OgdcDict()	
	{

	}

	//! \brief �õ�Ԫ�ظ�����
	//! \return ����Ԫ�ظ�����
	OgdcInt GetCount() const	
	{
		return (OgdcInt)m_dict.size();
	}

	//! \brief �ж��Ƿ�Ϊ�ա�
	//! \return �շ���true;�ǿշ���false��
	OgdcBool IsEmpty() const	
	{
		return m_dict.empty();
	}

	//! \brief ����һ���ֵ俽����
	//! \param src ���ڿ������ֵ�[in]��
	void Copy(const OgdcDict<Key,T,Compare>& src)	
	{
		*this=src;
	}

	//! \brief ����ָ��rkey��valueԪ�ء�
	//! \param rkey Ҫ���ҵ�key[in]��
	//! \param rValue �õ���Ԫ��[out]��
	//! \return ���ҳɹ�����true;���ɹ�����false��
	OgdcBool Lookup(const Key& rkey,T& rValue) const	
	{
		POSITION it=m_dict.find(rkey);		
		if(it!=m_dict.end())
		{
			rValue = it->second;
			return TRUE;
		}
		return FALSE;
	}

	//! jifang �����08/18/2005.
	//! \brief ͨ��rkeyֱ�Ӳ��ҵ�Ԫ�ص�ָ�롣
	//! \param rkey Ҫ���ҵ�keyֵ[in]��
	//! \return �ҵ��򷵻�ָ��UGDict�ڲ���Ԫ�ص�ָ��, ���ǿ���;��û�鵽, �򷵻ؿ�ָ�롣
	const T* Lookup(const Key &rkey) const	
	{
		POSITION it=m_dict.find(rkey);		
		if(it!=m_dict.end())
		{
			return (const T*)(&it->second);
		}
		return NULL;
	}	

	//! \brief ��ָ����rkey����ָ����Ԫ�ء�
	//! \param rkey ָ���ļ�ֵ[in]��
	//! \param newValue ָ����Ԫ��[in]��
	void SetAt(const Key& rkey,const T& newValue)	
	{
		operator[](rkey)=newValue;
	}
#ifndef SYMBIAN60
	//���������SYMBIAN��  ����OgdcDict������벻��
	//! \brief ͨ��ָ����rkey�õ���ӦԪ�ص����á�
	//! \param rkey ָ����rkeyֵ[in]��
	//! \return ���ض�ӦԪ�ص����á�
	const T& operator[](const Key& rkey) const	
	{
		return m_dict.operator [](rkey);
	}
#endif

	//! \brief ͨ��ָ����rkey�õ���ӦԪ�ص����á�
	//! \param rkey ָ����keyֵ[in]��
	//! \return ���ض�ӦԪ�ص����á�
	T& operator[](const Key& rkey) 
	{
		return m_dict.operator [](rkey);
	}

	//! \brief �Ƴ�rkeyֵ��Ӧ��Ԫ�ء�
	//! \param rkey Ҫ�Ƴ���keyֵ[in]��
	//! \return �ɹ�����true;ʧ�ܷ���false��
	OgdcBool RemoveKey(const Key& rkey)	
	{
		return m_dict.erase(rkey)>0;
	}

	//! \brief �Ƴ�����Ԫ��
	void RemoveAll()
	{
		m_dict.clear();
	}

	//! \brief �õ���ʼλ�á�
	//! \return ���ؿ�ʼλ�á�
	//! \remarks �õ���ʼλ�ú�,��ͨ��GetNextAssoc�����Ϳ���һ������һ���õ��ֵ������е�Ԫ��
	//! \attention ע��ʹ��IsEOF�����жϲ�Ҫ�����ֵ�ķ�Χ
	POSITION GetStartPosition() const	
	{
		return m_dict.begin();
	}

	//! \brief �жϴ����λ���Ƿ����ֵ�β��
	//! \param pos Ҫ�жϵ�λ��[in]��
	//! \return ����ѵ��ֵ�β�򷢻�true;���򷵻�false��
	OgdcBool IsEOF(POSITION pos) const	
	{
		return pos==m_dict.end();
	}

	//! \brief �õ�ָ��pos��rkey��Ԫ��,����pos�ƶ�����һ��λ��
	//! \param rNextPosition ָ����λ��[in]��
	//! \param rKey �õ���key[out]��
	//! \param rValue �õ���Ԫ��[out]��
	void GetNextAssoc(POSITION& rNextPosition,Key& rKey,T& rValue) const	
	{
		OGDCASSERT(!IsEOF(rNextPosition));		
		rKey = rNextPosition->first;
		rValue = rNextPosition->second;
		++rNextPosition;
	}

private:
	std::map<Key,T,Compare> m_dict;
};

}

#endif // !defined(AFX_OGDCDICT_H__EA6AD17F_452A_4C4B_9FA0_F79418967EB8__INCLUDED_)

