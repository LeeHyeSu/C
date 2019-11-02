//중복조합(Combination with Repetition)
#include<stdio.h>
void pick(int n, int* bucket, int bucketSize, int k) {
	
	int i, lastIndex, smallest, item;
	
	if(k == 0) {
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if(bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; // 중복조합은 가장 마지막에 뽑힌 수보다 크거나 같은 것을 뽑는다.

	for(item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}

int main()
{
	int n = 8;
	int bucket[4];

	pick(n, bucket, 4, 4);
}