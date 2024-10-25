#ifndef __SESSION_H__
#define __SESSION_H__
class Session {
private:
	short SessionNumber;
public:
	Session();
	Session(short SessionNumber);
	~Session();
	short getSessionNumber();
	void setSessionNumber(short SessionNumber);
};
Session::Session() {

}
Session::Session(short SessionNumber) {
	this->SessionNumber = SessionNumber;
}
Session::~Session() {
}
short Session::getSessionNumber() {
	return SessionNumber;
}
void Session::setSessionNumber(short SessionNumber) {
	this->SessionNumber = SessionNumber;
}
#endif // !__SESSION_H__