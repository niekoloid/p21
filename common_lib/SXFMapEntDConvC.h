/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EntityData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapEntDConvC_CLASS_
#define _SXFMapEntDConvC_CLASS_

#include <afx.h>
#include <afxtempl.h>

class SXFMapEntDConvC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapEntDConvC( ) ;

//	<�R���X�g���N�^>
	SXFMapEntDConvC(CString*) ;
	SXFMapEntDConvC(CString&) ;
	SXFMapEntDConvC(char*) ;

//	<�f�X�g���N�^>
//
	virtual	~SXFMapEntDConvC() ;

//
//�G���e�B�e�B���̓o�^
	int	SetEntitydata(CString&);

//
//	<integer�ւ̕ϊ�>
	int		GetInt(int&);
//
//	<double�ւ̕ϊ�>
	double	GetDouble(double& );
//
//	<String�ւ̕ϊ�>
	CString	GetCString();
//
//	<instanceID�ւ̕ϊ�>
	int		GetInst(int&);
//
//	<BOOL�ւ̕ϊ�>	
	int	GetBOOL(BOOL& OUT_BOOL);

//
//	<Set�^��integer�ւ̕ϊ�>
	int		GetSetInt(int&	OUT_Num ,CArray<int,int>&);
//
//	<Set�^��double�ւ̕ϊ�>
	int		GetSetDouble(int& OUT_Num , CArray<double,double>& OUT_Instarray);
//
//	<Set�^��instanceID�ւ̕ϊ�>
	int		GetSetInst(int&	OUT_Num ,CArray<int,int>& );

//
//	<SetSelect�^��double�ւ̕ϊ�>
	int		GetSetSelectDouble( CString& IN_Select, int& OUT_Num, CArray<double,double>& OUT_array);
	int		GetSetSelectDouble( char* IN_Select, int& OUT_Num, CArray<double,double>& OUT_array);

//
//	<Select�^�� double �ւ̕ϊ�>
	int		GetSelectDouble( CString& IN_Select, double &OUT_Double );
	int		GetSelectDouble( char* IN_Select, double &OUT_Double );
//
//	<Select�^�� CString �ւ̕ϊ�>
	BOOL	GetSelectCString(CString& IN_Select, CString& OUT_CString);
	BOOL	GetSelectCString(char* IN_Select, CString& OUT_CString);

// SELECT�^�̕�����폜 IDENTIFIER('XXXXXX')=>XXXXXX (�����R�[�h�ϊ��Ȃ�)
	BOOL	TrimSelect( CString& IN_Select, CString &OUT_CString );
	BOOL	TrimSelect( char* IN_Select, CString &OUT_CString );

//	DEL(S)	�`���[�j���O�Ή�	K.Naono
/*
//	�O��̊��ʁi�j ���폜����
	BOOL TrimKako(CString*& INOUT_CString);
*/
//	DEL(E)	�`���[�j���O�Ή�	K.Naono

private :

	void consumeQuote(CString& inSource) ;
//
//	<Set�^��CStringArray�ւ̕ϊ�>
	int		ConvCStringArray();

protected :

//
//	<�G���e�B�e�B�f�[�^>
	CString		m_Entity;

//
//	<���������G���e�B�e�B�f�[�^>
//	CStringArray*	m_Splitarray;

//	<���������G���e�B�e�B�f�[�^(���[�N)>
//	CStringArray	m_SplitarrayTemp;

//
//	<���������G���e�B�e�B�f�[�^>
//	CStringArray*	m_SplitarrayPP;

//	<���������G���e�B�e�B�f�[�^(���[�N)>
//	CStringArray	m_SplitarrayTT;

} ;

#endif

////////////////////////////
