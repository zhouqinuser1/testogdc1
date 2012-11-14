//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)             
//                                                           
//!  \file OgdcArray.h
//!  \brief ������
//!  \details �ڲ�����STL��vectoryʵ��
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCARRAY_H__1058166B_E59F_4206_869F_109ECDC3EDE2__INCLUDED_)
#define AFX_OGDCARRAY_H__1058166B_E59F_4206_869F_109ECDC3EDE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ogdcdefs.h"
#include <vector>
#include <algorithm>

// ���Ծ��� "warning C4018: '<' : signed/unsigned mismatch", 
// Arrayʹ��size_t��Ϊ�����󣬻���������ľ��棬���ǵ�32λ��Ӧ�ò�Ӱ�죬Ϊ�˺��Ըþ���
#pragma warning (disable: 4018) 

namespace OGDC {

//! \brief ������
//�ڲ�����STL��vectorʵ��
template<typename T>
class OGDCEXPORT OgdcArray
{
public:
	//! \brief Ĭ�Ϲ��캯��������һ������Ϊ�������
	OgdcArray() 
	{
		m_nGrowSize=0;
	}	

	//! \brief ���캯�������쳤��ΪnSize������
	//! \param nSize ���鳤�ȣ�������ڵ���0
	//explicit�����������εĴ�����ת��Ϊ��������
	explicit OgdcArray(OgdcSizeT nSize) 
	{
		OGDCASSERT(nSize>=0);
		m_nGrowSize=0;   
		m_array.resize(nSize);
	}

	//! \brief ���쳤��ΪnSize������,����Ԫ�ص�ֵΪelem�е�ö��ֵ
	//! \param nSize ���鳤��, ������ڵ���0
	//! \param elem ����Ԫ�ص�Ĭ��ֵ
	OgdcArray(OgdcSizeT nSize, const T& elem)
	{
		OGDCASSERT(nSize>=0);
		m_array.resize(nSize,elem);
	}

	OgdcArray(const std::vector<T> &vect) : m_array(vect.size())
	{
		std::copy(vect.begin(), vect.end(), m_array.begin());
	}

public:
	//! \brief ��ȡ����ĳ���
	//! \return ��������ĳ��ȣ�����ֵ����Ϊ���͡�
	OgdcSizeT GetCapacity() const
	{
		return (OgdcSizeT)m_array.capacity();
	}

	//! \brief ��������ĳ���
	//! \param nCapacity ����ĳ���,������ڵ���0
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������, �����ӵĿռ䲻�����TYPE�Ĺ��캯����
	//! ���ԭ�пռ��ָ���Ĵ�, Ҳ�����ͷſռ䡣
	void SetCapacity(OgdcSizeT nCapacity)
	{
		OGDCASSERT(nCapacity >= 0);
		m_array.reserve(nCapacity);
	}

	//! \brief ������ĩβ����һ��Ԫ�أ������鳤������1.
	//! \param newElement ����Ԫ��
	//! \return ��������Ԫ�ص�����ֵ
	//! \remarks �����Ԫ�غ󣬳�������������������鳤�Ȼ��Զ������Զ���������������
	OgdcSizeT Add(const T& newElement)
	{    
		if((m_array.size()>=m_array.capacity())&&(m_nGrowSize>0)) 
			m_array.reserve(m_array.capacity()+m_nGrowSize);      
		m_array.push_back(newElement);
		return (OgdcSizeT)m_array.size()-1;
	}
	//! \brief �����Զ�������
	//! \param nGrowSize �Զ�������
	//! \remarks ���������Զ������������������Ԫ�غ󣬳��ȳ���������������ᰴ���Զ�������������������
	void SetGrowSize(OgdcSizeT nGrowSize=10)
	{
		m_nGrowSize=nGrowSize;
	}
	//! \brief ��ȡ�Զ�������
	//! \return ����������Զ�������������ֵ����Ϊ���͡�
    OgdcSizeT GetGrowSize() const
	{   
		return m_nGrowSize;
	}

	//! \brief ������ĩβ׷��Ԫ��
	//! \param pData Ҫ׷�ӵ�Ԫ��
	//! \param nSize Ҫ׷�ӵ�Ԫ�ظ���
	//! \return ���ؼ���Ԫ�ص���ʼ����
	OgdcSizeT Append(const T* pData, OgdcSizeT nSize)
	{
		OgdcSizeT nOldSize=(OgdcSizeT)m_array.size();
		m_array.insert(m_array.end(),pData,pData+nSize);
		return nOldSize;
	}

	//! \brief ������ĩβ׷�����顣
	//! \brief src Ҫ׷�ӵ�����
	//! \return ����׷���������ʼ����������ֵ����Ϊ���͡�
	OgdcSizeT Append(const OgdcArray<T>& src)
	{
		OgdcSizeT nOldSize=(OgdcSizeT)m_array.size();
		m_array.insert(m_array.end(),src.m_array.begin(),src.m_array.end());
		return nOldSize;
	}

