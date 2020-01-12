#include"group_student.h"

GroupStudent::GroupStudent(int number)
{
	this->groupNumber = number;
}
void GroupStudent::addStudent(Student* student)
{
	if (listOfStudents.size() < 20) {
		if (find(listOfStudents.begin(), listOfStudents.end(), student) != listOfStudents.end()) {
		}
		else {
			listOfStudents.push_back(student);
			student->addGroupNumber(this->groupNumber);
		}
	}
	else cout << "!!!Errot." << endl;//more 20
}
void GroupStudent::deleteStudent(Student* student)
{
	vector<Student*>::iterator position = find(listOfStudents.begin(), listOfStudents.end(), student);
	if (position != listOfStudents.end()) {
		student->deleteGroupNumber(this->groupNumber);
		listOfStudents.erase(position);
	}
	else cout << "!!!Error." << endl;//no student
}
void GroupStudent::deleteAllStudents()
{
	for (auto& i : listOfStudents)
	{
		i->deleteGroupNumber(this->groupNumber);
	}
	listOfStudents.clear();
}
void GroupStudent::startExam()
{
	int tempNum = 0;
	for (auto& i : listOfStudents)
	{
		int mark = i->Exam();
		tempNum++;
		if (mark == 2)
		{
			cout << tempNum << ". " << setw(32) << left << i->getName() << "Failed the exam" << endl;
			startReExam(i);
		}
		else
		{
			cout << tempNum << ". " << setw(32) << left << i->getName() << "ExamMark: " << mark << endl;
		}
	}
}
void GroupStudent::startReExam(Student* student)
{
	int mark = student->ReExam();
	string name = student->getName();
	if (mark == 2)
	{
		cout  << setw(35) << " " << "Failed the ReExam" << endl;
		deleteStudent(student);
	}
	else
	{
		cout  << setw(35) << " " << "ReExamMark: " << mark << endl;
	}
}
int GroupStudent::getGroupNumber()
{
	return this->groupNumber;
}
Student* GroupStudent::getStudentByName(string& name)
{
	int i = 0;
	for (i = 0; listOfStudents.size(); i++)
	{
		if (listOfStudents[i]->getName() == name) {
			return listOfStudents[i];
		}
	}
	return nullptr;
}
vector<Student*> GroupStudent::getListOfStudents()
{
	return listOfStudents;
}
vector<Student*> GroupStudent::getListOfStudentsSortedByName()
{
	vector<Student*> tempVector = listOfStudents;
	if (listOfStudents.empty())
	{
		cout << endl << "!!!No students in group " << this->groupNumber << endl;
		return tempVector;
	}
	else {
		sort(tempVector.begin(), tempVector.end(), [](Student* a, Student* b)
		{
			return a->getName()[0] < b->getName()[0];
		});
	}
	return tempVector;
}
vector<Student*> GroupStudent::getListOfStudentsSortedByMarks()
{
	vector<Student*> tempVector = listOfStudents;
	if (listOfStudents.empty())
	{
		cout << "!!!No students in group " << this->groupNumber << endl;
		return tempVector;
	}
	else {
		sort(tempVector.begin(), tempVector.end(), [](Student* a, Student* b)
		{
			return a->getMinMark() > b->getMinMark();
		});
	}
	return tempVector;
}
void GroupStudent::setGroupNumber(int groupNumber)
{
	this->groupNumber = groupNumber;
}