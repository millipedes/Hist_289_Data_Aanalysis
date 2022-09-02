/**
 * @file   token_type.c
 * @brief  This file contains the related functions for the token_type
 * enumeration.
 * @author Matthew C. Lindeman
 * @date   August 25, 2022
 * @bug    None known
 * @todo   Nothing
 */
#include "include/token_type.h"

/**
 * This funciton takes a token_type and converts it to a const char *
 * representation.
 * @param token_type - The type in question.
 * @return        .\ - The corresponding const char *.
 */
const char * token_type_to_string(token_type type) {
  switch(type) {
    case TOKEN_CN:      return "Token Country Name";
    case TOKEN_NONE:    return "Token None";
    case TOKEN_NUMBER:  return "Token Number";
    case TOKEN_SEP:     return "Token Sep";
    case TOKEN_NEWLINE: return "Token Newline";
  }
  fprintf(stderr, "[TOKEN_TYPE_TO_STRING]: Fell Through\nExiting\n");
  exit(1);
}
