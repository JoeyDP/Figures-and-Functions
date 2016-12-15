
#include <iostream>

#include "figure/FunctionFigure.h"


int main(int argc, char* argv[]){

	figure::XYFunction f("y < x");

	figure::FunctionFigure figure1({f});

	return 0;
}
