#include "gameLost.h"
#include "game.h"
#include "menu.h"

void gameLost()
{
	//Initialise screen width and height
	const int screenHeight = 975;
	const int screenWidth = 1920;

	//Declare photo as texture
	Texture2D sadAstronaut = LoadTexture("../images/sadAstronaut.png");

	//Declare button boxes
	Rectangle tryAgain = { GetScreenWidth() / 2 - 600, GetScreenHeight() / 2 - 10, 300, 90 };
	Rectangle exitButton = { GetScreenWidth() / 2 + 250, GetScreenHeight() / 2 - 10, 300, 90 };
	
	Vector2 mousePosition;
	EnableCursor();
	SetTargetFPS(240);
	while (!WindowShouldClose())
	{
		
		mousePosition = GetMousePosition();

		BeginDrawing();

		//Display background color
		ClearBackground({ 0, 1, 41, 255 });

		//Draw photo texture
		DrawTexture(sadAstronaut, 700, 400, RAYWHITE);

		DrawText("Game over! You lost!", 580, 150, 80, WHITE); //Game lost

		//Check if "Try again" button is pressed
		bool isMouseOverTryAgain = CheckCollisionPointRec(mousePosition, tryAgain);

		DrawRectangleRec(tryAgain, (isMouseOverTryAgain ? RED : PURPLE));
		DrawText("Try Again", screenWidth / 2 - 575, screenHeight / 2 + 10, 50, WHITE);
		if (isMouseOverTryAgain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			game();
		}

		//Check if "Exit game" button is pressed
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