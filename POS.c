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
	printf("총 금액은 %d\n", total);
	
	while(1)
	{
		printf("지불액 입력:");
		scanf("%d", &payment);
		change = payment - total;
		if ( change < 0 )
		{
			printf("잘못된 입력입니다\n");
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
		printf("%d. %s :\t%d원\n", i + 1, item[i].name, item[i].price );
	}
	printf("--------------------------\n");
}

int buy_item( struct itemInfo item[], struct buyItem buyIt[] )
{
	int total = 0;
	int i;
	char choice;

	printf("(예: 콜라 3개를 사려면 1 3을 입력)\n");
	for( i = 0; i < 30; i++)
	{
		printf("물건의 번호와 수량을 입력(-1 exit): ");
		scanf("%d %d", &buyIt[i].num, &buyIt[i].quantity);
		if ( buyIt[i].num < 1 || buyIt[i].num > 3 )
			{
				printf("잘못된 입력입니다\n");
				continue;
			}
		printf("계속하시겠습니까?(y/n) ");
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
	printf("-----------------거스름돈----------------\n");
	for (i = 0; i < n; i++) {
		if ((changeNum = total / changeType[i]) != 0) {
			printf("%d원:\t %d개\n", changeType[i], changeNum);
			total = total % changeType[i];
		}
	}
}

void print_receipt( struct itemInfo item[], struct buyItem buyIt[], int total, int change, int payment )
{
	int i;

	printf("-------------------------------------\n");
	printf("메뉴명 \t\t 단가\t 수량\t 금액");
	printf("-------------------------------------\n");
	for( i = 0; i < 30; i++)
		printf("%c \t\t %d\t %d\t %d", item[buyIt[i].num - 1].name, buyIt[i].quantity, item[buyIt[i].num - 1].price);
	printf("-------------------------------------\n");
	printf("\t\t\t 합계금액\t %d원\n", total);
	printf("-------------------------------------\n");
	printf("\t\t\t 받을금액\t %d원\n", total);
	printf("\t\t\t 받은금액\t %d원\n", payment);
	printf("-------------------------------------\n");
	printf("\t\t\t 거스름돈\t %d원\n", change);
}