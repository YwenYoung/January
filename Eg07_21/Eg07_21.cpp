#include <iostream>
#include <iomanip>
using namespace std;
#include "Eg07_21.h"

GradeBook::GradeBook(const string &name, std::array<std::array<int, tests>, students> &gradesArray) :
	courseName(name), grades(gradesArray)
{
}

void GradeBook::setCourseName(const string &name)
{
	courseName = name;
}

string GradeBook::getCourseName() const
{
	return courseName;
}

void GradeBook::displayMessage() const
{
	cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}

void GradeBook::processGrades() const
{
	outputGrades();

	cout << "\nLowest grade in the grade book is " << getMinimum() << "\nHighest grade in the grade book is " << getMaximum() << endl;

	outputBarChart();
}

int GradeBook::getMinimum() const
{
	int lowGrade = 100;

	for (auto const &student : grades)
	{
		for (auto const &grade : student)
		{
			if (grade < lowGrade)
				lowGrade = grade;
		}
	}
	return lowGrade;
}

int GradeBook::getMaximum() const
{
	int highGrade = 0;

	for (auto const &student : grades)
	{
		for (auto const &grade : student)
		{
			if (grade > highGrade)
				highGrade = grade;
		}
	}
	return highGrade;
}

double GradeBook::getAverage(const array<int, tests> &setOfGrades) const
{
	int total = 0;

	for (int grade : setOfGrades)
		total += grade;

	return static_cast<double>(total) / setOfGrades.size();
}

void GradeBook::outputBarChart() const
{
	cout << "\nOverall grade distribution:" << endl;

	const size_t frequencySize = 11;
	array<unsigned int, frequencySize>frequency = {};

	for (auto const &student : grades)
		for (auto const &test : student)
			++frequency[test / 10];

	for (size_t count = 0; count < frequencySize; ++count)
	{
		if (0 == count)
			cout << "  0-9: ";
		else if (10 == count)
			cout << "  100: ";
		else
			cout << count * 10 << "-" << (count * 10) + 9 << ": ";

		for (unsigned int stars = 0; stars < frequency[count]; ++stars)
			cout << '*';

		cout << endl;
	}
}

void GradeBook::outputGrades() const
{
	cout << "\nThe grades are:\n\n";
	cout << "		";

	for (size_t test = 0; test < tests; ++test)
		cout << "Test " << test + 1 << "  ";

	cout << "Average" << endl;

	for (size_t student = 0; student < grades.size(); ++student)			//grades.size()就是Eg07_24中的array<>grades的数组个数的大小
	{
		cout << "Student " << setw(2) << student + 1;
		for (size_t test = 0; test < grades[student].size(); ++test)	//grades[student].size()就是Eg07_24中的grades数组中，按照学生编号的成绩数量的个数，每个学生有三门课程成绩，所以grades[student].size()就是3
			cout << setw(8) << grades[student][test];					//第一次外循环时，学生编号取0（为了复核逻辑，打印的学生编号为+1，实际程序内部学生编号还应该是0开始）
																		//第一次内循环时，第一门成绩编号取0（也就是语句中的test = 0），test只要小于该编号学生所考试的科目数量，就会一直执行内循环
		double average = getAverage(grades[student]);
		cout << setw(9) << setprecision(2) << fixed << average << endl;
	}
}