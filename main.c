#include <stdio.h>
#include <conio.h>
#include <string.h>
struct customer
{
    int account_no;
    char name[80];
    int balance;
};

void accept(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);

int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;
    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {   printf("Press 1 to display all records.\n");
        printf("Press 2 to withdraw money.\n");
        printf("Press 3 to deposit money.\n");
        printf("Press 4 to search a customer.\n");
        printf("Press 0 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(data, n);
                break;
            case 4:
                printf("Enter account number to search : ");
                scanf("%d", &account_no);
                index = search(data,n,account_no);
                if (index==- 1)
                    printf("Record not found : ");
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            case 2:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data,n,account_no,amount);
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);
        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        //fflush(stdin);
        printf("Enter name : ");
        scanf("%s",list[i].name);
        printf("Enter amount: ");
        scanf("%d",&list[i].balance);
    } 
}

void display(struct customer list[80], int s)
{
    int i;

    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t\t%s\t\t%d\n", list[i].account_no, list[i].name,
            list[i].balance);
    } 
}

int search(struct customer list[80], int s, int number)
{
    int i;
    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
            return i;
    }
    return  - 1;
}

void deposit(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
        printf("Record not found");
    else
        list[i].balance += amt;
}

void withdraw(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
        printf("Record not found\n");
    else if(list[i].balance < amt)
        printf("Insufficient balance\n");
    else
        list[i].balance -= amt;
}