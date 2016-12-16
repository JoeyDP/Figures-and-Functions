/*
 * Function.h
 *
 *  Created on: Dec 15, 2016
 *      Author: joey
 */

#ifndef INCLUDE_FUNCTION_FUNCTION_H_
#define INCLUDE_FUNCTION_FUNCTION_H_

#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>

#include "function/Operator.h"

namespace function {

class Function {
private:
	std::vector<Operator*> postfix;
	std::vector<Operator*> toDelete;

	std::list<Operator*> tokenize(const std::string& expression);
public:
	Function(const std::string& expression);

	template <typename Variables = Variables>
	double evaluate(const Variables& variables) const;

	template <typename Variables = Variables>
	double operator()(const Variables& variables) const{return evaluate(variables);}
};


template<typename Variables>
inline double Function::evaluate(const Variables& variables) const {
	std::stack<double> operands;
	for(const Operator* op:postfix){
//		std::cout << "Perfoming op: " << op->toString() << std::endl;
		op->operate(operands, variables);
	}

	if(operands.size() != 1){
		throw "Something went wrong evaluating function.";
	}

	return operands.top();
}

} /* namespace function */


#endif /* INCLUDE_FUNCTION_FUNCTION_H_ */
