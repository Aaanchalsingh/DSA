// SORTING TECHNIQUES
//  1. BUBBLE SORT
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) // 0[012345]1[01234]2[0123]3[012]4[01]5[0]
        {                                   // j-i-1 so to reduce time
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
            
    }
}
int main()
{
    int A[] = {0, 20, 5, 35, 10, 15, 40, 30};
    bubble_sort(A, sizeof(A) / 4);
    for (int i = 0; i < sizeof(A) / 4; i++)
        cout << A[i] << " ";

    return 0;
}
// CRITERIA FOR ANYLASIS
//#KEY POINTS FOR BUBBLE SORT METHOD
//@ TIME COMPLEXITY = O(n^2)
//^TOTAL NO. OF COMPARISON = O(n^2)
//$  TOTAL NO. OF SWAP = O(n^2)
//* BUBBLE SORT IS ADAPTIVE IN NATURE =>It means if bubble sort is sorted then it will not swap any further . In other words we can say that bubble sort was not adaptive but we made it adaptive
//= BUBBLE SORT IS STABLE IN NATURE => If duplicates are present then it never swaps the duplicates
//- BUBBLE SORT DO NOT REQUIRES ANY EXTRA SPACE
//% TOATAL NUMBER OF PASSES = n-1
// AFTER PASS 1 => WE OBTAIN 1ST LARGEST NUMBER
// AFTER PASS 2 => WE OBTAIN 2ND LARGEST NUMBER
// AFTER PASS 3 => WE OBTAIN 3RD LARGEST NUMBER
// AFTER PASS K => WE OBTAIN KTH LARGEST NUMBER