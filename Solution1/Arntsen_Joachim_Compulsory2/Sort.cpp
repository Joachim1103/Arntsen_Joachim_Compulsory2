#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

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

void Merge(int Array[], int l, int m, int r);

int Min(int x, int y) { return (x < y) ? x : y; }

void MergeSort(int Array[], int n)
{
    int curr_size;

    int left_start;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {

        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {

            int mid = min(left_start + curr_size - 1, n - 1);

            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            Merge(Array, left_start, mid, right_end);
        }
    }
}

void Merge(int Array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (i = 0; i < n1; i++)
        L[i] = Array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = Array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            Array[k] = L[i];
            i++;
        }
        else
        {
            Array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        Array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        Array[k] = R[j];
        j++;
        k++;
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
    const int n = 100;

    static int Array[n];

    Random(Array, n, 1, 100000);

    cout << "Original Array: \n ";
    PrintArray(Array, n);

    auto start = high_resolution_clock::now();

    //Quick Sort Algorithm Using Recursive Implementation
    QuickSort(Array, 0, n - 1); 


    //Insertion Sort Algorithm Using Recursive Implementation 
    InsertionSort(Array, n); 


    //Merge Sort Algorithm Using Iterative Implementation 
    MergeSort(Array, n);

    auto stop = high_resolution_clock::now();

    cout << "\n\nSorted Array: \n ";
    PrintArray(Array, n);

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n\nTime taken : " << duration.count() << " microseconds" << endl;

    return 0;
}