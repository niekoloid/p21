/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�N���X�T�v
		�W���̌^�̗v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
#include "stdafx.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	~SXFD_AggrC( )
	����:	�^								������				���e
			�Ȃ�
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_AggrC::~SXFD_AggrC( ) {
	CObject	*obj ;
	for( POSITION pos = m_Data.GetHeadPosition(); pos != NULL; ) {
		obj = m_Data.GetNext( pos ) ;
		if(obj) {
			if (CheckDeleteable(obj)) {
				AddDeleted(obj);
				delete obj ;
			}
			else {
				CObject *o = obj;
			}
		}
	}
	m_Data.RemoveAll() ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�v�f��ǉ�����
		
	�Q�D�C���^�[�t�F�C�X
	void AddElem( CObject* obj )
	����:	�^								������				���e
			CObject							IN_obj			�v�f			
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_AggrC::AddElem( CObject* IN_obj ) {
	m_Data.AddTail(IN_obj) ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�����om_Data���폜����
		
	�Q�D�C���^�[�t�F�C�X
	void�@RemoveTail
	����:	�^								������				���e
			�Ȃ�					
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_AggrC::RemoveTail( ) {
	m_Data.RemoveTail() ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�����om_Data���폜����
		
	�Q�D�C���^�[�t�F�C�X
	void�@Remove
	����:	�^								������				���e
			�Ȃ�					
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void SXFD_AggrC::Remove( ) {
	m_Data.RemoveAll() ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�����om_Data��ԋp
		
	�Q�D�C���^�[�t�F�C�X
	void�@GetData
	����:	�^								������				���e
			�Ȃ�					
	���A�l	m_Data
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
CObList& SXFD_AggrC::GetData(){
	return m_Data;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�v�f���o��
		
	�Q�D�C���^�[�t�F�C�X
	void WriteAttr(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC*					IN_file				SXFPart21FileC�ւ̃|�C���^
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void SXFD_AggrC::WriteAttr(SXFPart21FileC *IN_file){
	int flg = 0;
	for( POSITION pos = m_Data.GetHeadPosition(); pos != NULL;) {

		if(flg == 0){
			IN_file->WriteString("(");
			flg =1;
		}
		else{
			IN_file->WriteString(",");
		}

		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);

	}
	IN_file->WriteString(")");
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�C���X�^���X���o��
		
	�Q�D�C���^�[�t�F�C�X
	void WriteP21(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC*					IN_file				SXFPart21FileC�ւ̃|�C���^
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void SXFD_AggrC::WriteP21(SXFPart21FileC *IN_file){

	for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

		((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

	}

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�v�f���󂩂ǂ����m���߂�
		
	�Q�D�C���^�[�t�F�C�X
	BOOL Is_Empty
	����:	�^								������				���e
			�Ȃ��B
	���A�l	��FTRUE
			�v�f����FFALSE
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
BOOL SXFD_AggrC::Is_Empty(){
	//��̏ꍇ
	if (m_Data.IsEmpty())
		return TRUE;
	else
		return FALSE;
}

