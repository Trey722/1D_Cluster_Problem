#include "buckets.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void insertWithAlgorithm(buckets  ** ArrayOfBuckets,float value, int n, float min, float max)
{
    float delta = fabsf(max - min );
    float queryValue = value;
    float ratio = (float)(queryValue - min) / delta;
    int index = (int)(ratio * n);


    insertBucket(value, ArrayOfBuckets[index]);

}



void insertBucket(float value, buckets * bucket_X)
{
    bucket_X->size += 1;

    if ((bucket_X->size - 1) == 0)
    {
        bucket_X->min = value;
        bucket_X->max  = value;
        return;
    }

    if (bucket_X->min > value) bucket_X->min = value;

    else if (bucket_X->max < value) bucket_X->max = value;
}

buckets ** createArrayBuckets(int size)
{
    buckets ** array = malloc(sizeof(buckets*) * size);

    if (array == NULL) return NULL;

    for (int i =0; i < size; i++)
    {
        array[i] = malloc(sizeof(buckets));
        if (array[i] == NULL) return NULL;
        array[i]->size = 0;
    }

    return array;
}




float findBiggestExterme(buckets ** arrayBuckets, int size, float min, float max)
{
    if (arrayBuckets == NULL) {return NULL_POINTER;}
    buckets ** newArrayBuckets = malloc(sizeof(buckets) * size);
    if (newArrayBuckets == NULL) return MALLOC_FAILED;
    int a = 0;
    for (int i =0; i < size; i++)
    {
        if (arrayBuckets[i]->size == 0) continue;
        newArrayBuckets[a] = arrayBuckets[i];
        a += 1;
    }

    if (a == 0)
    {
        return min;
    }

    float biggestDiffernce = fabsf(min - newArrayBuckets[0]->min);
    float MaxSmall = min;
    float curDiffernce = 0;



    for (int i = 0; i < a; i++)
    {
        curDiffernce = fabsf(newArrayBuckets[i]->min - newArrayBuckets[i]->max);
        if (curDiffernce > biggestDiffernce)
        {
            biggestDiffernce = curDiffernce;
            MaxSmall = newArrayBuckets[i]->min;
        }

        if (i == a - 1)
        {
            curDiffernce = fabsf(newArrayBuckets[i]->max - max);
            if (curDiffernce > biggestDiffernce) return  newArrayBuckets[i]->max;
            else return MaxSmall;
        }

        curDiffernce = fabsf(newArrayBuckets[i]->max - newArrayBuckets[i + 1]->min);
        {
            if (curDiffernce > biggestDiffernce)
            {
                biggestDiffernce = curDiffernce;
                MaxSmall = newArrayBuckets[i]->max;
            }
        }
    }

    return MaxSmall;
}
