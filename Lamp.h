#pragma once
#include "Element.h"
using namespace System::Drawing;
ref class Lamp :
    public Element
{
private:
    Point p;
    int width, height;
public:
    Lamp(Point point);
    Point getLamp();
    void setLamp(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Element^ find(int x, int y) override;
};
