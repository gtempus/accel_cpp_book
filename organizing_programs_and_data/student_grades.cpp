#include "gtest/gtest.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  vec_sz mid = size/2;

  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

istream& read_hw(istream& in, vector<double>& homework)
{
	if (in) {
		homework.clear();
		double x;
		while (in >> x) homework.push_back(x);
		in.clear();
	}
	
	return in;
}

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework)
{
	if (homework.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(homework));
}

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};

istream& read(istream& is, Student_info& student)
{
	is >> student.name >> student.midterm >> student.final;
	read_hw(is, student.homework);
	return is;
}

double grade(const Student_info& student)
{
	return grade(student.midterm, student.final, student.homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  if (RUN_ALL_TESTS() != 0) return 1;
		
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin,record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name
				 << string(maxlen + 1 - students[i].name.size(), ' ');
		try {
			double finalGrade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << finalGrade
					 << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		
		cout << endl;
	}
	
  return 0; 
}

/**********************************
 * Testing follows...             *
 **********************************/

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

