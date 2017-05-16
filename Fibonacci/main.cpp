#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "main.h"

int main(int argc, char* argv[]) {
    // Ausgabe rechtsseitig formatieren
    std::cout << std::right;
    for(int i = 0; i <= 25; i++) {
        // Ausgabe formatieren
        std::cout << "n(" << std::setfill('0') << std::setw(2) << i << "):" << std::setfill(' ') << std::setw(6);
        // fibonacci ausgeben
        std::cout << fib(i) << std::endl;
    }
    return 0;
}

unsigned int fib(unsigned int n) {
    return n == 0 ? 0 : n == 1 ? 1 : fib(n - 2) + fib(n - 1);
}
