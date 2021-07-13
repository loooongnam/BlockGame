#include <iostream>
#include <sstream>
#include <raylib-cpp.hpp>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540
#define WINDOW_TITLE "Block Game"

float moveSpeed = 0.1f;
int moveSide;
int moveFD;
raylib::Vector2 playerPos = { (SCREEN_WIDTH / 2) - 50, (SCREEN_HEIGHT / 2) - 50 };
std::stringstream s;

bool InitWindow(int width, int height, std::string title, ConfigFlags flags);
void HandleInput();
void UpdatePosition();
void ChangeSpeed(float value);
void CheckPlayerPosToMoveBack();

int main(void)
{
	if (!InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, FLAG_WINDOW_RESIZABLE)) std::cout << "Window Initialization Failed" << std::endl;
	while (!WindowShouldClose())
	{
		HandleInput();
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawFPS(10, 10);
		s << "X: ";
		s << playerPos.x;
		DrawText(s.str().c_str(), 10, 45, 20, DARKGRAY);
		s.str("");
		s << "Y: ";
		s << playerPos.y;
		DrawText(s.str().c_str(), 10, 70, 20, DARKGRAY);
		s.str("");
		s << "Speed: ";
		s << moveSpeed;
		DrawText(s.str().c_str(), 10, 110, 20, DARKGRAY);
		s.str("");
		CheckPlayerPosToMoveBack();
		DrawRectangleV(playerPos, raylib::Vector2(100, 100), RED);
		EndDrawing();
	}
	CloseWindow();
}

bool InitWindow(int width, int height, std::string title, ConfigFlags flags)
{
	raylib::InitWindow(width, height, title);
	SetWindowState(flags);
	return true;
}

void HandleInput()
{
	if (IsKeyDown(KEY_A)) moveSide = -1;
	if (IsKeyDown(KEY_D)) moveSide = 1;
	if (IsKeyDown(KEY_W)) moveFD = -1;
	if (IsKeyDown(KEY_S)) moveFD = 1;
	UpdatePosition();

	if (IsKeyPressed(KEY_UP)) ChangeSpeed(0.1f);
	if (IsKeyPressed(KEY_DOWN)) ChangeSpeed(-0.1f);
}

void UpdatePosition()
{
	if (moveSide == 1) playerPos.x += moveSpeed;
	if (moveSide == -1) playerPos.x -= moveSpeed;
	if (moveFD == 1) playerPos.y += moveSpeed;
	if (moveFD == -1) playerPos.y -= moveSpeed;

	moveSide = 0;
	moveFD = 0;
}

void ChangeSpeed(float value)
{
	moveSpeed += value;
	if (moveSpeed < 0.1f) moveSpeed = 0.1f;
	if (moveSpeed > 2.0f) moveSpeed = 2.0f;
}

void CheckPlayerPosToMoveBack()
{
	if (playerPos.x > SCREEN_WIDTH) playerPos.x = -100;
	if (playerPos.x < -100) playerPos.x = SCREEN_WIDTH;
	if (playerPos.y > SCREEN_HEIGHT) playerPos.y = -100;
	if (playerPos.y < -100) playerPos.y = SCREEN_HEIGHT;
}
