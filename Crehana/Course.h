#ifndef __COURSE_H__
#define __COURSE_H__
#include "Queue.h"
#include "Rating.h"
#include "Calendar.h"
#include "Session.h"
class Course
{
private:
	Queue<Session>* SessionQueue;
	Rating CourseRating;
	Calendar Schedule;
	string CourseName;
	string CourseSection;
public:
	Course();
	Course(string CourseName, string CourseSection, string SessionDay, string StartTime, string FinishTime, string SessionCount, float CourseRating);
	~Course();
	Rating getCourseRating();
	Calendar getCalendar();
	void CourseDetails();
	string getCourseName();
	string getCourseSection();
	void setCourseName(string CourseName);
	void setCourseSection(string CourseSection);
	Queue<Session>* getSessionQueue();
};
Course::Course() {

}
Course::Course(string CourseName, string CourseSection, string SessionDay, string StartTime, string FinishTime, string SessionCount, float CourseRating) {
	SessionQueue = new Queue<Session>();

	for (int i = 4 - stoi(SessionCount); i <= 3; i++)
	{
		SessionQueue->Enqueue(Session(i));
	}

	Schedule = Calendar(SessionDay, StartTime, FinishTime);
	this->CourseName = CourseName;
	this->CourseSection = CourseSection;
	this->CourseRating.setQuantity(CourseRating);
}
Course::~Course() {
	SessionQueue = nullptr;
}
void Course::CourseDetails() {

}
Rating Course::getCourseRating() {
	return CourseRating;
}
Calendar Course::getCalendar() {
	return Schedule;
}
string Course::getCourseName() {
	return CourseName;
}
string Course::getCourseSection() {
	return CourseSection;
}
void Course::setCourseName(string CourseName) {
	this->CourseName = CourseName;
}
void Course::setCourseSection(string CourseSection) {
	this->CourseSection = CourseSection;
}
Queue<Session>* Course::getSessionQueue() {
	return SessionQueue;
}
#endif // !__COURSE_H__