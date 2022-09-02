#include "include/stats.h"

double total_individual_cost(individual * ind) {
  double sum = 0.0;
  for(int i = 0; i < ind->wf->qty_fc; i++) {
    if(ind->wf->fc[i]->none != 1)
      sum += ind->wf->fc[i]->value;
  }
  return sum;
}

double average_individual_category_cost(individual * ind) {
  double sum = 0.0;
  for(int i = 0; i < ind->wf->qty_fc; i++) {
    if(ind->wf->fc[i]->none != 1)
      sum += ind->wf->fc[i]->value;
  }
  return (sum / (double) ind->wf->qty_fc);
}

double highest_total_category_cost(individual_list * il) {
  double max = -1;
  for(int i = 0; i < il->qty_ind; i++)
    if(average_individual_category_cost(il->list[i]) > max)
      max = average_individual_category_cost(il->list[i]);
  return max;
}

double highest_total_individual_cost(individual_list * il) {
  double max = -1;
  for(int i = 0; i < il->qty_ind; i++)
    if(total_individual_cost(il->list[i]) > max)
      max = total_individual_cost(il->list[i]);
  return max;
}

// double most_expensive_category(individual_list * il) {
// }
