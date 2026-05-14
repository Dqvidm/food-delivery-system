#ifndef MODELS_H
#define MODELS_H

#define MAX_STR 50

#define CLR_RESET  "\033[0m"
#define CLR_RED    "\033[1;31m"
#define CLR_GREEN  "\033[1;32m"
#define CLR_YELLOW "\033[1;33m"
#define CLR_CYAN   "\033[1;36m"
#define CLR_MAGENTA "\033[1;35m"

typedef struct {
    char restaurant[MAX_STR];
    char item_name[MAX_STR];
    float total_price;
    char location[MAX_STR];
} Order;

#endif