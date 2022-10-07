/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.06.13

	�P�D�N���X�T�v
		���ʊ֐��N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.13			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include <math.h>
#include "SXFutyFunctionC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.06.13

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFutyFunctionC::SXFutyFunctionC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �@�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.13			���X��(FQS)			�Ȃ��B

**/
SXFutyFunctionC::SXFutyFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.06.13

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFutyFunctionC::~SXFutyFunctionC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.13			���X��(FQS)			�Ȃ��B

**/
SXFutyFunctionC::~SXFutyFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.06.13

	�P�D�@�\�T�v
		�p�x�����߂�

	�Q�D�C���^�[�t�F�[�X
		void	SXFutyFunctionC::make_angle(double start_x, double start_y, double end_x, double end_y, double *angle)
		
	����	�F	�^		������				���e
	double start_x			 �n�_�w���W 
	double start_y			 �n�_�x���W 
	double end_x			 �I�_�w���W 
	double end_y			 �I�_�x���W 
	double angle			 �p�x

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.13			���X��(FQS)			�Ȃ��B

**/
void SXFutyFunctionC::make_angle(double start_x, double start_y, double end_x, double end_y, double *angle)
{
	double LA;
	double Ax,Ay;

	//���@�����_�Ɩ��z�u���W�Ƃ̒���
	LA = fabs(sqrt(pow(end_x - start_x, 2)+pow(end_y - start_y, 2)));
	//�x�N�g��
	Ax = (end_x - start_x) / LA;
	Ay = (end_y - start_y) / LA;

	//	�p�x�����߂�
	if (Ay >= 0){
		//��P�ی�
			*angle = atan2(Ay,Ax);
		//��Q�ی�
	}
	else if (Ay < 0){
		*angle = 2 * acos(-1.) + atan2(Ay,Ax);
		//��4�ی�
		//��3�ی�
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.06.13

	�P�D�@�\�T�v
		�x�N�g������p�x�����߂�

	�Q�D�C���^�[�t�F�[�X
		void	SXFutyFunctionC::calc_angle(double y, double x)
		
	����	�F	�^		������				���e
			double		 y		�x�N�g��X����
			double		 x		�x�N�g��Y����

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.13			���X��(FQS)			�Ȃ��B

**/
double SXFutyFunctionC::calc_angle(double y, double x)
{
	double ret;

	ret = (atan2(y,x))*180.0/ acos(-1.);
	if (ret < 0)
		ret = 360.0 + ret;

	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.06.13

	�P�D�@�\�T�v
		�p�x�̐��K��

	�Q�D�C���^�[�t�F�[�X
		void	SXFutyFunctionC::angle_over()
		
	����	�F	�^		������				���e


	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.13			���X��(FQS)			�Ȃ��B

**/
double SXFutyFunctionC::angle_over(double IN_angle)
{
	double ret_angle;
	if (IN_angle >=360.){
		ret_angle = IN_angle - ((int)(IN_angle/360))*360;
	}
	else if (IN_angle < 0.0){
		ret_angle = IN_angle - ((int)(IN_angle/360-1))*360;
	}
	else 
		ret_angle = IN_angle ;
	return ret_angle;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2001.2.23

	�P�D�@�\�T�v
		�p�x��L����15���̕�����ɕϊ�

	�Q�D�C���^�[�t�F�[�X
		CString	SXFutyFunctionC::out_ctl(double IN_angle)
		
	����	�F	�^		������		���e
				double	IN_angle	�p�x

	���A�l�F
				CString		out		�L����15���̕�����

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.23			���X��(FQS)			�Ȃ��B
	�X�V			2002.03.06			K.Naono				�o�O�C��

    �S�D�⑫����
			double �̌^���l�𕶎���ɕϊ����܂��B

			char *_ecvt( double value, int count, int *dec, int *sign )

				�߂�l

					_ecvt �͐��l������ւ̃|�C���^��Ԃ��܂��B

				����

					value   �ϊ����鐔�l

					count   �i�[���錅��

					dec		�i�[���ꂽ�����_�ʒu

					sign   �ϊ����ꂽ���l�̕���

			��F
				value	count	dec		sign
				1.0		15		1		100000000000000
				0.1		15		0		100000000000000
				0.01	15		-1		100000000000000

**/
CString SXFutyFunctionC::out_ctl(double IN_angle)
{
	// �����_�̈ʒu
	int		decimal;
	// ���̒l�����̒l���H
	int		sign;
	// ����
//	char	*buffer;
	// �T�C�Y
	int		precision = 15;

//	ADD(S)	��Q�C��	K.Naono	02.03.06
	if( IN_angle <= 1.0e-014 ) {
		IN_angle += 5.0e-015 ;
	}
//	ADD(E)	��Q�C��	K.Naono	02.03.06

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	buffer = _ecvt(	IN_angle, 
//					precision,
//					&decimal,
//					&sign );
	char buffer[_CVTBUFSIZE] = "";
	_ecvt_s(	buffer,
				_countof(buffer),
				IN_angle, 
				precision,
				&decimal,
				&sign );
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

	//�����_�̈ʒu��0�܂��͕��̏ꍇ��buffer�̑O��0.00�����K�v
	/* �Ⴆ��0.0001�̂Ƃ�decimal=-3*/
	/* 0.0�̂Ƃ�deciaml=0 */
	CString tmp_out,out ;
	if (decimal <= 0){
		CString tmp_str("0.00000000000000");
		tmp_out = CString(buffer);
		out = tmp_str.Left(abs(decimal)+2) + tmp_out.Left(precision - (abs(decimal)+1));
	}
	//�����_������
	else{
		out = CString(buffer);
		out.Insert(decimal,'.');
	}

	//����������
	if (sign)
		out = "-" + out;

	return out;
}
