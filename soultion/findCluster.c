

#include "findCluster.h"

#include <stdlib.h>
#include <stdio.h>

#include "buckets.h"
#include "buckets.c"





//O(N) time
float * findMinMax(float array[], int n)
{
    float min = array[0];
    float max = array[0];
    for (int i =0; i < n; i++)
    {
        if (array[i] < min) min = array[i];

        else if (array[i] > max) max = array[i];

    }

    float * pair = malloc(sizeof(float) * 2);

    if (pair == NULL) return NULL;

    pair[0] = min;
    pair[1] = max;

    return pair;
}



//This function takes O(N) time
//If error is found then array[] points to a NULL variable

//THis algorithm uses enumation to return errors.
//It is reccomend that any used function checks that this function doesn't teturn NULL_pointer or MALLOC_Failed
//Any of those errors will appear as 1 or 2 in the return code, so if you get 1 or 2, and you are supposed to get
//something else most likely means you forgot your checking
/*
float array[] = {1.0, 1.2, 1.3};
    float x = findClusterExtreme(NULL, 3);

    if (x == NULL_POINTER) return 1;

    if (x == MALLOC_FAILED) return 2;

    printf("%f ", x);

 */
float findClusterExtreme(float array[], int n)
{
    if (array == NULL) return NULL_POINTER;

    if (n == 1) return array[0];

    float * MinAndMax = findMinMax(array, n);

    if (MinAndMax == NULL) return MALLOC_FAILED;


    if (n == 2) return MinAndMax[0];


    //This creates an ArrayOfBuckets in O(1) time
    buckets  ** ArrayOfBuckets = createArrayBuckets(n + 1);

    if (ArrayOfBuckets == NULL)
    {
        return MALLOC_FAILED;
    }

    if (ArrayOfBuckets == NULL) return -1;

    float min = MinAndMax[0];

    float max = MinAndMax[1];

    for (int i =0; i < n; i++)
    {
        if (array[i] == MinAndMax[0] || array[i] == MinAndMax[1]) continue;
        insertWithAlgorithm(ArrayOfBuckets, array[i], n + 1, min, max);
    }




    return findBiggestExterme(ArrayOfBuckets, n, min, max);
}