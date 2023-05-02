// REDUCED PERMUTATION OF STRING WIHOUT TWO AUXILLAR ARRAY
#include <bits/stdc++.h>
using namespace std;
void permutation(char *A, int low, int high)
{

    if (low == high)
    {
        for (int i = 0; A[i] != '\0'; i++)
        {
            cout << A[i];
        }
        cout << "    ";
    }
    else
    {
        for (int i = low; i<=high; i++)
        {
            swap(A[low], A[i]);
            permutation(A, low + 1, high);
            swap(A[low], A[i]);
        }
    }
}
int main()
{
    char A[10] = "ABC";
    permutation(A, 0,2);

    return 0;
}