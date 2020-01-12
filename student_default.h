#ifndef student_default_h
#define student_default_h

#include "student.h"

class StudentDefault : public Student
{
public:
	StudentDefault(const string &name);
	StudentDefault(Student* student);
	int Exam() override;
	int ReExam() override;
};
#endif 
