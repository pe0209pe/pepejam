//=======================================================
//DX21
//ウィンドウ表示処理
//=======================================================
#include<windows.h>

//**********
//マクロ定義
//**********
#define CLASS_NAME   "サンプル"                 //ウィンドウクラスの名前
#define WINDOW_NAME  "スケルトンプログラム"     //ウィンドウの名前

#define SCREEN_WIDTH  (640)                     //ウィンドウの幅
#define SCREEN_HEIGHT (480)                     //ウィンドウの高さ

//****************
//プロトタイプ宣言
//****************

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//**************
//グローバル変数
//**************


//===================================================================
//メイン関数
//  (WINAPI        :Win32API関数を呼び出すときの規約
//　hInstance     :このアプリケーションのインスタンスハンドル(識別子)
//　hPrevInstance :常にNULL(昔の仕様の名残り)
//　lpCmdLine     :コマンドラインから受け取った引数へのポインタ
//  nCmdShow      :アプリケーションの初期ウィンドウの表示方法の指定
//===================================================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),          //WNDCLASSEXのメモリサイズ指定
		CS_CLASSDC,                  //表示するウィンドウのスタイルを設定
		WndProc,                     //ウィンドウプロシージャのアドレス(関数名)を指定
		0,                           //通常は使用しないので"0"を指定
		0,                           //通常は使用しないので"0"を指定
		hInstance,                   //WinMainのパラメータのインスタンスハンドルを設定
		NULL,                        //使用するアイコンを指定(特に指定しないならNULL)
		LoadCursor(NULL,IDC_ARROW),  //マウスカーソルを指定
		(HBRUSH)(COLOR_WINDOW + 1),  //ウィンドウのクライアント領域の背景色を設定
		NULL,                        //Windowにつけるメニューの設定
		CLASS_NAME,                  //ウィンドウクラスの名前
		NULL                         //小さいアイコンが設定された場合の情報を記述
	};

	HWND hWnd;
	MSG msg;

	//ウィンドウクラスの登録
	RegisterClassEx(&wcex);

	//ウィンドウを作成
	hWnd = CreateWindowEx(0,    //拡張ウィンドウスタイル
		CLASS_NAME,             //ウィンドウクラスの名前
		WINDOW_NAME,            //ウィンドウの名前
		WS_OVERLAPPEDWINDOW,    //ウィンドウのスタイル
		CW_USEDEFAULT,          //ウィンドウの左上X座標
		CW_USEDEFAULT,          //ウィンドウの左上Y座標
		SCREEN_WIDTH,           //ウィンドウの幅
		SCREEN_HEIGHT,          //ウィンドウの高さ
		NULL,                   //親ウィンドウのハンドル
		NULL,                   //メニューハンドルまたは子ウィンドウID
		hInstance,              //インスタンスハンドル
		NULL);                 //ウィンドウ作成データ

	//ウィンドウ表示
	ShowWindow(hWnd, nCmdShow);      //指定されたウィンドウの表示状態を設定(ウィンドウを表示)
	UpdateWindow(hWnd);              //ウィンドウの状態を直ちに反映(クライアント領域を更新)

	//メッセージループ
	//第1引数:メッセージ情報
	//第2引数:ウィンドウのハンドル
	//第3引数:最初のメッセージ
	//第4引数:最後のメッセージ
	while (GetMessage(&msg, NULL, 0, 0) != 0)    //"WM_QUIT"メッセージを取得した場合"0"を返す
	{                                 //呼び出し側のスレッドのメッセージキューを取得してからメッセージを取得
		//メッセージの翻訳と送出
		TranslateMessage(&msg);       //仮想キーメッセージを文字メッセージへ変換
		DispatchMessage(&msg);        //ウィンドウプロシージャへメッセージを送出
	}

	//ウィンドウクラスの登録を解除
	//第1引数:クラス名
	//第2引数;アプリケーションインスタンスのハンドル
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return(int)msg.wParam;
}

//=================================================
//ウィンドウプロシージャ
// (CALLBACK :Win32API関数を呼び出すときの規約)
// hWnd      :ウィンドウのハンドル
// uMsg      :メッセージの識別子
// wParamm   :メッセージ最初のパラメータ
// lParam    :メッセージ二番目のパラメータ
//=================================================

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:            //ウィンドウ破棄のメッセージ
		PostQuitMessage(0);     //"WMQUIT"メッセージを返す
		break;

	case WM_KEYDOWN:            //何かのキーが押されたメッセージ

		switch(wParam)          //キーの種類で分岐
		{
		case VK_ESCAPE:         //エスケープキー
			int res = MessageBox(NULL, "終了します", "確認", MB_OKCANCEL | MB_ICONWARNING);
			if (res == IDOK) 
			{
				DestroyWindow(hWnd);
			}
			else {
				return 0;
			}
			break;
		}
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);   //既定の処理を提供
}