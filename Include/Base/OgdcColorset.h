//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)                
//                                                           
//!  \file OgdcColorset.h
//!  \brief ��ɫ������
//!  \attention 
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCCOLORSET_H__6FC58E88_B3CD_4B04_BC40_DEC2E08042FD__INCLUDED_)
#define AFX_OGDCCOLORSET_H__6FC58E88_B3CD_4B04_BC40_DEC2E08042FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ogdcdefs.h"
#include "OgdcArray.h"

namespace OGDC{

#define MAXCOLORCOUNT 0x7fff

//! \brief ������ɫ
typedef enum tagSM_ENUM_STOCK_GRADIENT_SET_STYLE
{
	//! \brief ��->��
	gtBlackWhite,
	//! \brief ��->��
	gtRedWhite,	
	//! \brief ��->��
	gtGreenWhite,
	//! \brief ��->��
	gtBlueWhite,
	//! \brief ��->��
	gtYellowWhite,
	//! \brief �ۺ�->��
	gtPinkWhite,
	//! \brief ��->��
	gtCyanWhite,
	//! \brief ��->��
	gtRedBlack,	
	//! \brief ��->��
	gtGreenBlack,
	//! \brief ��->��
	gtBlueBlack,
	//! \brief ��->��
	gtYellowBlack,
	//! \brief �ۺ�->��
	gtPinkBlack,
	//! \brief ��->��
	gtCyanBlack,
	//! \brief ��->��
	gtYellowRed,
	//! \brief ��->��
	gtYellowGreen,
	//! \brief ��->��
	gtYellowBlue,
	//! \brief ��->��
	gtGreenBlue,
	//! \brief ��->��
	gtGreenRed,	
	//! \brief ��->��
	gtBlueRed,
	//! \brief ��->��			
	gtPinkRed,
	//! \brief ��->��			
	gtPinkBlue,
	//! \brief ��->��			
	gtCyanBlue,
	//! \brief ��->��			
	gtCyanGreen,
	//! \brief �ʺ�
	gtRainbow,
	//! \brief ��->�ۻ�->������				
	gtGreenOrangeViolet,
	//! \brief ���ν���,������ά��ʾЧ���Ϻ�
	gtTerrain,
	//! \brief ���׽���			
	gtSpectrum				
}OGDC_ENUM_STOCK_GRADIENT_SET_STYLE;	

//!  \brief ��ɫ������
class BASE_API OgdcColorset:public OgdcArray<OgdcColor>
{
public:
	//!  \brief ��ɫ������Ĭ�Ϲ��캯��
	OgdcColorset();
	//!  \brief ��ɫ������Ĭ����������
	~OgdcColorset();  
	//!  \brief ��ɫ�����࿽�����캯��
	OgdcColorset(const OgdcColorset& colorset);
	//!  \brief ����=
	OgdcColorset& operator=(const OgdcColorset& colorset);
	//!  \brief ������ɫ������ɫ��
	void SetColorSize(OgdcInt nSize);

public:
	//! \brief 		ָ����ɫ�����������ɫ
	//! \param 		nCount  ��ɫ��
	//! \param 		nIndex  ��ɫ������
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	OgdcInt MakeStockRandom(OgdcInt nCount, OgdcInt nIndex,OgdcBool bReverse = FALSE);
	
	//! \brief 		�����������ɫ
	//! \param 		nCount			��ɫ��
	//! \param 		btRedStart		Red������ʼֵ
	//! \param 		btRedEnd		Red������ֵֹ
	//! \param 		btGreenStart    Green������ʼֵ
	//! \param 		btGreenEnd		Green������ֵֹ
	//! \param 		btBlueStart		Blue������ʼֵ
	//! \param 		btBlueEnd		Blue������ֵֹ
	//! \param 		FALSE			�Ƿ�Ҷ�
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	OgdcInt MakeRandom(OgdcInt nCount, OgdcByte btRedStart,OgdcByte btRedEnd,
								OgdcByte btGreenStart, OgdcByte btGreenEnd,
								OgdcByte btBlueStart,OgdcByte btBlueEnd,
								OgdcBool bIsGray = FALSE);

	//! \brief 		ָ����ɫ���ɵȾཥ��ɫ��ɫ��
	//! \param 		nCount					��ɫ��
	//! \param 		nStockGradientStyle     ��ɫ������
	//! \param 		bReverse=FALSE			�Ƿ���
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	OgdcInt MakeStockGradient(OgdcInt nCount, OGDC_ENUM_STOCK_GRADIENT_SET_STYLE nStockGradientStyle, OgdcBool bReverse=FALSE);
	
	//! \brief 		���ɵȾཥ��ɫ��ɫ��
	//! \param 		&arrayControlColors  
	//! \param 		&arrayIntervals
	//! \remarks 	�������Ƶ�ǵȾཥ����ɫ�������У�arrayControlColorsΪ���Ƶ���ɫ����,
	//!				arrayIntervals�����¼ÿ�������Ƶ���ɫ֮�����ɫ����������Ϊ0����ˣ�
	//!				arrayIntervals����Ĵ�С�������arrayControlColors�����С��ȥһ������
	//!				arrayIntervals.GetSize()+1 == arrayControlColors.GetSize()������ɹ���
	//!				�������������ɵ���ɫ���ϴ�С���ô�СӦ�õ���arrayIntervals�и���֮�͡�
	OgdcInt MakeGradient(OgdcColorset &arrayControlColors, OgdcArray<OgdcInt> &arrayIntervals);
	

	//! \brief 		�������Ƶ�Ⱦཥ����ɫ��
	//! \param 		nCount				Ҫ���ɵ���ɫ�����е���ɫ����
	//! \param 		&arrayCotrolColors	���Ƶ���ɫ����
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ�	
	OgdcInt MakeGradient(OgdcInt nCount, OgdcColorset &arrayCotrolColors);
		

	//! \brief 	    �������Ƶ�Ⱦཥ����ɫ��	
	//! \param 		nCount		��ɫ����	
	//! \param 		colorStart  ��ʼ��ɫֵ
	//! \param 		colorEnd	������ɫֵ
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ���	
	OgdcInt MakeGradient(OgdcInt nCount, OgdcColor clrStart, OgdcColor clrEnd);

	//! \brief	�����������ɫ
	OgdcInt MakeRandom(OgdcInt nCount);

	//! \brief 		�����������ɫ
	//! \param 		nCount				Ҫ���ɵ���ɫ��������ɫ����
	//! \param 		&arrayCotrolColors	���Ƶ���ɫ����
	//! \remarks 	�������0��ʾ������ɫ���ϲ��ɹ�	
	//added by zhengyl 2011-2-17
	OgdcInt MakeRandom(OgdcInt nTotalCount, OgdcColorset &arrayCotrolColors);

	
};

}

#endif // !defined(AFX_OGDCCOLORSET_H__6FC58E88_B3CD_4B04_BC40_DEC2E08042FD__INCLUDED_)

