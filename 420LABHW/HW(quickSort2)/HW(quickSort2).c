#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	int id;
	int korean, english, math;
} Student;

void quickSort(Student *s, int p, int r, int c);
int partition(Student *s, int p, int r, int c);
void swap(Student *s, int *i, int j);

void quickSort(Student *s, int p, int r, int c)
{
	if(p < r) 
	{
		int q = partition(s, p, r, c);
		quickSort(s, p, q-1, c);
		quickSort(s, q+1, r, c);
	}
}

int partition(Student *s, int p, int r, int c)
{
	int i, j;
	Student pivot = s[r];

	i = p - 1;
	for(j = p; j < r; j++)
	{
		if(c == 1) 
			if(s[j].korean > pivot.korean)
				swap(s, &i, j);
		if(c == 2)
			if(s[j].math > pivot.math)
				swap(s, &i, j);
		if(c == 3)
			if(s[j].english > pivot.english)
				swap(s, &i, j);
		if(c == 4) 
			if(s[j].id < pivot.id)
				swap(s, &i, j);
	}

	i++;
	s[r] = s[i];
	s[i] = pivot;
	return i;
}

void swap(Student *s, int *i, int j)
{
	Student t;
	(*i)++;
	t = s[*i];
	s[*i] = s[j];
	s[j] = t;
}

int main()
{
	int n, i;
	int choice;
	Student *s;
	srand(time(NULL));

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &n);

	s = (Student *) calloc(n, sizeof(Student));

	for(i = 0; i < n; i++) {
		s[i].id = i + 1;
		s[i].korean = rand() % 101;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
	}
	
	do {
		for(i = 0; i < n; i++)
			printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", s[i].id, s[i].english, s[i].math, s[i].korean);
		printf("\n");
	
		printf("정렬 기준 선택(1: 국어, 2: 수학, 3: 영어, 4:id(오름차순), 0: 끝내기) : ");
		scanf("%d", &choice);
		
		if(choice < 0 || choice > 4)
			continue;

		quickSort(s, 0, n-1, choice);
	} while(choice != 0);

	free(s);

	return 0;
}