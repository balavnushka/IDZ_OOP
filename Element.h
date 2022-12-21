#pragma once
using namespace System::Drawing;

ref class Element abstract
{
public:
	int type;
	virtual void draw(Graphics^ g) = 0;
	virtual Element^ find(int x, int y) = 0;
};
