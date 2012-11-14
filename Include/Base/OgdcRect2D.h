//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)               
//                                                           
//!  \file OgdcRect2D.h
//!  \brief 2D������ 
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCRECT2D_H__A3169E94_5510_4729_B37C_17CD30FC987B__INCLUDED_)
#define AFX_OGDCRECT2D_H__A3169E94_5510_4729_B37C_17CD30FC987B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcPoint2D.h"

namespace OGDC {
//!  \brief ���ζ����࣬�洢�˾��ε����Ͻǵ㡢���½ǵ��(x,y)���꣬����ֵΪOgdcDouble���͡�
class BASE_API OgdcRect2D  
{
public:
	//! \brief ������߽�
	OgdcDouble left;
	//! \brief �����ϱ߽�
	OgdcDouble top;
	//! \brief �����ұ߽硣left<right
	OgdcDouble right;
	//! \brief �����±߽硣bottom < top
	OgdcDouble bottom;

public:

	//! \brief ���캯��һ����ά���ζ���
	OgdcRect2D();

	//! \brief 		ȱʡ���캯��
	~OgdcRect2D();
	
	//! \brief 		���캯��һ����ά���ζ���
	//! \param 		nLeft	�������Ͻǵ��x������
	//! \param 		nTop	�������Ͻǵ��y������
	//! \param 		nRight	�������½ǵ��x������
	//! \param 		nBottom	�������½ǵ��y������
	//! \remarks 	��ȷ��nLeft<nRight,nTop<nBottom
	OgdcRect2D(OgdcDouble dLeft,OgdcDouble dTop,OgdcDouble dRight,OgdcDouble dBottom);

	//! \brief 		���캯��һ����ά���ζ���
	//! \param 		pnt	���½�����
	//! \param 		sz	���εĴ�С
	OgdcRect2D(const OgdcPoint2D& pnt,const OgdcSize2D& sz);

	//! \brief 		���캯��һ����ά���ζ���
	//! \param 		pntTL	���Ͻ�����
	//! \param 		pntBR   ���½�����
	OgdcRect2D(const OgdcPoint2D& pntTL,const OgdcPoint2D& pntBR);	

	//! \brief 		���� =
    OgdcRect2D& operator=(const OgdcRect2D& rc);

	//! \brief 		���� ==
	friend BASE_API OgdcBool operator==(const OgdcRect2D& rcStart,const OgdcRect2D& rcEnd);

	//! \brief 		���� !=
	friend BASE_API OgdcBool operator!=(const OgdcRect2D& rcStart,const OgdcRect2D& rcEnd);
	
	
	//! \brief 		���þ��β���
	//! \param 		dLeft	�������Ͻǵ��x������
	//! \param 		dTop	�������Ͻǵ��y������
	//! \param 		dRight	�������½ǵ��x������
	//! \param 		dBottom	�������½ǵ��y������
	void SetRect(OgdcDouble dLeft,OgdcDouble dTop,OgdcDouble dRight,OgdcDouble dBottom);
	
	//! \brief 		���þ��β���
	//! \param 		pntTL	���Ͻ�����
	//! \param 		pntBR	���½�����
	void SetRect(const OgdcPoint2D& pntTL,const OgdcPoint2D& pntBR);

	//! \brief 		��������Ϊ��
	//! \remarks 	���Ͻǡ����½ǵ����궼��Ϊ0
	void SetEmpty();

	//! \brief 		�жϾ����Ƿ�Ϊ�ջ��Ƿ�Ϸ�
	//! \return 	����Ϊ�շ���true�����β�Ϊ�շ���false
	//! \remarks 	�������left=right,top=bottom���򣬷���true����Ϊ����Ϊ�ա�
	OgdcBool IsEmpty() const;

	//! \brief 		�����Ƿ�Ϊδ��ʼ��
	//! \return 	�������left==right==top==bottom==0�����򷵻�true�����򣬷���false
	OgdcBool IsNull() const;

	//! \brief 		���εĿ��
	//! \return 	����right-left��ֵ(����)
	OgdcDouble Width() const;

	//! \brief 		���εĸ߶�
	//! \return 	����top-bottom��ֵ(����)
	OgdcDouble  Height() const;
	
	//! \brief 		��ȡ���ε����Ͻǵ�
	OgdcPoint2D& TopLeft();

	//! \brief 		��ȡ���ε����Ͻǵ�
	//! \remarks 	������ζ���Ϊconst���ͣ��򽫵��ñ��ӿ�
	const OgdcPoint2D& TopLeft() const;	

	
	//! \brief 		��ȡ�������Ͻ������
	OgdcPoint2D TopRight() const;
	
	//! \brief 		��ȡ�������½������
	OgdcPoint2D& BottomRight();	
	
	//! \brief 		��ȡ�������½������
	//! \remarks 	������ζ���Ϊconst���ͣ��򽫵��ñ��ӿ�
	const OgdcPoint2D& BottomRight() const;

	//! \brief 		��ȡ�������½������
	OgdcPoint2D BottomLeft() const;
	
	
	//! \brief 		��ȡ���ε����ĵ�
	//! \remarks 	���ζԽ��ߵĽ���
	OgdcPoint2D CenterPoint() const;

	//! \brief 		��ȡ���εĴ�С
	OgdcSize2D Size() const;

	
	//! \brief 		����left��right��ֵ
	void SwapLeftRight();

