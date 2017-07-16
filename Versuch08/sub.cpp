#include <iostream>
#include "sub.h"

SubExpression::SubExpression(Expression *left, Expression *right) {
	this->left = left;
	this->right = right;
}

SubExpression::~SubExpression() {
	std::cout << "Deleted SubExpression@" << this << std::endl;
	delete left;
	delete right;
}

double SubExpression::evaluate() const {
	return left->evaluate() - right->evaluate();
}

void SubExpression::print() const {
	std::cout << "(";
	left->print();
	std::cout << " - ";
	right->print();
	std::cout << ")";
}
