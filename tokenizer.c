#include "tokenizer.h"

static char *expression;
static char *expression_original;
static int num = 0;


static bool
my_strcmp (char *str1, char *str2)
{
  uint32_t length = strlen (str1);
  if (length > strlen (str2))
    {
      length = strlen (str2);
    }

  for (uint32_t i = 0; i < length; i++)
    {
      //printf(" , char1=%c    char2=%c \n" ,(char)(*(str1 +i)) , (char )(*(str2 +i)))  ;
      if ((char) (*(str1 + i)) != (char) (*(str2 + i)))
	{
	  return false;
	}
    }

  return true;

}


void
Tokenizer_handleParseError (char *error)
{
  printf ("\n error handling parse error at %s , at %s\n", error, expression);
  //printf("\n error handling parse error at %s" , expression);
}


int
Tokenizer_getNumber ()
{
  return num;
}

token_t
Tokenizer_getToken ()
{
  /*skip white space */
  while ((*expression == ' ') || (*expression == '\t'))
    {
      expression++;
    }

  printf ("current token %s\n", expression);
  if (my_strcmp (expression, "("))
    {
      expression = expression + 1;
      return left_braket;
    }
  else if (my_strcmp (expression, ")"))
    {
      expression = expression + 1;
      return right_braket;
    }
  else if ((*expression >= '0') && (*expression <= '9'))
    {
      num = *expression - '0';
      expression = expression + 1;

      while ((*expression >= '0') && (*expression <= '9'))
	{
	  num = num * 10;
	  num = num + *expression - '0';
	  expression = expression + 1;
	}

      return number;
    }
  else if (my_strcmp (expression, "add"))
    {
      expression = expression + 3;
      return add;
    }
  else if (my_strcmp (expression, "sub"))
    {
      expression = expression + 3;
      return sub;
    }
  else if (my_strcmp (expression, "div"))
    {
      expression = expression + 3;
      return div;
    }
  else if (my_strcmp (expression, "mul"))
    {
      expression = expression + 3;
      return mul;
    }
  else if (my_strcmp (expression, ","))
    {
      expression = expression + 1;
      return comma;
    }
  else if (expression == 0)
    {
      return none;
    }
  else
    {
      return uknown;
    }
}

bool
Tokenizer_consumeToken (token_t token)
{
  if (Tokenizer_getToken () == token)
    {
      return true;
    }
  else
    {
      char err[50];
      sprintf (err, "unexpected token, expected %d", token);
      Tokenizer_handleParseError (err);
      return false;
    }
}

void
Tokenizer_setExpression (char *expression_)
{
  expression = expression_;
  expression_original = expression_;
}
