/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�N���X�T�v
		�����^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFD_RealC.h"
#include "SXFPart21FileC.h"
#include "SXFutyFunctionC.h"
#include <iomanip>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_RealC::SXFD_RealC(float data)
	����:	�^						������				���e
			float					data			�����^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_RealC::SXFD_RealC(float data) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_RealC(double data)
	����:	�^						������				���e
			double					data		�����^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_RealC::SXFD_RealC(double data) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_RealC(int data)
	����:	�^						������				���e
			int						data		�����^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
SXFD_RealC::SXFD_RealC(int data) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g

	�Q�D�C���^�[�t�F�[�X
		void	SetData( float data )
	����:	�^					������				���e
			float				data		�����^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_RealC::SetData( float data ) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g

	�Q�D�C���^�[�t�F�[�X
	void	SetData( double data )
	����:	�^						������				���e
			double					data		double�^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_RealC::SetData( double data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g

	�Q�D�C���^�[�t�F�[�X
		void	SetData( int data )
	����:	�^						������				���e
			int						data			int�^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_RealC::SetData( int data ) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�f�[�^���擾

	�Q�D�C���^�[�t�F�[�X
		double	SXFD_RealC::GetData( )
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
double	SXFD_RealC::GetData( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�v�f���o��

	�Q�D�C���^�[�t�F�[�X
		void	WriteAttr(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC					*IN_file	̧�ٵ�޼ު��

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_RealC::WriteAttr(SXFPart21FileC *IN_file) {
	CString real_str;
	real_str.Format("%16.6lf",m_Data);
	real_str.TrimLeft();
	real_str.TrimRight();
	IN_file->WriteString(real_str);
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						�쐬���F2001.06.12

	�P�D�@�\�T�v
		�v�f���o��

	�Q�D�C���^�[�t�F�[�X
		void	WriteAttr(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC					*IN_file	̧�ٵ�޼ު��

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.12	���X��(FQS)	�Ȃ��B
**/
void	SXFD_AngleC::WriteAttr(SXFPart21FileC *IN_file) {
	CString real_str;
	real_str = SXFutyFunctionC::out_ctl(m_Data);
	real_str.TrimLeft();
	real_str.TrimRight();
	IN_file->WriteString(real_str);
}
