#pragma once
#include <cliext/list>
#include "Element.h"

ref class DrawingField
{
private:
	cliext::list<Element^> elements;

public:
	void addElement(Element^ element);
	void drawElement(Graphics^ g);
	Element^ findElement(int x, int y);
	void deleteElement(Element^ element);
	void clear();
};
