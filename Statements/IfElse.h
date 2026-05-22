#pragma once
#include "Expressions/Expression.h"
#include "Statement.h"
#ifndef JAVACOMPILER_IFELSE_H
#define JAVACOMPILER_IFELSE_H

class IfElse : public Statement
{
  public:
    IfElse(Expression *expression, Statement *If, Statement *Else,
           yy::location loc);
    void Accept(Visitor *visitor) override;

    Expression *expr;
    Statement *If;
    Statement *Else;
};

#endif // JAVACOMPILER_IFELSE_H
