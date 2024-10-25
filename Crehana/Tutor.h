#ifndef __TUTOR_H__
#define __TUTOR_H__
#include "Person.h"
#include "SimpleCircularLinkedList.h"
class Tutor :public Person
{
private:
	SimpleCircularLinkedList<Course>* CourseList;
	string TutorData;
public:
	Tutor(string FirstName, string SecondName, string LastName, string MothersLastName, int Age);
	~Tutor();
	string TutorProfile();
};
Tutor::Tutor(string FirstName, string SecondName, string LastName, string MothersLastName, int Age) : Person(FirstName, SecondName, LastName, MothersLastName, Age) {
	CourseList = new SimpleCircularLinkedList<Course>();
}
Tutor::~Tutor() {
	delete CourseList;
	CourseList = nullptr;
}
string Tutor::TutorProfile() {
	TutorData = "";
	TutorData += "Nombre del Profesor: " + FirstName + " " + SecondName + "\n";
	TutorData += "Apellidos del Profesor: " + LastName + " " + MothersLastName + "\n";
	TutorData += "Edad del Profesor: " + to_string(Age) + "\n";
	return TutorData;
}
#endif //!__TUTOR_H__