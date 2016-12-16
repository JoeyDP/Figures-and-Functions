#include "function/Function.h"

#include <stack>
#include <string>
#include <iostream>

namespace function {

Function::Function(const std::string& expression) {
	std::stack<Operator*> operators;

	std::list<Operator*> tokens = tokenize(expression);
	for(Operator* op:tokens){
//		std::cout << "Parsing: " << op->toString() << std::endl;

		if(!operators.empty()){
			Operator* top = operators.top();
			while(*op < *top){
//				std::cout << "Operators pop : " << top->toString() << std::endl;
				postfix.push_back(top);
				operators.pop();
				if(operators.empty()){
					break;
				}
				top = operators.top();
			}
		}

//		std::cout << "Operators push: " << op->toString() << std::endl;
		operators.push(op);
	}

	while(!operators.empty()){
//		std::cout << "Operators pop : " << operators.top()->toString() << std::endl;
		postfix.push_back(operators.top());
		operators.pop();
	}

	for(Operator* op:postfix){
		std::cout << op->toString();
	}
	std::cout << std::endl;


	/**
	for(std::string::iterator it = expression.begin();it != expression.end();){ // ++ handled in loop
		char c = *it;
//		std::cout << "outer: " << c << std::endl;

		Operator* foundOperator = 0;

		if(c == 'x'){
			postfix.push_back(&variableXOperator);
			it++;
			continue;
		}else if(c == 'y'){
			postfix.push_back(&variableYOperator);
			it++;
			continue;
		}else if(c == '+'){
			foundOperator = &opPlus;
//		}else if(c == '-'){
//			foundOperator = &opMinus;
//		}else if(c == '*'){
//			foundOperator = &opMult;
//		}else if(c == '/'){
//			foundOperator = &opDiv;
//		}else if(c == '^'){
//			foundOperator = &opPow;
//		}else if(c == 's'){
//			char second = *(++it);
//			char third = *(++it);
//			if(second == 'i' && third == 'n'){
//				foundOperator = &opSin;
//			}else if(second == 'q' && third == 'r' && *(++it) == 't'){
//				foundOperator = &opSqrt;
//			}else{
//				std::cerr << "started with s but didn't mean sin or sqrt?" << std::endl;
//			}
//		}else if(c == 'c'){
//			it++;
//			if(*it == 'o' && *(++it) == 's'){
//				foundOperator = &opCos;
//			}else{
//				std::cerr << "started with c but didnt mean cos?" << std::endl;
//			}
//		}else if(c == '('){
//			operators.push(&bracketOpen);
//			it++;
//			continue;
//		}else if(c == ')'){
//			Operator* top = operators.top();
//			while(top != &bracketOpen){
//				postfix.push_back(top);
//				operators.pop();
//				top = operators.top();
//			}
//			operators.pop();
//			it++;
//			continue;
		}

		if((foundOperator)){
			bool whileBool = !operators.empty();
			Operator* top=0;
			if(whileBool){
				top = operators.top();
				whileBool = top != &bracketOpen && *foundOperator <= *top;
			}
			while(whileBool){
				postfix.push_back(top);
				operators.pop();

				whileBool = !operators.empty();
				if(whileBool){
					top = operators.top();
					whileBool = top != &bracketOpen && *foundOperator <= *top;
				}
			}
			operators.push(foundOperator);
			it++;
			continue;
		}

		std::string fullExpr = "";
		while(('0' <= c && c <= '9') || c== '.'){
			fullExpr += c;
			it++;
			c = *it;
//			std::cout << c << std::endl;
		}
		if(fullExpr.size() > 0){
			double value = atof(fullExpr.c_str());
			Operator* item = new ConstantOperator(value);
			postfix.push_back(item);
			toDelete.push_back(item);
			continue;
		}

		std::cout << "Unused symbol: " << c << std::endl;
		it++;
	}
	while(!operators.empty()){
		postfix.push_back(operators.top());
		operators.pop();
	}
	**/
}

std::list<Operator*> Function::tokenize(const std::string& expression) {
	std::list<Operator*> tokens;
	size_t index = 0;

	// first operator names
	while(index < expression.size()){
		while(isspace(expression[index])){
			++index;
		}

//		std::cout << "Expression: " << expression.substr(index) << std::endl;

		bool foundSomething = false;
		for(const Operator::OperatorToken& opToken : Operator::getOperators()){
			const std::string& name = opToken.first;
			if(expression.compare(index, name.size(), name) == 0){
				tokens.push_back(opToken.second);

				index += name.size();
				foundSomething = true;
				break;
			}
		}
		if(foundSomething){
			continue;
		}

		// then numbers

		// then variables


		// found nothing.
		std::cerr << "Failed to parse function at this point: " + expression.substr(index) << std::endl;
		throw;
	}

	return tokens;
}

} /* namespace function */


