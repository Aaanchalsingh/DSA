// PRINT STARS
//*
//* *
//* * *
//* * * *
#include <bits/stdc++.h>
using namespace std;
string u;
// row 1 col 1

void stars(int row, int col)
{
    if (row > 0)
    {
        cout << "*";
        stars(row - 1, col - 1);
    }

    cout << endl;
}
int main()
{
    stars(4, 4);
    return 0;
}