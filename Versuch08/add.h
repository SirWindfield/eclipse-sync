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

	/**
	 * @brief Constructor. Accepts two expressions that will get added together.
	 *
	 * @param left The first expression used for addition.
	 * @param right The second expression used for addition.
	 */
	AddExpression(Expression *left, Expression *right);

	/**
	 * @brief Destructor. Also deletes any passed expression references.
	 */
	virtual ~AddExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};

#endif /* ADD_H_ */
