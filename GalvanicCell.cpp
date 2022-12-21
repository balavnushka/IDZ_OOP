#include "GalvanicCell.h"

using namespace System::Drawing;

GalvanicCell::GalvanicCell(Point point) {
	this->p = point;
	type = 5;
}
Point GalvanicCell::getGalvanicCell() {
	return p;
}
void GalvanicCell::setGalvanicCell(Point point) {
	this->p = point;
}
void GalvanicCell::draw(Graphics^ g) {
	Image^ img = Image::FromFile("galvaniccell.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}
Element^ GalvanicCell::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;
}
