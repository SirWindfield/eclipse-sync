//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Vektor.h"
#include <cmath>

double rnd3(double value)
{
    return round(value * 1000.0) / 1000.0;
}

void test()
{
    Vektor v1(1, 2, 3);
    Vektor v2(4, 5, 6);

    bool result = true;
    // test length
    if (rnd3(v1.length()) != 3.742 || rnd3(v2.length()) != 8.775)
    {
        std::cout << "Length test failed" << std::endl;
        result = false;
    }

    // test angle
    if (rnd3(v1.angle(v2)) != 12.933)
    {
        std::cout << "Angle test failed" << std::endl;
        result = false;
    }

    std::cout << (result ? "ALL TESTS PASSED" : "TESTS FAILED") << std::endl;
}

int main()
{
    test();

    // rotation
    Vektor v2(1, 2, 3);
    v2.rotateAroundZ(1);
    v2.ausgabe();
    return 0;
}
