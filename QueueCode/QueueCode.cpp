#include <iostream>
using namespace std;

template<class type>
class Node {
public:
	type data;
	Node* next;
	Node() {
		//data = 0;
		next = NULL;
	}
	Node(type _data) {
		data = _data;
		next = NULL;
	}
};
template<class type>
class Queue {
public:
	Node* front ;
	Node* back;
	Queue() {
		front = NULL;
		back = NULL;
	}
	bool is_empty() {
		return(front == NULL && back == NULL) ? true : false;
	}
	void Enqueue(type item) {
		Node* node = new Node(item);
		node->next = NULL;
		if (is_empty()) {
			front = node;
			back = node;
		}
		else {
			back->next = node;
			back = node;
		}
	}
	void Display() {
		if (is_empty()) {
			cout << "The queue is empty \n";
		}
		else {
			Node* ptr = new Node();
			ptr = front;
			while (ptr != NULL) {
				cout << ptr->data << "\t";
				ptr = ptr->next;
			}
		}
		cout << "\n";
	}
	int Count() {
		Node* ptr = new Node();
		ptr = front;
		int c = 0;
		while (ptr != NULL) {
			c++;
			ptr = ptr->next;
		}
		return c;
	}
	void Dequeue() {
		Node* delptr = new Node();
		delptr = front;
		if (is_empty()) {
			cout << "The dequeue is empty \n";
		}
		else if (front == back ) {
			front = NULL;
			back = NULL;
			delete delptr;
		}
		else {
			front = front->next;
			delete delptr;
		}
	}
	type getfront() {
		return front->data;
	}
	type getback() {
		return back->data;
	}
	bool is_found(type item) {
		Node* ptr = new Node();
		ptr = front;
		while (ptr != NULL) {
			if (ptr->data == item) {
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}
	void Clear() {
		while (front != NULL)
		{
			Dequeue();
		}
	}
	
};

int main()
{
	Queue<int> que;
	que.Enqueue(1);
	que.Enqueue(2);
	que.Enqueue(3);
	que.Enqueue(4);
	que.Enqueue(5);
	que.Enqueue(6);
	que.Display();
	cout << que.Count() << "\n";
	que.Dequeue();
	que.Display();
	cout << que.Count() << "\n";
	que.Clear();
	que.Dequeue();
   
}

