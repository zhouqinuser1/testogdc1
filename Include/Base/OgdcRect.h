//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcRect.h
//!  \brief ���ζ����� 
//!  \details  
//!  \attention һ��������Ļ����
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCRECT_H__389F8413_2C28_48F2_A87A_658DA28B5361__INCLUDED_)
#define AFX_OGDCRECT_H__389F8413_2C28_48F2_A87A_658DA28B5361__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcPoint.h"

namespace OGDC {
//!  \brief ���ζ����࣬�洢�˾��ε����Ͻǵ㡢���½ǵ��(x,y)���꣬����ֵΪOgdcInt�͡�
class BASE_API OgdcRect  
{
public:
	//! \brief �������Ͻǵ��x������
	OgdcInt left;
	//! \brief �������Ͻǵ��y������
	OgdcInt top;
	//! \brief �������½ǵ��x������
	OgdcInt right;
	//! \brief �������½ǵ��y������
	OgdcInt bottom;		

public:

	//! \brief 		ȱʡ���캯��
	OgdcRect();	

	//! \brief 		ȱʡ��������
	~OgdcRect();	

	//! \brief 		���캯��һ����ά���ζ���
	//! \param 		nLeft	�������Ͻǵ��x������
	//! \param 		nTop	�������Ͻǵ��y������
	//! \param 		nRight	�������½ǵ��x������
	//! \param 		nBottom	�������½ǵ��y������
	//! \remarks 	��ȷ��nLeft<nRight,nTop<nBottom
	OgdcRect(OgdcInt nLeft,OgdcInt nTop,OgdcInt nRight,OgdcInt nBottom);
	
	//! \brief 		���ι��캯��
	//! \param 		pnt	���Ͻ�����
	//! \param 		sz	���εĴ�С	
	OgdcRect(const OgdcPoint& pnt,const OgdcSize& sz);

	//! \brief 		���ι��캯��
	//! \param 		pntTL	���Ͻ������
	//! \param 		pntBR   ���½������	
	OgdcRect(const OgdcPoint& pntTL,const OgdcPoint& pntBR);	
 	
	//! \brief 		���� =
    OgdcRect& operator=(const OgdcRect& rc);

	//! \brief 		���� ==
	friend BASE_API OgdcBool operator==(const OgdcRect& rcStart,const OgdcRect& rcEnd);

	//! \brief 		���� !=
	friend BASE_API OgdcBool operator!=(const OgdcRect& rcStart,const OgdcRect& rcEnd);
	
	//! \brief 		���þ��β���
	//! \param 		nLeft	�������Ͻǵ��x������
	//! \param 		nTop	�������Ͻǵ��y������
	//! \param 		nRight	�������½ǵ��x������
	//! \param 		nBottom	�������½ǵ��y������
	void SetRect(OgdcInt nLeft,OgdcInt nTop,OgdcInt nRight,OgdcInt nBottom);

	//! \brief 		���þ��β���
	//! \param 		pntTL	���Ͻ�����
	//! \param 		pntBR	���½�����	
	void SetRect(const OgdcPoint& pntTL,const OgdcPoint& pntBR);

	//! \brief 		��������Ϊ��
	//! \remarks 	���Ͻǡ����½ǵ����궼��Ϊ0
	void SetEmpty();

	//! \brief 		�жϾ����Ƿ�Ϊ�ջ��Ƿ�Ϸ�
	//! \return 	����Ϊ�շ���true�����β�Ϊ�շ���false
	//! \remarks 	���������left<right,top<bottom���򣬷���true����Ϊ����Ϊ�ա�
	OgdcBool IsEmpty() const;

	//! \brief 		�����Ƿ�Ϊδ��ʼ��
	//! \return 	�������left==right==top==bottom==0�����򷵻�true�����򣬷���false
	OgdcBool IsNull() const;

	//! \brief 		���εĿ��
	//! \return 	����right-left��ֵ(����)
	OgdcInt Width() const;

	//! \brief 		���εĸ߶�
	//! \return 	����top-bottom��ֵ(����)
	OgdcInt  Height() const;

	//! \brief 		��ȡ���ε����Ͻǵ�
	OgdcPoint& TopLeft();

	//! \brief 		��ȡ���ε����Ͻǵ�
	//! \remarks 	������ζ���Ϊconst���ͣ��򽫵��ñ��ӿ�
	const OgdcPoint& TopLeft() const;	

	//! \brief 		��ȡ�������½������
	OgdcPoint& BottomRight();		

