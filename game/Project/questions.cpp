#include "questions.h"
#include "variables.h"

string currentQuestion = "";
void removeQuestion()
{
	for (int i = 0; i < 24; i++)
	{
		if (questionsArr[i] == currentQuestion)
		{
			questionsLength -= 1;
			for (int j = i; j < questionsLength; j++)
			{
				questionsArr[j] = questionsArr[j + 1];
				answers[j] = answers[j + 1];
			}

		}
	}
}
void questions(string currentQuestion)
{
	random_device(rd);
	uniform_int_distribution<int> dist(0, (questionsLength > 1) ? questionsLength - 1 : 1);
	currentQuestion = questionsArr[dist(rd)];
}
bool checkAnswer(string answer)
{
	for (int i = 0; i < questionsLength; i++)
	{
		if (questionsArr[i] == currentQuestion && answers[i] == answer)
		{
			return true;
		}

	}
	return false;
}
void questions() {

	bool isAnswerTrue = false;
	
	char name[20] = "\0";
	int letterCount = 0;

	Rectangle textBox = { GetScreenWidth() / 2 - 100, 500, 340, 100 };
	bool mouseOnText = false;

	int framesCounter = 0;

	Rectangle submitRec = { GetScreenWidth() / 2 - 115,700, 500, 300};

	const int screenWidth = 1000;
	const int screenHeight = 1000;
	
	bool exitGame = WindowShouldClose();

    string currentQuestion = questionsArr[GetRandomValue(0, 17)];
 
    Texture2D thinkingAlien = LoadTexture("../images/thinkingAlien.png");


    EnableCursor();
	while (!WindowShouldClose())
	{
        
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            int key = GetCharPressed();

            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (letterCount < 20))
                {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0';
                    letterCount++;
                }

                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
       /* if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, submitRec))
        {
            for (int i = 0; i < letterCount; i++)
            {
                if (name[i] == 'H' && name[i + 1] == '2' && name[i + 2] == 'O')
                {
                    gameWon();
                }
                else
                {
                    gameOver();
                }
            }
        }*/
        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });
        DrawTexture(thinkingAlien, 1400, 400, RAYWHITE);

        DrawText(currentQuestion.c_str(), (float)GetScreenWidth() / 2 - MeasureText(currentQuestion.c_str(), 40) / 2 - 100, (float)GetScreenHeight() / 2 - 200, 40, WHITE);
       
        DrawRectangleRec(textBox, RAYWHITE);
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, { 0, 91, 241, 255 });
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, { 0, 91, 241, 255 });

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, GREEN);
       
        EndDrawing();
    }
}