/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h						作成日：2000.05.12

	１．クラス概要
		PRE_DEFINED_TERMINATOR_SYMBOLを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
	    作成		2000.05.12	藤本(FQS)	なし。
**/

/*

			ENTITY pre_defined_terminator_symbol
				SUBTYPE OF (pre_defined_symbol);
				WHERE
					wr1: SELF.name IN [
									   'blanked arrow',
									   'blanked box',
									   'blanked dot',
									   'dimension origin',
									   'filled arrow',
									   'filled box',
									   'filled dot',
									   'integral symbol',
									   'open arrow',
									   'slash',
									   'unfilled arrow'
									   ];
			END_ENTITY;
*/

#ifndef _SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC_CLASS_
#define _SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC_CLASS_

class SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC:public SXFMapEntityBaseC{
public :

//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( );
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger);

//-----------------------------------------------------------------------------
//	デストラクタ
//-----------------------------------------------------------------------------
	~SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( );

//-----------------------------------------------------------------------------
//	矢印コードをセットするメンバ関数
//-----------------------------------------------------------------------------
	int	SetParameter( );

public:

//-----------------------------------------------------------------------------
//	メンバ変数
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//	エンティティ名
//-----------------------------------------------------------------------------
	CString m_Name;

//-----------------------------------------------------------------------------
//	矢印コード
//-----------------------------------------------------------------------------
	int		m_code;

};
#endif
////////////////////////////
