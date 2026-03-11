#include <stdio.h>
#include "menu.h"
#include "file_handler.h"

// Helper function to create space and wait for the user to read the screen
void pause_and_clear() {
    printf("\n-------------------------------------------");
    printf("\nPress [ENTER] to return to the main menu...");

    // These two lines clear the input buffer and wait for the user to hit Enter
    while (getchar() != '\n');
    getchar();
}

int main() {
    int choice = 0;

    while (choice != 3) {
        // --- VISUAL SPACING ---
        // This prints several newlines to separate the new menu from old text
        printf("\n\n\n\n");
        printf("==========================================\n");
        printf("       FOOD DELIVERY SYSTEM 2026          \n");
        printf("==========================================\n");
        printf(" 1. PLACE NEW ORDER\n");
        printf(" 2. VIEW ORDER HISTORY & STATS\n");
        printf(" 3. EXIT\n");
        printf("------------------------------------------\n");
        printf("Select an option: ");

        // Input validation: ensures the program doesn't crash if a user types a letter
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Invalid input. Please enter a number (1-3).\n");
            while (getchar() != '\n'); // Clear the "trash" from the buffer
            continue;
        }

        switch (choice) {
            case 1:
                // Starts the ordering process from menu.c
                handle_new_order();

                // Pauses so the user can see the "Order Successful" message
                pause_and_clear();
                break;

            case 2:
                // Prints the table of orders from file_handler.c
                display_history();

                // Calculates and displays the grand total
                float total_revenue = get_grand_total();
                printf("\n==========================================");
                printf("\n TOTAL SYSTEM REVENUE: %.2f lei", total_revenue);
                printf("\n==========================================\n");

                // Pauses so the user can read the history table
                pause_and_clear();
                break;

            case 3:
                printf("\nSaving data and shutting down... Goodbye!\n");
                break;

            default:
                printf("\n[!] Option %d is not valid. Please try again.\n", choice);
                break;
        }
    }

    return 0;
}