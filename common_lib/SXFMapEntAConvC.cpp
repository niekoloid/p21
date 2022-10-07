/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EntityArrayData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntDConvC.h"
#include "SXFMapEntAConvC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntAConvC::SXFMapEntAConvC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntAConvC::SXFMapEntAConvC()
{
//
//	<������>
//	<���������G���e�B�e�B�f�[�^>
//	m_EntityArray;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntAConvC::SXFMapEntAConvC(
					CStringArray*		IN_EntityArray)
					

	����  �F	�^					������				���e
				CStringArray*		IN_EntityArray		�G���e�B�e�B�f�[�^

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntAConvC::SXFMapEntAConvC(
		CStringArray*	IN_EntityArray)
{
	m_EntityArray = IN_EntityArray;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntAConvC::~SXFMapEntAConvC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntAConvC::~SXFMapEntAConvC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntAConvC::SetEntityArray(
			CStringArray* IN_EntityArray	//	<�G���e�B�e�B�f�[�^>

	����  �F	�^				������				���e
				CStringArray* 	IN_EntityArray

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapEntAConvC::SetEntityArray(
		CStringArray* IN_EntityArray	//	<���������G���e�B�e�B�f�[�^>
		)
{
	m_EntityArray = IN_EntityArray;

	return 0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�w�肳�ꂽ�z��Y�����̃t�B�[�`���f�[�^���^�ϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntAConvC::GetInt(int IN_Int	,int& Out_int)

	����  �F	�^			������				���e
				int 		IN_Int
				int&		Out_int

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

//	<integer�ւ̕ϊ�>
int SXFMapEntAConvC::GetInt(int IN_Int	,int& Out_int)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	Out_int =  atoi( (*m_EntityArray)[IN_Int] );
	return 0;
}

//	<double�ւ̕ϊ�>
int SXFMapEntAConvC::GetDouble(int IN_Int	,double& OUT_double)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	OUT_double = atof( (*m_EntityArray)[IN_Int] );
	return 0;
}

//	<String�ւ̕ϊ�>
int SXFMapEntAConvC::GetCString(int IN_Int	,CString& OUT_String)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Int]);
	OUT_String = SXFMapEntDConvC::GetCString();
	return 0;
}

//	<instanceID�ւ̕ϊ�>
int SXFMapEntAConvC::GetInst(int IN_Int	,int& Out_Int)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Int]);
	SXFMapEntDConvC::GetInst(Out_Int);

	return 0;
}

//	<instanceID�ւ̕ϊ�>
int SXFMapEntAConvC::GetBOOL(int IN_Int	,BOOL& OUT_BOOL)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Int]);
	SXFMapEntDConvC::GetBOOL(OUT_BOOL);

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�Z�b�g�^�̃t�H�[�`���f�[�^�̌^�ϊ�����

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntAConvC::GetSetDouble(
					int IN_Num,
					int& OUT_Num,	
					CArray<double,double>&  OUT_array )

	���� �F	�^						������				���e
			int 					IN_Num
			int&		 			OUT_Num
			CArray<double,double>&  OUT_array

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

//		�Z�b�g�^�̃t�B�[�`���f�[�^��double�ɕϊ�����

int	SXFMapEntAConvC::GetSetDouble(
					int IN_Num,
					int& OUT_Num,	
					CArray<double,double>&  OUT_array )
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetDouble(OUT_Num,OUT_array);

	return 0;

}
//		�Z�b�g�^�̃t�B�[�`���f�[�^��integer�ɕϊ�����
int	SXFMapEntAConvC::GetSetInt( int IN_Num
							,int& OUT_Num
							,CArray<int,int>&  OUT_array )
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetInt(OUT_Num,OUT_array);

	return 0;

}

//		�Z�b�g�^�̃t�B�[�`���f�[�^��InstanceID�ɕϊ�����
int	SXFMapEntAConvC::GetSetInst(
			int IN_Num,	
			int& OUT_Num,
			CArray<int,int>& OUT_array )
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetInst(OUT_Num,OUT_array);

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		Select�^�̕ϊ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntAConvC::GetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						double& OUT_Double)

	���� �F	�^			������				���e
			int 		IN_Num
			CString& 	IN_Select
			double& 	OUT_Double

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
//		Select�^��double�ւ̕ϊ�
int		SXFMapEntAConvC::GetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						double& OUT_Double)
{

//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectDouble(IN_Select,OUT_Double);

	return 0;

}


int		SXFMapEntAConvC::GetSelectDouble(
						int IN_Num,
						char* IN_Select,
						double& OUT_Double)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if (IN_Num > m_EntityArray->GetSize()){
	if (IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectDouble(IN_Select,OUT_Double);

	return 0;

}


//	<�Y�����Ŏw�肳�ꂽ�G���e�B�e�B�f�[�^�́ASelect�^��CString�ւ̕ϊ�>
BOOL	SXFMapEntAConvC::GetSelectCString(
			int IN_Num, 
			CString& IN_Select, 
			CString& OUT_CString)
{
//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if (IN_Num > m_EntityArray->GetSize()){
	if (IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return FALSE;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectCString( IN_Select, OUT_CString );

	return TRUE;
}


BOOL	SXFMapEntAConvC::GetSelectCString(
			int IN_Num, 
			char* IN_Select, 
			CString& OUT_CString)
{

//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if (IN_Num > m_EntityArray->GetSize()){
	if (IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return FALSE;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectCString(IN_Select,OUT_CString);

	return TRUE;
}



/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		Select�^��double�ւ̕ϊ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntAConvC::GetSetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						int& OUT_Num,  
						CArray<double,double>& OUT_array)

	���� �F	�^						������				���e
			int 					IN_Num
			CString& 				IN_Select
			int&	 				OUT_Num
			CArray<double,double>& 	OUT_array

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

// SET+SELECT�^�̗�
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,	(#516,PARAMETER_VALUE(0.0)),
//		(#517,PARAMETER_VALUE(12.383404246416728)), .T.,.PARAMETER.);
//#104 = TRIMMED_CURVE('trimmed_curve1', #103, 
//	(PARAMETER_VALUE(3.141593)),(PARAMETER_VALUE(0.)), .T., .PARAMETER.);

//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS(
//	( BOX_HEIGHT(1.), BOX_WIDTH(1.),BOX_SLANT_ANGLE(0.),BOX_ROTATE_ANGLE(0.)) 
//	)
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

//		SetSelect�^��double�ւ̕ϊ�
int		SXFMapEntAConvC::GetSetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						int& OUT_Num,  
						CArray<double,double>& OUT_array)
{

//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetSelectDouble(IN_Select, OUT_Num, OUT_array);

	return 0;

}

int		SXFMapEntAConvC::GetSetSelectDouble(
						int IN_Num,
						char* IN_Select,
						int& OUT_Num,  
						CArray<double,double>& OUT_array)
{

//	MOD(S)	�o�O�C��	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	�o�O�C��	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetSelectDouble(IN_Select, OUT_Num, OUT_array);

	return 0;

}
