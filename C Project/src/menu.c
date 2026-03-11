#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "file_handler.h"

void handle_new_order() {
    Order newOrder;
    int restChoice, pizzaChoice, burgerMenuChoice, sauceChoice;

    newOrder.total_price = 0.0;
    memset(newOrder.item_name, 0, sizeof(newOrder.item_name));

    printf("\n--- SELECT A RESTAURANT ---\n");
    printf("1. Pizza Place\n");
    printf("2. Burger4u\n");
    printf("Choice: ");
    scanf("%d", &restChoice);

    if (restChoice == 1) {
        strcpy(newOrder.restaurant, "Pizza Place");
        newOrder.total_price = 30.0; // pret start pizza

        printf("\n[ Pizza Customization ]\n");
        printf("1. Extra Cheese (+9 lei)\n");
        printf("2. Pepperoni (+12 lei)\n");
        printf("3. Classic (No extras)\n");
        printf("Choice: ");
        scanf("%d", &pizzaChoice);

        if (pizzaChoice == 1) {
            newOrder.total_price += 9.0;
            strcpy(newOrder.item_name, "Cheese Pizza");
        } else if (pizzaChoice == 2) {
            newOrder.total_price += 12.0;
            strcpy(newOrder.item_name, "Pepperoni Pizza");
        } else {
            strcpy(newOrder.item_name, "Classic Pizza");
        }
    }
    else if (restChoice == 2) {
        strcpy(newOrder.restaurant, "Burger4u");
        newOrder.total_price = 35.0; // pret start burger

        printf("\n[ Burger Options ]\n");
        printf("Would you like to make it a Menu? (Fries + Soda for +15 lei)\n");
        printf("1. Yes, make it a Menu\n");
        printf("2. No, just the Burger\n");
        printf("Choice: ");
        scanf("%d", &burgerMenuChoice);

        if (burgerMenuChoice == 1) {
            newOrder.total_price += 15.0;
            strcpy(newOrder.item_name, "Burger Menu");
        } else {
            strcpy(newOrder.item_name, "Solo Burger");
        }
    } else {
        printf("Invalid restaurant choice. Returning to main menu.\n");
        return;
    }

    printf("\n[ Add Sauces ]\n");
    printf("Would you like sauce? (+9 lei)\n");
    printf("1. Garlic Sauce\n");
    printf("2. Sweet Sauce\n");
    printf("3. Spicy Sauce\n");
    printf("4. No\n");
    printf("Choice: ");
    scanf("%d", &sauceChoice);

    if (sauceChoice == 1) {
        newOrder.total_price += 9.0;
        strcat(newOrder.item_name, " + Garlic Sauce");
    } else if (sauceChoice == 2) {
        newOrder.total_price += 9.0;
        strcat(newOrder.item_name, " + Sweet Sauce");
    } else if (sauceChoice == 3)
    {
        newOrder.total_price += 9.0;
        strcat(newOrder.item_name, " + Spicy Sauce");
    }

    printf("\nEnter Delivery Location: ");
    while (getchar() != '\n');
    scanf("%[^\n]s", newOrder.location);
    save_order_to_file(newOrder);

    printf("\n==============================\n");
    printf(" ORDER PLACED SUCCESSFULLY!\n");
    printf(" Total Price: %.2f lei\n", newOrder.total_price);
}
void wait_for_user() {
    printf("\nPress [Enter] to return to the Main Menu...");
    while (getchar() != '\n'); // Clear buffer
    getchar();                 // Wait for the actual Enter key
}