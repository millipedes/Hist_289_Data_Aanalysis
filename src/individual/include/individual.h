#ifndef IND_H
#define IND_H

#include "../../food_categories/include/food_categories.h"
#include "../../token/include/token_stack.h"
#include "../../lexer/include/lexer.h"

typedef struct INDIVIDUAL_T {
  char * country;
  weeks_food * wf;
} individual;

typedef struct INDIVIDUAL_LIST_T {
  individual ** list;
  int qty_ind;
} individual_list;

individual * init_individual(token_stack ** ts);
individual_list * parse_individual_list(char * file_name);
void individual_list_dump_debug(individual_list * ind);
void individual_dump_debug(individual * ind);
void free_individual_list(individual_list * il);
void free_individual(individual * ind);

#endif
