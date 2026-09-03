#include "mySort.h"
#define MAX_SIZE 100000

/* Merge function */
void merge(int array[], unsigned int first, unsigned int mid, unsigned int last) {

    int temp[MAX_SIZE];

    unsigned int i = first;
    unsigned int j = mid + 1;
    unsigned int k = 0;

    while (i <= mid && j <= last) {

        if (myCompare(array[i], array[j]) <= 0) //if (array[i] <= array[j]) 
        {
            myCopy(&array[i], &temp[k]); //temp[k] = array[i]; 
            i++;
        }
        else {
            myCopy(&array[j], &temp[k]); //temp[k] = array[j]; 
            j++;
        }
        k++;
    }

    /* Copy remaining left side */
    while (i <= mid) {
        myCopy(&array[i], &temp[k]); // temp[k] = array[i]; */
        i++;
        k++;
    }

    /* Copy remaining right side */
    while (j <= last) {
        myCopy(&array[j], &temp[k]); //temp[k] = array[j]; */
        j++;
        k++;
    }

    /* Copy temp back into array */
    for (i = 0; i < k; i++) {
        myCopy(&temp[i], &array[first + i]); //array[first + i] = temp[i]; */
    }
}

/* Recursive merge sort */
void mergeSort(int array[], unsigned int first, unsigned int last) {

    if (first >= last)
        return;

    unsigned int mid = (first + last) / 2;

    mergeSort(array, first, mid);
    mergeSort(array, mid + 1, last);

    merge(array, first, mid, last);
}

void mySort(int array[], unsigned int first, unsigned int last) {
    mergeSort(array, first, last);
}
