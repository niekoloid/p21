// SXFReadAP202MapManagerC.h: SXFReadAP202MapManagerC クラスのインターフェイス
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
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//class SXFFeatureC;
//	DEL(E)	チューニング対応	K.Naono	03.07.03

class SXFReadAP202MapManagerC  
{
public:
	void SetReturnFlag();
	LPVOID GetAssemblyStructData();
//	LPVOID GetStructData(char* OUT_TypeName);						JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	LPVOID GetStructData(char* OUT_TypeName,size_t TypeNameSize);	// バッファサイズを渡すように変更
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
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	SXFFeatureC* m_Feature;		/* ﾌｨｰﾁｬｵﾌﾞｼﾞｪｸﾄ */
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	SXFMapAssemblyC* m_MapAssembly;
	SXFMapGeometryC* m_MapGeometry;
	SXFInstanceIDC* m_InstanceIDManager;
	SXFTableManagerC* m_TableManager;
	SXFComInfoC *m_ComInfo;

	SXFReadAP202ManagerC* m_ReadManager;
	
};

#endif // !defined(AFX_SXFREADAP202MAPMANAGERC_H__59F06301_279E_11D4_A3A9_009027565E9B__INCLUDED_)
