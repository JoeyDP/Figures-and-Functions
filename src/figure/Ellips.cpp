#include "figure/Ellips.h"

#include <math.h>

namespace figure {

Ellips::Ellips(double width, double height) :
	Rectangle(width, height)
{
}

double Ellips::getSurface() const {
	return M_PI * getWidth() * getHeight() / 4;
}

bool Ellips::contains(double x, double y) const {
	// ((x - width/2) / width/2)^2 + ((y - height/2) / height/2)^2 <= 1
	// (2x / width - 1)^2 + (2y / height - 1)^2 <= 1
	double lhs = pow(2*x / getWidth() - 1, 2) + pow(2*y / getHeight() - 1, 2);
	return lhs <= 1;
}


} /* namespace figure */
