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

int main()
{ 
   Vektor v1(0,0,0); // objeckt
   Vektor *v = new Vektor(2,3,5); // -> pointer

   v->ausgabe();
   return 0;
}
