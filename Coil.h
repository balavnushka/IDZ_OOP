#pragma once
#include "Element.h"
ref class Coil :
    public Element
{
private:
    Point p;
    int width, height;
public:
    Coil(Point point);
    Point getCoil();
    void setCoil(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Element^ find(int x, int y) override;
};
