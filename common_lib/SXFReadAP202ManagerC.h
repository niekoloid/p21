//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFReadAp202ManagerC.h                 �쐬���F2001.06.24
//
//	�P�D�N���X�T�v
//      AP202���͂̎��A�Z���u���Ԃ̎Q�Ɗ֌W
//      ���Ǘ�����I�u�W�F�N�g
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.24     ���X��
//		�X�V		2015.04.27		T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�
//
//------------------------------------------------------------

#ifndef _SXFREADAP202MANAGERC_H_
#define _SXFREADAP202MANAGERC_H_

#include <afx.h>
#include <afxtempl.h>

#include "SXFStruct.h"
#include "SXFDataStructC.h"

class SXFInstanceIDC;
class SXFTableManagerC;
class SXFComInfoC;

typedef struct SXFFeatureDelete{
	LPVOID	p;
	CString	name;
}SXFFEATUREDELETE;

typedef struct SXFSymbolInfo{
	int		id;
	int		typeflag;	//1: $$FM_
						//2: $$FG_
						//3: $$G_
						//4: $$P_
	CString	name;
	int		locateflag;//0:�܂��z�u����Ă��Ȃ� 1:���łɔz�u����Ă���
//	ADD(S)	������ǂݍ��݂��s���ƕs�����	K.Naono	03.08.05
	SXFSymbolInfo() {
		id			= -1 ;
		typeflag	= -1 ;
		locateflag	= -1 ;
	}
//	ADD(E)	������ǂݍ��݂��s���ƕs�����	K.Naono	03.08.05
}SXFSYMBOLINFO;

typedef struct SXFAssemblyData{
	int ID;
	int AssemblyCode;
	int	error;
	SXFAssemblyData () {
		ID = 0;
		AssemblyCode = 0;
		error = 0;
	}
}SXFASSEMBLYDATA;

typedef CTypedPtrList<CPtrList,SXFASSEMBLYDATA*> SXFAPASSEMBLYLIST;

class SXFReadAP202ManagerC  
{
public:
	SXFReadAP202ManagerC();
	SXFReadAP202ManagerC(SXFInstanceIDC* IN_InstanceIDManager,SXFTableManagerC* IN_TableManager,SXFComInfoC* IN_ComInfo);

	virtual ~SXFReadAP202ManagerC();

//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	int GetNextFeature(	char*	OUT_TypeName,
						size_t	TypeNameSize,	// �o�b�t�@�T�C�Y��n���悤�ɕύX
						LPVOID&	OUT_Struct,
						int*	OUT_EndFlg);

	int GetNextAssembly(int		IN_Type,
						LPVOID&	OUT_Struct,
						int*	OUT_EndFlg,
						int&	OUT_InstanceID);

	BOOL RegisterAPAssembly(INSTANCEDATA *IN_Instance);

	BOOL ArrangeChild( int ExternalFlg);//ExternalFlag 0:StepFileRead 1:ExternalFileRead

	int m_SheetID;

	BOOL GetAllChild(int IN_ID, CUIntArray& OUT_ChildArray);

	int FindSymbolID( int IN_ID );

	int GetAssemblyCode(int IN_AssemblyID);

	BOOL GetSymbolInfo(int IN_SymbolID, int& OUT_Flag, CString& OUT_Name);

	int GetAssemblyID(int IN_AssemblyCode);

	BOOL SymbolCodeCheck( int IN_Code );

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//	CArray<SXFSYMBOLINFO,SXFSYMBOLINFO&> m_SymbolInfoTable;
	CMapStringToPtr	m_SymbolInfoTable;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//	BOOL SfigNameCheck( LPCTSTR IN_Name);
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

	BOOL GetSymbolID(LPCTSTR IN_Name,int& OUT_SymbolID, int& OUT_Flag);
	BOOL GetSfigFlg( LPCTSTR IN_Name,int* OUT_SfigFlg,int*OUT_LocFlg);
	BOOL SetLocFlg( LPCTSTR IN_Name);
	BOOL CheckHatchID( int IN_ID);

private:

	BOOL GetSymbolChild(int IN_ID,
				CUIntArray& OUT_ChildArray);
	BOOL SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray);

//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
	BOOL	builtRelationship(int	inID) ;
	CMapWordToPtr	m_mapSymId ;
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.04

private:
	SXFAPASSEMBLYLIST*	m_CurveAssemblyList;	/* �����Ȑ�̨���ð��� */
	int					m_code;					/* �����غ��� */
	CUIntArray m_CurveIDArray;
	CUIntArray m_SymbolIDArray;

	CUIntArray m_CurrentChildArray;

	int m_CurrentAssemblyType;	//1:sheet
								//2:symbol
								//3:curve
	int m_CurrentAssemblyNumber;
	int m_currentassemblyID;
	int m_CurrentChildArraySize;
	int m_CurrentChildNumber;

	char m_currentchild_TypeName[64];
	LPVOID m_currentchild_Struct;
	int m_currentchild_ID;

	//////temp data
	CUIntArray m_SymbolArrangeIDArray;
	CUIntArray m_SymbolIDTempArray;

//	CArray<SXFASSEMBLYDATA,SXFASSEMBLYDATA> m_SymbolIDTempArray;
//	CArray<SXFASSEMBLYDATA,SXFASSEMBLYDATA> m_CurveIDArray;

	SXFInstanceIDC *m_InstanceIDManager;

//	CTypedPtrArray<CPtrArray, SXFMapManagerC*> m_MapManagerArray;

	SXFTableManagerC* m_TableManager;
	SXFComInfoC *m_ComInfo;

//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
/*
	Sheet_Struct* m_SheetStruct;
	CArray<Sfigorg_Struct*,Sfigorg_Struct*> m_SfigStructArray;
	CArray<Ccurve_Org_Struct*,Ccurve_Org_Struct*> m_CurveStructArray;
*/
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.04

#if 0	// delete by emoto
	CArray<SXFFEATUREDELETE,SXFFEATUREDELETE> m_FeatureDeleteArray;
#endif
};

#endif