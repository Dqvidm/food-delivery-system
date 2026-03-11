#ifndef MODELS_H
#define MODELS_H

#define MAX_STR 50

// The "Blueprint" for an order
typedef struct {
    char restaurant[MAX_STR];
    char item_name[MAX_STR];
    float total_price;
    char location[MAX_STR];
} Order;

#endif