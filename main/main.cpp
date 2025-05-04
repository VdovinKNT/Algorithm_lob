// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_Heap/Heap.h"

template <typename T>
void print_array(const T arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void heapify(T arr[], size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

template <typename T>
void heap_sort(T arr[], size_t n)
{
    for (size_t i = n / 2 - 1; i < n; i--)
    {
        heapify(arr, n, i);
    }

    for (size_t i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    size_t n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    print_array(arr, n);

    heap_sort(arr, n);

    std::cout << "Sorted array: ";
    print_array(arr, n);

    return 0;
}

#endif // EASY_EXAMPLE