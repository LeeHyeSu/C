#include<stdio.h>
//Pick�Լ� : n���� ���ҿ��� m���� �̾ƾ� �ϴµ� 
//�̹� picked��ŭ ����� ������ toPick��ŭ ���� �Լ�
void pick(int n, int m, int picked[], int toPick)
{
	int smallest, lastIndex, i;

	if(toPick == 0) //�� ������� picked�� ������ ���
	{
		for(i = 0; i < m; i++)
			printf("%d", picked[i]);
		printf("\n");
		return;
	}

	lastIndex = m - toPick - 1; //picked array���� �������� ä���� element�� index

	if(m == toPick) //ó�� ���� �Ÿ�
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1; //���������� �� ���� ū ��

	for(i = smallest; i < n; i++) //���� ū ������ n-1����
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