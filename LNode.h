#ifndef LNODE_H
#define LNODE_H
template<typename T>
struct LNode
{
	T info;
	LNode<T>* nextPtr;
	LNode()
	{
		nextPtr = nullptr;
	}
	LNode(T val)
	{
		info = val;
		nextPtr = nullptr;
	}
};

#endif // !
