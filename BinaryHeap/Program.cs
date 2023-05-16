using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryHeap
{
    public class Node
    {
       public int data;
       public Node left;
       public Node right;
       public Node myparent;


        public Node()
        {
            data = 0;
            left = null;    
            right = null;
            myparent = null;    
        }
        public Node(int data)
        {
            this.data = data;
            left = null;
            right = null;
            myparent = null;
        }
    }

    public class BinaryHeap
    {
        Node parent;
        Node last;
        Node found;
        public int count = 0;
        public BinaryHeap()
        {
            parent = null;  
        }
        void swap(ref int x,ref int y)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        public void Insert(int new_value)
        {
            last = new Node(new_value);
            if (parent == null)
            {
                parent = last;

            }
            else
            {
                //insert at the end
                Queue<Node> queue = new Queue<Node>();
                queue.Enqueue(parent);
                while (true)
                {
                    Node temp = queue.Dequeue();
                    if (temp.left == null)
                    {
                        temp.left = last;
                        last.myparent = temp;
                        break;
                    }
                    else if (temp.right == null)
                    {
                        temp.right = last;
                        last.myparent = temp;
                        break;
                    }
                    queue.Enqueue(temp.left);
                    queue.Enqueue(temp.right);
                }
                heapfiy();
            }
            count++;

        }
        void heapfiy()
        {
            Node p = last;
            while (p.myparent != null )
            {
                if (p.data > p.myparent.data)
                {
                    swap(ref p.data,ref p.myparent.data);
                   }
                p = p.myparent;
                
            }
        }
        public void Delete(int element)
        {
            bool is_found = Search(element);
            if (!is_found)
            {
                Console.WriteLine("The element is not found");
                return;
            }
            else
            {
                found.data = last.data;  //to swap data between the last node and the deleted node
                if (last.myparent.right == null) //these conditions to delete the last node
                {               
                    last.myparent.left = null;
                }
                else
                {
                    last.myparent.right = null;
                }
                Queue<Node> queue = new Queue<Node>();
                queue.Enqueue(parent);
                while (true) //this loop to update the last refrence
                {
                    Node temp2 = queue.Dequeue();

                    if (temp2.left == null)
                    {
                        break;
                    }
                    if (temp2.right != null)
                    {
                        last = temp2.right;
                    }
                    else
                    {
                        last = temp2.left;
                    }
                    queue.Enqueue(temp2.left);
                    queue.Enqueue(temp2.right);
                }
                Node temp = found;
                while(temp.left != null && temp.right!=null) //heapify
                {
                   if(temp.data < temp.left.data && temp.right == null)
                   {
                        swap(ref temp.data,ref temp.left.data);
                        temp = temp.left;   
                   }
                   else if(temp.data < temp.left.data && temp.left.data > temp.right.data)
                   {
                        swap(ref temp.data,ref temp.left.data);
                        temp=temp.left;
                   }
                   else if(temp.data < temp.right.data && temp.right.data > temp.left.data)
                   {
                        swap(ref temp.data,ref temp.right.data);
                        temp=temp.right;
                   }
                   else
                   {
                        break;
                   }
                   
                }
                Node p = found;
                while (p.myparent != null)
                {
                    if (p.data > p.myparent.data)
                    {
                        swap(ref p.data, ref p.myparent.data);
                    }
                    p = p.myparent;

                }
            }
            count--; 
            if(count == 0)
            {
                parent = null;  
            }
        }
       public bool Search(int element)
       {
            if (element > parent.data)
            {
                return false;
            }
            else if (element == parent.data)
            {
                found = parent;
                return true;    
            }
            else
            {  
                Queue<Node> queue = new Queue<Node>();
                queue.Enqueue(parent);
                while (true)
                {
                    Node temp = queue.Dequeue();
                    if(temp.left ==null && temp.right == null)
                    {
                        return false;
                    }
                    if (temp.left != null && temp.left.data == element)
                    {
                        found = temp.left;
                        return true;
                    }
                    if (temp.right != null && temp.right.data == element)
                    {
                        found=temp.right;
                        return true;
                    }
                    queue.Enqueue(temp.left);
                    queue.Enqueue(temp.right);                 
                }             
            }
       }
        void Inorder(Node node)
        { //left root right
        
            if (node == null)
            {
                return;
            }
            Inorder(node.left);
            Console.Write(node.data+"\t");
            Inorder(node.right);

        }
        public void display(BinaryHeap binaryHeap)
        {
            Inorder(binaryHeap.parent);
            Console.WriteLine();
        }




    }
    internal class Program
    {
        static void Main(string[] args)
        {
            BinaryHeap binaryHeap = new BinaryHeap();

            binaryHeap.Insert(2);
            binaryHeap.Insert(7);
            binaryHeap.Insert(10);
            binaryHeap.Insert(8);
            binaryHeap.Insert(16);
            binaryHeap.Insert(9);
            binaryHeap.Insert(3);
            binaryHeap.Insert(14);
            binaryHeap.Insert(4);
            binaryHeap.Insert(1);
            Console.WriteLine("My binary heap in order travesring");
            binaryHeap.display(binaryHeap);//1
            Console.WriteLine();
            Console.WriteLine("Is 10 in my binary heap : "+binaryHeap.Search(10));
            binaryHeap.Delete(10);
            Console.WriteLine("Is 10 in my binary heap : " + binaryHeap.Search(10));
            Console.WriteLine();
           // binaryHeap.display(binaryHeap);//2
            binaryHeap.Delete(8);
            //binaryHeap.display(binaryHeap);//3
            binaryHeap.Delete(7);
            //binaryHeap.display(binaryHeap);//4
            binaryHeap.Delete(14);
            //binaryHeap.display(binaryHeap);//5
            binaryHeap.Delete(2);
          //  binaryHeap.display(binaryHeap);//6
            binaryHeap.Delete(1);
           // binaryHeap.display(binaryHeap);
            binaryHeap.Delete(3);
            //binaryHeap.display(binaryHeap);
            binaryHeap.Delete(4);
            Console.WriteLine("The heap after deleting 10 8 7 14 2 1 3 4");
            binaryHeap.display(binaryHeap);
            Console.WriteLine();
            binaryHeap.Insert(3);
            binaryHeap.Insert(14);
            binaryHeap.Insert(4);
            binaryHeap.Insert(17);
            Console.WriteLine("The heap after inserting 3 14 4 17");
            binaryHeap.display(binaryHeap);
            Console.WriteLine();









        }
    }
}
