// Given an array, check whether the array is in sorted order with recursion.
#include <bits/stdc++.h>
using namespace std;
bool sorted(int array[], int n)
{
    if (n == 1)
        return true;
    else
    {
        if (array[n] >= array[n - 1])
        {
            sorted(array, n - 1);
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    int array[10] = {1, 12, 3, 4, 5, 6, 6, 7, 8, 9};
    cout << sorted(array, 9);
    return 0;
}