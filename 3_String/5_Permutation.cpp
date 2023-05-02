// PERMUTATION OF STRING
#include <bits/stdc++.h>
using namespace std;
void permutation(char *A, int k)
{
    static int H[10] = {0};
    static char R[10];

    if (A[k] == '\0')
    {
        R[k] == '\0';
        for (int i = 0; R[i] != '\0'; i++)
        {
            cout << R[i];
        }
        cout << "    ";
    }
    else
    {
         for (int i = 0; A[i] != '\0'; i++)
        {
            if (H[i] == 0)
            {
                R[k] = A[i];
                H[i] = 1;
                permutation(A, k + 1);
                H[i] = 0;
            }
        }
    }
}
int main()
{
    char A[10] = "ABC";
    permutation(A, 0);

    return 0;
}