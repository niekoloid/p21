/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�N���X�T�v
		��`�e�[�u���v�f�̃��[���`�F�b�N

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFTableCheckC.h"
#include "SXFTableManagerC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFTableCheckC::SXFTableCheckC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
SXFTableCheckC::SXFTableCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFTableCheckC::~SXFTableCheckC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
SXFTableCheckC::~SXFTableCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�����v�f�̑������[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::TextFeature_Check()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F0
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::TextFeature_Check()
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Font
	error_code = FontCheck();
	if (error_code < 0)
		return error_code;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�����̑������[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::LineFeature_Check()
		
	����	�F	�^			������			���e
				�Ȃ�
				
	���A�l	���펞�F0
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::LineFeature_Check()
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Type
	error_code = TypeCheck();
	if (error_code < 0)
		return error_code;
	//Width
	error_code = WidthCheck();
	if (error_code < 0)
		return error_code;
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		���C���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::LayerCheck()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::LayerCheck()
{
	if (m_TableManager->GetID(1,m_layer) < 0){
		SXFErrorMsgC::RecordError(SXFEUNSETLAYER,
									m_feature_name,
									3,
									m_InstanceID,
									m_layer,
									m_feature_name);
		return SXFEUNSETLAYER;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�F�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::ColorCheck()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::ColorCheck()
{
	int table_type;
	if (m_color < 17)
		table_type = 2;
	else
		table_type = 3;
	if (m_TableManager->GetID(table_type,m_color) < 0){
		SXFErrorMsgC::RecordError(SXFERRORCOLOUR,
									m_feature_name,
									3,
									m_InstanceID,
									m_color,
									m_feature_name);
		return SXFERRORCOLOUR;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::TypeCheck()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::TypeCheck()
{
	int table_type;
	if (m_type < 17)
		table_type = 4;
	else
		table_type = 5;
	if (m_TableManager->GetID(table_type,m_type) < 0){
		SXFErrorMsgC::RecordError(SXFERRORFONT,
									m_feature_name,
									3,
									m_InstanceID,
									m_type,
									m_feature_name);
		return SXFERRORFONT;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::WidthCheck()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::WidthCheck()
{
	if (m_TableManager->GetID(6,m_line_width) < 0){
		SXFErrorMsgC::RecordError(SXFERRORWIDTH,
									m_feature_name,
									3,
									m_InstanceID,
									m_line_width,
									m_feature_name);
		return SXFERRORWIDTH;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�����t�H���g�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::FontCheck()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::FontCheck()
{
	if (m_TableManager->GetID(7,m_font) < 0){
		SXFErrorMsgC::RecordError(SXFTEXTFONTERROR,
									m_feature_name,
									3,
									m_InstanceID,
									m_font,
									m_feature_name);
		return SXFTEXTFONTERROR;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�����Ȑ��̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::CompCurveFeature_Check()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::CompCurveFeature_Check()
{
	int error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Type
	error_code = TypeCheck();
	if (error_code < 0)
		return error_code;
	//Width
	error_code = WidthCheck();
	if (error_code < 0)
		return error_code;
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		���@���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::DimFeature_Check(int IN_TextFlag)
		
	����	�F	�^			������			���e
				int			IN_TextFlag		���@�l�L���t���O(0:��1:�L)

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::DimFeature_Check(int IN_TextFlag)
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	//Type
	error_code = TypeCheck();
	if (error_code < 0)
		return error_code;
	//Width
	error_code = WidthCheck();
	if (error_code < 0)
		return error_code;
	//Font
	if (IN_TextFlag == 1){
		error_code = FontCheck();
		if (error_code < 0)
			return error_code;
	}
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�_�}�[�J�̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::PointMarkerFeature_CheckC()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::PointMarkerFeature_CheckC()
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	error_code = ColorCheck();
	if (error_code < 0)
		return error_code;
	return 0;
	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		����`�V���{���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::ExSymbol_Check(int IN_ColorFlag)
		
	����	�F	�^			������			���e
				int			IN_ColorFlag	�F�R�[�h�t���O(0:����1:�L��)

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::ExSymbol_Check( int IN_ColorFlag)
{
	int error_code;
	//Layer
	error_code = LayerCheck();
	if (error_code < 0)
		return error_code;
	//Color
	if (IN_ColorFlag != 0){
		error_code = ColorCheck();
		if (error_code < 0)
			return error_code;
	}
	return 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�����}�`�z�u�̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::SfiglocFeature_Check()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::SfiglocFeature_Check()
{
	//Layer
	if (m_layer != 0){
		int layer_error = LayerCheck();
		if (layer_error < 0)
			return layer_error;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		����`�n�b�`���O�̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		int	SXFTableCheckC::ExHatchFeature_Check()
		
	����	�F	�^			������			���e
				�Ȃ�

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableCheckC::ExHatchFeature_Check()
{
	//Layer
	int layer_error = LayerCheck();
	if (layer_error < 0)
		return layer_error;
	return 0;

}
