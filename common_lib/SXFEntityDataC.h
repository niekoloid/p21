//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.h					  �쐬���F2000.04.07
//
//	�P�D�N���X�T�v
//		�G���e�B�e�B�f�[�^��ێ�����I�u�W�F�N�g
//		
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2000.04.07	   ��
//
//------------------------------------------------------------

class SXFEntityDataC  
{
public:
	SXFEntityDataC();
	virtual ~SXFEntityDataC();

//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	BOOL SetEntityData(LPVOID& IO_DataInFilePtr,INSTANCEDATA *IN_Instance);
	// IO_DataInFilePtr ���g�p�ł���c��̃o�b�t�@�T�C�Y��n��
	size_t SetEntityData(LPVOID& IO_DataInFilePtr,size_t AvailableSize,INSTANCEDATA *IN_Instance);
	BOOL GetEntityData(CString& OUT_EntityData);
	BOOL GetEntityDataArray(CStringArray& OUT_EntityDataArray);

public:

	CString m_EntityName;
	int m_InstanceID;
	int m_InstanceMode;
	LPTSTR m_EntityDataPtr;
};
