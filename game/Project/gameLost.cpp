#include "gameLost.h"
#include "game.h"
#include "menu.h"

void gameLost()
{
	const int screenHeight = 975;
	const int screenWidth = 1920;

	Rectangle tryAgain = { GetScreenWidth() / 2 - 600, GetScreenHeight() / 2 - 10, 300, 90 };
	Rectangle exitButton = { GetScreenWidth() / 2 + 250, GetScreenHeight() / 2 - 10, 300, 90 };
	
	Vector2 mousePosition;
	EnableCursor();
	SetTargetFPS(240);
	while (!WindowShouldClose())
	{
		
		mousePosition = GetMousePosition();

		BeginDrawing();

		DrawText("Game over! You lost!", 580, 50, 80, WHITE);
		ClearBackground(DARKBLUE);

		bool isMouseOverTryAgain = CheckCollisionPointRec(mousePosition, tryAgain);

		DrawRectangleRec(tryAgain, (isMouseOverTryAgain ? ORANGE : GRAY));
		DrawText("Try Again", screenWidth / 2 - 575, screenHeight / 2 + 10, 50, BLACK);
		if (isMouseOverTryAgain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			game();
		}

		bool isMouseOverExitGame = CheckCollisionPointRec(mousePosition, exitButton);

		DrawRectangleRec(exitButton, (isMouseOverExitGame ? ORANGE : GRAY));
		DrawText("Exit Game", screenWidth / 2 + 275, screenHeight / 2 + 10, 50, BLACK);
		if (isMouseOverExitGame && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			CloseWindow();
		}


		EndDrawing();
	}
}