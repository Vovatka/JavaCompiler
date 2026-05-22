#include "Expressions/Expression.h"
#include "Statement.h"
#ifndef JAVACOMPILER_WHILE_H
#define JAVACOMPILER_WHILE_H

class While : public Statement
{
  public:
    While(Expression *expr, Statement *statement, yy::location loc);
    void Accept(Visitor *visitor) override;

  public:
    Expression *expr;
    Statement *statement;
};

#endif // JAVACOMPILER_WHILE_H
