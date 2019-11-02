#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quickSort(int *arr, int p, int r);
int partition(int *arr, int p, int r);

int main()
{
	int n, i;
	int *arr;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);

	arr = (int *) calloc(n, sizeof(int));

	for(i = 0; i < n; i++)
		arr[i] = rand() % 100;

	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	quickSort(arr, 0, n-1);

	printf("Quick Sort:\n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);

	return 0;
}

void quickSort(int *arr, int p, int r)
{
	if(p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}

int partition(int *arr, int p, int r)
{
	int i, j;
	int pivot = arr[r];
	
	i = p - 1;
	for(j = p; j < r; j++)
	{
		if(arr[j] < pivot)
		{
			int t;
			i++;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	i++;
	arr[r] = arr[i];
	arr[i] = pivot;
	return i;
}