#include "city.h"
#include "map.h"

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
        if(QString::compare(city->getName(), city_name, Qt::CaseSensitive)) {
            return city;
        }
    }
    return NULL;
}

std::vector<City*> Map::getCities() {
    return cities;
}

void Map::draw(QGraphicsScene &scene) {
    for(City* city : cities) {
        city->draw(scene);
    }
}
