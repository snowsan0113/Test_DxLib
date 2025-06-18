#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(TRUE);
	SetMainWindowText("DxLibのテストテストテストテスト");
	if (DxLib_Init() == -1)	{
		return -1;
	}

	bool cmd_mode = false;
	int mouseX = 0, mouseY = 0;
	int circleX = 0, circleY = 0;
	while (true) {
		ClearDrawScreen();
		GetMousePoint(&mouseX, &mouseY);

		DrawFormatString(400,400, GetColor(255, 255, 255), "（%d, %d）", mouseX, mouseY);

		if (CheckHitKey(KEY_INPUT_SLASH) == 1) {
			cmd_mode = true;
		}

		if (circleX == 0 && circleY == 0) {
			circleX = mouseX;
			circleY = mouseY;
		}
		if (CheckHitKey(KEY_INPUT_UP)) circleY -= 1;
		if (CheckHitKey(KEY_INPUT_DOWN)) circleY += 1;
		if (CheckHitKey(KEY_INPUT_LEFT)) circleX -= 1;
		if (CheckHitKey(KEY_INPUT_RIGHT)) circleX += 1;

		DrawCircle(circleX, circleY, 10, GetColor(255, 255, 255));
		DrawFormatString(400, 420, GetColor(255, 0, 0), "図形：（%d, %d）", circleX, circleY);

		ScreenFlip();

		//終了する
		if (cmd_mode) {
			DxLib_End();
			break;
			return 0;

			if (ProcessMessage() == -1) {
				break;      
			}
		}
	}
}