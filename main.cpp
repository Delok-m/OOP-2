#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<locale>
#include<ctime>
#include<iomanip>
#include"student.h"
#include"student_council.h"
#include"student_default.h"
#include"student_nerd.h"
#include"group_student.h"
#include"windows.h"

using namespace std;

int main(int argc, const char * argv[]) {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	string names[19] = {
		"Рашета Полина Захаровна",
		"Салтыкова Варвара Захаровна",
		"Кондракова Жанна Михеевна",
		"Коченков Бронислав Геннадиевич",
		"Миронов Андриян Кондратиевич",
		"Гречко Злата Александровна",
		"Гаврин Бронислав Владиславович",
		"Агеева Софья Игнатиевна",
		"Суснина Анна Ивановна",
		"Головченко Лаврентий Левович",
		"Гущин Тихон Трофимович",
		"Луков Адам Дмитриевич",
		"Власьев Святослав Капитонович",
		"Едемский Федот Венедиктович",
		"Верица Тимофей Ефремович",
		"Жаркин Кирилл Валерьянович",
		"Лукашенко Ипполит Натанович",
		"Караулова Вера Юлиевна",
		"Яковенко Давид Денисович"
	};
	int groups[5] = { 7091,7411,7401,7371,7311 };

	Student* AllStudentsList[19];
	GroupStudent* AllGroupsList[5];

	for (int i = 0; i < 12; i++)
	{
		StudentDefault* student = new StudentDefault(names[i]);
		AllStudentsList[i] = student;
	}
	for (int i = 12; i < 17; i++)
	{
		StudentNerd* student = new StudentNerd(names[i]);
		AllStudentsList[i] = student;
	}
	for (int i = 17; i < 19; i++)
	{
		StudentCouncil* student = new StudentCouncil(names[i]);
		AllStudentsList[i] = student;
	}
	for (int i = 0; i < 5; i++)
	{
		GroupStudent* studentGroup = new GroupStudent(groups[i]);
		AllGroupsList[i] = studentGroup;
	}
	for (int i = 0; i < 19; i++)
	{
		int tempGroupInd = rand() % 5;
		int tempStudInd = rand() % 19;

		AllGroupsList[tempGroupInd]->addStudent(AllStudentsList[tempStudInd]);
	}
	cout << "------------------------Exam------------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
			if (!AllGroupsList[i]->getListOfStudents().empty()) cout << "Group " << AllGroupsList[i]->getGroupNumber() << endl;
			AllGroupsList[i]->startExam();
	}
	system("pause");
	return 0;
}