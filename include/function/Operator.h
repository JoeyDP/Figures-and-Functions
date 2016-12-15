#ifndef SRC_FUNCTION_OPERATOR_H_
#define SRC_FUNCTION_OPERATOR_H_

#include <stack>
#include <string>
#include <map>

namespace function {

using Variables = std::map<std::string, double>;


class Operator{
private:
	unsigned int precedence;
public:
	Operator(unsigned int precedence):
		precedence(precedence)
	{}
	virtual ~Operator(){}

	virtual void operate(std::stack<double>& operands) const=0;
	virtual void operate(std::stack<double>& operands, const Variables& variables) const{operate(operands);}
	virtual void operate(std::stack<double>& operands, const std::pair<double, double>& point) const{operate(operands);}
};

class ConstantOperator: public Operator{
private:
	double value;
public:
	ConstantOperator(double value);
	virtual ~ConstantOperator(){}

	virtual void operate(std::stack<double>& operands) const;
};

class VariableOperator: public Operator{
private:
	std::string name;
public:
	VariableOperator(std::string name);
	virtual ~VariableOperator(){}

	virtual void operate(std::stack<double>& operands, const Variables& variables) const;
};

class VariableXOperator: public Operator{
private:
public:
	VariableXOperator();
	virtual ~VariableXOperator(){}

	virtual void operate(std::stack<double>& operands, const std::pair<double, double>& point) const;
};

class VariableYOperator: public Operator{
private:
public:
	VariableYOperator();
	virtual ~VariableYOperator(){}

	virtual void operate(std::stack<double>& operands, const std::pair<double, double>& point) const;
};

class UnaryOperator: public Operator{
public:
	using Operator::Operator;
	virtual ~UnaryOperator(){}

	virtual void operate(std::stack<double>& operands) const;
	virtual double operate(double op1) const=0;
};

class BinaryOperator: public Operator{
public:
	using Operator::Operator;
	virtual ~BinaryOperator(){}

	virtual void operate(std::stack<double>& operands) const;
	virtual double operate(double op1, double op2) const=0;
};

class OperatorPlus: public BinaryOperator{
public:
	OperatorPlus():BinaryOperator(1){}
	virtual ~OperatorPlus(){}

	virtual double operate(double op1, double op2) const{
		return op1 + op2;
	}

}extern opPlus;

} /* namespace function */

#endif /* SRC_FUNCTION_OPERATOR_H_ */
