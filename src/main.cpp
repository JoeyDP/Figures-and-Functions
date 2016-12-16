
#include <iostream>

#include "figure/FunctionFigure.h"


int main(int argc, char* argv[]){

	function::Function f("x * x + y");
	std::cout << f.evaluate(std::make_pair(5, 7)) << std::endl;

	return 0;
}
