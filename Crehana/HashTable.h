#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__
#include "HashEntity.h"
template<class T>
class HashTable
{
private:
	size_t Capacity;
	size_t Size;
	HashEntity<T>** Table;
public:
	HashTable(size_t Capacity);
	~HashTable();
	size_t getCapacity();
	size_t getSize();
	void Add(T Object, string Key);
	void Modify(string Key, T NewObject);
	void Remove(string Key);
	T Obtain(string Key);
	size_t BravoHashFunction(string Key);
	size_t BaldoHashFunction(string Key);
	size_t GutierrezHashFunction(string Key);
};
template<class T>
HashTable<T>::HashTable(size_t Capacity) {
	this->Capacity = Capacity;
	this->Size = 0;
	Table = new HashEntity<T>*[Capacity];
	for (size_t i = 0; i < Capacity; i++) {
		Table[i] = nullptr;
	}
}
template<class T>
HashTable<T>::~HashTable()
{
	for (int i = 0; i < Capacity; ++i) {
		if (Table[i] != nullptr) {
			delete Table[i];
		}
	}
	delete[] Table;
}
template<class T>
size_t HashTable<T>::getCapacity() {
	return Capacity;
}
template<class T>
size_t HashTable<T>::getSize() {
	return Size;
}
template<class T>
void HashTable<T>::Add(T Object, string Key) {
	if (Size == Capacity) {
		return;
	}
	size_t Index = BaldoHashFunction(Key);
	if (Table[Index] == nullptr) {
		Table[Index] = new HashEntity<T>(Object, Key);
	}
	else {
		for (int i = 0; i < Capacity; i++) {
			if (Table[i] == nullptr) {
				Table[i] = new HashEntity<T>(Object, Key);
			}
		}
	}
	Size++;
}
template<class T>
void HashTable<T>::Modify(string Key, T NewObject) {
	size_t Index = BravoHashFunction(Key);
	if (Table[Index] != nullptr && Table[Index]->getKey() == Key) {
		Table[Index]->setObject(NewObject);
	}
	else {
		for (int i = 0; i < Capacity; i++) {
			if (Table[Index] != nullptr && Table[Index]->getKey() == Key) {
				Table[Index]->setObject(NewObject);
			}
		}
	}
}
template<class T>
void HashTable<T>::Remove(string Key) {
	size_t Index = GutierrezHashFunction(Key);
	if (Table[Index] != nullptr && Table[Index]->getKey() == Key) {
		Table[Index] = nullptr;
	}
	else {
		for (int i = 0; i < Capacity; i++) {
			if (Table[Index] != nullptr && Table[Index]->getKey() == Key) {
				Table[Index] = nullptr;
			}
		}
	}
	Size--;
}
template<class T>
T HashTable<T>::Obtain(string Key) {
	size_t Index = (BaldoHashFunction(Key) + BravoHashFunction(Key) + GutierrezHashFunction(Key)) % Capacity;
	if (Table[Index] != nullptr && Table[Index]->getKey() == Key) {
		return Table[Index]->getObject();;
	}
	else {
		for (int i = 0; i < Capacity; i++) {
			if (Table[Index] != nullptr && Table[Index]->getKey() == Key) {
				return Table[Index]->getObject();;
			}
		}
	}
}
template<class T>
size_t HashTable<T>::BravoHashFunction(string Key) {
	size_t Hash = 0;
	Hash = Key.size() * Key.size() + Key.size();

	Hash = Hash % Capacity;
	return Hash;
}
template<class T>
size_t HashTable<T>::BaldoHashFunction(string Key) {
	size_t Hash = 0;
	for (string::iterator it = Key.begin(); it != Key.end(); it++) {
		Hash += Key.size() * int(*it);
	}
	Hash = Hash % Capacity;

	return Hash;
}
template<class T>
size_t HashTable<T>::GutierrezHashFunction(string Key) {
	size_t Hash = 0;
	for (string::iterator it = Key.begin(); it != Key.end(); it++) {
		Hash += int(*it) * (Hash / 2);
	}
	Hash = Hash % Capacity;
	return Hash;
}
#endif // !__HASH_TABLE_H__