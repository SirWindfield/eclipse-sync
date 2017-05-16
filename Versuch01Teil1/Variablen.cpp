//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Variablen.h"

// returns the length of a passed array, independent of the used data type
template <typename T, size_t S>
inline unsigned int asize(const T (&V)[S])
{
    // it will basically accept any array passed to it by reference and just return the length.
    // the compiler will infer the <args> automatically, no need to pass them.
    return S;
};

int main()
{
    exercise1_2_3();
    std::cout << std::string(15, '-') << std::endl;
    exercise4_6_7();
    std::cout << std::string(15, '-') << std::endl;
    exercise5();
    std::cout << std::string(15, '-') << std::endl;

    return 0;
}

/**
 * Exercise 1, 2, 3
 */
void exercise1_2_3()
{
    int iErste, iZweite;

    // Einlesen der Zahlen
    std::cout << "Please enter an integer value:";
    std::cin >> iErste;
    std::cout << "Do it again:";
    std::cin >> iZweite;

    // Berechnung der Werte
    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;
    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    double dSummeCast = (double) iErste + (double) iZweite;
    double dQuotientCast = (double) iErste / (double) iZweite;

    // Ausgabe
    std::cout << "[Integer]" << std::endl;
    std::cout << "\tQuotient: " << iQuotient << std::endl;
    std::cout << "\tSumme: " << iSumme << std::endl;

    std::cout << "[Double]" << std::endl;
    std::cout << "\tQuotient: " << dQuotient << std::endl;
    std::cout << "\tSumme: " << dSumme << std::endl;

    std::cout << "[Double (casted)]" << std::endl;
    std::cout << "\tQuotient: " << dQuotientCast << std::endl;
    std::cout << "\tSumme: " << dSummeCast << std::endl;
}

/**
 * Exercise 5
 */
void exercise5()
{
    { // Block erstellen, wie in der Aufgabe gefragt
        int iFeld[2] = {1, 2};
        // ANTWORT: Die Werte können über den Indizes 0 und 1 abgerufen werden

        int spielfeld[2][3] = {
                {1, 2, 3},
                {4, 5, 6}
        };
        // ANTWORT: Gültiger Indizeebereich: [0-1][0-2]

        for(int i = 0; i < asize(iFeld); i++)
        {
            std::cout << "iFeld[" << i << "] = " << iFeld[i] << std::endl;
        }
        for(int i = 0; i < asize(spielfeld); i++)
        {
            for(int j = 0; j < asize(spielfeld[i]); j++)
            {
                std::cout << "spielfeld[" << i << "] = " << spielfeld[i][j] << std::endl;
            }
        }

        // Neuer Block -> kein Kompilierfehler, da ich aber eine eigene Funktion benutzt habe macht const hier keinen Sinn :D
        const int iZweite = 1;
        std::cout << "const int iZweite = " << iZweite << std::endl;
    }
}

/**
 * Exercise 4, 6, 7
 */
void exercise4_6_7()
{
    std::string sVorname, sNachname;
    std::cout << "Gib deinen Vornamen ein: ";
    std::cin >> sVorname;
    std::cout << "Gib deinen Nachnamen ein: ";
    std::cin >> sNachname;

    std::string sVornameName = sVorname + " " + sNachname;
    std::string sNameVorname = sNachname + ", " + sVorname;

    std::cout << sVornameName << std::endl;
    std::cout << sNameVorname << std::endl;

    int iName1 = sVorname[0];
    int iName2 = sVorname[1];

    std::cout << "Erster Buchstabe: " << getIndexInAlphabet(iName1) << std::endl;
    std::cout << "Zweiter Buchstabe: " << getIndexInAlphabet(iName2) << std::endl;
}

int getIndexInAlphabet(int character)
{
    // just convert letters, ignore numbers and symbols
    int lower = character > 96 && character < 123 ? character - 32 : character;
    return lower - 'A'; // code-point 65
}
