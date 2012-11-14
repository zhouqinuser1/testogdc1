#if !defined(OGDCCOLORDEF_H)
#define OGDCCOLORDEF_H

namespace OGDC
 {
//! \brief ���ظ�ʽ
enum PixelFormat 
{
	//! \brief ��δ�趨, �ڲ�ʹ��
	IPF_UNKNOWN			= 0,
	//! \brief 1λ,��ɫ
	IPF_MONO			= 1,
	//! \brief 4λ,16ɫ
	IPF_FBIT			= 4,
	//! \brief 8λ,256ɫ
	IPF_BYTE			= 8,
	//! \brief 16λ,��ɫ
	IPF_TBYTE			= 16,
	//! \brief 24λ,���ɫ
	IPF_RGB				= 24,
	//! \brief 32λ,��ǿ���ɫ
	IPF_RGBA			= 32,
	//! \brief 48λ,���ɫ
	IPF_TRGB			= 48,
	//! \brief 64λ,������
	IPF_LONGLONG		= 64,
	//! \brief LONG
	IPF_LONG			= 320,
	//! \brief 32λ,������
	IPF_FLOAT			= 3200,
	//! \brief 64λ,˫���ȸ�����
	IPF_DOUBLE			= 6400	
};

//! \brief ɫ�ʿռ��ʽ����.
typedef enum
{
	//! \brief δ֪ɫ�ʿռ�
	ICS_UNKNOW =0,
		//! \brief ��ʾϵͳʹ��.
		ICS_RGB = 1,
		//! \brief ��ʾϵͳʹ��.
		ICS_RGBA = 2,
		//! \brief ӡˢϵͳʹ��(Cyan,Magenta,Yellow).
		ICS_CMY = 3,
		//! \brief ӡˢϵͳʹ��(Cyan,Magenta,Yellow,Black)
		ICS_CMYK = 4,
		//! \brief ��������ϵͳʹ��(NTSC,Y:Luminance,Chrominance).
		ICS_YIQ = 5,
		//! \brief ŷ�޵���ϵͳʹ��(PAL).
		ICS_YUV = 6,
		//! \brief ��YUV����,JPEGʹ��.
		ICS_YCC = 7		
} ImgColorSpace;

//! \brief �������ظ�ʽ��λ��Ϊ1λ.
#define IPF_MONO_BITS 1
//! \brief �������ظ�ʽ��λ��Ϊ4λ.
#define IPF_FBIT_BITS 4
//! \brief �������ظ�ʽ��λ��Ϊ8λ.
#define IPF_BYTE_BITS 8
//! \brief �������ظ�ʽ��λ��Ϊ16λ.
#define IPF_TBYTE_BITS 16
//! \brief �������ظ�ʽ��λ��Ϊ24λ.
#define IPF_RGB_BITS  24
//! \brief �������ظ�ʽ��λ��Ϊ32λ.
#define IPF_RGBA_BITS 32

//! \brief �������ظ�ʽ����ɫ��.
#define IPF_MONO_COLOR	0x00000001
//! \brief �������ظ�ʽ����ɫ��.
#define IPF_FBIT_COLOR	0x0000000F
//! \brief �������ظ�ʽ����ɫ��.
#define IPF_BYTE_COLOR	0x000000FF
//! \brief �������ظ�ʽ����ɫ��.
#define IPF_TBYTE_COLOR 0x0000FFFF
//! \brief �������ظ�ʽ����ɫ��.
#define IPF_RGB_COLOR	0x00FFFFFF
//! \brief �������ظ�ʽ����ɫ��.
#define IPF_RGBA_COLOR	0xFFFFFFFF

///////////////////////////////////////////////////////////////////////
//! \brief �õ���ByteΪ��λ��DWORD����Ŀ��.
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4) 
//! \brief �õ���ByteΪ��λ��DWORD����Ŀ��.
#define WIDTHBYTESBYTE(bits)    (((bits) + 7) / 8 )  
//! \brief �õ���ByteΪ��λ��DWORD����Ŀ��.
#define WIDTHBYTESWORD(bits)    (((bits) + 15) / 16 * 2)  
}

#endif //OGDCCOLORDEF_H

