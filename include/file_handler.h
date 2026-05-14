#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "models.h"

void save_order_to_file(Order o);
void display_history();
float get_grand_total();
void update_order_list(Order orders[], int count);

#endif