#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection_sort(struct Student *s, int n);

struct Student {
	int id;
	int korean, english, math;
};

int main()
{
	int n, i;
	struct Student *s;

	printf("�л� ���� �Է��ϼ���: ");
	scanf("%d", &n);

	s = (struct Student *) calloc(n, sizeof(struct Student));

	srand(time(NULL));
	for(i = 0; i < n; i++)
	{
		s[i].id = i + 1;
		s[i].korean = rand() % 101;
		s[i].english = rand() % 101;
		s[i].math = rand() % 101;
	}

	for(i = 0; i < n; i++)
	{
		printf("�й� : %d\t", s[i].id);
		printf("���� : %d\t", s[i].english);
		printf("���� : %d\t", s[i].math);
		printf("���� : %d\t\n", s[i].korean);
	}
	printf("\n");

	selection_sort(s, n);

	for(i = 0; i < n; i++)
	{
		printf("�й� : %d\t", s[i].id);
		printf("���� : %d\t", s[i].english);
		printf("���� : %d\t", s[i].math);
		printf("���� : %d\t\n", s[i].korean);
	}

	free(s);
}

void selection_sort(struct Student *s, int n)
{
	int i, j;
	struct Student stmp;

	for(i = 0; i < n-1; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(s[i].korean < s[j].korean)
			{
				stmp = s[i];
				s[i] = s[j];
				s[j] = stmp;
			}
		}
	}
}