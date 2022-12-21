#include "Line.h"
#include <cmath>

Line::Line(Point one, Point two)
{
	this->one = one;
	this->two = two;
	type = 1;
}



Point Line::getFirst()
{
	return one;
}

Point Line::getSecond()
{
	return two;
}

void Line::setFirst(Point p)
{
	one = p;
}

void Line::setSecond(Point p)
{
	two = p;
}

void Line::draw(Graphics^ g)
{
	g->DrawLine(gcnew Pen(Color::Black, 6), one, two);
}

Element^ Line::find(int x, int y)
{
	if (x < fmin(one.X, two.X) - 3 || x > fmax(one.X, two.X) + 3 || y < fmin(one.Y, two.Y) - 3 || y > fmax(one.Y, two.Y) + 3)
		return nullptr;
	int ab = abs((one.Y - two.Y) * x + (two.X - one.X) * y + (one.X * two.Y - two.X * one.Y));
	if (sqrt(abs((one.Y - two.Y) * x + (two.X - one.X) * y + (one.X * two.Y - two.X * one.Y))) <= 49)
		return this;
	return nullptr;
}
