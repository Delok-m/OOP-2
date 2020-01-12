#ifndef student_nerd_h
#define student_nerd_h

#include "student.h"

class StudentNerd : public Student
{
public:
	StudentNerd(const string &name);
	StudentNerd(Student* student);
	int Exam() override;
	int ReExam() override;
	~StudentNerd();
};
#endif