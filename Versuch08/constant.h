/*
 * constant.h
 *
 *  Created on: 09.07.2017
 *      Author: Sven
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "expression.h"

class ConstExpression: public Expression {
public:
	ConstExpression(double value);
	virtual ~ConstExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	double value;
};


#endif /* CONSTANT_H_ */
