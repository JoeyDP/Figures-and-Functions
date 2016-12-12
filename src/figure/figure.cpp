#include "figure/figure.h"

#include <stdio.h>
#include <math.h>
#include <vector>

// Checks if estimate has enough significant digits in respect to the actual value.
inline bool hasEnoughSignDigits(double actual, double estimate, unsigned int signDigits, unsigned int base=10){
	double difference = fabs((actual - estimate) / actual);
	double eps = base / 2 * pow(base, -1 * (int)signDigits);

	return difference <= eps;
}

double Figure::estimateSurface(unsigned int numPoints, gsl_rng *r) const {
	const Rectangle& boundingBox = getBoundingBox();
	double boundingSurface = boundingBox.getSurface();

	double estimate = 0;
	unsigned int totalPoints = 0;
	unsigned int pointsInFigure = 0;
	for(unsigned int i = 0;i < numPoints;++i){
		// x and y random in boundingBox
		double x = gsl_rng_uniform(r) * boundingBox.getWidth();
		double y = gsl_rng_uniform(r) * boundingBox.getHeight();

		if(contains(x, y)){
			++pointsInFigure;
		}
		++totalPoints;
	}
	estimate = (double)pointsInFigure / (double)totalPoints * boundingSurface;

	return estimate;
}

unsigned int Figure::pointsForEstimateSurface1(unsigned int signDigits, gsl_rng *r) const {
	const Rectangle& boundingBox = getBoundingBox();
	double boundingSurface = boundingBox.getSurface();
	double realSurface = getSurface();

	double estimate = 0;
	unsigned int totalPoints = 0;
	unsigned int pointsInFigure = 0;
	while(!hasEnoughSignDigits(realSurface, estimate, signDigits)){
		// x and y random in boundingBox
		double x = gsl_rng_uniform(r) * boundingBox.getWidth();
		double y = gsl_rng_uniform(r) * boundingBox.getHeight();

		if(contains(x, y)){
			++pointsInFigure;
		}
		++totalPoints;
		estimate = (double)pointsInFigure / (double)totalPoints * boundingSurface;

	}

	return totalPoints;
}

unsigned int Figure::pointsForEstimateSurface2(unsigned int signDigits, gsl_rng *r, unsigned int iterations, double accuracy) const {
	unsigned int numPoints = 1;

	double realSurface = getSurface();

	unsigned int invalid = 0;
	unsigned int threshold = (1 - accuracy) * iterations;
	do{
		invalid = 0;
		numPoints <<= 1;
//		printf("Checking if %d points are enough.\n", numPoints);

		for(unsigned int i = 0;i < iterations;++i){
			double estimate = estimateSurface(numPoints, r);
			if(!hasEnoughSignDigits(realSurface, estimate, signDigits)){
				++invalid;
			}
			// Can't fix this round anymore
			if(invalid > threshold){
				break;
			}
		}
	}while(invalid > threshold);

	return numPoints;
}

unsigned int Figure::pointsForEstimateSurface3(unsigned int signDigits, gsl_rng *r, unsigned int iterations, double accuracy) const {
	unsigned int numPoints = 1;

	unsigned int invalid = 0;
	unsigned int threshold = (1 - accuracy) * iterations;
	do{
		invalid = 0;
		numPoints <<= 1;
//		printf("Checking if %d points are enough.\n", numPoints);

		double sum = 0;
		std::vector<double> estimates;
		for(unsigned int i = 0;i < iterations;++i){
			double estimate = estimateSurface(numPoints, r);
			sum += estimate;
			estimates.push_back(estimate);
		}

		double average = (double)sum / (double)iterations;
		for(double estimate:estimates){
			if(!hasEnoughSignDigits(average, estimate, signDigits)){
				++invalid;
			}
			if(invalid > threshold){
				break;
			}
		}
	}while(invalid > threshold);

	return numPoints;
}

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



