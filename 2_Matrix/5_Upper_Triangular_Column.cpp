// UPPER TRIANGULAR MATRIX USING COLUMN MAJOR FORMULA
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
        A = new int[n*(n+1)/2];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~Matrix() { delete[] A; }
    void set(int x, int i, int j)
    {
        if (i <= j)
        {
            int k = ((((j - 1) * (j)) / 2) + (i - 1));
            A[k] = x;
        }
    }
    int get(int i, int j)
    {
        if (i <= j)
        {
            int k = ((((j - 1) * (j)) / 2) + (i - 1));
            return A[k];
        }
        return 0;
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                {
                    cout << A[((((j - 1) * (j)) / 2) + (i - 1))] << " ";
                }
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
