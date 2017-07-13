#include "street.h"

#include <QDebug>

Street::Street(City *first, City *second)
{
    this->first = first;
    this->second = second;
}

City* Street::getFirstCity() const {
    return this->first;
}

City* Street::getSecondCity() const {
    return this->second;
}
void Street::draw(QGraphicsScene &scene, QPen pen) {
    scene.addLine(getFirstCity()->getX(), getFirstCity()->getY(), getSecondCity()->getX(), getSecondCity()->getY(), pen);
    qDebug() << "Street drawn from " << getFirstCity()->getName() << " to " << getSecondCity()->getName();
}
