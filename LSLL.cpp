#include"LSLL.h"
template<typename T>
LSLL<T>::LSLL(const LSLL<T>& ref)
{
	*this = ref;
}
template<typename T>
LSLL<T>& LSLL<T>::operator=(const LSLL<T>& ref)
{
	if (!ref.head)
		return *this;
	LLNode<T>* temp = ref.head;
	while (temp->nextPtr != nullptr)
	{
		insertAtTail(temp->info);
		temp = temp->nextPtr;
	}
	insertAtTail(temp->info);
	return *this;
}
template<typename T>
LSLL<T>::LSLL()
{ 
	head = nullptr;
}
template<typename T>
void LSLL<T>::insertAtHead(const T& val)
{ 
	LNode<T>* ptr = new LNode<T>(val);
	ptr->nextPtr = head;
	head = ptr;
}
template<typename T>
void LSLL<T>::insertAtTail(const T& val)
{
	if (!head)
	{
		insertAtHead(val);
		return;
	}
	LNode<T>* temp = head;
	while (temp->nextPtr != nullptr)
		temp = temp->nextPtr;
	LNode<T>* ptr = new LNode<T>(val);
	temp->nextPtr = ptr;
}
template<typename T>
void LSLL<T>::insertAfter(const T& key, const T& val)
{
	if (!head)
		return;
	LLNode<T>* PTemp = head;
	while (PTemp != nullptr)
	{
		if (PTemp->info == key)
			break;
		PTemp = PTemp->nextPtr;
	}
	if (!PTemp)
		return;
	LLNode<T>* TNOde = new LLNode<T>(val);
	TNOde->nextPtr = PTemp->nextPtr;
	PTemp->nextPtr = TNOde;
}
template<typename T>
void LSLL<T>::insertBefore(const T& key, const T& val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		insertAtHead(val);
		return;
	}
	LLNode<T>* temp = head->nextPtr;
	LLLNode<T>* prev = head;
	while (temp != nullptr)
	{
		if (temp->info == key)
		{
			LLNode<T>* TNOde = new LLNode<T>(val);
			TNOde->nextPtr = temp;
			prev->nextPtr = TNOde;
			return;
		}
		prev = temp;
		temp = temp->nextPtr;
	}
}
template<typename T>
void LSLL<T>::deleteAtHead()
{
	if (!head)
		return;
	LLNode<T>* temp = head;
	head = head->nextPtr;
	temp->nextPtr = nullptr;
	delete temp;
}
template<typename T>
void LSLL<T>::deleteAtTail()
{
	if (!head)
		return;
	LLNode<T>* temp = head->nextPtr;
	LLNode<T>* prev = head;
	while (temp->nextPtr != nullptr)
	{
		prev = temp;
		temp = temp->nextPtr;
	}
	prev->nextPtr = nullptr;
	delete temp;
}
template<typename T>
void LSLL<T>::deleteAfter(const T& key)
{ 
	if (!head || !(head->nextPtr))
		return;
	LLNode<T>* temp = head;
	while (temp->nextPtr != nullptr)
	{
		if (temp->info == key)
		{
			LLNode<T>* p = temp->nextPtr->nextPtr;
			temp->nextPtr->nextPtr = nullptr;
			delete temp->nextPtr;
			temp->nextPtr = p;
			return;
		}
		temp = temp->nextPtr;
	}
}
template<typename T>
void LSLL<T>::deleteBefore(const T& key)
{
	if (!head || !(head->nextPtr))
		return;
	if (head->nextPtr->info == key)
	{
		deleteAtHead();
		return;
	}
	LNode<T>* pre = head;
	LNode<T>* temp = head->nextPtr;
	while (temp->nextPtr != nullptr)
	{
		if (temp->nextPtr->info == key)
		{
			LNode<T>* p = temp->nextPtr;
			temp->nextPtr = nullptr;
			delete temp;
			pre->nextPtr = p;
			return;
		}
		pre = temp;
		temp = temp->nextPtr;
	}
}
template<typename T>
LSLL<T>::~LSLL()
{
	delete head;
	head = nullptr;
}
template<typename T>
void LSLL<T>::removeDuplicates()
{
	//Assumption that the linked list is sorted
	if (!head)
		return;
	LNode<T>* ptr = head;
	while (ptr != nullptr && ptr->nextPtr != nullptr)
	{
		if (ptr->info == ptr->nextPtr->info)
		{
			LNode<T>* temp = ptr->nextPtr;
			ptr->nextPtr = ptr->nextPtr->nextPtr;
			temp->nextPtr = nullptr;
			delete temp;
		}
		else
			ptr = ptr->nextPtr;
	}
}
template<typename T>
LSLL<T> LSLL<T>::mergeSortedLists(LSLL<T>& list2)
{
	if (!head)
		return list2;
	else if (!list2.head)
		return *this;
	LSLL<T> res = *this;
	LNode<T>* primList = res.head;
	LNode<T>* secList = list2.head;
	while (secList != nullptr)
	{
		while (primList->info < secList->info && primList->nextPtr != nullptr)
			primList = primList->nextPtr;
		res.insertBefore(primList->info, secList->info);
		secList = secList->nextPtr;
	}
	return res;
}
template<typename T>
void LSLL<T>::display()
{
	LNode<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->info << " ";
		temp = temp->nextPtr;
	}
}