// SXFReadAP202MapManagerC.h: SXFReadAP202MapManagerC �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SXFREADAP202MAPMANAGERC_H__59F06301_279E_11D4_A3A9_009027565E9B__INCLUDED_)
#define AFX_SXFREADAP202MAPMANAGERC_H__59F06301_279E_11D4_A3A9_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
class SXFMapGeometryC;
class SXFInstanceIDC;
class SXFTableManagerC;
class SXFComInfoC;
class SXFMapAssemblyC;
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//class SXFFeatureC;
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

class SXFReadAP202MapManagerC  
{
public:
	void SetReturnFlag();
	LPVOID GetAssemblyStructData();
//	LPVOID GetStructData(char* OUT_TypeName);						JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	LPVOID GetStructData(char* OUT_TypeName,size_t TypeNameSize);	// �o�b�t�@�T�C�Y��n���悤�ɕύX
	LPVOID GetStructDataLevel(char *OUT_TypeName,int& OUT_Level);

	BOOL SetInstanceID(int IN_ChildID);
	BOOL SetAssemblyInstanceID(int IN_ChildID);
	SXFReadAP202MapManagerC();
	SXFReadAP202MapManagerC(SXFInstanceIDC* IN_InstanceIDManager,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo,
							SXFReadAP202ManagerC* IN_ReadManager);
	virtual ~SXFReadAP202MapManagerC();

private:
//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//	SXFFeatureC* m_Feature;		/* ̨�����޼ު�� */
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.03
	SXFMapAssemblyC* m_MapAssembly;
	SXFMapGeometryC* m_MapGeometry;
	SXFInstanceIDC* m_InstanceIDManager;
	SXFTableManagerC* m_TableManager;
	SXFComInfoC *m_ComInfo;

	SXFReadAP202ManagerC* m_ReadManager;
	
};

#endif // !defined(AFX_SXFREADAP202MAPMANAGERC_H__59F06301_279E_11D4_A3A9_009027565E9B__INCLUDED_)
