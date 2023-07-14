#include <iostream>
#include <string>
#include <cmath>
#pragma warning (disable: 4996)
using namespace std;


//function to get the max element in the array 
inline int getmax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

//function CountSort
inline void CountSort(int a[], int n, int exp)
{
     int *result= new int[n], i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        result[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = result[i];
}

// function Radix Sort
inline void radixsort(int a[], int n)
{
    int exp, i;
    i = getmax(a, n);
    for (exp = 1; i / exp > 0; exp *= 10)
        CountSort(a, n, exp);
}

//function heapify
inline void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }

}

//function heap sort
inline void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

//function read elements in the array 
inline void read(int* Arr, int size)
{
    cout << endl << "read an elements in the array " << endl;
    for (int k = 0; k < size; ++k)
    {
        cout << "enter number: ";
        cin >> Arr[k];
    }
}

//function to print Array 
inline void printArray(int Arr[], int number)
{
    for (register int i = 0; i < number; i++)
        cout << Arr[i] << "	";
}

int main()
{
    while (true) {
        cout << endl;
        cout << "list of tasks" << endl
            << "1-counting Sort + Radix sort" << endl
            << "2-Heap Sort" << endl
            << "3-exit" << endl
            << "*****************************" << endl;
        int size, choice;
        int* arr, * array;
        cout << "Enter a choice :";
        cin >> choice;

        switch (choice) {
        case 1:
            cout <<endl<< " plese read the size of array :";
            cin >> size;
            arr = new int[size];

            cout << endl << "read an elements in the array " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << " enter a number: ";
                cin >> arr[i];
            }

            radixsort(arr, size);
            cout << endl << endl << "the array after sorted " << endl; 
            printArray(arr, size);
            cout << endl; break;

        case 2:

            cout << endl << " plese read the size of array :";
            cin >> size;
            array = new int[size];
            read(array, size);
            cout << endl << "the array after sorted " << endl;
            heapSort(array, size);
            printArray(array, size);
            cout << endl; break;

        case 3:
            exit(0); break;

        default:cout << "wrong choice .. please try again";
            cout << endl; break;
        }
    }
    return 0;
}