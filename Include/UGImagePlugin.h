// UGImagePlugIn.h: interface for the UGImagePulgIn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMAGEPLUGIN_H__8C978A6D_1011_4B0F_A221_C9BEDA07CCD8__INCLUDED_)
#define AFX_UGIMAGEPLUGIN_H__8C978A6D_1011_4B0F_A221_C9BEDA07CCD8__INCLUDED_

#define MAXIMGAEPALETTEENTRY 256
#ifdef WIN32
	#include <Windows.h>
	#define IMAGEEXPORT __declspec(dllexport)
#else
	#define IMAGEEXPORT
#endif

#include "Stream/ugdefs.h"
#include "NetToolkit/UGDownloadListener.h"

//! \brief ���ظ�ʽ����.
enum ImagePixelFormat 
{
	PF_ERROR = 0,		// 0λ,��֧�ֵ����ظ�ʽ
	PF_MONO = 1,		// 1λ,��ɫ
	PF_FBIT = 4,		// 4λ,16ɫ
	PF_BYTE = 8,		// 8λ,256ɫ
	PF_TBYTE= 16,		// 16λ,��ɫ
	PF_RGB = 24,		// 24λ,���ɫ
	PF_RGBA = 32,		// 32λ,��ǿ���ɫ
	PF_LONGLONG = 64,	// 64λ,������
	PF_LONG = 320,
	PF_FLOAT = 3200,	// 32λ,������
	PF_DOUBLE = 6400,	// 64λ,˫���ȸ�����
};

//! \brief ���岻ͬ���ظ�ʽ��λ��.
enum ImagePixelBits
{
	PB_MONO = 1,
	PB_FBIT = 4,
	PB_BYTE = 8,
	PB_TBYTE = 16,
	PB_RGB = 24,
	PB_RGBA = 32,
};

//! \brief ɫ�ʿռ��ʽ����.
enum ImageColorSpace
{
	CS_RGB = 0,		// ��ʾϵͳʹ��.
	CS_RGBA = 1,	// ��ʾϵͳʹ��.
	CS_CMY = 2,		// ӡˢϵͳʹ��(Cyan,Magenta,Yellow).
	CS_CMYK = 3,	// ӡˢϵͳʹ��(Cyan,Magenta,Yellow,Black)
	CS_YIQ = 4,		// ��������ϵͳʹ��(NTSC,Y:Luminance,Chrominance).
	CS_YUV = 5,		// ŷ�޵���ϵͳʹ��(PAL).
	CS_YCC = 6		// ��YUV����,JPEGʹ��.
} ;

//! \brief ��������뵥λ���� - ��׼��ʽ
enum  ImageUnit
{
	EU_DEGREE		= 0,		// Radian����
	EU_MILIMETER	= 10,		// mm����
	EU_CENTIMETER	= 100,		// ����
	EU_DECIMETER	= 1000,		// ����
	EU_METER		= 10000,	// ��
	EU_KILOMETER	= 10000000,	// ����
	EU_MILE			= 16090000,	// Ӣ��
	EU_INCH			= 254,		// Ӣ��
	EU_YARD			= 9144,		// Yard��
	EU_FOOT			= 3048,		// FeetӢ��
};

struct IMAGEEXPORT UGImagePaletteEntry
{
	unsigned char peRed;
	unsigned char peGreen;
	unsigned char peBlue;
	unsigned char peAlpha;
};

enum PluginClass {
	PC_UNKNOWN,
	PC_MAPCACHE,
	PC_HPMAPCACHE,
	PC_SIT,
	PC_GLOBALCACHE,
	PC_COMMON,
	PC_GECACHE,
};

using namespace UGC;

class IMAGEEXPORT UGImagePlugin : public UGC::UGDownloadListener
{
public:
	UGImagePlugin(){m_nCurBandIndex = -1; m_dNoValue = -9999; m_nPluginClass = PC_UNKNOWN; m_bBackTransparent = FALSE;}
	virtual ~UGImagePlugin(){}

public:
	//! \brief ����������
	virtual PluginClass GetPluginClass() { return m_nPluginClass; }

	//! \brief  �����������ƣ����� ECW �ļ����.
	//! \param  strName,�ַ���,���������ռ�.[out]
	//! \param  nMaxLength �ַ�������[in]
	virtual bool GetPluginName(UGchar* strName, int nMaxLength) = 0;

