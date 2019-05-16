// Potenza, Matthew
// cs 540 section 13481/13468
// implementation of queue as a class using singly linked list in C++

#include <iostream>
using namespace std;

class Queue {
private:
	static int size;
	struct node {
		int info;
		node *link;
	};
	node *front, *back;
public:
    Queue();
	void enqueue(int data);
	int dequeue();
	void dq_all();
	void print_list();
	static int q_size();
};

int Queue::size = 0;

int main(void)
{
	Queue q1;
	
	cout << "Q size: " << q1.q_size() << endl;

	for (int i = 0; i < 10; i++)
		q1.enqueue(i);
	
	q1.print_list();
    cout << "Q size: " << q1.q_size() << endl;
    cout << "dequeued: " << q1.dequeue() << endl;
	q1.print_list();

	cout << "dequeued: ";
	for (int i = 0; i < 12; i++)
		cout << q1.dequeue() << " ";
	cout << endl;
	
	q1.print_list();

	q1.dq_all();
	q1.print_list();
	cout << "Q size: " << q1.q_size() << endl;

	// system("pause");
	return 0;
}

Queue::Queue()
{
   	front = NULL;
	back = NULL;
}

void Queue::enqueue(int data)
{
	node *np = new node;
	np->info = data;
	np->link = NULL;
	if (front == NULL)
		front = np;
	else
		back->link = np;
	back = np;
	size++;
}

int Queue::dequeue()
{
	if (front != NULL) {
		int dq_data;
		//node *np = new node;
		node *np = front;
		front = front->link;
		dq_data = np->info;
		delete np;
		size--;
		return dq_data;
	}
	else {
		cout << endl << "Queue empty, returning ";
		return 0; 
	}
}

void Queue::dq_all()
{
	//node *np = new node;
	node *np = front;
	cout << "Deleted all: ";
	while (front != NULL) {
		//np = front;
		front = front->link;
		cout << " " << np->info;
		delete np;
		size--;
	}
	cout << endl;
}

void Queue::print_list()
{
	node *np = front;
	cout << "Queue contents: ";
	while (np != NULL) {
		cout << np->info << " ";
		np = np->link;
	}
	cout << endl;
}

int Queue::q_size()
{
    return size;
}

