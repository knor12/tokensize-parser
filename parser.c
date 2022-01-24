#include "parser.h"
#include "tokenizer.h"

static int
parseE (char *expression, int *error)
{
  token_t token = Tokenizer_getToken ();
  int temp;
  if (token == left_braket)
    {
      temp = parseE (expression, error);
      if (!Tokenizer_consumeToken (right_braket))
	{
	  *error = 1;
	  return 0;
	}

      return temp;
    }
  else if (token == number)
    {
      return Tokenizer_getNumber ();
    }
  else if (token == add)
    {
      if (!Tokenizer_consumeToken (left_braket))
	{
	  *error = 1;
	  return 0;
	}
      int temp1 = parseE (expression, error);
      if (!Tokenizer_consumeToken (comma))
	{
	  *error = 1;
	  return 0;
	}
      int temp2 = parseE (expression, error);
      if (!Tokenizer_consumeToken (right_braket))
	{
	  *error = 1;
	  return 0;
	}
      return temp1 + temp2;
    }
  else if (token == div)
    {
      if (!Tokenizer_consumeToken (left_braket))
	{
	  *error = 1;
	  return 0;
	}
      int temp1 = parseE (expression, error);
      if (!Tokenizer_consumeToken (comma))
	{
	  *error = 1;
	  return 0;
	}
      int temp2 = parseE (expression, error);
      if (!Tokenizer_consumeToken (right_braket))
	{
	  *error = 1;
	  return 0;
	}
      return temp1 / temp2;
    }
  else if (token == mul)
    {
      if (!Tokenizer_consumeToken (left_braket))
	{
	  *error = 1;
	  return 0;
	}
      int temp1 = parseE (expression, error);
      if (!Tokenizer_consumeToken (comma))
	{
	  *error = 1;
	  return 0;
	}
      int temp2 = parseE (expression, error);
      if (!Tokenizer_consumeToken (right_braket))
	{
	  *error = 1;
	  return 0;
	}
      return temp1 * temp2;
    }
  else if (token == sub)
    {
      if (!Tokenizer_consumeToken (left_braket))
	{
	  *error = 1;
	  return 0;
	}
      int temp1 = parseE (expression, error);
      if (!Tokenizer_consumeToken (comma))
	{
	  *error = 1;
	  return 0;
	}
      int temp2 = parseE (expression, error);
      if (!Tokenizer_consumeToken (right_braket))
	{
	  *error = 1;
	  return 0;
	}
      return temp1 - temp2;
    }
  else if (token == uknown)
    {
      Tokenizer_handleParseError ("uknown token found");
      (*error) = 1;
    }


}

static int
parseS (char *expression, int *error)
{
  parseE (expression, error);
}


int
Parser_parse (char *expression_, int *error)
{
  Tokenizer_setExpression (expression_);
  *error = 0;
  return parseS (expression_, error);

}
