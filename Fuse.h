#pragma once
#include "Element.h"
using namespace System::Drawing;
ref class Fuse :
    public Element
{
private:
    Point p;
    int width, height;
public:
    Fuse(Point point);
    Point getFuse();
    void setFuse(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Element^ find(int x, int y) override;
};