	//! \brief  �õ������֧�ֵ�Ӱ���ļ�����չ������".BMP",".JPG"�ȡ�
	//! \param  nIndex �ڼ�����չ��������ͨ��GetExtNameCountȡ��֧�ֵ���չ����Ŀ��[in]
	//! \param  strExtName ��չ���ַ��������������ռ䡣[out]
	//! \param  nMaxLength �ַ������ȡ�[in]
	virtual bool GetExtName(UGchar* strExtName, int nMaxLength, int nExtNameIndex = 0) = 0;

	//! \brief ���ļ���
	//! \param  strFileName,�ļ�·������[in]
	//! \param  nFlags,�򿪷�ʽ����ֻ��������ȣ��ο�CFile�ı�־��[in]
	virtual bool Open(const UGchar* strFileName, unsigned int nFlags, const UGchar * strPassword) = 0;

	//! \brief �ر��ļ���
	virtual void Close() = 0;

	//! \brief ���Ӱ���ļ������ظ�ʽ��
	//! \param  nPixelformat ���ظ�ʽ����RGB,�Ҷȵ�[out]
	virtual bool GetPixelFormat(ImagePixelFormat& nPixelformat) = 0;

	//! \brief �������λ��
	//! \param  nPixelbits,���ظ�ʽλ������RGBһ����24λ[out]
	virtual bool GetPixelBits(ImagePixelBits& nPixelbits)= 0;

	//! \brief �õ�Ӱ��Ĵ�С
	//! \param  nWidth Ӱ����[out]
	//! \param  nHeight Ӱ��߶�[out]
	virtual bool GetImageSize(int& nWidth, int& nHeight)= 0;

	//! \brief �õ�Ӱ��ĵ���Χ�Լ����굥λ,�ο�enumUnit
	//! \param  dLeft, dRight ����Χ����ߺ��ұߣ�һ��dRight > dLeft.[out]
	//! \param  dButtom, dTop ����Χ���±ߺ��ϱߣ�һ��dTop > dBottom.[out]
	//! \param  nUnits ����λ���繫��׻�γ�ȡ�[out]
	virtual bool GetImageGeoRefrence(double& dLeft, double& dTop, double& dRight, double& dBottom, ImageUnit& nUnits)= 0;  

	//! \brief ���õ�ǰ��ʾ��Χ���������ͨ�� GetViewImageData() ���
	//! \param  nLeft, nTop,��ʾ��Χ����ߺ��ϱߡ�nLeft < nRight��nTop < nBottom.[in]
	//! \param  nRight, nBottom ��ʾ��Χ���ұߺ��±ߡ����Ǹ�ֵ��������������[in]
	//! \param  nDeviceWidth, nDeviceHeight ��ʵ��ʾ���ڵĴ�С����Ļ���ص�λ��[in]
	//! \remarks ���ڶ�ֱ��ʵ�ͼ�󣬿��԰��մ��ڴ�С����ʾ��Χ��С��ȷ��ͼ��ķֱ���,�Ӷ���������һ��ȡ��Ӱ������
	virtual bool SetViewPort(int nLeft,int nTop, int nRight, int nBottom, int nDeviceWidth, int nDeviceHeight) = 0;

	//! \brief ���õ�ǰ��ʾ��Χ���������ͨ�� GetViewImageData() ���
	//! \param  dLeft, dTop,��ʾ��Χ����ߺ��ϱߡ�dLeft < dRight��dTop < dBottom.[in]
	//! \param  dRight, dBottom ��ʾ��Χ���ұߺ��±ߡ����Ǹ�ֵ�����ǵ�������[in]
	//! \param  nDeviceWidth, nDeviceHeight,��ʵ��ʾ���ڵĴ�С����Ļ���ص�λ��[in]
	//! \remarks ���ڶ�ֱ��ʵ�ͼ�󣬿��԰��մ��ڴ�С����ʾ��Χ��С��ȷ��ͼ��ķֱ���,�Ӷ���������һ��ȡ��Ӱ������
	virtual bool SetViewPort(double dLeft,double dTop, double dRight, double dBottom, int nDeviceWidth, int nDeviceHeight) = 0;

