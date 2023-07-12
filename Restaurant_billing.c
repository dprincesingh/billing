#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct items
{

    float price;
    int quantity;
    float item_price;
    char name[50];
};
struct order
{
    char customere[100];
    struct items itm[200];
};
void space();
void generatebill_header(char date[], char name[]);
void generatebillbody(char name[], int quantity, float price);
void generatebillfooter(float subtotal);
void mainhedding();

//***************************main code**************************
int main()
{
    int select;
    int num_item;
    float subtotal;
    char savefile;
    FILE *bills;

    char date[] = {__DATE__};
    struct order ord;
    mainhedding();
    scanf("%d", &select);
    fgetc(stdin);
    printf("You have choosen : ");
    system("clear");
    switch (select)
    {
    case 1:

        printf("\tGenerate invoice:\n");
        space();
        printf("\tEnter name of Customere:-\t");
        fgets(ord.customere, 100, stdin);
        ord.customere[strlen(ord.customere) - 1] = 0;
        printf("\tEnter the number of itmes:-\t");
        scanf("%d", &num_item);
        fgetc(stdin);
        for (int i = 0; i < num_item; i++)
        {
            printf("\tEnter %d Item Name =\t\t", i + 1);
            fgets(ord.itm[i].name, 100, stdin);
            ord.itm[i].name[strlen(ord.itm[i].name) - 1] = 0;
            printf("\tEnter Quantity of %d item =\t", i + 1);
            scanf("%d", &ord.itm[i].quantity);
            fgetc(stdin);
            printf("\tEnter Price of %d item =\t\t", i + 1);
            scanf("%f", &ord.itm[i].price);
            fgetc(stdin);
            ord.itm[i].item_price = (ord.itm[i].price) * (ord.itm[i].quantity);
        }
        system("clear");
        generatebill_header(date, ord.customere);
        for (int i = 0; i < num_item; i++)
        {
            generatebillbody(ord.itm[i].name, ord.itm[i].quantity, ord.itm[i].item_price);
            subtotal = subtotal + ord.itm[i].item_price;
        }
        generatebillfooter(subtotal);

        printf("IF YOU WANT TO SAVE THE INVOICE PRESS (Y/N):-\t");

        scanf("%c", &savefile);
        if (savefile == 'y')
        {
            bills = fopen("Bills.pdf", "w");
            fwrite(&ord, sizeof(struct order), 1, bills);
            if (&fwrite != 0)
            {
                printf("INVOICE SAVED\n");
            }

            fclose(bills);
        }

        break;
    case 2:
        printf("Show all invoices:\n");
        break;
    case 3:
        printf("Search invoice:\n");
        break;
    case 4:
        printf("Search invoice:\n");
        break;

    default:
        printf("Wrong selection \nThank you \n");
        break;
    }
    return 0;
}
void space()
{
    printf("\n");
}
void mainhedding()
{
    space();
    printf("=*=*=*=* Champaran Meat House =*=*=*=*\n");
    printf("\t    Billing System\n");
    space();
    printf("\tKinldy choose your Prefrences:-\n");
    space();
    printf("\t1.Generate invoice:\n");
    printf("\t2.Show all invoice:\n");
    printf("\t3.Search   invoice:\n");
    printf("\t4.Exit:\n");
    space();
    printf("Your choice:-\t");
}
void generatebill_header(char date[], char name[])
{
    printf("=*=*=*=* Champaran Meat House =*=*=*=*\n\n");
    printf("%s\n", date);
    printf("Invoice to : %s\n", name);
    printf("========================================\n\n");
    printf("Items\t\tQty\t\tTotal\n\n");
    printf("========================================\n\n");
}
void generatebillbody(char name[], int quantity, float price)
{

    printf("%s\t\t%d\t\t%0.2f\n", name, quantity, price);
}
void generatebillfooter(float subtotal)
{
    printf("========================================\n\n");
    printf("Subtotal \t \t\t%0.2f\n\n", subtotal);
    printf("========================================\n\n");
    printf("Cgst     \t \t\t%0.2f\n", subtotal * 0.09);
    printf("Sgst     \t \t\t%0.2f\n", subtotal * 0.09);
    printf("========================================\n\n");
    printf("Subtotal \t \t\t%0.2f\n\n", (subtotal * 0.09) + (subtotal * 0.09) + (subtotal));
    printf("========================================\n\n");
}