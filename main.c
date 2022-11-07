#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inventory struct
struct Product{
char name[50];
float price;
int quantity;
int serialNum;
};
struct Product products[16];

//Globally declared variables
int i;
int totalSales;
char new_itemName[20];
int new_quantity;
int new_price;

//Functions in the programme
void viewInventory();
void addItem();
void updateInventory();
void sellItem();
void dailySales();



int main()
{
strcpy(products[0].name ,"Soaps");
strcpy(products[1].name ,"Plates");
strcpy(products[2].name ,"Spoons");
strcpy(products[3].name ,"Detergents");
strcpy(products[4].name ,"Tissues");
strcpy(products[5].name ,"Peak Milk");
strcpy(products[6].name ,"Body Spray");
strcpy(products[7].name ,"Biscuits");
strcpy(products[8].name ,"Exercise Books");
strcpy(products[9].name ,"Ceres drink");
strcpy(products[10].name ,"Cups");
strcpy(products[11].name ,"Buckets");
strcpy(products[12].name ,"Chocolates");
strcpy(products[13].name ,"Scissors");
strcpy(products[14].name ,"Pepsodent");
strcpy(products[15].name, new_itemName);

products[0].price = 6.00;
products[1].price = 15.00;
products[2].price = 5.00;
products[3].price = 10.00;
products[4].price = 8.00;
products[5].price = 50.00;
products[6].price = 85.00;
products[7].price = 30.00;
products[8].price = 10.00;
products[9].price = 15.00;
products[10].price = 7.00;
products[11].price = 20.00;
products[12].price = 25.00;
products[13].price = 15.00;
products[14].price = 8.00;
products[15].price = new_price;

products[0].quantity=90;
products[1].quantity=100;
products[2].quantity=110;
products[3].quantity=105;
products[4].quantity=85;
products[5].quantity=75;
products[6].quantity=95;
products[7].quantity=80;
products[8].quantity=105;
products[9].quantity=60;
products[10].quantity=120;
products[11].quantity=77;
products[12].quantity=105;
products[13].quantity=99;
products[14].quantity=100;
products[15].quantity  = new_quantity;


    //Cashier Login management
    char userName[30];
    int password;
    int tries = 0;
    int attempts = 4;
    printf("WELCOME TO NIPA NNY3 ENTERPRISES SUPERMARKET.\n");
    printf("\nCashier Login. Enter Username:");
    scanf("%s", userName);

    passRetry:
    printf("\nEnter Password:");
    scanf("%d", &password);

    if(password == 1111)
    {
        printf("Welcome %s\n", userName);
        goto MENU;
    }
    else
    {
        tries++;
        attempts--;
        if (tries<4)
        {
             printf("Wrong Password. Please try again(%d more tries).\n", attempts);
             goto passRetry;
        }

        else
        {
            printf("FORGOT PASSWORD? LOGGING YOU OUT\n");
            goto END;

        }

    }


    //Main menu with switch cases calling the functions
    MENU:
    printf("\nSELECTION MENU. \n1. View Inventory List \n2. Sell Item \n3. Add Item to Inventory \n4. Update Inventory \n5. Calculate Daily Sales \n6. Exit Menu \n\nEnter an option:");
    int menuEntry;
    scanf("%d", &menuEntry);

    switch(menuEntry)
    {
                //The for loop generates a product serial number
        case 1: for (int i=0; i<15; ++i){
                products[i].serialNum =123*(i+1);
                viewInventory(products[i]);
                }
                goto MENU;
                break;
        case 2: sellItem();
                goto MENU;
                break;
        case 3: addItem();
                goto MENU;
                break;
        case 4: updateInventory();
                goto MENU;
                break;
        case 5: dailySales();
                goto MENU;
                break;
        case 6: printf("Good Bye %s.\n",userName);
                goto END;
        default: printf("WRONG ENTRY. TRY AGAIN!");
                 goto MENU;
    }

    END:
    return 0;
}


//Prints out all available items in the inventory
void viewInventory(struct Product prod)
{
    printf("\nName: %s \tPrice(GHS):%.2f\nQuantity:%d\tSerial Number:%d\t\n",prod.name,prod.price,prod.quantity,prod.serialNum);

}


//Sells items from the inventory, reducing their available quantity
void sellItem()
{

    for (int i=0; i<16; ++i){
    products[i].serialNum =123*(i+1);
    }

    int order;
do{
    int i;
    printf("\nEnter Product Index Number:");
    scanf(" %d", &i);
    viewInventory(products[i]);
    printf("Enter Quantity:");
    int quant;
    scanf(" %d", &quant);
    products[i].quantity=products[i].quantity-quant;
    totalSales=(products[i].price * quant)+totalSales;
    printf("Add more items?(1-Yes\n2-No ):");
    int option;
    scanf("%d", &option);
    if(option==1)
    {
        order++;
    }
    else if(option == 2)
    {
        order=0;
    }
    }while(order>0);
    printf("Total Sales: GHc%d.00\n",totalSales);

}

//For adding new items to the inventory
void addItem()
{
    printf("Adding Item To Inventory\n");

    printf("\nItem name:");
    scanf("%s", new_itemName);
    strcpy(products[15].name, new_itemName);

    printf("\nItem Quantity:");
    scanf("%d", &new_quantity);

    printf("\nItem Price:");
    scanf("%d", &new_price);

     printf("%s Added To Inventory\n", new_itemName);

}

//For updating the quantity of items in the inventory
void updateInventory()
{
    printf("\nSelect Item Index Number to update:");
    int x;
    scanf("%d", &x);
    int new_quantity;
    printf("\nEnter New Quantity:");
    scanf("%d", &new_quantity);
    products[x].quantity=products[x].quantity+new_quantity;
}

//Calculates the total daily sales
void dailySales()
{
    printf("Daily total sales is GHc%d.00", totalSales);
}
