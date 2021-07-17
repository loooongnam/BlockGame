#pragma once

struct TileMap
{
	raylib::Vector2 tilePos[9];

	void GenTileMap(int numberOfTiles)
	{
		float sub = ((float)GetScreenHeight() / 7.25f);
		if (sub > 60.0f) sub = 60.0f;
		float height = (float)GetScreenHeight() - sub;
		float width = (float)GetScreenWidth() - 10.0f;

		raylib::Rectangle rec(5, (fontSize * 1.6f) + 5, width, height);

		int z = 0;
		for (float y = 7.0f; y <= 247.0f; y += 120)
		{
			for (float x = 7.0f; x <= 247.0f; x += 120)
			{
				tilePos[z] = raylib::Vector2(rec.x + x, rec.y + y);
				z++;
				if (z > 8) z = 0;
			}
		}
	}

	raylib::Vector2 GetTileMap(int index)
	{
		return tilePos[index];
	}
};

namespace my
{
	raylib::Vector2 tilePos[9];

	void GenTilesPosition(TileMap tileMap)
	{
		for (int i = 0; i <= 8; i++)
		{
			tilePos[i] = tileMap.GetTileMap(i);
			DrawRectangleRoundedV(tilePos[i]);
		}
	}

	void SetTilePosition()
	{

	}

	void GetTilePosition()
	{

	}
}
