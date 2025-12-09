#include "raylib.h"
#include "raymath.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/spiritualrowdy.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/evilMonster.h"

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

struct Bullet {
    Vector2 pos;
    Vector2 vel;
    bool active;
};

class Spiritual_rowdy{
    
    public:
    Spiritual_rowdy(int format, int height,int width,void* data){ //initiation of spiritual_rowdy
        img.format = format;
        img.height = height;
        img.width = width;
        img.data = data;
        img.mipmaps = 1;
        
        sprite = LoadTextureFromImage(img); //in the ctor because ctor initialises as last
        pos= {
            (float)50.0,    //defining position X
            (float)50.0     //defining position Y
        };
        rectangle={pos.x,pos.y,(float)sprite.width,(float)sprite.height};

    };
    void draw(){DrawTexture(sprite, pos.x, pos.y, WHITE);}
    
    Texture2D getsprite(){return sprite;}
    Vector2 getpos(){return pos;}
    Rectangle getrectangle(){return rectangle;}
    
    private:
    Image img;
    Texture2D sprite;
    Rectangle rectangle{};
    Vector2 pos{};
    
};

class Player_Character{
    
    public:
    Player_Character(int format, int height,int width,void* data){ //initiation of main character
        img.format = format;
        img.height = height;
        img.width = width;
        img.data = data;
        img.mipmaps = 1;
        
        sprite = LoadTextureFromImage(img); //in the ctor because ctor initialises as last
        pos={
            (float)screenWidth / 2 - (float)sprite.width / 2, //defining position X
            (float)screenHeight / 2 - (float)sprite.height / 2 //defining position Y
        };
        rectangle={
            pos.x - sprite.width / 2.0f,
            pos.y - sprite.height / 2.0f,
            (float)sprite.width,
            (float)sprite.height};
        };

    void draw(){
            DrawTexturePro(
            sprite,
            Rectangle{0, 0, (float)sprite.width, (float)sprite.height},
            Rectangle{pos.x, pos.y, (float)sprite.width, (float)sprite.height},
            Vector2{(float)sprite.width/2, (float)sprite.height/2}, 
            rotation,
            WHITE
        );
    }
    
    Texture2D getsprite(){return sprite;}
    Vector2 getpos(){return pos;}
    void setposX(float value){pos.x = value;}
    void setposY(float value){pos.y = value;}

    Rectangle getrectangle(){return rectangle;}
    
    private:
    Image img;
    Texture2D sprite;
    Rectangle rectangle{};
    Vector2 pos{};
    
};

int main(void){

    Bullet bullets[MAX_BULLETS] = {0};                                  //max available bullets
    
    InitWindow(screenWidth, screenHeight, "Invasion Defenders");
    
    SetTargetFPS(60);                                                   // Set our game to run at 60 frames-per-second

    
    //----------------------------Creating character----------------------------

    Spiritual_rowdy spiritual_rowdy = Spiritual_rowdy(SPIRITUALROWDY_FORMAT,SPIRITUALROWDY_HEIGHT,SPIRITUALROWDY_WIDTH,SPIRITUALROWDY_DATA);
    Player_Character player_character = Player_Character(EVILMONSTER_FORMAT,EVILMONSTER_HEIGHT,EVILMONSTER_WIDTH,EVILMONSTER_DATA);

    //---------------------------------------------------------------------------------
    
    
    // Main game loop
    while (!WindowShouldClose())                                        // Detect window close button or ESC key
    {
        //-------------------------------------Creating forward rule walking where looking---------------------------------------------
        
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
        if (IsKeyDown(KEY_RIGHT)) rotation += 2.0f;
        if (IsKeyDown(KEY_LEFT))  rotation -= 2.0f;

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