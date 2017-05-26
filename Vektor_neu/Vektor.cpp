//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <iostream>


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

double Vektor::getX() const {
    return x;
}

double Vektor::getY() const {
    return y;
}

double Vektor::getZ() const {
    return z;
}

double Vektor::length() const {
    double sx = pow(getX(), 2);
    double sy = pow(getY(), 2);
    double sz = pow(getZ(), 2);
    return sqrt(sx + sy + sz);
}


void Vektor::ausgabe() const
{
    std::cout << "x: " << getX() << std::endl;
    std::cout << "y: " << getY() << std::endl;
    std::cout << "z: " << getZ() << std::endl;
}