	//! \brief ��������
	//! \param src ���������
	//! \remarks ����һ�������Ԫ�ص���һ�������С���ԭ����������ֵ����ᱻ���ǡ�	
	void Copy(const OgdcArray<T>& src)
	{
		if(this == &src)
			return ;

		*this=src;
	}

	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����)
	const T* GetData() const
	{
		if (GetSize() > 0)
		{
			return &(*m_array.begin());
		}
		else 
		{
			return NULL;
		}
	}

	//! \brief �õ������ڲ�ָ��(��ַ����)
	//! \return ���������ڲ�ָ��(��ַ����)
	T* GetData()
	{
		if (GetSize() > 0)
		{
			return &(*m_array.begin());
		}
		else 
		{
			return NULL;
		}
	}

	//! \brief ��ȡ���Ŀ����±�ֵ 
	//! \return �����������±�ֵ
	//! \remarks �������Ϊ��, �򷵻� -1
	OgdcSizeT GetUpperBound() const
	{
		return (OgdcSizeT)m_array.size()-1;
	}
		
	//! \brief ��ȡ�����ڵ�Ԫ�ظ���
	OgdcSizeT GetSize() const
	{
		return (OgdcSizeT)m_array.size();
	}

	//! \brief �ͷŶ�����ڴ�ռ�
	//! \attention �ڲ����ÿ�������һ����ͬ������,Ȼ�󽻻��ķ�ʽʵ�ֵ�,
	//! ��˻��ƻ�֮ǰ���ڴ�, ����֮ǰGetData��ָ���Ϊ�Ƿ�, �ʶ����Ƽ�ʹ��.
	void FreeExtra()
	{
		if(m_array.capacity()>m_array.size()) {
			std::vector<T> vctTemp(m_array.begin(),m_array.end());
			m_array.swap(vctTemp);
		}
	}

