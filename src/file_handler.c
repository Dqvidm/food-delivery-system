#include <stdio.h>
#include <string.h>
#include "../include/file_handler.h"

#define DATA_FILE "orders.txt"

void save_order_to_file(Order o) {
    FILE *file = fopen(DATA_FILE, "a");
    if (file == NULL) {
        printf("%s[ERROR] File access failed.%s\n", CLR_RED, CLR_RESET);
        return;
    }
    fprintf(file, "%s|%s|%.2f|%s\n", o.restaurant, o.item_name, o.total_price, o.location);
    fclose(file);
    printf("\n%s[STATUS] Order saved successfully.%s\n", CLR_GREEN, CLR_RESET);
}

void display_history() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        printf("\n%s--- No Order History Found ---%s\n", CLR_YELLOW, CLR_RESET);
        return;
    }
    Order temp;
    printf("\n--- ORDER HISTORY ---\n");
    while (fscanf(file, " %[^|]|%[^|]|%f|%[^\n]\n",
           temp.restaurant, temp.item_name, &temp.total_price, temp.location) == 4) {
        printf("Rest: %s%-12s%s | Item: %s%-20s%s | Price: %s%.2f lei%s | Loc: %s%s%s\n",
               CLR_CYAN, temp.restaurant, CLR_RESET,
               CLR_MAGENTA, temp.item_name, CLR_RESET,
               CLR_YELLOW, temp.total_price, CLR_RESET,
               CLR_GREEN, temp.location, CLR_RESET);
           }
    fclose(file);
}

float get_grand_total() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) return 0.0f;
    Order temp;
    float total = 0.0f;
    while (fscanf(file, " %[^|]|%[^|]|%f|%[^\n]\n",
           temp.restaurant, temp.item_name, &temp.total_price, temp.location) == 4) {
        total += temp.total_price;
           }
    fclose(file);
    return total;
}

void update_order_list(Order orders[], int count) {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) return;
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s|%.2f|%s\n",
                orders[i].restaurant, orders[i].item_name,
                orders[i].total_price, orders[i].location);
    }
    fclose(file);
}