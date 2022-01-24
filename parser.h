/*
 * parser.h
 *
 *  Created on: Sep. 06, 2021
 *      Author: n.kessa
 */
 /*
    simple language parser.

    * S->E
    * E->(E)
    * E->add(E,E)
    * E->sub(E,E)
    * E->div(E,E)
    * E->mul(E,E)
    * E->NUM
    * NUM->DNUM
    * D->0 or 1 or 2 .....9 
  */
#ifndef PARSER_H_
#define PARSER_H_

int Parser_parse (char *expression_, int *error);

#endif
