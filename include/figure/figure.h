#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <gsl/gsl_rng.h>

// Forward declaration (bounding box)
class Rectangle;

class Figure{
public:
	virtual ~Figure(){}

	virtual Rectangle getBoundingBox() const=0;
	virtual double getSurface() const=0;
	virtual bool contains(double x, double y)const =0;

	/**
	 * Uses random numbers to estimate the surface of the figure.
	 */
	double estimateSurface(unsigned int numPoints, gsl_rng *r) const;

	/**
	 * Continues adding points until estimate has enough signDigits.
	 */
	unsigned int pointsForEstimateSurface1(unsigned int signDigits, gsl_rng *r) const;

	/**
	 * Gives an estimate for how many points are needed to achieve signDigits accuracy percent of the time.
	 * Performs totalChecks checks before concluding an amount of points is valid.
	 * This method starts with a small amount of points and increases the amount exponentially.
	 */
	unsigned int pointsForEstimateSurface2(unsigned int signDigits, gsl_rng *r, unsigned int iterations=1000, double accuracy=0.95) const;

	/**
	 * Same as 2, but uses average of estimations instead of actual surface.
	 */
	unsigned int pointsForEstimateSurface3(unsigned int signDigits, gsl_rng *r, unsigned int iterations=1000, double accuracy=0.95) const;
};

/**
 * Rectangle with width and height. Bottom left corner is (0, 0)
 */
class Rectangle: public Figure{
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

// Writes ellips to file for use with plotutils graph
void printEllips(const Ellips& ellips, unsigned int numPoints, std::ostream& stream);

#endif /* FIGURE_H_ */
