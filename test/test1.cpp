
#include <math.h>

#include "gtest/gtest.h"

#include "figure/figure.h"

TEST(SurfaceTest, ellips1){
	Ellips e(4, 2);
	ASSERT_EQ(e.getSurface(), 2 * M_PI);
}

TEST(SurfaceTest, ellips2){
	Ellips e(4, 8);
	ASSERT_EQ(e.getSurface(), 8 * M_PI);
}
