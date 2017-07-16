/*
 * add_expression.h
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */

#ifndef RESULT_H_
#define RESULT_H_

#include "expression.h"

class ResultExpression: public Expression {
public:
	ResultExpression(Expression *expression);
	virtual ~ResultExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *expression;
};


#endif /* RESULT_H_ */
