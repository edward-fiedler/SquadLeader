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
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	};

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta);
	Location GetNextHeadLocation(const Location& delta) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& tile_loc) const;
	bool IsInTile(const Location& tile_loc) const;
};