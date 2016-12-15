#ifndef INCLUDE_FIGURE_FIGURE_H_
#define INCLUDE_FIGURE_FIGURE_H_

#include <gsl/gsl_rng.h>


namespace figure {

// Forward declaration (bounding box)
class Rectangle;

class Figure{
public:
	virtual ~Figure(){}

	virtual Rectangle getBoundingBox() const=0;
	virtual bool contains(double x, double y)const =0;

	/**
	 * Uses random numbers to estimate the surface of the figure.
	 */
	double estimateSurface(unsigned int signDigits, gsl_rng *r, unsigned int iterations=1000, double accuracy=0.95) const;
};

class SimpleFigure: public Figure{
public:
	virtual double getSurface() const=0;
};

} /* namespace figure */

// Checks if estimate has enough significant digits in respect to the actual value.
bool hasEnoughSignDigits(double actual, double estimate, unsigned int signDigits, unsigned int base=10);

#endif /* INCLUDE_FIGURE_FIGURE_H_ */
