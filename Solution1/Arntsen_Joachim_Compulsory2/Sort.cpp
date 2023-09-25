#include <iostream>
using namespace std;

int QuickSort_Partition(int Array[], int l, int h)
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
        int q = QuickSort_Partition(Array, l, h);
        QuickSort(Array, l, q - 1);
        QuickSort(Array, q + 1, h);
    }
}

void InsertionSort(int Array[], int n)
{
    if (n <= 1)
        return;

    InsertionSort(Array, n - 1);

    int l = Array[n - 1];
    int j = n - 2;

    while (j >= 0 && Array[j] > l)
    {
        Array[j + 1] = Array[j];
        j--;
    }
    Array[j + 1] = l;
}

void Merge(int*, int, int, int);
void MergeSort(int* Array, int l, int h)
{
    int m;
    if (l < h)
    {
        m = (l + h) / 2;
        MergeSort(Array, l, m);
        MergeSort(Array, m + 1, h);
        Merge(Array, l, h, m);
    }
}

void Merge(int* Array, int l, int h, int m)
{
    int i, j, k, c[10000];
    i = l;
    k = l;
    j = m + 1;
    while (i <= m && j <= h)
    {
        if (Array[i] < Array[j])
        {
            c[k] = Array[i];
            k++;
            i++;
        }
        else
        {
            c[k] = Array[j];
            k++;
            j++;
        }
    }
    while (i <= m)
    {
        c[k] = Array[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        c[k] = Array[j];
        k++;
        j++;
    }
    for (i = l; i < k; i++)
    {
        Array[i] = c[i];
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
        } while (!unique);

        Array[i] = new_random;
    }
    return 0;
}

void PrintArray(int Array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << Array[i] << " ";
}

int main()
{
    int Array[100];

    Random(Array, 100, 1, 1000);

    int n = 100;

    cout << "Original Array: \n ";
    PrintArray(Array, n);

    //Quick Sort Algorithm Using Recursive Implementation
    QuickSort(Array, 0, n - 1);
    

    //Insertion Sort Algorithm Using Recursive Implementation 
    InsertionSort(Array, n);


    //Merge Sort Algorithm Using Iterative Implementation 
    MergeSort(Array, 0, n - 1);

    cout << "\n\nSorted Array: \n ";
    PrintArray(Array, n);

    return 0;
}