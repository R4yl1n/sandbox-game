#include "raylib.h"
#include "raymath.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/spiritualrowdy.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/evilMonster.h"

#include <iostream>

struct Bullet {
    Vector2 pos;
    Vector2 vel;
    bool active;
};

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int MAX_BULLETS = 50;
    Bullet bullets[MAX_BULLETS] = {0};

    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    //--------------------------------------------------------------------------------------
    //configrations embeded images
    //--------------------------------------------------------------------------------------
    
    //----------------------------Creating spiritual rowdy----------------------------
    Image spiritual_rowdy;
    spiritual_rowdy.format = SPIRITUALROWDY_FORMAT;
    spiritual_rowdy.height = SPIRITUALROWDY_HEIGHT;
    spiritual_rowdy.width = SPIRITUALROWDY_WIDTH;
    spiritual_rowdy.data = SPIRITUALROWDY_DATA;
    spiritual_rowdy.mipmaps = 1;
    
    Texture2D sprite_spiritual_rowdy = LoadTextureFromImage(spiritual_rowdy);
    
    //Vector2 spiritual_rowdy_pos;        
    //spiritual_rowdy_pos.y=(float)50.0;
    //spiritual_rowdy_pos.x=(float)50.0;
    
    Vector2 spiritual_rowdy_pos = {
        (float)50.0,    //defining position X
        (float)50.0     //defining position Y
    };
    Rectangle rowdyRect{
        spiritual_rowdy_pos.x,
        spiritual_rowdy_pos.y,
        (float)sprite_spiritual_rowdy.width,
        (float)sprite_spiritual_rowdy.height
    };
    //--------------------------------------------------------
    //----------------------------Creating Evil Monster(Player)----------------------------
    Image evil_Monster;
    evil_Monster.format = EVILMONSTER_FORMAT;
    evil_Monster.height = EVILMONSTER_HEIGHT;
    evil_Monster.width = EVILMONSTER_WIDTH;
    evil_Monster.data = EVILMONSTER_DATA;
    evil_Monster.mipmaps = 1;
    
    Texture2D sprite_evil_Monster = LoadTextureFromImage(evil_Monster);
    
    //Vector2 evilPos;
    //evilPos.x = (float)screenWidth / 2 - (float)sprite_evil_Monster.width / 2;
    //evilPos.y = (float)screenHeight / 2 - (float)sprite_evil_Monster.height / 2;

    Vector2 evilPos = {
        (float)screenWidth / 2 - (float)sprite_evil_Monster.width / 2, //defining position X
        (float)screenHeight / 2 - (float)sprite_evil_Monster.height / 2 //defining position Y
    };

    Rectangle evilRect{
    evilPos.x - sprite_evil_Monster.width / 2.0f,
    evilPos.y - sprite_evil_Monster.height / 2.0f,
    (float)sprite_evil_Monster.width,
    (float)sprite_evil_Monster.height
};
    //--------------------------------------------------------------------------------------

    //----------------------------Game Settings----------------------------
    float rotation = 0.0f;
    float speed = 2.0f;
    float bulletSpeed = 5.0f;
    float bulletRadius = 5.0f;

    //--------------------------------------------------------
    
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------
        
        Vector2 forward = {
        cosf(rotation * DEG2RAD), //defining position X
        sinf(rotation * DEG2RAD)  //defining position Y
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

        //if (IsKeyDown(KEY_RIGHT)) evilPos.x += 2.0f;
        //if (IsKeyDown(KEY_LEFT)) evilPos.x -= 2.0f;
        //if (IsKeyDown(KEY_UP)) evilPos.y -= 2.0f;
        //if (IsKeyDown(KEY_DOWN)) evilPos.y += 2.0f;
        
        if (IsKeyDown(KEY_UP)) {
        evilPos.x += forward.x * speed;
        evilPos.y += forward.y * speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
        evilPos.x -= forward.x * speed;
        evilPos.y -= forward.y * speed;
        }
        if (IsKeyDown(KEY_RIGHT)) rotation += 2.0f;
        if (IsKeyDown(KEY_LEFT))  rotation -= 2.0f;

        //------------------------------------------Shooting bullets using space button--------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) { 
            // Freien Bullet-Slot suchen
            for (int i = 0; i < MAX_BULLETS; i++) {
                if (!bullets[i].active) {
                    bullets[i].active = true;

                    // Startposition: Mitte des Monsters
                    bullets[i].pos = evilPos;

                    // Richtung = forward (gleiche Richtung wie Monster)
                    bullets[i].vel.x = forward.x * bulletSpeed;
                    bullets[i].vel.y = forward.y * bulletSpeed;

                    break; // nur einen Bullet pro Tastendruck
                }
            }
        }
                // ------------------ BULLETS UPDATEN ------------------
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
        for (auto &b : bullets) {
        if (!b.active) continue;

        if (CheckCollisionCircleRec(b.pos, bulletRadius, rowdyRect)) {
            b.active = false;
            // Hier könntest du z.B. Spiritual Rowdy "killen",
            // Score erhöhen, Explosion zeichnen, etc.
            std::cout << "HIT!" << std::endl;
    }
}
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawTexture(sprite_spiritual_rowdy, screenWidth/2 - sprite_spiritual_rowdy.width/2, screenHeight/2 - sprite_spiritual_rowdy.height/2, BLACK);
            //DrawTexture(sprite_evil_Monster, screenWidth/2 - sprite_evil_Monster.width/2, screenHeight/2 - sprite_evil_Monster.height/2,WHITE);
            //DrawText("this IS a texture loaded from an image!", 300, 370, 10, GRAY);
            DrawTexture(sprite_spiritual_rowdy, spiritual_rowdy_pos.x, spiritual_rowdy_pos.y, WHITE);
            
            //DrawTexture(sprite_evil_Monster, evilPos.x, evilPos.y, WHITE);
            //----------------------------------------Creating Evli Monster(Player)----------------------------------------------
            DrawTexturePro(
            sprite_evil_Monster,
            Rectangle{0, 0, (float)sprite_evil_Monster.width, (float)sprite_evil_Monster.height},
            Rectangle{evilPos.x, evilPos.y, (float)sprite_evil_Monster.width, (float)sprite_evil_Monster.height},
            Vector2{(float)sprite_evil_Monster.width/2, (float)sprite_evil_Monster.height/2}, 
            rotation,
            WHITE
        );
            //--------------------------------------------------------------------------------------------------------------------
        for (int i = 0; i < MAX_BULLETS; i++) {
                if (!bullets[i].active) continue;

                // Einfacher Kreis als Bullet
                DrawCircleV(bullets[i].pos, 4.0f, RED);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}