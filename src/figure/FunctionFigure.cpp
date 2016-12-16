#include "figure/FunctionFigure.h"

#include "figure/Rectangle.h"

namespace figure {

FunctionFigure::FunctionFigure(std::initializer_list<function::Function> inequations):
	inequations(inequations)
{
}

Rectangle FunctionFigure::getBoundingBox() const {
	// TODO implement

	return Rectangle(0, 0);
}

bool FunctionFigure::contains(double x, double y) const {
	Point variables(x, y);

	for(const function::Function& function:inequations){
		if(function.evaluate(variables)){
			return false;
		}
	}
	return true;
}

} /* namespace figure */
