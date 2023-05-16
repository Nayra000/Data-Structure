#include <iostream>
using namespace std;

class Array{

private:
    int size;
    int length;
    int* ptr;

public:
    Array(int _size) {  //Creation
        size = _size;
        length = 0;
        ptr = new int[size];
    }

    void Fill() {
        int no_items;
        cout<< "Enter number of items\n";
        cin >> no_items;
        if (no_items > size) {
            cout << "You excced the valid size \n";
            return;
        }
        for (int i = 0; i < no_items; i++) {
            cout << "Enter an item number " << i + 1 << "\n";
            cin >> ptr[i];
            length++;
        }

    }

    void Display() {
        cout << "Array items \n";
        for (int i = 0; i < length; i++) {
            cout << ptr[i] << "\t";
        }
        cout << endl;
    }
    int GetSize() {
        return size;
    }
    int GetLength() {
        return length;
    }
    int Search(int key) {
        int index = -1;
       /* int l = 0, r = length - 1, mid;
        while (l <= r) {
            mid = (l + r)/2;
            if (ptr[mid] < key) {
                l = mid+1;
                
            }
            else if(ptr[mid] > key) {
                r = mid-1;
            }
            else {
                return mid;
            }
        }
        return index;*/

        for (int i = 0; i < length; i++) {
            if (ptr[i] == key) {
                index = i;
                break;
            }
        }
        return index;
    }
    void Append(int newitem) {
        if (length < size) {
            ptr[length] = newitem;
            length++;
        }
        else {
            cout << "The array is full \n";
        }
    }
    void Insert(int index, int newitem) {
        if (index >= 0 && index < size)
        {
            if (length < size) {
                int i = length - 1;
                while (i >= index) {
                    ptr[i + 1] = ptr[i]; //1      4 5 6
                    i--;
                }
                ptr[index] = newitem;
                length++;
            }
            else {
                cout << "Array is full \n";
            }
        }
        else {
            cout << "Out of the range \n";
        }
    }
    void Delete(int index) {
        if (index >= 0 && index < size) {
            length--;
            while (index < length - 1)
            {
                ptr[index] = ptr[index + 1];
                index++;
            }
        }
        else {
            cout << "Out of the renge \n";
        }
    }

    void Enlarge(int newsize) {
        if (newsize <= size) {
            cout << "You must enter a lager size";
        }
        else
        {
            int* old = ptr;
            ptr = new int[newsize];
            size = newsize;
            for (int i = 0; i < length; i++) {
                ptr[i] = old[i];
            }
            delete []old;
        }
 

    }
    void Merge(Array other) {
        int* old = ptr;
        size = size + other.GetSize();
        ptr = new int[size];
        for (int i = 0; i < length; i++) {  //0 1 2 3 4
            ptr[i] = old[i];
        }
        delete[] old;
        int j =length;
        for (int i = 0; i < other.GetLength(); i++) {
            ptr[j] = other.ptr[i];
            j++;
        }
        length =length+ other.GetLength();
    }

};
int main()
{
    Array arr1(10),arr2(2);
    arr1.Fill();
    arr1.Display();
    arr2.Fill();
    arr2.Display();

    arr1.Merge(arr2);
    arr1.Display();
    cout << arr1.GetLength() << " " << arr1.GetSize() << "\n";
   
    
}

