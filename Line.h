#pragma once
#include "Element.h"

ref class Line :
    public Element
{
private:
    Point one;
    Point two;

public:
    Line(Point one, Point two);

    Point getFirst();
    Point getSecond();

    void setFirst(Point p);
    void setSecond(Point p);

    virtual void draw(Graphics^ g) override;
    virtual Element^ find(int x, int y) override;

};
