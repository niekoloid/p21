/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		Complex�^EntityArrayData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntCConvC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
//#include "ComSplitStringC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntCConvC::SXFMapEntCConvC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntCConvC::SXFMapEntCConvC()
{
	//������
	m_EntityArray = &m_EntityArrayTempEntC;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		Complex�^�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntCConvC::SXFMapEntCConvC(
					CStringArray*		IN_ComplexArray)
					

	���� �F	�^				������				���e
			CStringArray*	IN_ComplexArray		Complex�^�G���e�B�e�B�f�[�^

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntCConvC::SXFMapEntCConvC(
		CStringArray*	IN_ComplexArray)

{
	m_ComplexArray = IN_ComplexArray;
	m_EntityArray = &m_EntityArrayTempEntC; 

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntCConvC::~SXFMapEntCConvC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntCConvC::~SXFMapEntCConvC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		Complex�^EntityArrayData�̓o�^

	�Q�D�C���^�[�t�F�C�X
		BOOL	SetCompelexArray(
					CStringArray*		IN_ComplexArray)

  	���� �F	�^				������				���e
  			CStringArray*	IN_ComplexArray		Complex�^�G���e�B�e�B�f�[�^

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL	SXFMapEntCConvC::SetCompelexArray(
			CStringArray*	IN_ComplexArray)	//Complex�^�G���e�B�e�B�f�[�^
{
	m_ComplexArray = IN_ComplexArray;
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�w�肳�ꂽ�G���e�B�e�B���̃f�[�^�����o���o�^

	�Q�D�C���^�[�t�F�C�X
		BOOL	SplitComplex(
					CString& IN_EntityName);<�G���e�B�e�B��>

	����  �F	�^			������				���e
				CString& 	IN_EntityName		�G���e�B�e�B��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL	SXFMapEntCConvC::SplitComplex(
					CString& IN_EntityName)	//<�G���e�B�e�B��>

{
	m_EntityName  = IN_EntityName;
	m_EntityArray->RemoveAll();
	CString	IN_Str;
	IN_Str.Empty();
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
	CStringArray	array ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
	for (int i=0; i< m_ComplexArray->GetSize();i++){
		if ((*m_ComplexArray)[i].Left(m_EntityName.GetLength()) == m_EntityName ){
			IN_Str = (*m_ComplexArray)[i];
			IN_Str.TrimLeft();
			IN_Str.TrimLeft(m_EntityName);

//			CStringArray* IN_EntityArray;

			IN_Str.Delete(0,1);
			CString temp = IN_Str;
			IN_Str.Delete(temp.GetLength()-1,1);
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
			ComSplitStringC split(IN_Str);
			IN_EntityArray = split.Split(',');
			m_EntityArray->Copy(*IN_EntityArray); 
*/
			if( GFn_SplitString(IN_Str, ',' , array) > 0 )
				m_EntityArray->Copy(array) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
	
			return TRUE;
		}
	}

	// ERR 
	return FALSE;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�w�肳�ꂽ�G���e�B�e�B���̃f�[�^�����o���o�^

	�Q�D�C���^�[�t�F�C�X
		BOOL	SplitComplex(
					char* IN_EntityName);<�G���e�B�e�B��>

	����  �F	�^			������				���e
				char*		IN_EntityName			�G���e�B�e�B��	

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL	SXFMapEntCConvC::SplitComplex(
					char* IN_EntityName)	//<�G���e�B�e�B��>

{
	m_EntityName  = IN_EntityName;

	m_EntityArray->RemoveAll();

	CString	IN_Str;
	IN_Str.Empty();
	for (int i=0; i< m_ComplexArray->GetSize();i++){
		if ((*m_ComplexArray)[i].Left(m_EntityName.GetLength()) == m_EntityName ){
			IN_Str = (*m_ComplexArray)[i];
			IN_Str.TrimLeft();
			IN_Str.TrimLeft(m_EntityName);
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
			CStringArray* IN_EntityArray;

			int IN_Mode = 2; 
			SXFSplitAP202C  split(IN_Mode, IN_Str) ;
			IN_EntityArray = split.Split();

			m_EntityArray->Copy(*IN_EntityArray); 
*/
			CStringArray	IN_EntityArray ;
			if( GFn_SplitSEntityAttr(IN_Str, IN_EntityArray) > 0 )
				m_EntityArray->Copy(IN_EntityArray) ; 
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

			return TRUE;
		}
	}

	// ERR 
	return FALSE;

}
