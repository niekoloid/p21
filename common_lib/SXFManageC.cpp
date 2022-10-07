/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�N���X�T�v
	�ϊ��Ǘ��N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "SXFManageC.h"
#include "SXFComInfoC.h"
#include "SXF_EXT.h"
#include "SXFErrorMsgC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFTableManagerC.h"
#include "SXFWriteManagerC.h"
#include "SXFInstanceIDC.h"
#include "SXFPart21FileReadC.h"
#include "SXFEntitySchemaC.h"
#include "SXFAPI_RevInfo.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFManageC::SXFManageC()
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
SXFManageC::SXFManageC()
{
	m_Assem_type = -1;
	m_WriteFile = NULL;
	m_TableManager = NULL;
	m_WriteManager = NULL;
	m_ReadFile = NULL;
	m_InstanceIDManager = NULL;
	m_ReadAP202Manager = NULL;
	m_ReadExHatchFile = NULL;
	m_ExHatchFileInstanceIDManager = NULL;
	m_ExHatchFileTableManager = NULL;
	m_ExHatchFileReadAP202Manager = NULL;
	m_ReadExSymbolFile = NULL;
	m_ExSymbolFileInstanceIDManager = NULL;
	m_ExSymbolFileTableManager = NULL;
	m_ExSymbolFileReadAP202Manager = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFManageC::~SXFManageC()
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
SXFManageC::~SXFManageC()
{
	if (m_WriteFile != NULL)
		delete m_WriteFile;
	if (m_WriteManager != NULL)
		delete m_WriteManager;
	if (m_ReadFile != NULL)
		delete m_ReadFile;
	if (m_InstanceIDManager != NULL)
		delete m_InstanceIDManager;
	if (m_ReadAP202Manager != NULL)
		delete m_ReadAP202Manager;
	if (m_TableManager != NULL)
		delete m_TableManager;
	if (m_ReadExHatchFile != NULL)
		delete m_ReadExHatchFile;
	if (m_ExHatchFileInstanceIDManager != NULL)
		delete m_ExHatchFileInstanceIDManager;
	if (m_ExHatchFileTableManager != NULL)
		delete m_ExHatchFileTableManager;
	if (m_ExHatchFileReadAP202Manager != NULL)
		delete m_ExHatchFileReadAP202Manager;
	if (m_ReadExSymbolFile != NULL)
		delete m_ReadExSymbolFile;
	if (m_ExSymbolFileInstanceIDManager != NULL)
		delete m_ExSymbolFileInstanceIDManager;
	if (m_ExSymbolFileTableManager != NULL)
		delete m_ExSymbolFileTableManager;
	if (m_ExSymbolFileReadAP202Manager != NULL)
		delete m_ExSymbolFileReadAP202Manager;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�t�@�C�����I�[�v������

	�Q�D�C���^�[�t�F�[�X
	int Open(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char IN_author[257], char IN_org[257],char IN_translator_name[257],char OUT_version[257]);
	����:	�^				������			���e
			char			IN_file_name		�t�@�C����
			int				IN_rw_flg			�ǂݏ����t���O
			double			IN_tolerance1		���e�덷
			double			IN_tolerance2		�p�x�p���e�덷
			double			IN_divide			�_�E���R���o�[�g�p���e�덷
			int				IN_level			���x��(1or2)
			int				IN_mode				���[�h (0:���p
														1:�t�B�[�`���R�����g
														2:AP202�j
			char			IN_author			�t�@�C���쐬��
			char			IN_org				�쐬�ҏ���
			char			IN_translator_name	�g�����X���[�^��
			char			OUT_version			���ʃ��C�u�����o�[�W����
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Open(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char INOUT_author[257], char INOUT_org[257],char INOUT_translator_name[257],char OUT_version[257])
{

	int ret;
	/////////////////////////////
	//�G���[���O�t�@�C���I�[�v��
	/////////////////////////////
	gl_log_file = new ofstream("outAP202.log",ios::out);
	if(gl_log_file->fail()){
		delete gl_log_file;
		gl_log_file = NULL;
		cerr << "Error opening outAP202.log" << endl;
		return -1;
	}

	////////////////////////////
	//�����̃`�F�b�N
	////////////////////////////
	if ((ret = Param_Check(IN_rw_flg,IN_level,IN_mode)) < 0)
		return ret;

	////////////////////////////
	//		READ
	////////////////////////////
	if (IN_rw_flg == 0){//read
		//���ʏ��o�^
		m_Info.Set_Read_Come(IN_file_name,IN_rw_flg,IN_tolerance1,IN_tolerance2,IN_divide,IN_level,IN_mode);
		//�C���X�^���X�h�c�I�u�W�F�N�g����
		m_InstanceIDManager = new SXFInstanceIDC();
		//�e�[�u���Ǘ��I�u�W�F�N�g�̐���
		m_TableManager = new SXFTableManagerC(&m_Info,m_InstanceIDManager);

		//AP202Read�Ǘ��I�u�W�F�N�g����
		m_ReadAP202Manager = new SXFReadAP202ManagerC(m_InstanceIDManager,m_TableManager,&m_Info);

		//�t�@�C�����̓I�u�W�F�N�g����
		m_ReadFile = new SXFPart21FileReadC(m_TableManager,m_ReadAP202Manager,&m_Info,m_InstanceIDManager);

		//�t�@�C���̃I�[�v��
#ifdef _DEBUG
		clock_t	start = clock() ;
#endif
#ifdef _RELEASE
		clock_t	start = clock() ;
#endif

		ret = m_ReadFile->OpenPart21ReadFile(IN_file_name);
		if (ret < 0)
			return ret;
#ifdef _DEBUG
		clock_t	finish = clock() ;
		double	duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("OpenPart21ReadFile():%2.1f �b�ł��B\n", duration) ;
#endif
#ifdef _RELEASE
		clock_t	finish = clock() ;
		double	duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("OpenPart21ReadFile():%2.1f �b�ł��B\n", duration) ;
#endif

		/////////////////////////////////////////
		//Part21�t�@�C���̃`�F�b�N
		/////////////////////////////////////////
#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif

		SXFEntitySchemaC exec;
		exec.part21 = m_ReadFile;
		exec.EntitySchemaCheck();
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("EntitySchemaCheck():%2.1f �b�ł��B\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("EntitySchemaCheck():%2.1f �b�ł��B\n", duration) ;
#endif

		/////////////////////////////////////////
		//�w�b�_���擾
		/////////////////////////////////////////
#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif
		int FileLevel = -1;
		int FileMode = -1;
		char FileName[257];
		CString	strOutVersion;
		m_ReadFile->GetHeadData(&FileLevel,&FileMode,FileName,INOUT_author,INOUT_org,strOutVersion.GetBuffer(257),INOUT_translator_name);
		strOutVersion.ReleaseBuffer();
		//�t�@�C���o�[�W�����̎擾
		int pos = strOutVersion.Find("$$");
		if (pos == -1)
		{
			//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
			//strcpy(OUT_version, (LPCTSTR)strOutVersion);
			// �o�b�t�@�T�C�Y�͎d�l�����擾
			strcpy_s(OUT_version, 257, (LPCTSTR)strOutVersion);
			gl_FileVersion.Empty();
		}
		else
		{
			//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
			//strcpy(OUT_version, strOutVersion.Left(pos));
			// �o�b�t�@�T�C�Y�͎d�l�����擾
			strcpy_s(OUT_version, 257, strOutVersion.Left(pos));
			gl_FileVersion = strOutVersion.Mid(pos + 2);
		}
		//���[���`�F�b�N�I�u�W�F�N�g�Ƀe�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X��n���B
		m_rulecheck.m_TableManager = m_TableManager;
		//���[���`�F�b�N�I�u�W�F�N�g�ɋ��ʏ��Ǘ��̃A�h���X��n���B
		m_rulecheck.m_ComInfo = &m_Info;
		//���[���`�F�b�N�I�u�W�F�N�g��ReadAP202�Ǘ��I�u�W�F�N�g�̃A�h���X��n���B
		m_rulecheck.m_ReadAP202Manager = m_ReadAP202Manager;
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("�w�b�_���擾:%2.1f �b�ł��B\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("�w�b�_���擾:%2.1f �b�ł��B\n", duration) ;
#endif

#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif
		if( !m_TableManager->MappingAP202Table() )
			return -1;
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("MappingAP202Table():%2.1f �b�ł��B\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("MappingAP202Table():%2.1f �b�ł��B\n", duration) ;
#endif

#ifdef _DEBUG
		start = clock() ;
#endif
#ifdef _RELEASE
		start = clock() ;
#endif
		if( ! m_ReadAP202Manager->ArrangeChild(0) )//�����O�FStepFile�ǂݍ��ݎ�
			return -1;
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("ArrangeChild():%2.1f �b�ł��B\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("ArrangeChild():%2.1f �b�ł��B\n", duration) ;
#endif

	}
	////////////////////////////
	//		WRITE
	////////////////////////////
	else if (IN_rw_flg == 1){//write
		//���ʏ��o�^
		m_Info.Set_Write_Come(IN_file_name,IN_rw_flg,IN_tolerance1,IN_tolerance2,IN_divide,IN_level,IN_mode,INOUT_author,INOUT_org,INOUT_translator_name);
		//�O���ϐ�������
		gl_InstanceID = 20;
		//�t�@�C���I�[�v��
		m_WriteFile = new SXFPart21FileWriteC();
		ret = m_WriteFile->OpenPart21WriteFile(IN_file_name);
		if (ret < 0){
			gl_log_file->close();
			delete gl_log_file;
			gl_log_file = NULL;
			return ret;
		}
		////////////////////////////
		//�o�[�W�����̐ݒ�
		////////////////////////////
		CString	strVersion(SCADEC_API_RevInfo);
		if (!gl_FileVersion.IsEmpty())
		{
			//�t�@�C���o�[�W�����t��
			strVersion += "$$";
			strVersion += gl_FileVersion;
		}
		char Version[257];
//		strcpy(Version,(LPCTSTR)strVersion);	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		strcpy_s(Version,_countof(Version),(LPCTSTR)strVersion);
		//////////////
		//�w�b�_�̏o��
		m_WriteFile->SetHeadSection(&IN_level,&IN_mode,IN_file_name,INOUT_author,INOUT_org,Version,INOUT_translator_name);
		ret = m_WriteFile->WriteHeadSection();
		if (ret < 0){
			gl_log_file->close();
			delete gl_log_file;
			gl_log_file = NULL;
			return ret;
		}
		//////
		//�C���X�^���X�h�c�I�u�W�F�N�g����
		m_InstanceIDManager = new SXFInstanceIDC();

/* 2006.03.13 �������擾�T�C�Y�̕ύX�i��e�ʃt�@�C���Ή��j ===> */
//		if( !m_InstanceIDManager->InitFileMapping( 500000 ) )
		if( !m_InstanceIDManager->InitFileMapping( 1000000 ) )
/* 2006.03.13 �������擾�T�C�Y�̕ύX�i��e�ʃt�@�C���Ή��j <=== */
			return -1;

		//�e�[�u���Ǘ��I�u�W�F�N�g�̐���
		m_TableManager = new SXFTableManagerC(m_WriteFile->GetFileHandle(),&m_Info,m_WriteFile,m_InstanceIDManager);
		//AP202�Ǘ��I�u�W�F�N�g�̐���
		m_WriteManager = new SXFWriteManagerC(m_WriteFile->GetFileHandle(),m_TableManager,&m_Info,m_WriteFile,m_InstanceIDManager);
		//���[���`�F�b�N�I�u�W�F�N�g�Ƀe�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X��n���B
		m_rulecheck.m_TableManager = m_TableManager;
		//���[���`�F�b�N�I�u�W�F�N�g��AP202�Ǘ��I�u�W�F�N�g�̃A�h���X��n���B
		m_rulecheck.m_WriteManager = m_WriteManager;
		//���[���`�F�b�N�I�u�W�F�N�g�ɋ��ʏ��Ǘ��̃A�h���X��n���B
		m_rulecheck.m_ComInfo = &m_Info;
		//�G���[���b�Z�[�W�p�C���X�^���XID�̓o�^
		//WRITE���̓f�t�H���g��"-"
		m_rulecheck.m_InstanceID = "-";

	}
	else{
		SXFErrorMsgC::RecordError(SXFRWFLAG,"",1,IN_rw_flg);		
		return SXFRWFLAG;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�t�@�C�����N���[�Y����

	�Q�D�C���^�[�t�F�[�X
	int Close();
	����:	�^				������			���e
			�Ȃ��B
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Close()
{
	//�t�@�C���o�[�W�������Z�b�g
	gl_FileVersion.Empty();

	int flg;
	m_Info.Get_Flg(flg);
	if (flg == 0){
		//�t�@�C���N���[�Y
		m_ReadFile->ClosePart21ReadFile();
		if (m_ReadExHatchFile != NULL)
			//�O����`�t�@�C��(�n�b�`)�N���[�Y
			m_ReadExHatchFile->ClosePart21ReadFile();
		if (m_ReadExSymbolFile != NULL)
			//�O����`�t�@�C��(�V���{��)�N���[�Y
			m_ReadExSymbolFile->ClosePart21ReadFile();
	}
	///////////////////////////////////////
	//WRITE���F�t�@�C���N���[�Y
	///////////////////////////////////////
	else if (flg == 1){
		//SHEET Mapping
		m_WriteManager->CloseAssembly();
		//LAYER Mapping
		m_TableManager->LayerMapping();
		//INVISIVILITY Mapping
		//LAYER
		m_TableManager->MappingInvisibility();
		//COMPOSITE_CURVE
		m_WriteManager->MappingInvisibility();
		//�t�@�C���N���[�Y
		m_WriteFile->ClosePart21WriteFile();
	}
	else
		return -1;

	///////////////////////////////////////
	//�G���[���O�t�@�C���N���[�Y
	///////////////////////////////////////
	gl_log_file->close();
	delete gl_log_file;
	gl_log_file = NULL;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�I�[�v�����ɓn���ꂽ�����i�ǂݏ����t���O�A���x���A���[�h�j�̃`�F�b�N���s���B

	�Q�D�C���^�[�t�F�[�X
	int Param_Check(int IN_rw_flg,int IN_level, int IN_mode)
	����:	�^				������			���e
			int				IN_rw_flg			�ǂݏ����t���O
			int				IN_level			���x��
			int				IN_mode				���[�h
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Param_Check(int IN_rw_flg,int IN_level, int IN_mode)
{
	//�ǂݏ����t���O�̃`�F�b�N
	if ((IN_rw_flg != 0) && (IN_rw_flg != 1)){
		SXFErrorMsgC::RecordError(SXFRWFLAG,"",1,IN_rw_flg);
		return SXFRWFLAG;
	}
	//���x���̃`�F�b�N
	switch (IN_level){
		/** 1�̂Ƃ����[�j���O�Ƃ��ď������s **/
		case 1:
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//			SXFErrorMsgC::RecordError(SXFWARNINGLEVEL,"",1,IN_level);
			SXFErrorMsgC::RecordError2(SXFWARNINGLEVEL,"",1,IN_level);
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			break;
		case 2:
			break;
		/** 1,2�ȊO�̂Ƃ��G���[���� **/
		default:
			SXFErrorMsgC::RecordError(SXFNOLEVEL,"",1,IN_level);
			return SXFNOLEVEL;
	}
	//���[�h�̃`�F�b�N
	switch (IN_mode){
		/** �O�C�P�̂Ƃ����[�j���O�Ƃ��ď������s **/
		case 0:
 		case 1:
//	MOD(S)	���b�Z�[�W�C��	K.Naono	04.03.05
//			SXFErrorMsgC::RecordError(SXFWARNINGMODE,"",1,IN_mode);
			SXFErrorMsgC::RecordError2(SXFWARNINGMODE,"",1,IN_mode);
//	MOD(E)	���b�Z�[�W�C��	K.Naono	04.03.05
			break;
		case 2:
			break;
		/** �O�C�P�C�Q�ȊO�̂Ƃ��G���[���� **/
		default:
			SXFErrorMsgC::RecordError(SXFNOMODE,"",1,IN_mode);
			return SXFNOMODE;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	��`�e�[�u���t�B�[�`�����t�@�C���ɏo�͂���

	�Q�D�C���^�[�t�F�[�X
	int Write_table(int IN_table_type, void* IN_str)
	����:	�^				������				���e
			int				IN_table_type		��`�e�[�u���^
			void*			IN_str				�\����
	���A�l	���펞�F�R�[�h
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Write_table(int IN_table_type, void* IN_str)
{
	//���[���`�F�b�N�I�u�W�F�N�g�Ăяo��
	int error_code = m_rulecheck.TableRuleCheck(IN_table_type,IN_str);

	if (error_code < 0)
		return error_code;
	else{
		//��`�e�[�u���Ǘ��ďo��
		int code = m_TableManager->RegisterStructTable(IN_table_type,IN_str);
		return code;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	���ʏ��Ǘ��I�u�W�F�N�g��Ԃ�

	�Q�D�C���^�[�t�F�[�X
	SXFComInfoC GetInfo()
	����:	�^				������				���e
	�Ȃ��B
	���A�l	m_Info
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
SXFComInfoC SXFManageC::GetInfo()
{
	return m_Info;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�A�Z���u���v�f�t�B�[�`�����t�@�C���ɏo�͂���
	
	�Q�D�C���^�[�t�F�[�X
	int Write_assembly_name(int IN_Assem_type, void *IN_Struct)
	����:	�^				������				���e
			int				IN_Assem_type		�A�Z���u���^
			void*			IN_Struct				�\����
	���A�l	���펞�F���ʃ��C�u�������ӂ�ԍ�
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Write_assembly_name(int IN_Assem_type, void *IN_Struct)
{
	//���[���`�F�b�N�I�u�W�F�N�g�Ăяo��
	int error_code = m_rulecheck.AssemblyRuleCheck(IN_Assem_type,IN_Struct);
	if (error_code < 0){
		m_WriteManager->ErrorAssembly();
		m_Assem_type = -1;
		return error_code ;
	}
	else{
		int Assem_code = m_WriteManager->RegisterAssembly(IN_Assem_type,IN_Struct);
		//���J����Ă���A�Z���u���^�C�v�A�G���[�̂Ƃ���-�P
		m_Assem_type = m_WriteManager->GetAssemType();
		return Assem_code;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	��ʗv�f�t�B�[�`�����t�@�C���ɏo�͂���

	�Q�D�C���^�[�t�F�[�X
	int Write_next_feature(char *IN_FeatureType, void *IN_Struct)
	����:	�^				������				���e
			char*			IN_FeatureType		�t�B�[�`���^
			void*			IN_Struct			�\����
	
	���A�l	���펞�F�C���X�^���X�ԍ�
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Write_next_feature(char *IN_FeatureType, void *IN_Struct)
{
	//���[���`�F�b�N�I�u�W�F�N�g�Ăяo��
	int error_code = m_rulecheck.FeatureRuleCheck(m_Assem_type,IN_FeatureType,IN_Struct);
	if (error_code < 0){
		return error_code ;
	}
	else{
		error_code = m_WriteManager->RegisterFeature(IN_FeatureType,IN_Struct);
		return error_code;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	��`�e�[�u���v�f�����ŁA�\���̂�Ԃ�

	�Q�D�C���^�[�t�F�[�X
	int Read_table(int IN_TableType, LPVOID &OUT_Struct, int &OUT_EndFlag)
	����:	�^				������				���e
			int				IN_TableType		�e�[�u���^
			LPVOID&			OUT_Struct			�\����
			int&			OUT_EndFlag			�I���t���O�i�O�F�p���A�P�F�㑱�Ȃ��j
	���A�l	���펞�F�R�[�h
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Read_table(int IN_TableType, LPVOID OUT_Struct, int* OUT_EndFlag)
{	
	//�\���̂̎�肾��
	int code = m_TableManager->GetTableElement(IN_TableType,OUT_Struct,OUT_EndFlag);
	if (code < 0)
		return code;
	//���[���`�F�b�N
	//OPEN���Ƀ��[���`�F�b�N�ς�
	//���x���̃`�F�b�N�̂ݍs��
	int error_code = m_rulecheck.TableRuleCheck(IN_TableType,OUT_Struct);
	if (error_code < 0)
		return error_code;
	return code;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	�A�Z���u���v�f��ǂ݂���ŁA�\���̂�Ԃ�

	�Q�D�C���^�[�t�F�[�X
	int Read_assembly_name(int IN_Type, LPVOID &OUT_Struct, int &OUT_EndFlag)
	����:	�^				������				���e
			int				IN_Type				�A�Z���u���^
			LPVOID&			OUT_Struct			�\����
			int&			OUT_EndFlag			�I���t���O�i�O�F�p���A�P�F�㑱�Ȃ��j
	���A�l	���펞�F���ʃ��C�u�������ӂ�ԍ�
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B

**/
int SXFManageC::Read_assembly_name(int IN_Type, LPVOID &OUT_Struct, int *OUT_EndFlag)
{
	m_Assem_type = -1;
	int InstanceID = -1;
	int returnCode = -1;
	returnCode = m_ReadAP202Manager->GetNextAssembly(IN_Type,OUT_Struct,OUT_EndFlag,InstanceID);
	if (returnCode < 0)
		return returnCode;
	//�G���[���b�Z�[�W�p�C���X�^���XID
	m_rulecheck.m_InstanceID.Format("#%d",InstanceID);	
	//���[���`�F�b�N
	//���[���`�F�b�N�I�u�W�F�N�g�Ăяo��
	int error_code = m_rulecheck.AssemblyRuleCheck(IN_Type,OUT_Struct);
	if (error_code < 0) {
		// �����ō폜
		Delete_assembly(IN_Type,OUT_Struct);
		OUT_Struct = NULL;
		return error_code;
	}
		///���݂̃A�Z���u���^�@�t�B�[�`���v�f�̃��[���`�F�b�N�Ɏg�p
		m_Assem_type = IN_Type;
	return returnCode;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.05.29

	�P�D�@�\�T�v
	��ʃt�B�[�`���v�f��ǂ݂���ŁA�\���̂�Ԃ�

	�Q�D�C���^�[�t�F�[�X
	int Read_next_feature(char* OUT_Type, size_t TypeSize, LPVOID &OUT_Struct, int &OUT_EndFlag)
	����:	�^				������				���e
			char*			OUT_Type			�t�B�[�`���^
			size_t			TypeSize			�t�B�[�`���^�̃o�b�t�@�T�C�Y
			LPVOID&			OUT_Struct			�\����
			int&			OUT_EndFlag			�I���t���O�i�O�F�p���A�P�F�㑱�Ȃ��j
	���A�l	���펞�F�C���X�^���X�ԍ�
			�ُ펞�F�G���[�ԍ�
			
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		JPCERT/CC �w�E �Ǝ㐫�Ή�

**/
//int SXFManageC::Read_next_feature(char* OUT_Type, LPVOID &OUT_Struct, int *OUT_EndFlag)
int SXFManageC::Read_next_feature(char* OUT_Type,size_t TypeSize, LPVOID &OUT_Struct, int *OUT_EndFlag)
{
	int returnID;
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	returnID = m_ReadAP202Manager->GetNextFeature(OUT_Type,OUT_Struct,OUT_EndFlag);
	returnID = m_ReadAP202Manager->GetNextFeature(OUT_Type,TypeSize,OUT_Struct,OUT_EndFlag);
	if (returnID < 0)
		return returnID;

	//�G���[���b�Z�[�W�p�C���X�^���XID
	m_rulecheck.m_InstanceID.Format("#%d",returnID);
	//���[���`�F�b�N
	//���[���`�F�b�N�I�u�W�F�N�g�Ăяo��
	int error_code = m_rulecheck.FeatureRuleCheck(m_Assem_type,OUT_Type,OUT_Struct);
	if (error_code < 0) {
		// �����ō폜
		Delete_feature(OUT_Type,OUT_Struct);
		OUT_Struct = NULL;
		return error_code;
	}

	return returnID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.2.23

	�P�D�@�\�T�v
		�t�B�[�`���\���̗̂̈���

	�Q�D�C���^�[�t�F�[�X
	void SXFManageC::Delete_feature(char* feature_name,void *& f_struct)

	����:	�^			������			���e
			char*		feature_name	�t�B�[�`����
			void*&		f_struct		�t�B�[�`���\���̂̃A�h���X

	���A�l	�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.23			���X��(FQS)			�Ȃ��B

**/
void SXFManageC::Delete_feature(char* feature_name,void *& f_struct)
{
	if (f_struct)
		if (strcmp(feature_name,DEF_POLYLINE) == 0)
			delete (Polyline_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_SPLINE) == 0)
			delete (Spline_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_CLOTHOID) == 0)
			delete (Clothoid_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_LABEL) == 0)
			delete (Label_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_BALLOON) == 0)
			delete (Balloon_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_FILL_AREA_STYLE_HATCHING) == 0)
			delete (Fill_area_style_hatching_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_EXTERNALLY_DEFINED_HATCH) == 0)
			delete (Externally_Defined_Hatch_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_FILL_AREA_STYLE_COLOUR) == 0)
			delete (Fill_area_style_colour_Struct*)f_struct;
		else if (strcmp(feature_name,DEF_FILL_AREA_STYLE_TILES) == 0)
			delete (Fill_area_style_tiles_Struct*)f_struct;
		else 
			delete f_struct;
	f_struct = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								�쐬���F2001.2.23

	�P�D�@�\�T�v
		�A�Z���u���\���̗̂̈���

	�Q�D�C���^�[�t�F�[�X
	void SXFManageC::Delete_assembly(int assem_type,void *& f_struct)

	����:	�^			������		���e
			char*		assem_type	�A�Z���u���^
										�P�F�p��
										�Q�F�����}�`
										�R�F�����Ȑ�
			void*&		f_struct	�t�B�[�`���\���̂̃A�h���X

	���A�l	�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.3.28			���X��(FQS)			�Ȃ��B

**/
void SXFManageC::Delete_assembly(int assem_type,void *& f_struct)
{
	if (f_struct){
		switch(assem_type){
			case 1:
			case 2:
			case 3:
				delete f_struct;
				break;
			default:
				SXFErrorMsgC::RecordError(SXFASSEMTYPEERR,"",1,assem_type);
				break;
		}
	}
	f_struct = NULL;
}
