/*
 * mul_expression.h
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */

#ifndef MUL_H_
#define MUL_H_

#include "expression.h"

class MulExpression: public Expression {
public:
	MulExpression(Expression *left, Expression *right);
	virtual ~MulExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};

#endif /* MUL_H_ */
