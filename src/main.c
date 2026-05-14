#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/file_handler.h"

void clear_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_and_clear() {
    printf("\n-------------------------------------------");
    printf("\nPress [ENTER] to return to the main menu...");
    int c; while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    clear_terminal();
}

int main() {
    int choice = 0;
    clear_terminal();

    while (choice != 6) {
        printf("       FOOD DELIVERY SYSTEM PP          \n");
        printf("==========================================\n");
        printf(" 1. PLACE NEW ORDER\n");
        printf(" 2. VIEW ORDER HISTORY & STATS\n");
        printf(" 3. MODIFY EXISTING ORDER\n");
        printf(" 4. DELETE AN ORDER\n");
        printf(" 5. SEARCH ORDERS BY FIELD\n");
        printf(" 6. EXIT\n");
        printf("------------------------------------------\n");
        printf("Select an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("\n%s[ERROR] Invalid input. Enter a number.%s\n", CLR_RED, CLR_RESET);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            pause_and_clear();
            continue;
        }

        switch (choice) {
        case 1:
            clear_terminal();
            handle_new_order();
            pause_and_clear();
            break;
        case 2:
            clear_terminal();
            display_history();
            printf("\n==========================================");
            printf("\n TOTAL REVENUE: %s%.2f lei%s", CLR_YELLOW, get_grand_total(), CLR_RESET);
            printf("\n==========================================\n");
            pause_and_clear();
            break;
        case 3:
            clear_terminal();
            handle_modify_order();
            pause_and_clear();
            break;
        case 4:
            clear_terminal();
            handle_delete_order();
            pause_and_clear();
            break;
        case 5:
            clear_terminal();
            handle_search_order();
            pause_and_clear();
            break;
        case 6:
            clear_terminal();
            printf("\nSaving data... Goodbye!\n");
            break;
        default:
            printf("\n[!] Option %d is not valid.\n", choice);
            pause_and_clear();
            break;
        }
    }
    return 0;
}