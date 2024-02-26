#include "gameWon.h"
#include "game.h"

void gameWon()
{
	//Initialise screen width and height
	const int screenHeight = 975;
	const int screenWidth = 1920;

	//Declare background photo as texture
	Texture2D background = LoadTexture("../images/wonGameBg.png");
	Texture2D spacecraft = LoadTexture("../images/spacecraft.png");

	//Declare button boxes
	Rectangle playAgain = { GetScreenWidth() / 2 - 770, GetScreenHeight() / 2 + 300, 320, 90 };
	Rectangle exitButton = { GetScreenWidth() / 2 + 470, GetScreenHeight() / 2 + 300, 320, 90 };

	Vector2 mousePosition;

	EnableCursor();
	SetTargetFPS(240);
	while (!WindowShouldClose())
	{
		mousePosition = GetMousePosition();

		BeginDrawing();

		//Display background 
		DrawTexture(background, 0, 0, RAYWHITE);
		DrawTexture(spacecraft, GetScreenWidth() / 2, GetScreenHeight() / 2 - 70, RAYWHITE);

		DrawText("Congratulations! You won!", 470, 280, 80, RED); //Game won

		//Check if "Play again" button is pressed
		bool isMouseOverPlayAgain = CheckCollisionPointRec(mousePosition, playAgain);

		DrawRectangleRec(playAgain, (isMouseOverPlayAgain ? RED : LIGHTGRAY));
		DrawText("Play Again", screenWidth / 2 - 740, screenHeight / 2 + 320, 50, WHITE);
		if (isMouseOverPlayAgain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			game();
		}


		//Check if "Exit game" button is pressed
		bool isMouseOverExitGame = CheckCollisionPointRec(mousePosition, exitButton);

		DrawRectangleRec(exitButton, (isMouseOverExitGame ? RED : LIGHTGRAY));
		DrawText("Exit Game", screenWidth / 2 + 510, screenHeight / 2 + 320, 50, WHITE);
		if (isMouseOverExitGame && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			CloseWindow();
		}


		EndDrawing();
	}
}
