#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QPen>
#include <QGraphicsScene>

class Drawable
{
public:
    virtual void draw(QGraphicsScene &scene, QPen pen = QPen(Qt::black)) = 0;
};

#endif // DRAWABLE_H
