This is an implemntation of a worst case O(N) soultion to the 1D Cluster Problem. 


# What is the 1D Cluster Problem?


Lets say you have an unsorted array. 


[ 5, 3, 2, 7, 20, 15, 18]


The 1D cluster problem would be finding the two pairs that would be ajacent in sorted order that are maximally farthest apart.


# Simple O(N LOG N) Soultion
A simple soultion to this problem is to sort it like the following piece of code 

```c
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
```

This code calls mergeSort and then loops through and returns the lower pair in the pair that has the furthest distance. This will succesfully return 7 and 15. This guartness an O(N LOG N) soultion to the problem. 

# The O(N) Soultion


1. First we get rid of the biggest and smallest number from the array in O(N) time using the following code. 

``````c
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
``````


We create an array of O(N - 1) buckets. We then insert each value into a bucket based on the following. 

```c
	float delta = fabsf(max - min );
    float queryValue = value;
    float ratio = (float)(queryValue - min) / delta;
    int index = (int)(ratio * n);
```

This uses nearly the following equation.

[(queryValue - min) / (Max - Min) ] * size of Array. 

You then insert each element into a bucket. 

