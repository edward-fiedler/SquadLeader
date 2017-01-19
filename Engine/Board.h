#pragma once

#include "Graphics.h"
#include "Location.h"
#include <assert.h>

#define TILE_SIZE 20;
#define BOARD_WIDTH 32;
#define BOARD_HEIGHT 24;

class Board
{
private:
	static const int dimension = TILE_SIZE;
	static const int width = BOARD_WIDTH;
	static const int height = BOARD_HEIGHT;
	static const int borderWidth = 4;
	static const int borderPadding = 2;
	static const int cellPadding = 1;
	static const int x = 70;
	static const int y = 50;
	Graphics& gfx;
	static constexpr Color borderColor = Colors::Blue;

public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	bool IsInsideBoard(const Location& loc) const;
	int GetGridWidth() const;
	int GetGridHeight() const;
	void DrawBorder();
};