#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion_sort(int *arr, int n)
{
	int i, j, k, tmp;

	for(i = 1; i < n; i++)
	{
		tmp = arr[i];

		for(j = 0; j < i; j++)
			if(arr[j] > arr[i])
				break;

		for(k = i; k > j; k--)
			arr[k] = arr[k-1];

		arr[j] = tmp;
	}
}

int main()
{
	int n, i;
	int *arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);

	arr = (int *) malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		arr[i] = rand() % 100;

	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	insertion_sort(arr, n);

	printf("Insertion Sort:\n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);

	return 0;
}