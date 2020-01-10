#include <string>
#include <array>

class GradeBook
{
public:
	static const size_t students = 10;		//常量，参加测试的学生数量
	GradeBook(const std::string &, const std::array<int, students> &);		//构造函数：初始化课程名称和成绩数组
	
	void setCourseName(const std::string &);
	std::string getCourseName()const;
	void displayMessage() const;
	void processGrades() const;
	int getMinimum() const;
	int getMaximum() const;
	double getAverage() const;
	void outputBarChart() const;
	void outputGrades() const;
protected:
private:
	std::string courseName;
	std::array<int, students>grades;
};