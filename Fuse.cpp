#include "Fuse.h"

using namespace System::Drawing;

Fuse::Fuse(Point point) {
	this->p = point;
	type = 3;
}
Point Fuse::getFuse() {
	return p;
}
void Fuse::setFuse(Point point) {
	this->p = point;
}
void Fuse::draw(Graphics^ g) {
	Image^ img = Image::FromFile("fuse.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}

Element^ Fuse::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;


}
