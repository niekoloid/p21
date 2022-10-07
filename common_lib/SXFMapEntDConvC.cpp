/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EntityData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntDConvC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
//#include "ComSplitStringC.h"
#include "SXFutyConvKanjiC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2003

	�P�D�@�\�T�v
		'xxx'����xxx�݂̂𒊏o����

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntDConvC::SXFMapEntDConvC()

	����  �F	�^			������				���e
			CString&		inSource		�����l������
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2003.07.10	K.Naono
**/
void SXFMapEntDConvC::consumeQuote(CString& inSource)
{
	CString	str ;
	register int		i, j ;
	register bool		bQuot = false ;
	register int		nLength = inSource.GetLength() ;
	register LPCTSTR	wp = (LPCTSTR)inSource ;

	//	�N�H�[�g���Ȃ���΁A�ŏ��ɂ��邱�Ƃɂ���
	if( strchr(wp, '\'') == NULL ) {
		bQuot = true ;
	}

	for(i = 0; i < nLength; i++) {
		if( wp[i] == '\'' ) {
			//	���߂ẴN�H�[�g(')�͊J�n�̈�
			if( !bQuot ) {
				bQuot = true ;

			//	�N�H�[�g�������ꍇ('')�͎擾
			} else if( (i + 1) < nLength && wp[i + 1] == '\'' ) {
				LPCTSTR p = &wp[nLength - 1] ;
				for(j = nLength - 1; j >= 0; j--) {
					if( wp[j] == '\'' ) break ;
				}
				//	�����I���̃N�H�[�g(')�łȂ���Ύ��̃N�H�[�g�܂Ŏ擾
				if( (i + 1) != j ) {
					str += (TCHAR)wp[i] ;
					str += (TCHAR)wp[i + 1] ;
					i++ ;
				//	�����I���̃N�H�[�g(')�Ȃ�΃J�����g�̂ݎ擾
				} else {
					str += (TCHAR)wp[i] ;
				}

			//	�I���̃N�H�[�g�ł���΃��[�v���I��
			} else if( bQuot ) {
				break ;
			}
			continue ;
		}
		//	�N�H�[�g(')�ڍs�͎擾����
		if( bQuot )
			str += (TCHAR)wp[i] ;
	}
	inSource = str ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntDConvC::SXFMapEntDConvC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntDConvC::SXFMapEntDConvC()
{
//
//	<������>
//
	m_Entity.Empty();

}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntDConvC::SXFMapEntDConvC(
					CString*		IN_Entity)
					

	����  �F	�^				������				���e
				CString*		IN_Entity		�G���e�B�e�B�f�[�^

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntDConvC::SXFMapEntDConvC(
			CString*	IN_Entity)
{
	m_Entity = *IN_Entity;
//	m_SplitarrayPP = &m_SplitarrayTT;
}

SXFMapEntDConvC::SXFMapEntDConvC(
			CString&	IN_Entity)
{
	m_Entity = IN_Entity;
//	m_SplitarrayPP = &m_SplitarrayTT;

}

SXFMapEntDConvC::SXFMapEntDConvC(
			char*	IN_Entity)
{
	m_Entity = IN_Entity;
//	m_Splitarray = &m_SplitarrayTemp;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntDConvC::~SXFMapEntDConvC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntDConvC::~SXFMapEntDConvC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::SetEntitydata(
			CString& IN_Entity)

	����  �F	�^			������				���e
				CString& 	IN_Entity

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapEntDConvC::SetEntitydata(CString& IN_Entity)
{
	m_Entity = IN_Entity;
	return 0;
}

//�G���e�B�e�B���̓o�^
	int	SetEntitydata(CString&);

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�H�[�`���f�[�^��Integer�^�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetInt(int& OUT_Int)

	����  �F	�^			������				���e
				int& 		OUT_Int

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapEntDConvC::GetInt(int& OUT_Int)
{
	OUT_Int = atoi( m_Entity );

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�H�[�`���f�[�^��double�^�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		double		SXFMapEntDConvC::GetDouble(double& OUT_Double)

	����  �F	�^			������				���e
				double&		OUT_Double

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

double SXFMapEntDConvC::GetDouble(double& OUT_Double)
{
	OUT_Double=atof( m_Entity );

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���f�[�^��double�^�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		void	CString SXFMapEntDConvC::GetCString()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

CString SXFMapEntDConvC::GetCString()
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.09
/*
	///////////////////////////////////////////////////////////////
	// �� �v�ύX
	m_Entity.TrimLeft();
	int find=-1;
	find = m_Entity.Find("'");
	if (find != -1)
		m_Entity = m_Entity.Mid(find+1);
	m_Entity.TrimRight();
	find = m_Entity.ReverseFind('\'');
	if (find != -1)
		m_Entity = m_Entity.Left(find);
*/
	consumeQuote(m_Entity) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.09

	// �R�[�h�̕ϊ� UNI=>SJIS
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.11
//	char OUT_Char[MAXTEXT];		//������
	static char OUT_Char[MAXTEXT];		//������
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.11
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,(char*)(LPCTSTR)m_Entity,OUT_Char);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)m_Entity,OUT_Char);
	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)m_Entity,OUT_Char, _countof(OUT_Char));

	m_Entity  = OUT_Char;

	return m_Entity;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���f�[�^��InstanceID�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetInst(int& OUT_Inst)

	����  �F	�^			������				���e
				int& 		OUT_Inst

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapEntDConvC::GetInst(int& OUT_Inst)
{
	m_Entity.TrimLeft();
	if(m_Entity[0] != '#')
		return -10000 ;
	m_Entity.TrimLeft('#') ;
	OUT_Inst = atoi(  m_Entity	);
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���f�[�^��BOOL�^�ɕϊ�����
	//BOOL (TRUE,FALSE)
	//LOGICAL �_���^�iTRUE�AFALSE�AUNKNOWN�j

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetBOOL(
			BOOL& OUT_BOOL)

	����  �F	�^			������				���e
				BOOL& 		OUT_BOOL

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapEntDConvC::GetBOOL(BOOL& OUT_BOOL)
{
	if ( m_Entity.Find(DEF_D_T) != -1 ){ 
		OUT_BOOL=TRUE;
		return 0;
	}
	if ( m_Entity.Find(DEF_D_F) != -1 ){ 
		OUT_BOOL=FALSE;
		return 0;
	}
	if ( m_Entity.Find(DEF_D_UNSPECIFIED) != -1 ){ 
		OUT_BOOL=TRUE;
		return 0;
	}

	return -10000;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�Z�b�g�^�̃t�H�[�`���f�[�^��InstanceID�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetSetInst(
				int& Out_num,
				CArray<int,int>& Out_Intarray);

	���� �F	�^					������				���e
			int& 				Out_num
			CArray<int,int>& 	Out_Intarray

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int	SXFMapEntDConvC::GetSetInt( int& OUT_Num	
							 ,CArray<int,int>& OUT_Instarray )
{

	OUT_Instarray.RemoveAll();

	m_Entity.TrimLeft();
	m_Entity.TrimLeft('(');
	m_Entity.TrimRight();
	m_Entity.TrimRight(')');

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_Splitarray = split.Split(',');
	OUT_Num = m_Splitarray->GetSize(); 

	for(int i=0;i<OUT_Num;i++){
		OUT_Instarray.Add( atoi( (*m_Splitarray)[i] ) );
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		OUT_Instarray.Add(atoi(array[i])) ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�Z�b�g�^�̃t�H�[�`���f�[�^��double�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetSetDouble(
				int& Out_num,
				CArray<double,double>& Out_Intarray);

	���� �F	�^						������				���e
			int& 					OUT_Num
			CArray<double,double>&	OUT_Instarray

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int	SXFMapEntDConvC::GetSetDouble( int& OUT_Num	
							 ,CArray<double,double>&  OUT_Instarray )
{

	OUT_Instarray.RemoveAll();

	m_Entity.TrimLeft('(');
	m_Entity.TrimLeft();
	m_Entity.TrimRight(')');
	m_Entity.TrimRight();

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);

	m_Splitarray = split.Split(',');

	OUT_Num = m_Splitarray->GetSize();	

	for(int i=0;i<OUT_Num;i++){
		OUT_Instarray.Add( atof( (*m_Splitarray)[i] ) );
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		OUT_Instarray.Add(atof(array[i])) ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�Z�b�g�^�̃t�B�[�`���f�[�^��InstanceID�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetSetInst(
				int& Out_num,
				CArray<int,int>& Out_Intarray);

	���� �F	�^					������				���e
			int& 				OUT_Num
			CArray<int,int>& 	OUT_Instarray

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int	SXFMapEntDConvC::GetSetInst( int& OUT_Num	
							 ,CArray<int,int>& OUT_Instarray )
{

	OUT_Instarray.RemoveAll();

	m_Entity.TrimLeft();
	m_Entity.TrimLeft('(');
	m_Entity.TrimRight();
	m_Entity.TrimRight(')');
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_Splitarray = split.Split(',');

	if (m_Splitarray == NULL) return -10000; 

	OUT_Num = m_Splitarray->GetSize();		
	CString tmpstring;
	for(int i=0;i<OUT_Num;i++){
		tmpstring = 	(*m_Splitarray)[i];
		(*m_Splitarray)[i].TrimLeft();
		tmpstring.Find('#');
		(*m_Splitarray)[i].TrimLeft('#') ;
		OUT_Instarray.Add( atoi( (*m_Splitarray)[i] ) );
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		array[i].TrimLeft() ;
		array[i].TrimLeft('#') ;
		OUT_Instarray.Add(atoi(array[i])) ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

  return 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		Set+Select�^��double�ւ̕ϊ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetSetSelectDouble(
						CString& IN_Select, 
						int& OUT_Num, 
						CArray<double,double>& OUT_array)

	���� �F	�^						������				���e
			CString& 				IN_Select
			int& 					OUT_Num
			CArray<double,double>& 	OUT_array

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int		SXFMapEntDConvC::GetSetSelectDouble(
						CString& IN_Select,
						int& OUT_Num,
						CArray<double,double>& OUT_array)

{
// SET+SELECT�^�̗�
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,	(#516,PARAMETER_VALUE(0.0)),
//		(#517,PARAMETER_VALUE(12.383404246416728)), .T.,.PARAMETER.);
//#104 = TRIMMED_CURVE('trimmed_curve1', #103, 
//	(PARAMETER_VALUE(3.141593)),(PARAMETER_VALUE(0.)), .T., .PARAMETER.);


//#200	TEXT_STYLE_WITH_BOX_CHARACTERISTICS(
//	( BOX_HEIGHT(1.), BOX_WIDTH(1.),BOX_SLANT_ANGLE(0.),BOX_ROTATE_ANGLE(0.)) )

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	int IN_Mode = 2; 
	SXFSplitAP202C	split(IN_Mode, m_Entity) ;

	m_Splitarray = split.Split();
	OUT_Num = m_Splitarray->GetSize();

	CString tmpstring;
	for(int i=0;i<OUT_Num;i++){
		if ( (*m_Splitarray)[i].Find(IN_Select,0) ){
			tmpstring = (*m_Splitarray)[i];
			tmpstring.TrimLeft();			//�擪�̋󔒂��폜
			tmpstring.TrimLeft(IN_Select);	//
			tmpstring.TrimLeft();			
			tmpstring.TrimLeft('(');
			tmpstring.TrimRight();
			tmpstring.TrimRight(')');
			OUT_array.Add( atof( tmpstring ) );
		}
	}

	return 0;
*/
	return GetSetSelectDouble((char*)(LPCTSTR)IN_Select, OUT_Num, OUT_array) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

//			Set+Select�^��double�ւ̕ϊ�
int		SXFMapEntDConvC::GetSetSelectDouble(
						char* IN_Select, 
						int& OUT_Num, 
						CArray<double,double>& OUT_array)

{

	CString tmpstring;
	m_Entity.TrimLeft();
	m_Entity.TrimLeft("(");
	tmpstring = m_Entity;
	m_Entity.Delete( tmpstring.GetLength()-1,1);

	OUT_array.RemoveAll();

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_SplitarrayPP = split.Split(',');
	m_SplitarrayTT.Copy(*m_SplitarrayPP);
	OUT_Num = m_SplitarrayTT.GetSize();
	for(int i=0;i<OUT_Num;i++){
		if ( m_SplitarrayTT[i].Find(IN_Select,0) != -1 ){
			tmpstring = m_SplitarrayTT[i];
			tmpstring.TrimLeft();			//�擪�̋󔒂��폜
			tmpstring.TrimLeft(IN_Select);	//
			tmpstring.TrimLeft();
			tmpstring.TrimLeft('(');
			tmpstring.TrimRight();
			tmpstring.TrimRight(')');
			OUT_array.Add( atof( tmpstring ) );
		}
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		if ( array[i].Find(IN_Select,0) == -1 ) {
			continue ;
		}
		array[i].TrimLeft() ;			//�擪�̋󔒂��폜
		array[i].TrimLeft(IN_Select) ;
		array[i].TrimLeft() ;
		array[i].TrimLeft('(') ;
		array[i].TrimRight() ;
		array[i].TrimRight(')') ;
		OUT_array.Add(atof(array[i])) ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	return 0;
}

////////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		Select�^��double�ւ̕ϊ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::GetSelectDouble(
					CString& IN_Select, 
					double &OUT_Double )

	����  �F	�^			������				���e
				CString& 	IN_Select
				double 		&OUT_Double

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
////////////////////////////////////////////////////////////////////////
//	Select�^��double�ւ̕ϊ�
int	SXFMapEntDConvC::GetSelectDouble( 
			CString& IN_Select, 
			double &OUT_Double )
{
	//SELECT+double�^�̗�
	//TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)) ;
	//���̓f�[�^==> LENGTH_MEASURE(0.2)

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.10
/*
	m_Entity.TrimLeft();		//�擪�̋󔒂��폜
	if (m_Entity.Find(IN_Select)!=-1 ){

		m_Entity.TrimLeft(IN_Select);	//
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_Double =  atof( m_Entity ) ;
	}
	else{
		return -10000;
	}
	return 0;
*/
	return GetSelectDouble((char*)(LPCTSTR)IN_Select, OUT_Double) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.10
}

////////////////////////////////////////////////////////////////////////
int	SXFMapEntDConvC::GetSelectDouble( 
			char* IN_Select, 
			double &OUT_Double )
{
	//SELECT+double�^�̗�
	//TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)) ;
	//���̓f�[�^==> LENGTH_MEASURE(0.2)
	
	m_Entity.TrimLeft();		//�擪�̋󔒂��폜
	if (m_Entity.Find(IN_Select)!=-1 ){

		m_Entity.TrimLeft(IN_Select);
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_Double =  atof( m_Entity ) ;
	}
	else{
		return -10000;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////
//	<Select�^�� CString �ւ̕ϊ�>
BOOL	SXFMapEntDConvC::GetSelectCString(
			CString& IN_Select, CString& OUT_CString)

{
	//SELECT+CString �^�̗�
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//���̓f�[�^==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'

	///////////////////////////////////////////////////////////////
	//	SELECT�̕�����ƑO��̂������폜
	TrimSelect(IN_Select,OUT_CString);

	///////////////////////////////////////////////////////////////
	// �� �v�ύX
	int find=-1;
	find = OUT_CString.Find("'");
	if (find != -1)
		OUT_CString = OUT_CString.Mid(find+1);
	OUT_CString.TrimRight();
	find = OUT_CString.ReverseFind('\'');
	if (find != -1)
		OUT_CString = OUT_CString.Left(find);

	// �R�[�h�̕ϊ� UNI=>SJIS
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.11
//	char OUT_Char[MAXTEXT];		//������
	static char OUT_Char[MAXTEXT];		//������
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.11
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,(char*)(LPCTSTR)OUT_CString,OUT_Char);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char);
	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char, _countof(OUT_Char));

	OUT_CString  = OUT_Char;

	return TRUE;
}

BOOL	SXFMapEntDConvC::GetSelectCString(
			char* IN_Select, CString& OUT_CString)
{
	//SELECT+CString �^�̗�
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//���̓f�[�^==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'

	///////////////////////////////////////////////////////////////
	//	SELECT�̕�����ƑO��̂������폜
	TrimSelect(IN_Select,OUT_CString);

	///////////////////////////////////////////////////////////////
	// �� �v�ύX
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.09
/*
	int find=-1;
	find = OUT_CString.Find("'");
	if (find != -1)
		OUT_CString = OUT_CString.Mid(find+1);
	OUT_CString.TrimRight();
	find = OUT_CString.ReverseFind('\'');
	if (find != -1)
		OUT_CString = OUT_CString.Left(find);
*/
	consumeQuote(OUT_CString) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.09

	// �R�[�h�̕ϊ� UNI=>SJIS
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.11
//	char OUT_Char[MAXTEXT];		//������
	static char OUT_Char[MAXTEXT];		//������
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.11
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,(char*)(LPCTSTR)OUT_CString,OUT_Char);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char);
	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char, _countof(OUT_Char));

	OUT_CString  = OUT_Char;

	return TRUE;
}

////////////////////////////////////////////////////////////////////////

// SELECT�^�̕�����폜 IDENTIFIER('XXXXXX')=>XXXXXX (�����R�[�h�ϊ��Ȃ�)

BOOL	SXFMapEntDConvC::TrimSelect( 
			char* IN_Select, 
			CString &OUT_CString )
{
	//SELECT+CString �^�̗�
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//���̓f�[�^==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'
	
	m_Entity.TrimLeft();		//�擪�̋󔒂��폜
	if (m_Entity.Find(IN_Select)!=-1 ){
		m_Entity.TrimLeft(IN_Select);	//
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_CString =  m_Entity ;
	}
	else{
		return FALSE;
	}
	return TRUE;
}

// SELECT�^�̕�����폜 IDENTIFIER('XXXXXX')=>XXXXXX (�����R�[�h�ϊ��Ȃ�)

BOOL	SXFMapEntDConvC::TrimSelect( 
			CString& IN_Select, 
			CString &OUT_CString )
{
	//SELECT+CString �^�̗�
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//���̓f�[�^==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'
	
	m_Entity.TrimLeft();		//�擪�̋󔒂��폜
	if (m_Entity.Find(IN_Select)!=-1 ){
		m_Entity.TrimLeft(IN_Select);	//
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_CString =  m_Entity ;
	}
	else{
		return FALSE;
	}
	return TRUE;
}

////////////////////////////////////////////////////////////////////////

//	DEL(S)	�`���[�j���O�Ή�	K.Naono
/*
//	�O��̊��ʁi�j ���폜����
BOOL SXFMapEntDConvC::TrimKako(CString*& INOUT_CString)
{
	INOUT_CString->TrimLeft();
	if (INOUT_CString->Find('(')!=1 ) return FALSE;
	INOUT_CString->Delete(0,1);
	INOUT_CString->TrimRight();
	CString tmpstring;
	tmpstring = *INOUT_CString;
	if (INOUT_CString->Find('(')!= (tmpstring.GetLength()-1) ) return FALSE;
	tmpstring = *INOUT_CString;
	INOUT_CString->Delete(tmpstring.GetLength()-1,1);

	return TRUE;
}
*/
//	DEL(E)	�`���[�j���O�Ή�	K.Naono

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�Z�b�g�^�̃t�B�[�`���f�[�^��CStringArray�ɕϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntDConvC::ConvCStringArray()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int	SXFMapEntDConvC::ConvCStringArray()
{

	m_Entity.TrimLeft();
	m_Entity.TrimLeft('(');
	m_Entity.TrimRight();
	m_Entity.TrimRight(')');

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_Splitarray = split.Split(',');

	int array_num = m_Splitarray->GetSize();

	return array_num;
*/
	CStringArray	array ;
	return GFn_SplitString(m_Entity, ',' , array) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
}

