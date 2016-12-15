#ifndef INCLUDE_FIGURE_RECTANGLE_H_
#define INCLUDE_FIGURE_RECTANGLE_H_

#include "figure/Figure.h"

namespace figure {

/**
 * Rectangle with width and height. Bottom left corner is (0, 0)
 */
class Rectangle: public SimpleFigure{
private:
	double width;
	double height;
public:
	Rectangle(double width, double height);
	virtual ~Rectangle(){}

	double getWidth() const {return width;}
	double getHeight() const {return height;}

	virtual Rectangle getBoundingBox() const;
	virtual double getSurface() const;
	virtual bool contains(double x, double y)const;
};

} /* namespace figure */

#endif /* INCLUDE_FIGURE_RECTANGLE_H_ */
