//#POINTS TO REMEMBER
//@ Char is of 1 byte which is equal to 7 bit for example int binary 1 is 0001 2 is 0010
//$bitwise left shift==A<<2 where the arraow will go bits will also shift
//%BitwiseANDing is 00&11=00 it is used to check the state either 0 or 1 like in hashing Also Called Masking
//-BitwiseORing is 00|11=00 it is used to change the state either 0 or 1 Also Called Merging
//^WE NEED ALL OF THE ABOVE TO FIND DUPLICATES IN AN ARRAY
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char A[10] = "AANCHALL";
    int x = 0, H = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1; // N=N<<M then N will become N=N*(2^M)
        int n= (A[i] - 65);
        x = x << (A[i] - 65);
        if ((H & x) > 0)
            cout << A[i];
        else
            H = (H | x);
    }
//ONE INT CONTAINS 4 BYTES ,EACH BYTE CONTAINS 8 BITS 
// [----------2524][2322212019181716][15141312111098][76543210]
//THIS IS ONE INTEGER VARIABLE NO FILL VALUES IN LIKE HASHING
//FOR FIRST F=5 SO,
//      [00000000][00000000][00000000][00100000] INCREMENTED WHERE 5 POSITION
//IF WE WANT TO CHECK WHETHER THE NUMBER IS PRESENT EARLIER OR NOT THEN WE DO MASKING
//WE FIRST TAKE ANOTHER VARIABLE INITIALLISE IT WITH 1 THEN WE RIGHT SHIFT THAT ELEMENT THEN PERFORM AND IF TRUE IS RETURNED THEN WE WILL GET OUR DUPLICATE VALUE OTHER WISE USING OR IT WILL SET TO 1

    return 0;
}