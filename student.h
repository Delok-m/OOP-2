#ifndef student_h
#define student_h

#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

class Student
{
private:
	string name;
	int min_mark;
	vector<int> group_numbers;
public:
	Student(const string &name, int min_mark);
	void addGroupNumber(int groupNumber);
	void deleteGroupNumber(int groupNumber);
	string getName();
	virtual int Exam() = 0;
	virtual int ReExam() = 0;
	int getMinMark();
	int getGroupCount();
	const vector<int>& getGroupNumbers();
	void setName(string name);
	virtual ~Student() = default;
};
#endif 