%{
    #include <cstring>
    #include <string>
    #include <iostream>
    #include "driver.hpp"
    #include "parser.hpp"
%}

%option noyywrap nounput noinput batch debug
%option c++
%option yyclass="Scanner"

id          [_a-zA-Z][_a-zA-Z0-9]*
number      [0-9]+
blank       [ \t\r]

%{
  #define YY_USER_ACTION \
      driver.loc.columns(yyleng); \
      driver.loc.step();
%}

%%

\n+                         driver.loc.lines(yyleng); driver.loc.step();

{blank}+                   

"public static void main"   return yy::parser::make_BOYLERPLATE(driver.loc);
"this."                     return yy::parser::make_THISINV(driver.loc);

"+"                         return yy::parser::make_PLUS(driver.loc);
"*"                         return yy::parser::make_STAR(driver.loc);
"/"                         return yy::parser::make_SLASH(driver.loc);
"-"                         return yy::parser::make_MINUS(driver.loc);
"%"                         return yy::parser::make_PERCENT(driver.loc);
"=="                        return yy::parser::make_BOOLEQUALS(driver.loc);
">"                         return yy::parser::make_MORE(driver.loc);
"<"                         return yy::parser::make_LESS(driver.loc);
"||"                        return yy::parser::make_BITWISEOR(driver.loc);
"&&"                        return yy::parser::make_BITWISEAND(driver.loc);

"{"                         return yy::parser::make_LEFTFBRACKET(driver.loc);
"}"                         return yy::parser::make_RIGHTFBRACKET(driver.loc);
"("                         return yy::parser::make_LBRACKET(driver.loc);
")"                         return yy::parser::make_RBRACKET(driver.loc);
","                         return yy::parser::make_COMMA(driver.loc);
";"                         return yy::parser::make_SEMICOLON(driver.loc);
"["                         return yy::parser::make_LEFTSBRACKET(driver.loc);
"]"                         return yy::parser::make_RIGHTSBRACKET(driver.loc);
"="                         return yy::parser::make_EQUALS(driver.loc);
"."                         return yy::parser::make_DOT(driver.loc);
"!"                         return yy::parser::make_BANG(driver.loc);
"class"                     return yy::parser::make_CLASS(driver.loc);
"extends"                   return yy::parser::make_EXTENDS(driver.loc);
"public"                    return yy::parser::make_PUBLIC(driver.loc);
"int"                       return yy::parser::make_INT(driver.loc);
"boolean"                   return yy::parser::make_BOOLEAN(driver.loc);
"bool"                      return yy::parser::make_BOOLEAN(driver.loc);
"void"                      return yy::parser::make_VOID(driver.loc);
"assert"                    return yy::parser::make_ASSERT(driver.loc);
"if"                        return yy::parser::make_IF(driver.loc);
"while"                     return yy::parser::make_WHILE(driver.loc);
"else"                      return yy::parser::make_ELSE(driver.loc);
"System.out.println"        return yy::parser::make_PRINT(driver.loc);
"return"                    return yy::parser::make_RETURN(driver.loc);
"this"                      return yy::parser::make_THIS(driver.loc);
"length"                    return yy::parser::make_LENGTH(driver.loc);
"new"                       return yy::parser::make_NEW(driver.loc);
"true"                      return yy::parser::make_TRUE(driver.loc);
"false"                     return yy::parser::make_FALSE(driver.loc);

{number}                    return yy::parser::make_NUMBER(atoi(yytext), driver.loc);
{id}                        return yy::parser::make_IDENTIFIER(yytext, driver.loc);

.                           {
                                throw yy::parser::syntax_error(driver.loc, "invalid character: " + std::string(yytext));
                            }
<<EOF>>                     return yy::parser::make_END(driver.loc);

%%
