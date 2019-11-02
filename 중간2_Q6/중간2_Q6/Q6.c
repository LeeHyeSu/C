#include<stdio.h>
void pick(int *items, int numItems, int *bucket, int bucketSize, int k, int A)
{
	int i, lastIndex;

	if(k == 0)
	{
		int total = 0;
		for(i = 0;i < bucketSize; i++)
			total += bucket[i];
		if(total == A)
		{
			for(i = 0; i < bucketSize; i++)
				printf("%d ", bucket[i]);
			printf("\n");
		}
		return;
	}

	lastIndex = bucketSize - k - 1;

	for(i = 0; i < numItems; i++)
	{
		if(lastIndex != -1 && bucket[lastIndex] >= items[i]) continue;
		bucket[lastIndex+1] = items[i];
		pick(items, numItems, bucket, bucketSize, k-1, A);
	}
}

int main(void)
{
	int items[7] = {10, 20, 30, 40, 50, 60, 70};
	int A;
	int bucket[3];

	scanf("%d", &A);

	pick(items, 7, bucket, 3, 3, A);
	return;
}