#include <iostream>
#include <string>
#include "main.h"

int main()
{
    std::cout << "Gib eine Nachricht ein: " << std::endl;
    std::string input;
    std::cin >> input;

    caeser(input, 17);

    return 0;
}

int encode(const char c, int offset)
{
    // 'z' - offset < c         -> noch Platz für die Verschiebung?
    // ja                       -> addieren
    // nein                     -> 1) Restplatz zwischen c und 'z' berechnen
    //                             2) Auf 'a' addieren (verschieben)
    //                             3) Index korrigieren wegen der Verschiebung
    return ('z' - offset < c) ? 'a' + (offset - ('z' - c) - 1) : c + offset;
}

int decode(const char c, int offset)
{
    return ('a' + offset > c) ? 'z' - (offset - (c - 'a')) + 1 : c - offset;
}

void caeser(std::string msg, int offset)
{
    std::cout << "Input: ";
    for (char& c : msg)
    {
        std::cout << (char) encode(std::tolower(c), offset);
    }
    std::cout << std::endl;

    std::cout << "Output: ";
    for (char& c : msg)
    {
        std::cout << (char) decode(encode(std::tolower(c), offset), offset);
    }
}
