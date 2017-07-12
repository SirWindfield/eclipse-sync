/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 08: Taschenrechner
 *
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 */

#include <iostream>
#include "expression.h"
#include "constant.h"
#include "result.h"
#include "add.h"
#include "mul.h"
#include "sub.h"
#include "div.h"

void testConst() {
	ConstExpression c(4);
	c.print();
	std::cout << " = " << c.evaluate() << std::endl;
}

void testResult() {
	ResultExpression res(new ConstExpression(4));
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

void testAddConst() {
	ResultExpression res(
			new AddExpression(new ConstExpression(7), new ConstExpression(8)));
	res.print();
	// nur die obersten Objekte werden gelöscht, deren interne Expressions (left, right) bleiben im Speicher.
	std::cout << " = " << res.evaluate() << std::endl;
}

void testMulAddConst()
{
	ResultExpression res (	new AddExpression (
					new ConstExpression(4),
					new MulExpression (
						new ConstExpression(9),
						new ConstExpression(5)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

void testSubMulAddConst()
{
	ResultExpression res (new AddExpression (
					new ConstExpression(4),
					new MulExpression (
						new ConstExpression(9),
						new SubExpression (
							new ConstExpression(7),
							new ConstExpression(2)
						)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}


void finalTest()
{



	ResultExpression res (new AddExpression (
					new ConstExpression(4),
					new MulExpression (
						new ConstExpression(9),
						new SubExpression (
							new ConstExpression(7),
							new DivExpression (
								new ConstExpression(10),
								new ConstExpression(5)
								)
							)
						)
					)
		   );

	res.print();
	std::cout << " = ";
	std::cout << res.evaluate();
	std::cout << std::endl;

// Das Ergebnis sollte etwa so aussehen:
// (4 + (9 * (7 - (10 / 5)))) = 49

}

int main() {
	// Implementieren Sie zuerst die Klassen Const und Result und testen Sie das Ergebnis.
	testConst();
	testResult();

	// Erg�nzen Sie ihr Programm nach und nach um weitere Rechenoperationen
	testAddConst();
	testMulAddConst();
	testSubMulAddConst();
	std::cout << "Der finale Test: kommt noch..." << std::endl;
	finalTest();

	return 0;
}

