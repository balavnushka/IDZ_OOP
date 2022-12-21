#pragma once
#include "Element.h"
ref class GalvanicCell :
    public Element
{
private:
    Point p;
    int width, height;
public:
    GalvanicCell(Point point);
    Point getGalvanicCell();
    void setGalvanicCell(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Element^ find(int x, int y) override;
};
