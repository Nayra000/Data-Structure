#include <iostream>
using namespace std;

class Node {
public :
    int  data;
    Node *next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node( int _data) {
        data = _data;
        next = NULL;
    }

};
class Stack {
    Node* top = new Node();
   

public :
    Stack() {
        top = NULL;
    }
    bool Is_empty() {
        if (top == NULL)
            return true;
        else
            return false;
    }
    void Push(int newelement) {
        Node* node = new Node(newelement);
        if (Is_empty()) {
            node->next = NULL;
            top = node;
        }
        else {
            node->next = top;
            top = node;
        }
    }
    void Display() {
        Node* ptr = new Node();
        ptr = top;
        while (ptr != NULL) {
            cout << ptr->data << " \t";
            ptr = ptr->next;
        }
        cout << "\n";
    }
    void Pop() {
        Node* delptr = new Node();
        delptr = top;
        top = top->next;
        delete delptr;
    }
    int Peek() {
        return top->data;
    }
    int Count() {
        Node* ptr = new Node();
        ptr = top;
        int c = 0;
        while (ptr != NULL) {
            c++;
            ptr = ptr->next;
        }
        return c;
    }
    bool Is_found(int item) {
        Node* ptr = new Node();
        ptr = top;
        while (ptr != NULL) {
            if (ptr->data == item) {
                return true;
           }
            ptr = ptr->next;
        }
        return false;
    }

};
int main()
{
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);
    st.Display();
    cout << st.Is_found(40) << "\n";
    cout << st.Is_found(100) << "\n";
    cout << st.Count() << "\n";
    st.Pop();
    st.Display();
    cout << st.Count() << "\n";
  
    
    
}

