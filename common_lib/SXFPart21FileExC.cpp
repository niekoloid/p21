//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�N���X�T�v
//		�t�@�C���̓��͂��Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)	�w�b�_��͏����̉��P�Ή�
//
//---------------------------------------------------------
#include "stdafx.h"
#include "SXFPart21FileExC.h"
#include "SXFHeaderLex.h"
//#include "ComSplitStringC.h"
#include "SXFComncApi.h"
#include "SXFutyConvKanjiC.h"
#include "SXFComndef.h"

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�R���X�g���N�^
//
//	�Q�D�C���^�[�t�F�C�X
//		SXFPart21FileExC::SXFPart21FileExC(
//						LPCTSTR	IN_lpszFileName,
//						UINT	IN_nOpenFlags)
//
//		����: �^				������				���e
//				LPCTSTR		IN_lpszFileName		�t�@�C����
//				UINT		IN_nOpenFlags		�t�@�C���I�[�v�����[�h
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
SXFPart21FileExC::SXFPart21FileExC(
						LPCTSTR	IN_lpszFileName,
						UINT	IN_nOpenFlags)
				:SXFPart21FileC(IN_lpszFileName, IN_nOpenFlags)
{
	m_pDataLex		= NULL ;
	m_pDataRecord	= NULL ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�f�X�g���N�^
//
//	�Q�D�C���^�[�t�F�C�X
//		SXFPart21FileExC::~SXFPart21FileExC()
//
//		����:	�Ȃ�
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
SXFPart21FileExC::~SXFPart21FileExC()
{
	if( m_pDataLex )
		delete m_pDataLex ;

	if( m_pDataRecord )
		delete m_pDataRecord ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		Head Section������ǂݍ���
//
//	�Q�D�C���^�[�t�F�C�X
//		int SXFPart21FileExC::ReadHeadSection(
//							HEADSECTION*	IO_Head)
//
//		����: �^				������				���e
//			HEADSECTION*	IO_Head				HeadSection��
//												�\���̂̃A�h���X
//		���A�l
//			���펞�F 1 : OK
//			�ُ펞�F
//					-1 : file end
//					-2 : found syntax error 
//					-3 : can not to find a headsection
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int SXFPart21FileExC::ReadHeadSection(HEADSECTION* IO_Head)
{
	ASSERT(IO_Head) ;
	if( IO_Head == NULL ) {
		return -1 ;
	}

	//	HEADER �` ENDSEC�܂ł�ǂݍ���
	CString	buffer ;
	CString	record ;

	while( ReadString(record) ) {
		record.TrimLeft() ;
		record.TrimRight() ;
		buffer += record ;
		if( record.Find(ID_ENDSEC) != -1 )
			break ;
	}
	if( buffer.GetLength() == 0 ) {
		return -3 ;
	}

	//	����̉�͂��n�߂�
	BOOL			bExistHeader = FALSE ;
	CStringArray	array ;
	int token = 0, ret = 0 ;
	CSXFHeaderLex*	pLex = new CSXFHeaderLex(buffer) ;
	while( (token = pLex->Lex()) != TT_EOF ) {

		switch(token) {
		case TT_FILE_DESCRIPTION :
			//	�����l�̎擾
			getAttribute(pLex, array) ;

			//	�����l�̉��
			if( (ret = analyzeDescription(array, IO_Head)) == 1 ) {
				break ;
			}
			delete pLex ;
			if( ret == 0 ) {
				return ret ;
			} else {
				return !bExistHeader ? -3 : ret ;
			}
			break ;

		case TT_FILE_NAME :
			//	�����l�̎擾
			getAttribute(pLex, array) ;

			//	�����l�̉��
			if( (ret = analyzeName(array, IO_Head)) < 0 ) {
				delete pLex ;
				return !bExistHeader ? -3 : ret ;
			}
			break ;

		case TT_FILE_SCHEMA :
			break ;

		case TT_HEADER :
			bExistHeader = TRUE ;
			break ;

		case TT_ENDSEC :
			bExistHeader = FALSE ;
			break ;
		}
	}

	delete pLex ;

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		Part21 File��FILE_DESCRIPTION��������͂���
//
//	�Q�D�C���^�[�t�F�C�X
//		int SXFPart21FileExC::analyzeDescription(
//							CStringArray&	array,
//							HEADSECTION*	IO_Head)
//
//		����: �^				������				���e
//			CStringArray&		array			�����l
//			HEADSECTION*		IO_Head			HeadSection��
//												�\���̂̃A�h���X
//		���A�l	
//			���펞�F 1 : OK
//			�ُ펞�F
//					-1 : file end
//					-2 : found syntax error 
//					-3 : can not to find a headsection
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int SXFPart21FileExC::analyzeDescription(
							CStringArray&	array,
							HEADSECTION*	IO_Head)
{
	if( array.GetSize() != 2 ) {
		return -2 ;
	}

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	CStringArray*	pElem ;
	ComSplitStringC split(array[0]) ;
	pElem = split.Split(' ') ;
	if( pElem->GetSize() < 3 ) {
		return -2 ;
	}
	//	SCADEC�ȊO�̃t�@�C��
	if( (*pElem)[0] != ID_SCADEC ) {
		return 0 ;
	}

	//	SCADEC flg ��ON
	IO_Head->scadec_flg = 1 ;
	for(int i = 0; i < pElem->GetSize(); i++) {
		//	���x��
		if( !(*pElem)[i].CompareNoCase(ID_LEVEL1) ) {
			IO_Head->Level = 1 ;

		} else if( !(*pElem)[i].CompareNoCase(ID_LEVEL2) ) {
			IO_Head->Level = 2 ;

		//	���[�h
		} else if( !(*pElem)[i].CompareNoCase(ID_AMBI_MODE) ) {
			IO_Head->Mode = 0 ;

		} else if( !(*pElem)[i].CompareNoCase(ID_FEATURE_MODE) ) {
			IO_Head->Mode = 1 ;

		} else if( !(*pElem)[i].CompareNoCase(ID_AP202_MODE) ) {
			IO_Head->Mode = 2 ;
		}
	}
*/
	CStringArray	arElem ;
	int	nCount = GFn_SplitString(array[0], ' ' , arElem) ;
	if( nCount < 3 ) {
		return -2 ;
	}
	//	SCADEC�ȊO�̃t�@�C��
	if( arElem[0] != ID_SCADEC ) {
		return 0 ;
	}

	//	SCADEC flg ��ON
	IO_Head->scadec_flg = 1 ;
	for(int i = 0; i < nCount; i++) {
		//	���x��
		if( !arElem[i].CompareNoCase(ID_LEVEL1) ) {
			IO_Head->Level = 1 ;

		} else if( !arElem[i].CompareNoCase(ID_LEVEL2) ) {
			IO_Head->Level = 2 ;

		//	���[�h
		} else if( !arElem[i].CompareNoCase(ID_AMBI_MODE) ) {
			IO_Head->Mode = 0 ;

		} else if( !arElem[i].CompareNoCase(ID_FEATURE_MODE) ) {
			IO_Head->Mode = 1 ;

		} else if( !arElem[i].CompareNoCase(ID_AP202_MODE) ) {
			IO_Head->Mode = 2 ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		Part21 File��FILE_NAME��������͂���
//
//	�Q�D�C���^�[�t�F�C�X
//		int SXFPart21FileExC::analyzeName(
//							CStringArray&	array,
//							HEADSECTION*	IO_Head)
//
//		����: �^				������				���e
//			CStringArray&		array			�����l
//			HEADSECTION*		IO_Head			HeadSection��
//												�\���̂̃A�h���X
//		���A�l	
//			���펞�F 1 : OK
//			�ُ펞�F
//					-1 : file end
//					-2 : found syntax error 
//					-3 : can not to find a headsection
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int SXFPart21FileExC::analyzeName(
							CStringArray&	array,
							HEADSECTION*	IO_Head)
{
	if( array.GetSize() != 7 ) {
		return -2 ;
	}

	TCHAR	buffer[257] ;
	//	name�����l�̎擾
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[0], buffer) ;	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[0], buffer, _countof(buffer)) ;
	IO_Head->FileName = buffer ;

	//	author�����l�̎擾
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[2], buffer) ;	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[2], buffer, _countof(buffer)) ;
	IO_Head->Author = buffer ;

	//	organization�����l�̎擾
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[3], buffer) ;	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[3], buffer, _countof(buffer)) ;
	IO_Head->Organization = buffer ;

	//	preprocessor_version�����l�̎擾
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[4], buffer) ;	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[4], buffer, _countof(buffer)) ;
	IO_Head->Version = buffer ;

	//	originating_system�����l�̎擾
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[5], buffer) ;	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[5], buffer, _countof(buffer)) ;
	IO_Head->OriginatingSystem = buffer ;

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		Part21 File�̃G���e�B�e�B�̑����l���擾����
//
//	�Q�D�C���^�[�t�F�C�X
//		void SXFPart21FileExC::getAttribute(
//							CSXFHeaderLex*	pLex,
//							CStringArray&	array)
//
//		����: �^				������				���e
//			CSXFHeaderLex*		pLex			Lex�I�u�W�F�N�g
//			CStringArray&		array			�����l�i�[�p�z��
//
//		���A�l
//			�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void SXFPart21FileExC::getAttribute(
					CSXFHeaderLex*	pLex,
					CStringArray&	array)
{
	if( array.GetSize() > 0 ) {
		array.RemoveAll() ;
	}

//	CString	key ;
	int token ;
	while( (token = pLex->Lex()) != ';' ) {
//	ADD(S)	�o�O�C��	K.Naono	03.05.29
		if( token == TT_EOF ) break ;
//	ADD(E)	�o�O�C��	K.Naono	03.05.29

		// �ǂݔ�΂�
		if( token == ' ' || token == '\t' )	continue ;

		if( token == TT_LINE_COMMENT ) {
			while((token = pLex->Lex()) != TT_EOL) ;
			continue ;
		}
		if( token == TT_BLOCK_COMMENT_START ) {
//			while((token = pLex->Lex()) != TT_BLOCK_COMMENT_END) ;
			while( (token = pLex->Lex()) != TT_EOF ) {
				if( token == TT_BLOCK_COMMENT_END )
					break ;
			}
			continue ;
		}

		switch(token) {
		// �L�[���[�h
		case TT_IDENTIFIER :
		case TT_STRING :
			array.Add(pLex->GetTokenImage()) ;
			break ;

		default :
			break ;
		}
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.05.25
//
//	�P�D�@�\�T�v
//		���Instance��ǂݍ���
//
//	�Q�D�C���^�[�t�F�C�X
//		int ReadInstance(INSTANCEDATA *IO_Instance)
//
//		����: �^			������				���e
//			INSTANCEDATA*	IO_Instance			Instance Data��
//													�\���̂̃A�h���X
//		���A�l	
//			���펞�F 1 :	OK
//			�ُ펞�F-1 :	file end
//					-2 :	found syntax error
//					-3 :	can not to find a ap202 instance
//							in this file
//					-4 :	can not to find a feature instance
//							in this file 
//
//	�R�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2003.07.04	K.Naono		�`���[�j���O�Ή�
//---------------------------------------------------------
int SXFPart21FileExC::ReadInstance(INSTANCEDATA* IO_Instance)
{
	CString	recordline ;
	CString	record ;

	while( ReadString(recordline) ) {
		recordline.TrimLeft() ; recordline.TrimRight() ;

		//	�R�����g�ł���΁A�R�����g��ǂݔ�΂�
		if( recordline.Find("/*") != -1 )
			skippedComment(recordline) ;

		if( recordline.GetLength() == 0 )
			continue;

		record += recordline ;

		if( record.Right(1) == ";" ) {
			break ;
		}
	}

	//	�t�@�C�����Ō�܂œǂ�
	if( record.GetLength() == 0 ) {
		//	̨����ݽ�ݽ������Ȃ�
		if( ap202count == 0 )
			return -3 ; 
		return -1 ;//file end
	}

	record.TrimRight(';') ;

	if(record[0] != '#') {
		return -2 ;
	}

	ap202count++ ;//ap202 instance count ++

	int	findequalsign = record.Find('=') ;
	if (findequalsign < 2) 
		return -2 ;//found syntax error in file

	//	�C���X�^���X�ԍ����擾
	CString	idstring = record.Mid(1, findequalsign - 1) ;
	idstring.TrimLeft() ;
	idstring.TrimRight() ;
	int	instanceid = atoi(idstring) ;
	if (instanceid <= 0)
		return -2;//found syntax error in file
	IO_Instance->InstanceID = instanceid ;

	//	�G���e�B�e�B�̑��������擾
	CString datastring = record.Right(record.GetLength()
									- findequalsign - 1) ;
	datastring.TrimLeft() ;
	datastring.TrimRight() ;
	int	findfirstparentheses = datastring.Find('(') ;
	if (findfirstparentheses < 0) {
		return -2;//found syntax error in file

	//	�����G���e�B�e�B�̏ꍇ
	} else if( findfirstparentheses == 0 ) {
		IO_Instance->EntityName = DEF_SXF_COMPLEX_INSTANCE;
					// if a complex instance 
					// then set entity name:
					// "SXF_COMPLEX_INSTANCE"
		IO_Instance->EntityData = datastring ;

	//	�P���G���e�B�e�B�̏ꍇ
	} else {
		IO_Instance->EntityName = datastring.Left( findfirstparentheses);
		IO_Instance->EntityName.TrimRight();
		IO_Instance->EntityData = datastring.Right(
						datastring.GetLength() - findfirstparentheses) ;
		IO_Instance->EntityData.TrimLeft() ;
	}

	//	��`�e�[�u�����
	if( IO_Instance->EntityName == DEF_PRESENTATION_LAYER_USAGE ||
		IO_Instance->EntityName == DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT ||
		IO_Instance->EntityName == DEF_COLOUR_RGB ||
		IO_Instance->EntityName == DEF_DRAUGHTING_PRE_DEFINED_COLOUR ||
		IO_Instance->EntityName == DEF_LENGTH_MEASURE_WITH_UNIT ||
		IO_Instance->EntityName == DEF_EXTERNALLY_DEFINED_TEXT_FONT ||
		IO_Instance->EntityName == DEF_CURVE_STYLE_FONT)
	{
		IO_Instance->InstanceMode = SXF_IM_AP_TABLE ;

	//	�A�Z���u�����
	} else if (	IO_Instance->EntityName == DEF_SYMBOL_REPRESENTATION_MAP ||
				IO_Instance->EntityName == DEF_DRAWING_SHEET_REVISION_USAGE ||
				IO_Instance->EntityName == DEF_COMPOSITE_CURVE ) {
		IO_Instance->InstanceMode = SXF_IM_AP_ASSEMBLY ;

	} else if (	IO_Instance->EntityName == DEF_INVISIBILITY ) {
		IO_Instance->InstanceMode = SXF_IM_AP_INVISIBILITY ;

	} else if (	IO_Instance->EntityName == DEF_PRESENTATION_SIZE ) {
		IO_Instance->InstanceMode = SXF_IM_AP_PRESENTATION_SIZE ;

	} else if (	IO_Instance->EntityName == DEF_DRAUGHTING_TITLE ) {
		IO_Instance->InstanceMode = SXF_IM_AP_DRAUGHTING_TITLE ;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	} else if (	IO_Instance->EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT ||
				IO_Instance->EntityName == DEF_DRAUGHTING_APPROVAL_ASSIGNMENT ||
				IO_Instance->EntityName == DEF_APPROVAL_DATE_TIME ||
				IO_Instance->EntityName == DEF_DRAUGHTING_ORGANIZATION_ASSIGNMENT ) {
		IO_Instance->InstanceMode = SXF_IM_AP_ATTRIBUTE ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
	} else {
		IO_Instance->InstanceMode = SXF_IM_AP_ENTITY ;
	}

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFPart21FileC.cpp						�쐬���F2003.07.04
//
//	�P�D�@�\�T�v
//		�R�����g��ǂݔ�΂�
//
//	�Q�D�C���^�[�t�F�C�X
//		void skippedComment(CString& strRecord)
//
//		����: �^			������			���e
//			CString&		strRecord		���ݓǂݍ��ݒ��̕�����
//
//		���A�l	
//			�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		�S����		�T�v
//		�쐬		2003.07.04	K.Naono		�`���[�j���O�Ή�
//---------------------------------------------------------
void SXFPart21FileExC::skippedComment(CString& strRecord)
{
	int		idx = strRecord.Find("/*") ;
	if( idx == -1 || isQuoteString(strRecord, idx) ) {
		return ;
	}

	CString	record, recordline ;

	//	�R�����g�J�n�܂ł̕�����擾
	if( idx > 0 ) {
		record = CString((LPCTSTR)strRecord, idx) ;
	}
	idx = strRecord.Find("*/") ;

	//	�R�����g�I�����Ȃ���΁A�R�����g�I���܂œǂݔ�΂�
	if( idx == -1 || (idx > 0 && isQuoteString(strRecord, idx)) ) {
		while( ReadString(recordline) ) {
			recordline.TrimLeft() ; recordline.TrimRight() ;
			idx = recordline.Find("*/") ;
			if( idx != -1 && !isQuoteString(recordline, idx) ) {
				if( idx != (recordline.GetLength() - 2) ) {
					record += CString((LPCTSTR)recordline + (idx + 2),
									recordline.GetLength() - (idx + 2)) ;
				} else {
					recordline.Empty() ;
				}
				break ;
			}
		}

	//	�R�����g�I�����r���ɂ���΁A�R�����g�I���ȍ~���擾
	} else if( idx != (strRecord.GetLength() - 2) ) {
		record += CString((LPCTSTR)strRecord + (idx + 2),
						strRecord.GetLength() - (idx + 2)) ;
	}
	record.TrimLeft() ;
	record.TrimRight() ;
	strRecord = record ;

	if( strRecord.Find("/*") != -1 )
		skippedComment(strRecord) ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFPart21FileC.cpp						�쐬���F2003.07.04
//
//	�P�D�@�\�T�v
//		�R�����g�J�n������(/*)���A�����񂩔ۂ��𔻒肷��
//
//	�Q�D�C���^�[�t�F�C�X
//		void isQuoteString(CString& strRecord)
//
//		����: �^			������			���e
//			CString&		strRecord		���ݓǂݍ��ݒ��̕�����
//			int				nIndex			�R�����g�J�n�C���f�b�N�X
//
//		���A�l	
//			TRUE	:������������
//			FALSE	:�R�����g
//
//	�R�D����
//		����ԍ�	���t��		�S����		�T�v
//		�쐬		2003.07.04	K.Naono		�`���[�j���O�Ή�
//---------------------------------------------------------
BOOL	SXFPart21FileExC::isQuoteString(
								CString&	strRecord,
								int			nIndex)
{
	bool	bQuote = false ;
	int		s_quote = 0, e_quote = 0 ;
	int		nLength = strRecord.GetLength() ;
	LPCTSTR	wp = (LPCTSTR)strRecord ;

	//	�R�����g�C���f�b�N�X���O������
	for(int i = nIndex - 1; i >= 0; i--) {
		if( wp[i] == '\'' ) {
			bQuote = !bQuote ;
		} else if( wp[i] == ',' ) {
			break ;
		}
	}
	if( !bQuote ) {
		return FALSE ;
	}
	//	'�̊J�n�C���f�b�N�X���擾
	s_quote = i ;

	//	�R�����g�C���f�b�N�X����������
	bQuote = false ;
	for(i = nIndex + 1; i < nLength; i++) {
		if( wp[i] == '\'' ) {
			bQuote = !bQuote ;
		} else if( wp[i] == ',' ) {
			break ;
		}
	}
	if( !bQuote ) {
		return FALSE ;
	}
	//	'�̏I���C���f�b�N�X���擾
	e_quote = i ;

	//	'�`'�̊Ԃł���΁A�R�����g�ł͂Ȃ�
	if( nIndex > s_quote && nIndex < e_quote ) {
		return TRUE ;
	}

	return FALSE ;
}
