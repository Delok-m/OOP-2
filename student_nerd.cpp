#include "student_nerd.h"

StudentNerd::StudentNerd(const string &name) : Student(name, (4 + rand() % 2))
{

}
StudentNerd::StudentNerd(Student* student) : Student(student->getName(), (4 + rand() % 2))
{

}
int StudentNerd::Exam()
{
	return 4 + rand() % 2;
}
int StudentNerd::ReExam()
{
	return 4 + rand() % 2;
}
StudentNerd::~StudentNerd()
{

}