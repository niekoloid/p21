/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.h						�쐬���F2001.05.17

	�P�D�N���X�T�v
		���ʏ��i���x���E���[�h�j��ێ�����N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.05.17	�ЎR(FQS)	�Ȃ��B
**/

#ifndef _SXFCOMINFOC_CLASS_
#define _SXFCOMINFOC_CLASS_
#include "SXFDataStructC.h"

class SXFComInfoC
{
	char	m_file_name[257] ;		//�t�@�C����
	int		m_rw_flg ;				//�ǁ^���t���O
	double	m_tolerance ;			//�����p���e�덷
	double	m_tolerance2 ;			//�p�x���e�덷
	double	m_devide ;				//���e�덷
	int		m_level ;				//���x���w��
	int		m_mode ;				//���[�h
	char	m_author[257] ;			//�t�@�C���쐬��
	char	m_organization[257] ;	//�쐬�ҏ���
	char	m_trans_name[257] ;		//�g�����X���[�^��
	char	m_version[257] ;		//���ʃ��C�u�����o�[�W����
	int		m_IN_level;				//���͂��ꂽ���x��
	int		m_exfile;				//�O���t�@�C���ǂݍ��݃t���O

public :
//	void Get_ExFileFlg(int &OUT_ExFileFlg);
//	void Get_Divide(double& OUT_Divide);
	int SetFileInfo(HEADSECTION IN_Head);
	void Get_RWFlag(int &OUT_RWFlag);
//------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------
	SXFComInfoC() ;
//------------------------------------------------
//	�f�X�g���N�^
//------------------------------------------------
	~SXFComInfoC() ;
//------------------------------------------------
//	���ʏ���ێ�(write)
//------------------------------------------------
	void Set_Write_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode, char IN_author[257], char IN_organization[257], char IN_trans_name[257]) ;
//------------------------------------------------
//	���ʏ���ێ�(read)
//------------------------------------------------
	void Set_Read_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode) ;
//------------------------------------------------
//	�S���ԋp
//------------------------------------------------
	void Get_Come(char OUT_fname[257], int &OUT_flg, double &OUT_tolerance, double &OUT_tolerance2, double &OUT_devide, int &OUT_level, int &OUT_mode, char OUT_author[257], char OUT_organization[257], char OUT_trans_name[257], char OUT_version[257]) ;
//------------------------------------------------
//	�t���O�̎擾
//------------------------------------------------
	void Get_Flg(int &OUT_flg) ;
//------------------------------------------------
//	�g�������X���̎擾
//------------------------------------------------
	void Get_Tolerance(double &OUT_tolerance, double &OUT_tolerance2) ;
private:
	int m_FileMode;
	int m_FileLevel;
} ;

#endif