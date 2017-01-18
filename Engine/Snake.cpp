#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) 
	{
		segments[nSegments].InitBody();
		++nSegments;
	}
}


Location Snake::GetNextHeadLocation(const Location & delta) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta);
	return l;
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::IsInTileExceptEnd(const Location & tile_loc) const
{
	for (int i = 0; i < nSegments-1; ++i)
	{
		if (segments[i].GetLocation() == tile_loc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location & tile_loc) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == tile_loc)
		{
			return true;
		}
	}
	return false;
}



//---------Segment Functions------------

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta)
{
	assert(abs(delta.x) + abs(delta.y) == 1);
	loc.Add(delta);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
