//^Anagram means like "MEDICAL" & "DECIMAL" SAME LETTERS BUT DIFFERENT POSITIONS
//#HASH TABLE TECHNIQUE TO FIND ANAGRAM
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char A[10] = "DECIMAL";
    char B[10] = "MEDICAL";
    int C[26] = {0};
    for (int i = 0; i < 10; i++)
    {
        C[A[i] - 65]++;
    }
    for (int i = 0; i < 10; i++)
    {
        C[B[i] - 65]--;
    }
    bool res = true;
    for (int i = 0; i < 26; i++)
    {
        if (C[i] > -1)
            continue;
        else
        {
            res = false;
            break;
        }
    }
    if (res)
        cout << "ANAGRAM REFLECTS IN THE STRING ";
    else
        cout << "NO ANAGRAM  FOUND IN THE STRING ";

    return 0;
}
