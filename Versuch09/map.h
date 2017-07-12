#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include "city.h"
#include "street.h"

#include <QGraphicsScene>
#include <vector>

class Map: public AbstractMap
{

public:
    Map();
    void addCity(City *city);
    void draw(QGraphicsScene &scene);
    std::vector<City*> getCities();
    bool addStreet(Street *street);
    City* find_city(const QString city_name) const;


private:
    std::vector<City*> cities;
    std::vector<Street*> streets;
};

#endif // MAP_H
