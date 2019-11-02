//순열(Permutation)
#include<stdio.h>
void pick(int n, int* bucket, int bucketSize, int k) {

	int i, lastIndex, smallest, item;
	
	if(k == 0) {
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k- 1;

	smallest = 0;

	for(item = smallest; item < n; item++) {
		int j = 0;
		int flag = 0;
		
		for(j = 0; j <= lastIndex; j++) //순열에서는 안뽑힌 아이템 중에서 뽑는다.
			if(bucket[j] == item)
				flag = 1; // 이미 뽑혔는지 검사

		if(flag == 1)
			continue;

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