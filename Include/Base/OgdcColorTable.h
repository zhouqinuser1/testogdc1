//////////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)           
//                                                           
//!  \file OgdcColorTable.h
//!  \brief �ֲ���ɫ��ɫ�� 
//!  \attention ��OgdcColorset�Ľ��,֧�ֲַ���ɫ�ͼ��������ɫ
//!   Copyright (c) 2007-2012 SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCCOLORTABLE_H__B6F4BBA2_614E_4B02_83B3_FA02C425A6EC__INCLUDED_)
#define AFX_OGDCCOLORTABLE_H__B6F4BBA2_614E_4B02_83B3_FA02C425A6EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ogdcdefs.h"
#include "OgdcString.h"
#include "OgdcArray.h"
#include "OgdcColorset.h"

namespace OGDC {
//!  \brief ��ɫ���� 
class BASE_API OgdcColorTable
{
public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcColorTable();
	//! \brief Ĭ����������
	~OgdcColorTable(); //�����Ӧ���������������
	//! \brief �������캯��
	//! \param 		colorTable ������������ɫ��
	OgdcColorTable(const OgdcColorTable& colorTable);
	//! \brief ���ز����� =
	//! \param 		colorTable ������������ɫ��
	OgdcColorTable& operator=(const OgdcColorTable& colorTable);

public:
    
	//! \brief 	�õ���ɫ��
	//! \return 	��ɫ��Ŀ
	OgdcInt GetSize() const;

	//! \brief 		������ɫ��
	//! \param 		nNewValue ��ɫ��
	void SetSize(OgdcInt nNewValue);

	//! \brief 		����ɫ������ɫ��
	//! \param 		clr	Ҫ��ӵ���ɫ��
	//! \return 	���ؽ����ɫ����С
	OgdcLong AddColor(OgdcColor clr);

	//! \brief 		����µ���ɫ(RGBģʽ)
	//! \param 		nRed ����ɫ����
	//! \param 		nGreen ����ɫ����
	//! \param 		nBlue ����ɫ����
	//! \return 	���ؽ����ɫ����С
	OgdcLong Add(OgdcUchar nRed, OgdcUchar nGreen, OgdcUchar nBlue);

	//! \brief 		��m_Colorset��������ɫ��colorset��	
	//! \param 		colorset Ŀ����ɫ��
	//! \return 	�����ɹ�������true������ʧ�ܷ���false
	//! \remark     ��colorset��Ϊ�գ���Ὣ������ٽ��е���
	OgdcBool ToColorset(OgdcColorset& colorset) const;

	//! \brief 		������ɫ��colorset��m_Colorset��
	//! \param 		colorset Դ��ɫ��
	//! \return 	����ɹ�������true������ʧ�ܷ���false
	OgdcBool FromColorset(const OgdcColorset &colorset);

	//! \brief 		����������ȡ��ɫ���е���ɫ
	//! \param 		nIndex ��ɫ����
	//! \return 	����nIndex��Ӧ����ɫ
	OgdcColor GetRGB(OgdcInt nIndex);

	//! \brief 		�޸���ɫ���е���ɫ
	//! \param 		nIndex Ҫ�޸ĵ�����
	//! \param 		nNewValue �µ���ɫֵ		
	void SetColor(OgdcInt nIndex, OgdcInt nNewValue);


	//! \brief 		���ݸ߶�ȡ����ɫ����������Ӧ���ڷֲ���ɫ
	//! \param 		dZ Ҫ��ȡ�ĸ߶�
	//! \param 		dR �洢����ɫ����
	//! \param 		dG �洢����ɫ����
	//! \param 		gB �洢����ɫ����
	//! \return 	�ɹ�����true��ʧ�ܷ���false.
	OgdcBool GetColor(OgdcDouble dZ,OgdcDouble& dR,OgdcDouble& dG,OgdcDouble& dB);
	
	//! \brief 		��ȡ��ɫ���е���Сֵ
	//! \return 	������ɫ���е���ɫ����Сֵ		
	OgdcDouble GetFloor()const;

	//! \brief 		������ɫ���е���Сֵ
	//! \param 		newValue		
	void SetFloor(OgdcDouble dNewValue);

	//! \brief 		��ȡ��ɫ���е����ֵ
	//! \return 	��ɫ�����ֵ		
	OgdcDouble GetCeiling()const;

	//! \brief 		������ɫ���е����ֵ
	//! \param 		dNewValue ��ɫ�����ֵ		
	void SetCeiling(OgdcDouble dNewValue);

	//! \brief 		���ˮƽ�߸߶�
	//! \return 	����ˮƽ�߸߶�		
	OgdcDouble GetWaterLevel() const;

	//! \brief 		����ˮƽ�߸߶�
	//! \param 		dNewValue ˮƽ�߸߶�		
	void SetWaterLevel(OgdcDouble dNewValue);

	//! \brief 		��ɫ���ߵ�����	
	void SwapIndex();

	//! \brief 		������ɫ��������		
	void SwapRedBlue();

