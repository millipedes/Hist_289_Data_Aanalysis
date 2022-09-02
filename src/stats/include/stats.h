#ifndef STAT_H
#define STAT_H

#include "../../individual/include/individual.h"

double total_individual_cost(individual * ind);
double average_individual_category_cost(individual * ind);
double highest_total_category_cost(individual_list * il);
double highest_total_individual_cost(individual_list * il);
category most_used_category(individual_list * il);
category least_used_category(individual_list * il);

#endif
