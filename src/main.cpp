#include "raylib.h"
#include "raymath.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/spiritualrowdy.h"
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
    Image spiritual_rowdy;
    spiritual_rowdy.format = SPIRITUALROWDY_FORMAT;
    spiritual_rowdy.height = SPIRITUALROWDY_HEIGHT;
    spiritual_rowdy.width = SPIRITUALROWDY_WIDTH;
    spiritual_rowdy.data = SPIRITUALROWDY_DATA;
    spiritual_rowdy.mipmaps = 1;

    Texture2D sprite_spiritual_rowdy = LoadTextureFromImage(spiritual_rowdy);

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

Vector2 spiritual_rowdy_pos; 
spiritual_rowdy_pos.y=(float)50.0;
spiritual_rowdy_pos.x=(float)50.0;

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

            //DrawTexture(sprite_spiritual_rowdy, screenWidth/2 - sprite_spiritual_rowdy.width/2, screenHeight/2 - sprite_spiritual_rowdy.height/2, BLACK);
            //DrawTexture(sprite_evil_Monster, screenWidth/2 - sprite_evil_Monster.width/2, screenHeight/2 - sprite_evil_Monster.height/2,WHITE);
            DrawTexture(sprite_evil_Monster, evilPos.x, evilPos.y, WHITE);
            DrawTexture(sprite_spiritual_rowdy, spiritual_rowdy_pos.x, spiritual_rowdy_pos.y, WHITE);
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