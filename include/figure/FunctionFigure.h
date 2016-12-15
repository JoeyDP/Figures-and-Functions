#ifndef SRC_FIGURE_FUNCTIONFIGURE_H_
#define SRC_FIGURE_FUNCTIONFIGURE_H_

#include <initializer_list>
#include <vector>

#include "Figure.h"
#include "function/Function.h"

namespace figure {

using Point = std::pair<double, double>;
using XYFunction = function::Function<Point>;

class FunctionFigure: public Figure{
private:
	std::vector<XYFunction> inequations;

public:
	FunctionFigure(std::initializer_list<XYFunction> functions);
	virtual ~FunctionFigure(){}

	virtual Rectangle getBoundingBox() const;
	virtual bool contains(double x, double y)const;
};

} /* namespace figure */

#endif /* SRC_FIGURE_FUNCTIONFIGURE_H_ */
