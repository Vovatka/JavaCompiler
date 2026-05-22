%skeleton "lalr1.cc"
%require "3.7"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
    #include <string>
    #include <iostream>
    #include "Visitors/Elements.h"
    #include "Symbols/Type.h"
    class Scanner;
    class Driver;
}

%code {
    #include "location.hh"
    #include "driver.hpp"

    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner& scanner }
%parse-param { Scanner& scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    PLUS "+"
    STAR "*"
    SLASH "/"
    MINUS "-"
    PERCENT "%"
    BOOLEQUALS "=="
    MORE ">"
    LESS "<"
    BITWISEOR "||"
    BITWISEAND "&&"
    LEFTFBRACKET "{"
    RIGHTFBRACKET "}"
    LBRACKET "("
    RBRACKET ")"
    COMMA ","
    SEMICOLON ";"
    LEFTSBRACKET "["
    RIGHTSBRACKET "]"
    EQUALS "="
    DOT "."
    BANG "!"
    CLASS "class"
    EXTENDS "extends"
    PUBLIC "public"
    INT "int"
    BOOLEAN "boolean"
    VOID "void"
    ASSERT "assert"
    IF "if"
    WHILE "while"
    ELSE "else"
    PRINT "System.out.println"
    RETURN "return"
    THISINV "this."
    THIS "this"
    LENGTH "length"
    NEW "new"
    TRUE "true"
    FALSE "false"
    BOYLERPLATE "public static void main"
    EMPTYBRACKETS "[]"
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "num"

%nterm <Expression*> expr
%nterm <ClassDeclarationList*> class_declarations
%nterm <ClassDeclaration*> class_declaration
%nterm <Statement*> statement
%nterm <StatementList*> statements
%nterm <Program*> program
%nterm <MainClass*> main_class;
%nterm <MethodDeclaration*> method_declaration;
%nterm <LocalVarDeclaration*> local_variable_declaration;
%nterm <DeclarationList*> declarations;
%nterm <std::variant<FieldDeclaration*, MethodDeclaration*>> declaration;
%nterm <FormalsList*> formals;
%nterm <FieldInvokeExpression*> field_invocation;
%nterm <MethodInvocation*> method_invocation;
%nterm <ExpressionList*> exprs;
%nterm <Type> type;
%nterm <Type> simple_type;
%nterm <Type> array_type;
%nterm <std::string> type_identifier;
%nterm <FieldDeclaration*> field_declaration;

%%

%left ";";
%left "=";
%left "||";
%left "&&";
%left "==";
%left ">" "<";
%left "+" "-";
%left "*" "/" "%";
%left "(";
%left "[";

%left ".";

%left "!";

%nonassoc "then";
%nonassoc "else";

%start program;

program:
    main_class class_declarations {$$ = new Program($1, $2, driver.loc); driver.program = $$;};

class_declarations:
    %empty {$$ = new ClassDeclarationList(driver.loc);}
    | class_declarations class_declaration {$1->AddClassDeclaration($2); $$ = $1;};

main_class:
    CLASS IDENTIFIER LEFTFBRACKET BOYLERPLATE LBRACKET RBRACKET LEFTFBRACKET statements RIGHTFBRACKET RIGHTFBRACKET {$$ = new MainClass($8, driver.loc);};

statements:
    %empty {$$ = new StatementList(driver.loc);}
   | statements statement {$1->AddStatement($2); $$ = $1;};

class_declaration:
    CLASS IDENTIFIER EXTENDS IDENTIFIER LEFTFBRACKET declarations RIGHTFBRACKET {$$ = new ClassDeclaration($2, $4, $6, driver.loc);}
  | CLASS IDENTIFIER LEFTFBRACKET declarations RIGHTFBRACKET {$$ = new ClassDeclaration($2, "", $4, driver.loc);};

declarations:
    %empty {$$ = new DeclarationList(driver.loc);}
   | declarations declaration {$1->AddDeclaration($2); $$ = $1;};

declaration:
    field_declaration {$$ = $1;} | method_declaration {$$ = $1;};

field_declaration:
    type IDENTIFIER SEMICOLON {$$ = new FieldDeclaration($1, $2, driver.loc);};

method_declaration:
    PUBLIC type IDENTIFIER LBRACKET formals RBRACKET LEFTFBRACKET statements RIGHTFBRACKET {$$ = new MethodDeclaration($3, $2, $5, $8, driver.loc);}
  | PUBLIC type IDENTIFIER LBRACKET RBRACKET LEFTFBRACKET statements RIGHTFBRACKET {$$ = new MethodDeclaration($3, $2, new FormalsList(driver.loc), $7, driver.loc);};

formals:
    type IDENTIFIER {$$ = new FormalsList(driver.loc); $$->AddFormal(new Formal($1, $2, driver.loc));}
   | formals COMMA type IDENTIFIER {$1->AddFormal(new Formal($3, $4, driver.loc)); $$ = $1;};

type:
    simple_type {$$ = $1;} | array_type {$$ = $1;};

simple_type:
    INT {$$ = Type("int");}
  | BOOLEAN {$$ = Type("bool");}
  | VOID {$$ = Type("void");}
  | type_identifier {$$ = Type($1);};

array_type:
    simple_type LEFTSBRACKET RIGHTSBRACKET {$$ = $1; $$.is_array = true;};

type_identifier:
    IDENTIFIER {$$ = $1;};

statement:
    ASSERT LBRACKET expr RBRACKET {$$ = new Assert($3, driver.loc);}
  | local_variable_declaration {$$ = $1;}
  | LEFTFBRACKET statements RIGHTFBRACKET {$$ = new ScopeBlock($2, driver.loc);}
  | IF LBRACKET expr RBRACKET statement {$$ = new IfElse($3, $5, nullptr, driver.loc);}     %prec "then"
  | IF LBRACKET expr RBRACKET statement ELSE statement {$$ = new IfElse($3, $5, $7, driver.loc);}
  | WHILE LBRACKET expr RBRACKET statement {$$ = new While($3, $5, driver.loc);}
  | PRINT LBRACKET expr RBRACKET SEMICOLON {$$ = new Print($3, driver.loc);}
  | expr EQUALS expr SEMICOLON {$$ = new VarAssignment($1, $3, driver.loc);}
  | RETURN expr SEMICOLON {$$ = new Return($2, driver.loc);}
  | method_invocation SEMICOLON {$$ = $1;};

local_variable_declaration:
    type IDENTIFIER SEMICOLON {$$ = new LocalVarDeclaration($1, $2, driver.loc);};

method_invocation:
    THISINV IDENTIFIER LBRACKET RBRACKET {$$ = new MethodInvocation(new ThisExpression(driver.loc), $2, nullptr, driver.loc);}
  | THISINV IDENTIFIER LBRACKET exprs RBRACKET {$$ = new MethodInvocation(new ThisExpression(driver.loc), $2, $4, driver.loc);}
  | expr DOT IDENTIFIER LBRACKET RBRACKET {$$ = new MethodInvocation($1, $3, nullptr, driver.loc);}
  | expr DOT IDENTIFIER LBRACKET exprs RBRACKET {$$ = new MethodInvocation($1, $3, $5, driver.loc);};

exprs:
    expr {$$ = new ExpressionList(driver.loc); $$->AddExpression($1);}
  | exprs COMMA expr {$1->AddExpression($3); $$ = $1;};

field_invocation:
    THISINV IDENTIFIER {$$ = new FieldInvokeExpression($2, driver.loc);};

expr:
    expr BITWISEAND expr {$$ = new LogicalAndExpression($1, $3, driver.loc);}
  | expr BITWISEOR expr {$$ = new LogicalOrExpression($1, $3, driver.loc);}
  | expr LESS expr {$$ = new LessExpression($1, $3, driver.loc);}
  | expr MORE expr {$$ = new GreaterExpression($1, $3, driver.loc);}
  | expr BOOLEQUALS expr {$$ = new EqualExpression($1, $3, driver.loc);}
  | expr PLUS expr {$$ = new AddExpression($1, $3, driver.loc);}
  | expr MINUS expr {$$ = new SubExpression($1, $3, driver.loc);}
  | expr STAR expr {$$ = new MulExpression($1, $3, driver.loc);}
  | expr SLASH expr {$$ = new DivExpression($1, $3, driver.loc);}
  | expr PERCENT expr {$$ = new ModExpression($1, $3, driver.loc);}
  | expr LEFTSBRACKET expr RIGHTSBRACKET {$$ = new IndexExpression($1, $3, driver.loc);}
  | expr DOT LENGTH {$$ = new LengthExpression($1, driver.loc);}
  | NEW simple_type LEFTSBRACKET expr RIGHTSBRACKET { $$ = new AllocExpression(Type($2.type_name, true), $4, driver.loc); }
  | NEW type_identifier LBRACKET RBRACKET { $$ = new AllocExpression(Type($2), nullptr, driver.loc); }
  | BANG expr {$$ = new NotExpression($2, driver.loc);}
  | LBRACKET expr RBRACKET {$$ = $2;}
  | IDENTIFIER {$$ = new IdentExpression($1, driver.loc);}
  | NUMBER {$$ = new NumExpression($1, driver.loc);}
  | THIS {$$ = new ThisExpression(driver.loc);}
  | TRUE {$$ = new TrueExpression(driver.loc);}
  | FALSE {$$ = new FalseExpression(driver.loc);}
  | method_invocation {$$ = $1;}
  | field_invocation {$$ = $1;};

%%

void yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}
