#include <iostream>
#include <sstream>
#include <raylib-cpp.hpp>

void DrawTiles(int x, int y, int width, int height, int numberOfTiles);
void DrawBlockPoints(int x, int y);

struct App
{
	int _width;
	void CreateWindow(int width, int height, std::string title, ConfigFlags flags)
	{
		InitWindow(width, height, title.c_str());
		SetWindowState(flags);
	}

	void DestroyWindow()
	{
		CloseWindow();
	}
};

struct Game
{
	void Run()
	{
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Score: ", 17, 15, 20, DARKGRAY);
			DrawRectangleRounded(raylib::Rectangle(3, 5, 533, 40), 1.0f, 10, ColorAlpha(DARKBROWN, 0.4f));
			DrawRectangleRounded(raylib::Rectangle(13, 57, 513, 487), 0.05f, 10, ColorAlpha(BROWN, 0.8f));
			DrawRectangleRoundedLines(raylib::Rectangle(13, 57, 513, 487), 0.05f, 10, 8, ColorAlpha(BROWN, 1.0f));
			DrawTiles(40, 80, 140, 130, 160*3);
			DrawBlockPoints(93, 120);
			EndDrawing();
		}
	}
};

int main(void)
{
	App app;
	Game game;

	app.CreateWindow(540, 560, "2048", FLAG_WINDOW_ALWAYS_RUN);
	game.Run();
	app.DestroyWindow();
}

void DrawTiles(int x, int y, int width, int height, int numberOfTiles)
{
	for (int i = x; i < numberOfTiles; i += 160)
	{
		for (int j = y; j < numberOfTiles; j += 155)
		{
			DrawRectangleRounded(raylib::Rectangle(i, j, width, height), 0.1f, 10, ColorAlpha(BROWN, 1.0f));
		}
	}
}

void DrawBlockPoints(int x, int y)
{
	for (int i = x; i < 1000; i += 161)
	{
		for (int j = y; j < 1000; j += 155)
		{
			DrawText("2", i, j, 60, DARKGRAY);
		}
	}
}
