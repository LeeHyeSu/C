#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct student {
	int id;
	int korean, english, math;
};

void quickSort(struct student *s, int p, int r)
{
	if(p < r)
	{
		int q = partition(s, p, r);
		quickSort(s, p, q-1);
		quickSort(s, q+1, r);
	}
}

int partition(struct student *s, int p, int r)
{
	int i, j;
	struct student pivot = s[r];

	i = p - 1;
	for(j = p; j < r; j++)
	{
		if(s[j].korean > pivot.korean)
		{
			struct student t;
			i++;
			t = s[i];
			s[i] = s[j];
			s[j] = t;
		}
	}

	i++;
	s[r] = s[i];
	s[i] = pivot;
	return i;
}

int main()
{
	int n, i;
	struct student *s;
	srand(time(NULL));

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &n);

	s = (struct student *) calloc(n, sizeof(struct student));

	for(i = 0; i < n; i++)
	{
		s[i].id = i + 1;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
		s[i].korean = rand() % 101;
	}

	for(i = 0; i < n; i++)
		printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
	printf("\n");

	quickSort(s, 0, n-1);

	for(i = 0; i < n; i++)
		printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);

	free(s);

	return 0;
}