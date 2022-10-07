//
#define MAXLAYER			256				/*最大レイヤ数*/
#define MAXPRELINETYPE		16				/*最大既定義線種数*/
#define MAXPRECOLOUR		16				/*最大既定義色数*/
#define MAXLINEWIDTH		16				/*最大線幅数*/
#define MAXTEXTFONT			1024			/*最大文字フォント数*/

#define MAXUSERLINETYPE		16				/*最大ユーザ定義線種数*/
#define MAXUSERCOLOUR		240				/*最大ユーザ定義色数*/
#define MAXCOLOUR			256				/*最大色数*/
#define MAXLINETYPE			32				/*最大線種数*/

//最大ピッチ数
#define MAXPITCH			8				/*最大ピッチ数*/
//最大RGB値
#define MAXRGB				255				/*最大RGB値*/
//最大セグメント数
#define MAXSEGMENT			8
//最小セグメント数
#define MINSEGMENT			2

//double型の上限と下限
#define MINDOUBLE			-1000000000000000.0	/*double下限*/
#define MAXDOUBLE			1000000000000000.0	/*double上限*/

//	ADD(S)	障害修正	K.Naono	02.03.06
#define LMT_CHK_DOUBLE		5.0e-015			/**/
#define MIN_CHK_DOUBLE		4.0e-015			/*double下限*/
#define MAX_CHK_DOUBLE		999999999999999.5	/*double上限*/
//	ADD(E)	障害修正	K.Naono	02.03.06

//名前の最大名称長
#define MAXSHEETNAME		257				/*図面名の最大名称長*/
#define MAXLAYERNAME2		257				/*レイヤ名の最大名称長*/
#define MAXLINETYPENAME		257				/*線種名の最大名称長*/
#define MAXCOLOURNAME		257				/*色名の最大名称長*/
#define MAXTEXTFONTNAME		257				/*文字フォント名の最大名称長*/
#define MAXFIGURENAME		257				/*複合図形名の最大名称長*/
#define MAXSYMBOLNAME		257				/*既定義シンボル名の最大名称長*/
#define MAXHATCHNAME		257				/*ハッチング名の最大名称長*/
#define MAXPRESYMBOLNAME	257				/*既定義シンボル名（ハッチングパターンに使用）の最大名称長*/
#define MAXTEXT				257				/*最大文字数*/

//
#define MAXHATCHNUMBER		4				/*ハッチング線の最大パターン数*/

//角度の上限と下限
#define MAXANGLE			360.0
#define MINANGLE			0.0

//スラント角度の上限と下限
#define MAXSLANT			85.0
#define MINSLANT			-85.0

//文字列をUNICODEに変換後の最大文字数
#define MAXUNICODETEXT		20480

//ヘッダ情報(ファイル名など)をUNICODEに変換後の最大文字数
#define MAXUNICODENAME		1280
