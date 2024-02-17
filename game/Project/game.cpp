#include "game.h"

#define ROCKS 200
void game()
{
    //Screen's size
    const int screenWidth = 1920;
    const int screenHeight = 975;

    //Game's background
    Texture2D bgPhoto = LoadTexture("../images/bgPhoto.png");


    //Objects
    float heights[ROCKS] = { 0 };
    Vector3 rockPositions[ROCKS] = { 0 };


    //First spacecraft part object
    Model firstPartobj = LoadModel("../images/spacecraft/objects/firstPart.obj");
    Texture2D firstPartTexture = LoadTexture("..images/spacecraft/firstPart.png");
    Vector3 positionOne = { 102.5f,2.0f,9.8f };

    //Second spacecraft part object
    Model secondPartobj = LoadModel("../images/spacecraft/objects/secondPart.obj");
    Texture2D secondPartTexture = LoadTexture("..images/spacecraft/secondPart.png");
    Vector3 positionTwo = { -120.0f,1.0f,-60.7f };

    //Third spacecraft part object 
    Model thirdPartobj = LoadModel("../images/spacecraft/objects/thirdPart.obj");
    Texture2D thirdPartTexture = LoadTexture("..images/spacecraft/thirdPart.png");
    Vector3 positionThree = { -70.0f,1.0f,80.9f };

    //Fourth spacecraft part object
    Model fourthPartobj = LoadModel("../images/spacecraft/objects/fourthPart.obj");
    Texture2D fourthPartTexture = LoadTexture("..images/spacecraft/fourthPart.png");
    Vector3 positionFour = { 10.6f,2.0f,-100.4f };

    //Fifth spacecraft part object
    Model fifthPartobj = LoadModel("../images/spacecraft/objects/fifthPart.obj");
    Texture2D fifthPartTexture = LoadTexture("..images/spacecraft/fifthPart.png");
    Vector3 positionFive = { 90.0f,1.0f,80.0f };

    //Sixth spacecraft part object
    Model sixthPartobj = LoadModel("../images/spacecraft/objects/sixthPart.obj");
    Texture2D sixthPartTexture = LoadTexture("..images/spacecraft/sixthPart.png");
    Vector3 positionSix = { 95.6f,1.0f,-120.0f };

    //Variables for the camera
    Camera camera = { 0 };
    camera.position = { 0.0f, 2.0f, 4.0f };
    camera.target = { 0.0f, 2.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    int cameraMode = CAMERA_FIRST_PERSON;

    //Defines rocks' positions
    for (int i = 0; i < ROCKS; i++)
    {
        heights[i] = (float)GetRandomValue(0.9, 1.0);
        rockPositions[i] = { (float)GetRandomValue(-110,110), heights[i] / 2.0f, (float)GetRandomValue(-100, 100) };
    }
    DisableCursor();
    SetTargetFPS(360);
    while (!WindowShouldClose())
    {

        UpdateCamera(&camera, cameraMode);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(bgPhoto, 0, 0, WHITE);

        BeginMode3D(camera);

        //Draw ground
        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 250.0f, 250.0f }, { 192, 96, 0, 250 });

        for (int i = 0; i < ROCKS; i++)
        {
            DrawCube(rockPositions[i], 1.5f, { 0.9f }, 1.5f, { 138, 69, 0, 250 });
        }
        DrawModel(firstPartobj, positionOne, 0.05f, RED);
        DrawModel(secondPartobj, positionTwo, 0.05f, WHITE);
        DrawModel(thirdPartobj, positionThree, 0.05f, WHITE);
        DrawModel(fourthPartobj, positionFour, 0.05f, RED);
        DrawModel(fifthPartobj, positionFive, 0.05f, WHITE);
        DrawModel(sixthPartobj, positionSix, 0.05f, WHITE);
        EndMode3D();

        EndDrawing();
    }
    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}
