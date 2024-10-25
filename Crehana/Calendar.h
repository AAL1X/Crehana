#ifndef __CALENDAR_H__
#define __CALENDAR_H__
#include "Resources.h"
#include "Time.h"
class Calendar
{
private:
	string SessionDay;
	Time CalendarTime;
public:
	Calendar();
	Calendar(string SessionDay, string StartTime, string FinishTime);
	~Calendar();
	string getSessionDay();
	Time getCalendarTime();
	void setSessionDay(string SessionDay);
};
Calendar::Calendar() {

}
Calendar::Calendar(string SessionDay, string StartTime, string FinishTime) {
	this->SessionDay = SessionDay;
	CalendarTime = Time(StartTime, FinishTime);
}
Calendar::~Calendar() {

}
string Calendar::getSessionDay() {
	return this->SessionDay;
}
Time Calendar::getCalendarTime() {
	return CalendarTime;
}
void Calendar::setSessionDay(string SessionDay) {
	this->SessionDay = SessionDay;
}
#endif // !__CALENDAR_H__