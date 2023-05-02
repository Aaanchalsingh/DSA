// AP-GP-HP CHECKER
// -1  0  1
#include <bits/stdc++.h>
using namespace std;
int static pre, cd = 0;
bool res = true;
int checker(int arr[], int n)
{
    if (n == 0)
    {
        return abs(arr[n + 1] - arr[n]);
    }
    else
    {
        pre = checker(arr, n - 1);
        cd = abs(arr[n - 1] - arr[n]);
        if (cd != pre)
        {
            res = false;
        }
        return pre;
    }
}
int main()
{
    int arr[10] = {0, 2, 4, 6, 8, 10};
    cout << checker(arr, 4);
    return 0;
}