	//! \brief 		����top��bottom��ֵ	
	void SwapTopBottom();	
	
	//! \brief 		�жϵ��Ƿ��ھ�����
	//! \param 		pnt	�����
	//! \return		�����ھ����л��ھ��α߽��ϣ��򷵻�true�����򷵻�false��
	OgdcBool PtInRect(const OgdcPoint2D& pnt) const;

	//! \brief 		�жϵ�ǰ�����Ƿ��������rc
	//! \param 		rc ����
	//! \return		����ǰ���ΰ�������rc���򷵻�ture�����򣬷���false��
	//! \image html Contains.png
	OgdcBool Contains(const OgdcRect2D& rc) const;

	//! \brief 		�жϵ�ǰ�����Ƿ񱻾���rc����
	//! \param 		rc	����
	//! \return		����ǰ���α�����rc�������򷵻�ture�����򣬷���false��
	//! \image html within.png
	OgdcBool Withins(const OgdcRect2D& rc) const;

	
	//! \brief 		�жϵ�ǰ�����Ƿ������rc�ཻ
	//! \param 		rc	����
	//! \returen	�ཻ����true�����򣬷���false��
	OgdcBool IsIntersect(const OgdcRect2D& rc) const;
	
	//! \brief 		�淶���Σ�ȷ��left<=right,top<=bottom	
	void Normalize();
	
	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		dX	������ƫ����
	//! \param 		dY	������ƫ����
	void Offset(OgdcDouble dX,OgdcDouble dY);

	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		sz	��������ƫ����
	void Offset(const OgdcSize2D& sz);

	//! \brief 		�Ծ��ν���ƫ��
	//! \param 		pnt	��������ƫ����
	void Offset(const OgdcPoint2D& pnt);
	
	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nMargin	���ݷŴ���� 	
	void Inflate(OgdcDouble dMargin);

	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		dHormargin	������Ŵ����
	//! \param 		dVermargin	������Ŵ����	
	void Inflate(OgdcDouble dHorMargin,OgdcDouble dVerMargin);
	
	//! \brief 		�Ծ��ν��зŴ�
	//! \param 		nLeftMargin	���Ͻǵ���x�������ƫ����
	//! \param 		nTopMargin	���Ͻǵ���y�����ϵ�ƫ����
	//! \param 		nRightMargin    ���½ǵ���x�����ҵ�ƫ����
	//! \param 		nBottomMargin	���½ǵ���y�����µ�ƫ����
	void Inflate(OgdcDouble nLeftMargin,OgdcDouble nTopMargin,OgdcDouble nRightMargin,OgdcDouble nBottomMargin);
	
	//! \brief 		�Ծ��ν�����С
	//! \param 		dMargin	������С����	
	void Deflate(OgdcDouble dMargin);
	
	//! \brief 		�Ծ��ν�����С
	//! \param 		dHorMargin	��������С����
	//! \param 		dVerMargin	��������С����
	void Deflate(OgdcDouble dHorMargin,OgdcDouble dVerMargin);

	
	//! \brief 		�Ծ��ν�����С
	//! \param 		dLeftMargin	���Ͻǵ���x�����ҵ�ƫ����
	//! \param 		dTopMargin	���Ͻǵ���y�����µ�ƫ����
	//! \param 		dRightMargin ���½ǵ���x�������ƫ����	
	//! \param 		dBottomMargin ���½ǵ���y�����ϵ�ƫ����	
	void Deflate(OgdcDouble dLeftMargin,OgdcDouble dTopMargin,OgdcDouble dRightMargin,OgdcDouble dBottomMargin);
	
	//! \brief 		���κϲ�
	//! \param 		pnt	�ϲ��ĵ�
	//! \image html union.png
	void Union(const OgdcPoint2D& pnt);
	
	//! \brief 		���κϲ�
	//! \param 		rc ������ԭ���κϲ��ľ���rc
	//! \image html union2.png
	void Union(const OgdcRect2D& rc);	
	
	//! \brief 		������
	//! \param 		rc ������ԭ�����󽻵ľ���rc
	//! \param		��ǰ����Ϊ��rc�󽻵Ľ������
	//! \image html Intersect2.png
	OgdcBool IntersectRect(const OgdcRect2D& rc);
	
	//! \brief 		������
	//! \param 		rc1 �����󽻵ľ���	
	//! \param 		rc2	�����󽻵ľ���
	//! \remarks	��ǰ����Ϊrc1����rc2�󽻺�Ľṹ���Ρ�
	//! \image html Interset.png
	OgdcBool IntersectRect(const OgdcRect2D& rc1,const OgdcRect2D& rc2);
	
	//! \brief 		��ǰ��������ת֮��ľ�����
	//! \param 		pntOrg ���ĵ�
	//! \param 		dbAngle ��ת�Ƕ�
	//! \image html union3.png
	void UnionRotate(const OgdcPoint2D &pntOrg, OgdcDouble dbAngle);
	
	//! \brief �ж�OgdcRect2D�����Ƿ���Ч
	OgdcBool IsValid() const;
	
	void InflateRect(OgdcDouble x, OgdcDouble y);
	
};

}

#endif // !defined(AFX_OGDCRECT2D_H__A3169E94_5510_4729_B37C_17CD30FC987B__INCLUDED_)

