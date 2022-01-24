/*
 * tokenizer.h :
 *
 *  Created on: Sep. 06, 2021
 *      Author: n.kessa
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>



typedef enum
{
  zero,
  number,
  left_braket,
  right_braket,
  comma,
  add,
  sub,
  div,
  mul,
  uknown,
  none
} token_t;


void Tokenizer_handleParseError (char *error);

int Tokenizer_getNumber ();

token_t Tokenizer_getToken ();

bool Tokenizer_consumeToken (token_t token);

void Tokenizer_setExpression (char *expression);

#endif
