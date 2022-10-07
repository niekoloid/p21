//////////////////////////////////////////////////////////////////////////
//																		//
//	このプログラムは、													//
//	ＳＸＦ仕様Ｖ３．１対応レベル２フィーチャコメント共通ライブラリを	//
//	利用するためのサンプルプログラムです。								//
//																		//
//	※Ｒｅａｄ時は、指定したファイルを読み込み、ファイル名dump.datを	//
//	作成します。														//
//																		//
//	※Ｗｒｉｔｅ時は、本サンプルプログラム内で定義した値を指定した		//
//	ファイルに出力します。												//
//																		//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <stdio.h>
/* ライブラリ関数定義用.hファイル */
#include "SXFAPIFuncExtAP202.h"
/* フィーチャ構造体用.hファイル */
#include "SXFStruct.h"

using namespace std;		// 2010.8

void main(){
	char *name="";
	int msgno=0;
	char* text="";

	int rw_flg;
	int mode;
	double tolerance1,tolerance2;
	double divide;
	int level;
	int FeatureEndFlag;
	int error_code;
	char FeatureName[64];

	/** 読み書きフラグ取得 **/
	printf("read or write (0 or 1) ==>");
	scanf("%d",&rw_flg);
	/** 許容誤差取得(長さ用) **/
	printf("tolerance? ==>");
	scanf("%lf",&tolerance1);
	/** 許容誤差(角度用)取得 **/
	printf("angular tolerance? ==>");
	scanf("%lf",&tolerance2);
	/** 許容誤差(分割用)設定 **/
	/* 0.0で固定 */
	divide = 0.0;
	/** レベル設定 **/
	/* レベル２で固定。それ以外は受け付けない */
	level = 2;

	/** 読み書きフラグにより、Read/Write処理を行う **/

	/***********************************************************/
	/**************************** READ *************************/
	/***********************************************************/
	/** 読み書きフラグが0の場合、Read処理 **/
	if (rw_flg == 0){
		/* テスト用dump_file */
		ofstream *dump_file;
		int ret;
		int EndFlag;
		void* Struct = NULL;
		Layer_Struct las;
		Predefined_Colour_Struct pcs;
		Userdefined_Colour_Struct ucs;
		Predefined_Linetype_Struct pls;
		Userdefined_Linetype_Struct uls;
		Line_Width_Struct lws;
		Text_Font_Struct tfs;
		char in_file_name[257];
		char author[257];
		char org[257];
		char translator_name[257];
		char version[257];
		char file_version[257];
		/** 入力ファイル名の取得 **/
		printf("input file_name==>");
		scanf("%s",in_file_name);
		/** 読み込みモードの設定 **/
		/* モードは2で固定。それ以外は受け付けない */
		mode = 2;
		
		DWORD timeCount = 0;		// 2010.8
		timeCount = GetTickCount();	// 2010.8

		/**********************************/
		/****** STEPファイルオープン ******/
		/**********************************/
		if (SXFopen_AP202(
			in_file_name,	//ファイル名
			rw_flg,			//read/writeフラグ
			tolerance1,		//長さ用許容誤差
			tolerance2,		//角度用許容誤差
			divide,			//スプライン分解用許容誤差
			level,			//レベル指定		(入力）
			mode,			//変換モード		(入力)
			author,			//ファイル作成者		(write入力／read出力）
			org,			//ファイル作成者所属	(write入力／read出力）
			translator_name,//トランスレータ名		(write入力／read出力）
			version			//共通ライブラリバージョン（read時のみ出力）
		) < 0){
			//エラー問い合わせ
			SXFPopMsg_AP202(name,&msgno,text);
			cout << name << " : " << msgno << " : " << text << endl << endl;
			msgno = 0;
			name = "";
			text = "";
			return ;
		}
		if (SXFget_file_version_AP202(file_version) < 0)
		{
			return ;
		}
		/** ファイル作成者 **/
		cout << "anthor = " << author << endl;
		/** 作成者所属 **/
		cout << "org = " << org << endl;
		/** トランスレータ名 **/
		cout << "translator_name = " << translator_name << endl;
		/** 共通ライブラリバージョン **/
		cout << "version = " << version << endl;
		/** ファイルバージョン **/
		cout << "file_version = " << file_version << endl;
		/**** dump file open ****/
		dump_file = new ofstream("dump.dat");

		/**************************************/
		/****** 定義テーブル情報読み込み ******/
		/**************************************/
		/****** レイヤコード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_layer =SXFread_table_AP202(1,&las,&EndFlag);
			if (ret_layer > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------" << ret_layer << "-----------------" << endl;
				*dump_file << "name = " << las.name << endl;
				*dump_file << "lflag = " << las.lflag << endl;
				strcpy(las.name,"");
				las.lflag = -1;
			}
		}
		/****** 既定義色コード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_precolor = SXFread_table_AP202(2,&pcs,&EndFlag);
			if (ret_precolor > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------" << ret_precolor << "-----------------" << endl;
				*dump_file << "name = " << pcs.name << endl;
				strcpy(pcs.name,"");
			}
		}
		/****** ユーザ定義色コード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_usercolor = SXFread_table_AP202(3,&ucs,&EndFlag);
			if (ret_usercolor > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------" << ret_usercolor << "-----------------" << endl;
				*dump_file << "red = " << ucs.red << endl;
				*dump_file << "greed = " << ucs.green << endl;
				*dump_file << "blue = " << ucs.blue << endl;
				ucs.red = 0;
				ucs.green = 0;
				ucs.blue = 0;
			}
		}
		/****** 既定義線種コード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_pretype = SXFread_table_AP202(4,&pls,&EndFlag);
			if (ret_pretype > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------" << ret_pretype << "-----------------" << endl;
				*dump_file << "name = " << pls.name << endl;
				strcpy(pls.name,"");
			}
		}
		/****** ユーザ定義線種コード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_usertype = SXFread_table_AP202(5,&uls,&EndFlag);
			if (ret_usertype > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------" << ret_usertype << "-----------------" << endl;
				*dump_file << "name = " << uls.name << endl;
				*dump_file << "segment = " << uls.segment << endl;
				for (int i = 0; i < uls.segment; i++)
					*dump_file << "pitch[" << i << "] = " << uls.pitch[i] << endl;
				int pretype_code=0;
				strcpy(uls.name,"");
				uls.segment = 0;
			}
		}
		/****** 線幅コード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_width = SXFread_table_AP202(6,&lws,&EndFlag);
			if (ret_width > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------" << ret_width << "-----------------" << endl;
				*dump_file << "width = " << lws.width << endl;
				lws.width = 0.0;
			}
		}
		/****** 文字フォントコード読み込み ******/
		EndFlag = 0;
		while(!EndFlag){
			int ret_font = SXFread_table_AP202(7,&tfs,&EndFlag);
			if (ret_font > 0){
				/****** ここに要素の処理を記載 ******/
				*dump_file << "-----------text_font-----------------" << endl;
				*dump_file << "-----------" << ret_font << "-----------------" << endl;
				*dump_file << "name = " << tfs.name << endl;
				strcpy(tfs.name,""); 
			}
		}
		/**********************************************/
		/****** アセンブリ要素(複合曲線)読み込み ******/
		/**********************************************/
		EndFlag = 0;
		while(!EndFlag){
			ret = SXFread_assembly_name_AP202(CCURVE_ORG,Struct,&EndFlag);
			if (ret < 0){
				continue;
			}
			else{
				/****** ここに要素の処理を記載 ******/
				*dump_file << "--------------composite_curve_org-----------------" << endl;
				*dump_file << "-----------------" << ret << "-----------------------" << endl;
				*dump_file << "color = " << ((Ccurve_Org_Struct*)Struct)->color << endl;
				*dump_file << "type = " << ((Ccurve_Org_Struct*)Struct)->type << endl;
				*dump_file << "line_width = " << ((Ccurve_Org_Struct*)Struct)->line_width << endl;
				*dump_file << "flag = " << ((Ccurve_Org_Struct*)Struct)->flag << endl;
				/** アセンブリ要素フィーチャ構造体の削除 **/
				SXFdelete_assembly_AP202(CCURVE_ORG,Struct);
			}
			/**************************************/
			/****** 複合曲線上の要素を読込む ******/
			/**************************************/
			FeatureEndFlag=0;
			while(!FeatureEndFlag){
				/** 終了フラグが立つまで要素を読込む **/
				error_code = SXFread_next_feature_AP202(FeatureName,Struct,&FeatureEndFlag);
				if (error_code  > 0){
					if (!strcmp(FeatureName, "ARC")){//円弧読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ARC-----------------------" << endl;
						*dump_file << "layer = " << ((Arc_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Arc_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Arc_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Arc_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Arc_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Arc_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Arc_Struct*)Struct)->radius << endl;
						*dump_file << "direction = " << ((Arc_Struct*)Struct)->direction << endl;
						*dump_file << "start_angle = " << ((Arc_Struct*)Struct)->start_angle << endl;
						*dump_file << "end_angle = " << ((Arc_Struct*)Struct)->end_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ELLIPSE_ARC")){//楕円弧読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ELLIPSE_ARC-----------------------" << endl;
						*dump_file << "layer = " << ((Ellipse_Arc_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Ellipse_Arc_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Ellipse_Arc_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Ellipse_Arc_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Ellipse_Arc_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Ellipse_Arc_Struct*)Struct)->center_y << endl;
						*dump_file << "radius_x = " << ((Ellipse_Arc_Struct*)Struct)->radius_x << endl;
						*dump_file << "radius_y = " << ((Ellipse_Arc_Struct*)Struct)->radius_y << endl;
						*dump_file << "direction = " << ((Ellipse_Arc_Struct*)Struct)->direction << endl;
						*dump_file << "rotation_angle = " << ((Ellipse_Arc_Struct*)Struct)->rotation_angle << endl;
						*dump_file << "start_angle = " << ((Ellipse_Arc_Struct*)Struct)->start_angle << endl;
						*dump_file << "end_angle = " << ((Ellipse_Arc_Struct*)Struct)->end_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "POLYLINE")){//折線読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------POLYLINE-----------------------" << endl;
						*dump_file << "layer = " << ((Polyline_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Polyline_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Polyline_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Polyline_Struct*)Struct)->line_width << endl;
						*dump_file << "number = " << ((Polyline_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Polyline_Struct*)Struct)->number; i++){
							*dump_file << "x[" << i << "] = " << ((Polyline_Struct*)Struct)->x[i] << endl;
							*dump_file << "y[" << i << "] = " << ((Polyline_Struct*)Struct)->y[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "SPLINE")){//スプライン読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------SPLINE-----------------------" << endl;
						*dump_file << "layer = " << ((Spline_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Spline_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Spline_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Spline_Struct*)Struct)->line_width << endl;
						*dump_file << "open_close = " << ((Spline_Struct*)Struct)->open_close << endl;
						*dump_file << "number = " << ((Spline_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Spline_Struct*)Struct)->number; i++){
							*dump_file << "x[" << i << "] = " << ((Spline_Struct*)Struct)->x[i] << endl;
							*dump_file << "y[" << i << "] = " << ((Spline_Struct*)Struct)->y[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CLOTHOID")){//クロソイド読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CLOTHOID-----------------------" << endl;
						*dump_file << "layer = " << ((Clothoid_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Clothoid_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Clothoid_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Clothoid_Struct*)Struct)->line_width << endl;
						*dump_file << "base_x = " << ((Clothoid_Struct*)Struct)->base_x << endl;
						*dump_file << "base_y = " << ((Clothoid_Struct*)Struct)->base_y << endl;
						*dump_file << "parameter = " << ((Clothoid_Struct*)Struct)->parameter << endl;
						*dump_file << "direction = " << ((Clothoid_Struct*)Struct)->direction << endl;
						*dump_file << "angle = " << ((Clothoid_Struct*)Struct)->angle << endl;
						*dump_file << "start_length = " << ((Clothoid_Struct*)Struct)->start_length << endl;
						*dump_file << "end_length = " << ((Clothoid_Struct*)Struct)->end_length << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
				}
			}			
		}
		/************************************************/
		/****** アセンブリ要素(複合図形)の読み込み ******/
		/************************************************/
		EndFlag = 0;
		while(!EndFlag){
			ret = SXFread_assembly_name_AP202(SFIG_ORG,Struct,&EndFlag);//複合図形
			if (ret < 0){
				continue;
			}
			else{
				/****** ここに要素の処理を記載 ******/
				*dump_file << "--------------subfigure_org-----------------" << endl;
				*dump_file << "-----------------" << ret << "-----------------------" << endl;
				*dump_file << "name = " << ((Sfigorg_Struct*)Struct)->name << endl;
				*dump_file << "flag = " << ((Sfigorg_Struct*)Struct)->flag << endl;
				/** アセンブリ要素フィーチャ構造体の削除 **/
				SXFdelete_assembly_AP202(SFIG_ORG,Struct);
			}
			/****************************************/
			/****** 複合図形上の要素の読み込み ******/
			/****************************************/
			FeatureEndFlag=0;			
			while(!FeatureEndFlag){
				/** 終了フラグが立つまで要素を読込む **/
				error_code = SXFread_next_feature_AP202(FeatureName,Struct,&FeatureEndFlag);
				if (error_code > 0){
					if(!strcmp(FeatureName,"LINE")){// 線分の読み込み
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------LINE-----------------------" << endl;
						*dump_file << "layer = " << ((Line_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Line_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Line_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Line_Struct*)Struct)->line_width << endl;
						*dump_file << "start_x = " << ((Line_Struct*)Struct)->start_x << endl;
						*dump_file << "start_y = " << ((Line_Struct*)Struct)->start_y << endl;
						*dump_file << "end_x = " << ((Line_Struct*)Struct)->end_x << endl;
						*dump_file << "end_y = " << ((Line_Struct*)Struct)->end_y << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CIRCLE")){//円読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CIRCLE-----------------------" << endl;
						*dump_file << "layer = " << ((Circle_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Circle_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Circle_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Circle_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Circle_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Circle_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Circle_Struct*)Struct)->radius << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ARC")){//円弧読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ARC-----------------------" << endl;
						*dump_file << "layer = " << ((Arc_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Arc_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Arc_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Arc_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Arc_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Arc_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Arc_Struct*)Struct)->radius << endl;
						*dump_file << "direction = " << ((Arc_Struct*)Struct)->direction << endl;
						*dump_file << "start_angle = " << ((Arc_Struct*)Struct)->start_angle << endl;
						*dump_file << "end_angle = " << ((Arc_Struct*)Struct)->end_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ELLIPSE")){//楕円読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ELLIPSE-----------------------" << endl;
						*dump_file << "layer = " << ((Ellipse_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Ellipse_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Ellipse_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Ellipse_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Ellipse_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Ellipse_Struct*)Struct)->center_y << endl;
						*dump_file << "radius_x = " << ((Ellipse_Struct*)Struct)->radius_x << endl;
						*dump_file << "radius_y = " << ((Ellipse_Struct*)Struct)->radius_y << endl;
						*dump_file << "rotation_angle = " << ((Ellipse_Struct*)Struct)->rotation_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ELLIPSE_ARC")){//楕円弧読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ELLIPSE_ARC-----------------------" << endl;
						*dump_file << "layer = " << ((Ellipse_Arc_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Ellipse_Arc_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Ellipse_Arc_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Ellipse_Arc_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Ellipse_Arc_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Ellipse_Arc_Struct*)Struct)->center_y << endl;
						*dump_file << "radius_x = " << ((Ellipse_Arc_Struct*)Struct)->radius_x << endl;
						*dump_file << "radius_y = " << ((Ellipse_Arc_Struct*)Struct)->radius_y << endl;
						*dump_file << "direction = " << ((Ellipse_Arc_Struct*)Struct)->direction << endl;
						*dump_file << "rotation_angle = " << ((Ellipse_Arc_Struct*)Struct)->rotation_angle << endl;
						*dump_file << "start_angle = " << ((Ellipse_Arc_Struct*)Struct)->start_angle << endl;
						*dump_file << "end_angle = " << ((Ellipse_Arc_Struct*)Struct)->end_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "POLYLINE")){//折線読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------POLYLINE-----------------------" << endl;
						*dump_file << "layer = " << ((Polyline_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Polyline_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Polyline_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Polyline_Struct*)Struct)->line_width << endl;
						*dump_file << "number = " << ((Polyline_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Polyline_Struct*)Struct)->number; i++){
							*dump_file << "x[" << i << "] = " << ((Polyline_Struct*)Struct)->x[i] << endl;
							*dump_file << "y[" << i << "] = " << ((Polyline_Struct*)Struct)->y[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "TEXT")){//文字要素読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------TEXT-----------------------" << endl;
						*dump_file << "layer = " << ((Text_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Text_Struct*)Struct)->color << endl;
						*dump_file << "font = " << ((Text_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((Text_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((Text_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((Text_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((Text_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((Text_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((Text_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((Text_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((Text_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((Text_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((Text_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "POINT_MARKER")){//点マーカ読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------POINT_MARKER-----------------------" << endl;
						*dump_file << "layer = " << ((Point_Marker_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Point_Marker_Struct*)Struct)->color << endl;
						*dump_file << "start_x = " << ((Point_Marker_Struct*)Struct)->start_x << endl;
						*dump_file << "start_y = " << ((Point_Marker_Struct*)Struct)->start_y << endl;
						*dump_file << "marker_code = " << ((Point_Marker_Struct*)Struct)->marker_code << endl;
						*dump_file << "rotate_angle = " << ((Point_Marker_Struct*)Struct)->rotate_angle << endl;
						*dump_file << "scale = " << ((Point_Marker_Struct*)Struct)->scale << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "SPLINE")){//スプライン読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------SPLINE-----------------------" << endl;
						*dump_file << "layer = " << ((Spline_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Spline_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Spline_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Spline_Struct*)Struct)->line_width << endl;
						*dump_file << "open_close = " << ((Spline_Struct*)Struct)->open_close << endl;
						*dump_file << "number = " << ((Spline_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Spline_Struct*)Struct)->number; i++){
							*dump_file << "x[" << i << "] = " << ((Spline_Struct*)Struct)->x[i] << endl;
							*dump_file << "y[" << i << "] = " << ((Spline_Struct*)Struct)->y[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CLOTHOID")){//クロソイド読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CLOTHOID-----------------------" << endl;
						*dump_file << "layer = " << ((Clothoid_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Clothoid_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Clothoid_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Clothoid_Struct*)Struct)->line_width << endl;
						*dump_file << "base_x = " << ((Clothoid_Struct*)Struct)->base_x << endl;
						*dump_file << "base_y = " << ((Clothoid_Struct*)Struct)->base_y << endl;
						*dump_file << "parameter = " << ((Clothoid_Struct*)Struct)->parameter << endl;
						*dump_file << "direction = " << ((Clothoid_Struct*)Struct)->direction << endl;
						*dump_file << "angle = " << ((Clothoid_Struct*)Struct)->angle << endl;
						*dump_file << "start_length = " << ((Clothoid_Struct*)Struct)->start_length << endl;
						*dump_file << "end_length = " << ((Clothoid_Struct*)Struct)->end_length << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "EXTERNALLY_DEFINED_SYMBOL")){//既定義シンボル読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------EXTERNALLY_DEFINED_SYMBOL-----------------------" << endl;
						*dump_file << "layer = " << ((Externally_Defined_Symbol_Struct*)Struct)->layer << endl;
						*dump_file << "color_flag = " << ((Externally_Defined_Symbol_Struct*)Struct)->color_flag << endl;
						*dump_file << "color = " << ((Externally_Defined_Symbol_Struct*)Struct)->color << endl;
						*dump_file << "name = " << ((Externally_Defined_Symbol_Struct*)Struct)->name << endl;
						*dump_file << "start_x = " << ((Externally_Defined_Symbol_Struct*)Struct)->start_x << endl;
						*dump_file << "start_y = " << ((Externally_Defined_Symbol_Struct*)Struct)->start_y << endl;
						*dump_file << "rotate_angle = " << ((Externally_Defined_Symbol_Struct*)Struct)->rotate_angle << endl;
						*dump_file << "scale = " << ((Externally_Defined_Symbol_Struct*)Struct)->scale << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "LINEAR_DIMENSION")){//直線寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------LINEAR_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((LinearDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((LinearDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((LinearDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((LinearDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x1 = " << ((LinearDim_Struct*)Struct)->sun_x1 << endl;
						*dump_file << "sun_y1 = " << ((LinearDim_Struct*)Struct)->sun_y1 << endl;
						*dump_file << "sun_x2 = " << ((LinearDim_Struct*)Struct)->sun_x2 << endl;
						*dump_file << "sun_y2 = " << ((LinearDim_Struct*)Struct)->sun_y2 << endl;
						*dump_file << "flg2 = " << ((LinearDim_Struct*)Struct)->flg2 << endl;
						*dump_file << "ho1_x0 = " << ((LinearDim_Struct*)Struct)->ho1_x0 << endl;
						*dump_file << "ho1_y0 = " << ((LinearDim_Struct*)Struct)->ho1_y0 << endl;
						*dump_file << "ho1_x1 = " << ((LinearDim_Struct*)Struct)->ho1_x1 << endl;
						*dump_file << "ho1_y1 = " << ((LinearDim_Struct*)Struct)->ho1_y1 << endl;
						*dump_file << "ho1_x2 = " << ((LinearDim_Struct*)Struct)->ho1_x2 << endl;
						*dump_file << "ho1_y2 = " << ((LinearDim_Struct*)Struct)->ho1_y2 << endl;
						*dump_file << "flg3 = " << ((LinearDim_Struct*)Struct)->flg3 << endl;
						*dump_file << "ho2_x0 = " << ((LinearDim_Struct*)Struct)->ho2_x0 << endl;
						*dump_file << "ho2_y0 = " << ((LinearDim_Struct*)Struct)->ho2_y0 << endl;
						*dump_file << "ho2_x1 = " << ((LinearDim_Struct*)Struct)->ho2_x1 << endl;
						*dump_file << "ho2_y1 = " << ((LinearDim_Struct*)Struct)->ho2_y1 << endl;
						*dump_file << "ho2_x2 = " << ((LinearDim_Struct*)Struct)->ho2_x2 << endl;
						*dump_file << "ho2_y2 = " << ((LinearDim_Struct*)Struct)->ho2_y2 << endl;
						*dump_file << "arr1_code1 = " << ((LinearDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((LinearDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((LinearDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((LinearDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((LinearDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((LinearDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((LinearDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((LinearDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((LinearDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((LinearDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg4 = " << ((LinearDim_Struct*)Struct)->flg4 << endl;
						*dump_file << "font = " << ((LinearDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((LinearDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((LinearDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((LinearDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((LinearDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((LinearDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((LinearDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((LinearDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((LinearDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((LinearDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((LinearDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CURVE_DIMENSION")){//弧長寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CURVE_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((CurveDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((CurveDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((CurveDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((CurveDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x = " << ((CurveDim_Struct*)Struct)->sun_x << endl;
						*dump_file << "sun_y = " << ((CurveDim_Struct*)Struct)->sun_y << endl;
						*dump_file << "sun_radius = " << ((CurveDim_Struct*)Struct)->sun_radius << endl;
						*dump_file << "sun_angle0 = " << ((CurveDim_Struct*)Struct)->sun_angle0 << endl;
						*dump_file << "sun_angle1 = " << ((CurveDim_Struct*)Struct)->sun_angle1 << endl;
						*dump_file << "flg2 = " << ((CurveDim_Struct*)Struct)->flg2 << endl;
						*dump_file << "ho1_x0 = " << ((CurveDim_Struct*)Struct)->ho1_x0 << endl;
						*dump_file << "ho1_y0 = " << ((CurveDim_Struct*)Struct)->ho1_y0 << endl;
						*dump_file << "ho1_x1 = " << ((CurveDim_Struct*)Struct)->ho1_x1 << endl;
						*dump_file << "ho1_y1 = " << ((CurveDim_Struct*)Struct)->ho1_y1 << endl;
						*dump_file << "ho1_x2 = " << ((CurveDim_Struct*)Struct)->ho1_x2 << endl;
						*dump_file << "ho1_y2 = " << ((CurveDim_Struct*)Struct)->ho1_y2 << endl;
						*dump_file << "flg3 = " << ((CurveDim_Struct*)Struct)->flg3 << endl;
						*dump_file << "ho2_x0 = " << ((CurveDim_Struct*)Struct)->ho2_x0 << endl;
						*dump_file << "ho2_y0 = " << ((CurveDim_Struct*)Struct)->ho2_y0 << endl;
						*dump_file << "ho2_x1 = " << ((CurveDim_Struct*)Struct)->ho2_x1 << endl;
						*dump_file << "ho2_y1 = " << ((CurveDim_Struct*)Struct)->ho2_y1 << endl;
						*dump_file << "ho2_x2 = " << ((CurveDim_Struct*)Struct)->ho2_x2 << endl;
						*dump_file << "ho2_y2 = " << ((CurveDim_Struct*)Struct)->ho2_y2 << endl;
						*dump_file << "arr1_code1 = " << ((CurveDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((CurveDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((CurveDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((CurveDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((CurveDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((CurveDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((CurveDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((CurveDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((CurveDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((CurveDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg4 = " << ((CurveDim_Struct*)Struct)->flg4 << endl;
						*dump_file << "font = " << ((CurveDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((CurveDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((CurveDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((CurveDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((CurveDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((CurveDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((CurveDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((CurveDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((CurveDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((CurveDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((CurveDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ANGULAR_DIMENSION")){//角度寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ANGULAR_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((AngularDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((AngularDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((AngularDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((AngularDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x = " << ((AngularDim_Struct*)Struct)->sun_x << endl;
						*dump_file << "sun_y = " << ((AngularDim_Struct*)Struct)->sun_y << endl;
						*dump_file << "sun_radius = " << ((AngularDim_Struct*)Struct)->sun_radius << endl;
						*dump_file << "sun_angle0 = " << ((AngularDim_Struct*)Struct)->sun_angle0 << endl;
						*dump_file << "sun_angle1 = " << ((AngularDim_Struct*)Struct)->sun_angle1 << endl;
						*dump_file << "flg2 = " << ((AngularDim_Struct*)Struct)->flg2 << endl;
						*dump_file << "ho1_x0 = " << ((AngularDim_Struct*)Struct)->ho1_x0 << endl;
						*dump_file << "ho1_y0 = " << ((AngularDim_Struct*)Struct)->ho1_y0 << endl;
						*dump_file << "ho1_x1 = " << ((AngularDim_Struct*)Struct)->ho1_x1 << endl;
						*dump_file << "ho1_y1 = " << ((AngularDim_Struct*)Struct)->ho1_y1 << endl;
						*dump_file << "ho1_x2 = " << ((AngularDim_Struct*)Struct)->ho1_x2 << endl;
						*dump_file << "ho1_y2 = " << ((AngularDim_Struct*)Struct)->ho1_y2 << endl;
						*dump_file << "flg3 = " << ((AngularDim_Struct*)Struct)->flg3 << endl;
						*dump_file << "ho2_x0 = " << ((AngularDim_Struct*)Struct)->ho2_x0 << endl;
						*dump_file << "ho2_y0 = " << ((AngularDim_Struct*)Struct)->ho2_y0 << endl;
						*dump_file << "ho2_x1 = " << ((AngularDim_Struct*)Struct)->ho2_x1 << endl;
						*dump_file << "ho2_y1 = " << ((AngularDim_Struct*)Struct)->ho2_y1 << endl;
						*dump_file << "ho2_x2 = " << ((AngularDim_Struct*)Struct)->ho2_x2 << endl;
						*dump_file << "ho2_y2 = " << ((AngularDim_Struct*)Struct)->ho2_y2 << endl;
						*dump_file << "arr1_code1 = " << ((AngularDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((AngularDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((AngularDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((AngularDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((AngularDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((AngularDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((AngularDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((AngularDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((AngularDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((AngularDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg4 = " << ((AngularDim_Struct*)Struct)->flg4 << endl;
						*dump_file << "font = " << ((AngularDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((AngularDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((AngularDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((AngularDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((AngularDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((AngularDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((AngularDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((AngularDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((AngularDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((AngularDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((AngularDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "RADIUS_DIMENSION")){//半径寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------RADIUS_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((RadiusDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((RadiusDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((RadiusDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((RadiusDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x1 = " << ((RadiusDim_Struct*)Struct)->sun_x1 << endl;
						*dump_file << "sun_y1 = " << ((RadiusDim_Struct*)Struct)->sun_y1 << endl;
						*dump_file << "sun_x2 = " << ((RadiusDim_Struct*)Struct)->sun_x2 << endl;
						*dump_file << "sun_y2 = " << ((RadiusDim_Struct*)Struct)->sun_y2 << endl;
						*dump_file << "arr_code1 = " << ((RadiusDim_Struct*)Struct)->arr_code1 << endl;
						*dump_file << "arr_code2 = " << ((RadiusDim_Struct*)Struct)->arr_code2 << endl;
						*dump_file << "arr_x = " << ((RadiusDim_Struct*)Struct)->arr_x << endl;
						*dump_file << "arr_y = " << ((RadiusDim_Struct*)Struct)->arr_y << endl;
						*dump_file << "arr_r = " << ((RadiusDim_Struct*)Struct)->arr_r << endl;
						*dump_file << "flg = " << ((RadiusDim_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((RadiusDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((RadiusDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((RadiusDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((RadiusDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((RadiusDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((RadiusDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((RadiusDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((RadiusDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((RadiusDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((RadiusDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((RadiusDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "DIAMETER_DIMENSION")){//直径寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------DIAMETER_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((DiameterDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((DiameterDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((DiameterDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((DiameterDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x1 = " << ((DiameterDim_Struct*)Struct)->sun_x1 << endl;
						*dump_file << "sun_y1 = " << ((DiameterDim_Struct*)Struct)->sun_y1 << endl;
						*dump_file << "sun_x2 = " << ((DiameterDim_Struct*)Struct)->sun_x2 << endl;
						*dump_file << "sun_y2 = " << ((DiameterDim_Struct*)Struct)->sun_y2 << endl;
						*dump_file << "arr1_code1 = " << ((DiameterDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((DiameterDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((DiameterDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((DiameterDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((DiameterDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((DiameterDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((DiameterDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((DiameterDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((DiameterDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((DiameterDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg = " << ((DiameterDim_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((DiameterDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((DiameterDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((DiameterDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((DiameterDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((DiameterDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((DiameterDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((DiameterDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((DiameterDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((DiameterDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((DiameterDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((DiameterDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "LABEL")){//ラベル読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------LABEL-----------------------" << endl;
						*dump_file << "layer = " << ((Label_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Label_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Label_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Label_Struct*)Struct)->line_width << endl;
						*dump_file << "vertex_number = " << ((Label_Struct*)Struct)->vertex_number << endl;
						for (int i = 0; i < ((Label_Struct*)Struct)->vertex_number; i++){
							*dump_file << "vertex_x[" << i << "] = " << ((Label_Struct*)Struct)->vertex_x[i] << endl;
							*dump_file << "vertex_y[" << i << "] = " << ((Label_Struct*)Struct)->vertex_y[i] << endl;
						}
						*dump_file << "arr_code = " << ((Label_Struct*)Struct)->arr_code << endl;
						*dump_file << "arr_r = " << ((Label_Struct*)Struct)->arr_r << endl;
						*dump_file << "flg = " << ((Label_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((Label_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((Label_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((Label_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((Label_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((Label_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((Label_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((Label_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((Label_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((Label_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((Label_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((Label_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "BALLOON")){//バルーン読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------BALLOON-----------------------" << endl;
						*dump_file << "layer = " << ((Balloon_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Balloon_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Balloon_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Balloon_Struct*)Struct)->line_width << endl;
						*dump_file << "vertex_number = " << ((Balloon_Struct*)Struct)->vertex_number << endl;
						for (int i = 0; i < ((Balloon_Struct*)Struct)->vertex_number; i++){
							*dump_file << "vertex_x[" << i << "] = " << ((Balloon_Struct*)Struct)->vertex_x[i] << endl;
							*dump_file << "vertex_y[" << i << "] = " << ((Balloon_Struct*)Struct)->vertex_y[i] << endl;
						}
						*dump_file << "center_x = " << ((Balloon_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Balloon_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Balloon_Struct*)Struct)->radius << endl;
						*dump_file << "arr_code = " << ((Balloon_Struct*)Struct)->arr_code << endl;
						*dump_file << "arr_r = " << ((Balloon_Struct*)Struct)->arr_r << endl;
						*dump_file << "flg = " << ((Balloon_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((Balloon_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((Balloon_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((Balloon_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((Balloon_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((Balloon_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((Balloon_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((Balloon_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((Balloon_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((Balloon_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((Balloon_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((Balloon_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "FILL_AREA_STYLE_HATCHING")){//ユーザ定義ハッチング読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------FILL_AREA_STYLE_HATCHING-----------------------" << endl;
						*dump_file << "layer = " << ((Fill_area_style_hatching_Struct*)Struct)->layer << endl;
						*dump_file << "hatch_number = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_number << endl;
						for (int i = 0; i < ((Fill_area_style_hatching_Struct*)Struct)->hatch_number; i++){
							*dump_file << "hatch_color[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_color[i] << endl;
							*dump_file << "hatch_type[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_type[i] << endl;
							*dump_file << "hatch_line_width[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_line_width[i] << endl;
							*dump_file << "hatch_start_x[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_start_x[i] << endl;
							*dump_file << "hatch_start_y[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_start_y[i] << endl;
							*dump_file << "hatch_spacing[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_spacing[i] << endl;
							*dump_file << "hatch_angle[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_angle[i] << endl;
						}
						*dump_file << "out_id = " << ((Fill_area_style_hatching_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Fill_area_style_hatching_Struct*)Struct)->number << endl;
						for (i = 0; i < ((Fill_area_style_hatching_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "EXTERNALLY_DEFINED_HATCH")){//ハッチング（外部定義）読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------EXTERNALLY_DEFINED_HATCH-----------------------" << endl;
						*dump_file << "layer = " << ((Externally_Defined_Hatch_Struct*)Struct)->layer << endl;
						*dump_file << "name = " << ((Externally_Defined_Hatch_Struct*)Struct)->name << endl;
						*dump_file << "out_id = " << ((Externally_Defined_Hatch_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Externally_Defined_Hatch_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Externally_Defined_Hatch_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Externally_Defined_Hatch_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "FILL_AREA_STYLE_COLOUR")){//ハッチング(塗り）読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------FILL_AREA_STYLE_COLOUR-----------------------" << endl;
						*dump_file << "layer = " << ((Fill_area_style_colour_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Fill_area_style_colour_Struct*)Struct)->color << endl;
						*dump_file << "out_id = " << ((Fill_area_style_colour_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Fill_area_style_colour_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Fill_area_style_colour_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Fill_area_style_colour_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "FILL_AREA_STYLE_TILES")){//ハッチング(パターン）読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------FILL_AREA_STYLE_TILES-----------------------" << endl;
						*dump_file << "layer = " << ((Fill_area_style_tiles_Struct*)Struct)->layer << endl;
						*dump_file << "name = " << ((Fill_area_style_tiles_Struct*)Struct)->name << endl;
						*dump_file << "hatch_color = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_color << endl;
						*dump_file << "hatch_pattern_x = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_x << endl;
						*dump_file << "hatch_pattern_y = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_y << endl;
						*dump_file << "hatch_pttern_vector1 = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector1 << endl;
						*dump_file << "hatch_pattern_vector1_angle = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector1_angle << endl;
						*dump_file << "hatch_pttern_vector2 = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector2 << endl;
						*dump_file << "hatch_pattern_vector2_angle = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector2_angle << endl;
						*dump_file << "hatch_pattern_scale_x = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_scale_x << endl;
						*dump_file << "hatch_pattern_scale_y = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_scale_y << endl;
						*dump_file << "hatch_pattern_angle = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_angle << endl;
						*dump_file << "out_id = " << ((Fill_area_style_tiles_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Fill_area_style_tiles_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Fill_area_style_tiles_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Fill_area_style_tiles_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "SFIG_LOCATE")){//複合図形配置読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------SFIG_LOCATE-----------------------" << endl;
						*dump_file << "layer = " << ((Sfigloc_Struct*)Struct)->layer << endl;
						*dump_file << "name = " << ((Sfigloc_Struct*)Struct)->name << endl;
						*dump_file << "x = " << ((Sfigloc_Struct*)Struct)->x << endl;
						*dump_file << "y = " << ((Sfigloc_Struct*)Struct)->y << endl;
						*dump_file << "angle = " << ((Sfigloc_Struct*)Struct)->angle << endl;
						*dump_file << "ratio_x = " << ((Sfigloc_Struct*)Struct)->ratio_x << endl;
						*dump_file << "ratio_y = " << ((Sfigloc_Struct*)Struct)->ratio_y << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ATTRIBUTE")){//図面表題欄読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ATTRIBUTE-----------------------"	<< endl;
						*dump_file << "p_name = "	<< ((Attribute_Struct*)Struct)->p_name		<< endl;
						*dump_file << "c_name = "	<< ((Attribute_Struct*)Struct)->c_name		<< endl;
						*dump_file << "c_type = "	<< ((Attribute_Struct*)Struct)->c_type		<< endl;
						*dump_file << "d_title = "	<< ((Attribute_Struct*)Struct)->d_title		<< endl;
						*dump_file << "d_number = "	<< ((Attribute_Struct*)Struct)->d_number	<< endl;
						*dump_file << "d_type = "	<< ((Attribute_Struct*)Struct)->d_type		<< endl;
						*dump_file << "d_scale = "	<< ((Attribute_Struct*)Struct)->d_scale		<< endl;
						*dump_file << "d_year = "	<< ((Attribute_Struct*)Struct)->d_year		<< endl;
						*dump_file << "d_month = "	<< ((Attribute_Struct*)Struct)->d_month		<< endl;
						*dump_file << "d_day = "	<< ((Attribute_Struct*)Struct)->d_day			<< endl;
						*dump_file << "c_contractor = "	<< ((Attribute_Struct*)Struct)->c_contractor	<< endl;
						*dump_file << "c_owner = "	<< ((Attribute_Struct*)Struct)->c_owner		<< endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
				}
			}	
		}
		/********************************************/
		/****** アセンブリ要素(用紙)の読み込み ******/
		/********************************************/
		EndFlag = 0;
		while(!EndFlag){ 
			ret = SXFread_assembly_name_AP202(SHEET,Struct,&EndFlag);//シート
			if (ret < 0){
				EndFlag = 1;
				break;
			}
			else{
				/****** ここに要素の処理を記載 ******/
				*dump_file << "--------------sheet-----------------" << endl;
				*dump_file << "-----------------" << ret << "-----------------------" << endl;
				*dump_file << "name = " << ((Sheet_Struct*)Struct)->name << endl;
				*dump_file << "type = " << ((Sheet_Struct*)Struct)->type << endl;
				*dump_file << "orient = " << ((Sheet_Struct*)Struct)->orient << endl;
				*dump_file << "x = " << ((Sheet_Struct*)Struct)->x << endl;
				*dump_file << "y = " << ((Sheet_Struct*)Struct)->y << endl;
				/** アセンブリ要素フィーチャ構造体の削除 **/
				SXFdelete_assembly_AP202(SHEET,Struct);
			}
			/************************************/
			/****** 用紙上の要素の読み込み ******/
			/************************************/
			FeatureEndFlag=0;
			while(!FeatureEndFlag){
				/** 終了フラグが立つまで要素を読込む **/
				error_code = SXFread_next_feature_AP202(FeatureName,Struct,&FeatureEndFlag);
				if (error_code > 0){
					if(!strcmp(FeatureName,"LINE")){// 線分の読み込み
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------LINE-----------------------" << endl;
						*dump_file << "layer = " << ((Line_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Line_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Line_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Line_Struct*)Struct)->line_width << endl;
						*dump_file << "start_x = " << ((Line_Struct*)Struct)->start_x << endl;
						*dump_file << "start_y = " << ((Line_Struct*)Struct)->start_y << endl;
						*dump_file << "end_x = " << ((Line_Struct*)Struct)->end_x << endl;
						*dump_file << "end_y = " << ((Line_Struct*)Struct)->end_y << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CIRCLE")){//円読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CIRCLE-----------------------" << endl;
						*dump_file << "layer = " << ((Circle_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Circle_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Circle_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Circle_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Circle_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Circle_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Circle_Struct*)Struct)->radius << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ARC")){//円弧読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ARC-----------------------" << endl;
						*dump_file << "layer = " << ((Arc_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Arc_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Arc_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Arc_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Arc_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Arc_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Arc_Struct*)Struct)->radius << endl;
						*dump_file << "direction = " << ((Arc_Struct*)Struct)->direction << endl;
						*dump_file << "start_angle = " << ((Arc_Struct*)Struct)->start_angle << endl;
						*dump_file << "end_angle = " << ((Arc_Struct*)Struct)->end_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ELLIPSE")){//楕円読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ELLIPSE-----------------------" << endl;
						*dump_file << "layer = " << ((Ellipse_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Ellipse_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Ellipse_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Ellipse_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Ellipse_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Ellipse_Struct*)Struct)->center_y << endl;
						*dump_file << "radius_x = " << ((Ellipse_Struct*)Struct)->radius_x << endl;
						*dump_file << "radius_y = " << ((Ellipse_Struct*)Struct)->radius_y << endl;
						*dump_file << "rotation_angle = " << ((Ellipse_Struct*)Struct)->rotation_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ELLIPSE_ARC")){//楕円弧読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ELLIPSE_ARC-----------------------" << endl;
						*dump_file << "layer = " << ((Ellipse_Arc_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Ellipse_Arc_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Ellipse_Arc_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Ellipse_Arc_Struct*)Struct)->line_width << endl;
						*dump_file << "center_x = " << ((Ellipse_Arc_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Ellipse_Arc_Struct*)Struct)->center_y << endl;
						*dump_file << "radius_x = " << ((Ellipse_Arc_Struct*)Struct)->radius_x << endl;
						*dump_file << "radius_y = " << ((Ellipse_Arc_Struct*)Struct)->radius_y << endl;
						*dump_file << "direction = " << ((Ellipse_Arc_Struct*)Struct)->direction << endl;
						*dump_file << "rotation_angle = " << ((Ellipse_Arc_Struct*)Struct)->rotation_angle << endl;
						*dump_file << "start_angle = " << ((Ellipse_Arc_Struct*)Struct)->start_angle << endl;
						*dump_file << "end_angle = " << ((Ellipse_Arc_Struct*)Struct)->end_angle << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "POLYLINE")){//折線読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------POLYLINE-----------------------" << endl;
						*dump_file << "layer = " << ((Polyline_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Polyline_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Polyline_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Polyline_Struct*)Struct)->line_width << endl;
						*dump_file << "number = " << ((Polyline_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Polyline_Struct*)Struct)->number; i++){
							*dump_file << "x[" << i << "] = " << ((Polyline_Struct*)Struct)->x[i] << endl;
							*dump_file << "y[" << i << "] = " << ((Polyline_Struct*)Struct)->y[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "TEXT")){//文字要素読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------TEXT-----------------------" << endl;
						*dump_file << "layer = " << ((Text_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Text_Struct*)Struct)->color << endl;
						*dump_file << "font = " << ((Text_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((Text_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((Text_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((Text_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((Text_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((Text_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((Text_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((Text_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((Text_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((Text_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((Text_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "POINT_MARKER")){//点マーカ読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------POINT_MARKER-----------------------" << endl;
						*dump_file << "layer = " << ((Point_Marker_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Point_Marker_Struct*)Struct)->color << endl;
						*dump_file << "start_x = " << ((Point_Marker_Struct*)Struct)->start_x << endl;
						*dump_file << "start_y = " << ((Point_Marker_Struct*)Struct)->start_y << endl;
						*dump_file << "marker_code = " << ((Point_Marker_Struct*)Struct)->marker_code << endl;
						*dump_file << "rotate_angle = " << ((Point_Marker_Struct*)Struct)->rotate_angle << endl;
						*dump_file << "scale = " << ((Point_Marker_Struct*)Struct)->scale << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "SPLINE")){//スプライン読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------SPLINE-----------------------" << endl;
						*dump_file << "layer = " << ((Spline_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Spline_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Spline_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Spline_Struct*)Struct)->line_width << endl;
						*dump_file << "open_close = " << ((Spline_Struct*)Struct)->open_close << endl;
						*dump_file << "number = " << ((Spline_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Spline_Struct*)Struct)->number; i++){
							*dump_file << "x[" << i << "] = " << ((Spline_Struct*)Struct)->x[i] << endl;
							*dump_file << "y[" << i << "] = " << ((Spline_Struct*)Struct)->y[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CLOTHOID")){//クロソイド読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CLOTHOID-----------------------" << endl;
						*dump_file << "layer = " << ((Clothoid_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Clothoid_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Clothoid_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Clothoid_Struct*)Struct)->line_width << endl;
						*dump_file << "base_x = " << ((Clothoid_Struct*)Struct)->base_x << endl;
						*dump_file << "base_y = " << ((Clothoid_Struct*)Struct)->base_y << endl;
						*dump_file << "parameter = " << ((Clothoid_Struct*)Struct)->parameter << endl;
						*dump_file << "direction = " << ((Clothoid_Struct*)Struct)->direction << endl;
						*dump_file << "angle = " << ((Clothoid_Struct*)Struct)->angle << endl;
						*dump_file << "start_length = " << ((Clothoid_Struct*)Struct)->start_length << endl;
						*dump_file << "end_length = " << ((Clothoid_Struct*)Struct)->end_length << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "EXTERNALLY_DEFINED_SYMBOL")){//既定義シンボル読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------EXTERNALLY_DEFINED_SYMBOL-----------------------" << endl;
						*dump_file << "layer = " << ((Externally_Defined_Symbol_Struct*)Struct)->layer << endl;
						*dump_file << "color_flag = " << ((Externally_Defined_Symbol_Struct*)Struct)->color_flag << endl;
						*dump_file << "color = " << ((Externally_Defined_Symbol_Struct*)Struct)->color << endl;
						*dump_file << "name = " << ((Externally_Defined_Symbol_Struct*)Struct)->name << endl;
						*dump_file << "start_x = " << ((Externally_Defined_Symbol_Struct*)Struct)->start_x << endl;
						*dump_file << "start_y = " << ((Externally_Defined_Symbol_Struct*)Struct)->start_y << endl;
						*dump_file << "rotate_angle = " << ((Externally_Defined_Symbol_Struct*)Struct)->rotate_angle << endl;
						*dump_file << "scale = " << ((Externally_Defined_Symbol_Struct*)Struct)->scale << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "LINEAR_DIMENSION")){//直線寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------LINEAR_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((LinearDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((LinearDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((LinearDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((LinearDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x1 = " << ((LinearDim_Struct*)Struct)->sun_x1 << endl;
						*dump_file << "sun_y1 = " << ((LinearDim_Struct*)Struct)->sun_y1 << endl;
						*dump_file << "sun_x2 = " << ((LinearDim_Struct*)Struct)->sun_x2 << endl;
						*dump_file << "sun_y2 = " << ((LinearDim_Struct*)Struct)->sun_y2 << endl;
						*dump_file << "flg2 = " << ((LinearDim_Struct*)Struct)->flg2 << endl;
						*dump_file << "ho1_x0 = " << ((LinearDim_Struct*)Struct)->ho1_x0 << endl;
						*dump_file << "ho1_y0 = " << ((LinearDim_Struct*)Struct)->ho1_y0 << endl;
						*dump_file << "ho1_x1 = " << ((LinearDim_Struct*)Struct)->ho1_x1 << endl;
						*dump_file << "ho1_y1 = " << ((LinearDim_Struct*)Struct)->ho1_y1 << endl;
						*dump_file << "ho1_x2 = " << ((LinearDim_Struct*)Struct)->ho1_x2 << endl;
						*dump_file << "ho1_y2 = " << ((LinearDim_Struct*)Struct)->ho1_y2 << endl;
						*dump_file << "flg3 = " << ((LinearDim_Struct*)Struct)->flg3 << endl;
						*dump_file << "ho2_x0 = " << ((LinearDim_Struct*)Struct)->ho2_x0 << endl;
						*dump_file << "ho2_y0 = " << ((LinearDim_Struct*)Struct)->ho2_y0 << endl;
						*dump_file << "ho2_x1 = " << ((LinearDim_Struct*)Struct)->ho2_x1 << endl;
						*dump_file << "ho2_y1 = " << ((LinearDim_Struct*)Struct)->ho2_y1 << endl;
						*dump_file << "ho2_x2 = " << ((LinearDim_Struct*)Struct)->ho2_x2 << endl;
						*dump_file << "ho2_y2 = " << ((LinearDim_Struct*)Struct)->ho2_y2 << endl;
						*dump_file << "arr1_code1 = " << ((LinearDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((LinearDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((LinearDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((LinearDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((LinearDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((LinearDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((LinearDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((LinearDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((LinearDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((LinearDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg4 = " << ((LinearDim_Struct*)Struct)->flg4 << endl;
						*dump_file << "font = " << ((LinearDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((LinearDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((LinearDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((LinearDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((LinearDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((LinearDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((LinearDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((LinearDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((LinearDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((LinearDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((LinearDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "CURVE_DIMENSION")){//弧長寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------CURVE_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((CurveDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((CurveDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((CurveDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((CurveDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x = " << ((CurveDim_Struct*)Struct)->sun_x << endl;
						*dump_file << "sun_y = " << ((CurveDim_Struct*)Struct)->sun_y << endl;
						*dump_file << "sun_radius = " << ((CurveDim_Struct*)Struct)->sun_radius << endl;
						*dump_file << "sun_angle0 = " << ((CurveDim_Struct*)Struct)->sun_angle0 << endl;
						*dump_file << "sun_angle1 = " << ((CurveDim_Struct*)Struct)->sun_angle1 << endl;
						*dump_file << "flg2 = " << ((CurveDim_Struct*)Struct)->flg2 << endl;
						*dump_file << "ho1_x0 = " << ((CurveDim_Struct*)Struct)->ho1_x0 << endl;
						*dump_file << "ho1_y0 = " << ((CurveDim_Struct*)Struct)->ho1_y0 << endl;
						*dump_file << "ho1_x1 = " << ((CurveDim_Struct*)Struct)->ho1_x1 << endl;
						*dump_file << "ho1_y1 = " << ((CurveDim_Struct*)Struct)->ho1_y1 << endl;
						*dump_file << "ho1_x2 = " << ((CurveDim_Struct*)Struct)->ho1_x2 << endl;
						*dump_file << "ho1_y2 = " << ((CurveDim_Struct*)Struct)->ho1_y2 << endl;
						*dump_file << "flg3 = " << ((CurveDim_Struct*)Struct)->flg3 << endl;
						*dump_file << "ho2_x0 = " << ((CurveDim_Struct*)Struct)->ho2_x0 << endl;
						*dump_file << "ho2_y0 = " << ((CurveDim_Struct*)Struct)->ho2_y0 << endl;
						*dump_file << "ho2_x1 = " << ((CurveDim_Struct*)Struct)->ho2_x1 << endl;
						*dump_file << "ho2_y1 = " << ((CurveDim_Struct*)Struct)->ho2_y1 << endl;
						*dump_file << "ho2_x2 = " << ((CurveDim_Struct*)Struct)->ho2_x2 << endl;
						*dump_file << "ho2_y2 = " << ((CurveDim_Struct*)Struct)->ho2_y2 << endl;
						*dump_file << "arr1_code1 = " << ((CurveDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((CurveDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((CurveDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((CurveDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((CurveDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((CurveDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((CurveDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((CurveDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((CurveDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((CurveDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg4 = " << ((CurveDim_Struct*)Struct)->flg4 << endl;
						*dump_file << "font = " << ((CurveDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((CurveDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((CurveDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((CurveDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((CurveDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((CurveDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((CurveDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((CurveDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((CurveDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((CurveDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((CurveDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ANGULAR_DIMENSION")){//角度寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ANGULAR_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((AngularDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((AngularDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((AngularDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((AngularDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x = " << ((AngularDim_Struct*)Struct)->sun_x << endl;
						*dump_file << "sun_y = " << ((AngularDim_Struct*)Struct)->sun_y << endl;
						*dump_file << "sun_radius = " << ((AngularDim_Struct*)Struct)->sun_radius << endl;
						*dump_file << "sun_angle0 = " << ((AngularDim_Struct*)Struct)->sun_angle0 << endl;
						*dump_file << "sun_angle1 = " << ((AngularDim_Struct*)Struct)->sun_angle1 << endl;
						*dump_file << "flg2 = " << ((AngularDim_Struct*)Struct)->flg2 << endl;
						*dump_file << "ho1_x0 = " << ((AngularDim_Struct*)Struct)->ho1_x0 << endl;
						*dump_file << "ho1_y0 = " << ((AngularDim_Struct*)Struct)->ho1_y0 << endl;
						*dump_file << "ho1_x1 = " << ((AngularDim_Struct*)Struct)->ho1_x1 << endl;
						*dump_file << "ho1_y1 = " << ((AngularDim_Struct*)Struct)->ho1_y1 << endl;
						*dump_file << "ho1_x2 = " << ((AngularDim_Struct*)Struct)->ho1_x2 << endl;
						*dump_file << "ho1_y2 = " << ((AngularDim_Struct*)Struct)->ho1_y2 << endl;
						*dump_file << "flg3 = " << ((AngularDim_Struct*)Struct)->flg3 << endl;
						*dump_file << "ho2_x0 = " << ((AngularDim_Struct*)Struct)->ho2_x0 << endl;
						*dump_file << "ho2_y0 = " << ((AngularDim_Struct*)Struct)->ho2_y0 << endl;
						*dump_file << "ho2_x1 = " << ((AngularDim_Struct*)Struct)->ho2_x1 << endl;
						*dump_file << "ho2_y1 = " << ((AngularDim_Struct*)Struct)->ho2_y1 << endl;
						*dump_file << "ho2_x2 = " << ((AngularDim_Struct*)Struct)->ho2_x2 << endl;
						*dump_file << "ho2_y2 = " << ((AngularDim_Struct*)Struct)->ho2_y2 << endl;
						*dump_file << "arr1_code1 = " << ((AngularDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((AngularDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((AngularDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((AngularDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((AngularDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((AngularDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((AngularDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((AngularDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((AngularDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((AngularDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg4 = " << ((AngularDim_Struct*)Struct)->flg4 << endl;
						*dump_file << "font = " << ((AngularDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((AngularDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((AngularDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((AngularDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((AngularDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((AngularDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((AngularDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((AngularDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((AngularDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((AngularDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((AngularDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "RADIUS_DIMENSION")){//半径寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------RADIUS_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((RadiusDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((RadiusDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((RadiusDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((RadiusDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x1 = " << ((RadiusDim_Struct*)Struct)->sun_x1 << endl;
						*dump_file << "sun_y1 = " << ((RadiusDim_Struct*)Struct)->sun_y1 << endl;
						*dump_file << "sun_x2 = " << ((RadiusDim_Struct*)Struct)->sun_x2 << endl;
						*dump_file << "sun_y2 = " << ((RadiusDim_Struct*)Struct)->sun_y2 << endl;
						*dump_file << "arr_code1 = " << ((RadiusDim_Struct*)Struct)->arr_code1 << endl;
						*dump_file << "arr_code2 = " << ((RadiusDim_Struct*)Struct)->arr_code2 << endl;
						*dump_file << "arr_x = " << ((RadiusDim_Struct*)Struct)->arr_x << endl;
						*dump_file << "arr_y = " << ((RadiusDim_Struct*)Struct)->arr_y << endl;
						*dump_file << "arr_r = " << ((RadiusDim_Struct*)Struct)->arr_r << endl;
						*dump_file << "flg = " << ((RadiusDim_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((RadiusDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((RadiusDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((RadiusDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((RadiusDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((RadiusDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((RadiusDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((RadiusDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((RadiusDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((RadiusDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((RadiusDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((RadiusDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "DIAMETER_DIMENSION")){//直径寸法読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------DIAMETER_DIMENSION-----------------------" << endl;
						*dump_file << "layer = " << ((DiameterDim_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((DiameterDim_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((DiameterDim_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((DiameterDim_Struct*)Struct)->line_width << endl;
						*dump_file << "sun_x1 = " << ((DiameterDim_Struct*)Struct)->sun_x1 << endl;
						*dump_file << "sun_y1 = " << ((DiameterDim_Struct*)Struct)->sun_y1 << endl;
						*dump_file << "sun_x2 = " << ((DiameterDim_Struct*)Struct)->sun_x2 << endl;
						*dump_file << "sun_y2 = " << ((DiameterDim_Struct*)Struct)->sun_y2 << endl;
						*dump_file << "arr1_code1 = " << ((DiameterDim_Struct*)Struct)->arr1_code1 << endl;
						*dump_file << "arr1_code2 = " << ((DiameterDim_Struct*)Struct)->arr1_code2 << endl;
						*dump_file << "arr1_x = " << ((DiameterDim_Struct*)Struct)->arr1_x << endl;
						*dump_file << "arr1_y = " << ((DiameterDim_Struct*)Struct)->arr1_y << endl;
						*dump_file << "arr1_r = " << ((DiameterDim_Struct*)Struct)->arr1_r << endl;
						*dump_file << "arr2_code1 = " << ((DiameterDim_Struct*)Struct)->arr2_code1 << endl;
						*dump_file << "arr2_code2 = " << ((DiameterDim_Struct*)Struct)->arr2_code2 << endl;
						*dump_file << "arr2_x = " << ((DiameterDim_Struct*)Struct)->arr2_x << endl;
						*dump_file << "arr2_y = " << ((DiameterDim_Struct*)Struct)->arr2_y << endl;
						*dump_file << "arr2_r = " << ((DiameterDim_Struct*)Struct)->arr2_r << endl;
						*dump_file << "flg = " << ((DiameterDim_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((DiameterDim_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((DiameterDim_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((DiameterDim_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((DiameterDim_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((DiameterDim_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((DiameterDim_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((DiameterDim_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((DiameterDim_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((DiameterDim_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((DiameterDim_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((DiameterDim_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "LABEL")){//ラベル読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------LABEL-----------------------" << endl;
						*dump_file << "layer = " << ((Label_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Label_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Label_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Label_Struct*)Struct)->line_width << endl;
						*dump_file << "vertex_number = " << ((Label_Struct*)Struct)->vertex_number << endl;
						for (int i = 0; i < ((Label_Struct*)Struct)->vertex_number; i++){
							*dump_file << "vertex_x[" << i << "] = " << ((Label_Struct*)Struct)->vertex_x[i] << endl;
							*dump_file << "vertex_y[" << i << "] = " << ((Label_Struct*)Struct)->vertex_y[i] << endl;
						}
						*dump_file << "arr_code = " << ((Label_Struct*)Struct)->arr_code << endl;
						*dump_file << "arr_r = " << ((Label_Struct*)Struct)->arr_r << endl;
						*dump_file << "flg = " << ((Label_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((Label_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((Label_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((Label_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((Label_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((Label_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((Label_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((Label_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((Label_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((Label_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((Label_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((Label_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "BALLOON")){//バルーン読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------BALLOON-----------------------" << endl;
						*dump_file << "layer = " << ((Balloon_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Balloon_Struct*)Struct)->color << endl;
						*dump_file << "type = " << ((Balloon_Struct*)Struct)->type << endl;
						*dump_file << "line_width = " << ((Balloon_Struct*)Struct)->line_width << endl;
						*dump_file << "vertex_number = " << ((Balloon_Struct*)Struct)->vertex_number << endl;
						for (int i = 0; i < ((Balloon_Struct*)Struct)->vertex_number; i++){
							*dump_file << "vertex_x[" << i << "] = " << ((Balloon_Struct*)Struct)->vertex_x[i] << endl;
							*dump_file << "vertex_y[" << i << "] = " << ((Balloon_Struct*)Struct)->vertex_y[i] << endl;
						}
						*dump_file << "center_x = " << ((Balloon_Struct*)Struct)->center_x << endl;
						*dump_file << "center_y = " << ((Balloon_Struct*)Struct)->center_y << endl;
						*dump_file << "radius = " << ((Balloon_Struct*)Struct)->radius << endl;
						*dump_file << "arr_code = " << ((Balloon_Struct*)Struct)->arr_code << endl;
						*dump_file << "arr_r = " << ((Balloon_Struct*)Struct)->arr_r << endl;
						*dump_file << "flg = " << ((Balloon_Struct*)Struct)->flg << endl;
						*dump_file << "font = " << ((Balloon_Struct*)Struct)->font << endl;
						*dump_file << "str = " << ((Balloon_Struct*)Struct)->str << endl;
						*dump_file << "text_x = " << ((Balloon_Struct*)Struct)->text_x << endl;
						*dump_file << "text_y = " << ((Balloon_Struct*)Struct)->text_y << endl;
						*dump_file << "height = " << ((Balloon_Struct*)Struct)->height << endl;
						*dump_file << "width = " << ((Balloon_Struct*)Struct)->width << endl;
						*dump_file << "spc = " << ((Balloon_Struct*)Struct)->spc << endl;
						*dump_file << "angle = " << ((Balloon_Struct*)Struct)->angle << endl;
						*dump_file << "slant = " << ((Balloon_Struct*)Struct)->slant << endl;
						*dump_file << "b_pnt = " << ((Balloon_Struct*)Struct)->b_pnt << endl;
						*dump_file << "direct = " << ((Balloon_Struct*)Struct)->direct << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "FILL_AREA_STYLE_HATCHING")){//ユーザ定義ハッチング読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------FILL_AREA_STYLE_HATCHING-----------------------" << endl;
						*dump_file << "layer = " << ((Fill_area_style_hatching_Struct*)Struct)->layer << endl;
						*dump_file << "hatch_number = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_number << endl;
						for (int i = 0; i < ((Fill_area_style_hatching_Struct*)Struct)->hatch_number; i++){
							*dump_file << "hatch_color[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_color[i] << endl;
							*dump_file << "hatch_type[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_type[i] << endl;
							*dump_file << "hatch_line_width[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_line_width[i] << endl;
							*dump_file << "hatch_start_x[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_start_x[i] << endl;
							*dump_file << "hatch_start_y[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_start_y[i] << endl;
							*dump_file << "hatch_spacing[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_spacing[i] << endl;
							*dump_file << "hatch_angle[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->hatch_angle[i] << endl;
						}
						*dump_file << "out_id = " << ((Fill_area_style_hatching_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Fill_area_style_hatching_Struct*)Struct)->number << endl;
						for (i = 0; i < ((Fill_area_style_hatching_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Fill_area_style_hatching_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "EXTERNALLY_DEFINED_HATCH")){//ハッチング（外部定義）読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------EXTERNALLY_DEFINED_HATCH-----------------------" << endl;
						*dump_file << "layer = " << ((Externally_Defined_Hatch_Struct*)Struct)->layer << endl;
						*dump_file << "name = " << ((Externally_Defined_Hatch_Struct*)Struct)->name << endl;
						*dump_file << "out_id = " << ((Externally_Defined_Hatch_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Externally_Defined_Hatch_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Externally_Defined_Hatch_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Externally_Defined_Hatch_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "FILL_AREA_STYLE_COLOUR")){//ハッチング(塗り）読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------FILL_AREA_STYLE_COLOUR-----------------------" << endl;
						*dump_file << "layer = " << ((Fill_area_style_colour_Struct*)Struct)->layer << endl;
						*dump_file << "color = " << ((Fill_area_style_colour_Struct*)Struct)->color << endl;
						*dump_file << "out_id = " << ((Fill_area_style_colour_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Fill_area_style_colour_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Fill_area_style_colour_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Fill_area_style_colour_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "FILL_AREA_STYLE_TILES")){//ハッチング(パターン）読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------FILL_AREA_STYLE_TILES-----------------------" << endl;
						*dump_file << "layer = " << ((Fill_area_style_tiles_Struct*)Struct)->layer << endl;
						*dump_file << "name = " << ((Fill_area_style_tiles_Struct*)Struct)->name << endl;
						*dump_file << "hatch_color = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_color << endl;
						*dump_file << "hatch_pattern_x = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_x << endl;
						*dump_file << "hatch_pattern_y = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_y << endl;
						*dump_file << "hatch_pttern_vector1 = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector1 << endl;
						*dump_file << "hatch_pattern_vector1_angle = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector1_angle << endl;
						*dump_file << "hatch_pttern_vector2 = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector2 << endl;
						*dump_file << "hatch_pattern_vector2_angle = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_vector2_angle << endl;
						*dump_file << "hatch_pattern_scale_x = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_scale_x << endl;
						*dump_file << "hatch_pattern_scale_y = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_scale_y << endl;
						*dump_file << "hatch_pattern_angle = " << ((Fill_area_style_tiles_Struct*)Struct)->hatch_pattern_angle << endl;
						*dump_file << "out_id = " << ((Fill_area_style_tiles_Struct*)Struct)->out_id << endl;
						*dump_file << "number = " << ((Fill_area_style_tiles_Struct*)Struct)->number << endl;
						for (int i = 0; i < ((Fill_area_style_tiles_Struct*)Struct)->number; i++){
							*dump_file << "in_id[" << i << "] = " << ((Fill_area_style_tiles_Struct*)Struct)->in_id[i] << endl;
						}
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "SFIG_LOCATE")){//複合図形配置読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------SFIG_LOCATE-----------------------" << endl;
						*dump_file << "layer = " << ((Sfigloc_Struct*)Struct)->layer << endl;
						*dump_file << "name = " << ((Sfigloc_Struct*)Struct)->name << endl;
						*dump_file << "x = " << ((Sfigloc_Struct*)Struct)->x << endl;
						*dump_file << "y = " << ((Sfigloc_Struct*)Struct)->y << endl;
						*dump_file << "angle = " << ((Sfigloc_Struct*)Struct)->angle << endl;
						*dump_file << "ratio_x = " << ((Sfigloc_Struct*)Struct)->ratio_x << endl;
						*dump_file << "ratio_y = " << ((Sfigloc_Struct*)Struct)->ratio_y << endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
					else if (!strcmp(FeatureName, "ATTRIBUTE")){//図面表題欄読みこみ
						/****** ここに要素の処理を記載 ******/
						*dump_file << "--------------------ATTRIBUTE-----------------------"	<< endl;
						*dump_file << "p_name = "	<< ((Attribute_Struct*)Struct)->p_name		<< endl;
						*dump_file << "c_name = "	<< ((Attribute_Struct*)Struct)->c_name		<< endl;
						*dump_file << "c_type = "	<< ((Attribute_Struct*)Struct)->c_type		<< endl;
						*dump_file << "d_title = "	<< ((Attribute_Struct*)Struct)->d_title		<< endl;
						*dump_file << "d_number = "	<< ((Attribute_Struct*)Struct)->d_number	<< endl;
						*dump_file << "d_type = "	<< ((Attribute_Struct*)Struct)->d_type		<< endl;
						*dump_file << "d_scale = "	<< ((Attribute_Struct*)Struct)->d_scale		<< endl;
						*dump_file << "d_year = "	<< ((Attribute_Struct*)Struct)->d_year		<< endl;
						*dump_file << "d_month = "	<< ((Attribute_Struct*)Struct)->d_month		<< endl;
						*dump_file << "d_day = "	<< ((Attribute_Struct*)Struct)->d_day			<< endl;
						*dump_file << "c_contractor = "	<< ((Attribute_Struct*)Struct)->c_contractor	<< endl;
						*dump_file << "c_owner = "	<< ((Attribute_Struct*)Struct)->c_owner		<< endl;
						/** 一般要素フィーチャ構造体の削除 **/
						SXFdelete_feature_AP202(FeatureName,Struct);
						continue;
					}
				}
			}
		}
		/*****************************/
		/****** dump file close ******/
		/*****************************/
		timeCount = GetTickCount() - timeCount;					// 2010.8
		*dump_file << "timeCount = "		    << timeCount << " , "
				   << (timeCount / 3600000)  	<< "時"
				   << (timeCount / 60000) % 60  << "分"
				   << (timeCount / 1000) % 60	<< "秒"
				   << endl;										// 2010.8

		dump_file->close();
		delete dump_file;
		/**********************************/
		/****** STEPファイルクローズ ******/		
		/**********************************/
		if (SXFclose_AP202() < 0){
			//エラー問い合わせ
			SXFPopMsg_AP202(name,&msgno,text);
			cout << name << " : " << msgno << " : " << text << endl << endl;
			msgno = 0;
			name = "";
			text = "";
			return ;
		}
	}


	/*********************************************************/
	/*********************** WIRTE ***************************/
	/*********************************************************/
	/** 読み書きフラグが1の場合、Write処理 **/
	else if (rw_flg == 1){
		int		return_code;
		char	out_file_name[257];//出力ファイル名
		char	author[257];//
		char	org[257];
		char	translator_name[257];
		char	file_version[257];

		/** 出力ファイル名取得 **/
		printf("output file_name==>");
		scanf("%s",out_file_name);
		/** 書き込みモード設定 **/
		/* モードは2で固定。それ以外は受け付けない。 */
		mode = 2;
		/** ファイル作成者名取得 **/
		printf("author ?");
		scanf("%s",author);
		/** 作成者所属取得 **/
		printf("organization name ?");
		scanf("%s",org);
		/** トランスレータ名取得 **/
		printf("translator name ?");
		scanf("%s",translator_name);
		/** ファイルバージョン取得 **/
		printf("file version ?");
		scanf("%s",file_version);
		/**********************************/
		/****** STEPファイルオープン ******/
		/**********************************/
		if (SXFset_file_version_AP202(file_version) < 0)
		{
			return ;
		}
		if (SXFopen_AP202(out_file_name,		/** 出力ﾌｧｲﾙ名 **/
							rw_flg,				/** read/writeﾌﾗｸﾞ **/
							tolerance1,			/** 長さ用許容誤差 **/
							tolerance2,			/** 角度用許容誤差 **/
							divide,				/** スプライン分割用許容誤差 **/
							level,				/** ﾚﾍﾞﾙ **/
							mode,				/** 書き込みﾓｰﾄﾞ **/
							author,				/** ﾌｧｲﾙ作成者名 **/
							org,				/** ﾌｧｲﾙ作成者所属 **/
							translator_name,	/** ﾄﾗﾝｽﾚｰﾀ名 **/
							NULL				/** 共通ﾗｲﾌﾞﾗﾘﾊﾞｰｼﾞｮﾝ(WRITE時無効) **/
							) < 0){
			//エラー問い合わせ
			SXFPopMsg_AP202(name,&msgno,text);
			cout << name << " : " << msgno << " : " << text << endl << endl;
			msgno = 0;
			name = "";
			text = "";
			return ;
		}

		/***************************************************/
		/******************* 構造体の定義 ******************/
		/***************************************************/
		/********************************/
		/***** アセンブリ要素の定義 *****/
		/********************************/
		Sheet_Struct* Sheet_str = new Sheet_Struct;
		Sfigorg_Struct* Sfigorg_str = new Sfigorg_Struct;
		Ccurve_Org_Struct* Ccurve_str = new Ccurve_Org_Struct;
		/********************************/
		/**** 定義テーブル要素の定義 ****/
		/********************************/
		Layer_Struct* layer_str = new Layer_Struct;
		Predefined_Colour_Struct* predefcolor_str = new Predefined_Colour_Struct;
		Userdefined_Colour_Struct* userdefcolor_str = new Userdefined_Colour_Struct;
		Predefined_Linetype_Struct* predeffont_str = new Predefined_Linetype_Struct;
		Userdefined_Linetype_Struct* userdeffont_str = new Userdefined_Linetype_Struct;
		Line_Width_Struct* width_str = new Line_Width_Struct;
		Text_Font_Struct* textfont_str = new Text_Font_Struct;
		/********************************/
		/******** 一般要素の定義 ********/
		/********************************/
		Attribute_Struct* Attribute_str = new Attribute_Struct;
		Point_Marker_Struct* PointMarker_str = new Point_Marker_Struct;
		Line_Struct* Line_str = new Line_Struct;
		Polyline_Struct* Polyline_str = new Polyline_Struct;
		Circle_Struct* Circle_str = new Circle_Struct;
		Arc_Struct* Arc_str = new Arc_Struct;
		Ellipse_Struct* Ellipse_str = new Ellipse_Struct;
		Ellipse_Arc_Struct* Ellipse_Arc_str = new Ellipse_Arc_Struct;
		Text_Struct* Text_str = new Text_Struct;
		Spline_Struct* Spline_str = new Spline_Struct;
		Clothoid_Struct* Clothoid_str = new Clothoid_Struct;
		Sfigloc_Struct* Sfigloc_str = new Sfigloc_Struct;
		Externally_Defined_Symbol_Struct* ExSymbol_str = new Externally_Defined_Symbol_Struct;
		LinearDim_Struct* LinearDim_str = new LinearDim_Struct;
		CurveDim_Struct* CurveDim_str = new CurveDim_Struct;
		AngularDim_Struct* AngularDim_str = new AngularDim_Struct;
		RadiusDim_Struct* RadiusDim_str = new RadiusDim_Struct;
		DiameterDim_Struct* DiameterDim_str = new DiameterDim_Struct;
		Label_Struct* Label_str = new Label_Struct;
		Balloon_Struct* Balloon_str = new Balloon_Struct;
		Externally_Defined_Hatch_Struct* ExHatch_str = new Externally_Defined_Hatch_Struct;
		Fill_area_style_colour_Struct* FillColour_str = new Fill_area_style_colour_Struct;
		Fill_area_style_hatching_Struct* FillHatching_str = new Fill_area_style_hatching_Struct;
		Fill_area_style_tiles_Struct* FillTiles_str = new Fill_area_style_tiles_Struct;

		/***************************************************/
		/*************** 定義テーブル要素出力 **************/
		/***************************************************/

		/************ レイヤコード出力 ************/
		/********************************/
		/** レイヤコード出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		/* フィーチャ構造体へのデータ設定 */
		strcpy(layer_str->name,"layer1");
		layer_str->lflag = 1;
		/** レイヤコード出力 **/
		return_code = SXFwrite_table_AP202(1,layer_str);
		/********************************/
		/** レイヤコード出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(layer_str->name,"layer2");
		layer_str->lflag = 0;
		/** レイヤコード出力 **/
		return_code = SXFwrite_table_AP202(1,layer_str);
		/********************************/
		/** レイヤコード出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(layer_str->name,"layer3");
		layer_str->lflag = 1;
		/** レイヤコード出力 **/
		return_code = SXFwrite_table_AP202(1,layer_str);

		/************ 既定義色出力 ************/
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"red");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"deeppink");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"green");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"black");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"blue");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"yellow");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"magenta");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"cyan");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"white");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"brown");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"orange");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"lightgreen");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"lightblue");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"lavender");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"lightgray");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);
		/****************************/
		/** 既定義色出力データ設定 **/
		/****************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predefcolor_str->name,"darkgray");
		/** 既定義色出力 **/
		return_code = SXFwrite_table_AP202(2,predefcolor_str);

		/************ ユーザ定義色出力 ************/
		/********************************/
		/** ユーザ定義色出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		userdefcolor_str->red = 255;
		userdefcolor_str->green = 255;
		userdefcolor_str->blue = 0;
		/** ユーザ定義色出力 **/
		return_code = SXFwrite_table_AP202(3,userdefcolor_str);
		/********************************/
		/** ユーザ定義色出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		userdefcolor_str->red = 255;
		userdefcolor_str->green = 0;
		userdefcolor_str->blue = 255;
		/** ユーザ定義色出力 **/
		return_code = SXFwrite_table_AP202(3,userdefcolor_str);
		/********************************/
		/** ユーザ定義色出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		userdefcolor_str->red = 255;
		userdefcolor_str->green = 255;
		userdefcolor_str->blue = 255;
		/** ユーザ定義色出力 **/
		return_code = SXFwrite_table_AP202(3,userdefcolor_str);


		/************ 既定義線種出力 ************/
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"long dashed double-dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"continuous");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"double-dashed double-dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"dashed");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"dashed spaced");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"long dashed dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"long dashed triplicate-dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"chain");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"chain double dash");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"dashed dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"double-dashed dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"dashed double-dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"dashed triplicate-dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);
		/******************************/
		/** 既定義線種出力データ設定 **/
		/******************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(predeffont_str->name,"double-dashed triplicate-dotted");
		/** 既定義線種出力 **/
		return_code = SXFwrite_table_AP202(4,predeffont_str);

		/************ ユーザ定義線種出力 ************/
		/**********************************/
		/** ユーザ定義線種出力データ設定 **/
		/**********************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(userdeffont_str->name,"$$SXF_continuous");
		userdeffont_str->segment = 2;
		userdeffont_str->pitch[0] = 3.5;
		userdeffont_str->pitch[1] = 5.5;
		/** ユーザ定義線種出力 **/
		return_code = SXFwrite_table_AP202(5,userdeffont_str);
		/**********************************/
		/** ユーザ定義線種出力データ設定 **/
		/**********************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(userdeffont_str->name,"$$SXF_dashed");
		userdeffont_str->segment = 4;
		userdeffont_str->pitch[0] = 5.5;
		userdeffont_str->pitch[1] = 3.5;
		userdeffont_str->pitch[2] = 2.5;
		userdeffont_str->pitch[3] = 1.5;
		/** ユーザ定義線種出力 **/
		return_code = SXFwrite_table_AP202(5,userdeffont_str);

		/************ 線幅出力 ************/
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 0.13;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 0.18;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 0.25;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 0.35;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 0.5;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 0.7;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 1.0;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 1.4;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 2.0;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 10.13;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 10.18;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 10.25;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 10.35;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);
		/************************/
		/** 線幅出力データ設定 **/
		/************************/
		/****** ここに要素の処理を記載 ******/
		width_str->width = 10.5;
		/** 線幅出力 **/
		return_code = SXFwrite_table_AP202(6,width_str);

		/************ 文字フォント出力 ************/
		/********************************/
		/** 文字フォント出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(textfont_str->name,"ＭＳ ゴシック");
		/** 文字フォント出力 **/
		return_code = SXFwrite_table_AP202(7,textfont_str);
		/********************************/
		/** 文字フォント出力データ設定 **/
		/********************************/
		/****** ここに要素の処理を記載 ******/
		strcpy(textfont_str->name,"ＭＳ 明朝");
		/** 文字フォント出力 **/
		return_code = SXFwrite_table_AP202(7,textfont_str);

		/*********************************************/
		/********* アセンブリ要素出力テスト **********/
		/*********************************************/
		/****** 複合曲線データ設定 ******/
		/****** ここに要素の処理を記載 ******/
		/* フィーチャ構造体へのデータ設定 */
		Ccurve_str->color = 17;
		Ccurve_str->type = 12;
		Ccurve_str->line_width = 2;
		Ccurve_str->flag = 1;
		/** 複合曲線出力 **/
		int curve = SXFwrite_assembly_name_AP202(3,Ccurve_str);

		/**************************/
		/*** 一般要素出力テスト ***/
		/**************************/
		/** 図面表題欄データ設定 **/
		/****** ここに要素の処理を記載 ******/
		strcpy(Attribute_str->p_name,		"事業名1") ;		/* 事業名 */
		strcpy(Attribute_str->c_name,		"工事名1") ;		/* 工事名 */
		strcpy(Attribute_str->c_type,		"契約区分1") ;		/* 契約区分 */
		strcpy(Attribute_str->d_title,		"図面名1") ;		/* 図面名 */
		strcpy(Attribute_str->d_number,		"図面番号1") ;		/* 図面番号 */
		strcpy(Attribute_str->d_type,		"図面種別1") ;		/* 図面種別 */
		strcpy(Attribute_str->d_scale,		"尺度1") ;			/* 尺度 */
		Attribute_str->d_year	= 2002 ;						/* 図面作成年(西暦) */
		Attribute_str->d_month	= 12 ;							/* 図面作成月(西暦) */
		Attribute_str->d_day	= 1 ;							/* 図面作成日(西暦) */
		strcpy(Attribute_str->c_contractor,	"受注会社名1") ;	/* 受注会社名 */
		strcpy(Attribute_str->c_owner,		"発注事業者名1") ;	/* 発注事業者名 */
		/** 図面表題欄出力 **/
		return_code = SXFwrite_next_feature_AP202("ATTRIBUTE",Attribute_str);

		/** 円弧データ設定 **/
		/****** ここに要素の処理を記載 ******/
		/* フィーチャ構造体の定義 */
		/* フィーチャ構造体へのデータ設定 */
		Arc_str->layer = 3;
		Arc_str->color = 1;
		Arc_str->type = 2;
		Arc_str->line_width = 2;
		Arc_str->center_x = 0.0;
		Arc_str->center_y = 0.0;
		Arc_str->radius = 20.0;
		Arc_str->direction = 0;
		Arc_str->start_angle = 0.0;
		Arc_str->end_angle = 180.0;
		/** 円弧出力 **/
		return_code = SXFwrite_next_feature_AP202("ARC",Arc_str);
		/** 折線データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Polyline_str->layer = 1;
		Polyline_str->color = 4;
		Polyline_str->type = 3;
		Polyline_str->line_width = 1;
		Polyline_str->number = 3;
		double d;
		d = -20.0;
		Polyline_str->x.Add(d);
		d = -20.0;
		Polyline_str->x.Add(d);
		d = 20.0;
		Polyline_str->x.Add(d);
		d = 0.0;
		Polyline_str->y.Add(d);
		d = -20.0;
		Polyline_str->y.Add(d);
		d = 0.0;
		Polyline_str->y.Add(d);
		/** 折線出力 **/
		return_code = SXFwrite_next_feature_AP202("POLYLINE",Polyline_str);

		/*********************************************/
		/********* アセンブリ要素出力テスト **********/
		/*********************************************/
		/****** 複合曲線データ設定 ******/
		/****** ここに要素の処理を記載 ******/
		Ccurve_str->color = 2;
		Ccurve_str->type = 5;
		Ccurve_str->line_width = 2;
		Ccurve_str->flag = 1;
		/** 複合曲線出力 **/
		int curve2 = SXFwrite_assembly_name_AP202(3,Ccurve_str);

		/**************************/
		/*** 一般要素出力テスト ***/
		/**************************/

		/** 折線データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Polyline_str->layer = 1;
		Polyline_str->color = 4;
		Polyline_str->type = 10;
		Polyline_str->line_width = 1;
		Polyline_str->number = 4;
		d = -5.0;
		Polyline_str->x.Add(d);
		d = 5.0;
		Polyline_str->x.Add(d);
		d = 5.0;
		Polyline_str->x.Add(d);
		d = -5.0;
		Polyline_str->x.Add(d);
		d = 0.0;
		Polyline_str->y.Add(d);
		d = 0.0;
		Polyline_str->y.Add(d);
		d = 5.0;
		Polyline_str->y.Add(d);
		d = 0.0;
		Polyline_str->y.Add(d);
		/** 折線出力 **/
		return_code = SXFwrite_next_feature_AP202("POLYLINE",Polyline_str);

		/*********************************************/
		/********* アセンブリ要素出力テスト **********/
		/*********************************************/
		/****** 複合図形データ設定 ******/
		/****** ここに要素の処理を記載 ******/
		strcpy(Sfigorg_str->name,"sfig");
		Sfigorg_str->flag = 4;
		/** 複合図形出力 **/
		return_code =SXFwrite_assembly_name_AP202(2,Sfigorg_str);

		/**************************/
		/*** 一般要素出力テスト ***/
		/**************************/

		/** 線分データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Line_str->layer = 2;
		Line_str->color = 2;
		Line_str->type = 8;
		Line_str->line_width = 15;
		Line_str->start_x = 0.0;
		Line_str->start_y = 0.0;
		Line_str->end_x = 10.0;
		Line_str->end_y = 10.0;
		/** 線分出力 **/
		return_code = SXFwrite_next_feature_AP202("LINE",Line_str);
		/** 円弧データ出力 **/
		/****** ここに要素の処理を記載 ******/
		Arc_str->layer = 2;
		Arc_str->color = 5;
		Arc_str->type = 10;
		Arc_str->line_width = 5;
		Arc_str->center_x = 0.0;
		Arc_str->center_y = 0.0;
		Arc_str->radius = 10.0;
		Arc_str->direction = 0;
		Arc_str->start_angle = 0.0;
		Arc_str->end_angle = 90.0;
		/** 円弧出力 **/
		return_code = SXFwrite_next_feature_AP202("ARC",Arc_str);
		/** 楕円弧データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Ellipse_Arc_str->layer = 3;
		Ellipse_Arc_str->color = 7;
		Ellipse_Arc_str->type = 11;
		Ellipse_Arc_str->line_width = 7;
		Ellipse_Arc_str->center_x = 0.0;
		Ellipse_Arc_str->center_y = 0.0;
		Ellipse_Arc_str->radius_x = 10.0;
		Ellipse_Arc_str->radius_y = 20.0;
		Ellipse_Arc_str->direction = 1;
		Ellipse_Arc_str->rotation_angle = 0.0;
		Ellipse_Arc_str->start_angle = 0.0;
		Ellipse_Arc_str->end_angle = 90.0;
		/** 楕円弧出力 **/
		return_code = SXFwrite_next_feature_AP202("ELLIPSE_ARC",Ellipse_Arc_str);
		
		/** 文字要素データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Text_str->layer = 1;
		Text_str->color = 4;
		Text_str->font = 1;
		strcpy(Text_str->str,"、　。々○０あ亜唖 テスト文字 abc 出力");
		Text_str->text_x = 0.0;
		Text_str->text_y = 0.0;
		Text_str->height = 5.0;
		Text_str->width = 20.0;
		Text_str->spc = 1.0;
		Text_str->angle = 0.0;
		Text_str->slant = 0.0;
		Text_str->b_pnt = 1;
		Text_str->direct = 1;
		/** 文字要素出力 **/
		return_code = SXFwrite_next_feature_AP202("TEXT",Text_str);

		/*********************************************/
		/********* アセンブリ要素出力テスト **********/
		/*********************************************/
		/****** 複合図形データ設定 ******/
		/****** ここに要素の処理を記載 ******/
		strcpy(Sfigorg_str->name,"sfig2");
		Sfigorg_str->flag = 1;
		/** 複合図形出力 **/
		return_code = SXFwrite_assembly_name_AP202(2,Sfigorg_str);

		/**************************/
		/*** 一般要素出力テスト ***/
		/**************************/

		/** 文字要素データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Text_str->layer = 2;
		Text_str->color = 8;
		Text_str->font = 2;
		strcpy(Text_str->str,"text10");
		Text_str->text_x = 0.0;
		Text_str->text_y = 0.0;
		Text_str->height = 5.0;
		Text_str->width = 20.0;
		Text_str->spc = 1.0;
		Text_str->angle = 0.0;
		Text_str->slant = 0.0;
		Text_str->b_pnt = 1;
		Text_str->direct = 2;
		/** 文字要素出力 **/
		return_code = SXFwrite_next_feature_AP202("TEXT",Text_str);
		/** 楕円データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Ellipse_str->layer = 3;
		Ellipse_str->color = 6;
		Ellipse_str->type = 6;
		Ellipse_str->line_width = 6;
		Ellipse_str->center_x = 0.0;
		Ellipse_str->center_y = 0.0;
		Ellipse_str->radius_x = 10.0;
		Ellipse_str->radius_y = 20.0;
		Ellipse_str->rotation_angle = 0.0;
		/** 楕円出力 **/
		return_code = SXFwrite_next_feature_AP202("ELLIPSE",Ellipse_str);
		/** 複合図形配置データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Sfigloc_str->layer = 1;
		strcpy(Sfigloc_str->name,"sfig");
		Sfigloc_str->x = 0.0;
		Sfigloc_str->y = 0.0;
		Sfigloc_str->angle = 0.0;
		Sfigloc_str->ratio_x = 2.0;
		Sfigloc_str->ratio_y = 2.0;
		/** 複合図形配置出力 **/
		return_code = SXFwrite_next_feature_AP202("SFIG_LOCATE",Sfigloc_str);

		/** 点マーカデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		PointMarker_str->layer = 1;
		PointMarker_str->color = 1;
		PointMarker_str->start_x = 0.0;
		PointMarker_str->start_y = 0.0;
		PointMarker_str->marker_code = 7;
		PointMarker_str->rotate_angle = 0.0;
		PointMarker_str->scale = 1.0;
		/** 点マーカ出力 **/
		return_code = SXFwrite_next_feature_AP202("POINT_MARKER",PointMarker_str);

		/** 線分データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Line_str->layer = 2;
		Line_str->color = 2;
		Line_str->type = 2;
		Line_str->line_width = 2;
		Line_str->start_x = 0.0;
		Line_str->start_y = 0.0;
		Line_str->end_x = 10.0;
		Line_str->end_y = 10.0;
		/** 線分出力 **/
		return_code = SXFwrite_next_feature_AP202("LINE",Line_str);
		
		/** 折線データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Polyline_str->layer = 1;
		Polyline_str->color = 3;
		Polyline_str->type = 3;
		Polyline_str->line_width = 3;
		Polyline_str->number = 3;
		d = 1.0;
		Polyline_str->x.Add(d);
		d = 1.0;
		Polyline_str->x.Add(d);
		d = -4.0;
		Polyline_str->x.Add(d);
		d = 2.0;
		Polyline_str->y.Add(d);
		d = 1.0;
		Polyline_str->y.Add(d);
		d = 3.0;
		Polyline_str->y.Add(d);
		/** 折線出力 **/
		return_code = SXFwrite_next_feature_AP202("POLYLINE",Polyline_str);
		/** スプラインデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		Spline_str->layer = 3;
		Spline_str->color = 9;
		Spline_str->type = 9;
		Spline_str->line_width = 9;
		Spline_str->open_close = 1;
		Spline_str->number = 4;
		d = 1.0;
		Spline_str->x.Add(d);
		d = 2.0;
		Spline_str->x.Add(d);
		d = 4.0;
		Spline_str->x.Add(d);
		d = 3.0;
		Spline_str->x.Add(d);
		d = 0.0;
		Spline_str->y.Add(d);
		d = -1.0;
		Spline_str->y.Add(d);
		d = 3.0;
		Spline_str->y.Add(d);
		d = 5.0;
		Spline_str->y.Add(d);
		/** スプライン出力 **/
		return_code = SXFwrite_next_feature_AP202("SPLINE",Spline_str);

		/** クロソイドデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		Clothoid_str->layer = 3;
		Clothoid_str->color = 9;
		Clothoid_str->type = 9;
		Clothoid_str->line_width = 9;
		Clothoid_str->base_x = 10.1234567890123;
		Clothoid_str->base_y = 20.0;
		Clothoid_str->parameter = 100.0;
		Clothoid_str->direction = 1;
		Clothoid_str->angle = 30.0;
		Clothoid_str->start_length = 0.0;
		Clothoid_str->end_length = 100.0;
		/** クロソイド出力 **/
		return_code = SXFwrite_next_feature_AP202("CLOTHOID",Clothoid_str);

		/** 直線寸法データ設定 **/
		/****** ここに要素の処理を記載 ******/
		LinearDim_str->layer = 3;
		LinearDim_str->color = 12;
		LinearDim_str->type = 12;
		LinearDim_str->line_width = 12;
		LinearDim_str->sun_x1 = 1.0;
		LinearDim_str->sun_y1 = 2.0;
		LinearDim_str->sun_x2 = 7.0;
		LinearDim_str->sun_y2 = 8.0;
		LinearDim_str->flg2 = 1;
		LinearDim_str->ho1_x0 = 2.0;
		LinearDim_str->ho1_y0 = 2.0;
		LinearDim_str->ho1_x1 = 2.0;
		LinearDim_str->ho1_y1 = 2.0;
		LinearDim_str->ho1_x2 = 2.0;
		LinearDim_str->ho1_y2 = 8.0;
		LinearDim_str->flg3 = 1;
		LinearDim_str->ho2_x0 = 7.0;
		LinearDim_str->ho2_y0 = 1.0;
		LinearDim_str->ho2_x1 = 7.0;
		LinearDim_str->ho2_y1 = 1.0;
		LinearDim_str->ho2_x2 = 7.0;
		LinearDim_str->ho2_y2 = 12.0;
		LinearDim_str->arr1_code1 = 9;
		LinearDim_str->arr1_code2 = 1;
		LinearDim_str->arr1_x = 1.0;
		LinearDim_str->arr1_y = 2.0;
		LinearDim_str->arr1_r = 3.0;
		LinearDim_str->arr2_code1 = 9;
		LinearDim_str->arr2_code2 = 1;
		LinearDim_str->arr2_x = 4.0;
		LinearDim_str->arr2_y = 5.0;
		LinearDim_str->arr2_r = 6.0;
		LinearDim_str->flg4 = 1;
		LinearDim_str->font = 1;
		strcpy(LinearDim_str->str,"lineardim");
		LinearDim_str->text_x = 1.3;
		LinearDim_str->text_y = -1.4;
		LinearDim_str->height = 3.2;
		LinearDim_str->width = 11.2;
		LinearDim_str->spc   = 0.8;
		LinearDim_str->angle = 0.0;
		LinearDim_str->slant = 0.0;
		LinearDim_str->b_pnt = 1;
		LinearDim_str->direct = 1;
		/** 直線寸法出力 **/
		return_code = SXFwrite_next_feature_AP202("LINEAR_DIMENSION",LinearDim_str);
		
		/** 弧長寸法データ設定 **/
		/****** ここに要素の処理を記載 ******/
		CurveDim_str->layer = 3;
		CurveDim_str->color = 13;
		CurveDim_str->type = 13;
		CurveDim_str->line_width = 13;
		CurveDim_str->sun_x = 0.0;
		CurveDim_str->sun_y = 0.0;
		CurveDim_str->sun_radius = 20.0;
		CurveDim_str->sun_angle0 = 0.0;
		CurveDim_str->sun_angle1 = 90.0;
		CurveDim_str->flg2 = 1;
		CurveDim_str->ho1_x0 = 0.0;
		CurveDim_str->ho1_y0 = 0.0;
		CurveDim_str->ho1_x1 = 0.0;
		CurveDim_str->ho1_y1 = 0.0;
		CurveDim_str->ho1_x2 = 20.0;
		CurveDim_str->ho1_y2 = 0.0;
		CurveDim_str->flg3 = 1;
		CurveDim_str->ho2_x0 = 0.0;
		CurveDim_str->ho2_y0 = 0.0;
		CurveDim_str->ho2_x1 = 0.0;
		CurveDim_str->ho2_y1 = 0.0;
		CurveDim_str->ho2_x2 = 0.0;
		CurveDim_str->ho2_y2 = 20.0;
		CurveDim_str->arr1_code1 = 9;
		CurveDim_str->arr1_code2 = 1;
		CurveDim_str->arr1_x = 20.0;
		CurveDim_str->arr1_y = 0.0;
		CurveDim_str->arr1_r = 0.5;
		CurveDim_str->arr2_code1 = 9;
		CurveDim_str->arr2_code2 = 1;
		CurveDim_str->arr2_x = 0.0;
		CurveDim_str->arr2_y = 20.0;
		CurveDim_str->arr2_r = 0.5;
		CurveDim_str->flg4 = 1;
		CurveDim_str->font = 1;
		strcpy(CurveDim_str->str,"curvedim");
		CurveDim_str->text_x = 1.3;
		CurveDim_str->text_y = -1.4;
		CurveDim_str->height = 3.2;
		CurveDim_str->width = 11.2;
		CurveDim_str->spc   = 0.8;
		CurveDim_str->angle = 0.0;
		CurveDim_str->slant = 0.0;
		CurveDim_str->b_pnt = 1;
		CurveDim_str->direct = 1;
		/** 弧長寸法出力 **/
		return_code = SXFwrite_next_feature_AP202("CURVE_DIMENSION",CurveDim_str);

		/** 角度寸法データ設定 **/
		/****** ここに要素の処理を記載 ******/
		AngularDim_str->layer = 3;
		AngularDim_str->color = 13;
		AngularDim_str->type = 13;
		AngularDim_str->line_width = 13;
		AngularDim_str->sun_x = 0.0;
		AngularDim_str->sun_y = 0.0;
		AngularDim_str->sun_radius = 20.0;
		AngularDim_str->sun_angle0 = 0.0;
		AngularDim_str->sun_angle1 = 90.0;
		AngularDim_str->flg2 = 1;
		AngularDim_str->ho1_x0 = 0.0;
		AngularDim_str->ho1_y0 = 0.0;
		AngularDim_str->ho1_x1 = 0.0;
		AngularDim_str->ho1_y1 = 0.0;
		AngularDim_str->ho1_x2 = 20.0;
		AngularDim_str->ho1_y2 = 0.0;
		AngularDim_str->flg3 = 1;
		AngularDim_str->ho2_x0 = 0.0;
		AngularDim_str->ho2_y0 = 0.0;
		AngularDim_str->ho2_x1 = 0.0;
		AngularDim_str->ho2_y1 = 0.0;
		AngularDim_str->ho2_x2 = 0.0;
		AngularDim_str->ho2_y2 = 20.0;
		AngularDim_str->arr1_code1 = 9;
		AngularDim_str->arr1_code2 = 1;
		AngularDim_str->arr1_x = 20.0;
		AngularDim_str->arr1_y = 0.0;
		AngularDim_str->arr1_r = 0.5;
		AngularDim_str->arr2_code1 = 9;
		AngularDim_str->arr2_code2 = 1;
		AngularDim_str->arr2_x = 0.0;
		AngularDim_str->arr2_y = 20.0;
		AngularDim_str->arr2_r = 0.5;
		AngularDim_str->flg4 = 1;
		AngularDim_str->font = 1;
		strcpy(AngularDim_str->str,"angulardim");
		AngularDim_str->text_x = 1.3;
		AngularDim_str->text_y = -1.4;
		AngularDim_str->height = 3.2;
		AngularDim_str->width = 11.2;
		AngularDim_str->spc   = 0.8;
		AngularDim_str->angle = 0.0;
		AngularDim_str->slant = 0.0;
		AngularDim_str->b_pnt = 1;
		AngularDim_str->direct = 1;
		/** 角度寸法出力 **/
		return_code = SXFwrite_next_feature_AP202("ANGULAR_DIMENSION",AngularDim_str);
		/** 直径寸法データ設定 **/
		/****** ここに要素の処理を記載 ******/
		DiameterDim_str->layer = 3;
		DiameterDim_str->color = 15;
		DiameterDim_str->type = 15;
		DiameterDim_str->line_width = 15;
		DiameterDim_str->sun_x1 = 1.0;
		DiameterDim_str->sun_y1 = 2.0;
		DiameterDim_str->sun_x2 = 7.0;
		DiameterDim_str->sun_y2 = 8.0;
		DiameterDim_str->arr1_code1 = 9;
		DiameterDim_str->arr1_code2 = 1;
		DiameterDim_str->arr1_x = 1.0;
		DiameterDim_str->arr1_y = 2.0;
		DiameterDim_str->arr1_r = 3.0;
		DiameterDim_str->arr2_code1 = 9;
		DiameterDim_str->arr2_code2 = 1;
		DiameterDim_str->arr2_x = 4.0;
		DiameterDim_str->arr2_y = 5.0;
		DiameterDim_str->arr2_r = 6.0;
		DiameterDim_str->flg = 1;
		DiameterDim_str->font = 1;
		strcpy(DiameterDim_str->str,"diameterdim");
		DiameterDim_str->text_x = 1.3;
		DiameterDim_str->text_y = -1.4;
		DiameterDim_str->height = 3.2;
		DiameterDim_str->width = 11.2;
		DiameterDim_str->spc   = 0.8;
		DiameterDim_str->angle = 0.0;
		DiameterDim_str->slant = 0.0;
		DiameterDim_str->b_pnt = 1;
		DiameterDim_str->direct = 1;
		/** 直径寸法出力 **/
		return_code = SXFwrite_next_feature_AP202("DIAMETER_DIMENSION",DiameterDim_str);
		/** 半径寸法データ設定 **/
		/****** ここに要素の処理を記載 ******/
		RadiusDim_str->layer = 3;
		RadiusDim_str->color = 14;
		RadiusDim_str->type = 14;
		RadiusDim_str->line_width = 14;
		RadiusDim_str->sun_x1 = 1.0;
		RadiusDim_str->sun_y1 = 2.0;
		RadiusDim_str->sun_x2 = 7.0;
		RadiusDim_str->sun_y2 = 8.0;
		RadiusDim_str->arr_code1 = 9;
		RadiusDim_str->arr_code2 = 1;
		RadiusDim_str->arr_x = 1.0;
		RadiusDim_str->arr_y = 2.0;
		RadiusDim_str->arr_r = 3.0;
		RadiusDim_str->flg = 1;
		RadiusDim_str->font = 1;
		strcpy(RadiusDim_str->str,"radiusdim");
		RadiusDim_str->text_x = 1.3;
		RadiusDim_str->text_y = -1.4;
		RadiusDim_str->height = 3.2;
		RadiusDim_str->width = 11.2;
		RadiusDim_str->spc   = 0.8;
		RadiusDim_str->angle = 0.0;
		RadiusDim_str->slant = 0.0;
		RadiusDim_str->b_pnt = 1;
		RadiusDim_str->direct = 1;
		/* 半径寸法出力 */
		return_code = SXFwrite_next_feature_AP202("RADIUS_DIMENSION",RadiusDim_str);
		/** 引出し線データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Label_str->layer = 1;
		Label_str->color = 16;
		Label_str->type = 17;
		Label_str->line_width = 1;
		Label_str->vertex_number = 2;
		d = 1.0;
		Label_str->vertex_x.Add(d);
		d = 3.0;
		Label_str->vertex_x.Add(d);
		d = 2.0;
		Label_str->vertex_y.Add(d);
		d = 4.0;
		Label_str->vertex_y.Add(d);
		Label_str->arr_code = 1;
		Label_str->arr_r = 3.0;
		Label_str->flg = 1;
		Label_str->font = 1;
		strcpy(Label_str->str,"label");
		Label_str->text_x = 1.3;
		Label_str->text_y = -1.4;
		Label_str->height = 3.2;
		Label_str->width = 11.2;
		Label_str->spc   = 0.8;
		Label_str->angle = 0.0;
		Label_str->slant = 0.0;
		Label_str->b_pnt = 1;
		Label_str->direct = 1;
		/** 引出し線出力 **/
		return_code = SXFwrite_next_feature_AP202("LABEL",Label_str);
		/** バルーンデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		Balloon_str->layer = 1;
		Balloon_str->color = 17;
		Balloon_str->type = 17;
		Balloon_str->line_width = 8;
		Balloon_str->vertex_number = 2;
		d = 1.0;
		Balloon_str->vertex_x.Add(d);
		d = 3.0;
		Balloon_str->vertex_x.Add(d);
		d = 2.0;
		Balloon_str->vertex_y.Add(d);
		d = 4.0;
		Balloon_str->vertex_y.Add(d);
		Balloon_str->center_x = 0.0;
		Balloon_str->center_y = 0.0;
		Balloon_str->radius = 10.0;
		Balloon_str->arr_code = 4;
		Balloon_str->arr_r = 3.0;
		Balloon_str->flg = 1;
		Balloon_str->font = 1;
		strcpy(Balloon_str->str,"balloon");
		Balloon_str->text_x = 1.3;
		Balloon_str->text_y = -1.4;
		Balloon_str->height = 3.2;
		Balloon_str->width = 11.2;
		Balloon_str->spc   = 0.8;
		Balloon_str->angle = 0.0;
		Balloon_str->slant = 0.0;
		Balloon_str->b_pnt = 1;
		Balloon_str->direct = 1;
		/** バルーン出力 **/
		return_code = SXFwrite_next_feature_AP202("BALLOON",Balloon_str);
		/** 既定義シンボルデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		ExSymbol_str->layer = 1;
		ExSymbol_str->color_flag = 1;
		ExSymbol_str->color = 11;
		strcpy(ExSymbol_str->name, "40201050100000&&a0010010");
		ExSymbol_str->start_x = 1.3;
		ExSymbol_str->start_y = -1.4;
		ExSymbol_str->rotate_angle = 0.0;
		ExSymbol_str->scale = 1.0;
		/** 既定義シンボル出力 **/
		return_code = SXFwrite_next_feature_AP202("EXTERNALLY_DEFINED_SYMBOL",ExSymbol_str);

		/** 外部定義ハッチデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		ExHatch_str->layer = 2;
		strcpy(ExHatch_str->name, "sxf_hatch_style_1");
		ExHatch_str->out_id = curve;
		ExHatch_str->number = 1;
		ExHatch_str->in_id.Add(curve2);
		/** 外部定義ハッチ出力 **/
		return_code = SXFwrite_next_feature_AP202("EXTERNALLY_DEFINED_HATCH",ExHatch_str);

		/** ハッチング(塗り)データ設定 **/
		/****** ここに要素の処理を記載 ******/
		FillColour_str->layer = 2;
		FillColour_str->color = 19;
		FillColour_str->out_id = curve;
		FillColour_str->number = 1;
		FillColour_str->in_id.Add(curve2);
		/** ハッチング(塗り)出力 **/
		return_code = SXFwrite_next_feature_AP202("FILL_AREA_STYLE_COLOUR",FillColour_str);

		/** ユーザ定義ハッチデータ設定 **/
		/****** ここに要素の処理を記載 ******/
		FillHatching_str->layer = 3;
		FillHatching_str->hatch_number = 2;
		FillHatching_str->hatch_color[0] = 1;
		FillHatching_str->hatch_type[0] = 3;
		FillHatching_str->hatch_line_width[0] = 2;
		FillHatching_str->hatch_start_x[0] = 11.0;
		FillHatching_str->hatch_start_y[0] = 12.0;
		FillHatching_str->hatch_spacing[0] = 5.0;
		FillHatching_str->hatch_angle[0] = 60.0;
		FillHatching_str->hatch_color[1] = 10;
		FillHatching_str->hatch_type[1] = 1;
		FillHatching_str->hatch_line_width[1] = 11;
		FillHatching_str->hatch_start_x[1] = 1.0;
		FillHatching_str->hatch_start_y[1] = 2.0;
		FillHatching_str->hatch_spacing[1] = 5.0;
		FillHatching_str->hatch_angle[1] = 30.0;
		FillHatching_str->out_id = curve;
		FillHatching_str->number = 1;
		FillHatching_str->in_id.Add(curve2);
		/** ユーザ定義ハッチ出力 **/
		return_code = SXFwrite_next_feature_AP202("FILL_AREA_STYLE_HATCHING",FillHatching_str);
		/** ハッチング(パターン)データ設定 **/
		/****** ここに要素の処理を記載 ******/
		FillTiles_str->layer = 3;
		strcpy(FillTiles_str->name,"40201050100000&&a0010010");
		FillTiles_str->hatch_color = 18;
		FillTiles_str->hatch_pattern_x = 11.0;
		FillTiles_str->hatch_pattern_y = 12.0;
		FillTiles_str->hatch_pattern_vector1 = 13.0;
		FillTiles_str->hatch_pattern_vector1_angle = 30.0;
		FillTiles_str->hatch_pattern_vector2 = 15.0;
		FillTiles_str->hatch_pattern_vector2_angle = 60.0;
		FillTiles_str->hatch_pattern_scale_x = 1.0;
		FillTiles_str->hatch_pattern_scale_y = 1.0;
		FillTiles_str->hatch_pattern_angle = 45.0;
		FillTiles_str->out_id = curve;
		FillTiles_str->number = 1;
		FillTiles_str->in_id.Add(curve2);
		/** ハッチング(パターン)出力 **/
		return_code = SXFwrite_next_feature_AP202("FILL_AREA_STYLE_TILES",FillTiles_str);

		/*********************************************/
		/********* アセンブリ要素出力テスト **********/
		/*********************************************/
		/****** 用紙データ設定 ******/
		/****** ここに要素の処理を記載 ******/
		strcpy(Sheet_str->name,"sheet");
		Sheet_str->type = 9;
		Sheet_str->orient = 1;
		Sheet_str->x = 100;
		Sheet_str->y = 300;
		/** 用紙出力 **/
		return_code = SXFwrite_assembly_name_AP202(1,Sheet_str);

		/**************************/
		/*** 一般要素出力テスト ***/
		/**************************/

		/** 円弧データ出力 **/
		/****** ここに要素の処理を記載 ******/
		Arc_str->layer = 2;
		Arc_str->color = 5;
		Arc_str->type = 5;
		Arc_str->line_width = 5;
		Arc_str->center_x = 0.0;
		Arc_str->center_y = 0.0;
		Arc_str->radius = 10.0;
		Arc_str->direction = 0;
		Arc_str->start_angle = 0.0;
		Arc_str->end_angle = 90.0;
		/** 円弧出力 **/
		return_code = SXFwrite_next_feature_AP202("ARC",Arc_str);
		/** 楕円弧データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Ellipse_Arc_str->layer = 3;
		Ellipse_Arc_str->color = 7;
		Ellipse_Arc_str->type = 7;
		Ellipse_Arc_str->line_width = 7;
		Ellipse_Arc_str->center_x = 0.0;
		Ellipse_Arc_str->center_y = 0.0;
		Ellipse_Arc_str->radius_x = 10.0;
		Ellipse_Arc_str->radius_y = 20.0;
		Ellipse_Arc_str->direction = 1;
		Ellipse_Arc_str->rotation_angle = 0.0;
		Ellipse_Arc_str->start_angle = 0.0;
		Ellipse_Arc_str->end_angle = 90.0;
		/** 楕円弧出力 **/
		return_code = SXFwrite_next_feature_AP202("ELLIPSE_ARC",Ellipse_Arc_str);
		/** 線分データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Line_str->layer = 1;
		Line_str->color = 18;
		Line_str->type = 18;
		Line_str->line_width = 1;
		Line_str->start_x = 0.0;
		Line_str->start_y = 0.0;
		Line_str->end_x = -10.0;
		Line_str->end_y = -10.0;
		/** 線分出力 **/
		return_code = SXFwrite_next_feature_AP202("LINE",Line_str);
		/** 円データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Circle_str->layer = 3;
		Circle_str->color = 4;
		Circle_str->type = 4;
		Circle_str->line_width = 4;
		Circle_str->center_x = 0.0;
		Circle_str->center_y = 0.0;
		Circle_str->radius = 10.0;
		/** 円出力 **/
		return_code = SXFwrite_next_feature_AP202("CIRCLE",Circle_str);
		/** 複合図形配置データ設定 **/
		/****** ここに要素の処理を記載 ******/
		Sfigloc_str->layer = 0;
		strcpy(Sfigloc_str->name,"sfig2");
		Sfigloc_str->x = 0.0;
		Sfigloc_str->y = 0.0;
		Sfigloc_str->angle = 0.0;
		Sfigloc_str->ratio_x = 1.0;
		Sfigloc_str->ratio_y = 1.0;
		/** 複合図形配置出力 **/
		return_code = SXFwrite_next_feature_AP202("SFIG_LOCATE",Sfigloc_str);
		/***********************************/
		/****** STEPファイルクローズ *******/
		/***********************************/
		if (SXFclose_AP202() < 0){
			//エラー問い合わせ
			SXFPopMsg_AP202(name,&msgno,text);
			cout << name << " : " << msgno << " : " << text << endl << endl;
			msgno = 0;
			name = "";
			text = "";
			return ;
		}

		/***************************************************/
		/******************* 構造体の削除 ******************/
		/***************************************************/
		/********************************/
		/***** アセンブリ要素の定義 *****/
		/********************************/
		delete Sheet_str;
		delete Sfigorg_str;
		delete Ccurve_str;
		/********************************/
		/**** 定義テーブル要素の定義 ****/
		/********************************/
		delete layer_str;
		delete predefcolor_str;
		delete userdefcolor_str;
		delete predeffont_str;
		delete userdeffont_str;
		delete width_str;
		delete textfont_str;
		/********************************/
		/******** 一般要素の定義 ********/
		/********************************/
		delete (Polyline_Struct*)Polyline_str;
		delete (Spline_Struct*)Spline_str;
		delete (Clothoid_Struct*)Clothoid_str;
		delete (Label_Struct*)Label_str;
		delete (Balloon_Struct*)Balloon_str;
		delete (Externally_Defined_Hatch_Struct*)ExHatch_str;
		delete (Fill_area_style_colour_Struct*)FillColour_str;
		delete (Fill_area_style_hatching_Struct*)FillHatching_str;
		delete (Fill_area_style_tiles_Struct*)FillTiles_str;
		delete Attribute_str;
		delete PointMarker_str;
		delete Line_str;
		delete Circle_str;
		delete Arc_str;
		delete Ellipse_str;
		delete Ellipse_Arc_str;
		delete Text_str;
		delete Sfigloc_str;
		delete ExSymbol_str;
		delete LinearDim_str;
		delete CurveDim_str;
		delete AngularDim_str;
		delete RadiusDim_str;
		delete DiameterDim_str;

	}
	else
		return ;

	return ;
}