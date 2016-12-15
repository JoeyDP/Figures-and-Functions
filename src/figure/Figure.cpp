#include "figure/Figure.h"

#include <math.h>
#include <vector>

#include "figure/Rectangle.h"

bool hasEnoughSignDigits(double actual, double estimate, unsigned int signDigits, unsigned int base){
	double difference = fabs((actual - estimate) / actual);
	double eps = base / 2 * pow(base, -1 * (int)signDigits);

	return difference <= eps;
}

namespace figure {

//double Figure::estimateSurface(unsigned int numPoints, gsl_rng *r) const {
//	const Rectangle& boundingBox = getBoundingBox();
//	double boundingSurface = boundingBox.getSurface();
//
//	double estimate = 0;
//	unsigned int totalPoints = 0;
//	unsigned int pointsInFigure = 0;
//	for(unsigned int i = 0;i < numPoints;++i){
//		// x and y random in boundingBox
//		double x = gsl_rng_uniform(r) * boundingBox.getWidth();
//		double y = gsl_rng_uniform(r) * boundingBox.getHeight();
//
//		if(contains(x, y)){
//			++pointsInFigure;
//		}
//		++totalPoints;
//	}
//	estimate = (double)pointsInFigure / (double)totalPoints * boundingSurface;
//
//	return estimate;
//}

double Figure::estimateSurface(unsigned int signDigits, gsl_rng* r, unsigned int iterations, double accuracy) const {
	// TODO implement
	return 0;

//	unsigned int numPoints = 1;
//
//	unsigned int invalid = 0;
//	unsigned int threshold = (1 - accuracy) * iterations;
//	do{
//		invalid = 0;
//		numPoints <<= 1;
//
//		double sum = 0;
//		std::vector<double> estimates(iterations);
//		for(unsigned int i = 0;i < iterations;++i){
//			double estimate = estimateSurface(numPoints, r);
//			sum += estimate;
//			estimates.push_back(estimate);
//		}
//
//		double average = (double)sum / (double)iterations;
//		for(double estimate:estimates){
//			if(!hasEnoughSignDigits(average, estimate, signDigits)){
//				++invalid;
//			}
//			if(invalid > threshold){
//				break;
//			}
//		}
//	}while(invalid > threshold);
}

} /* namespace figure */


