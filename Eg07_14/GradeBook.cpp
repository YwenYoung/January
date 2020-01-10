#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(const string &name, const array<int,students>&gradesArray): courseName(name),grades(gradesArray)