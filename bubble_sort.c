#include <stdio.h>                                      //Header files

void printArray(int arr[], int N)                       //Prints the array
{
    for(int i = 0; i < N; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)                               //swaps x and y
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int N)                      //Sorting of the array using bubble sort.
{
    int swapped;                                        //To check if there was a swap. If there was no swap then the array is sorted. 0 is false. 1 is true.

    for(int i = 0; i < N-1; i++)                        //Traverses the array from 0 to N-1.
    {
        swapped = 0;
        for(int j = 0; j < N-i-1; j++)                  //Traverses from 0 to N-i-1. Does not traverses over the sorted region.
        {
            if(arr[j] > arr[j+1])                       //If the adjacent element is less than the element.
            {
                swapped = 1;                            //Swap is true
                swap(&arr[j], &arr[j+1]);               //Swapping the element with it's adjacent element.
            }
        }

        if(swapped == 0)                                //If there was no swapping meaning the array is sorted. 0 is false. 1 is true.
        {
            break;                                      //exits the loop.
        }
    }
}

int main()
{
    int arr[] = {10, 7, 2, 8, 6, 1, 5, 3, 0, 9, 4};     //intialising an array to work with
    int N = sizeof(arr) / sizeof(arr[0]);               //Size of the array

    printArray(arr, N);                                 //Prints the array before the array is sorted
    bubble_sort(arr, N);                                //Calling the bubble_sort function to sort the array
    printArray(arr, N);                                 //Prints the array after the array is sorted

    return 0;
}

// Time Complexity = O(N**2)