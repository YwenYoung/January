//使用二维array对象的GradeBook对象的输出
//用二维  array<array<int,tests>,students> &  对象存储考试成绩
#include <array>
#include <string>
class GradeBook
{
public:
	static const size_t students = 10;
	static const size_t tests = 3;

	GradeBook(const std::string &, std::array<std::array<int, tests>, students> &);

	void setCourseName(const std::string &);
	std::string getCourseName() const;
	void displayMessage() const;
	void processGrades() const;
	int getMinimum() const;
	int getMaximum() const;
	double getAverage(const std::array<int, tests> &) const;
	void outputBarChart() const;
	void outputGrades() const;

private:
	std::string courseName;
	std::array<std::array<int, tests>, students> grades;	//创建一个叫grades的二维数组
};