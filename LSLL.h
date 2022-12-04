#ifndef LSLL_H
#define LSLL_H
#include"LNode.h"
#include<iostream>
using namespace std;
template<typename T>
class LSLL
{
	LLNode<T>* head;
public:
	LSLL();
	LSLL(const LSLL<T>& ref);
	LSLL<T>& operator=(const LSLL<T>& ref);
	void insertAtHead(const T& val);
	void insertAtTail(const T& val);
	void insertBefore(const T& key,const T& val);
	void insertAfter(const T& key, const T& val);
	void deleteAtHead();
	void deleteAtTail();
	void deleteAfter(const T& key);
	void deleteBefore(const T& key);
	void removeDuplicates();
	LSLL<T> mergeSortedLists(LSLL<T>& list2);
	void display();
	~LSLL();









};
#endif // !LSLL_H
