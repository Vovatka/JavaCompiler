#ifndef JAVACOMPILER_PRINT_H
#define JAVACOMPILER_PRINT_H

#include "Statement.h"
#include <Expressions/Expression.h>

class Print : public Statement
{
  public:
    explicit Print(Expression *expr, yy::location loc);
    void Accept(Visitor *visitor) override;
    Expression *expr;
};

#endif // JAVACOMPILER_PRINT_H
