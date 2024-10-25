#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__
#include "BinaryNode.h"
template<class T>
class BinarySearchTree
{
private:
	BinaryNode<T>* Root;
	size_t Size;
	BinaryNode<T>* _getBinaryTreeNode(BinaryNode<T>* TreeNode, T Object) {
		if (TreeNode != nullptr) {
			if (TreeNode->getObject() > Object) {
				_getBinaryTreeNode(TreeNode->getLeft(), Object);
			}
			else
				if (TreeNode->getObject() < Object) {
					_getBinaryTreeNode(TreeNode->getRigth(), Object);
				}
				else
					if (TreeNode->getObject() == Object) {
						return TreeNode;
					}
		}
		else
			return nullptr;
	}
	void _Add(BinaryNode<T>*& TreeNode, BinaryNode<T>*& FatherNode, T Object) {
		if (TreeNode == nullptr) {
			TreeNode = new BinaryNode<T>(Object);
			if (Size == 0) {
				TreeNode->setFather(nullptr);
			}
			else {
				TreeNode->setFather(FatherNode);
			}
			Size++;
		}
		else {
			if (TreeNode->getObject() > Object) {
				_Add(TreeNode->getLeft(), TreeNode, Object);
			}
			else
				if (TreeNode->getObject() < Object) {
					_Add(TreeNode->getRigth(), TreeNode, Object);
				}
		}
	}
	void _Remove(BinaryNode<T>* TreeNode, char Branch, T Object) {
		if (TreeNode != nullptr) {
			if (TreeNode->getObject() == Object) {
				if (TreeNode->getLeft() == nullptr && TreeNode->getRigth() == nullptr) {
					if (Branch == 'L') {
						TreeNode->getFather()->setLeft(nullptr);
					}
					else
						if (Branch == 'R') {
							TreeNode->getFather()->setRigth(nullptr);
						}
					delete TreeNode;
					TreeNode = nullptr;
				}
				else
					if (TreeNode->getLeft() != nullptr && TreeNode->getRigth() != nullptr) {
						BinaryNode<T>* Auxiliary = _ObtainMinimum(TreeNode->getRigth());
						TreeNode->setObject(Auxiliary->getObject());
						if (Auxiliary->getRigth() == nullptr) {
							if (Auxiliary->getFather() == TreeNode) {
								Auxiliary->getFather()->setRigth(nullptr);
							}
							else {
								Auxiliary->getFather()->setLeft(nullptr);
							}
						}
						else
							if (Auxiliary->getRigth() != nullptr) {
								Auxiliary->getRigth()->setFather(Auxiliary->getFather());

								if (Auxiliary->getFather() == TreeNode) {
									Auxiliary->getFather()->setRigth(Auxiliary->getRigth());
								}
								else {
									Auxiliary->getFather()->setLeft(Auxiliary->getRigth());
								}
							}

						delete Auxiliary;
						Auxiliary = nullptr;
					}
					else
						if (TreeNode->getLeft() != nullptr) {
							if (Branch == 'N') {
								BinaryNode<T>* Auxiliary = Root;
								Root = Root->getLeft();
								Root->setFather(nullptr);

								delete Auxiliary;
								Auxiliary = nullptr;
							}
							else
								if (Branch == 'L') {
									TreeNode->getLeft()->setFather(TreeNode->getFather());
									TreeNode->getFather()->setLeft(TreeNode->getLeft());

									delete TreeNode;
									TreeNode = nullptr;
								}
								else
									if (Branch == 'R') {
										TreeNode->getLeft()->setFather(TreeNode->getFather());
										TreeNode->getFather()->setRigth(TreeNode->getLeft());

										delete TreeNode;
										TreeNode = nullptr;
									}
						}
						else
							if (TreeNode->getRigth() != nullptr) {
								if (Branch == 'N') {
									BinaryNode<T>* Auxiliary = TreeNode;
									Root = Root->getRigth();
									Root->setFather(nullptr);

									delete Auxiliary;
									Auxiliary = nullptr;
								}
								else
									if (Branch == 'L') {
										TreeNode->getRigth()->setFather(TreeNode->getFather());
										TreeNode->getFather()->setLeft(TreeNode->getRigth());

										delete TreeNode;
										TreeNode = nullptr;
									}
									else
										if (Branch == 'R') {
											TreeNode->getRigth()->setFather(TreeNode->getFather());
											TreeNode->getFather()->setRigth(TreeNode->getRigth());

											delete TreeNode;
											TreeNode = nullptr;
										}
							}
			}
			else
				if (TreeNode->getObject() > Object) {
					_Remove(TreeNode->getLeft(), 'L', Object);
				}
				else
					if (TreeNode->getObject() < Object) {
						_Remove(TreeNode->getRigth(), 'R', Object);
					}
		}
	}
	BinaryNode<T>* _ObtainMinimum(BinaryNode<T>* TreeNode) {
		if (TreeNode->getLeft() == nullptr) {
			return TreeNode;
		}
		else {
			return _ObtainMinimum(TreeNode->getLeft());
		}
	}
	BinaryNode<T>* _ObtainRandom(BinaryNode<T>* TreeNode) {
		if (TreeNode != nullptr) {
			int Random = 1 + rand() % 4;
			if (Random == 4) {
				return TreeNode;
			}
			else
				if (Random % 2 == 0) {
					if (TreeNode->getLeft() == nullptr) {
						if (TreeNode->getRigth() == nullptr) {
							return TreeNode;
						}
						else
							return _ObtainRandom(TreeNode->getRigth());
					}
					else
						return _ObtainRandom(TreeNode->getLeft());
				}
				else
					if (Random % 2 != 0) {
						if (TreeNode->getRigth() == nullptr) {
							if (TreeNode->getLeft() == nullptr) {
								return TreeNode;
							}
							else
								return _ObtainRandom(TreeNode->getLeft());
						}
						else
							return _ObtainRandom(TreeNode->getRigth());
					}

		}
		else
			return nullptr;
	}
	BinaryNode<T>* _Obtain(BinaryNode<T>* TreeNode, T Object) {
		if (TreeNode != nullptr) {
			if (TreeNode->getObject() > Object) {
				return _Obtain(TreeNode->getLeft(), Object);
			}
			else
				if (TreeNode->getObject() < Object) {
					return _Obtain(TreeNode->getRigth(), Object);
				}
				else
					if (TreeNode->getObject() == Object) {
						return TreeNode;
					}
		}
		else
			return nullptr;
	}
	BinaryNode<T>* _ObtainMaximum(BinaryNode<T>* TreeNode) {
		if (TreeNode->getRigth() == nullptr) {
			return TreeNode;
		}
		else {
			return _ObtainMaximum(TreeNode->getRigth());
		}
	}
	size_t _getHeight(BinaryNode<T>* TreeNode) {
		if (TreeNode == nullptr) {
			return 0;
		}
		else {
			size_t HeigthLeft = 1;
			size_t HeigthRigth = 1;
			HeigthLeft += _getHeight(TreeNode->getLeft());
			HeigthRigth += _getHeight(TreeNode->getRigth());
			if (HeigthLeft >= HeigthRigth) {
				return HeigthLeft;
			}
			else
				if (HeigthRigth >= HeigthLeft) {
					return HeigthRigth;
				}
		}
	}
public:
	BinarySearchTree();
	~BinarySearchTree();
	BinaryNode<T>* getBinaryNode(T Object);
	void Add(T Object);
	void Remove(T Object);
	void InOrder();
	void PreOrder();
	void PostOrder();
	T ObtainMinimum();
	T ObtainRandom();
	T Obtain(T Object);
	T ObtainMaximum();
	size_t getHeight();
	size_t getSize();
	bool IsEmpty();
};
template<class T>
BinarySearchTree<T>::BinarySearchTree() {
	Root = nullptr;
	Size = 0;
}
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
	Root = nullptr;
}
template<class T>
BinaryNode<T>* BinarySearchTree<T>::getBinaryNode(T Object) {
	return _getBinaryTreeNode(Root, Object);
}
template<class T>
void BinarySearchTree<T>::Add(T Object) {
	_Add(Root, Root, Object);
}
template<class T>
void BinarySearchTree<T>::Remove(T Object) {
	_Remove(Root, 'N', Object);
}
template<class T>
void BinarySearchTree<T>::InOrder() {
	_InOrder(Root);
}
template<class T>
void BinarySearchTree<T>::PreOrder() {
	_PreOrder(Root);
}
template<class T>
void BinarySearchTree<T>::PostOrder() {
	_PostOrder(Root);
}
template<class T>
T BinarySearchTree<T>::ObtainMinimum() {
	return _ObtainMinimum(Root)->getObject();
}
template<class T>
T BinarySearchTree<T>::ObtainRandom() {
	return _ObtainRandom(Root)->getObject();
}
template<class T>
T BinarySearchTree<T>::Obtain(T Object) {
	return _Obtain(Root, Object)->getObject();
}
template<class T>
T BinarySearchTree<T>::ObtainMaximum() {
	return _ObtainMaximum(Root)->getObject();
}
template<class T>
size_t BinarySearchTree<T>::getHeight() {
	return _getHeight(Root);
}
template<class T>
size_t BinarySearchTree<T>::getSize() {
	return Size;
}
template<class T>
bool BinarySearchTree<T>::IsEmpty() {
	return Root == nullptr;
}
#endif // !__BINARY_SEARCH_TREE_H__