/*
 * sub_expression.h
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */

#ifndef SUB_H_
#define SUB_H_

#include "expression.h"

class SubExpression: public Expression {
public:
	SubExpression(Expression *left, Expression *right);
	virtual ~SubExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};


#endif /* SUB_H_ */
