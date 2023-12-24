This is an implemntation of a worst case O(N) soultion to the 1D Cluster Problem. 


# What is the 1D Cluster Problem?


Lets say you have an unsorted array. 


[ 5, 3, 2, 7, 20, 15, 18]


The 1D cluster problem would be finding the two pairs that would be ajacent in sorted order that are maximally farthest apart.


# How to use my implmentation 



![carbon(1)](https://github.com/Trey722/Cluster_Problem/assets/141661331/23006ec0-0748-4b4d-b871-0d8b4effb2e2)

This is the main function you will call. This function takes an array of floats and a size as an input, and it will return the lower number in the pair that will maxmise the distance between two clusters. 

## Error handeling 

![carbon(1)](https://github.com/Trey722/Cluster_Problem/assets/141661331/6dac4d3b-e6a6-4ffc-8339-76031840194a)


Due to the fact that we are dealing with changing numbers that could be both positve or negative error handling is done by enumartion. If the function recives a NULL_POINTER. You can check the output by writing the following C code.



![carbon](https://github.com/Trey722/Cluster_Problem/assets/141661331/67fce7e7-ed45-48eb-8008-cabecfb41b03)


