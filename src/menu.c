#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/file_handler.h"

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void handle_new_order() {
    Order newOrder;
    int r_choice = 0, f_choice = 0, s_choice = 0;

    while (r_choice < 1 || r_choice > 2) {
        printf("\nSelect Restaurant:\n [%s1%s] %sPizza Place%s\n [%s2%s] %sBurger4u%s\nChoice (1-2): ",
               CLR_CYAN, CLR_RESET, CLR_CYAN, CLR_RESET, CLR_CYAN, CLR_RESET, CLR_CYAN, CLR_RESET);
        if (scanf("%d", &r_choice) != 1) {
            printf("%s[Error] Input a number (1-2).%s\n", CLR_RED, CLR_RESET);
            flush_input();
        }
    }

    if (r_choice == 1) {
        strcpy(newOrder.restaurant, "Pizza Place");
        while (f_choice < 1 || f_choice > 2) {
            printf("\n%sPizza Menu%s:\n [%s1%s] %sMargherita%s (%s30.00%s)\n [%s2%s] %sPepperoni%s (%s35.00%s)\nChoice: ",
                   CLR_CYAN, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_YELLOW, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_YELLOW, CLR_RESET);
            if (scanf("%d", &f_choice) != 1) { flush_input(); }
        }
        newOrder.total_price = (f_choice == 1) ? 30.0 : 35.0;
        strcpy(newOrder.item_name, (f_choice == 1) ? "Margherita" : "Pepperoni");
    } else {
        strcpy(newOrder.restaurant, "Burger4u");
        while (f_choice < 1 || f_choice > 2) {
            printf("\n%sBurger Menu%s:\n [%s1%s] %sClassic Burger%s (%s25.00%s)\n [%s2%s] %sCheese Burger%s (%s28.00%s)\nChoice: ",
                   CLR_CYAN, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_YELLOW, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_MAGENTA, CLR_RESET, CLR_YELLOW, CLR_RESET);
            if (scanf("%d", &f_choice) != 1) { flush_input(); }
        }
        newOrder.total_price = (f_choice == 1) ? 25.0 : 28.0;
        strcpy(newOrder.item_name, (f_choice == 1) ? "Classic Burger" : "Cheese Burger");
    }

    while (s_choice < 1 || s_choice > 4) {
        printf("\nExtra Sauce (%s+9.00 lei%s):\n [%s1%s] Garlic\n [%s2%s] Sweet\n [%s3%s] Spicy\n [%s4%s] None\nChoice (1-4): ",
               CLR_YELLOW, CLR_RESET, CLR_CYAN, CLR_RESET, CLR_CYAN, CLR_RESET, CLR_CYAN, CLR_RESET, CLR_CYAN, CLR_RESET);
        if (scanf("%d", &s_choice) != 1) { flush_input(); }
    }

    if (s_choice >= 1 && s_choice <= 3) {
        newOrder.total_price += 9.0;
        char *names[] = {"Garlic", "Sweet", "Spicy"};
        strcat(newOrder.item_name, " + ");
        strcat(newOrder.item_name, names[s_choice - 1]);
    }

    printf("\nDelivery Address %s(Format: Street, Number)%s: ", CLR_GREEN, CLR_RESET);
    flush_input();
    scanf("%49[^\n]", newOrder.location);

    save_order_to_file(newOrder);
}

void handle_modify_order() {
    Order list[100];
    int count = 0;
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL) return;
    while (count < 100 && fscanf(file, " %[^|]|%[^|]|%f|%[^\n]\n", list[count].restaurant, list[count].item_name, &list[count].total_price, list[count].location) == 4) {
        printf("[%s%d%s] %s%s%s | %s%s%s | %s%s%s\n",
               CLR_CYAN, count + 1, CLR_RESET,
               CLR_CYAN, list[count].restaurant, CLR_RESET,
               CLR_MAGENTA, list[count].item_name, CLR_RESET,
               CLR_GREEN, list[count].location, CLR_RESET);
        count++;
    }
    fclose(file);
    if (count == 0) return;
    int index = 0;
    while (index < 1 || index > count) {
        printf("\nIndex to modify %s(1-%d)%s: ", CLR_CYAN, count, CLR_RESET);
        if (scanf("%d", &index) != 1) { flush_input(); }
    }
    printf("New Location %s(Street, Number)%s: ", CLR_GREEN, CLR_RESET);
    flush_input();
    scanf("%49[^\n]", list[index - 1].location);
    printf("New Price %s(0.00)%s: ", CLR_YELLOW, CLR_RESET);
    if (scanf("%f", &list[index - 1].total_price) != 1) { flush_input(); }
    update_order_list(list, count);
    printf("%s[Success] Entry modified.%s\n", CLR_GREEN, CLR_RESET);
}

void handle_delete_order() {
    Order list[100];
    int count = 0;
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL) return;
    while (count < 100 && fscanf(file, " %[^|]|%[^|]|%f|%[^\n]\n", list[count].restaurant, list[count].item_name, &list[count].total_price, list[count].location) == 4) {
        printf("[%s%d%s] %s%s%s | %s%s%s\n",
               CLR_RED, count + 1, CLR_RESET,
               CLR_CYAN, list[count].restaurant, CLR_RESET,
               CLR_MAGENTA, list[count].item_name, CLR_RESET);
        count++;
    }
    fclose(file);
    if (count == 0) return;
    int index = 0;
    while (index < 1 || index > count) {
        printf("\nID to delete %s(1-%d)%s: ", CLR_RED, count, CLR_RESET);
        if (scanf("%d", &index) != 1) { flush_input(); }
    }
    for (int i = index - 1; i < count - 1; i++) { list[i] = list[i + 1]; }
    update_order_list(list, count - 1);
    printf("%s[Status] Order #%d removed.%s\n", CLR_RED, index, CLR_RESET);
}

void handle_search_order() {
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL) return;
    int type = 0;
    char keyword[MAX_STR];
    Order temp;
    while (type < 1 || type > 2) {
        printf("\nSearch by:\n [%s1%s] Restaurant\n [%s2%s] Location\nChoice: ",
               CLR_CYAN, CLR_RESET, CLR_GREEN, CLR_RESET);
        if (scanf("%d", &type) != 1) { flush_input(); }
    }
    printf("Keyword %s(Case Sensitive)%s: ", CLR_MAGENTA, CLR_RESET);
    flush_input();
    scanf("%49[^\n]", keyword);
    while (fscanf(file, " %[^|]|%[^|]|%f|%[^\n]\n", temp.restaurant, temp.item_name, &temp.total_price, temp.location) == 4) {
        char *field = (type == 1) ? temp.restaurant : temp.location;
        if (strstr(field, keyword)) {
            printf("Found: %s%s%s | %s%s%s | %s%.2f lei%s | %s%s%s\n",
                   CLR_CYAN, temp.restaurant, CLR_RESET,
                   CLR_MAGENTA, temp.item_name, CLR_RESET,
                   CLR_YELLOW, temp.total_price, CLR_RESET,
                   CLR_GREEN, temp.location, CLR_RESET);
        }
    }
    fclose(file);
}