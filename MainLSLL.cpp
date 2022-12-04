#include"LSLL_implementation.cpp"
#include<iostream>
using namespace std;
int main()
{
	LSLL<int> q,q2;
	q.insertAtTail(1);
	q.insertAtTail(4);
	q.insertAtTail(5);
	q.insertAtTail(7);
	q.insertAtTail(9);

	q2.insertAtTail(3);
	q2.insertAtTail(5);
	q2.insertAtTail(6);
	q2.insertAtTail(8);

	LSLL<int> temp = q.mergeSortedLists(q2);
	temp.display();

	return 0;
}