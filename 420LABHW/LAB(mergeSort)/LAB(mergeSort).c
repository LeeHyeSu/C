#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void mergeSort(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);

int main()
{
	int *arr;
	int n, i;
	srand(time(NULL));

	printf("Enter a number: ");
	scanf("%d", &n);

	arr = (int *) calloc(n, sizeof(int));

	for(i = 0; i < n; i++)
		arr[i] = rand() % 100;

	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	mergeSort(arr, 0, n-1);

	printf("Merge Sort:\n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);

	return 0;
}

void mergeSort(int *arr, int p, int r)
{
	if(p < r)
	{
		int q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

void merge(int *arr, int p, int q, int r)
{
	int i, j, k;
	int *temp;

	i = p;
	j = q + 1;
	k = 0;

	temp = (int *) malloc(sizeof(int) * (r-p+1));

	while(1) 
	{
		if( arr[i] < arr[j] )
			temp[k] = arr[i++];
		else
			temp[k] = arr[j++];
		k++;
		if(i == q + 1 || j == r + 1)
			break;
	}

	if( i == q + 1 )
		for(; j <= r; j++, k++)
			temp[k] = arr[j];
	else 
		for(; i <= q; i++, k++)
			temp[k] = arr[i];

	for(i = p, k = 0; i <= r; i++)
		arr[i] = temp[k++];
	free(temp);
}