#include "raylib.h"
#include "raymath.h"
//#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/spiritualrowdy.h"
//#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/evilMonster.h"
#include "Spiritual_rowdy.hpp"
#include "Player_Character.hpp"
#include "Bullet.hpp"

#include <iostream>

//----------------------------Game Settings----------------------------

const int screenWidth = 800;
const int screenHeight = 450;
float rotation = 0.0f;
float speed = 2.0f;
float bulletSpeed = 5.0f;
float bulletRadius = 5.0f;
const int MAX_BULLETS = 50;

//--------------------------------------------------------
ScreenDimensions screendimensions(
    screenWidth,
    screenHeight
);
 
int main(void){

    Bullet bullets[MAX_BULLETS] = {0};                                  //max available bullets
    
    InitWindow(screenWidth, screenHeight, "Invasion Defenders");
    
    SetTargetFPS(60);                                                   // Set our game to run at 60 frames-per-second

    
    //----------------------------Creating character----------------------------

    Spiritual_rowdy spiritual_rowdy = Spiritual_rowdy(SPIRITUALROWDY_FORMAT,SPIRITUALROWDY_HEIGHT,SPIRITUALROWDY_WIDTH,SPIRITUALROWDY_DATA);
    Player_Character player_character = Player_Character(EVILMONSTER_FORMAT,EVILMONSTER_HEIGHT,EVILMONSTER_WIDTH,EVILMONSTER_DATA,rotation,screendimensions);

    //---------------------------------------------------------------------------------
    
    
    // Main game loop
    while (!WindowShouldClose())                                        // Detect window close button or ESC key
    {
        //-------------------------------------Creating forward rule walking where looking---------------------------------------------
        
        Vector2 forward = {
            cosf(player_character.getrotation() * DEG2RAD), //defining position X
            sinf(player_character.getrotation() * DEG2RAD)  //defining position Y
        };
/*
           y (sin)
            ↑
            |
            |
 (-cos) ←---o---→ (cos)             Sin Cos explination
            |
            |
            ↓ (-sin)
*/
        //------------------------------------------------------------------------------------------------------------------------------

        //-----------------------------------------Walking character logic------------------------------------
        
        if (IsKeyDown(KEY_UP)) {
            player_character.setposX(player_character.getpos().x + forward.x * speed);
            player_character.setposY(player_character.getpos().y + forward.y * speed);
        }
        if (IsKeyDown(KEY_DOWN)) {
            player_character.setposX(player_character.getpos().x - forward.x * speed);
            player_character.setposY(player_character.getpos().y - forward.y * speed);
        }
        if (IsKeyDown(KEY_RIGHT)) player_character.setrotation(player_character.getrotation() + 2.0f);
        if (IsKeyDown(KEY_LEFT))  player_character.setrotation(player_character.getrotation() - 2.0f);

        //-------------------------------------------------------------------------------------------

        //------------------------------------------Shooting bullets using space button--------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) { 
            // Freien Bullet-Slot suchen
            for (int i = 0; i < MAX_BULLETS; i++) {
                if (!bullets[i].active) {
                    bullets[i].active = true;

                    // Startposition: Mitte des Monsters
                    bullets[i].pos = player_character.getpos();

                    // Richtung = forward (gleiche Richtung wie Monster)
                    bullets[i].vel.x = forward.x * bulletSpeed;
                    bullets[i].vel.y = forward.y * bulletSpeed;

                    break; // nur einen Bullet pro Tastendruck
                }
            }
        }
        //---------------------------------------------------------------------------------------------------------------------------

        // ------------------Bullets logic------------------
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].active) continue;

            bullets[i].pos.x += bullets[i].vel.x;
            bullets[i].pos.y += bullets[i].vel.y;

            // Deaktivieren, wenn ausserhalb vom Screen
            if (bullets[i].pos.x < 0 || bullets[i].pos.x > screenWidth ||
                bullets[i].pos.y < 0 || bullets[i].pos.y > screenHeight) {
                bullets[i].active = false;
            }
        }
        //-------------------------------------------------------

        //--------------------Collision points---------------------
        for (auto &b : bullets) {
            if (!b.active) continue;
                if (CheckCollisionCircleRec(b.pos, bulletRadius, spiritual_rowdy.getrectangle())) {
                    b.active = false;
                    //here muss ich denn actions
                    std::cout << "HIT!" << std::endl;
                }
            }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------//
        BeginDrawing();

            //----------------------------Setting Background-------------------------------

            ClearBackground(RAYWHITE);

            //-----------------------------------------------------------------------------

            //----------------------------Drawing characters---------------------------------

            spiritual_rowdy.draw();
            player_character.draw();

            //--------------------------------------------------------------------------------

            //-------------------------------Drawing Bullets--------------------------------
            for (int i = 0; i < MAX_BULLETS; i++) {
                if (!bullets[i].active) continue;
                DrawCircleV(bullets[i].pos, 4.0f, RED);  // Einfacher Kreis als Bullet
            }
            //------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------//
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------//
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------//

    return 0;
}