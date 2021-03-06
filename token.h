﻿#ifndef TOKEN_H
#define TOKEN_H


#include <string>
#include <vector>


const std::string ALLOWED{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM.0123456789()[]{}+-*/%=^$_;" };

constexpr char NUMBER{ '8' };            // for numbers
constexpr char QUIT{ 'q' };              // for quit
constexpr char PRINT{ ';' };             // for print
constexpr char HELP{ 'h' };              // for help
constexpr char NAME{ 'n' };              // for variable name
constexpr char FUNC{ 'f' };              // for functions name
constexpr char LET{ 'l' };               // for DECLKEY keyword
constexpr char CONST{ 'c' };             // for CONSTKEY keyword
constexpr char INIT{ '=' };              // for variable initialization
constexpr char ENDLINE{ '\n' };          // for end of line

const std::string PROMPT{ "> " };        // string before inputing statement
const std::string RESULT{ "= " };        // string before printing result
const std::string DECLKEY{ "let" };      // for variable declaration
const std::string CONSTKEY{ "const" };   // for constant declaration
const std::string HELPKEY{ "help" };     // for get help
const std::string QUITKEY{ "exit" };     // for quit
const std::vector<std::string> FUNCKEYS{ "sin", "cos", "tg", "ctg", "arcsin", "arccos", "arctg",
                                        "arcctg", "abs", "sqrt", "ch", "sh", "th", "cth", "ln",
                                        "exp", "lg"};


class Token
{
  public:
    char kind;
    double value;
    std::string name;

    Token(char ch)
      : kind{ ch } { }

    // Initialize kind & value
    Token(char ch, double val)
      : kind{ ch }, value{ val }  { }

    // Initialize kind & name
    Token(char ch, std::string n)
      : kind{ ch }, name{ n } { }
};

class TokenStream
{
  public:
    Token get();
    void putback(Token t);

    TokenStream()
      : buffer{ } { }

  private:
    std::vector<Token> buffer;
};

class TokenError
{
  public:
    std::string what;

    TokenError () = delete;
    TokenError (std::string str)
      : what{ str } { }
};


#endif // TOKEN_H
