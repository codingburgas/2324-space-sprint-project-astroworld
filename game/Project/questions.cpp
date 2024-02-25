#include "questions.h"
#include "variables.h"


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

void trueAnswer() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Correct", 500, 500, 50, GREEN);
        EndDrawing();
    }

}

void wrongAnswer() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Incorrect", 500, 500, 50, RED);
        EndDrawing();
    }
}

void questions() {

    char name[20] = "\0";
    int letterCount = 0;

    Rectangle textBox = { GetScreenWidth() / 2 - 100, 500, 340, 100 };
    bool mouseOnText = false;

    int framesCounter = 0;

    Rectangle submitRec = { GetScreenWidth() / 2 - 115, 600, 210, 100 };

    const int screenWidth = 1000;
    const int screenHeight = 1000;

    bool exitGame = WindowShouldClose();

    string currentQuestion = questionsArr[GetRandomValue(0, 17)];

    Texture2D thinkingAlien = LoadTexture("../images/thinkingAlien.png");

    /*const Rectangle firstButton = { (screenWidth / 2) - 300, (screenHeight / 2) - 150, 270, 90 };
    const Rectangle secondButton = { (screenWidth / 2) + 10, (screenHeight / 2) - 150, 270, 90 };
    const Rectangle thirdButton = { (screenWidth / 2) + 310, (screenHeight / 2) - 150, 270, 90 }*/

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

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, submitRec))
        {
            for (int i = 0; i < letterCount; i++)
            {
                if (currentQuestion == "How many constellations are there? \n a. 88 \n b. 39 \n c. 120" && name[i] == 'a' ||
                    currentQuestion == "How long does each season last on Neptune? \n a. 3 months \n b. 30 weeks \n c. more than 40 years" && name[i] == 'c' ||
                    currentQuestion == "How many minutes was the shortest space flight? \n a. 1 hour \n b. 15 minutes \n c. 3 days" && name[i] == 'b' ||
                    currentQuestion == "What is the only planet not named after a God? \n a. Earth \n b. Mars \n c. Venus" && name[i] == 'a' ||
                    currentQuestion == "The first manned space mission to land on the Moon was called what? \n a. Apollo 17 \n b. Apollo 14 \n c. Apollo 11" && name[i] == 'c' ||
                    currentQuestion == "What planet is nicknamed the 'Red Planet'? \n a. Mars \n b. Saturn \n c. Mercury" && name[i] == 'a' ||
                    currentQuestion == "How long does it take to get to the moon from Earth in a space shuttle? \n a. 3 days \n b. 1 hour \n c. 5 hours" && name[i] == 'a' ||
                    currentQuestion == "Which constellation takes its name from the Latin word for 'twins'? \n a. Libra \n b. Gemini \n c. Cancer" && name[i] == 'b' ||
                    currentQuestion == "How many space shuttles actually flew in space? \n a. Three \n b. Eighteen \n c. Five" && name[i] == 'c' ||
                    currentQuestion == "Neptune has the fastest winds of any solar system planet what speeds do they reach? \n a. 1,000 mph \n b. 1,300 mph \n c. 6,500 mph" && name[i] == 'b' ||
                    currentQuestion == "Which constellation holds the hottest place in the universe? \n a. Virgo \n b. Orion \n c. Draco" && name[i] == 'a' ||
                    currentQuestion == "Apollo 11 landed in which ocean upon completion of their moon landing mission? \n a. Atlantic \n b. Arctic \n c. North Pacific" && name[i] == 'c' ||
                    currentQuestion == "How long does it take for Venus to rotate once on its axis (in earth days)? \n a. 365 \n b. 224 \n c. 12" && name[i] == 'b' ||
                    currentQuestion == "In which year did man last walk on the Moon? \n a. 1972 \n b. 2001 \n c. 1975" && name[i] == 'a' ||
                    currentQuestion == "How many ring does Uranus have? \n a. 200 \n b. 13 \n c. 46" && name[i] == 'b' ||
                    currentQuestion == "How long is Mercury's year? \n a. 88 Earth days \n b. 365 Earth days \n c. 27 Earth days" && name[i] == 'a' ||
                    currentQuestion == "Who was the first astronaut to walk on the moon? \n a. Charles Duke \n b. Neil Armstrong \n c. Buzz Aldrin" && name[i] == 'b' ||
                    currentQuestion == "Which planet is name after the King of the Roman gods? \n a. Jupiter \n b. Neptune \n c. Uranus" && name[i] == 'a'
                    )
                {
                    trueAnswer();
                }
                else {
                    wrongAnswer();
                }

            }



        }

        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });
        DrawTexture(thinkingAlien, 1400, 400, RAYWHITE);

        DrawText(currentQuestion.c_str(), (float)GetScreenWidth() / 2 - MeasureText(currentQuestion.c_str(), 40) / 2 - 100, (float)GetScreenHeight() / 2 - 200, 40, WHITE);

        DrawRectangleRec(textBox, RAYWHITE);

        DrawRectangleRec(submitRec, (CheckCollisionPointRec(mousePoint, submitRec) ? PURPLE : GRAY));

        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, { 0, 91, 241, 255 });
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, { 0, 91, 241, 255 });

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, GREEN);

        EndDrawing();
    }
}