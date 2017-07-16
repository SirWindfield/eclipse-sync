
#include <iostream>
#include "result.h"

ResultExpression::ResultExpression(Expression *expression) {
	this->expression = expression;
}

ResultExpression::~ResultExpression() {
	std::cout << "Deleted ResultExpression@" << this << std::endl;
	delete expression;
}

double ResultExpression::evaluate() const {
	return expression->evaluate();
}

void ResultExpression::print() const {
	expression->print();
}
