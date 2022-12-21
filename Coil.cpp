#include "Coil.h"

using namespace System::Drawing;

Coil::Coil(Point point) {
	this->p = point;
	type = 6;
}
Point Coil::getCoil() {
	return p;
}
void Coil::setCoil(Point point) {
	this->p = point;
}
void Coil::draw(Graphics^ g) {
	Image^ img = Image::FromFile("coil.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}
Element^ Coil::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;
}
