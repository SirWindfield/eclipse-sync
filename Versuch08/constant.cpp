
#include <iostream>
#include "constant.h"

ConstExpression::ConstExpression(double value) {
	this->value = value;
}

ConstExpression::~ConstExpression() {
	std::cout << "Deleted ConstExpression@" << this << std::endl;
}

double ConstExpression::evaluate() const {
	return value;
}

void ConstExpression::print() const {
	std::cout << evaluate();
}

std::ostream& operator <<(std::ostream &out, ConstExpression &expression) {
	expression.print();
	return std::cout;
}
