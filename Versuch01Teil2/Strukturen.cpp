//
// Created by Sven on 2017-04-23.
//
#include <iostream>
#include <string>
#include "Strukturen.h"

struct Person {
    std::string sVorname;
    std::string sNachname;
    int iGeburtsjahr;
    int iAlter;
};

std::ostream& operator <<(std::ostream& os, const Person& person) {
    return os << "Vorname: " << person.sVorname << std::endl
              << "Nachname: " << person.sNachname << std::endl
              << "Alter: " << person.iAlter << std::endl
              << "Geburtsjahr: " << person.iGeburtsjahr << std::endl
              << std::string(25, '-') << std::endl;
}

int main() {
    Person nBenutzer;

    std::cout << "Gib deinen Vornamen ein: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Gib deinen Nachnamen ein: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Gib dein Alter ein: ";
    std::cin >> nBenutzer.iAlter;
    std::cout << "Gib dein Geburtsjahr ein: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << nBenutzer;

    // Einzeln kopieren
    Person nKopieEinfach;
    nKopieEinfach.sVorname = nBenutzer.sVorname;
    nKopieEinfach.sNachname = nBenutzer.sNachname;
    nKopieEinfach.iAlter = nBenutzer.iAlter;
    nKopieEinfach.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    std::cout << nKopieEinfach;

    // Komplett kopieren
    Person nKopieGesamt = nBenutzer;
    std::cout << nKopieGesamt;
    return 0;
}