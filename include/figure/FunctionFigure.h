#ifndef SRC_FIGURE_FUNCTIONFIGURE_H_
#define SRC_FIGURE_FUNCTIONFIGURE_H_

#include <initializer_list>
#include <vector>

#include "Figure.h"
#include "function/Function.h"

namespace figure {

using Point = std::pair<double, double>;

class FunctionFigure: public Figure{
private:
	std::vector<function::Function> inequations;

public:
	FunctionFigure(std::initializer_list<function::Function> functions);
	virtual ~FunctionFigure(){}

	virtual Rectangle getBoundingBox() const;
	virtual bool contains(double x, double y)const;
};

} /* namespace figure */

#endif /* SRC_FIGURE_FUNCTIONFIGURE_H_ */
