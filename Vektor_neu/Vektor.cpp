/**
 * @file Vektor.cpp
 */

#include "Vektor.h"
#include <cmath>
#include <iomanip>
#include <iostream>

#define DELTA 0.1

Vektor::Vektor(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vektor::~Vektor()
{
    // nothing to do here...
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
    return fabs(scalarProd(vec)) < DELTA;
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

void Vektor::rotateAroundZ(const double rad)
{
    // calculate new positions using the rotation matrix provided within the pdf file
    double nx = x * cos(rad) - y * sin(rad);
    double ny = x * sin(rad) + y * cos(rad);
    // set new values
    x = nx;
    y = ny;
}

void Vektor::ausgabe() const
{
    std::cout << std::fixed << std::setprecision(4) << "Vector@" << this
            << "[x=" << x << ", y=" << y << ", z=" << z << "]" << std::endl;

}
