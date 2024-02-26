#include "gameWon.h"
#include "game.h"

void gameWon()
{
	const int screenHeight = 975;
	const int screenWidth = 1920;

	Rectangle playAgain = { GetScreenWidth() / 2 - 770, GetScreenHeight() / 2 + 240, 320, 90 };
	Rectangle exitButton = { GetScreenWidth() / 2 + 470, GetScreenHeight() / 2 + 240, 320, 90 };

	Vector2 mousePosition;
	EnableCursor();
	SetTargetFPS(240);
	while (!WindowShouldClose())
	{

		mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground({ 0, 1, 41, 255 });
		DrawText("Congratulations! You won!", 490, 150, 80, WHITE);
		bool isMouseOverPlayAgain = CheckCollisionPointRec(mousePosition, playAgain);

		DrawRectangleRec(playAgain, (isMouseOverPlayAgain ? RED : PURPLE));
		DrawText("Play Again", screenWidth / 2 - 740, screenHeight / 2 + 260, 50, WHITE);
		if (isMouseOverPlayAgain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			game();
		}

		bool isMouseOverExitGame = CheckCollisionPointRec(mousePosition, exitButton);

		DrawRectangleRec(exitButton, (isMouseOverExitGame ? RED : PURPLE));
		DrawText("Exit Game", screenWidth / 2 + 510, screenHeight / 2 + 260, 50, WHITE);
		if (isMouseOverExitGame && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			CloseWindow();
		}


		EndDrawing();
	}
}
