#include "questions.h"
#include "variables.h"
#include "game.h"

void trueAnswer() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        // Draw trueAnswer() function
        BeginDrawing();
        Texture2D bgPhoto = LoadTexture("../images/bgPhoto.png");
        DrawTexture(bgPhoto, 0, 0, WHITE);
        DrawText("Correct", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 70, GREEN);
        EndDrawing();
    }

}

void wrongAnswer() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        // Draw wrongAnswer() function
        BeginDrawing();
        Texture2D bgPhoto = LoadTexture("../images/bgPhoto.png");
        DrawTexture(bgPhoto, 0, 0, WHITE);
        DrawText("Incorrect", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2, 70, RED);
        EndDrawing();
    }
}

void questions() {

    // Initialize an empty string
    char name[20] = "\0";
    // Initialize the letter count to zero
    int letterCount = 0;

    // Define a rectangle for the text box and set the bool flag to false
    Rectangle textBox = { GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 + 120, 340, 100 };
    bool mouseOnText = false;

    // Initialize the frames counter to zero
    int framesCounter = 0;

    // Create responsive button
    Rectangle submitRec = { GetScreenWidth() / 2 + 120, GetScreenHeight() / 2 + 240, 210, 70 };

    // Get screen size through variables
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    // Asing a function for exiting the game to exitGame
    bool exitGame = WindowShouldClose();

    // Get random question from the question bank and load texture
    string currentQuestion = questionsArr[GetRandomValue(0, 17)];
    Texture2D thinkingAlien = LoadTexture("../images/thinkingAlien.png");

    EnableCursor();
    while (!WindowShouldClose())
    {
        // Get the current mouse position
        Vector2 mousePoint = GetMousePosition();

        // Check if the mouse pointer is within the text box rectangle
        if (CheckCollisionPointRec(mousePoint, textBox)) mouseOnText = true;
        else mouseOnText = false;

        // If the mouse is over the text box
        if (mouseOnText)
        {
            // Change the mouse cursor to an I-beam cursor
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get the ASCII value of the pressed key
            int key = GetCharPressed();

            // While there is a key pressed
            while (key > 0)
            {
                // Check if the key is a printable character and if there's still space
                if ((key >= 32) && (key <= 125) && (letterCount < 20))
                {
                    // Add the character
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0';
                    letterCount++;
                }
                // Get the next pressed key
                key = GetCharPressed();
            }

            // If the backspace key is pressed
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                // Check to make sure that the letter count doesn't go bellow zero
                if (letterCount < 0) letterCount = 0;
                // Delete the last letter
                name[letterCount] = '\0';

            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        // Increase frame counter if mouse is hovering on the text
        if (mouseOnText) framesCounter++;
        else framesCounter = 0;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePoint, submitRec))
        {
            // Iterate through each character in the name
            for (int i = 0; i < letterCount; i++)
            {
                // Check if the current question matches the assigned answer
                if (currentQuestion == "How many constellations are there? \n \n a. 88 \n b. 39 \n c. 120" && name[i] == 'a' ||
                    currentQuestion == "How long does each season last on Neptune? \n \n a. 3 months \n b. 30 weeks \n c. more than 40 years" && name[i] == 'c' ||
                    currentQuestion == "How many minutes was the shortest space flight? \n \n a. 60 minutes \n b. 15 minutes \n c. 3 minutes" && name[i] == 'b' ||
                    currentQuestion == "What is the only planet not named after a God? \n \n a. Earth \n b. Mars \n c. Venus" && name[i] == 'a' ||
                    currentQuestion == "How was the first manned space mission to land on the Moon called? \n \n a. Apollo 17 \n b. Apollo 14 \n c. Apollo 11" && name[i] == 'c' ||
                    currentQuestion == "What planet is nicknamed the 'Red Planet'? \n \n a. Mars \n b. Saturn \n c. Mercury" && name[i] == 'a' ||
                    currentQuestion == "How long does it take to get to the moon from Earth in a space shuttle? \n \n a. 3 days \n b. 1 hour \n c. 5 hours" && name[i] == 'a' ||
                    currentQuestion == "Which constellation takes its name from the Latin word for 'twins'? \n \n a. Libra \n b. Gemini \n c. Cancer" && name[i] == 'b' ||
                    currentQuestion == "How many space shuttles actually flew in space? \n \n a. Three \n b. Eighteen \n c. Five" && name[i] == 'c' ||
                    currentQuestion == "Neptune has the fastest winds of any planet, what speeds do they reach? \n \n a. 1,000 mph \n b. 1,300 mph \n c. 6,500 mph" && name[i] == 'b' ||
                    currentQuestion == "Which constellation holds the hottest place in the universe? \n \n a. Virgo \n b. Orion \n c. Draco" && name[i] == 'a' ||
                    currentQuestion == "Apollo 11 landed in which ocean upon completion of their moon landing mission? \n \n a. Atlantic \n b. Arctic \n c. North Pacific" && name[i] == 'c' ||
                    currentQuestion == "How long does it take for Venus to rotate once on its axis (in earth days)? \n \n a. 365 \n b. 224 \n c. 12" && name[i] == 'b' ||
                    currentQuestion == "In which year did man last walk on the Moon? \n \n a. 1972 \n b. 2001 \n c. 1975" && name[i] == 'a' ||
                    currentQuestion == "How many ring does Uranus have? \n \n a. 200 \n b. 13 \n c. 46" && name[i] == 'b' ||
                    currentQuestion == "How long is Mercury's year? \n \n a. 88 Earth days \n b. 365 Earth days \n c. 27 Earth days" && name[i] == 'a' ||
                    currentQuestion == "Who was the first astronaut to walk on the moon? \n \n a. Charles Duke \n b. Neil Armstrong \n c. Buzz Aldrin" && name[i] == 'b' ||
                    currentQuestion == "Which planet is name after the King of the Roman gods? \n \n a. Jupiter \n b. Neptune \n c. Uranus" && name[i] == 'a'
                    )
                {
                    // If the answer is correct, call trueAnswer() function and set answer to true
                    trueAnswer();
                    DisableCursor();
                    answer = true;
                }
                else {
                    // If the answer is wrong, call wrongAnswer() function and set answer to false
                    wrongAnswer();
                    DisableCursor();
                    answer = false;
                }
            }
        }

        // Begin drawing on the window
        BeginDrawing();
        // Clear the background with a custom color
        ClearBackground({ 0, 1, 41, 255 });

        // Draw different textures, text, and textbox
        DrawTexture(thinkingAlien, 1400, 460, RAYWHITE);
        DrawText(currentQuestion.c_str(), (float)GetScreenWidth() / 2 - MeasureText(currentQuestion.c_str(), 40) / 2 - 30, (float)GetScreenHeight() / 2 - 200, 40, WHITE);
        DrawRectangleRec(textBox, RAYWHITE);

        // Draw a submit button using rectangle
        DrawRectangleRec(submitRec, (CheckCollisionPointRec(mousePoint, submitRec) ? PURPLE : GRAY));
        DrawText("SUBMIT", GetScreenWidth() / 2 + 160, GetScreenHeight() / 2 + 260, 35, WHITE);

        // Draw rectangle lines around the text box based on whether the mouse is hovering over it or not
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, { 0, 91, 241, 255 });
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, WHITE);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, GREEN);

        // End drawing
        EndDrawing();
    }
}