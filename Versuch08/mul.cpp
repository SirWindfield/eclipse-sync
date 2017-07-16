#include "mul.h"
#include <iostream>

MulExpression::MulExpression(Expression *left, Expression *right) {
	this->left = left;
	this->right = right;
}

MulExpression::~MulExpression() {
	std::cout << "Deleted MulExpression@" << this << std::endl;
	delete left;
	delete right;
}

double MulExpression::evaluate() const {
	return left->evaluate() * right->evaluate();
}

void MulExpression::print() const {
	left->print();
	std::cout << " * ";
	right->print();
}
