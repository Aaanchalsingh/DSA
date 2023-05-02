// DELETION IN HEAP
#include <bits/stdc++.h>
using namespace std;
void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
int Deleted(int a[],int n){
int v=a[1];
if((a[2]>a[1])&&(a[2]>a[3])||a[2]<a[3]){
    a[1]=a[2];
}
else if((a[3]>a[1])&&(a[3]>a[2])||(a[2]>a[3])){
    a[1]=a[3];
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
    while (j < n)
    {
        if (A[j + 1] > A[j])
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
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40};
    int i;
    for (i = 2; i <= 7; i++)
    {
        Insert(H, i);
    }
    Delete(H, 1);
     Delete(H, 2);
    for (i = 1; i <= 6; i++)
    {
        cout << H[i] << " ";
    }

    return 0;
}