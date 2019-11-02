#include<stdio.h>

void encry(char *key, int num, char *cipher, char *clear)
{
	int i = 0, j = 0, k = 0;
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(i = 0; key[i] != '\0'; i++)
		for(j = 0; arr[j] != '\0'; j++)
		{
			if(key[i] == arr[j])
			{
				for(k = j; arr[k] != '\0'; k++)
					arr[k] = arr[k+1];
				arr[k] = '\0';
			}
		}

	for(j = 0; arr[j] != '\0'; i++, j++)
		key[i] = arr[j];
	key[i] = '\0';

	for(i = num, j = 0; key[j] != '\0'; i++, j++)
	{
		if(clear[i] == '\0')
		{
			cipher[i] = '\0';
			i = 0;
		}
		cipher[i] = key[j];
	}
}

int main()
{
	char key[30], cipher[30] = "", clear[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char input[30], output[30];
	int key_num, state;
	char ch;
	FILE *fp1, *fp2;
	int i, j, k;

	printf("ALPHA_STRING KEY : ");
	scanf("%s", key);
	printf("NUMERIC KEY : ");
	scanf("%d", &key_num);
	printf("INPUT FILE : ");
	scanf("%s", input);
	printf("OUTPUT FILE : ");
	scanf("%s", output);

	for(i = 0; key[i] != '\0'; i++)
		for(j = 0; key[j] != '\0'; j++)
		{
			if(i == j) continue;
			if(key[i] == key[j])
			{
				for(k = j; key[k] != '\0'; k++)
					key[k] = key[k+1];
				key[k] = '\0';
			}
		}

	encry(key, key_num, cipher, clear);

	fp1 = fopen(input, "r");
	fp2 = fopen(output, "w");
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	ch = fgetc(fp1);
	while(!feof(fp1))
	{
		int c = 0;
		for(i = 0; clear[i] != '\0'; i++)
		{
			if(ch == clear[i])
			{
				c = 1;
				break;
			}
		}
		
		if(c != 0)
			fputc(cipher[i], fp2);
		else
			fputc(ch, fp2);
		ch = fgetc(fp1);
	}

	state = fclose(fp1);
	if(state != 0)
	{
		printf("flie close error!\n");
		return 1;
	}

	state = fclose(fp2);
	if(state != 0)
	{
		printf("file close error!\n");
		return 1;
	}
}