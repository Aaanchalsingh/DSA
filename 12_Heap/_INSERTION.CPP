// MAX HEAP /CREATION OR INSERTION
#include <bits/stdc++.h>
using namespace std;
void insert(int key[], int n)
{
    int i = n;//i=2
    int temp = key[n];//temp=5
    while (i > 1 && temp > key[i / 2]) // FOR MIN HEAP JUST CHANGE TO temp < key[i/2]
    {
        key[i] = key[i / 2];
        i = i / 2;
    }
    key[i] = temp;
}//0, 10, 5, 9, 30, 25, 45, 40
void create(int key[], int n)
{
    for (int i = 2; i < n; i++)
    {
        insert(key, i);
    }
}
void display(int key[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << key[i] << " ";
    }
}

int main()
{
    int key[] = {0, 10, 5, 9, 30, 25, 45, 40};
    create(key, sizeof(key) / 4);
    display(key, sizeof(key) / 4);
    return 0;
}