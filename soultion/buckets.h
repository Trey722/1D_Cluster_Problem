typedef struct buckets
{
    float min;
    float max;
    int size;
}buckets;

void insertBucket(float value, buckets * bucket_X);

buckets ** createArrayBuckets(int size);

float findWidestSeperatedBuckets(buckets ** ArrayOfBuckets, int size, float min, float max);


int* furthestBuckets(buckets** arrayBuckets, int size);

float findBiggestExterme(buckets ** arrayBuckets, int size, float min, float max);
