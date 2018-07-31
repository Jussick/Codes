//C++ file
/***********************************************
#
#      Filename: queue.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-07-26 10:32:08
#**********************************************/
#include "myqueue.h"

template <class T>
void Queue<T>::showInfo()
{
	Node *temp = front;
	for (; front != NULL; front = front->next)
		cout << front->item << " ";
	cout << endl;
	front = temp;
}

template <class T>
int Queue<T>::queuecount()
{
	return itemNum;	
}

template <class T>
bool Queue<T>::isFull()
{
	return itemNum == queueSize;	
}

template <class T>
bool Queue<T>::isEmpty()
{
	return itemNum == 0;	
}
template <class T>
bool Queue<T>::enqueue(const T &newitem)
{
	cout << "enqueue item:" << newitem << endl;
	if (isFull())
	{
		cout << "Queue is full!" << endl;
		return false;
	}
	if (isEmpty())
	{
		Node *newnode = new(Node);
		newnode->item = newitem;
		newnode->next = NULL;
		front = rare = newnode;	
	}
	else
	{
		rare->next = new(Node);
		rare->next->item = newitem;
		rare = rare->next;
		rare->next = NULL;
	}
	itemNum++;
	return true;
}
template <class T>
bool Queue<T>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty!" << endl;
		return false;
	}
	cout << "dequeue:" << front->item << endl;
	front = front->next;

}
template <class T>
int Queue<T>::getqueueSize()
{
	return queueSize;
}

int main()
{
	Queue<int> q1(3);	
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.dequeue();
	q1.showInfo();

	return 0;
}
