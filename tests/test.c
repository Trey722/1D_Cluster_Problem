#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#include "sortSoultion.h"
#include "findCluster.c"




// Function type for the function to be tested
typedef void (*TestFunction)();

// Function to measure the execution time of a function
double measureExecutionTime(TestFunction func) {
    clock_t start_time = clock(); // Record the start time
    func(); // Call the provided function
    clock_t end_time = clock(); // Record the end time

    // Calculate the elapsed time in seconds
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}


float getRandomFloat()
{
    return ((float)rand() * (float)drand48()) / 200;
}


float * createArrayOfFloat(int size)
{
    float * array = malloc(sizeof(float) * (size));

    if (array == NULL)
    {
        printf("Malloc Failed in function createArrayOfFloat");
        return NULL;
    }
    for (int i =0; i < size; i++)
    {
        array[i] = getRandomFloat();
    }

    return array;
}





int checkForTime() //QuickSort is again used abouve 1 MILLion to pervent the memory usage for merge sort
{
    clock_t start_time;
    clock_t end_time;
    double YourAlgorithm;
    double sortThenSovle;

    float * array = createArrayOfFloat(1024);

    if (array == NULL) return -1;



    for (int i = 2048; i < 1000000000; i *= 2) {
        array = createArrayOfFloat(i);  // You should provide createArrayOfFloat().

        if (array == NULL) return -1;


        start_time = clock();
        findClusterExtreme(array, i);
        end_time = clock();


        // Calculate the elapsed time in seconds
        YourAlgorithm = (double)(end_time - start_time) / CLOCKS_PER_SEC;


        start_time = clock();
        if (i > 1000000) {findClusterExtermeViaQuickSort(array, i);}
        else {findClusterExtermeViaQuickSort(array, i);}
        end_time = clock();

        // Calculate the elapsed time in seconds
        sortThenSovle = (double)(end_time - start_time) / CLOCKS_PER_SEC;



        printf("bucketsSoultion takes y =  %f x = %d\n", YourAlgorithm, i);
        printf("Sorting takes y =  %f x = %d\n \n", sortThenSovle, i);
    }

    return 0;

}

int checkForAccuracy() //If More then 1 Million Tests. It is reccomended that you use quicksort becuase mergesort runs into issues
{
    float yourAlgoirthm;
    float acuarteAlgorithm;


    for (int i = 1000000; i < 10000000; i *= 2)
    {

        float * array = createArrayOfFloat(i);

        if (array == NULL) return -1;
        yourAlgoirthm = findClusterExtreme(array, i);

        if (yourAlgoirthm == NULL_POINTER) return -1;

        if (yourAlgoirthm == MALLOC_FAILED) return -1;

        if (i > 1000000) acuarteAlgorithm = findClusterExtermeViaQuickSort(array, i);

        else acuarteAlgorithm = findClusterExtermeViaSorting(array, i);


        if (yourAlgoirthm != acuarteAlgorithm)
        {

            return 1;
        }
    }

    return 0;
}











