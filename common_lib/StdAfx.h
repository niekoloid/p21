// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

// 下で指定された定義の前に対象プラットフォームを指定しなければならない場合、以下の定義を変更してください。
// 異なるプラットフォームに対応する値に関する最新情報については、MSDN を参照してください。
#ifndef WINVER				// Windows 98 以降のバージョンに固有の機能の使用を許可します。
#define WINVER 0x0410		// これを Windows の他のバージョン向けに適切な値に変更してください。
#endif

#ifndef _WIN32_WINNT		// Windows 2000 以降のバージョンに固有の機能の使用を許可します。                   
#define _WIN32_WINNT 0x0500	// これを Windows の他のバージョン向けに適切な値に変更してください。
#endif						

#ifndef _WIN32_WINDOWS		// Windows 98 以降のバージョンに固有の機能の使用を許可します。
#define _WIN32_WINDOWS 0x0410 // これを Windows Me またはそれ以降のバージョン向けに適切な値に変更してください。
#endif

#ifndef _WIN32_IE			// IE 5.01 以降のバージョンに固有の機能の使用を許可します。
#define _WIN32_IE 0x0501	// これを IE の他のバージョン向けに適切な値に変更してください。
#endif

#include <afx.h>
#include <afxtempl.h>
#include <math.h>
#include <iostream>

using namespace std;

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
