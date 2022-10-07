//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.h				  作成日：2001.05.26
//
//	１．クラス概要
//		ファイルの入力を管理する
// 
//	２．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.26	 佐々木(FQS)
//
//---------------------------------------------------------
#ifndef _SXFPART21FILEREADC_H_
#define _SXFPART21FILEREADC_H_

class SXFTableManagerC;
class SXFReadAP202ManagerC;
class SXFComInfoC;
class SXFInstanceIDC;

class SXFPart21FileReadC{

public:
//
//	<コンストラクタ>
//
	SXFPart21FileReadC();
	//SXFPart21FileReadC(SXFTableManagerC* IN_TableManager,SXFReadFeatureManagerC* IN_ReadFeatureManager,SXFComInfoC* IN_ComInfo,SXFInstanceIDC* IN_InstanceIDManager);

	SXFPart21FileReadC(SXFTableManagerC* IN_TableManager,
					   SXFReadAP202ManagerC*  IN_ReadAP202Manager,
					   SXFComInfoC* IN_ComInfo,
					   SXFInstanceIDC* IN_InstanceIDManager);

//
//	<デストラクタ>
//
	~SXFPart21FileReadC();
//
	int OpenPart21ReadFile( LPCTSTR IN_FileName );

	BOOL ClosePart21ReadFile(  );

	BOOL GetHeadData(int *OUT_Level,
					 int *OUT_Mode,
					 char *OUT_FileName,
					 char *OUT_Author,
					 char *OUT_Organization,
					 char *OUT_Version,
					 char *OUT_OriginatingSystem );
protected:

	BOOL RegisterAPEntity(INSTANCEDATA *IN_Instance);
	BOOL RegisterAPTable(INSTANCEDATA *IN_Instance);
	BOOL RegisterAPAssembly(INSTANCEDATA *IN_Instance);

	void ClearInstanceData();

public:
	SXFPart21FileC* GetFileHandle();
	SXFInstanceIDC*		 m_InstanceIDManager;
//	  SXFAssemblyManagerC* m_AssemblyManager;
//	  SXFAPModelManagerC*  m_APModelManager;
	SXFTableManagerC* m_TableManager;

	SXFReadAP202ManagerC* m_ReadAP202Manager;
	int m_FileSize;


protected:
	HEADSECTION  m_HeadSection;
	INSTANCEDATA m_InstanceData;
	SXFPart21FileC *m_File;
	SXFComInfoC* m_ComInfo;
};

#endif

