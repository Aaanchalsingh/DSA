// Toeplitz MATRIX
#include <bits/stdc++.h>
using namespace std;
class Matrix
{
    int *A;
    int n;

public:
    Matrix(int n)
    {
        this->n = n;
        A = new int[(2 * n)];
    }
    ~Matrix() { delete[] A; }
    void set(int x, int i, int j)
    {
        if (i <= j)
            A[j - i] = x;
        else
            A[n - 1 + i - j] = x;
    }
    int get(int i, int j)
    {
        if (i <= j)
            return A[j - i];
        else
            return A[n - 1 + i - j];
    }
    void display()
    {
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                {
                    cout << A[j - i] << " ";
                }
                else
                    cout << A[n - 1 + i - j] << " ";
            }
            cout << endl;
        }
    }
    int getn() { return n; }
};
int main()
{
    int value;
    Matrix *B = new Matrix(4);
    for (int i = 1; i <= B->getn(); i++)
    {
        for (int j = 1; j <= B->getn(); j++)
        {
            cin >> value;
            B->set(value, i, j);
        }
    }
    B->display();
    return 0;
}
