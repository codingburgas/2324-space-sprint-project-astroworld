#include "gameLost.h"
#include "game.h"
#include "menu.h"

void gameLost()
{
	const int screenHeight = 975;
	const int screenWidth = 1920;

	Texture2D sadAstronaut = LoadTexture("../images/sadAstronaut.png");

	Rectangle tryAgain = { GetScreenWidth() / 2 - 600, GetScreenHeight() / 2 - 10, 300, 90 };
	Rectangle exitButton = { GetScreenWidth() / 2 + 250, GetScreenHeight() / 2 - 10, 300, 90 };
	
	Vector2 mousePosition;
	EnableCursor();
	SetTargetFPS(240);
	while (!WindowShouldClose())
	{
		
		mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground({ 0, 1, 41, 255 });
		DrawTexture(sadAstronaut, 700, 400, RAYWHITE);
		DrawText("Game over! You lost!", 580, 150, 80, WHITE);

		bool isMouseOverTryAgain = CheckCollisionPointRec(mousePosition, tryAgain);

		DrawRectangleRec(tryAgain, (isMouseOverTryAgain ? RED : PURPLE));
		DrawText("Try Again", screenWidth / 2 - 575, screenHeight / 2 + 10, 50, WHITE);
		if (isMouseOverTryAgain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			game();
		}

		bool isMouseOverExitGame = CheckCollisionPointRec(mousePosition, exitButton);

		DrawRectangleRec(exitButton, (isMouseOverExitGame ? RED : PURPLE));
		DrawText("Exit Game", screenWidth / 2 + 275, screenHeight / 2 + 10, 50, WHITE);
		if (isMouseOverExitGame && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			CloseWindow();
		}


		EndDrawing();
	}
}