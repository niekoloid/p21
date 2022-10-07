//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�N���X�T�v
//      �t�@�C���̓��͂Əo�͂��Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//
//---------------------------------------------------------
#include "stdafx.h"
#include <afx.h>
//#include "ComSplitStringC.h"
#include "SXFDataStructC.h"
#include "SXFPart21FileC.h"
#include "SXFutyConvKanjiC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		(�R���X�g���N�^)
//
//	�Q�D�C���^�[�t�F�C�X
//		SXFPart21FileC::SXFPart21FileC()
//
//	����  �F	�^				������				���e
//			�Ȃ�	  
//
//	���A�l�F�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//---------------------------------------------------------
SXFPart21FileC::SXFPart21FileC()
{
	ap202count = 0;
	featurecount = 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		(�R���X�g���N�^)
//
//	�Q�D�C���^�[�t�F�C�X
//		void	SXFPart21FileC::SXFPart21FileC( 
//								LPCTSTR IN_lpszFileName,
//								UINT IN_nOpenFlags)
//
//	����	�F	�^			������				���e
//				LPCTSTR		IN_lpszFileName		�t�@�C����
//				UINT		IN_nOpenFlags		�t�@�C���I�[�v�����[�h
//		
//	���A�l�F�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2001.05.25		���X��(FQS)
//---------------------------------------------------------
SXFPart21FileC::SXFPart21FileC( FILE* IN_pOpenStream )
			   :CStdioFile( IN_pOpenStream )
{
	ap202count = 0;
	featurecount = 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		(�R���X�g���N�^)
//
//	�Q�D�C���^�[�t�F�C�X
//		void	SXFPart21FileC::SXFPart21FileC( 
//								LPCTSTR IN_lpszFileName,
//								UINT IN_nOpenFlags)
//
//	����	�F	�^			������				���e
//				LPCTSTR		IN_lpszFileName		�t�@�C����
//				UINT		IN_nOpenFlags		�t�@�C���I�[�v�����[�h
//		
//	���A�l�F�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��			�S����		�T�v
//		�쐬		2001.05.25		���X��(FQS)
//---------------------------------------------------------
SXFPart21FileC::SXFPart21FileC( LPCTSTR IN_lpszFileName,
								UINT IN_nOpenFlags)
			   :CStdioFile( IN_lpszFileName,IN_nOpenFlags )
{
	ap202count = 0;
	featurecount = 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		�N���X����
//
//	�Q�D�C���^�[�t�F�C�X
//
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//---------------------------------------------------------
SXFPart21FileC::~SXFPart21FileC()
{
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		Head Section������ǂݍ���
//
//	�Q�D�C���^�[�t�F�C�X
//		int ReadHeadSection(HEADSECTION *IO_Head)
//
//		����: �^			  ������				���e
//			  HEADSECTION*	  IO_Head			   HeadSection��
//												   �\���̂̃A�h���X
//		���A�l	
//			  ���펞�F	1 : OK
//			  �ُ펞�F -1 : file end
//					  -2  : found syntax error 
//					  -3  : can not to find a headsection
//		
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//---------------------------------------------------------
int SXFPart21FileC::ReadHeadSection(HEADSECTION *IO_Head)
{
	return 1;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		���Instance��ǂݍ���
//
//	�Q�D�C���^�[�t�F�C�X
//		int ReadInstance(INSTANCEDATA *IO_Instance)
//
//		����: �^			  ������				���e
//			  INSTANCEDATA*   IO_Instance		   Instance Data��
//												   �\���̂̃A�h���X
//		���A�l	
//			  ���펞�F	 1 :  OK
//			  �ُ펞�F	-1 :  file end
//					   -2 :  found syntax error
//					   -3 :  can not to find a ap202 instance
//							 in this file
//					   -4 :  can not to find a feature instance
//							 in this file 
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//---------------------------------------------------------
int SXFPart21FileC::ReadInstance(INSTANCEDATA *IO_Instance)
{
	return 1;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//
//		Head Section�����o�͂���
//
//	�Q�D�C���^�[�t�F�C�X
//		BOOL WriteHeadSection(HEADSECTION *IN_Head)
//
//		����: �^			  ������				���e
//			  HEADSECTION*	  IN_Head			   Head Section��
//												   �\���̂̃A�h���X
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F	FALSE
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//---------------------------------------------------------
BOOL SXFPart21FileC::WriteHeadSection(HEADSECTION *IN_Head)
{
	CString headsection;
	CString tempstring;
	CString mode;
	CString endline("\n");
	headsection="ISO-10303-21;";
	headsection+=endline;
	headsection+="HEADER;";
	headsection+=endline;

	/* Ӱ�� */
	switch (IN_Head->Mode)
	{
	case 0:
		mode = "ambi_mode";
		break;
	case 1:
		mode = "feature_mode";
		break;
	case 2:
		mode = "AP202_mode";
		break;
	default:
		break;	 
	}
	/* level, mode�̏o��̫�ϯč쐬 */
	tempstring.Format("FILE_DESCRIPTION(('SCADEC level%d %s'),\n",
					   IN_Head->Level,mode);
	headsection += tempstring;
	headsection += "		'2;1');";
	headsection+=endline;
	/* file name(need not path name) */
	CString filename = IN_Head->FileName;
	int backslash_find = filename.ReverseFind('\\');
	if (backslash_find != -1){
		filename = filename.Mid(backslash_find+1);
	}
	/* ̧�ٖ���UNICODE�֕ϊ� */
	char out_filename[MAXUNICODENAME];
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)filename,out_filename);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)filename,out_filename);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)filename,out_filename,_countof(out_filename));
	/* ̧�ٖ��̏o��̫�ϯč쐬 */
	tempstring.Format("FILE_NAME('%s',\n",out_filename);
	headsection += tempstring;
	//current date and time
	CTime currenttime=CTime::GetCurrentTime();
	tempstring.Format("		   '%d-%d-%dT%d:%d:%d',\n",
					  currenttime.GetYear(),
					  currenttime.GetMonth(),
					  currenttime.GetDay(),
					  currenttime.GetHour(),
					  currenttime.GetMinute(),
					  currenttime.GetSecond() );
	headsection += tempstring;
	/* author��UNICODE�ɕϊ� */
	char out_author[MAXUNICODENAME];
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)IN_Head->Author,out_author);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Author,out_author);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Author,out_author,_countof(out_author));
	/* �o��̫�ϯč쐬 */
	tempstring.Format("		   ('%s'),\n",out_author);
	headsection += tempstring;

	/* organization ��UNICODE�ɕϊ� */
	char out_org[MAXUNICODENAME];
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)IN_Head->Organization,out_org);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Organization,out_org);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Organization,out_org,_countof(out_org));
	/* �o��̫�ϯč쐬 */
	tempstring.Format("		   ('%s'),\n",out_org);
	headsection += tempstring;
	/* version �o��̫�ϯč쐬 */
	tempstring.Format("		   '%s',\n",IN_Head->Version);
	headsection += tempstring;
	char out_orgsystem[MAXUNICODENAME];
	/* Originating system �o��̫�ϯč쐬 */
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)IN_Head->OriginatingSystem,out_orgsystem);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->OriginatingSystem,out_orgsystem);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->OriginatingSystem,out_orgsystem,_countof(out_orgsystem));
	tempstring.Format("		   '%s',\n",out_orgsystem);
	/* ͯ�ް�o��̫�ϯč쐬 */
	headsection += tempstring;
	headsection += "		'');";
	headsection += endline;
	headsection += "FILE_SCHEMA(('ASSOCIATIVE_DRAUGHTING'));";
	headsection+=endline;
	headsection += "ENDSEC;";
	headsection+=endline;
	headsection += "DATA;";
	headsection+=endline;
	/* ͯ�ް�̏o�� */
	WriteString(headsection);

	//�P�ʃC���X�^���X�̏o��
	if (IN_Head->Mode == 0 || IN_Head->Mode == 2){
		CString unit_instance;
		unit_instance = "#10=(";
		unit_instance += endline;
		unit_instance += "LENGTH_UNIT()";
		unit_instance += endline;
		unit_instance += "NAMED_UNIT(*)";
		unit_instance += endline;
		unit_instance += "SI_UNIT(.MILLI.,.METRE.)";
		unit_instance += endline;
		unit_instance += ");";
		unit_instance += endline;
		WriteString(unit_instance);
	}

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  �쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		���Instance���o�͂���
//
//	�Q�D�C���^�[�t�F�C�X
//		BOOL WriteInstance(INSTANCEDATA *IN_Instance)
//
//		����: �^			  ������				���e
//			  INSTANCEDATA*   IN_Instance		   Instance Data��
//												   �\���̂̃A�h���X
//		���A�l	
//			  ���펞�F TRUE
//			  �ُ펞�F FALSE
//
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2001.05.25	���X��(FQS)
//---------------------------------------------------------
BOOL SXFPart21FileC::WriteInstance(INSTANCEDATA *IN_Instance)
{
	CString instance;

	switch (IN_Instance->InstanceMode)
	{
	case SXF_IM_COMMENT: //comment
		/* �o��̫�ϯč쐬 */
		instance.Format("/*\n%s\n*/",IN_Instance->EntityData);
		break;
	case SXF_IM_SECTIONMARK: //SectionMark
		/* �o��̫�ϯč쐬 */
		instance.Format("%s;\n",IN_Instance->EntityName);
		break;
	case SXF_IM_AP_ENTITY: //AP202 entity
	case SXF_IM_AP_TABLE:  //AP202 table
	case SXF_IM_AP_ASSEMBLY: //AP202 assembly
		if (IN_Instance->EntityName == DEF_SXF_COMPLEX_INSTANCE){
			//if entityname=="SXF_COMPLEX_INSTANCE"
			//then complex_instance eg.#10=(a()
									  //	b()
									  //	c());
			/* �o��̫�ϯč쐬 */
			instance.Format("#%d=%s;\n",
							IN_Instance->InstanceID,
							IN_Instance->EntityData);
		}else{ // if not a complex instance 
			/* �o��̫�ϯč쐬 */
			instance.Format("#%d=%s%s;\n",
							IN_Instance->InstanceID,
							IN_Instance->EntityName,
							IN_Instance->EntityData);
		}
		break;
	case SXF_IM_FT_ENTITY: //Feature
	case SXF_IM_FT_TABLE:  //Feature table
	case SXF_IM_FT_ASSEMBLY: //Feature assembly
		/* �o��̫�ϯč쐬 */
		instance.Format("\n/*SXF\n#%d = %s%s\nSXF*/\n\n",
						IN_Instance->InstanceID,
						IN_Instance->EntityName,
						IN_Instance->EntityData);
		break;
	default: 
		break;
	}
	
	/* �ݽ�ݽ�o�� */
	WriteString(instance);

	return TRUE;
}
