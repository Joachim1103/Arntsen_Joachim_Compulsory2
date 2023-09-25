#include <iostream>
#include <algorithm>
#include <chrono>
#include<vector>
using namespace std::chrono;
using namespace std;

int Partition(int Array[], int l, int h)
{
    int p = Array[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++)
    {
        if (Array[j] <= p)
        {
            i++;
            swap(Array[i], Array[j]);
        }
    }
    swap(Array[i + 1], Array[h]);
    return (i + 1);
}

void QuickSort(int Array[], int l, int h)
{
    if (l < h)
    {
        int q = Partition(Array, l, h);
        QuickSort(Array, l, q - 1);
        QuickSort(Array, q + 1, h);
    }
}

int Random(int Array[], int length, int min, int max)
{
    int new_random;
    bool unique;

    for (int i = 0; i < length; i++)
    {
        do 
        {
            new_random = (rand() % (max - min + 1)) + min;

            unique = true;
            for (int j = 0; j < i; j++)
                if (Array[j] == new_random) unique = false;
        } 
        while (!unique);

        Array[i] = new_random;
    }
    return 0;
}

int main()
{
    int Array[100];

    Random(Array, 100, 1, 100);

    int n = 100;
    QuickSort(Array, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << Array[i] << " ";

    return 0;


}

