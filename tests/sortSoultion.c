#include "sortSoultion.h"

#include "stdlib.h"
#include "stdio.h"

#include "mergeSort.h"
#include "mergeSort.c"

#include "math.h"


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


float findClusterExtermeViaSorting(float array[], int size)
{
    mergeSort(array, 0, size - 1);

    float a;
    float biggestDiffernce = 0;
    float BigA = array[0];
    float b;
    for (int i =0; i < size - 1; i++)
    {
        a = array[i];
        b = array[i + 1];
        if (fabsf(a - b) > biggestDiffernce)
        {
            biggestDiffernce = fabsf(a - b);
            BigA = a;
        }
    }

    return BigA;
}

float findClusterExtermeViaQuickSort(float array[], int size)
{
    qsort(array, size, sizeof(int), compare);

    float a;
    float biggestDiffernce = 0;
    float BigA = array[0];
    float b;
    for (int i =0; i < size - 1; i++)
    {
        a = array[i];
        b = array[i + 1];
        if (fabsf(a - b) > biggestDiffernce)
        {
            biggestDiffernce = fabsf(a - b);
            BigA = a;
        }
    }

    return BigA;

}




