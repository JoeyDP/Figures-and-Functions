#include "figure/Rectangle.h"

namespace figure {

Rectangle::Rectangle(double width, double height) :
	width(width), height(height)
{
}

Rectangle Rectangle::getBoundingBox() const {
	return *this;
}

double Rectangle::getSurface() const {
	return getWidth() * getHeight();
}

bool Rectangle::contains(double x, double y) const {
	return x <= width && y <= height;
}


} /* namespace figure */
