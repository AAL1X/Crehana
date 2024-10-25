#ifndef __NAME_H__
#define __NAME_H__
#include <iostream>
using namespace std;
class Name
{
private:
	string Data;
public:
	bool operator> (Name L) { return Data > L.Data; }
	bool operator< (Name L) { return Data < L.Data; }
	Name();
	Name(string Data);
	~Name();
	string getData();
};
Name::Name()
{
}
Name::Name(string Data)
{
	this->Data = Data;
}
Name::~Name()
{
}
string Name::getData() {
	return Data;
}
#endif // !__NAME_H__