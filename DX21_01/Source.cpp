//=======================================================
//DX21
//�E�B���h�E�\������
//=======================================================
#include<windows.h>

//**********
//�}�N����`
//**********
#define CLASS_NAME   "�T���v��"                 //�E�B���h�E�N���X�̖��O
#define WINDOW_NAME  "�X�P���g���v���O����"     //�E�B���h�E�̖��O

#define SCREEN_WIDTH  (640)                     //�E�B���h�E�̕�
#define SCREEN_HEIGHT (480)                     //�E�B���h�E�̍���

//****************
//�v���g�^�C�v�錾
//****************

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//**************
//�O���[�o���ϐ�
//**************


//===================================================================
//���C���֐�
//  (WINAPI        :Win32API�֐����Ăяo���Ƃ��̋K��
//�@hInstance     :���̃A�v���P�[�V�����̃C���X�^���X�n���h��(���ʎq)
//�@hPrevInstance :���NULL(�̂̎d�l�̖��c��)
//�@lpCmdLine     :�R�}���h���C������󂯎���������ւ̃|�C���^
//  nCmdShow      :�A�v���P�[�V�����̏����E�B���h�E�̕\�����@�̎w��
//===================================================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),          //WNDCLASSEX�̃������T�C�Y�w��
		CS_CLASSDC,                  //�\������E�B���h�E�̃X�^�C����ݒ�
		WndProc,                     //�E�B���h�E�v���V�[�W���̃A�h���X(�֐���)���w��
		0,                           //�ʏ�͎g�p���Ȃ��̂�"0"���w��
		0,                           //�ʏ�͎g�p���Ȃ��̂�"0"���w��
		hInstance,                   //WinMain�̃p�����[�^�̃C���X�^���X�n���h����ݒ�
		NULL,                        //�g�p����A�C�R�����w��(���Ɏw�肵�Ȃ��Ȃ�NULL)
		LoadCursor(NULL,IDC_ARROW),  //�}�E�X�J�[�\�����w��
		(HBRUSH)(COLOR_WINDOW + 1),  //�E�B���h�E�̃N���C�A���g�̈�̔w�i�F��ݒ�
		NULL,                        //Window�ɂ��郁�j���[�̐ݒ�
		CLASS_NAME,                  //�E�B���h�E�N���X�̖��O
		NULL                         //�������A�C�R�����ݒ肳�ꂽ�ꍇ�̏����L�q
	};

	HWND hWnd;
	MSG msg;

	//�E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	//�E�B���h�E���쐬
	hWnd = CreateWindowEx(0,    //�g���E�B���h�E�X�^�C��
		CLASS_NAME,             //�E�B���h�E�N���X�̖��O
		WINDOW_NAME,            //�E�B���h�E�̖��O
		WS_OVERLAPPEDWINDOW,    //�E�B���h�E�̃X�^�C��
		CW_USEDEFAULT,          //�E�B���h�E�̍���X���W
		CW_USEDEFAULT,          //�E�B���h�E�̍���Y���W
		SCREEN_WIDTH,           //�E�B���h�E�̕�
		SCREEN_HEIGHT,          //�E�B���h�E�̍���
		NULL,                   //�e�E�B���h�E�̃n���h��
		NULL,                   //���j���[�n���h���܂��͎q�E�B���h�EID
		hInstance,              //�C���X�^���X�n���h��
		NULL);                 //�E�B���h�E�쐬�f�[�^

	//�E�B���h�E�\��
	ShowWindow(hWnd, nCmdShow);      //�w�肳�ꂽ�E�B���h�E�̕\����Ԃ�ݒ�(�E�B���h�E��\��)
	UpdateWindow(hWnd);              //�E�B���h�E�̏�Ԃ𒼂��ɔ��f(�N���C�A���g�̈���X�V)

	//���b�Z�[�W���[�v
	//��1����:���b�Z�[�W���
	//��2����:�E�B���h�E�̃n���h��
	//��3����:�ŏ��̃��b�Z�[�W
	//��4����:�Ō�̃��b�Z�[�W
	while (GetMessage(&msg, NULL, 0, 0) != 0)    //"WM_QUIT"���b�Z�[�W���擾�����ꍇ"0"��Ԃ�
	{                                 //�Ăяo�����̃X���b�h�̃��b�Z�[�W�L���[���擾���Ă��烁�b�Z�[�W���擾
		//���b�Z�[�W�̖|��Ƒ��o
		TranslateMessage(&msg);       //���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�
		DispatchMessage(&msg);        //�E�B���h�E�v���V�[�W���փ��b�Z�[�W�𑗏o
	}

	//�E�B���h�E�N���X�̓o�^������
	//��1����:�N���X��
	//��2����;�A�v���P�[�V�����C���X�^���X�̃n���h��
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	return(int)msg.wParam;
}

//=================================================
//�E�B���h�E�v���V�[�W��
// (CALLBACK :Win32API�֐����Ăяo���Ƃ��̋K��)
// hWnd      :�E�B���h�E�̃n���h��
// uMsg      :���b�Z�[�W�̎��ʎq
// wParamm   :���b�Z�[�W�ŏ��̃p�����[�^
// lParam    :���b�Z�[�W��Ԗڂ̃p�����[�^
//=================================================

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:            //�E�B���h�E�j���̃��b�Z�[�W
		PostQuitMessage(0);     //"WMQUIT"���b�Z�[�W��Ԃ�
		break;

	case WM_KEYDOWN:            //�����̃L�[�������ꂽ���b�Z�[�W

		switch(wParam)          //�L�[�̎�ނŕ���
		{
		case VK_ESCAPE:         //�G�X�P�[�v�L�[
			int res = MessageBox(NULL, "�I�����܂�", "�m�F", MB_OKCANCEL | MB_ICONWARNING);
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

	return DefWindowProc(hWnd, uMsg, wParam, lParam);   //����̏������
}