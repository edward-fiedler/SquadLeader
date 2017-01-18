#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>

#define TILE_SIZE 20;
#define BOARD_WIDTH 25;
#define BOARD_HEIGHT 25;

class Board
{
private:
	static const int dimension = TILE_SIZE;
	static const int width = BOARD_WIDTH;
	static const int height = BOARD_HEIGHT;
	Graphics& gfx;

public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	bool IsInsideBoard(const Location& loc) const;
	int GetGridWidth() const;
	int GetGridHeight() const;
};