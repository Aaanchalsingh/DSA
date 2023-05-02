// HEAP SORT IS JUST OBTAINED AFTER DELETING ALL ELEMENT FROM HEAP
#include <bits/stdc++.h>
using namespace std;
void Heapify(int A[], int n)
{ 
    static int size = n;
    int i, j, temp;
    i = j = n;
    temp = A[j];
    while (temp > A[i / 2])
    {
        int swap = A[j];
        A[j] = A[i / 2];
        A[i / 2] = swap;
    }
    if ((2 * i) < size)
    {
        if (A[i] < A[2 * i])
        {
            int swap = A[i];
            A[i] = A[2 * i];
            A[2 * i] = swap;
        }
    }
}
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return val;
}
int main()
{
    int H[] = {0, 20, 5, 35, 10, 15, 40, 30};
    int i;
    for (i = 7; i > 1; i--)
        Heapify(H, i);

    // for (i = 7; i > 1; i--)
    // {
    //     Delete(H, i);
    // }
    for (i = 1; i <= 7; i++)
        cout << H[i] << " ";
    cout << "\n";

    return 0;
}