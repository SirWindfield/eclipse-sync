#include "city.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include <QString>


City::City(QString name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;
}

void City::draw(QGraphicsScene &scene, QPen pen) {
    scene.addEllipse(x, y, 4, 4, pen);

    // draw label
    QGraphicsTextItem *item = new QGraphicsTextItem();
    item->setPlainText(name);
    item->setPos(x + 5, y - 10);
    scene.addItem(item);

    qDebug() << QString("Added City %1").arg(name);
}

QString City::getName() const {
    return this->name;
}

int City::getX() const {
    return this->x;
}

int City::getY() const {
    return this->y;
}
