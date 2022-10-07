/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�N���X�T�v
		�C���X�^���X��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
#include "stdafx.h"
#include "SXFD_InstC.h"
#include "SXFPart21FileC.h"
#include "SXF_EXT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMapPtrToPtr *SXFInstanceC::m_deleteMap = NULL;

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_InstC( )
	����:	�^				������				���e
			�Ȃ�				
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_InstC::SXFD_InstC() { 
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_InstC( )
	����:	�^				������				���e
			int				i					�C���X�^���X�h�c
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_InstC::SXFD_InstC(int i) {
	m_InstanceID = i;
	m_Flg = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFD_InstC::~SXFD_InstC( )

	����:	�^				������				���e
			�Ȃ�				

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_InstC::~SXFD_InstC( ) {
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
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�G���e�B�e�B���̃Z�b�g
		
	�Q�D�C���^�[�t�F�C�X
	SetEntity( CString ent )
	����:	�^				������				���e
			CString			ent					�G���e�B�e�B��				
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_InstC::SetEntity( CString ent ) {
	m_Entity = ent ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�v�f�̃Z�b�g
		
	�Q�D�C���^�[�t�F�C�X
	AddAttr( CObject* data ) 
	����:	�^				������				���e
			CObject*		data				�ݽ�ݽ
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_InstC::AddAttr( CObject* data ) {
	m_Data.AddTail(data) ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�C���X�^���X���o��
		
	�Q�D�C���^�[�t�F�C�X
	WriteP21(SXFPart21FileC *IN_file)
	����:	�^					������				���e
			SXFPart21FileC*		IN_file			̧�ٵ�޼ު��
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_InstC::WriteP21(SXFPart21FileC *IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		CString insID;
		insID.Format("#%d=%s",m_InstanceID,m_Entity);
		IN_file->WriteString(insID);

		int flg = 0;
		for(pos = m_Data.GetHeadPosition(); pos != NULL;) {
	
			if(flg == 0){
				IN_file->WriteString("(");
				flg =1;
			}
			else{
				IN_file->WriteString(",");
			}

			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);

		}
		IN_file->WriteString(");\n");
		m_Flg = 0;

	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2001.06.12

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
void	SXFD_InstC::WriteAttr(SXFPart21FileC *IN_file) {
	CString insID;
	insID.Format("#%d",m_InstanceID);
	IN_file->WriteString(insID);
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2001.06.23
	SXFD_InstC.cpp

	�P�D�@�\�T�v
	�@�@�����̌^���擾

	�Q�D�C���^�[�t�F�C�X
		SXFD_InstC::GetAttr( )

	�����F�^		������		���e
		�@�Ȃ��@�@�@

	���A�l�F���͂��ꂽ������������΁A�����̌^��ԋp����B
			�Ȃ����́ANULL��ԋp����B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2001.06.23	�@�@���X��(FQS)	�Ȃ��B
**/
CObList&	SXFD_InstC::GetAttr( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2001.06.23
	SXFD_InstC.cpp

	�P�D�@�\�T�v
	�@�@ID���擾

	�Q�D�C���^�[�t�F�C�X
		SXFD_InstC::GetInsID( )

	�����F�^		������		���e
		�@�Ȃ��@�@�@

	���A�l�F���펞�F�C���X�^���XID
			�ُ펞�FNULL

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2001.06.23	�@�@���X��(FQS)	�Ȃ��B
**/
int		SXFD_InstC::GetInsID( ) {
	return m_InstanceID ;
}

