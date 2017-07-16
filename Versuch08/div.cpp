/*
 * add_expression.cpp
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */
#include "div.h"
#include <iostream>

DivExpression::DivExpression(Expression *left, Expression *right) {
	this->left = left;
	this->right = right;
}

DivExpression::~DivExpression() {
	std::cout << "Deleted DivExpression@" << this << std::endl;
	delete left;
	delete right;
}

double DivExpression::evaluate() const {
	return left->evaluate() / right->evaluate();
}

void DivExpression::print() const {
	left->print();
	std::cout << " / ";
	right->print();
}
