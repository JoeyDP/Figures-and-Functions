#ifndef SRC_FUNCTION_OPERATOR_H_
#define SRC_FUNCTION_OPERATOR_H_

#include <stack>
#include <list>
#include <map>
#include <string>

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

	bool operator<(const Operator& other) const{return precedence < other.precedence;}

	virtual void operate(std::stack<double>& operands) const{}
	virtual void operate(std::stack<double>& operands, const Variables& variables) const{operate(operands);}
	virtual void operate(std::stack<double>& operands, const std::pair<double, double>& point) const{operate(operands);}

	virtual std::string toString() const=0;

	// static part
public:
	using OperatorToken = std::pair<std::string, Operator*>;
	using OperatorList = std::list<OperatorToken>;

	static void registerOperator(Operator* op);
	static void registerOperator(const std::string& name, Operator* op);

	static const OperatorList getOperators();
private:
	static OperatorList operators;
};

class ConstantOperator: public Operator{
private:
	double value;
public:
	ConstantOperator(double value);
	virtual ~ConstantOperator(){}

	virtual void operate(std::stack<double>& operands) const;

	virtual std::string toString() const{return std::to_string(value);}
}extern constantOperator;

class VariableOperator: public Operator{
private:
	std::string name;
public:
	VariableOperator(std::string name);
	virtual ~VariableOperator(){}

	virtual void operate(std::stack<double>& operands, const Variables& variables) const;

	virtual std::string toString() const{return name;}
};

class VariableXOperator: public VariableOperator{
private:
public:
	VariableXOperator():VariableOperator("x"){}
	virtual ~VariableXOperator(){}

	virtual void operate(std::stack<double>& operands, const std::pair<double, double>& point) const;
}extern variableXOperator;

class VariableYOperator: public VariableOperator{
private:
public:
	VariableYOperator():VariableOperator("y"){}
	virtual ~VariableYOperator(){}

	virtual void operate(std::stack<double>& operands, const std::pair<double, double>& point) const;
}extern variableYOperator;

class UnaryOperator: public Operator{
public:
	using Operator::Operator;
	virtual ~UnaryOperator(){}

	virtual void operate(std::stack<double>& operands) const;
	virtual double operate(double op1) const=0;
};

class BinaryOperator: public UnaryOperator{
public:
	using UnaryOperator::UnaryOperator;
	virtual ~BinaryOperator(){}

	virtual void operate(std::stack<double>& operands) const;

	virtual double operate(double op1) const{throw "UnaryOperator::operate(double op1) called but not implemented for specific operator.";} // available for minus
	virtual double operate(double op1, double op2) const=0;
};

class OperatorPlus: public BinaryOperator{
public:
	OperatorPlus():BinaryOperator(1){}
	virtual ~OperatorPlus(){}

	virtual double operate(double op1, double op2) const{
		return op1 + op2;
	}

	virtual std::string toString() const{return "+";}
}extern opPlus;

class OperatorMinus: public BinaryOperator{
public:
	OperatorMinus():BinaryOperator(1){}
	virtual ~OperatorMinus(){}

	virtual double operate(double op1) const{
		return -op1;
	}

	virtual double operate(double op1, double op2) const{
		return op1 - op2;
	}

	virtual std::string toString() const{return "-";}
}extern opMinus;

class OperatorTimes: public BinaryOperator{
public:
	OperatorTimes():BinaryOperator(2){}
	virtual ~OperatorTimes(){}

	virtual double operate(double op1, double op2) const{
		return op1 * op2;
	}

	virtual std::string toString() const{return "*";}
}extern opTimes;

class OperatorDiv: public BinaryOperator{
public:
	OperatorDiv():BinaryOperator(2){}
	virtual ~OperatorDiv(){}

	virtual double operate(double op1, double op2) const{
		return op1 / op2;
	}

	virtual std::string toString() const{return "/";}
}extern opDiv;

} /* namespace function */

#endif /* SRC_FUNCTION_OPERATOR_H_ */
