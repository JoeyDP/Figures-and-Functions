#include "function/Operator.h"

#include "function/Function.h"

namespace function {

OperatorPlus opPlus;

ConstantOperator::ConstantOperator(double value):
	Operator(0),
	value(value)
{
}

void ConstantOperator::operate(std::stack<double>& operands) const {
	operands.push(value);
}

VariableOperator::VariableOperator(std::string name):
	Operator(0),
	name(name)
{
}

void VariableOperator::operate(std::stack<double>& operands, const Variables& variables) const {
	Variables::const_iterator it = variables.find(name);
	if(it != variables.end()){
		double value = it->second;
		operands.push(value);
	}else{
		throw "No variable with name " + name + " found.";
	}
}

void VariableXOperator::operate(std::stack<double>& operands, const std::pair<double, double>& point) const {
	operands.push(point.first);
}

void VariableYOperator::operate(std::stack<double>& operands, const std::pair<double, double>& point) const {
	operands.push(point.second);
}

void UnaryOperator::operate(std::stack<double>& operands) const{
	double op1 = operands.top();
	operands.pop();
	operands.push(operate(op1));
}

void BinaryOperator::operate(std::stack<double>& operands) const{
	double op1 = operands.top();
	operands.pop();
	double op2 = operands.top();
	operands.pop();
	operands.push(operate(op1, op2));
}

} /* namespace function */
