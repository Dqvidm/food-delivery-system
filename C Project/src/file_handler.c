#include <stdio.h>
#include "file_handler.h"

void save_order_to_file(Order o) {
    FILE *file = fopen("orders.dat", "ab"); // Open for Append in Binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&o, sizeof(Order), 1, file);
    fclose(file);
}

void display_history() {
    FILE *file = fopen("orders.dat", "rb"); // Open for Reading in Binary mode
    if (file == NULL) {
        printf("\n--- No Order History Found ---\n");
        return;
    }

    Order temp;
    printf("\n--- ORDER HISTORY ---\n");
    printf("%-15s | %-15s | %-10s | %-15s\n", "Restaurant", "Item", "Price", "Location");
    printf("------------------------------------------------------------\n");

    while (fread(&temp, sizeof(Order), 1, file)) {
        printf("%-15s | %-15s | lei%-9.2f | %-15s\n",
               temp.restaurant, temp.item_name, temp.total_price, temp.location);
    }
    fclose(file);
}
float get_grand_total() {
    FILE *file = fopen("orders.dat", "rb");
    if (file == NULL) {
        return 0.0f; // Return 0 if no file exists yet
    }

    Order temp;
    float grand_total = 0.0f;

    // Loop through the binary file until the end
    while (fread(&temp, sizeof(Order), 1, file)) {
        grand_total += temp.total_price;
    }

    fclose(file);
    return grand_total;
}