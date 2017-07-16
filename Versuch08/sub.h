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

	/**
	 * @brief Constructor. Accepts two expressions that will get subtracted.
	 *
	 * @param left THe first expression used for subtraction.
	 * @param right The second expression used for subtraction.
	 */
	SubExpression(Expression *left, Expression *right);

	/**
	 * @brief Destructor. Also deletes any passed expression references.
	 */
	virtual ~SubExpression();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression *left;
	Expression *right;
};

#endif /* SUB_H_ */
