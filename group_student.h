#ifndef group_student_h
#define group_student_h

#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<iomanip>
#include<string>
#include"student.h"
#include"student_default.h"

using namespace std;

class GroupStudent
{
private:
	int groupNumber;
	vector<Student*> listOfStudents;
public:
	GroupStudent(int number);
	void addStudent(Student* student);
	void deleteStudent(Student* student);
	void deleteAllStudents();
	void startExam();
	void startReExam(Student* student);
	int getGroupNumber();
	Student* getStudentByName(string &name);
	vector<Student*> getListOfStudents();
	vector<Student*> getListOfStudentsSortedByName();
	vector<Student*> getListOfStudentsSortedByMarks();
	void setGroupNumber(int groupNumber);
};
#endif 