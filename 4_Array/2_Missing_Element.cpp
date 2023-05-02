//#FIND MISSING ELEMENT IN AN ARRAY
//@SINGLE MISSING IN SORTED ARRAY
//$MULTIPLE MISSING IN SORTED ARRAY
//*MULTIPLE MISSING IN UNSORTED ARRAY

#include <bits/stdc++.h>
using namespace std;
class Array
{
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int siz)
    {
        size = siz;
        length = 0;
        A = new int[size];
    }
    ~Array() { delete[] A; }
    void insertion(int data, int index)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = data;
        length++;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    int Single_missing_sorted()
    {
        int total = 0, sum = 0, net = 0;
        total = ((length + 1) * (length + 2)) / 2;
        // n(n+1)/2->where n=length+1
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        if (total == sum)
        {
            cout << "NO MISSING ELEMENT FOUND ";
            return -1;
        }
        else
        {
            net = total - sum;
            return net;
        }

        return 0;
    }
    int multiple_missing_sorted()
    {
        int net = 0, k = 0;
        net = A[0];
        for (int i = 0; i < length; i++)
        {
            if (net != (A[i] - i))
            {
                while (net < (A[i] - i))
                {
                    cout << i + net << " ";
                    net++;
                }
            }
        }
    }
};
int main()
{
    Array *arr1 = new Array(10);
    arr1->insertion(6, 0);
    arr1->insertion(7, 1);
    arr1->insertion(8, 2);
    arr1->insertion(10, 3);
    arr1->insertion(13, 4);
    arr1->insertion(14, 5);
    arr1->insertion(15, 6);
    // cout << arr1->Single_missing_sorted();
    arr1->multiple_missing_sorted();
    return 0;
}