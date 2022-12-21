#pragma once
#include "Element.h"
ref class Ammeter :
    public Element
{
private:
    Point p;
    int width, height;
public:
    Ammeter(Point point);
    Point getAmmeter();
    void setAmmeter(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Element^ find(int x, int y) override;
};
