#ifndef MYQUEUE_H
#define MYQUEUE_H
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


template <class T>
class Queue {
	private:
		typedef struct node { T item; struct node *next; }Node;  // 类的嵌套结构定义
		enum {MAX_QSIZE = 10};

		Node *front;
		Node *rare;
		int itemNum;
		const int queueSize;

	public:
		Queue(int qs = MAX_QSIZE):front(NULL), rare(NULL), itemNum(0), queueSize(qs) { }
		~Queue();
		void showInfo();
		int getqueueSize();
		int queuecount();
		bool isFull();
		bool isEmpty();
		bool enqueue(const T &item);
		bool dequeue();


};



#endif
