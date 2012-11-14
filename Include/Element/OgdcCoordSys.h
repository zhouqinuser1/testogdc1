// OgdcCoordSys.h: interface for the OgdcCoordSys class.
//
//////////////////////////////////////////////////////////////////////
//                     ____    ____   ____     ____                    
//   Project          / _  \  / ___) |  _ \   / ___)                   
//                   | | | | | | __  | | \ | | |                       
//                   | |_| | | |_\ | | |_/ | | \___                    
//                    \____/  \____| |____/   \ ___)        
//                                                           
//!  \file OgdcCoordSys.h
//!  \brief ͶӰ����ϵ
//!  \details 
//!  \attention 
//!   Copyright(c) 2007-2012  SuperMap Software Co., Ltd.  <br> 
//!   All Rights Reserved.
//!  \version 1.0(2012)
//////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OGDCCOORDSYS_H__B15D37E7_C1BB_45D9_AB5F_34B08BA3D5C4__INCLUDED_)
#define AFX_OGDCCOORDSYS_H__B15D37E7_C1BB_45D9_AB5F_34B08BA3D5C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OgdcPrjParams.h"
#include "Base/OgdcString.h"

namespace OGDC {

class ELEMENT_API OgdcCoordSys  
{
public:
	enum SpatialRefType
	{
		//! \brief ƽ������ϵ
		SPATIALREF_NONEARTH = 0,
		//! \brief ��γ����ϵ
  		SPATIALREF_EARTH_LONGITUDE_LATITUDE = 1,
		//! \brief ͶӰ����ϵ
		SPATIALREF_EARTH_PROJECTION = 2,				
	};

	enum ProjectionType
	{
		//! \brief ��ͶӰ-- 
		PRJ_NONPROJECTION					= 43000,
		//! \brief Plate Carree   
		PRJ_PLATE_CARREE				    = 43001,
		//! \brief Equidistant Cylindrical 
		PRJ_EQUIDISTANT_CYLINDRICAL		    = 43002,
		//! \brief Miller Cylindrical 
		PRJ_MILLER_CYLINDRICAL			    = 43003, 
		//! \brief Mercator 
		PRJ_MERCATOR					    = 43004,
		//! \brief Gauss-Kruger
		PRJ_GAUSS_KRUGER				    = 43005,
		//! \brief Transverse Mercator ==43005  
		PRJ_TRANSVERSE_MERCATOR			    = 43006,
		//! \brief Albers
		PRJ_ALBERS                          = 43007,
		//! \brief Sinusoidal
		PRJ_SINUSOIDAL                      = 43008,
		//! \brief Mollweide
		PRJ_MOLLWEIDE                       = 43009,
		//! \brief Eckert VI 
		PRJ_ECKERT_VI                       = 43010,
		//! \brief Eckert V 
		PRJ_ECKERT_V                        = 43011,
		//! \brief Eckert IV
		PRJ_ECKERT_IV                       = 43012, 
		//! \brief Eckert III
		PRJ_ECKERT_III                      = 43013,
		//! \brief Eckert II
		PRJ_ECKERT_II                       = 43014,
		//! \brief Eckert I
		PRJ_ECKERT_I                        = 43015,                           
		//! \brief Gall Stereographic           
		PRJ_GALL_STEREOGRAPHIC              = 43016,      
		//! \brief Behrmann                     
		PRJ_BEHRMANN                        = 43017,      
		//! \brief Winkel I                     
		PRJ_WINKEL_I                        = 43018,      
		//! \brief Winkel II                    
		PRJ_WINKEL_II                       = 43019,      
		//! \brief Lambert Conformal Conic      
		PRJ_LAMBERT_CONFORMAL_CONIC         = 43020,      
		//! \brief Polyconic                    
		PRJ_POLYCONIC                       = 43021,      
		//! \brief Quartic Authalic             
		PRJ_QUARTIC_AUTHALIC                = 43022,      
		//! \brief Loximuthal                   
		PRJ_LOXIMUTHAL                      = 43023,      
		//! \brief Bonne                        
		PRJ_BONNE                           = 43024,      
		//! \brief Hotine                       
		PRJ_HOTINE                          = 43025,      
		//! \brief Stereographic                
		PRJ_STEREOGRAPHIC                   = 43026,      
		//! \brief Equidistant Conic            
		PRJ_EQUIDISTANT_CONIC               = 43027,      
		//! \brief Cassini                      
		PRJ_CASSINI                         = 43028,      
		//! \brief Van der Grinten I            
		PRJ_VAN_DER_GRINTEN_I               = 43029,      
		//! \brief Robinson                     
		PRJ_ROBINSON                        = 43030,      
		//! \brief Two-Point Equidistant        
		PRJ_TWO_POINT_EQUIDISTANT           = 43031,      
		//! \brief Equidistant Azimuthal        
		PRJ_EQUIDISTANT_AZIMUTHAL           = 43032,      
		//! \brief Lambert Azimuthal Equal Area 
		PRJ_LAMBERT_AZIMUTHAL_EQUAL_AREA    = 43033,      
		//! \brief Conformal Azimuthal 
		PRJ_CONFORMAL_AZIMUTHAL		        = 43034,      
		//! \brief ortho_graphic ���� 
		PRJ_ORTHO_GRAPHIC			        = 43035,      
		//! \brief Gnomonic ���� 
		PRJ_GNOMONIC				        = 43036,      
		//! \brief �й�ȫͼ��λͶӰ 
		PRJ_CHINA_AZIMUTHAL			        = 43037,      
		//! \brief ɣѷͶӰ�����������ߵȻ�αԲ��ͶӰ 
		PRJ_SANSON					        = 43040,	  
		//! \brief EqualArea Cylindrical        
		PRJ_EQUALAREA_CYLINDRICAL           = 43041,      
		//! \brief Hotine_azimuth_natorigin 
		PRJ_HOTINE_AZIMUTH_NATORIGIN        = 43042,
		//! \brief б��ī����ͶӰ
		PRJ_OBLIQUE_MERCATOR				= 43043,
		//! \brief Hotineб��ī����ͶӰ
		PRJ_HOTINE_OBLIQUE_MERCATOR			= 43044,		
		//! \brief ����ī����
		PRJ_SPHERE_MERCATOR					= 43045,		
		//! \brief �ϰ�������ͶӰ
		PRJ_BONNE_SOUTH_ORIENTATED			= 43046		
	};

public:
	//! \brief Ĭ�Ϲ��캯��
	OgdcCoordSys();
	//! \brief Ĭ����������
	virtual ~OgdcCoordSys();
	//! \brief �������캯��
	//! \param coordSys ���������ĵ�������ϵ
	OgdcCoordSys(const OgdcCoordSys& coordSys);	
    //! \brief ���� =
	//! \param coordSys ���������ĵ�������ϵ
	OgdcCoordSys& operator=(const OgdcCoordSys& coordSys);
	//! \brief ���� ==
	//! \param coordSys �����Ƚϵĵ�������ϵ
	OgdcBool operator==(const OgdcCoordSys& coordSys);
	//! \brief ���� !=
	//! \param coordSys �����Ƚϵĵ�������ϵ
	OgdcBool operator!=(const OgdcCoordSys& coordSys);

public:
	//! \brief �õ�����ռ�ο�ϵ���͡�
	OgdcCoordSys::SpatialRefType GetSpatailRefType() const;	 

