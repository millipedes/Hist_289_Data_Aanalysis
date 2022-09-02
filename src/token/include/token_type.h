/**
 * @file   token_type.h
 * @brief  This file contains the function definitions for token_type.c
 * @author Matthew C. Lindeman
 * @date   August 25, 2022
 * @bug    None known
 * @todo   Nothing
 */
#ifndef TT_H
#define TT_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  TOKEN_CN,
  TOKEN_NONE,
  TOKEN_NUMBER,
  TOKEN_SEP,
  TOKEN_NEWLINE
} token_type;

const char * token_type_to_string(token_type type);

#endif
