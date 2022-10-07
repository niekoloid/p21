/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�N���X�T�v
	��`�e�[�u���t�B�[�`���I�u�W�F�N�g��Mapping�I�u�W�F�N�g���Ǘ�����N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFMapTableC.h"
#include "SXFTableMapManagerC.h"
#include "SXFPreColourMappingC.h"
#include "SXFPreTypeMappingC.h"
#include "SXFUserColourMappingC.h"
#include "SXFUserTypeMappingC.h"
#include "SXFLayerMappingC.h"
#include "SXFLineWidthMappingC.h"
#include "SXFTextFontMappingC.h"
#include "SXFTableFeatureC.h"
#include "SXFPart21FileC.h"
#include "SXFPreDefColorC.h"
#include "SXFLayerC.h"
#include "SXFInvisibilityMappingC.h"
#include "SXFComInfoC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFInstanceIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFTableMapManagerC::SXFTableMapManagerC()
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFTableMapManagerC::SXFTableMapManagerC()
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_InvisibilityMapping = NULL;
	m_ComInfo = NULL;
	m_WriteFile = NULL;
	m_InstanceIDManager = NULL;
	m_MapTable = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFTableMapManagerC(SXFPart21FileC* IN_File)
	����:	�^								������				���e
			SXFPart21FileC*					IN_File		̧�ٵ�޼ު��

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFTableMapManagerC::SXFTableMapManagerC(SXFPart21FileC* IN_File)
{
	m_File = IN_File;
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_InvisibilityMapping = NULL;
	m_ComInfo = NULL;
	m_WriteFile = NULL;
	m_InstanceIDManager = NULL;
	m_MapTable = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFTableMapManagerC(SXFPart21FileC* IN_File,
								SXFComInfoC* IN_ComInfo,
								SXFPart21FileWriteC* IN_WriteFile,
								SXFInstanceIDC* IN_InstanceIDManager)
	����:	�^								������				���e
			SXFPart21FileC*					IN_File					̧�ٵ�޼ު��
			SXFComInfoC* 					IN_ComInfo				���ʏ��Ǘ���޼ު��
			SXFPart21FileWriteC* 			IN_WriteFile			̧�ُo�͵�޼ު��
			SXFInstanceIDC* 				IN_InstanceIDManager	�ݽ�ݽID�Ǘ���޼ު��

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFTableMapManagerC::SXFTableMapManagerC(SXFPart21FileC* IN_File,SXFComInfoC* IN_ComInfo,SXFPart21FileWriteC* IN_WriteFile,SXFInstanceIDC* IN_InstanceIDManager)
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_File = IN_File;
	m_ComInfo = IN_ComInfo;
	m_WriteFile = IN_WriteFile;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_InvisibilityMapping = NULL;
	m_MapTable = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFTableMapManagerC::~SXFTableMapManagerC()
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFTableMapManagerC::~SXFTableMapManagerC()
{
	if (m_PreColourMapping != NULL)
		delete m_PreColourMapping;
	if (m_PreTypeMapping != NULL)
		delete m_PreTypeMapping;
	if (m_UserColourMapping != NULL)
		delete m_UserColourMapping;
	if (m_UserTypeMapping != NULL)
		delete m_UserTypeMapping;
	if (m_LayerMapping != NULL)
		delete m_LayerMapping;
	if (m_LineWidthMapping != NULL)
		delete m_LineWidthMapping;
	if (m_TextFontMapping != NULL)
		delete m_TextFontMapping;
	if (m_TableFeature != NULL)
		delete m_TableFeature;
	if (m_LayerFeature != NULL)
		delete m_LayerFeature;
	if (m_InvisibilityMapping != NULL)
		delete m_InvisibilityMapping;

	if(m_MapTable != NULL)
		delete m_MapTable;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�\���̂̐���

	�Q�D�C���^�[�t�F�[�X
	BOOL SetStructData(int IN_type, LPVOID IN_Struct)
	����:	�^				������				���e
			int				IN_type				�e�[�u���^
			LPVOID			IN_Struct			�\����
	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFTableMapManagerC::SetStructData(int IN_type, LPVOID IN_Struct)
{
	switch(IN_type)
	{
	case 1://layer
		return FALSE;
		break;
	case 2://����`�F
		return FALSE;
		break;
	case 3://���[�U�F
		m_UserColourMapping = new SXFUserColourMappingC();
		if (m_UserColourMapping->MappingStruct((Userdefined_Colour_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 4://����`����
		m_PreTypeMapping = new SXFPreTypeMappingC();
		if (m_PreTypeMapping->MappingStruct((Predefined_Linetype_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 5://���[�U����
		m_UserTypeMapping = new SXFUserTypeMappingC();
		if (m_UserTypeMapping->MappingStruct((Userdefined_Linetype_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 6://����
		m_LineWidthMapping = new SXFLineWidthMappingC();
		if (m_LineWidthMapping->MappingStruct((Line_Width_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 7://�����t�H���g
		m_TextFontMapping = new SXFTextFontMappingC();
		if (m_TextFontMapping->MappingStruct((Text_Font_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	default:
		return FALSE;
		break;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�C���X�^���XID�̎擾

	�Q�D�C���^�[�t�F�[�X
	int GetInstanceID(int IN_table_type)
	����:	�^				������				���e
			int				IN_type		�e�[�u���^

	���A�l	���펞�F�C���X�^���XID
			�ُ펞�F0

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
int SXFTableMapManagerC::GetInstanceID(int IN_table_type)
{
	int ID = 0;
	switch(IN_table_type)
	{
	case 1://layer
		ID = m_LayerMapping->GetID();
		break;
	case 2://����`�F
		ID = m_PreColourMapping->GetID();
		break;
	case 3://���[�U�F
		ID = m_UserColourMapping->GetID();
		break;
	case 4://����`����
		ID = m_PreTypeMapping->GetID();
		break;
	case 5://���[�U����
		ID = m_UserTypeMapping->GetID();
		break;
	case 6://����
		ID = m_LineWidthMapping->GetID();
		break;
	case 7://�����t�H���g
		ID = m_TextFontMapping->GetID();
		break;
	default:
		return -1;
		break;
	}
	return ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�C���X�^���X���t�@�C���֏o�͂���

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteInstance(int IN_Type)
	����:	�^				������			���e
			int				IN_Type			�e�[�u���^

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFTableMapManagerC::WriteInstance(int IN_Type)
{
	switch(IN_Type)
	{
	case 1://layer
		m_LayerMapping->WriteAP202(m_File);
		break;
	case 2://����`�F
		m_PreColourMapping->WriteAP202(m_File);
		break;
	case 3://���[�U�F
		m_UserColourMapping->WriteAP202(m_File);
		break;
	case 4://����`����
		m_PreTypeMapping->WriteAP202(m_File);
		break;
	case 5://���[�U����
		m_UserTypeMapping->WriteAP202(m_File);
		break;
	case 6://����
		m_LineWidthMapping->WriteAP202(m_File);
		break;
	case 7://�����t�H���g
		m_TextFontMapping->WriteAP202(m_File);
		break;
	default:
		return FALSE;
		break;
	}
	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	����`�F�̍\���̂̐���(READ)

	�Q�D�C���^�[�t�F�[�X
	BOOL SetStructPrecolor(int IN_Type, LPVOID IN_Struct, SXFPreDefColorC IN_Precolor)
	����:	�^				������			���e
			int				IN_Type			�e�[�u���^
			LPVOID			IN_Struct		�\����
			SXFPreDefColorC IN_Precolor		����`�F�N���X

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFTableMapManagerC::SetStructPrecolor(int IN_Type, LPVOID IN_Struct, SXFPreDefColorC IN_Precolor)
{
	m_PreColourMapping = new SXFPreColourMappingC();
	if (m_PreColourMapping->MappingStruct(IN_Precolor)){
		return TRUE;
	}
	else 
		return FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	���C���t�B�[�`���̍\���̂̐���(WRITE)

	�Q�D�C���^�[�t�F�[�X
	BOOL SXFTableMapManagerC::SetStructLayer(SXFLayerC *IN_Layer)
	����:	�^				������			���e
			SXFLayerC*		IN_Layer		���C���N���X

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFTableMapManagerC::SetStructLayer(SXFLayerC *IN_Layer){

	if (IN_Layer->m_SheetID < 0)
		return FALSE;
	if (IN_Layer->m_Element.GetSize() > 0){
		m_LayerMapping = new SXFLayerMappingC();
		if (m_LayerMapping->MappingStruct(IN_Layer)){
			return TRUE;
		}
		else
			return FALSE;
	}
	else
		FALSE;
	return FALSE;
}


/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	Invisibility�C���X�^���X��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable)
	����:	�^				������					���e
			CUIntArray*		IN_InvisibilityTable	Invisiblity�C���X�^���X�����C���X�^���XID�̔z��

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFTableMapManagerC::MappingInvisibility(CUIntArray* IN_InvisibilityTable)
{
	m_InvisibilityMapping = new SXFInvisibilityMappingC();
	if (m_InvisibilityMapping->MappingStruct(IN_InvisibilityTable)){
		m_InvisibilityMapping->WriteAP202(m_File);
		return TRUE;
	}
	else
		return FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�\���̂̐���(READ)

	�Q�D�C���^�[�t�F�[�X
	void SetFeatureData(int IN_Type, LPVOID IN_Class)
	����:	�^				������		���e
			int				IN_Type		��`�e�[�u���^
			LPVOID			IN_Class	�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
void SXFTableMapManagerC::SetFeatureData(int IN_Type, LPVOID IN_Class)
{
	m_TableFeature = new SXFTableFeatureC();
	m_TableFeature->SetStructData(IN_Type,IN_Class);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�\���̂̎擾(READ)

	�Q�D�C���^�[�t�F�[�X
	LPVOID GetStructData()
	����:	�^				������		���e
			�Ȃ�

	���A�l	�\����

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
LPVOID SXFTableMapManagerC::GetStructData()
{
	int type;
	return m_TableFeature->GetStructData(type);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	ID�̐���

	�Q�D�C���^�[�t�F�[�X
	void SetAP202ID(int IN_Type)

	����:	�^				������		���e
			int				IN_Type		��`�e�[�u���^

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFTableMapManagerC::SetAP202ID(int IN_InstanceID)
{
	/*�}�b�s���O���Ǘ���޼ު�Đ���*/
	m_MapTable = new SXFMapTableC(m_InstanceIDManager,m_ComInfo,m_TableManager);
	/*���[�g�h�c�̐ݒ�*/
	m_MapTable->SetRootID(IN_InstanceID);

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ANGULARDIMC.cpp						�쐬���F2001.06.17

	�P�D�@�\�T�v
		�\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		LPVOID SXFTableMapManagerC::GetStruct(int& OUT_TableType)

	���� �F	�^					������			���e
			int			OUT_TableType		ð��ٌ^

	���A�l�F���펞�FOUT_Struct

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.17	
**/
LPVOID SXFTableMapManagerC::GetStruct(int& OUT_TableType)
{
	int TableType = 0;
	LPVOID TableClass = NULL;
	LPVOID OUT_Struct = NULL;
	m_MapTable->SetFeatureParameter(TableType,TableClass);
	if (TableClass == NULL)
		return OUT_Struct;
	m_TableFeature = new SXFTableFeatureC();
	m_TableFeature->SetStructData(TableType,TableClass);
	OUT_Struct = m_TableFeature->GetStructData(OUT_TableType);

	return OUT_Struct;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	SXFTableMapManagerC::SXFTableMapManagerC(
                     SXFTableManagerC* IN_TableManager,
                     SXFInstanceIDC* IN_InstanceIDManager)
	
	����:	�^				������				���e
         SXFTableManagerC	 IN_TableManager		��`ð��يǗ���޼ު��
         SXFInstanceIDC		 IN_InstanceIDManager	�ݽ�ݽID�Ǘ���޼ު��
	���A�l:
			�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFTableMapManagerC::SXFTableMapManagerC(
						SXFTableManagerC* IN_TableManager,
						SXFInstanceIDC* IN_InstanceIDManager)
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_File = NULL;

	m_InstanceIDManager = IN_InstanceIDManager;

	m_TableManager = IN_TableManager;

	m_InvisibilityMapping = NULL;

	m_MapTable = NULL;

	m_ComInfo = NULL;
	m_WriteFile = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	SXFTableMapManagerC::SXFTableMapManagerC(
                     SXFTableManagerC* IN_TableManager,
                     SXFInstanceIDC* IN_InstanceIDManager,
					 SXFComInfoC* IN_ComInfo)
	
	����:	�^				������				���e
         SXFTableManagerC	 IN_TableManager		��`ð��يǗ���޼ު��
         SXFInstanceIDC		 IN_InstanceIDManager	�ݽ�ݽID�Ǘ���޼ު��
�@       SXFComInfoC		 IN_ComInfo				���ʏ��Ǘ���޼ު��
  
	���A�l:
			�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFTableMapManagerC::SXFTableMapManagerC(
						SXFTableManagerC* IN_TableManager,
						SXFInstanceIDC* IN_InstanceIDManager,
						SXFComInfoC* IN_ComInfo)
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_File = NULL;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_TableManager = IN_TableManager;
	m_InvisibilityMapping = NULL;
	m_MapTable = NULL;
	m_ComInfo = IN_ComInfo;
	m_WriteFile = NULL;
}
