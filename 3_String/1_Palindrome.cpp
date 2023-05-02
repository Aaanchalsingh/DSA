#include <bits/stdc++.h>
using namespace std;
int palindrome(char *A)
{
    int i, j;
    for (i = 0, j = strlen(A) - 1; A[i] != '\0', j >= 0;)
    {
        if (A[i] == A[j])
        {
            i++, j--;
        }
        else
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    char A[] = "RADAR";
    cout << palindrome(A);
    return 0;
}