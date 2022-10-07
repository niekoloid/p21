/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EntityArrayData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapEntAConvC_CLASS_
#define _SXFMapEntAConvC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntDConvC.h"

class SXFMapEntAConvC : public SXFMapEntDConvC{
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapEntAConvC( ) ;

//	<�R���X�g���N�^>
	SXFMapEntAConvC(CStringArray*) ;
//	SXFMapEntAConvC(CStringArray&) ;

//	<�f�X�g���N�^>
//
	virtual	~SXFMapEntAConvC() ;

//�G���e�B�e�B���ƃG���e�B�e�B�f�[�^�̓o�^
	int	SetEntityArray(CStringArray*);

////// Get�p�̃����o�֐�///////////////

//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́Ainteger�֕ϊ�>
	int		GetInt(int	,int&);

//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́Adouble�֕ϊ�>
	int		GetDouble(int	,double& );

//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ACString�֕ϊ�>
	int		GetCString(int	,CString&);

//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́AinstanceID�֕ϊ�>
	int		GetInst(int	,int&);

//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ABOOL�֕ϊ�>
	int		GetBOOL(int IN_Int	,BOOL& OUT_BOOL);

//
//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASet��integer�֕ϊ�>
	int		GetSetInt(int	,int&	,CArray<int,int>&);
//
//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASet��double�֕ϊ�>
	int		GetSetDouble(int	,int&	,CArray<double,double>& );
//
//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASet��instanceID�֕ϊ�>
	int		GetSetInst( int IN_Num	,int& OUT_Num	,CArray<int,int>& OUT_array );

//
//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASelect��double�֕ϊ�>

int		GetSelectDouble(int IN_Num,CString& IN_Select,double& OUT_Double);
int		GetSelectDouble(int IN_Num, char* IN_Select,double& OUT_Double);

//
//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASelect��CString�֕ϊ�>
BOOL	GetSelectCString(int IN_Num, CString& IN_Select, CString& OUT_CString);
BOOL	GetSelectCString(int IN_Num, char* IN_Select, CString& OUT_CString);

//
//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASetSelect��double�֕ϊ�>
//		SetSelect�^��double�ւ̕ϊ�
int		GetSetSelectDouble(int IN_Num,CString& IN_Select,int& OUT_Num, 
						   CArray<double,double>& OUT_array);
int		GetSetSelectDouble(int IN_Num,char* IN_Select,int& OUT_Num, 
						   CArray<double,double>& OUT_array);

//	<Set�^��CStringArray�ւ̕ϊ�>
//	CStringArray*		ConvCStringArray(CString&);

private :

protected :

//
//	<�G���e�B�e�B�f�[�^>
//	CString		m_EntityName;
//
//	<�G���e�B�e�B�f�[�^>
//	CString		m_EntityData;
//
//	<���������G���e�B�e�B�f�[�^>
	CStringArray*	m_EntityArray;

} ;

#endif

////////////////////////////
