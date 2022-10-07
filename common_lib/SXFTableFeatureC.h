//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableFeatureC.h					  �쐬���F2000.04.10
//
//	�P�D�N���X�T�v
//		��`�e�[�u���t�B�[�`���f�[�^��ێ�����
//
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2000.04.10	   ��
//
//------------------------------------------------------------
#ifndef _SXFTABLEFEATUREC_H_
#define _SXFTABLEFEATUREC_H_

class SXFInstanceIDC;
class SXFLayerC;

class SXFTableFeatureC	
{
public:
	BOOL SetLayerFeature(SXFLayerC* IN_Layer);
	SXFTableFeatureC();
	SXFTableFeatureC(SXFInstanceIDC* IN_InstanceIDManager);
	virtual ~SXFTableFeatureC();

	// when read feature comment:  class->struct
	BOOL SetStructData(int IN_Type, LPVOID IN_Class);

	// when want to write feature commentor or
	// after read AP202 instance && (mapping AP202->Struct):
	// struct->feature comment
	BOOL SetFeatureData(int IN_Type,LPVOID IN_Struct);
	

	INSTANCEDATA* GetFeatureData( );
	LPVOID GetStructData(int& OUT_Type);

private:
	INSTANCEDATA m_FeatureData;

	int    m_Type;
	LPVOID m_StructData;
	SXFInstanceIDC* m_InstanceIDManager;

};

#endif
