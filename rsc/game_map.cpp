#include "game_map.h"
#include<iostream>
void GameMap::LoadMap()
{
	/*FILE* fp = NULL;
	errno_t err = fopen_s(&fp,name, "rb");
	if (err!=0||fp == NULL)
	{
		return;
	}
	game_map_.max_x_ = 0;
	game_map_.max_y_ = 0;
	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{
			fscanf_s(fp, "%d", &game_map_.tile[i][j]);
			int val = game_map_.tile[i][j];
			if (val > 0)
			{
				if (j > game_map_.max_x_)
				{
					game_map_.max_x_ = j;
				}
				if (i > game_map_.max_y_)
				{
					game_map_.max_y_ = i;
				}
			}
		}
	}

	game_map_.max_x_ = (game_map_.max_x_ + 1) * TILE_SIZE;
	game_map_.max_y_ = (game_map_.max_y_ + 1) * TILE_SIZE;

	

	game_map_.file_name = name;*/
	
	int k = 0;
	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{
			game_map_.tile[i][j] =map01[k]; k++;
		}
	}


}

void GameMap::LoadTiles(SDL_Renderer* screen)
{
	char file_img[20];
	FILE* fp = NULL;

	for (int i = 0; i < MAX_TILES; i++)
	{
		sprintf_s(file_img, "map01/%d.png", i);

		fopen_s(&fp, file_img, "rb");
		if (fp == NULL)
		{
			continue;
		}
		

		tile_mat[i].LoadImg(file_img, screen);
		
	}fclose(fp);
}

void GameMap::DrawMap(SDL_Renderer* screen)
{
	int x1 = 300;
	int x2 = 870;

	int y1 = 0;
	int y2 = 660;

	int map_x = 0;
	int map_y = 0;

	for (int i = y1; i < y2; i += TILE_SIZE)
	{
		map_x = 0;
		for (int j = x1; j < x2; j += TILE_SIZE)
		{
			int val = game_map_.tile[map_y][map_x];
			if (val > 0)
			{
				tile_mat[val].setRect(j, i);
				tile_mat[val].ApplyRender(screen,NULL);
			}
			map_x++;
		}
		map_y++;
	}
}