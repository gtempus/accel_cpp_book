#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
  vector<string> students;
  vector<double> grades;
  
  while (true) {
    cout << "enter a students name (end-of-file to quit):";
    string name;

    if (!(cin >> name)) break;
    
    students.push_back(name);
    
    //ask for and read the midterm and final grades
    cout << "Please enter you midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    //ask for the homework grades
    cout << "Enter the five homework grades: ";
    
    // homework grades
    vector<double> homework;
    double x;
    
    for (int i = 0; i < 5; i++) {
      cin >> x;
      homework.push_back(x);
    }
    
    sort(homework.begin(), homework.end());
    int mid = 5 / 2;
    double median;
    
    median = mid % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
    int grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
    grades.push_back(grade);
  }
  
  //write the result
  cout << endl << "=== Grade Report ===" << endl;

  for (int i = 0; i < students.size(); i++) {
  streamsize prec = cout.precision();
  cout << "Final grade for " << students[i] << " is: " << setprecision(3)
       << grades[i]
       << setprecision(prec) << endl;
  }
  
  return 0;
}

