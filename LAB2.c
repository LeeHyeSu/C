#include<stdio.h>
void pick(int* items, int numItems, int* bucket, int bucketSize, int k)
{
	int i, lastIndex;

	if(k == 0)
	{
		int total = 0;
		for(i = 0; i < bucketSize; i++)
		{
			if( bucket[i] == 1 ) {
				printf("+%d", i + 1);
				total += i + 1;
			}
			else {
				printf("-%d", i + 1);
				total -= i + 1;
			}
		}
		printf(" = %d\n", total);
		return;
	}

	lastIndex = bucketSize - k - 1;

	for(i = 0; i < numItems; i++) {
		bucket[lastIndex + 1] = items[i];
		pick(items, numItems, bucket, bucketSize, k - 1);
	}
}

int main(void)
{
	//int n = 5;
	int items[] = {1, -1};
	int bucket[4];

	pick(items, 2, bucket, 4, 4);

	return 0;
}