	//! \brief ���õ�ǰ��ʾ��Χ��,������ʾ��Χ��Ӱ�����ݵĿ�ȡ�
	//! \remarks ���ڶ�ֱ���ͼ�󣬿��ܴ�����һ���ȡ���ݣ���������Ŀ�ȿ��ܺ���ʾ��Χ�Ŀ�Ȳ�һ��
	//! \param  nViewWidth ��ʾ����Ӱ���ȡ�[out]
	//! \param  nViewHeight ��ʾ����Ӱ��߶ȡ�[out]
	virtual bool GetViewImageSize(int& nViewWidth, int& nViewHeight)= 0;
	
	//! \brief ���õ�ǰ��ʾ��Χ��,������ʾ��Χ�����ݵĴ�С��
	virtual int GetViewImageDataSize() = 0; 

	//! \brief ���õ�ǰ��ʾ��Χ��,��ȡ��ʾ��Χ�ڵ�Ӱ������,�ⲿȡ�������Ժ󣬿���������ʾ
	//! \param  pDataBuffer Ӱ�����ݣ����������ռ䡣[in]
	//! \param  nSize ���ݴ�С(�ֽ�������һ�����GetViewImageDataSize��������ֵ[in]
	virtual bool GetViewImageData(unsigned char* pDataBuffer, int nSize)= 0;

	//! \brief ���õ�ͼ�Ĺ̶������ߡ�ĳЩ����Դ�������ͼ������Ҫ�����õ�ͼ�Ĺ̶�������
	//! \brief pMap ����Ҫ���ù̶������ߵĵ�ͼ [in]
	//! \brief pCallBack �������ù̶������ߵĻص��������ûص�������һ������Ϊ UGMap ָ�룬�ڶ�������Ϊ����Ҫ���õĹ̶������� [in]
	virtual void ConfigureMap(void *pMap, void (*pCallBack) (void *, std::vector<double>)) { /* do nothing */ }

public:
	//! \brief �ͷ��Լ��������������Ҫ��һ����̬���ڷ���Ķ��ڴ棬
	//! \remarks ������һ����̬�����ͷſ��ܻ�������Ը��������ͷ��Լ���
	virtual bool BuildPyramid(bool bShhowProgress){return FALSE;}

	virtual bool RemovePyramids(){return FALSE;}

	virtual bool IsBuildPyramid() const{return FALSE;}

	//! \brief Ϊդ���ļ��޸�����
	//! \param  bool �޸���������Ƿ�ɹ�[out]
	//! \param  strNewPassword ���õ�������[in]
	virtual bool ChangePassword(const UGchar* strNewPassword){return false;}

	//! \brief Ϊ��ȡդ���ļ��Ļ����������
	//! \return ���������õ����룬��û�������򷵻ؿ�
	virtual const UGchar* GetPassword() {return NULL;}

	//! \brief �õ�֧�ֵ�Ӱ���ļ���չ����Ŀ��
	virtual int GetExtNameCount() const{return 1;}
	
	//! \brief  �õ�������Ŀ��
	virtual int GetBandCount() const {return 0;}

	//! \brief  ���õ�ǰȡ���ݵĲ���������
	//! \param  nBandIndex ����������[in]
	virtual void SetCurBandIndex(int nCurBandIndex){m_nCurBandIndex = nCurBandIndex;}

	//! \brief  �õ���ǰȡ���ݵĲ���������
	virtual int GetCurBandIndex() const{return m_nCurBandIndex;}

	//! \brief  ���ò������ģʽ��
	//! \param  pBandIndexs �����������顣[in]
	//! \param  nColorSpace ��ɫ�ռ�ģʽ��[in]
	virtual void SetBandCombineMode(const int* pBandIndexs, ImageColorSpace nColorSpace){}

	//! \brief  �õ��������ģʽ��
	//! \param  pBandIndexs �����������飬���濪���ڴ档���Ϊ4��int��������ɫ�ռ�ģʽ������[out]
	//! \param  nColorSpace ��ɫ�ռ�ģʽ��[out]
	virtual void GetBandCombineMode(int* pBandIndexs, ImageColorSpace& nColorSpace) const{}

	//! \brief ����ͶӰ��Ϣ
	virtual void SetPrjCoordSys(const UGchar*strPrjCoordSys){}
	virtual const UGchar* GetPrjCoordSys(){return NULL;}

	//! \brief �����ļ��汾��Ϣ
	virtual void SetVersion(int nVersion){}
	virtual int GetVersion(){return 0;}
	
