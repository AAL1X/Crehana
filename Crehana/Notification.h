#ifndef __NOTIFICATION_H__
#define __NOTIFICATION_H__
class Notification {
private:
	string Type;
	string Name;
public:
	Notification();
	Notification(string Type, string Name);
	~Notification();
	string getType();
	string getName();
	void setType(string Type);
	void setName(string Name);
};
Notification::Notification() {

}
Notification::Notification(string Type, string Name) {
	this->Type = Type;
	this->Name = Name;
}
Notification::~Notification() {
}
string Notification::getType() {
	return Type;
}
string Notification::getName() {
	return Name;
}
void Notification::setType(string Type) {
	this->Type = Type;
}
void Notification::setName(string Name) {
	this->Name = Name;
}
#endif // !__NOTIFICATION_H__