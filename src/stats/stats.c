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

category most_used_category(individual_list * il) {
  int categories[10];
  int max = -1;
  int max_index = 0;
  for(int i = 0; i < il->qty_ind; i++)
    for(int j = 0; j < il->list[i]->wf->qty_fc; j++)
      if(il->list[i]->wf->fc[j]->none != 1)
        categories[il->list[i]->wf->fc[j]->cat]++;
  for(int i = 0; i < 10; i++)
    if(categories[i] > max) {
      max = categories[i];
      max_index = i;
    }
  return (category)max_index;
}

category least_used_category(individual_list * il) {
  int categories[10];
  int min = 1000;
  int min_index = 0;
  for(int i = 0; i < il->qty_ind; i++)
    for(int j = 0; j < il->list[i]->wf->qty_fc; j++)
      if(il->list[i]->wf->fc[j]->none != 1)
        categories[il->list[i]->wf->fc[j]->cat]++;
  for(int i = 0; i < 10; i++)
    if(categories[i] < min) {
      min = categories[i];
      min_index = i;
    }
  return (category)min_index;
}
