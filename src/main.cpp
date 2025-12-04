#include "raylib.h"
#include "raymath.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/slime_purple.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/evilMonster.h"

#include <iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //configrations embeded images
    //--------------------------------------------------------------------------------------
    Image slime_purple;
    slime_purple.format = SLIME_PURPLE_FORMAT;
    slime_purple.height = SLIME_PURPLE_HEIGHT;
    slime_purple.width = SLIME_PURPLE_WIDTH;
    slime_purple.data = SLIME_PURPLE_DATA;
    slime_purple.mipmaps = 1;

    Texture2D sprite_slime_purple = LoadTextureFromImage(slime_purple);

    Image evil_Monster;
    evil_Monster.format = EVILMONSTER_FORMAT;
    evil_Monster.height = EVILMONSTER_HEIGHT;
    evil_Monster.width = EVILMONSTER_WIDTH;
    evil_Monster.data = EVILMONSTER_DATA;
    evil_Monster.mipmaps = 1;

    Texture2D sprite_evil_Monster = LoadTextureFromImage(evil_Monster);

Vector2 evilPos;
evilPos.x = (float)screenWidth / 2 - (float)sprite_evil_Monster.width / 2;
evilPos.y = (float)screenHeight / 2 - (float)sprite_evil_Monster.height / 2;

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        float speed = 2.0f;


        if (IsKeyDown(KEY_RIGHT)) evilPos.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) evilPos.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) evilPos.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) evilPos.y += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawTexture(sprite_slime_purple, screenWidth/2 - sprite_slime_purple.width/2, screenHeight/2 - sprite_slime_purple.height/2, BLACK);
            //DrawTexture(sprite_evil_Monster, screenWidth/2 - sprite_evil_Monster.width/2, screenHeight/2 - sprite_evil_Monster.height/2,WHITE);
            DrawTexture(sprite_evil_Monster, evilPos.x, evilPos.y, WHITE);
            //DrawText("this IS a texture loaded from an image!", 300, 370, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}