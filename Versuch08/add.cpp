/*
 * add_expression.cpp
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */
#include "add.h"
#include "expression.h"
#include <iostream>

AddExpression::AddExpression(Expression *left, Expression *right) {
	this->left = left;
	this->right = right;
}

AddExpression::~AddExpression() {
	std::cout << "Deleted AddExpression@" << this << std::endl;
	delete left;
	delete right;
}

double AddExpression::evaluate() const {
	return left->evaluate() + right->evaluate();
}

void AddExpression::print() const {
	std::cout << "(";
	left->print();
	std::cout << " + ";
	right->print();
	std::cout << ")";
}
