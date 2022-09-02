#include "include/individual.h"

individual * init_individual(token_stack ** ts) {
  individual * ind = calloc(1, sizeof(struct INDIVIDUAL_T));
  ind->wf = init_weeks_food();
  size_t len = 0;
  int enum_index = 0;
  while(ts[0]) {
    if(ts[0]->current->type == TOKEN_SEP)
      ts[0] = pop_token(ts[0]);

    if(ts[0]->current->type == TOKEN_NONE) {
      ind->wf = add_weeks_food(ind->wf, init_food_category(enum_index, 0, 1));
      enum_index++;
    } else if(ts[0]->current->type == TOKEN_CN) {
      len = strnlen(ts[0]->current->t_literal, MAX_TOK_LEN) + 1;
      ind->country = calloc(len, sizeof(char));
      strncpy(ind->country, ts[0]->current->t_literal, len);
    } else if(ts[0]->current->type != TOKEN_NEWLINE) {
      ind->wf = add_weeks_food(ind->wf, init_food_category(enum_index,
            atof(ts[0]->current->t_literal), 0));
      enum_index++;
    }
    ts[0] = pop_token(ts[0]);
  }
  return ind;
}

individual_list * parse_individual_list(char * file_name) {
  FILE * fp = fopen(file_name, "r");
  char buf[MAX_TOK_LEN];
  lexer * lex = NULL;
  token_stack * ts = NULL;
  token_stack * rev = NULL;
  individual_list * il = calloc(1, sizeof(struct INDIVIDUAL_LIST_T));
  il->list = NULL;
  il->qty_ind = 0;
  // The header line
  fgets(buf, MAX_TOK_LEN, fp);

  while(fgets(buf, MAX_TOK_LEN, fp)) {
    lex = init_lexer(buf);
    ts = lex_source(lex);
    rev = reverse_stack(&ts);
    il->qty_ind++;
    if(il->list)
      il->list = realloc(il->list, il->qty_ind * sizeof(struct INDIVIDUAL_T *));
    else
      il->list = calloc(1, sizeof(struct INDIVIDUAL_T *));
    il->list[il->qty_ind - 1] = init_individual(&rev);
    free_lexer(lex);
    while(ts)
      ts = pop_token(ts);
    while(rev)
      rev = pop_token(rev);
  }
  fclose(fp);
  return il;
}

void individual_list_dump_debug(individual_list * ind) {
  printf("Individual List\n");
  for(int i = 0; i < ind->qty_ind; i++)
    individual_dump_debug(ind->list[i]);
  printf("Qty: %d\n", ind->qty_ind);
}

void individual_dump_debug(individual * ind) {
  printf("Individual\n");
  printf("Country: %s\n", ind->country);
  weeks_food_dump_debug(ind->wf);
}

void free_individual_list(individual_list * il) {
  if(il) {
    if(il->list) {
      for(int i = 0; i < il->qty_ind; i++)
        if(il->list[i])
          free_individual(il->list[i]);
      free(il->list);
    }
    free(il);
  }
}

void free_individual(individual * ind) {
  if(ind) {
    if(ind->country)
      free(ind->country);
    if(ind->wf)
      free_weeks_food(ind->wf);
    free(ind);
  }
}
