#pragma once
#include <iostream>

constexpr auto CENTER = 0;
constexpr auto TOP = 1;
constexpr auto BOTTOM = 2;
constexpr auto LEFT = 3;
constexpr auto RIGHT = 4;

using namespace std;

float fontSize;

void DrawRectangleRoundedScore(float roundness, int segments, raylib::Color color, string text, raylib::Color textColor)
{
	fontSize = GetScreenWidth() / 12.5f;
	if (fontSize > 30) fontSize = 30;

	float x = 5;
	float y = 0;

	raylib::Rectangle rec(x, y, (float)GetScreenWidth() - 10.0f, fontSize * 1.6f);

	DrawRectangleRounded(rec, roundness, segments, color);

	x += (float)fontSize / 2.2f;
	y += (float)fontSize / 3.0f;

	DrawText(text.c_str(), (int)x, (int)y, (int)fontSize, textColor);
}

void DrawRectangleRoundedTileContainer(float roundness, int segments, raylib::Color color)
{
	float sub = ((float)GetScreenHeight() / 7.25f);
	if (sub > 60.0f) sub = 60.0f;
	float height = (float)GetScreenHeight() - sub;
	float width = (float)GetScreenWidth() - 10.0f;

	raylib::Rectangle rec(5, (fontSize * 1.6f) + 5, width, height);
	DrawRectangleRounded(rec, roundness, segments, color);
}

void DrawRectangleRoundedV(raylib::Vector2 vector)
{
	raylib::Rectangle rec(vector.x, vector.y, 110, 110);
	DrawRectangleRounded(rec, 0.05f, 10, raylib::Color(205, 193, 180));
}
