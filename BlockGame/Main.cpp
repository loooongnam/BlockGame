#include <raylib-cpp.hpp>
#include "raylib-cpp-addons.hpp"
#include "BlockGame.hpp"

TileMap tileMap;

int main(void)
{
	InitWindow(375, 375 + 60, "2048");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	while (!WindowShouldClose())
	{
		if (GetScreenWidth() < GetScreenHeight() - 60) SetWindowSize(GetScreenHeight() - 60, GetScreenHeight());
		if (GetScreenHeight() < GetScreenWidth() + 60) SetWindowSize(GetScreenWidth(), GetScreenWidth() + 60);

		BeginDrawing();
		ClearBackground(raylib::Color(250, 248, 239));
		DrawRectangleRoundedScore(0.1f, 10, ColorAlpha(DARKBROWN, 0.6f), "Score: ", WHITE);
		DrawRectangleRoundedTileContainer(0.02f, 10, raylib::Color(187, 173, 160));
		tileMap.GenTileMap(3);
		my::GenTilesPosition(tileMap);
		EndDrawing();
	}

	CloseWindow();
}
