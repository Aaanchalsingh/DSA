// TRIDIAGONAL
#include <bits/stdc++.h>
using namespace std;
class Matrix
{
    int *A;
    int n;

public:
    Matrix()
    {
        n = 4;
        A = new int[(3 * n) - 2];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[(3 * n) - 2];
    }
    ~Matrix() { delete[] A; }
    void set(int x, int i, int j)
    {
        if ((i - j) == 0)
            A[n - 1 + i - 1] = x;
        else if ((i - j) == 1)
            A[2 * n - 1 + j - 1] = x;
        else if ((i - j) == -1)
            A[i - 1] = x;
    }
    int get(int i, int j)
    {
        if ((i - j) == 0)
            return A[n - 1 + i - 1];
        else if ((i - j) == 1)
            return A[2 * n - 1 + j - 1];
        else if ((i - j) == -1)
            return A[i - 1];
        else
            return 0;
    }
    void display()
    {
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if ((i - j) == 0)
                    cout << A[n - 1 + i - 1] << " ";
                else if ((i - j) == 1)
                    cout << A[2 * n - 1 + j - 1] << " ";
                else if ((i - j) == -1)
                    cout << A[i - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
    int getn() { return n; }
};
int main()
{
    int value;
    Matrix *B = new Matrix(5);
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
