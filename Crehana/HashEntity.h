#ifndef __HASH_ENTITY__H_
#define __HASH_ENTITY__H_
#include <string>
using namespace std;
template<class T>
class HashEntity
{
private:
	T Object;
	string Key;
public:
	HashEntity(T object, string Key);
	~HashEntity();
	void setObject(T Object);
	string setKey(string Key);
	T getObject();
	string getKey();
};
template<class T>
HashEntity<T>::HashEntity(T Object, string Key) {
	this->Object = Object;
	this->Key = Key;
}
template<class T>
HashEntity<T>::~HashEntity()
{

}
template<class T>
void HashEntity<T>::setObject(T Object) {
	this->Object = Object;
}
template<class T>
string HashEntity<T>::setKey(string Key) {
	this->Key = Key;
}
template<class T>
T HashEntity<T>::getObject() {
	return Object;
}
template<class T>
string HashEntity<T>::getKey() {
	return Key;
}
#endif // !__HASH_ENTITY__H_