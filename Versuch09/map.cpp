#include "city.h"
#include "map.h"

#include <cmath>
#include <QDebug>
#include <QGraphicsScene>

Map::Map()
{

}

void Map::addCity(City *city) {
    if(city != NULL) {
        cities.push_back(city);
    }
}

bool Map::addStreet(Street *street) {
    if(street == NULL) {
        return false;
    }
    // make sure the cities actually exist
    if(find_city(street->getFirstCity()->getName()) != NULL && find_city(street->getSecondCity()->getName()) != NULL) {
        streets.push_back(street);
        return true;
    }
    return false;
}

City* Map::find_city(const QString city_name) const {
    for(City *city : this->cities) {
        if(city->getName() == city_name) {
            return city;
        }
    }
    return NULL;
}

std::vector<Street*> Map::get_street_list(const City* city) const
{
    std::vector<Street*> result;
    for(Street* street : streets)
    {
        if(street->getFirstCity() == city || street->getSecondCity() == city)
        {
            result.push_back(street);
        }
    }
    return result;
}

City* Map::get_opposite_city(const Street* street, const City* city) const
{
    if(street->getFirstCity() == city) {
        return street->getSecondCity();
    } else if(street->getSecondCity() == city)
    {
        return street->getFirstCity();
    } else {
        return NULL;
    }
}

double Map::get_length(const Street* street) const
{
    double dx = abs(street->getFirstCity()->getX() - street->getSecondCity()->getX());
    double dy = abs(street->getFirstCity()->getY() - street->getSecondCity()->getY());

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

std::vector<City*> Map::getCities() {
    return cities;
}

void Map::draw(QGraphicsScene &scene) {
    for(City* city : cities) {
        city->draw(scene);
    }
    for(Street* street : streets)
    {
        street->draw(scene);
    }
}
