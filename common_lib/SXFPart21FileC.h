//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.h	                  �쐬���F2000.03.25
//
//	�P�D�N���X�T�v
//      �t�@�C���̓��͂Əo�͂��Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		 �S����	    �T�v
//		�쐬		2000.03.25  ��
//		�X�V		2001.09.17	K.Naono		�w�b�_��͏����̉��P�Ή�
//
//---------------------------------------------------------
#include "SXFDataStructC.h"

class SXFPart21FileC:public CStdioFile{

public:
//
//	<�R���X�g���N�^>
//
    SXFPart21FileC();
    SXFPart21FileC( FILE* IN_pOpenStream );
    SXFPart21FileC( LPCTSTR IN_lpszFileName, UINT IN_nOpenFlags);

//
//	<�f�X�g���N�^>
//
    ~SXFPart21FileC();

//	MOD(S)	�w�b�_��͏����̉��P�Ή�	K.Naono		01.09.17
//	int  ReadHeadSection(HEADSECTION *IO_Head);
	virtual int  ReadHeadSection(HEADSECTION* IO_Head) ;
//	MOD(E)	�w�b�_��͏����̉��P�Ή�	K.Naono		01.09.17

//	int  ReadInstance(INSTANCEDATA *IO_Instance);
	virtual int  ReadInstance(INSTANCEDATA *IO_Instance) ;
	BOOL WriteHeadSection(HEADSECTION *IN_Head);
	BOOL WriteInstance(INSTANCEDATA *IN_Instance);

protected:
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//private:
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
	int ap202count;
	int featurecount;

};
