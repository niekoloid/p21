//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//	�P�D�N���X�T�v
//      �t�@�C���̏o�͂��Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//		�X�V		2002.02.20	K.Naono		���C�Ή�
//
//---------------------------------------------------------
#include "stdafx.h"
#include <afx.h>
#include "SXFDataStructC.h"
#include "SXFPart21FileC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      �R���X�g���N�^
//
//  �Q�D�C���^�[�t�F�[�X
//
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
SXFPart21FileWriteC::SXFPart21FileWriteC()
{
	//initialization
	m_HeadSection.Level = -1;
	m_HeadSection.Mode = -1;
	m_HeadSection.FileName.Empty();
	m_HeadSection.Author.Empty();
	m_HeadSection.Organization.Empty();
	m_HeadSection.Version.Empty();
	m_HeadSection.OriginatingSystem.Empty();
	m_File = NULL;

}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      �f�X�g���N�^
//
//  �Q�D�C���^�[�t�F�[�X
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
SXFPart21FileWriteC::~SXFPart21FileWriteC()
{
	if(m_File!=NULL)
		delete m_File;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      �t�@�C���̃I�[�v��
//
//  �Q�D�C���^�[�t�F�[�X
//      int OpenPart21WriteFile(LPCTSTR IN_FileName )
//
//	    ����: �^			  ������			    ���e
//            LPCTSTR         IN_FileNamer         File Name
//
//	    ���A�l	
//            ���펞�F 0
//			  �ُ펞�F���̑�
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
int SXFPart21FileWriteC::OpenPart21WriteFile(LPCTSTR IN_FileName )
{
	CString infilename=IN_FileName;
	CString pathname;
//	DEL(S)	���C�Ή�	K.Naono	02.02.20
/*
    ULARGE_INTEGER freebytestocaller;
    ULARGE_INTEGER totalbytes;
    ULARGE_INTEGER totalfreebytes;

    int findbackslash = infilename.ReverseFind('\\');
    if( findbackslash != -1 ){ //filename with a path
        pathname = infilename.Left(findbackslash+1);
		//�󂫗e�ʂ̃`�F�b�N
		GetDiskFreeSpaceEx( pathname,  // pointer to the directory name
							&freebytestocaller, // receives the number of bytes on
												// disk available to the caller
							&totalbytes,        // receives the number of bytes on disk
							&totalfreebytes     // receives the free bytes on disk
							);
    }else{ //file name without a path
        //check the free disk space
		GetDiskFreeSpaceEx( NULL,  // pointer to the current directory
							&freebytestocaller, // receives the number of bytes on
												// disk available to the caller
							&totalbytes,        // receives the number of bytes on disk
							&totalfreebytes     // receives the free bytes on disk
							);
    }
*/
//	DEL(E)	���C�Ή�	K.Naono	02.02.20

	TRY
	{
		m_File = new SXFPart21FileC(IN_FileName,CFile::modeCreate |
			CFile::modeWrite | CFile::shareExclusive);
	}
	CATCH( CFileException, e )
	{
		/* �f�B�X�N�ɏ������߂܂��� */
		if (e->m_cause == CFileException::diskFull){
			SXFErrorMsgC::RecordError(SXFDISC,"",0);
			return SXFDISC;
		}
		else if (e->m_cause == CFileException::fileNotFound){
			/* �w�肳�ꂽ�t�@�C���܂��̓f�B���N�g����������܂��� */
			SXFErrorMsgC::RecordError(SXFFILEDIRECTORY,"",1,IN_FileName);
			return SXFFILEDIRECTORY;
		}
		else{
			/* STEP�t�@�C���̃I�[�v���Ɏ��s���܂��� */
			SXFErrorMsgC::RecordError(SXFNOTOPENSTEPFILE,"",1,IN_FileName);
			return SXFNOTOPENSTEPFILE;
		}
	}
	END_CATCH

	return 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      Head Section Data�̐ݒ�
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL SetHeadSection( int  *IN_Level,
//                           int  *IN_Mode,
//                           char *IN_FileName,
//                           char *IN_Author,
//                           char *IN_Organization,
//                           char *IN_Version,
//                           char *IN_OriginatingSystem )
//
//	    ����: �^			  ������			    ���e
//            int  *          IN_Level
//            int  *          IN_Mode
//            char *          IN_FileName
//            char *          IN_Author
//            char *          IN_Organization
//            char *          IN_Version
//            char *          IN_OriginatingSystem
//
//	    ���A�l	
//            ���펞�F TRUE
//			  �ُ펞�F FALSE
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------

BOOL SXFPart21FileWriteC::SetHeadSection(	int  *IN_Level,
											int  *IN_Mode,
											char *IN_FileName,
											char *IN_Author,
											char *IN_Organization,
											char *IN_Version,
											char *IN_OriginatingSystem )
{
	m_HeadSection.Level = *IN_Level ;
	m_HeadSection.Mode = *IN_Mode;
	m_HeadSection.FileName = IN_FileName;  
	m_HeadSection.Author = IN_Author;
	m_HeadSection.Organization = IN_Organization;
	m_HeadSection.Version = IN_Version;
	m_HeadSection.OriginatingSystem = IN_OriginatingSystem;

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      Head Section Data�̏o��
//
//  �Q�D�C���^�[�t�F�[�X
//      int WriteHeadSection( )
//
//	    ����: �^			  ������			    ���e
//				�Ȃ�
//
//	    ���A�l	
//            ���펞�F 0
//			  �ُ펞�F ���̑�
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
int SXFPart21FileWriteC::WriteHeadSection( )
{
    if (m_File == NULL){
		/* �t�@�C�����I�[�v������Ă��܂��� */
		SXFErrorMsgC::RecordError(SXFSTEPFILENOTOPEN,"",0);		
		return SXFSTEPFILENOTOPEN;
	}
	TRY{
		m_File->WriteHeadSection(&m_HeadSection);
	}
	CATCH( CFileException, e ){
		/* �f�B�X�N�ɏ������߂܂��� */
		SXFErrorMsgC::RecordError(SXFDISC,"",0);
		return SXFDISC;
	}
	END_CATCH

	return 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      Feature Comment Instance�̏o��
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL WriteFeatureInstance(INSTANCEDATA* feature)
//
//	    ����: �^			  ������			    ���e
//            INSTANCEDATA*   feature              Instance Data��
//                                                 �\���̂̃A�h���X
//
//	    ���A�l	
//            ���펞�F TRUE
//			  �ُ펞�F FALSE
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
BOOL SXFPart21FileWriteC::WriteFeatureInstance(INSTANCEDATA* feature)
{
	/* STEP�t�@�C�����I�[�v������Ă��܂��� */
	if ( m_File == NULL )//have not a file to write
		return FALSE;

	if(m_HeadSection.Mode == 2){	// if not 0:ambilateral mode
									// or not 1:Feature mode or
		return FALSE;
	}

	if( feature->InstanceMode != SXF_IM_FT_ENTITY &&
		feature->InstanceMode != SXF_IM_FT_TABLE  &&
		feature->InstanceMode != SXF_IM_FT_ASSEMBLY)
	{
		return FALSE;
	}

	TRY{
		m_File->WriteInstance( feature );
	}
	/* �f�B�X�N�ɏ������߂܂��� */
	CATCH( CFileException, e ){
		//�f�B�X�N�������ς��ł�
		if( e->m_cause == CFileException::diskFull){
			return FALSE;
		//�t�@�C����������܂���
		}else if (e->m_cause == CFileException::fileNotFound ){
			return FALSE;
		// ���̑��̃G���[
		}else{
			return FALSE;
		}
	}
	END_CATCH

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      �t�@�C���̃N���[�Y
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL ClosePart21WriteFile(  )
//
//	    ����: �^			  ������			    ���e
//					�Ȃ�
//
//	    ���A�l	
//            ���펞�F TRUE
//			  �ُ펞�F FALSE
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
BOOL SXFPart21FileWriteC::ClosePart21WriteFile(  )
{
	/*����t�@�C��������܂���*/
	if (m_File == NULL)
		return FALSE;
	CString endsec;
	CString endline("\n");
	endsec="ENDSEC;";
	endsec+=endline;
	endsec+="END-ISO-10303-21;";
	endsec+=endline;
	m_File->WriteString(endsec);
	m_File->Close();

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              �쐬���F2000.03.26
//
//  �P�D�@�\�T�v
//      �ϊ��Ǘ�����t�@�C���̃n���h�����擾
//
//  �Q�D�C���^�[�t�F�[�X
//      SXFPart21FileC* GetFileHandle()
//
//	    ����: �^			  ������			    ���e
//						�Ȃ�
//	    ���A�l	
//            ���펞�F SXFPart21FileC�̃A�h���X
//			  �ُ펞�F 
//
//	�R�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.26   ��
//---------------------------------------------------------
SXFPart21FileC* SXFPart21FileWriteC::GetFileHandle()
{
	return m_File;
}
