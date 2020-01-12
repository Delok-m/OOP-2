#ifndef student_council_h
#define student_council_h

#include "student_default.h"

class StudentCouncil : public StudentDefault
{
public:
	StudentCouncil(const string &name);
	StudentCouncil(Student* student);
	int ReExam() override;
	~StudentCouncil();
};
#endif 