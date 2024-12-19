#include <raylib.h>
#include <stdio.h>
typedef struct Player 
{
  Vector2 pos;
  Texture2D sprite;
  Vector2 velocity;
  Rectangle avatar;
  int groundPosition;
} Player;

typedef struct Game 
{
  const int width = 1024;
  const int height = 720;
  const int FPS = 60;
  const char* title = "Dapper Dasher!";
  float deltaTime;
  float runningTime;
} Game;

Game game;
Player player;
const int gravity = 1000;

void initialize()
{
  player.sprite = LoadTexture("textures/scarfy.png");
  player.avatar.width = (float) player.sprite.width / 6;
  player.avatar.height = player.sprite.height;
  player.groundPosition = game.height - player.avatar.height;
}

void placePlayer() 
{
  player.pos.x = game.width / 2 - player.avatar.width / 2;
  player.pos.y = player.groundPosition;
}

void applyGravity()
{
  if(player.pos.y != player.groundPosition)
  {
    player.velocity.y += gravity * game.deltaTime;
  }
}
void handleJump()
{
  bool isJumping = IsKeyDown(KEY_SPACE);
  if(isJumping && player.pos.y == player.groundPosition) 
  {
    player.velocity.y = -600;
  }
}
void fallToTheGround()
{
  player.pos.y += player.velocity.y * game.deltaTime;
  if(player.pos.y > player.groundPosition) 
  {
    player.pos.y = player.groundPosition;
    player.velocity.y = 0;
  }
}
void run()
{
  float updateTime = 1.0 / 12; //update 1 times per second
  game.runningTime += game.deltaTime;
  float cycles = game.runningTime / updateTime;
  float currentSprite = (int)cycles % 6;
  player.avatar.x = currentSprite * player.avatar.width;
}
int main() 
{
  InitWindow(game.width, game.height, game.title);
  initialize();
  SetTargetFPS(game.FPS);
  placePlayer();
  while(!WindowShouldClose()) 
  {  
    game.deltaTime = GetFrameTime();
    BeginDrawing();
    applyGravity();
    handleJump();
    run();
    fallToTheGround();
    DrawTextureRec(player.sprite, player.avatar, player.pos, WHITE);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  UnloadTexture(player.sprite);
  CloseWindow();
}

