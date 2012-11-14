// OgdcElement.h: interface for the OgdcElement class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcElement.h
//!  \brief ���ζ������
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCELEMENT_H__D804932C_6A86_4E0B_8EE6_B114437AA9D4__INCLUDED_)
#define AFX_OGDCELEMENT_H__D804932C_6A86_4E0B_8EE6_B114437AA9D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base/OgdcStyle.h"
#include "Base/OgdcRect2D.h"
#include "Base/OgdcArray.h"

namespace OGDC {

//!  \brief ���ζ������
class ELEMENT_API OgdcElement  
{
public:
    //! \brief element����
	//! \remarks 0-10000Ϊ�ڲ�Ԥ����10000����Ϊ�û���չ��
	enum Type
	{
		//! \brief ��
		ElemNull			=0,
		//! \brief ��
		ElemPoint			=1,
		//! \brief ���
		ElemMultiPoint		=2,
		//! \brief ��
		ElemLine			=3,
		//! \brief ��
		ElemRegion			=5,
		//! \brief �ı�
		ElemText			=7,
		//! \brief ���Σ�֧����б
		ElemRect			=12,
		//! \brief Բ�Ǿ��Σ�֧����б
		ElemRectRound		=13,
		//! \brief Բ
		ElemCircle			=15,
		//! \brief ��Բ��֧����б
		ElemEllipse			=20,
		//! \brief ��Բ������
		ElemPie				=21,
		//! \brief ��Բ������
		ElemChord			=23,
		//! \brief Բ��
		ElemArc				=24,
		//! \brief ��Բ��
		ElemEllipticArc		=25,
		//! \brief Cardinal����,��֤����һ��ͨ�����Ƶ�
		ElemCardinal		=27,
		//! \brief DGN curve������
		ElemCurve			=28,
		//! \brief ���ξ���B��������
		ElemBSpline			=29,
		//! \brief �̶��ߣ�����������ϵ���ߣ�
		ElemLineM			=35,
		//! \brief ��ά��
		ElemPoint3D			=101,
		//! \brief ��ά���
		ElemMultiPoint3D	=102,
		//! \brief ��ά��
		ElemLine3D			=103,
		//! \brief ��ά��
		ElemRegion3D		=105,
		//! \brief ���϶���
		ElemCompound		=1000,
		//! \brief �û��������
		ElemUser			=1001,	
	};

public:
	//!  \brief ���ζ������Ĭ�Ϲ��캯��
	OgdcElement();
	//!  \brief ���ζ������Ĭ����������
	virtual ~OgdcElement();

public:
	//! \brief  �õ�Element���͡�
	virtual OgdcInt GetType() const=0;

	//! \brief  �õ�������ά���������0ά����1ά����2ά���ı�-1ά��
	virtual OgdcInt GetStyleDimension() const=0;		

	//! \brief  �õ������������
	virtual OgdcRect2D GetBounds();	

public:
	//! \brief 	���ζ���ID����ȡ������ʱҪ��֤Ψһ��
	OgdcInt m_nID;
	//! \brief  0ά��1ά��2ά��-1ά���ζ���ķ��ά����
	OgdcStyle* m_pStyle;
	//! \brief	�����������
	OgdcRect2D m_rcBounds;			

};

}

#endif // !defined(AFX_OGDCELEMENT_H__D804932C_6A86_4E0B_8EE6_B114437AA9D4__INCLUDED_)

