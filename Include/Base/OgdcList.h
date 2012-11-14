//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)              
//                                                           
//!  \file OgdcList.h
//!  \brief List����ģ���� 
//!  \details  �ڲ�����STL��Listʵ��
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCLIST_H__E90FD10D_6701_47C1_8726_BD749DE72C09__INCLUDED_)
#define AFX_OGDCLIST_H__E90FD10D_6701_47C1_8726_BD749DE72C09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/ogdcdefs.h"
#include <list>
#include <algorithm>

namespace OGDC {

//! \brief ����ģ����
//�ӿڲο�MFC��CList,�ڲ�����stl��listʵ��
template<typename T>
class OGDCEXPORT OgdcList
{
public:
	//typedef typename std::list<T>::iterator POSITION;
	//! \brief ����ָʾԪ�����б���λ�õ�ֵ
	typedef typename std::list<T>::iterator STDPosition;
	//! \brief ��OgdcList�ж�λ�õ���,����ֱ�ӹ���,����ͨ��OgdcList�����в���.
	struct POSITION
	{
		friend class OgdcList<T>;
	public:
		POSITION() {
			bIsBOF = false;
		}
	private:
		STDPosition it;
		// �Ƿ��ѵ�����β
		// OgdcBool bIsEOF;
		//! \brief �Ƿ��ѵ�����ͷ
		OgdcBool bIsBOF; 

		POSITION(STDPosition pos, OgdcBool bisBOF=false){
			this->it = pos;
			this->bIsBOF = bisBOF;
		}
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcList()
	{
	}

	//! \brief �� std::list ���й���ĺ���
	OgdcList(const std::list<T> &lst) : m_list(lst.size())
	{
		std::copy(lst.begin(), lst.end(), m_list.begin());
	}
	
	//! \brief �õ�Ԫ�ظ���
	OgdcInt GetCount() const
	{
		return (OgdcInt)m_list.size();
	}

	//! \brief �ж��Ƿ�Ϊ��
	//! \return Ϊ�շ���true;��Ϊ�շ���false
	OgdcBool IsEmpty() const
	{
		return m_list.empty();	
	}

	//! \brief �õ�����ͷ��Ԫ��
	//! \return Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
	T& GetHead()
	{
		OGDCASSERT(!IsEmpty());
		return m_list.front();
	}

	//! \brief �õ�����ͷ��Ԫ��
	//! \return Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
    const T& GetHead() const
	{
		OGDCASSERT(!IsEmpty());
		return m_list.front();
	}

	//! \brief �õ�����β��Ԫ��
	//! \return Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
    T& GetTail()
	{
		OGDCASSERT(!IsEmpty());
		return m_list.back();
	}

	//! \brief �õ�����β��Ԫ��
	//! \return Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
    const T& GetTail() const
	{
		OGDCASSERT(!IsEmpty());
		return m_list.back();
	}

	//! \brief �Ƴ�����ͷ��Ԫ��
	//! \return ���ر��Ƴ���Ԫ�ء�Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
	T RemoveHead()
	{
		OGDCASSERT(!IsEmpty());
		T f=m_list.front();
		m_list.pop_front();
		return f;
	}

	//! \brief �Ƴ�βԪ��
	//! \return ���ر��Ƴ���Ԫ�ء�Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
    T RemoveTail()
	{
		OGDCASSERT(!IsEmpty());
		T t=m_list.back();
		m_list.pop_back();
		return t;
	}

	//! \brief ������ͷ���Ԫ��
	//! \param newElement ����ӵ�Ԫ��
	//! \return �������Ԫ���������е�λ��(Position)��
	POSITION AddHead(const T& newElement)
	{
		m_list.push_front(newElement);
		return m_list.begin();
	}

	//! \brief ������β���Ԫ��
	//! \param newElement ����ӵ�Ԫ��
	//! \return �������Ԫ���������е�λ��(Position)��
    POSITION AddTail(const T& newElement)
	{
		m_list.push_back(newElement);
		return --m_list.end();
	}

