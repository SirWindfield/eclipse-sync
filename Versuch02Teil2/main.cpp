//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

/**
 * Ab n = 47 sind die Ergebnisse falsch, da der Wertebereich des Datentyps Integer ueberschritten wird. Normalerweise wird dann
 * bei der kleinsten Zahl angefangen.
 * Dies kann verhindert werden, indem man das int als unsigned definiert oder einen groesseren Datentypen verwendet
 * (mehr Bits -> groessere Zahlen). Dafuer eignet sich zum Beispiel long long.
 */
int fib(int n)
{
    int prevFib = 0;
    int currFib = 1;

    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {
        int newFib = prevFib + currFib;
        prevFib = currFib;
        currFib = newFib;
    }
    return currFib;
}

int main()
{
    std::cout << " Fibonacci - Zahlen :" << std::endl;
    for (int i = 1; i <= 48; i++)
    {
        std::cout << "f(" << i << ") = " << fib(i) << std::endl;
    }
    return 0;
}
