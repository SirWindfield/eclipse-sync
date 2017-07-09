/*
 * add_expression.h
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */

#ifndef ADD_H_
#define ADD_H_

#include "expression.h"

class AddExpression: public Expression {
public:
	AddExpression(Expression *left, Expression *right);
	virtual ~AddExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};


#endif /* ADD_H_ */
