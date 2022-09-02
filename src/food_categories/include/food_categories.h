#ifndef FOC_H
#define FOC_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  GRAINS,
  DAIRY,
  MEAT_FISH,
  FRUIT_VEGIES,
  CONDIMENTS,
  SNACKS_DESSERTS,
  PREPARED_FOOD,
  FAST_FOOD,
  BEVERAGES,
  MISC
} category;

const char * category_to_string(category cat);

typedef struct FOOD_CATEGORY_T {
  category cat;
  double value;
  int none; // 0 - No None, 1 - None
} food_category;

food_category * init_food_category(category cat, double value, int none);
void food_category_dump_debug(food_category * fc);
void free_food_category(food_category * fc);

typedef struct WEEKS_FOOD_T {
  food_category ** fc;
  int qty_fc;
} weeks_food;

weeks_food * init_weeks_food(void);
weeks_food * add_weeks_food(weeks_food * wf, food_category * fc);
void weeks_food_dump_debug(weeks_food * wf);
void free_weeks_food(weeks_food * wf);

#endif
