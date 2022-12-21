#include "DrawingField.h"

void DrawingField::addElement(Element^ element)
{
    elements.push_front(element);
}

void DrawingField::drawElement(Graphics^ g)
{
    if (!elements.empty()) {
        for each (Element ^ element in elements) {
            element->draw(g);
        }
    }
}

Element^ DrawingField::findElement(int x, int y)
{
    Element^ result = nullptr;
    for each (Element ^ element in elements)
        if (element->find(x, y) != nullptr)
        {
            result = element;
            elements.remove(element);
            break;
        }

    return result;
}

void DrawingField::clear() {
    elements.clear();
}


void DrawingField::deleteElement(Element^ element)
{
    elements.remove(element);
}
