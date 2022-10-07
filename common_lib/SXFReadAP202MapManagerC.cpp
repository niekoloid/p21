/**
	All Rights Reserved,(c)JACIC 2001
	SXFReadAP202MapManagerC.cpp						�쐬���F2001.06.12

	�P�D�N���X�T�v
		SXFReadAP202MapManagerC �N���X�̃C���v�������e�[�V����

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFReadAP202MapManagerC.h"
#include "SXFMapGeometryC.h"
#include "SXFInstanceIDC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXFMapAssemblyC.h"
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//#include "SXFFeatureC.h"
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   �쐬���F2001.03.21

  �P�D�@�\�T�v
      �R���X�g���N�^
      
  �Q�D�C���^�[�t�F�[�X
      void SXFReadAP202MapManagerC::SXFReadAP202MapManagerC()

	    ����: �^		������		���e
			  �Ȃ�

  �R�D����
	    ����ԍ�    ���t��         �S����    �T�v
      �쐬		2001.03.21     ���X��(FQS)

**/
SXFReadAP202MapManagerC::SXFReadAP202MapManagerC()
{
	m_InstanceIDManager = NULL;
	m_TableManager = NULL;
	m_ComInfo = NULL;
	m_MapAssembly = NULL;
	m_MapGeometry = NULL;
	m_ReadManager = NULL;
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//	m_Feature = NULL;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   �쐬���F2001.03.21

  �P�D�@�\�T�v
      �R���X�g���N�^
      
  �Q�D�C���^�[�t�F�[�X
      void SXFReadAP202MapManagerC(SXFInstanceIDC* IN_InstanceIDManager,
                                   SXFTableManagerC* IN_TableManager,
                                   SXFComInfoC* IN_ComInfo,
                                   SXFReadAP202ManagerC* IN_ReadManager)

	    ����: �^					������					���e
			  SXFInstanceIDC* 		IN_InstanceIDManager	�ݽ�ݽID�Ǘ���޼ު��
			  SXFTableManagerC* 	IN_TableManager			��`ð��يǗ���޼ު��
			  SXFComInfoC* 			IN_ComInfo				���ʏ��Ǘ���޼ު��
			  SXFReadAP202ManagerC* IN_ReadManager			Read�Ǘ���޼ު��

  �R�D����
	    ����ԍ�    ���t��         �S����    �T�v
      �쐬		2001.03.21     ���X��(FQS)

**/
SXFReadAP202MapManagerC::SXFReadAP202MapManagerC(SXFInstanceIDC* IN_InstanceIDManager,
												SXFTableManagerC* IN_TableManager,
												SXFComInfoC* IN_ComInfo,
												SXFReadAP202ManagerC* IN_ReadManager)
{
	m_InstanceIDManager = IN_InstanceIDManager;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	m_MapAssembly = NULL;
	m_MapGeometry = NULL;
	m_ReadManager = IN_ReadManager;
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//	m_Feature = NULL;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   �쐬���F2001.03.21

  �P�D�@�\�T�v
      �f�X�g���N�^
      
  �Q�D�C���^�[�t�F�[�X
      SXFReadAP202MapManagerC::~SXFReadAP202MapManagerC()

	    ����: �^		������		���e
			  �Ȃ�

	    ���A�l	
			  �Ȃ�

  �R�D����
	    ����ԍ�    ���t��         �S����    �T�v
      �쐬		2001.03.21     ���X��(FQS)

**/
SXFReadAP202MapManagerC::~SXFReadAP202MapManagerC()
{
	if (m_MapAssembly != NULL)
		delete m_MapAssembly;
	if (m_MapGeometry != NULL)
		delete m_MapGeometry;
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//	if (m_Feature != NULL)
//		delete m_Feature;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   �쐬���F2001.03.21

  �P�D�@�\�T�v
      Assembly InstanceID�̃Z�b�g
      
  �Q�D�C���^�[�t�F�[�X
      BOOL SetAssemblyInstanceID(int IN_ChildID)

	    ����: �^		������		���e
			  int		IN_ChildID	Child ID

  �R�D����
	    ����ԍ�    ���t��         �S����    �T�v
      �쐬		2001.03.21     ���X��(FQS)

**/
BOOL SXFReadAP202MapManagerC::SetAssemblyInstanceID(int IN_ChildID)
{
	m_MapAssembly = new SXFMapAssemblyC(m_InstanceIDManager,m_TableManager,m_ComInfo);
	if (m_MapAssembly->SetRootID(IN_ChildID) < 0)
		return FALSE;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   �쐬���F2001.03.21

  �P�D�@�\�T�v
   Instance ID�̃Z�b�g   
      
  �Q�D�C���^�[�t�F�[�X
      BOOL SetInstanceID(int IN_ChildID)

	    ����: �^		������		���e
			  int		IN_ChildID		Child ID

  �R�D����
	    ����ԍ�    ���t��         �S����    �T�v
      �쐬		2001.03.21     ���X��(FQS)

**/
BOOL SXFReadAP202MapManagerC::SetInstanceID(int IN_ChildID)
{   
	m_MapGeometry = new SXFMapGeometryC(m_InstanceIDManager,m_TableManager,m_ComInfo,m_ReadManager);
	if (m_MapGeometry->SetRootID(IN_ChildID) < 0)
		return FALSE;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp								�쐬���F2001.06.25

	�P�D�@�\�T�v
	��ʗv�f�t�B�[�`���̍\���̎擾

	�Q�D�C���^�[�t�F�[�X
	LPVOID GetStructData(char *OUT_TypeName,size_t TypeNameSize)

	����:	�^			������				���e
			char*		OUT_TypeName		�t�B�[�`���^
			size_t		TypeNameSize		�o�b�t�@�T�C�Y

	���A�l	�\����

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.25			���X��(FQS)(FQS)	�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		JPCERT/CC �w�E �Ǝ㐫�Ή�
**/
//LPVOID SXFReadAP202MapManagerC::GetStructData(char *OUT_TypeName)
LPVOID SXFReadAP202MapManagerC::GetStructData(char *OUT_TypeName,size_t TypeNameSize)
{
	int FeatureType=0;
	LPVOID FeatureClass = NULL;
	LPVOID OUT_Struct = NULL;
	m_MapGeometry->SetFeatureParameter(FeatureType,FeatureClass);
//	MOD(S)	Ver3.0�Ή�	K.Naono	04.01.30
//	if (FeatureClass == NULL){
	if( FeatureType == 0 && FeatureClass == NULL ) {
//	MOD(E)	Ver3.0�Ή�	K.Naono	04.01.30
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(OUT_TypeName,"");
		strcpy_s(OUT_TypeName,TypeNameSize,"");
		return OUT_Struct;
	}
	m_MapGeometry->SetStructData(FeatureType,FeatureClass);
	//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//m_MapGeometry->GetStructData(OUT_TypeName,OUT_Struct);
	m_MapGeometry->GetStructData(OUT_TypeName,TypeNameSize,OUT_Struct);
	return OUT_Struct;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureC.cpp                        �쐬���F2001.06.17
//
//  �P�D�@�\�T�v
//      Assembly�\���̃A�h���X�̎擾(READ)
//      
//  �Q�D�C���^�[�t�F�[�X
//      LPVOID GetAssemblyStructData()
//
//	    ����: �^			  ������			    ���e
//			  �Ȃ�
//
//	    ���A�l	
//            ���펞�FAssembly�\���̂̃A�h���X
//			  �ُ펞�FNULL
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.17     ���X��(FQS)
//
//------------------------------------------------------------
LPVOID SXFReadAP202MapManagerC::GetAssemblyStructData()
{
	int AssemblyType=0;
	LPVOID AssemblyClass = NULL;
	LPVOID OUT_Struct = NULL;
	m_MapAssembly->SetFeatureParameter(AssemblyType,AssemblyClass);
	if (AssemblyClass == NULL){
		return OUT_Struct;
	}
	m_MapAssembly->SetStructData(AssemblyType,AssemblyClass);
	m_MapAssembly->GetStructData(OUT_Struct);
	return OUT_Struct;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadMapManagerC.cpp                   �쐬���F2001.03.21

  �P�D�@�\�T�v
      �t�B�[�`���\���̕ԋp�ς݃t���O��ON�ɂ���(READ)
      
  �Q�D�C���^�[�t�F�[�X
      void SetReturnFlag()

	    ����: �^		������		���e
			  �Ȃ�

	    ���A�l	
			  �Ȃ�

  �R�D����
	    ����ԍ�    ���t��         �S����    �T�v
      �쐬		2001.03.21     ���X��(FQS)

**/
void SXFReadAP202MapManagerC::SetReturnFlag()
{
}
