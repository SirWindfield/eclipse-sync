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
    std::vector<Street*> get_street_list(const City* city) const;
    City * get_opposite_city(const Street* street, const City* city) const;
    double get_length(const Street* street) const;


private:
    std::vector<City*> cities;
    std::vector<Street*> streets;
};

#endif // MAP_H
