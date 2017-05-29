/**
 * @file main.cpp
 */

#include <iostream>
#include "Vektor.h"
#include <cmath>
#include "main.h"

/**
 * Entry point of the application.
 */
int main()
{
    // needed vectors for the calculations (in km)
    Vektor human(0, (PLATFORM_HEIGHT_M + HUMAN_HEIGHT_M) / 1000, 0);
    Vektor earth(0, 6371, 0);
    Vektor head = earth.add(human);
    // the current view vector
    Vektor view_port = earth.sub(head);

    // debug
    head.ausgabe();
    view_port.ausgabe();

    double rad = 0;
    int steps = 0;
    while (!view_port.ortho(earth))
    {
        // rotate earth
        rad += DELTA_ROT;
        earth.rotateAroundZ(DELTA_ROT);

        // calculate view port
        view_port = earth.sub(head);
        steps++;
    }

    std::cout << "Sie koennen " << view_port.length() << " km weit sehen."
            << std::endl;
    std::cout << "Sie sind " << PLATFORM_HEIGHT_M << "m hoch." << std::endl;
    std::cout << "Der Winkel betraegt " << rad * (180 / M_PI) << " grad"
            << std::endl;
    std::cout << "Anzahl Steps: " << steps << std::endl;
    return 0;
}

