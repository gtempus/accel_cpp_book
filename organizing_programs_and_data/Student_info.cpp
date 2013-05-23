#include "Student_info.h"
#include <iostream>
#include <vector>

using std::istream;
using std::vector;

istream& read(istream& is, Student_info& student)
{
	is >> student.name >> student.midterm >> student.final;
	read_hw(is, student.homework);
	return is;
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


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
