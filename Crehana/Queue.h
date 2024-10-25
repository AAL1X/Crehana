#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "QueueNode.h"
template<class T>
class Queue
{
private:
	QueueNode<T>* FirstNode;
	QueueNode<T>* LastNode;
	size_t Size;
public:
	Queue();
	~Queue();
	QueueNode<T>* getNodo(size_t Index);
	size_t getSize();
	void Enqueue(T Object);
	T Dequeue();
	T Peek();
	bool IsEmpty();
};
template<class T>
Queue<T>::Queue()
{
	FirstNode = nullptr;
	LastNode = nullptr;
	Size = 0;
}
template<class T>
Queue<T>::~Queue()
{
	if (LastNode != nullptr) {
		LastNode = nullptr;
	}
	QueueNode<T>* Auxiliary = FirstNode;
	while (Auxiliary != nullptr)
	{
		FirstNode = FirstNode->getNextNode();
		delete Auxiliary;
		Auxiliary = FirstNode;
	}
}
template<class T>
QueueNode<T>* Queue<T>::getNodo(size_t Index) {
	QueueNode<T>* Auxiliary = FirstNode;
	for (size_t i = 0; i < Index; i++)
	{
		Auxiliary = Auxiliary->getNextNode();
	}
	return Auxiliary;
}
template<class T>
size_t Queue<T>::getSize() {
	return Size;
}
template<class T>
void Queue<T>::Enqueue(T Object) {
	QueueNode<T>* NewNode = new QueueNode<T>(Object);
	if (FirstNode == nullptr) {
		FirstNode = NewNode;
	}
	else {
		LastNode->setNextNode(NewNode);
	}
	LastNode = NewNode;
	Size++;
	NewNode = nullptr;
}
template<class T>
T Queue<T>::Dequeue() {
	QueueNode<T>* Auxiliary = FirstNode;
	T Object = FirstNode->getObject();
	if (FirstNode == LastNode) {
		FirstNode = nullptr;
		LastNode = nullptr;
	}
	else {
		FirstNode = FirstNode->getNextNode();
	}
	Size--;
	delete Auxiliary;
	Auxiliary = nullptr;
	return Object;
}
template<class T>
T Queue<T>::Peek() {
	return FirstNode->getObject();
}
template<class T>
bool Queue<T>::IsEmpty() {
	return FirstNode == nullptr;
}
#endif // !__QUEUE_H__