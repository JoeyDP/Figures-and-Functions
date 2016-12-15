#include "figure/FunctionFigure.h"

#include "figure/Rectangle.h"

namespace figure {

FunctionFigure::FunctionFigure(std::initializer_list<XYFunction> inequations):
	inequations(inequations)
{
}

Rectangle FunctionFigure::getBoundingBox() const {
}

bool FunctionFigure::contains(double x, double y) const {
	Point variables(x, y);

	for(const XYFunction& function:inequations){
		if(function.evaluate(variables)){
			return false;
		}
	}
	return true;
}

} /* namespace figure */
