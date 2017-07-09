/*
 * div_expression.h
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */

#ifndef DIV_H_
#define DIV_H_

#include "expression.h"

class DivExpression: public Expression {
public:
	DivExpression(Expression *left, Expression *right);
	virtual ~DivExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};

#endif /* DIV_H_ */