	//! \brief ������ͷ���һ������
	//! \param newList ����ӵ�����
	void AddHead(const OgdcList<T>& newList)
	{
		//OGDCASSERT(pNewList);
		m_list.insert(m_list.begin(),newList.m_list.begin(),newList.m_list.end());
	}

	//! \brief ������β������һ������
	//! \param newList Ҫ����ӵ�����
    void AddTail(const OgdcList<T>& newList)
	{
		//OGDCASSERT(pNewList);
		m_list.insert(m_list.end(),newList.m_list.begin(),newList.m_list.end());
	}
	
	//! \brief �Ƴ�����������Ԫ��
	void RemoveAll()
	{
		m_list.clear();
	}

	//! \brief �õ�����ͷ��λ��
	//! \return ������Ϊ�գ���˵������Ϊ��
	POSITION GetHeadPosition() const
	{				
		// return const_cast<UGList<T>*>(this)->begin();
		// ����������˼��: �Ȱ�m_list�ĳ�����ȥ��, Ȼ��õ�ָ��begin�ĵ�����
		// ������������Ƿ�const����, Ȼ�����POSITION������.
		// �������кü����ط��õ������ַ���,
		return POSITION( (const_cast< std::list<T>& >(m_list)).begin());
	}

	//! \brief �õ�����β��λ��
	//! \return ������Ϊ�գ���˵������Ϊ��
    POSITION GetTailPosition() const
	{
		// return --(const_cast<UGList<T>*>(this)->end());
		STDPosition itEnd = const_cast<std::list<T>&>(m_list).end();
		if (GetCount() == 0) {
			return POSITION(itEnd, true);
		}
		return POSITION(--itEnd);
	}

	//! \brief �ж��Ƿ��ѵ�����β
	//! \param pos Ҫ�жϵ�λ��
	//! \return �ѵ�����β����true;���򷵻�false
	OgdcBool IsEOF(POSITION pos) const
	{
		return pos.it==const_cast<std::list<T>&>(m_list).end();
	}

	//! \brief �ж�ĳλ���Ƿ��ѵ�����ͷ
	//! \param pos Ҫ�жϵ�λ��
	//! \return �ѵ�����ͷ����true;���򷵻�false
	OgdcBool IsBOF(POSITION pos) const
	{
		return pos.bIsBOF 
			|| (++pos.it==const_cast<std::list<T>&>(m_list).begin());
	}
	
	//! \brief ��ȡ�����е���һ��λ��
	//! \param pos[in][out] �����е�ָ��λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����,Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
	//! \remarks pos��Ӧ��λ�ò���������ͷ��������β

	T& GetNext(POSITION& pos)
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		return *pos.it++;
	}

	//! \brief ��ȡ�����е���һ��λ��
	//! \param pos[in][out] �����е�ָ��λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����,Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
    const T& GetNext(POSITION& pos) const
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		return *pos.it++;
	}

