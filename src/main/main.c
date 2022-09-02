#include <stdio.h>
#include "../individual/include/individual.h"
#include "../stats/include/stats.h"

int main(void) {
  individual_list * il = parse_individual_list("data.txt");
  printf("%f\n", highest_total_category_cost(il));
  printf("Most Used Category: %s\n", category_to_string(most_used_category(il)));
  printf("Least Used Category: %s\n", category_to_string(least_used_category(il)));
  free_individual_list(il);
  return 0;
}
