#include "Lamp.h"

using namespace System::Drawing;

Lamp::Lamp(Point point) {
	this->p = point;
	type = 2;
}
Point Lamp::getLamp() {
	return p;
}
void Lamp::setLamp(Point point) {
	this->p = point;
}
void Lamp::draw(Graphics^ g) {
	Image^ img = Image::FromFile("lamp.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}

Element^ Lamp::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;


}
