project(workingWithStrings)
cmake_minimum_required(VERSION 2.6)

include_directories(
	$ENV{GMOCK_HOME}/include
	$ENV{GMOCK_HOME}/gtest/include)

link_directories(
	$ENV{GMOCK_HOME}/mybuild
	$ENV{GMOCK_HOME}/gtest/mybuild)

add_definitions(-std=c++0x)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources
	Student_info.cpp
	grade.cpp
	median.cpp)
	
set(tests
	test/grade_test.cpp
	test/median_test.cpp)

add_executable(hw ${sources} student_grades.cpp)
add_executable(test_runner ${sources} ${tests} test/test_runner.cpp)
target_link_libraries(test_runner pthread)
target_link_libraries(test_runner gmock)
target_link_libraries(test_runner gtest)

