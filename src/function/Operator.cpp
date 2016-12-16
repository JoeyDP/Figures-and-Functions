#include "function/Operator.h"

namespace function {

Operator::OperatorList Operator::operators;

OperatorPlus opPlus;
OperatorMinus opMinus;

OperatorTimes opTimes;
OperatorDiv opDiv;

VariableXOperator variableXOperator;
VariableYOperator variableYOperator;

void Operator::registerOperator(Operator* op) {
	registerOperator(op->toString(), op);
}

void Operator::registerOperator(const std::string& name, Operator* op) {
	operators.push_front(std::make_pair(name, op));
}

const Operator::OperatorList Operator::getOperators() {
	if(operators.empty()){
		registerOperator(&opPlus);
		registerOperator(&opMinus);

		registerOperator(&opTimes);
		registerOperator(&opDiv);

		registerOperator(&variableXOperator);
		registerOperator(&variableYOperator);
	}

	return operators;
}

ConstantOperator::ConstantOperator(double value):
	Operator(100),
	value(value)
{
}

void ConstantOperator::operate(std::stack<double>& operands) const {
	operands.push(value);
}

VariableOperator::VariableOperator(std::string name):
	Operator(100),
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
	if(operands.size() < 2){
		return UnaryOperator::operate(operands);
	}
	double op2 = operands.top();
	operands.pop();
	double op1 = operands.top();
	operands.pop();
	operands.push(operate(op1, op2));
}

} /* namespace function */


