// ALL ARRAY OPERATIONS IN ONE
#include <iostream>
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
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    void insertion(int data, int index)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = data;
        length++;
    }
    void deletion(int index)
    {
        for (int i = index; i < length; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        cout << endl;
    }
    int get(int index)
    {
        return A[index];
    }
    void set(int index, int data)
    {
        A[index] = data;
    }
    int maximum()
    {
        int max = A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        return max;
    }
    int average()
    {
        int total = 0;
        for (int i = 0; i < length; i++)
        {
            total += A[i];
        }
        return total / length;
    }
    void reverse()
    {
        int i, j;
        for (i = 0, j = length - 1; i < length, i < j; i++, j--)
        {
            swap(A[i], A[j]);
        }
    }
    int linear_search(int key)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
    int binary_search(int key, int low, int high)
    {
        int mid = 0;
        if (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] == key)
            {
                return mid;
            }
            else if (A[mid] > key)
            {
                binary_search(key, low, mid - 1);
            }
            else if (A[mid] < key)
            {
                binary_search(key, mid + 1, high);
            }
            else
            {
                return -1;
            }
        }
    }
    void rearrange_()
    {
        int i, j;
        for (i = 0, j = length - 1; i < j; i++, j--)
        {
            while (A[i] < 0)
            {
                i++;
            }
            while (A[j] > 0)
            {
                j--;
            }
            if (i < j)
            {
                swap(A[i], A[j]);
            }
        }
    }
    Array *Union(Array *brr)
    {
        Array *crr = new Array(20);
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < length))
        {
            if (A[i] < brr->A[j])
            {
                crr->A[k++] = A[i++];
            }
            else if (A[i] > brr->A[j])
            {
                crr->A[k++] = brr->A[j++];
            }
            else
            {
                crr->A[k++] = brr->A[j++];
                i++;
            }
        }

        for (; i < length; i++)
        {
            crr->A[k++] = A[i];
        }
        for (; j < length; j++)
        {
            crr->A[k++] = brr->A[j];
        }
        crr->length = k;
        return crr;
    }
    Array *Intersection(Array *brr)
    {
        Array *crr = new Array(20);
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < length))
        {
            if (A[i] < brr->A[j])
            {
                i++;
            }
            else if (A[i] > brr->A[j])
            {
                j++;
            }
            else
            {
                crr->A[k++] = brr->A[j++];
                i++;
            }
        }
        crr->length = k;
        return crr;
    }
    Array *Difference(Array *brr)
    {
        Array *crr = new Array(20);
        int i = 0, j = 0, k = 0;
        while ((i < length) && (j < length))
        {
            if (A[i] < brr->A[j])
            {
                crr->A[k++] = A[i++];
            }
            else if (A[i] > brr->A[j])
            {
                j++;
            }
            else
            {
                j++;
                i++;
            }
        }

        for (; i < length; i++)
        {
            crr->A[k++] = A[i];
        }
        crr->length = k;
        return crr;
    }
};

int main()
{
    Array *arr1 = new Array(10);
    Array *arr2 = new Array(10);
    Array *arr3 = new Array(20);
    Array *arr4 = new Array(20);
    Array *arr5 = new Array(20);
    arr1->insertion(1, 0);
    arr1->insertion(2, 1);
    arr1->insertion(3, 2);
    arr1->insertion(4, 3);
    arr1->insertion(5, 4);
    arr1->insertion(6, 5);
    arr1->insertion(7, 6);
    arr1->display();
    arr2->insertion(0, 0);
    arr2->insertion(2, 1);
    arr2->insertion(4, 2);
    arr2->insertion(6, 3);
    arr2->insertion(8, 4);
    arr2->insertion(10, 5);
    arr2->insertion(12, 6);
    arr2->display();
    // arr1->deletion(0);
    // arr1->display();
    // arr1->reverse();
    // arr1->display();
    // cout << arr1->binary_search(arr, 5, 0, 10);
    // arr1->rearrange_();
    // arr1->display();
    // arr3 = arr1->Union(arr2);
    // arr3->display();
    // arr4 = arr1->Intersection(arr2);
    // arr4->display();
    // arr5 = arr1->Difference(arr2);
    // arr5->display();
    return 0;
}