	//! \brief �õ�������ָ��λ��Ԫ�ص�����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�����
	T& ElementAt(OgdcSizeT nIndex)
	{
		OGDCASSERT(nIndex>=0 && nIndex<(OgdcSizeT)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief �õ�������ָ��λ��Ԫ�ص�const����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�const����
	const T& ElementAt(OgdcSizeT nIndex) const
	{
		OGDCASSERT(nIndex>=0 && nIndex<(OgdcSizeT)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief �õ�������ָ��λ��Ԫ�ص�����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�����
	T& operator[](OgdcSizeT nIndex)
	{
		OGDCASSERT(nIndex>=0 && nIndex<(OgdcSizeT)m_array.size());
		return m_array.at(nIndex);
	}

	//! \brief �õ�������ָ��λ��Ԫ�ص�const����
	//! \param nIndex ָ����λ��
	//! \return ���ظ�λ��Ԫ�ص�const����
	const T& operator[](OgdcSizeT nIndex) const
	{
		OGDCASSERT(nIndex>=0 && nIndex<(OgdcSizeT)m_array.size());
		return m_array.at(nIndex);
	}
	
	//! \brief �õ�ָ��λ��Ԫ��ֵ
	//! \param nIndex ָ����λ��/����ֵ
	//! \return ���ظ�λ��Ԫ�صĿ���
	T GetAt(OgdcSizeT nIndex) const
	{				
		OGDCASSERT(nIndex>=0 && nIndex<(OgdcSizeT)m_array.size());
		return m_array.at(nIndex);
	}
	
	//! \brief ��ָ��λ������Ԫ��ֵ(�滻ԭ��Ԫ��)
	//! \remarks ָ��λ�ñ��������鳤�ȷ�Χ֮��
	//! \param nIndex ָ����λ�� 
	//! \param newElement Ҫ���õ�Ԫ��
	void SetAt(OgdcSizeT nIndex, const T& newElement)
	{			
		OGDCASSERT(nIndex>=0 && nIndex<(OgdcSizeT)m_array.size());
		m_array.at(nIndex) = newElement;
	}
	
	//! \brief ��ָ��λ������Ԫ��(�滻ԭ��Ԫ��)
	//! \remarks ���ָ��λ�ô������鳤��,������Զ�����
	//! \param nIndex ָ����λ�� 
	//! \param newElement Ҫ���õ�Ԫ��
	void SetAtGrow(OgdcSizeT nIndex,const T& newElement)
	{
		OGDCASSERT(nIndex >= 0);		
		if(nIndex>=(OgdcSizeT)m_array.size())
		{
			m_array.resize(nIndex+1);
		}
		m_array.at(nIndex) = newElement;
	}
	
	//! \brief ���������ڿ����ɵ�Ԫ������
	//! \param nNewSize ָ�����µ�Ԫ�ظ���
	//! \remarks ���ԭ�пռ䲻��, �ڴ�ռ������, 
	//! ���ӵĿռ�����TYPE��Ĭ�Ϲ��캯��(�����newElement)��
	//! ���ԭ�пռ��ָ���Ĵ�, �����ͷſռ�,����ָ���Ŀռ�֮���Ԫ�ؾ���Ч�ˡ�
	//! ���Ҫǿ���ͷ��ڴ�,�����FreeExtra(),�ͷŶ�����ڴ�ռ䡣
	void SetSize(OgdcSizeT nNewSize)
	{
		OGDCASSERT(nNewSize>=0);
		if((nNewSize>(OgdcSizeT)m_array.capacity()) && (m_nGrowSize>0)) 
			m_array.reserve(m_array.capacity()+(nNewSize/m_nGrowSize+1)*m_nGrowSize);// ȷ���ܹ���֤�����Զ�����������
		m_array.resize(nNewSize);
	}	
	
	//! \brief �Ƴ�����Ԫ��,ͬʱ�ͷ��ڴ�ռ�
	void RemoveAll()
	{
		m_array.clear(); 		
		FreeExtra();
	}

	//! \brief �Ƴ�������ָ��λ��,ָ��������Ԫ��
	//! \remarks ָ��λ�ñ��������鷶Χ��
	//! \param nIndex Ҫ�Ƴ���Ԫ��λ��
	//! \param nCount Ҫ�Ƴ���Ԫ�ظ���,Ĭ��Ϊ1
	//! \return �����Ƴ���Ԫ�ظ���
	OgdcSizeT RemoveAt(OgdcSizeT nIndex,OgdcSizeT nCount=1)
	{
		OGDCASSERT(nIndex>=0);
		nCount = OGDCMAX(nCount,0);
		if(nCount == 0)
		{
			return 0;
		}

		OgdcSizeT nSize=(OgdcSizeT)m_array.size();
		if(nIndex >= nSize)
		{
			return 0;
		}

		OgdcSizeT nEnd=nIndex+nCount;
		if(nEnd>nSize)
		{
			nEnd=nSize;
		}
		m_array.erase(m_array.begin()+nIndex,m_array.begin()+nEnd);
		return nEnd - nIndex;
	}
	
	//! \brief ��������ָ��λ��֮ǰ������ָ��������Ԫ��
	//! \param nIndex ָ����λ��
	//! \param newElement ָ����Ԫ��
	//! \param nCount Ҫ�����Ԫ�ظ�����Ĭ��Ϊ1
	//! \remarks ���ָ��λ�ò������鷶Χ�ڣ����Զ�������[0,size]
	void InsertAt(OgdcSizeT nIndex,const T& newElement,OgdcSizeT nCount=1)
	{				
		OgdcSizeT nSize=(OgdcSizeT)m_array.size();
		nIndex=OGDCCLAMP(0,nIndex,nSize);
		if(nCount>0) 
		{
			m_array.insert(m_array.begin()+nIndex,nCount,newElement);
		}				
	}

	//! \brief �������е�ָ��λ��֮ǰ������ָ��������Ԫ��
	//! \param nIndex ָ����λ��
	//! \param pNewElement ָ����Ԫ��ָ��
	//! \param nCount Ҫ�����Ԫ�ظ���
	//! \remarks ���ָ��λ�ò������鷶Χ�ڣ����Զ�������[0,size]
	void InsertAt(OgdcSizeT nIndex,const T* pNewElement,OgdcSizeT nCount)
	{				
		OgdcSizeT nSize=(OgdcSizeT)m_array.size();
		nIndex=OGDCCLAMP(0,nIndex,nSize);
		if(nCount>0 && pNewElement) 
		{
			m_array.insert(m_array.begin()+nIndex,pNewElement,pNewElement+nCount);
		}				
	}
	
	//! \brief ��ָ��λ�ã�����һ���µ�����
	//! \param nIndex ָ����λ��
	//! \param newArray Ҫ���������
	//! \remarks ���ָ��λ�ò������鷶Χ�ڣ����Զ�������[0,size]
	void InsertAt(OgdcSizeT nIndex, const OgdcArray<T>& newArray)
	{		
		OgdcSizeT nSize=(OgdcSizeT)m_array.size();
		nIndex=OGDCCLAMP(0,nIndex,nSize);
		m_array.insert(m_array.begin()+nIndex,newArray.m_array.begin(),newArray.m_array.end());
	}

	//! \brief �õ��ڲ�STL����, �ⲿһ�㲻Ҫʹ��
	//! \return �����ڲ�STL����
	std::vector<T>& Inner()
	{
		return m_array;
	}

private:
	//! \brief �ڲ�����STL��vectorʵ��
	std::vector<T> m_array;
	//! \brief ������Զ�������
	OgdcSizeT m_nGrowSize;
};

}

#endif // !defined(AFX_OGDCARRAY_H__1058166B_E59F_4206_869F_109ECDC3EDE2__INCLUDED_)

