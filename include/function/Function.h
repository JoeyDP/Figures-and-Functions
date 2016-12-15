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
#include <string>

#include "function/Operator.h"

namespace function {

template <typename Variables = Variables>
class Function {
private:
	std::vector<Operator*> postfix;
public:
	Function(const std::string& expression);

	double evaluate(const Variables& variables) const;
};

} /* namespace function */

#include "function/Function.cpp"


#endif /* INCLUDE_FUNCTION_FUNCTION_H_ */
