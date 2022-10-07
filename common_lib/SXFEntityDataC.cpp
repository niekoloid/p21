//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  �쐬���F2001.06.07
//
//	�P�D�N���X�T�v
//      �G���e�B�e�B�f�[�^��ێ�����I�u�W�F�N�g     
//      
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.07     ���X��(FQS)
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFDataStructC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
#include "SXFEntityDataC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//  SXFEntityDataC.cpp	                  �쐬���F2001.06.07
//
//  �P�D�@�\�T�v
//      �N���X�\�z
//
//  �Q�D�C���^�[�t�F�[�X
//		SXFEntityDataC::SXFEntityDataC()
//
//	    ����: �^			  ������			    ���e
//					�Ȃ�   
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.07     ���X��(FQS)
//
//------------------------------------------------------------
SXFEntityDataC::SXFEntityDataC()
{

	//������
	m_InstanceMode = -1;
	m_InstanceID = -1;
	m_EntityName.Empty();
	m_EntityDataPtr = NULL;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  �쐬���F2001.06.07
//
//  �P�D�@�\�T�v
//      �N���X����
//
//  �Q�D�C���^�[�t�F�[�X
//		SXFEntityDataC::~SXFEntityDataC()
//
//	    ����: �^			  ������			    ���e
//					�Ȃ�   
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.07     ���X��(FQS)
//
//------------------------------------------------------------
SXFEntityDataC::~SXFEntityDataC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  �쐬���F2001.06.07
//
//  �P�D�@�\�T�v
//      Entity Data �̐ݒ�
//      
//  �Q�D�C���^�[�t�F�[�X
//      BOOL SetEntityData(LPVOID& IO_DataInFilePtr,
//                         INSTANCEDATA *IN_Instance)
//	    ����: �^				������				���e
//				LPVOID&			IO_DataInFilePtr	MappingFile��
//													���ʂ̃A�h���X
//				size_t			AvailableSize		IO_DataInFilePtr ���g����c��T�C�Y
//				INSTANCEDATA*	IN_Instance			Instance Data
//													�\���̂̃A�h���X
//		���A�l
//			  size_t	����g�p�����T�C�Y
//
//  �R�D����
//	    ����ԍ�    ���t��			�S����			�T�v
//      �쐬		2001.06.07		���X��(FQS)
//		�X�V		2015.04.27		T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�
//
//------------------------------------------------------------
//BOOL SXFEntityDataC::SetEntityData(LPVOID& IO_DataInFilePtr,INSTANCEDATA *IN_Instance)
size_t SXFEntityDataC::SetEntityData(LPVOID& IO_DataInFilePtr,size_t AvailableSize,INSTANCEDATA *IN_Instance)
{

	m_EntityName = IN_Instance->EntityName;
	m_InstanceID = IN_Instance->InstanceID;
	m_InstanceMode = IN_Instance->InstanceMode;
	m_EntityDataPtr = ( LPTSTR )IO_DataInFilePtr;
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy(m_EntityDataPtr,IN_Instance->EntityData);
	//IO_DataInFilePtr = ( LPTSTR )IO_DataInFilePtr + 
	//							strlen(m_EntityDataPtr) + 1;
	//return TRUE;

	strcpy_s(m_EntityDataPtr,AvailableSize,IN_Instance->EntityData);
	size_t len = strlen(m_EntityDataPtr) + 1;
	IO_DataInFilePtr = ( LPTSTR )IO_DataInFilePtr + len;

	return len;	// �߂�l�͍���g�p�����T�C�Y��Ԃ�
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  �쐬���F2001.06.07
//
//  �P�D�@�\�T�v
//      Instance��Entity Data���̎擾
//      
//  �Q�D�C���^�[�t�F�[�X
//      BOOL GetEntityData(CString& OUT_EntityData)
//	    ����: �^			  ������			    ���e
//            CString&        OUT_EntityData       Instance��
//                                                 Entity Data�� 
//      
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.07     ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFEntityDataC::GetEntityData(CString& OUT_EntityData)
{
	//�f�[�^��Null�̏ꍇ
	if(m_EntityDataPtr == NULL)
		return FALSE; 

	OUT_EntityData = m_EntityDataPtr;

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  �쐬���F2001.06.07
//
//  �P�D�@�\�T�v
//      Instance��Entity Data���̎擾�i��������StringArray�j
//      
//  �Q�D�C���^�[�t�F�[�X
//      BOOL GetEntityDataArray(CStringArray& OUT_EntityDataArray)
//	    ����: �^			  ������			    ���e
//            CStringArray&   OUT_EntityDataArray  ����������
//                                                 Entity Data�� 
//      
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.07     ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFEntityDataC::GetEntityDataArray(CStringArray& OUT_EntityDataArray)
{
	CString entitydata;

	int mode = 0;

	//�f�[�^��NULL
	if( ! GetEntityData(entitydata) )
		return FALSE; 

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	//complex AP202 instance
	if(m_EntityName == "SXF_COMPLEX_INSTANCE"){
		mode = 1;
	//common instance
	}else{
		mode = 2;
	}

	CStringArray* array;

	SXFSplitAP202C splitap202(mode,entitydata);
    
	array = splitap202.Split();

	if(array==NULL)
		return FALSE;

	OUT_EntityDataArray.Copy( *array );
*/
	int				nCount = 0 ;
	CStringArray	array ;

	//	�����G���e�B�e�B�̏ꍇ
	if(m_EntityName == DEF_SXF_COMPLEX_INSTANCE){
		nCount = GFn_SplitCEntityAttr(entitydata, array) ;

	//	�P���G���e�B�e�B�̏ꍇ
	} else {
		nCount = GFn_SplitSEntityAttr(entitydata, array) ;
	}

	if( nCount )
		OUT_EntityDataArray.Copy(array) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return TRUE;
}
