#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){

    unsigned int i;
    int key;
    int j;

    for (i = first + 1; i <= last; i++) {

        myCopy(&array[i], &key);   //key = array[i];
        j = i - 1;

		/* shifts the array 1 spot to the right
         * if the key is less than the right most 
         * sorted number.  */
        while (j >= (int)first && myCompare(array[j], key) > 0) {
            myCopy(&array[j], &array[j + 1]);   //array[j + 1] = array[j];
            j = j - 1;
        }
        myCopy(&key, &array[j + 1]);   //array[j + 1] = key;
    }
}
