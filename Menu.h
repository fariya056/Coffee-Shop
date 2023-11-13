#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a coffee item
struct CoffeeItem {
    char name[50];
    double price;
    int quantity;
};

// Function to display the menu
void displayMenu(struct CoffeeItem menu[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to process orders
void processOrder(struct CoffeeItem menu[], int numItems, int order[], int quantities[]) {
    int totalQuantity = 0;
    double totalCost = 0.0;

    printf("Enter the item numbers you want to order (0 to finish):\n");
    int itemNum;
    while (1) {
        scanf("%d", &itemNum);
        if (itemNum == 0) {
            break;
        }

        if (itemNum < 1 || itemNum > numItems) {
            printf("Invalid item number. Try again.\n");
            continue;
        }

        int itemIndex = itemNum - 1;
        int quantity;

        printf("Enter the quantity for %s: ", menu[itemIndex].name);
        scanf("%d", &quantity);

        if (quantity < 1) {
            printf("Invalid quantity. Try again.\n");
            continue;
        }

        menu[itemIndex].quantity -= quantity;
        order[itemIndex] += quantity;

        totalQuantity += quantity;
        totalCost += menu[itemIndex].price * quantity;
    }

    printf("Order summary:\n");
    for (int i = 0; i < numItems; i++) {
        if (order[i] > 0) {
            printf("%s - Quantity: %d\n", menu[i].name, order[i]);
        }
    }
    printf("Total Quantity: %d\n", totalQuantity);
    printf("Total Cost: $%.2lf\n", totalCost);
}

int menu() {
    struct CoffeeItem menu[] = {
        {"Espresso", 2.5, 10},
        {"Latte", 3.0, 15},
        {"Cappuccino", 3.2, 12},
        {"Mocha", 3.5, 10}
    };

    int numItems = sizeof(menu) / sizeof(menu[0]);
    int order[numItems];
    memset(order, 0, sizeof(order));

    displayMenu(menu, numItems);
    processOrder(menu, numItems, order, menu);

}