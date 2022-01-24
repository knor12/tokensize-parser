/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include "parser.h"





int
main ()
{
  int err;
  int i ; 
  i = Parser_parse ("sub(add(1,add(add(1,(1021)),1)),1000)", &err);
  printf ("s=%d\n", i);

  i = Parser_parse ("add(100,div((10),(2)))", &err);
  printf ("s=%d\n", i);


  i = Parser_parse ("mul(100,2)", &err);
  printf ("s=%d\n", i);


  i = Parser_parse ("div(100,add(2,1))", &err);
  printf ("s=%d\n", i);

  i =Parser_parse("(sub(div(mul(     add(add(1,add  (1,-1)),1),            10),40),3))",&err);
  printf ("s=%d\n", i);
  
  
  
  i = Parser_parse ("mul(add(-0,1000), 5856)", &err);
  printf ("s=%d\n", i);

  return 0;
}
