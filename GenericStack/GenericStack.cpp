#include<iostream>
using namespace std;

template<class t>
class Node {
public:
    t data;
    Node <t>* next = NULL;
};

template<class t>
class Stack {
public:
    Node <t>* top = NULL;

    bool is_empty() {
        return (top == NULL) ? true : false;
    }

    void Push(t newitem) {
        Node<t>* node = new Node<t>();
        node->data = newitem;
        if (is_empty()) {
            node->next = NULL;
            top = node;
        }
        else {
            node->next = top;
            top = node;
        }
    }
    void Display() {
        if (is_empty()) {
            cout << "Stack is empty \n";
        }
        else {
            Node<t>* ptr = new Node<t>();
            ptr = top;
            while (ptr != NULL) {
                cout << ptr->data << " \t";
                ptr = ptr->next;
            }
            cout << "\n";
        }
    }
    void Pop() {
        Node <t>* delptr = new Node <t>();
        delptr = top;
        top = top->next;
        delete delptr;
    }

    t Peek() {
        return top->data;
    }

    int Count() {
        Node <t>* ptr = new Node <t>();
        ptr = top;
        int c = 0;
        while (ptr != NULL) {
            c++;
            ptr = ptr->next;
        }
        return c;
    }

    bool Is_found(t item) {
        Node <t>* ptr = new Node <t>();
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
    /*  Stack<char> *st =new Stack<char> ();
      cout<<st->is_empty()<<"\n";
      st->Push('A');
      st->Push('B');
      st->Push('C');
      st->Push('D');
      st->Push('E');
       cout<<st->is_empty()<<"\n";
       st->Display();
       st->Pop();
       st->Display();
       cout<<st->Peek()<<"\n";
       cout<<st->Count()<<"\n";
       cout<<st->Is_found('A')<<"\n";
       cout<<st->Is_found('Q')<<"\n";*/

    Stack <string > st;
    st.Push("Nayra");
    st.Push("Maka");
    st.Push("Mai");
    st.Push("Shahd");
    st.Push("Salma");
    st.Display();
    st.Pop();
    st.Pop();
    st.Display();


}



