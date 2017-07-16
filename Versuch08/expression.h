/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 8: Taschenrechner
 *
 * Datei:  expression.h
 * Inhalt: Headerdatei Abstrakte Klasse Expression
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:

	/**
	 * @brief Constructor.
	 */
	Expression();

	/**
	 * @brief Destructor.
	 */
	virtual ~Expression();

	/**
	 * @brief Evaluates the expression and returns the calculated value.
	 * @return The calculated double value.
	 */
	virtual double evaluate() const = 0; // calculates and returns the value of expression

	/**
	 * @brief Prints the expression in a readable way to std::cout.
	 */
	virtual void print() const = 0; // returns the mathematical expression as string
};

#endif
