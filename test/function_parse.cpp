
#include <math.h>

#include "gtest/gtest.h"

#include "function/Function.h"

TEST(FunctionParse, x){
	double x = 42.42;
	std::pair<double, double> variables1(x, 5.0);

	function::Variables variables2;
	variables2["x"] = x;

	function::Function f("x");

	ASSERT_EQ(f.evaluate(variables1), x);
	ASSERT_EQ(f.evaluate(variables2), x);
}

TEST(FunctionParse, y){
	double y =5;
	std::pair<double, double> variables1(8, y);

	function::Variables variables2;
	variables2["y"] = y;

	function::Function f("y");

	ASSERT_EQ(f.evaluate(variables1), y);
	ASSERT_EQ(f.evaluate(variables2), y);
}

TEST(FunctionParse, plus){
	double x = 42.42;
	double y = 5.5;
	std::pair<double, double> variables(x, y);

	function::Function f("x + y");
	ASSERT_EQ(f.evaluate(variables), x + y);

	f = function::Function("x + y + x + y + y");
	ASSERT_EQ(f.evaluate(variables), 2*x + 3*y);
}

TEST(FunctionParse, minus){
	double x = 42.42;
	double y = 5.5;
	std::pair<double, double> variables(x, y);

	function::Function f("x - y");
	ASSERT_EQ(f.evaluate(variables), x - y);

	f = function::Function("-x");
	ASSERT_EQ(f.evaluate(variables), -x);

	// Postfix notation can't differentiate between unary and binary minus in this case.
//	f = function::Function("x+-x");
//	ASSERT_EQ(f.evaluate(variables), x+-x);
}

TEST(FunctionParse, times){
	double x = 42.42;
	double y = 5.5;
	std::pair<double, double> variables(x, y);

	function::Function f("x * y");
	ASSERT_EQ(f.evaluate(variables), x * y);

	f = function::Function("x + x * y");
	ASSERT_EQ(f.evaluate(variables), x + x * y);

	f = function::Function("x * x + y");
	ASSERT_EQ(f.evaluate(variables), x * x + y);

	f = function::Function("y + x * x - y");
	ASSERT_EQ(f.evaluate(variables), y + x * x - y);
}

TEST(FunctionParse, divide){
	double x = 42.42;
	double y = 5.5;
	std::pair<double, double> variables(x, y);

	function::Function f("x / y");
	ASSERT_EQ(f.evaluate(variables), x / y);

	f = function::Function("x + x / y");
	ASSERT_EQ(f.evaluate(variables), x + x / y);

	f = function::Function("x / x + y");
	ASSERT_EQ(f.evaluate(variables), x / x + y);

	f = function::Function("y + x / x - y");
	ASSERT_EQ(f.evaluate(variables), y + x / x - y);
}