	//! \brief �õ������е���һ��λ��
	//! \param pos[in][out] �����е�ָ��λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����,Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
	//! \remarks pos��Ӧ��λ�ò���������ͷ��������β
    T& GetPrev(POSITION& pos)
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		if (pos.it == m_list.begin()) 
		{ // �����ͷ��, Ҫ��¼һ��, ���Ҳ�--��
			pos.bIsBOF = true; 
			return *pos.it;
		}
		return *pos.it--;
	}

	//! \brief �õ������е���һ��λ��
	//! \param pos[in][out] �����е�ָ��λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����,Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����
	//! \remarks pos��Ӧ��λ�ò���������ͷ��������β
    const T& GetPrev(POSITION& pos) const
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		if (pos.it == m_list.begin()) 
		{ // �����ͷ��, Ҫ��¼һ��, ���Ҳ�--��
			pos.bIsBOF = true; 
			return *pos.it;
		}
		return *pos.it--;
	}
	
	//! \brief �õ�������ָ��λ�õ�Ԫ��
	//! \param pos ָ��λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����,Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����	
	T& GetAt(POSITION pos)
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		return *pos.it;
	}

	//! \brief �õ�������ָ��λ�õ�Ԫ��
	//! \param pos ָ��λ��
	//! \return ���ش���λ�õ�Ԫ�ص�����,Tָ��������Ԫ�ص����ͣ��ɵ�����ָ����	
    const T& GetAt(POSITION pos) const
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		return *pos.it;
	}

	//! \brief ����������ָ��λ�õ�Ԫ��ֵ
	//! \param pos �����е�ָ��λ��
	//! \param newElement Ҫ���õ�Ԫ�ص���ֵ
	void SetAt(POSITION pos, const T& newElement)
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		*pos.it=newElement;
	}

	//! \brief �Ƴ�������ָ��λ�õ�Ԫ��
	//! \param pos ָ����λ��
    void RemoveAt(POSITION& pos)
	{
		OGDCASSERT(!(IsEOF(pos) || IsBOF(pos)));
		pos.it = m_list.erase(pos.it);
	}
	
	//! \brief ��������ָ��λ��֮ǰ����һ��Ԫ��
	//! \param pos Ҫ�����λ��
	//! \param newElement Ҫ�����Ԫ��
	//! \return ���ر�����Ԫ���������е�λ��
	POSITION InsertBefore(POSITION pos,const T& newElement)
	{
		OGDCASSERT(!IsBOF(pos));
		return m_list.insert(pos.it,newElement);
	}

	//! \brief ��������ָ��λ��֮�����һ��Ԫ��
	//! \param pos Ҫ�����λ��
	//! \param newElement Ҫ�����Ԫ��
	//! \return ���ر�����Ԫ���������е�λ��
    POSITION InsertAfter(POSITION pos,const T& newElement)
	{
		OGDCASSERT(!IsEOF(pos));
		return m_list.insert(++pos.it,newElement);
	}

	//! \brief ����Ԫ��ֵ����Ԫ������λ�ã�������ͷ��ʼ���ң�
	//! \param searchValue Ҫ���ҵ�Ԫ��
	//! \return ���ص�һ���ҵ���Ԫ�ص�λ��
	POSITION Find(const T& searchValue) const
	{
		return std::find(const_cast<std::list<T>&>(m_list).begin(),
			const_cast<std::list<T>&>(m_list).end(),searchValue);
	}

	//! \brief ����Ԫ��ֵ����Ԫ������λ�ã���ָ��λ��֮��ʼ���ң�ָ��λ�ò������ң���
	//! \param searchValue Ҫ���ҵ�Ԫ��
	//! \param startAfter ָ�����ҵ�λ��
	//! \return ���ص�һ���ҵ���Ԫ�ص�λ��
    POSITION Find(const T& searchValue, POSITION pos) const
	{
		OGDCASSERT(!IsEOF(pos));
		return std::find(++pos.it,const_cast<std::list<T>&>(m_list).end(),searchValue);
	}
	
	//! \brief �õ�ָ��������Ԫ�ص�λ��
	//! \param nIndex ָ���Ĳ��ҿ�ʼ������
	//! \return �����ҵ���Ԫ�ص�λ��; �����������δ�ҵ�,�򷵻�βλ��
    POSITION FindIndex(OgdcInt nIndex) const
	{		
		
		POSITION pos(const_cast<std::list<T>&>(m_list).begin());
		for(OgdcInt i=0;i<nIndex;i++)
		{
			if(++pos.it==const_cast<std::list<T>&>(m_list).end())
				break;
		}
		return pos;
	}

private:
	//! \brief �ڲ�ʵ�ֲ���stl��list
	std::list<T> m_list;
};

}

#endif // !defined(AFX_OGDCLIST_H__E90FD10D_6701_47C1_8726_BD749DE72C09__INCLUDED_)

