#include<stdio.h>
void pick(int* items, int numItems, int* bucket, int bucketSize, int k) //왜 bucket 포인터를 쓸까?
{ 
	int i, lastIndex;

	if( k == 0 ) {
		for( i = 0; i < bucketSize; i++ )
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	for( i = 0; i < numItems; i++ ) {
		bucket[lastIndex + 1] = items[i];
		pick(items, 4, bucket, bucketSize, k - 1);
	}
}

int main(void)
{
	int items[] = {0, 1, 2, 3};
	int bucket[3];

	pick(items, 4, bucket, 3, 3);

	return 0;
}