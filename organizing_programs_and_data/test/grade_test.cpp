#include <vector>
#include <stdexcept>
#include "gtest/gtest.h"
#include "../grade.h"
#include "../Student_info.h"

using std::domain_error;
using std::vector;

TEST(grade, CalculatesTheFinalGradeForTheClass)
{
	vector<double> homework;
	homework.push_back(100);
	homework.push_back(80);
	homework.push_back(75);
	homework.push_back(95);
	
  double result = grade(100, 80, homework);
	
  EXPECT_DOUBLE_EQ(87,result);
}

TEST(grade, CalculatesTheFinalGradeFromAStudentInfoStruct)
{
	Student_info student;
	student.name = "Gary";
	student.midterm = 100;
	student.final = 80;
	student.homework.push_back(100);
	student.homework.push_back(80);
	student.homework.push_back(75);
	student.homework.push_back(95);

	double result = grade(student);
	
	EXPECT_DOUBLE_EQ(87, result);
}

TEST(grade, ThrowsAnExceptionIfThereIsNoHomework)
{
	vector<double> no_homework;
	ASSERT_THROW(grade(100, 80, no_homework), domain_error);
}
