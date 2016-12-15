#ifndef INCLUDE_FIGURE_ELLIPS_H_
#define INCLUDE_FIGURE_ELLIPS_H_

#include <iostream>

#include "figure/Rectangle.h"

namespace figure {

/**
 * Ellips with one axis length: width and other axis length: height.
 * Center at (width/2, height/2)
 */
class Ellips: public Rectangle{
private:
public:
	Ellips(double width, double height);
	virtual ~Ellips(){}

	virtual double getSurface() const;
	virtual bool contains(double x, double y)const;
};

} /* namespace figure */

#endif /* INCLUDE_FIGURE_ELLIPS_H_ */
