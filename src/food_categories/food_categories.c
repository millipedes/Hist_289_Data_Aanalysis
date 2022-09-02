#include "include/food_categories.h"

const char * category_to_string(category cat) {
  switch(cat) {
    case GRAINS:          return "Grains";
    case DAIRY:           return "Dairy";
    case MEAT_FISH:       return "Meat Fish";
    case FRUIT_VEGIES:    return "Fruit Vegies";
    case CONDIMENTS:      return "Condiments";
    case SNACKS_DESSERTS: return "Snacks Desserts";
    case PREPARED_FOOD:   return "Prepared Food";
    case FAST_FOOD:       return "Fast Food";
    case BEVERAGES:       return "Beverages";
    case MISC:            return "Misc";
  }
  return NULL;
}

food_category * init_food_category(category cat, double value, int none) {
  food_category * fc = calloc(1, sizeof(struct FOOD_CATEGORY_T));
  fc->cat = cat;
  fc->value = value;
  fc->none = none;
  return fc;
}

void food_category_dump_debug(food_category * fc) {
  printf("Food Category: %s\n", category_to_string(fc->cat));
  printf("Value: %f\n", fc->value);
  printf("None? %s\n", fc->none ? "Is Not None" : "Is None");
}

void free_food_category(food_category * fc) {
  if(fc)
    free(fc);
}

weeks_food * init_weeks_food(void) {
  weeks_food * wf = calloc(1, sizeof(struct WEEKS_FOOD_T));
  wf->fc = NULL;
  wf->qty_fc = 0;
  return wf;
}

weeks_food * add_weeks_food(weeks_food * wf, food_category * fc) {
  wf->qty_fc++;
  if(wf->fc)
    wf->fc = realloc(wf->fc, wf->qty_fc * sizeof(struct FOOD_CATEGORY_T *));
  else
    wf->fc = calloc(1, sizeof(struct FOOD_CATEGORY_T *));
  wf->fc[wf->qty_fc - 1] = fc;
  return wf;
}

void weeks_food_dump_debug(weeks_food * wf) {
  printf("Week's Food\n");
  for(int i = 0; i < wf->qty_fc; i++)
    food_category_dump_debug(wf->fc[i]);
}

void free_weeks_food(weeks_food * wf) {
  if(wf) {
    for(int i = 0; i < wf->qty_fc; i++)
      if(wf->fc[i])
        free_food_category(wf->fc[i]);
    if(wf->fc)
      free(wf->fc);
    free(wf);
  }
}
