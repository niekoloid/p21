//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.h					  作成日：2000.04.07
//
//	１．クラス概要
//		エンティティデータを保持するオブジェクト
//		
//	２．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2000.04.07	   周
//
//------------------------------------------------------------

class SXFEntityDataC  
{
public:
	SXFEntityDataC();
	virtual ~SXFEntityDataC();

//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	BOOL SetEntityData(LPVOID& IO_DataInFilePtr,INSTANCEDATA *IN_Instance);
	// IO_DataInFilePtr が使用できる残りのバッファサイズを渡す
	size_t SetEntityData(LPVOID& IO_DataInFilePtr,size_t AvailableSize,INSTANCEDATA *IN_Instance);
	BOOL GetEntityData(CString& OUT_EntityData);
	BOOL GetEntityDataArray(CStringArray& OUT_EntityDataArray);

public:

	CString m_EntityName;
	int m_InstanceID;
	int m_InstanceMode;
	LPTSTR m_EntityDataPtr;
};
