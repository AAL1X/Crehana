#ifndef __DIPLOMA_H__
#define __DIPLOMA_H__
#include "Resources.h"
class Diploma
{
private:
	string DiplomaTitle;
	string ReceiverName;
	string AchievementHonor;
public:
	Diploma();
	Diploma(string DiplomaTitle, string ReceiverName, string AchievementHonor);
	~Diploma();
	string getDiplomaTitle();
	string getReceiverName();
	string getAchievementHonor();
	void setDiplomaTitle(string DiplomaTitle);
	void setReceiverName(string ReceiverName);
	void setAchievementHonor(string AchievementHonor);
};
Diploma::Diploma()
{
}
Diploma::Diploma(string DiplomaTitle, string ReceiverName, string AchievementHonor)
{
	this->DiplomaTitle = DiplomaTitle;
	this->ReceiverName = ReceiverName;
	this->AchievementHonor = AchievementHonor;
}
Diploma::~Diploma() {

}
string Diploma::getDiplomaTitle() {
	return DiplomaTitle;
}
string Diploma::getReceiverName() {
	return ReceiverName;
}
string Diploma::getAchievementHonor() {
	return AchievementHonor;
}
void Diploma::setDiplomaTitle(string DiplomaTitle) {
	this->DiplomaTitle = DiplomaTitle;
}
void Diploma::setReceiverName(string ReceiverName) {
	this->ReceiverName = ReceiverName;
}
void Diploma::setAchievementHonor(string AchievementHonor) {
	this->AchievementHonor = AchievementHonor;
}
#endif // !__DIPLOMA_H__