/**
	All Rights Reserved,(c)JACIC 2001
	SXFutyConvKanjiC.h						作成日：2000.04.17

	１．クラス概要
		JISコード←→UNICODEの変換

	２．履歴
		履歴番号	日付		担当者			概要
		作成		2000.04.17	宮園(FQS)		なし。
		更新		2015.04.27	T.Matsushima	JPCERT/CC 指摘 脆弱性対応
**/

#if !defined(AFX_UTYCONVKANJI_H__26C0F4A1_D841_11D3_8D34_0000E2071B4B__INCLUDED_)
#define AFX_UTYCONVKANJI_H__26C0F4A1_D841_11D3_8D34_0000E2071B4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SXFutyConvKanjiC  
{
public:
	SXFutyConvKanjiC();
	virtual ~SXFutyConvKanjiC();
//	static int ConvKanji(char *Direction,char *InChar,char *OutChar);
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	static int ToJIS(char *InChar, char *OutChar) ;
//	static int FromJIS(char *InChar, char *OutChar) ;
	static int ToJIS(char *InChar, char *OutChar,size_t OutCharSize) ;		// バッファサイズを渡すように変更
	static int FromJIS(char *InChar, char *OutChar,size_t OutCharSize) ;	// バッファサイズを渡すように変更
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

private:
	static int AddTable(int KanjiTable[]);

};

#endif // !defined(AFX_UTYCONVKANJI_H__26C0F4A1_D841_11D3_8D34_0000E2071B4B__INCLUDED_)
