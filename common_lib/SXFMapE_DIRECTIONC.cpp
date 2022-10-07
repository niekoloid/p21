/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DIRECTIONC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DIRECTION���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_DIRECTIONC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DIRECTIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DIRECTIONC::SXFMapE_DIRECTIONC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DIRECTIONC::SXFMapE_DIRECTIONC()
{
//#101 = DIRECTION('DIRECTION1', (0., 0.));

//	<������>
	m_EntityName = DEF_DIRECTION;
//
//	<�G���e�B�e�B�f�[�^>
	m_name.Empty();
//
//	<(x,Y)>
	m_x =  m_y = 0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DIRECTIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DIRECTIONC::SXFMapE_DIRECTIONC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DIRECTIONC::SXFMapE_DIRECTIONC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//#101 = DIRECTION('DIRECTION1', (0., 0.));

//	<������>
	m_EntityName = DEF_DIRECTION;
//
//	<�G���e�B�e�B�f�[�^>
	m_name.Empty();
//
//	<(x,Y)>
	m_x =  m_y = 0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DIRECTIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DIRECTIONC::~SXFMapE_DIRECTIONC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DIRECTIONC::~SXFMapE_DIRECTIONC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DIRECTIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DIRECTIONC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/


int SXFMapE_DIRECTIONC::SetParameter()

{
	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
	convent.GetCString(0,m_name);
	//<(X,Y)>
	int num;
	CArray<double,double> array;
	convent.GetSetDouble(1,num,array);

	if ( num >=2 ){
		m_x = array[0];
		m_y = array[1];
	}
	else{
		//�G���e�B�e�B�p�����^�̐��Ɏӂ肪����܂��B
		SXFErrorMsgC::RecordError(
				SXFPARAMS,			//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_RootID,			//�p�����^
				m_EntityName
				);
		return SXFPARAMS;	//-55003
	}
	return 0;
}
