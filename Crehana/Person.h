#ifndef __PERSON_H__
#define __PERSON_H__
#include "Resources.h"
class Person
{
protected:
	string FirstName;
	string SecondName;
	string LastName;
	string MothersLastName;
	int Age;
public:
	Person();
	Person(string FirstName, string SecondName, string LastName, string MothersLastName, int Age);
	~Person();
	string getFirstName();
	string getSecondName();
	string getLastName();
	string getMothersLastName();
	int getAge();
	void setFirstName(string FirstName);
	void setSecondName(string SecondName);
	void setLastName(string LastName);
	void setMothersLastName(string MothersLastName);
	void setAge(int Age);
};
Person::Person() {
}
Person::Person(string FirstName, string SecondName, string LastName, string MothersLastName, int Age) {
	this->FirstName = FirstName;
	this->SecondName = SecondName;
	this->LastName = LastName;
	this->MothersLastName = MothersLastName;
	this->Age = Age;
}
Person::~Person() {

}
string Person::getFirstName() {
	return FirstName;
}
string Person::getSecondName() {
	return SecondName;
}
string Person::getLastName() {
	return LastName;
}
string Person::getMothersLastName() {
	return MothersLastName;
}
int Person::getAge() {
	return this->Age;
}
void Person::setFirstName(string FirstName) {
	this->FirstName = FirstName;
}
void Person::setSecondName(string SecondName) {
	this->SecondName = SecondName;
}
void Person::setLastName(string LastName) {
	this->LastName = LastName;
}
void Person::setMothersLastName(string MothersLastName) {
	this->MothersLastName = MothersLastName;
}
void Person::setAge(int Age) {
	this->Age = Age;
}
#endif // !__PERSON_H__