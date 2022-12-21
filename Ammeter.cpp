#include "Ammeter.h"

using namespace System::Drawing;

Ammeter::Ammeter(Point point) {
	this->p = point;
	type = 4;
}
Point Ammeter::getAmmeter() {
	return p;
}
void Ammeter::setAmmeter(Point point) {
	this->p = point;
}
void Ammeter::draw(Graphics^ g) {
	Image^ img = Image::FromFile("ammeter.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}
Element^ Ammeter::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;
}
