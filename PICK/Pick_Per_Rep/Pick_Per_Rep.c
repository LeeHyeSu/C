//중복순열(Permutation with Repetition)
#include<stdio.h>
void pick(int n, int* bucket, int bucketSize, int k) {
	
	int i, lastIndex, smallest, item;

	if(k == 0) {
		for(i = 0; i < bucketSize; i++)
			printf("%d ", bucket[i]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index

	smallest = 0; //중복순열은 매번 전체 아이템 중에서 뽑는다.

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