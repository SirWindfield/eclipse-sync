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

Vektor::Vektor(double inX, double inY, double inZ) :
        x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

double Vektor::getX() const
{
    return x;
}

double Vektor::getY() const
{
    return y;
}

double Vektor::getZ() const
{
    return z;
}

Vektor Vektor::sub(const Vektor& vec) const
{
    return Vektor(x - vec.x, y - vec.y, z - vec.z);
}

Vektor Vektor::add(const Vektor& vec) const
{
    return Vektor(x + vec.x, y + vec.y, z + vec.z);
}

bool Vektor::ortho(const Vektor& vec) const
{
    return scalarProd(vec) == 0;
}

double Vektor::scalarProd(const Vektor& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z;
}

double Vektor::length() const
{
    double sx = pow(x, 2);
    double sy = pow(y, 2);
    double sz = pow(z, 2);
    return sqrt(sx + sy + sz);
}

double Vektor::angle(const Vektor& vec) const
{
    double scalar = scalarProd(vec);
    double rad = acos(scalar / (length() * vec.length()));
    return rad * (180 / M_PI);
}

void Vektor::rotateAroundZ(const double rad) {

}

void Vektor::ausgabe() const
{
    std::cout << "Vector[x=" << x << ", y=" << y << ", z=" << z << "]"
            << std::endl;

}
