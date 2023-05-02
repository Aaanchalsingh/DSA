// DIAGONAL MATRICES
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
        A = new int[n];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Matrix() { delete[] A; }
    void set(int x, int i, int j)
    {
        if (i == j)
        {
            A[i - 1] = x;
        }
    }
    int get(int i, int j)
    {
        if (i == j)
        {
            return A[i - 1];
        }
        return 0;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cout << A[i - 1] << " ";
                }
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
    int getn()
    {
        return n;
    }
};
int main()
{
    int value;
    Matrix *B = new Matrix(4);
    for (int i = 0; i < B->getn(); i++)
    {
        for (int j = 0; j < B->getn(); j++)
        {
            cin >> value;
            B->set(value, i, j);
        }
    }
    B->display();
    return 0;
}