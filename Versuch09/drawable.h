#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QGraphicsScene>

class Drawable
{
public:
    virtual void draw(QGraphicsScene &scene) = 0;
};

#endif // DRAWABLE_H
