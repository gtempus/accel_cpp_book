#include <vector>
#include <stdexcept>

#include "gtest/gtest.h"
#include "../median.h"

using std::vector;
using std::domain_error;

TEST(median, ThrowsAnExceptionIfTheVectorIsEmpty)
{
	vector<double> empty;
	ASSERT_THROW(median(empty),domain_error);
}

TEST(median, ReturnsTheMedianOfTheElements)
{
	vector<double> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	double result = median(vec);
	
	ASSERT_DOUBLE_EQ(20, result);
}
