/*
 * Function.cpp
 *
 *  Created on: Dec 15, 2016
 *      Author: joey
 */

#include <stack>
#include <iostream>

namespace function {

template<typename Variables>
inline Function<Variables>::Function(const std::string& expression) {
	// TODO parsing
}

template<typename Variables>
inline double Function<Variables>::evaluate(const Variables& variables) const {
	std::stack<double> operands;
	for(const Operator* op:postfix){
		op->operate(operands, variables);
	}

	if(operands.size() != 1){
		throw "Something went wrong evaluating function.";
	}

	return operands.top();
}


} /* namespace function */