	//! \brief ��������ϵΪƽ������ϵ����������ϵ��λ
	//! \param nUnit ����ϵ��λ
	OgdcBool SetPlanar(OgdcInt nUnit);


	//! \brief ��������ϵΪ��������ϵ����������ϵ�����峤��뾶�����ʺ�����ϵ��λ
	//! \param dPriAxis	�����峤��뾶
	//! \param dFlatten	���������
	//! \param nUnit ����ϵ��λ
	OgdcBool SetEarth(OgdcDouble dPriAxis, OgdcDouble dFlatten,	OgdcInt nUnit);
	
	//! \brief ��������ϵΪͶӰ����ϵ������������ϵ��ͶӰ��ʽ��ͶӰ�����������峤��뾶����������ʣ�����ϵ��λ
	//! \param  nType ͶӰ��ʽ
	//! \param  prjParams ͶӰ��������	
	//! \param  dPriAxis �����峤��뾶
	//! \param  dFlatten ���������	
	//! \param  dPrimeMeridian ���������߾���
	//! \param  nUnit ����ϵ��λ	
	//! \param  nDistUnit ����ϵ���㵥λ
	OgdcBool SetCoordSys(ProjectionType nType,				
			const OgdcPrjParams& prjParams,								
			OgdcDouble dPriAxis,											
			OgdcDouble dFlatten,										
			OgdcDouble dPrimeMeridian,										
			OgdcInt nUnit,												
			OgdcInt nDistUnit);										


public:	
	//! \brief ͶӰ����ϵ��ͶӰ����
	OgdcString m_strPrjName;	
	//! \brief ��������ϵ������
	OgdcString m_strEarthName;
	//! \brief �����峤��뾶��Ĭ��ֵ��6378137��
	OgdcDouble m_dPriAxis;
	//! \brief ��������ʣ�Ĭ��ֵ��0.0033528107��
	OgdcDouble m_dFlatten;
	//! \brief ���������߾��ȣ�Ĭ��ֵ��0.0��
	OgdcDouble m_dPrimeMeridian;
	//! \brief ����ϵ��λ��Ĭ��ֵ��10000��
	OgdcInt m_nUnit;
	//! \brief ����ϵ���㵥λ��Ĭ��ֵ��10000��
	OgdcInt m_nDistUnit;
	//! \brief ͶӰ��ʽ��Ĭ��ֵ��PRJ_NONPROJECTION��
	OgdcCoordSys::ProjectionType m_ProjectionType;
	//! \brief ͶӰ��������
	OgdcPrjParams m_PrjParams;						

protected:
	//! \brief ����ο�ϵ���ͣ�Ĭ��ֵ��SPATIALREF_NONEARTH��
	OgdcCoordSys::SpatialRefType m_nRefType;		
};

}

#endif // !defined(AFX_OGDCCOORDSYS_H__B15D37E7_C1BB_45D9_AB5F_34B08BA3D5C4__INCLUDED_)

