/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�N���X�T�v
	���[���`�F�b�N���ʊ֐��N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include "SXFComFunctionC.h"
#include "max.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	 SXFComFunctionC::SXFComFunctionC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFComFunctionC::SXFComFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	 SXFComFunctionC::~SXFComFunctionC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFComFunctionC::~SXFComFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		double�͈̔̓`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int double_check(double IN_double);

	����:	�^			������		���e
			double		IN_double	�`�F�b�N�Ώۂ̐��l

	���A�l	���펞�F�O
			�ُ펞�F�|�P

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B
	�X�V			2002.03.06			K.Naono				�o�O�C��
**/
int SXFComFunctionC::double_check(double IN_double)
{
//	MOD(S)	��Q�C��	K.Naono	02.03.06
//	if ((IN_double <= 0.0) || (IN_double >= MAXDOUBLE))
//		return -1;
//	else
//		return 0;

	// 0.000000000000004�ȉ��܂��́A999999999999999.5�ȏ�
	if ((IN_double <= MIN_CHK_DOUBLE) || (IN_double >= MAX_CHK_DOUBLE)) {
		return -1 ;
	}

	// 0.000000000000004 < IN_double < 0.000000000000005
	if ((IN_double > MIN_CHK_DOUBLE) && (IN_double < LMT_CHK_DOUBLE)) {
		return -1 ;
	}

	return 0 ;
//	MOD(E)	��Q�C��	K.Naono	02.03.06
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�p�x�͈̔̓`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int angle_check(double IN_angle);

	����:	�^			������		���e
			double		IN_angle	�p�x

	���A�l	���펞�F�O
			�ُ펞�F�|�P

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFComFunctionC::angle_check(double &IN_angle)
{
	if ((IN_angle < MINANGLE) || (IN_angle > MAXANGLE)) {				// 2010.08
		return -1;
	} else {
		if (359.999999999999999 < IN_angle && IN_angle <= MAXANGLE) {	// 2010.08
			IN_angle = 359.999999999999999;
		}
		return 0;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�Q�_�Ԃ̋��������߂�

	�Q�D�C���^�[�t�F�[�X
	double calc_length(double IN_x1,double IN_y1,
						double IN_x2,double IN_y2);

	����:	�^			������		���e
			double		IN_x1		�n�_X���W
			double		IN_y1		�n�_Y���W
			double		IN_x1		�I�_X���W
			double		IN_y2		�I�_Y���W

	���A�l	���펞�F��_�Ԃ̋���

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
double SXFComFunctionC::calc_length(double IN_x1, 
									double IN_y1,
									double IN_x2, 
									double IN_y2)
{
	double ret = sqrt( (IN_x2 - IN_x1) * (IN_x2 - IN_x1) 
							+ (IN_y2 - IN_y1) * (IN_y2 - IN_y1) );
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		double�͈̔̓`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int max_double_check(double IN_double);

	����:	�^			������		���e
			double		IN_double	�`�F�b�N�Ώۂ̐��l

	���A�l	���펞�F�O
			�ُ펞�F�|�P

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFComFunctionC::max_double_check(double IN_double)
{
	if ((IN_double < 0.0) || (IN_double >= MAXDOUBLE))
		return -1;
	else
		return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�X�����g�p�͈̔̓`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int slant_check(double IN_slant);

	����:	�^			������		���e
			double		IN_slant	�X�����g�p�x

	���A�l	���펞�F�O
			�ُ펞�F�|�P

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFComFunctionC::slant_check(double IN_slant)
{
	if ((IN_slant < MINSLANT) || (IN_slant > MAXSLANT))
		return -1;
	else
		return 0;
}
