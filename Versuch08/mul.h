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

	/**
	 * @brief Constructor. Accepts two expressions that will get multiplied.
	 *
	 * @param left The first expression used for multiplied.
	 * @param right The second expression used for multiplied.
	 */
	MulExpression(Expression *left, Expression *right);

	/**
	 * @brief Destructor. Also deletes any passed expression references.
	 */
	virtual ~MulExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};

#endif /* MUL_H_ */
