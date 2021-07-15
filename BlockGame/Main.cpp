#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include <sstream>
#include <raylib-cpp.hpp>

void DrawTiles(int x, int y, int width, int height);
void DrawBlockPoints(int x, int y);

bool haveValue[9];

struct App
{
    void CreateWindow(int width, int height, std::string title, ConfigFlags flags)
    {
        InitWindow(width, height, title.c_str());
        SetWindowState(flags);

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, 8);

        int r = dist(rng);

        std::cout << r+1 << std::endl;
        haveValue[r] = true;
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
            DrawText("Score: ", 20, 15, 30, DARKGRAY);
            DrawRectangleRounded(raylib::Rectangle(13, 57, 513, 487), 0.02f, 10, raylib::Color(187, 173, 160));
            DrawTiles(40, 80, 140, 130);
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

void DrawTiles(int x, int y, int width, int height)
{
    int z = 0;
    auto col = raylib::Color(205, 193, 180);
    auto colH = raylib::Color(238, 228, 218);

    for (int i = x; i < 160*3; i += 160)
    {
        for (int j = y; j < 155*3; j += 155)
        {
            if (haveValue[z])
            {
                DrawRectangleRounded(raylib::Rectangle(i, j, width, height), 0.1f, 10, colH);
            }
            else
            {
                DrawRectangleRounded(raylib::Rectangle(i, j, width, height), 0.1f, 10, col);
            }
            z++;
            if (z > 8) z = 0;
        }
    }
}

void DrawBlockPoints(int x, int y)
{
    int z = 0;
    for (int i = x; i < 161*3; i += 161)
    {
        //DrawText("2", i, y, 60, raylib::Color(119, 110, 101));
        for (int j = y; j < 155*3; j += 155)
        {
            if (haveValue[z])
            {
                DrawText("2", i, j, 60, raylib::Color(119, 110, 101));
            }
            if (!haveValue[z])
            {
                DrawText("", i, j, 60, raylib::Color(119, 110, 101));
            }
            z++;
            if (z > 8) z = 0;
        }
    }
}
