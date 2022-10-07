//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileWriteC.h				  �쐬���F2000.03.26
//
//	�P�D�N���X�T�v
//		�t�@�C���̏o�͂��Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		 �S����		�T�v
//		�쐬		2000.03.26	 ��
//
//---------------------------------------------------------

#include "SXFDataStructC.h"

class SXFPart21FileC;

class SXFPart21FileWriteC{

public:
//
//	<�R���X�g���N�^>
//
	SXFPart21FileWriteC();
//
//	<�f�X�g���N�^>
//
	~SXFPart21FileWriteC();
	int OpenPart21WriteFile(LPCTSTR IN_FileName );
	BOOL ClosePart21WriteFile(	);

	BOOL SetHeadSection( int  *IN_Level,
						 int  *IN_Mode,
						 char *IN_FileName,
						 char *IN_Author,
						 char *IN_Organization,
						 char *IN_Version,
						 char *IN_OriginatingSystem );

	int WriteHeadSection( );
	
	BOOL WriteFeatureInstance(INSTANCEDATA* feature);
	//BOOL WriteAP202Instance(INSTANCEDATA* instance);

	//�ϊ��Ǘ�����t�@�C���̃n���h�����擾
	SXFPart21FileC* GetFileHandle();


protected:
	HEADSECTION  m_HeadSection;
	SXFPart21FileC *m_File;
};