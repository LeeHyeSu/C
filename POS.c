#include <stdio.h>
void display_menu( struct itemInfo item[], int n);
int buy_item( struct itemInfo item[], struct buyItem buyit[] );
void display_change( int total, int changeType[], int n );
void print_receipt( struct itemInfo item[], struct buyItem buyIt[], int total, int change, int payment );

struct itemInfo {
	char name[10];
	int price;
};

struct buyItem {
	int num;
	int quantity;
};

int main(void)
{
	struct buyItem buyIt[30];
	struct itemInfo item[3] = {{"Cola", 1500}, {"Cider", 2100}, {"Hamberger", 5110}};
	int changeType[5] = {1000, 500, 100, 50, 10};

	int total = 0, change, payment;

	display_menu( item, 3 );

	total = buy_item( item, buyIt );
	printf("�� �ݾ��� %d\n", total);
	
	while(1)
	{
		printf("���Ҿ� �Է�:");
		scanf("%d", &payment);
		change = payment - total;
		if ( change < 0 )
		{
			printf("�߸��� �Է��Դϴ�\n");
			continue;
		}
		else break;
	}
	display_change(change, changeType, 5);
	print_receipt(item, buyIt, total, change, payment);
}

void display_menu( struct itemInfo item[], int n)
{
	int i = 0;
	printf("--------------------------\n");
	for(i=0; i<n; i++ )
	{
		printf("%d. %s :\t%d��\n", i + 1, item[i].name, item[i].price );
	}
	printf("--------------------------\n");
}

int buy_item( struct itemInfo item[], struct buyItem buyIt[] )
{
	int total = 0;
	int i;
	char choice;

	printf("(��: �ݶ� 3���� ����� 1 3�� �Է�)\n");
	for( i = 0; i < 30; i++)
	{
		printf("������ ��ȣ�� ������ �Է�(-1 exit): ");
		scanf("%d %d", &buyIt[i].num, &buyIt[i].quantity);
		if ( buyIt[i].num < 1 || buyIt[i].num > 3 )
			{
				printf("�߸��� �Է��Դϴ�\n");
				continue;
			}
		printf("����Ͻðڽ��ϱ�?(y/n) ");
		scanf("%c", &choice);
		if ( choice == 'n' )
			break;

		total += item[(buyIt[i].num) - 1].price * (buyIt[i].quantity);
	}

	return total;
}

void display_change(int total, int changeType[], int n)
{
	int i;
	int changeNum;
	printf("-----------------�Ž�����----------------\n");
	for (i = 0; i < n; i++) {
		if ((changeNum = total / changeType[i]) != 0) {
			printf("%d��:\t %d��\n", changeType[i], changeNum);
			total = total % changeType[i];
		}
	}
}

void print_receipt( struct itemInfo item[], struct buyItem buyIt[], int total, int change, int payment )
{
	int i;

	printf("-------------------------------------\n");
	printf("�޴��� \t\t �ܰ�\t ����\t �ݾ�");
	printf("-------------------------------------\n");
	for( i = 0; i < 30; i++)
		printf("%c \t\t %d\t %d\t %d", item[buyIt[i].num - 1].name, buyIt[i].quantity, item[buyIt[i].num - 1].price);
	printf("-------------------------------------\n");
	printf("\t\t\t �հ�ݾ�\t %d��\n", total);
	printf("-------------------------------------\n");
	printf("\t\t\t �����ݾ�\t %d��\n", total);
	printf("\t\t\t �����ݾ�\t %d��\n", payment);
	printf("-------------------------------------\n");
	printf("\t\t\t �Ž�����\t %d��\n", change);
}