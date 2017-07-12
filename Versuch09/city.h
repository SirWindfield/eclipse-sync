#ifndef CITY_H
#define CITY_H

#include <QGraphicsScene>
#include <QString>

#include "drawable.h"

class City: public Drawable
{

public:
    City(QString name, int x, int y);
    int getX() const;
    int getY() const;
    QString getName() const;
    virtual void draw(QGraphicsScene &scene);

private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
