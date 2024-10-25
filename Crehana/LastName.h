#ifndef __LAST_NAME_H__
#define __LAST_NAME_H__
#include <iostream>
using namespace std;
class LastName
{
private:
	string Data;
public:
	bool operator> (LastName L) { return Data > L.Data; }
	bool operator< (LastName L) { return Data < L.Data; }
	LastName();
	LastName(string Data);
	~LastName();
	string getData();
};
LastName::LastName()
{
}
LastName::LastName(string Data)
{
	this->Data = Data;
}
LastName::~LastName()
{
}
string LastName::getData() {
	return Data;
}
#endif // !__LAST_NAME_H__