	//! \brief 		�����ҶȽ�����ɫ��
	//! \return 	��ɫ������ɫ���Ĵ�С
	//! \remarks    ��ɫ���ɵ�ǰm_Colorset����Ŀ����
	OgdcInt CreateGrey();

	//! \brief 		������ɫ������ɫ��
	//! \return 	��ɫ������ɫ���Ĵ�С
	//! \remarks	��ɫ���ɵ�ǰm_Colorset����Ŀ����
	OgdcInt CreateRed();

	//! \brief 		������ɫ������ɫ��
	//! \return 	��ɫ������ɫ���Ĵ�С	
	//! \remarks	��ɫ���ɵ�ǰm_Colorset����Ŀ����
	OgdcInt CreateGreen();

	//! \brief 		������ɫ������ɫ��
	//! \return 	������ɫ���Ĵ�С		
	//! \remarks	��ɫ���ɵ�ǰm_Colorset����Ŀ����
	OgdcInt CreateBlue();

	//! \brief 		�������ν�����ɫ��
	//! \return 	��ɫ���Ĵ�С
	//! \remarks 	��ɫ���ɵ�ǰm_Colorset����Ŀ�������������ˮ�ߣ���ôҪ��ʼ������Colorset	
	OgdcInt CreateDefault();
	
	
	//! \brief 		���ݸ߶�ȡ����ɫ������Ӧ���ڷֲ���ɫ
	//! \param 		dZValue	�߶�ֵ
	//! \return 	��ȡ����ɫ
	OgdcColor GetColor(OgdcDouble dZValue);
	
	//! \brief 		���ɽ�����ɫ��
	//! \param 		nCount				��ɫ��
	//! \param 		nStockGradientStyle ��������
	//! \param 		bReverse			�Ƿ���
	//! \return 	������ɫ����С��������0���򴴽�ʧ��
	OgdcInt CreateStockGradient(OgdcInt nCount, OGDC_ENUM_STOCK_GRADIENT_SET_STYLE nStockGradientStyle, OgdcBool bReverse = FALSE);

	//! \brief 		����������ɫ��
	//! \param 		nCount		��ɫ����	
	//! \param 		colorStart  ��ʼ����ɫֵ
	//! \param 		colorEnd	������ɫֵ	
	//! \return 	������ɫ����С��������0���򴴽�ʧ��
	OgdcInt CreateGradient(OgdcInt nCount, OgdcColor clrStart,OgdcColor clrEnd);

	//! \brief 		���ݸ߶�ȡ����ɫ
	//! \param 		dZValue �߶�ֵ
	//! \return 	ȡ�õ���ɫֵ
	OgdcColor InterColor(OgdcDouble dZValue);
	
	//! \brief 		ȡ�ú���ɫ����
	//! \param 		nIndex ��ɫ������
	//! \return 	����ɫ����ֵ
	OgdcShort GetRed(OgdcInt nIndex);

	//! \brief 		���ú���ɫ����
	//! \param 		nIndex ����
	//! \param 		nNewValue ����ɫ��������ֵ 		
	void SetRed(OgdcInt nIndex,OgdcUchar nNewValue);

	//! \brief 		ȡ������ɫ����
	//! \return 	����ɫ����ֵ
	//! \param 		nIndex ��ɫ������	
	OgdcShort GetGreen(OgdcInt nIndex);

	//! \brief 		��������ɫ����
	//! \param 		nIndex ����
	//! \param 		nNewValue ����ɫ��������ֵ 	
	void SetGreen(OgdcInt nIndex,OgdcUchar nNewValue);

	//! \brief 		ȡ������ɫ����
	//! \param 		nIndex ��ɫ������		
	//! \return 	����ɫ����ֵ
	OgdcShort GetBlue(OgdcInt nIndex);

	//! \brief 		��������ɫ����
	//! \param 		nIndex ����
	//! \param 		nNewValue ����ɫ��������ֵ 		
	void SetBlue(OgdcInt nIndex,OgdcUchar nNewValue);

private:
	OgdcColor InterColor(OgdcColorset &colorset,OgdcDouble dUpperLimit,OgdcDouble dLowerLimit,OgdcDouble dValue) const;

public:
	//! \brief 	�ڲ���ɫ��
	OgdcColorset m_Colorset;
	//! \brief 	�ڲ���ɫ��׼ֵ
	OgdcColorset m_ColorsetWater;

	// {{add by Jingfei 2012-06-12 ������ɫ���ձ��֧��
	OgdcBool m_bUseColorDictTable;		// �Ƿ�ʹ����ɫ���ձ�
	OgdcArray<OgdcDouble> m_arrValue;	// �߳�ֵ����
	// }}end

protected:
	//! \brief �����ɫֵ
	OgdcDouble m_dCeiling;
	//! \brief ��С��ɫֵ
	OgdcDouble m_dFloor;
	//! \brief ˮƽ�߸߶�
	OgdcDouble m_dWaterLevel;
	//! \brief �Ƿ�Ϊˮƽ�߸߶�
	OgdcBool m_bWaterLevel;
};

}


#endif // !defined(AFX_OGDCCOLORTABLE_H__B6F4BBA2_614E_4B02_83B3_FA02C425A6EC__INCLUDED_)

