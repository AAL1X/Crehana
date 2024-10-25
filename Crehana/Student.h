#ifndef __STUDENT_H__
#define __STUDENT_H__
#include "Heap.h"
#include "SimpleCircularLinkedList.h"
#include "Person.h"
#include "Course.h"
#include "Notification.h"
#include "Diploma.h"
class Student : public Person {
private:
	SimpleCircularLinkedList<Course*>* CourseList;
	SimpleCircularLinkedList<Diploma>* DiplomaList;
	Heap<Notification>* NotificationHeap;
	string StudentID;
	string Password;
public:
	bool operator<(Student S) { return S.getStudentID().compare(StudentID); }
	bool operator>(Student S) { return StudentID.compare(S.getStudentID()); }
	Student();
	Student(string FirstName, string SecondName, string LastName, string MothersLastName, int Age, string StudentID, string Password);
	~Student();
	string getStudentID();
	string getPassword();
	void setStudentID(string StudentID);
	void setPassword(string Password);
	Course* getCourse(size_t Index);
	SimpleCircularLinkedList<Course*>* getCourseList();
	Diploma getDiploma(size_t Index);
	SimpleCircularLinkedList<Diploma>* getDiplomaList();
	Heap<Notification>* getNotificationHeap();
};
Student::Student() :Person() {
}
Student::Student(string FirstName, string SecondName, string LastName, string MothersLastName, int Age, string StudentID, string Password) : Person(FirstName, SecondName, LastName, MothersLastName, Age) {
	CourseList = new SimpleCircularLinkedList<Course*>();
	DiplomaList = new SimpleCircularLinkedList<Diploma>();
	NotificationHeap = new Heap<Notification>();
	this->StudentID = StudentID;
	this->Password = Password;
}
Student::~Student() {
	delete CourseList;
	delete DiplomaList;
	CourseList = nullptr;
	DiplomaList = nullptr;
}
string Student::getStudentID() {
	return StudentID;
}
string Student::getPassword() {
	return Password;
}
void Student::setStudentID(string StudentID) {
	this->StudentID = StudentID;
}
void Student::setPassword(string Password) {
	this->Password = Password;
}
Course* Student::getCourse(size_t Index) {
	return CourseList->ObtainIndex(Index);
}
SimpleCircularLinkedList<Course*>* Student::getCourseList() {
	return CourseList;
}
Diploma Student::getDiploma(size_t Index) {
	return DiplomaList->ObtainIndex(Index);
}
SimpleCircularLinkedList<Diploma>* Student::getDiplomaList() {
	return DiplomaList;
}
Heap<Notification>* Student::getNotificationHeap() {
	return NotificationHeap;
}
#endif //!__STUDENT_H__