	//! \brief 		��ȡ�������½������
	//! \remarks 	������ζ���Ϊconst���ͣ��򽫵��ñ��ӿ�
	const OgdcPoint& BottomRight() const;
	
	//! \brief 		��ȡ���ε����ĵ�
	OgdcPoint CenterPoint() const;
	
	//! \brief 		��ȡ���εĴ�С
	OgdcSize Size() const;

	//! \brief 		����left��right��ֵ
	void SwapLeftRight();

	//! \brief 		����top��bottom��ֵ	
	void SwapTopBottom();	

	//! \brief 		�жϵ��Ƿ��ھ�����
	//! \param 		pnt	�����
	//! \return		�����ھ����л��ھ��α߽��ϣ��򷵻�true�����򷵻�false��
	OgdcBool PtInRect(const OgdcPoint& pnt) const;

	//! \brief 		�жϵ�ǰ�����Ƿ��������rc
	//! \param 		rc ����
	//! \return		����ǰ���ΰ�������rc���򷵻�ture�����򣬷���false��
	//! \image html Contains.png
	OgdcBool Contains(const OgdcRect& rc) const;

	//! \brief 		�жϵ�ǰ�����Ƿ񱻾���rc����
	//! \param 		rc	����
	//! \return		����ǰ���α�����rc�������򷵻�ture�����򣬷���false��
	//! \image html within.png
	OgdcBool Withins(const OgdcRect& rc) const;

	//! \brief 		�жϵ�ǰ�����Ƿ������rc�ཻ
	//! \param 		rc	����
	//! \returen	�ཻ����true�����򣬷���false��
	//! \image html Intersect2.png
	OgdcBool Intersects(const OgdcRect& rc) const;


	//! \brief 		�淶���Σ�ȷ��left<=right,top<=bottom	
	void Normalize();
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		nX	������ƫ����
	//! \param 		nY	������ƫ����	
	void Offset(OgdcInt nX,OgdcInt nY);
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		sz	��������ƫ����	
	void Offset(const OgdcSize& sz);
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		pnt	��������ƫ����	
	void Offset(const OgdcPoint& p);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nMargin	���ݷŴ���� 	
	void Inflate(OgdcInt nMargin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nHormargin	������Ŵ����
	//! \param 		nVermargin	������Ŵ����	
	void Inflate(OgdcInt nHorMargin,OgdcInt nVerMargin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nLeftMargin	���Ͻǵ���x�������ƫ����
	//! \param 		nTopMargin	���Ͻǵ���y�����ϵ�ƫ����
	//! \param 		nRightMargin    ���½ǵ���x�����ҵ�ƫ����
	//! \param 		nBottomMargin	���½ǵ���y�����µ�ƫ����
	void Inflate(OgdcInt nLeftMargin,OgdcInt nTopMargin,OgdcInt nRightMargin,OgdcInt nBottomMargin);
	
	//! \brief 		�Ծ��ν�����С
	//! \param 		nMargin	������С����	
	void Deflate(OgdcInt nMargin);

	//! \brief 		�Ծ��ν�����С
	//! \param 		nHormargin	��������С����
	//! \param 		nVermargin	��������С����	
	void Deflate(OgdcInt nHorMargin,OgdcInt nVerMargin);

	//! \brief 		�Ծ��ν�����С
	//! \param 		nLeftMargin	���Ͻǵ���x�����ҵ�ƫ����
	//! \param 		nTopMargin	���Ͻǵ���y�����µ�ƫ����
	//! \param 		nRightMargin ���½ǵ���x�������ƫ����	
	//! \param 		nBottomMargin ���½ǵ���y�����ϵ�ƫ����	
	void Deflate(OgdcInt nLeftMargin,OgdcInt nTopMargin,OgdcInt nRightMargin,OgdcInt nBottomMargin);

	//! \brief 		���κϲ�
	//! \param 		pnt	�ϲ��ĵ�
	//! \image html union.png
	void Union(const OgdcPoint& pnt);

	//! \brief 		���κϲ�
	//! \param 		rc ������ԭ���κϲ��ľ���rc	
	//! \image html union2.png
	void Union(const OgdcRect& rc);	

	//! \brief 		������
	//! \param 		rc ������ԭ�����󽻵ľ���rc
	//! \image html Intersect2.png
	void Intersection(const OgdcRect& rc);

};

}

#endif // !defined(AFX_OGDCRECT_H__389F8413_2C28_48F2_A87A_658DA28B5361__INCLUDED_)

