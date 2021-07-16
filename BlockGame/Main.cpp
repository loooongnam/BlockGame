#include <random>
#include <iostream>
#include <sstream>
#include <string>
#include <raylib-cpp.hpp>

void DrawTiles(int x, int y, int width, int height, int numberOfTiles);
void DrawBlockPoints(int x, int y, int numberOfTiles);
void GenNum(int z);
void MoveTile();
void SetTileVal(int z);
void GenNew(int a);

bool haveValue[9];
bool isOld[9];
int  genC = 1;

raylib::Vector2 tilePos[9];
raylib::Vector2 tileValPos[9];

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(0, 8);
std::uniform_int_distribution<std::mt19937::result_type> distR(1, 5);

const char* val;
std::string valT[9];
std::stringstream s;

struct App
{
    void CreateWindow(int width, int height, std::string title, ConfigFlags flags)
    {
        InitWindow(width, height, title.c_str());
        SetWindowState(flags);
        for (int i = 0; i < 2; i++)
        {
            GenNew(dist(rng));
        }
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
            DrawTiles(40, 80, 140, 130, 3);
            DrawBlockPoints(93, 120, 3);
            MoveTile();
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
    int z = 0;
    auto col = raylib::Color(205, 193, 180);
    auto colH = raylib::Color(238, 228, 218);

    for (int i = x; i < 160*numberOfTiles; i += 160)
    {
        for (int j = y; j < 155*numberOfTiles; j += 155)
        {
            tilePos[z].x = i;
            tilePos[z].y = j;

            if (haveValue[z])
            {
                DrawRectangleRounded(raylib::Rectangle(tilePos[z].x, tilePos[z].y, width, height), 0.1f, 10, colH);
            }
            else
            {
                DrawRectangleRounded(raylib::Rectangle(tilePos[z].x, tilePos[z].y, width, height), 0.1f, 10, col);
            }
            z++;
            if (z > 8) z = 0;
        }
    }
}

void DrawBlockPoints(int x, int y, int numberOfTiles)
{
    int z = 0;
    for (int i = x; i < 161*numberOfTiles; i += 161)
    {
        for (int j = y; j < 155*numberOfTiles; j += 155)
        {
            tileValPos[z].x = i;
            tileValPos[z].y = j;

            if (haveValue[z] && !isOld[z])
            {
                GenNum(z);
                SetTileVal(z);
                DrawText(val, tileValPos[z].x, tileValPos[z].y, 60, raylib::Color(119, 110, 101));
            }
            else if (haveValue[z])
            {
                SetTileVal(z);
                DrawText(val, tileValPos[z].x, tileValPos[z].y, 60, raylib::Color(119, 110, 101));
            }
            z++;
            if (z > 8) z = 0;
        }
    }
}

void GenNum(int z)
{
    if (genC <= 2)
    {
        if (distR(rng) != 5)
        {
            valT[z] = "2";
        }
        else
        {
            valT[z] = "4";
        }
        std::cout << "GenNum(" << z << ")" << std::endl;
    }
    genC++;
}

void MoveTile()
{
    int temp[4];
    int ac = 0;
    if (IsKeyPressed(KEY_RIGHT))
    {
        if (haveValue[0] || haveValue[3] || haveValue[6])
        {
            haveValue[0] = false;
            haveValue[3] = false;
            haveValue[6] = true;

            if (valT[0] != "") temp[0] = std::stoi(valT[0]);
            if (valT[3] != "") temp[1] = std::stoi(valT[3]);
            if (valT[6] != "") temp[2] = std::stoi(valT[6]);

            for (int i = 0; i < 3; i++)
            {
                if (temp[i] > 0) ac += temp[i];
            }

            valT[6] = std::to_string(ac);
            isOld[6] = true;
            valT[0] = "";
            valT[3] = "";

            for (int i = 0; i < 2; i++)
            {
                temp[3] = dist(rng);
                GenNew(temp[3]);
            }
            genC = 1;
            ac = 0;
        }

        if (haveValue[1] || haveValue[4] || haveValue[7])
        {
            haveValue[1] = false;
            haveValue[4] = false;
            haveValue[7] = true;

            if (valT[1] != "") temp[0] = std::stoi(valT[1]);
            if (valT[4] != "") temp[1] = std::stoi(valT[4]);
            if (valT[7] != "") temp[2] = std::stoi(valT[7]);

            for (int i = 0; i < 3; i++)
            {
                if (temp[i] > 0) ac += temp[i];
            }

            valT[7] = std::to_string(ac);
            isOld[7] = true;
            valT[1] = "";
            valT[4] = "";

            for (int i = 0; i < 2; i++)
            {
                temp[3] = dist(rng);
                GenNew(temp[3]);
            }
            genC = 1;
            ac = 0;
        }

        if (haveValue[2] || haveValue[5] || haveValue[8])
        {
            haveValue[2] = false;
            haveValue[5] = false;
            haveValue[8] = true;

            if (valT[2] != "") temp[0] = std::stoi(valT[2]);
            if (valT[5] != "") temp[1] = std::stoi(valT[5]);
            if (valT[8] != "") temp[2] = std::stoi(valT[8]);

            for (int i = 0; i < 3; i++)
            {
                if (temp[i] > 0) ac += temp[i];
            }

            valT[8] = std::to_string(ac);
            isOld[8] = true;
            valT[2] = "";
            valT[5] = "";

            for (int i = 0; i < 2; i++)
            {
                temp[3] = dist(rng);
                GenNew(temp[3]);
            }
            genC = 1;
        }
    }
}

void SetTileVal(int z)
{
    val = valT[z].c_str();
}

void GenNew(int a)
{
    if (!haveValue[a])
    {
        std::cout << haveValue << std::endl;
        haveValue[a] = true;
    }
}