	//! \brief �õ�ָ����Χ���ݵİ汾��Ϣ
	virtual int GetDataVersion(double dLeft,double dTop, double dRight, double dBottom, int nDeviceWidth, int nDeviceHeight){return 0;}
	
	//! \brief �õ��ü�����,����Ҫ��������ڴ棬������Ҫ�����ͷš�
	virtual bool GetClipRgn(double*& pXCoord, double*& pYCoord, int*& pPloyCounts, int& nSubCount){return false;}
	
	//! \brief �ͷ���ʱ���ݡ�
	virtual void Release(){}

	//! \brief �ͷŻ����е�����
	virtual void FreeCache() {}

	//! \brief �������ؽ���
	virtual float GetDataStreamingProgress(){return -1.0;}

	//! brief �õ���ʾ�Ľ�����������Ҫ���ڴ��(�ֽ�)
	//! param nBand ����
	//! param nTierIndex ����������
	virtual int GetViewPyramidDataSize(int nBand, int nTierIndex){return 0;}

	//! \brief ������ʾ�ĵ���Χ
	//! \param ��ʾ�ķ�Χ
	//! \remarks ������������UGPluginCommon�����õģ��ڷֿ��ȡRDAS��IMG��ʽ�ļ�ʱ���õ�
	//! ��UGDatasetRasterImg::GetViewBlock�����е���
	virtual void SetViewBounds(double dLeft, double dTop, double dRight, double dBottom){};

	//! \brief GetViewImageData() ��ȡ�����Ƿ��Ѿ���ȡ��ϣ����û�У���Ҫ�������� GetViewImageData() ��ȡ���ݡ���ǰֻ�� UGPluginMapCache �п���һ�����޷���ȡȫ�����ݡ�
	virtual bool IsFinished() { return true; }

	//!	\brief	��ȡ�����ȫ·���ļ���
	virtual const UGchar* GetPluginFileName() { return NULL; }

	//! \brief �����Ƿ񱳾�͸��
	virtual void SetBackTransparent(UGbool bBackTransparent){ m_bBackTransparent = bBackTransparent; }

	// ��ȡ�Ƿ񱳾�͸��
	virtual bool IsTransparentBack() { return m_bBackTransparent; }

	//! \brief�ж�Ӱ�����Ƿ��������OGC����
	virtual UGbool IsOGCServerMap(){ return false; };

	//! \brief ��������UGPluginGlobalCache��,֧������WMS����
	//! \brief ��ȡ�������ݼ�����ͼ��
	virtual UGbool GetWebSubLayersName(UGStrings& aryLayerNames) const{ return false; }

	//! \brief ��ȡ�������ݼ�����ͼ�����
	virtual UGbool GetWebSubLayersTitle(UGStrings& aryLayerTitle) const{ return false; }

	//! \brief �����������ݼ�����ͼ���Ƿ�ɼ�����
	virtual UGbool SetWebSubLayersVisible(UGStrings& arrLayersVisible){ return false; }

	//! \brief �õ��������ݼ�����ͼ���Ƿ�ɼ�����
	virtual UGbool GetWebSubLayersVisible(UGStrings& arrLayersVisible) const{ return false; }

	//! \brief ���û���Ŀ¼
	//! \param  [in]��
	//! \return ��
	//! \remarks ��Ҫ�������WMSͼ��
	//! \attention ��
	virtual void SetCachePath(const UGString& strCachePath) { }

public:
	//! \brief  ��ɫ�����ݡ�
	UGImagePaletteEntry m_palette[MAXIMGAEPALETTEENTRY];  
	//! \brief  ��ֵ����
	double m_dNoValue;

protected:
	//! \brief  ��ǰ����������
	int m_nCurBandIndex;
	int m_bandCombine[4];
	ImageColorSpace m_nColorSpace;

	//! \brief �Ƿ񱳾�͸��
	UGbool m_bBackTransparent; 

	PluginClass m_nPluginClass;		// ��ǰӰ��������
};

// �����Ҫʵ��һ��������ȫ�ֺ����������� UGImagePlugin �������ࡣ
// ����һ������࣬��new һ���� UGImagePlugin �������ࡣ
extern "C" IMAGEEXPORT UGImagePlugin* CreateImagePlugin();

#endif // !defined(AFX_UGIMAGEPLUGIN_H__8C978A6D_1011_4B0F_A221_C9BEDA07CCD8__INCLUDED_)

