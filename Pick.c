#include<stdio.h>
//Pick함수 : n개의 원소에서 m개를 뽑아야 하는데 
//이미 picked만큼 골랐고 앞으로 toPick만큼 고르는 함수
void pick(int n, int m, int picked[], int toPick)
{
	int smallest, lastIndex, i;

	if(toPick == 0) //다 골랐으면 picked의 내용을 출력
	{
		for(i = 0; i < m; i++)
			printf("%d", picked[i]);
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1; //picked array에서 마지막에 채워진 element의 index

	if(m == toPick) //처음 고르는 거면
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1; //마지막으로 고른 다음 큰 수

	for(i = smallest; i < n; i++) //다음 큰 수부터 n-1까지
	{
		picked[lastIndex + 1] = i;
		pick(n, m, picked, toPick - 1);
	}
}

int main(void)
{
	int picked[4];
	pick(7, 4, picked, 4);
}