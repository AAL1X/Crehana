#ifndef __QUEUE_NODE_H__
#define __QUEUE_NODE_H__
template<class T>
class QueueNode
{
private:
	T Object;
	QueueNode<T>* NextNode;
public:
	QueueNode(T Object);
	~QueueNode();
	T getObject();
	QueueNode<T>* getNextNode();
	void setObject(T Object);
	void setNextNode(QueueNode<T>* NextNode);
};
template<class T>
QueueNode<T>::QueueNode(T Object)
{
	this->Object = Object;
	NextNode = nullptr;
}
template<class T>
QueueNode<T>::~QueueNode()
{
	NextNode = nullptr;
}
template<class T>
T QueueNode<T>::getObject() {
	return Object;
}
template<class T>
QueueNode<T>* QueueNode<T>::getNextNode() {
	return NextNode;
}
template<class T>
void QueueNode<T>::setObject(T Object) {
	this->Object = Object;
}
template<class T>
void QueueNode<T>::setNextNode(QueueNode<T>* NextNode) {
	this->NextNode = NextNode;
}
#endif // !__QUEUE_NODE_H__