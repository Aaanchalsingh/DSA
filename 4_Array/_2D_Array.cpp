//$ 2D ARRAY INITIALIZTION DISPLAY RULES
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // INITIALIZATION
    int A[2][3];

    int C[2][3] = {0};
    // FIRST METHOD
    int B[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // SECOND METHOD
    int **D;
    D = new int *[2];
    D[0] = new int[3];
    D[1] = new int[3];
    D[2] = new int[3];
    D[2][2] = 5;
    // THIRD METHOD
    int *E[2];
    E[0] = new int[3];
    E[1] = new int[3];
    E[0][1] = 5;
    // DISPLAYING 2D ARRAYS
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}