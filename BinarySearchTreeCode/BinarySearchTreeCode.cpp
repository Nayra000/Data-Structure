#include <iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* left, * right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;

    }
    Node(int _data) {
        data =_data;
        left = NULL;
        right = NULL;

    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    bool is_empty() {
        return(root == NULL) ? true : false;
    }
  
   

  void Insert(int item) {
       Node* node = new Node() ,*prev=NULL;
       node = root;
       while ( node!=NULL)
       {
           prev = node;
           if (item < node->data) {
               node = node->left;
           }
           else {
               node = node->right;
           }
       }
       if (root == NULL) {
           root = new Node(item);
       }
       else if(item <prev->data)
       {
           prev->left = new Node(item);
       }
       else
       {
           prev->right = new Node(item);
       }
   }

   //Node* Insert(Node* r, int item) //recrusion
   //{
   //    if (r == NULL)
   //    {
   //        Node* newnode = new Node(item);
   //        r = newnode;
   //    }

   //    else if (item < r->data)
   //        r->left = Insert(r->left, item);
   //    else
   //        r->right = Insert(r->right, item);

   //    return r;
   //}

   //void Insert(int item)
   //{
   //    root = Insert(root, item);
   //}

   void Preorder(Node *node) { // root left right 
       if (node == NULL) {
           return;
       }
       cout << node->data << "\t";
       Preorder(node->left);
       Preorder(node->right);
   }
   void Inorder(Node *node) { //left root right
       if (node == NULL) {
           return;
       }
       Inorder(node->left);
       cout << node->data << "\t";
       Inorder(node->right);

   }
   void Postorder(Node* node) {
       if (node == NULL) {
           return;
       }
       Inorder(node->left);
       Inorder(node->right);
       cout << node->data << "\t";
   }
   bool Search(Node* node,int item) {
       if (node == NULL) { //tree is empty or item is not found
           return 0;
       }
       else if (node->data == item) {
           return 1;
       }
       else if (item < node->data) {
           Search(node->left,item);
       }
       else {
           Search(node->right, item);
       }

   }
  
   int Min(Node* node,int minn) {
       if (is_empty())
           throw exception("The tree is empty\n");
       if (node == NULL) {
           return minn;
       }
       minn = node->data;
       Min(node->left,minn);
   }
   int Max(Node* node, int maax) {
       if (node == NULL) {
           return maax;
       }
       maax = node->data;
       Max(node->right, maax);
   }
   Node* Delete(Node* r, int key) {
       if (r == NULL) { // key is not found 
           return NULL;
       }
       else if (key < r->data) {
           r->left = Delete(r->left, key);
       }
       else if (key > r->data) {
           r->right = Delete(r->right, key);
       }
       else {  // key is found
           if (r->left == NULL && r->right == NULL) { //leaf node
               delete r;
               r = NULL;
           }
           else if (r->left != NULL && r->right == NULL) {//one left child
               r->data = r->left->data;
               delete r->left;
               r->left = NULL;
           }  
           else if (r->left == NULL && r->right != NULL) {//one right child
               r->data = r->right->data;
               delete r->right;
               r->right = NULL;
           }
           else {
           
               r->data = Max(r->left, r->data);
               r->left = Delete(r->left, r->data);
           }
       }
       return r;
   }
};

int main()
{
    BST b;
    // cout << b.Min(b.root, b.root->data) << "\n";
    b.Insert(45);
    b.Insert(15);
    b.Insert(79);
    b.Insert(90);
    b.Insert(10);
    b.Insert(55);
    b.Insert(12);
    b.Insert(20);
    b.Insert(50);
    b.Preorder(b.root);
    cout << endl;
    /* b.Inorder(b.root);
     cout << endl;
     b.Postorder(b.root);
     cout << endl;
   */
    Node* result = b.Delete(b.root, 12);
    b.Preorder(result);
    cout << endl;
    result = b.Delete(b.root, 15);
    b.Preorder(result);
}