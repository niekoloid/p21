/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	��`�e�[�u���t�B�[�`���I�u�W�F�N�g��Mapping�I�u�W�F�N�g���Ǘ�����N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFTABLEMAPMANAGERC_H__16B30B22_0BAC_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTABLEMAPMANAGERC_H__16B30B22_0BAC_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFDataStructC.h"
#include "SXFStruct.h"

class SXFPreColourMappingC;
class SXFPreTypeMappingC;
class SXFUserColourMappingC;
class SXFUserTypeMappingC;
class SXFLayerMappingC;
class SXFLineWidthMappingC;
class SXFTextFontMappingC;
class SXFTableFeatureC;
class SXFPart21FileC;
class SXFPreDefColorC;
class SXFLayerC;
class SXFInvisibilityMappingC;
class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFInstanceIDC;
class SXFTableManagerC;
class SXFMapTableC;

class SXFTableMapManagerC  
{
public:
	LPVOID GetStructData();
	void SetFeatureData(int IN_Type,LPVOID IN_Class);
	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable);
	BOOL SetStructLayer(SXFLayerC* IN_Layer);
	BOOL SetStructPrecolor(int IN_Type,LPVOID IN_Struct,SXFPreDefColorC IN_Precolor);
	BOOL WriteInstance(int IN_Type);
	int GetInstanceID(int IN_table_type);
	BOOL SetStructData(int IN_type,LPVOID IN_Struct);

	BOOL SetAP202ID(int IN_InstanceID);
	LPVOID GetStruct(int& OUT_TableType);

	SXFTableMapManagerC();
	SXFTableMapManagerC(SXFPart21FileC* IN_File,SXFComInfoC* IN_ComInfo,SXFPart21FileWriteC* IN_WriteFile,SXFInstanceIDC* m_InstanceIDManager);
	SXFTableMapManagerC(SXFPart21FileC* IN_File);

	SXFTableMapManagerC(SXFTableManagerC* IN_TableManager,
						SXFInstanceIDC* IN_InstanceIDManager);
	SXFTableMapManagerC(
					 SXFTableManagerC* IN_TableManager,
					 SXFInstanceIDC* IN_InstanceIDManager,
					 SXFComInfoC* IN_ComInfo);

	virtual ~SXFTableMapManagerC();

public:

	SXFTableManagerC* m_TableManager;
	SXFMapTableC* m_MapTable;

private:
	///////////////////////////////////
	//��`�e�[�u���t�B�[�`���I�u�W�F�N�g
	///////////////////////////////////
	SXFTableFeatureC* m_LayerFeature;
	///////////////////////////////////
	//�C���X�^���XID�I�u�W�F�N�g
	///////////////////////////////////
	SXFInstanceIDC* m_InstanceIDManager;
	///////////////////////////////////
	//�o�̓t�@�C���I�u�W�F�N�g
	///////////////////////////////////
	SXFPart21FileWriteC* m_WriteFile;
	///////////////////////////////////
	//�t�@�C���I�u�W�F�N�g
	///////////////////////////////////
	SXFPart21FileC* m_File;
	///////////////////////////////////
	//�����t�H���g�I�u�W�F�N�g
	///////////////////////////////////
	SXFTextFontMappingC* m_TextFontMapping;
	///////////////////////////////////
	//����Mapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFLineWidthMappingC* m_LineWidthMapping;
	///////////////////////////////////
	//���[�U��`����Mapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFUserTypeMappingC* m_UserTypeMapping;
	///////////////////////////////////
	//���[�U��`�FMapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFUserColourMappingC* m_UserColourMapping;
	///////////////////////////////////
	//���C��Mapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFLayerMappingC* m_LayerMapping;
	///////////////////////////////////
	//����`�FMapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFPreColourMappingC* m_PreColourMapping;
	///////////////////////////////////
	//����`����Mapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFPreTypeMappingC* m_PreTypeMapping;
	///////////////////////////////////
	//��`�e�[�u���t�B�[�`���I�u�W�F�N�g
	///////////////////////////////////
	SXFTableFeatureC* m_TableFeature;
	///////////////////////////////////
	//InvisibilityMapping�I�u�W�F�N�g
	///////////////////////////////////
	SXFInvisibilityMappingC* m_InvisibilityMapping;
	///////////////////////////////////
	//���ʏ��Ǘ��I�u�W�F�N�g
	///////////////////////////////////
	SXFComInfoC* m_ComInfo;

};

#endif // !defined(AFX_SXFTABLEMAPMANAGERC_H__16B30B22_0BAC_11D4_A76E_00000EB03267__INCLUDED_)
