﻿#include "token.h"
#include <iostream>
#include <string>
#include <vector>



Token Token_stream::get()
{
  if (!buffer.empty())               /// If buffer is full
  {
    Token tmp{ buffer[buffer.size()-1] };
    buffer.pop_back();
    return tmp;
  }

  char ch;
  std::cin >> ch;              /// >> operator skips white space symbols

  switch (ch)
  {
  case PRINT:
  case QUIT:
  case NAME:
  case LET:
  case INIT:
  case '(': case ')':
  case '{': case '}':
  case '%':
  case '+': case '-':
  case '*': case '/':
  {
    return Token{ ch }; /// Every symbol represents itself
  }

  case '.':             /// Float numbers
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  {
    std::cin.putback(ch);    /// First digit returns to input stream
    double val;
    std::cin >> val;         /// Reading float number
    return Token{ NUMBER, val };
  }

  default:
  {
    if (isalpha(ch))    /// Reading variable name or declaration key word
    {
      std::string s;
      s += ch;
      while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
      std::cin.putback(ch);
      if (s == DECLKEY) return Token{ LET };
      return Token{ NAME, s };
    }
    throw std::runtime_error{"Token_stream::get(): bad token"};
  }
  }
}

void Token_stream::putback(Token t)
{
  buffer.push_back(t);
}

void Token_stream::ignore(char token_kind)
{
  while (true)
  {
    Token t{ get() };
    if (t.kind == token_kind)
    {
      putback(t);
      return;
    }
  }
}
