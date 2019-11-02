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
	printf("INPUT : %s\n", arr);

	for(j = 0; arr[j] != '\0'; i++, j++)
		key[i] = arr[j];
	key[i] = '\0';
	printf("INPUT : %s\n", key);

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
	char key[30], cipher[30] = "", clear[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char input[30] = "NEVER TRUST BRUTUS";
	int key_num;
	int i, j, k;

	printf("ALPHA_STRING KEY : ");
	scanf("%s", key);
	printf("NUMERIC KEY : ");
	scanf("%d", &key_num);
	printf("INPUT : %s\n", input); 

	for(i = 0; key[i] != '\0'; i++) 
	{
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
	}
	printf("INPUT : %s\n", key);

	encry(key, key_num, cipher, clear);

	printf("INPUT : %s\n", cipher);
}