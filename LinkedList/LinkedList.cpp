#include <iostream>
using namespace std;



class Node {
public:
	int data ;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int _data) {
		data = _data;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head = new Node();
	LinkedList() {
		head = NULL;
	}
	bool is_empty() {
		return(head == NULL);
	}
	void InsertFirst(int newvalue) {
		Node* node=new Node (newvalue);
		
		
		if (is_empty()) {
			node->next = NULL;
			head = node;
		}
		else {
			node->next = head;
			head = node;
		}
	}

	void Display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << "\n";
	}
	bool Is_found(int key) {
		Node* temp=head;
		while (temp !=NULL)
		{
			if (temp->data == key) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	int Count() {
		Node* temp = head;
		int c = 0;
		while (temp != NULL) {
			c++;
			temp = temp->next;
		}
		return c;
	}

	void InsertBefore(int item, int newitem) {
		if (is_empty()) {
			cout << "The list is empty \n";
		}
		else if (Is_found(item)) {
			Node* node = new Node(newitem);
			Node* temp = new Node();
			temp = head;
			if (temp->data == item) {
				InsertFirst(newitem);
			}
			else {
				while (temp != NULL && temp->next->data != item) {
					temp = temp->next;
				}
				node->next = temp->next;
				temp->next = node;
			}
		}
		else {
			cout << "The item is not found\n";
		}
		
	}
	void Append(int newitem) {
		if (is_empty()) {
			InsertFirst(newitem);
		}
		else {
			Node* node = new Node(newitem);
			Node* temp = new Node();
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			node->next = NULL;
			temp->next = node;
		}
	}

	void Delete(int item) {
		if (is_empty()) {
			cout << "The list is empty \n";
			return ;
		}
		if (!Is_found(item)) {
			cout << "The item is not found \n";
			return;
		}
		Node* delptr = new Node();
		delptr = head;
		if (head->data == item) { //case of deleting first node
			head = head->next;
			delete delptr;
		}
		else {
			Node* prev = NULL;
			while (delptr->data != item) {
				prev = delptr;
				delptr = delptr->next;
			}
			prev->next = delptr->next;
			delete delptr;
		}
	}


};
int main()
{
	
	

	
	

}

