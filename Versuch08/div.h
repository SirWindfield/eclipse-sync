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

	/**
	 * @brief Constructor. Accepts two expressions taht will get divided.
	 *
	 * @param left THe first expression used for division.
	 * @param right The second expression used for division.
	 */
	DivExpression(Expression *left, Expression *right);

	/**
	 * @brief Destructor. Also deletes any passed expression references.
	 */
	virtual ~DivExpression();

	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};

#endif /* DIV_H_ */
