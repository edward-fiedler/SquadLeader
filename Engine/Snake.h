#pragma once

#include "Board.h"




class Snake
{

private:
	
	class Segment
	{
	private:
		Location loc;
		Color c;
	public:
		void InitHead(const Location& loc);
		void InitBody(Color c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	};
	//Merging practice
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	static const int nBodyColors = 4;
	const Color bodyColors[nBodyColors] =
	{
		{ 10, 100, 32 },
		{ 10, 130, 48 },
		{ 18, 160, 48 },
		{ 10, 145, 48 }
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta);
	Location GetNextHeadLocation(const Location& delta) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& tile_loc) const;
	bool IsInTile(const Location& tile_loc) const;
};