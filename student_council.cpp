#include "student_council.h"

StudentCouncil::StudentCouncil(const string &name) : StudentDefault(name)
{

}
StudentCouncil::StudentCouncil(Student* student) : StudentDefault(student->getName())
{

}
int StudentCouncil::ReExam()
{
	return 3 + rand() % 3;
}
StudentCouncil::~StudentCouncil()
{

}