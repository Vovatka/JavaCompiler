#ifndef JAVACOMPILER_RETURN_H
#define JAVACOMPILER_RETURN_H

#include "Statement.h"
#include <Expressions/Expression.h>

class Return : public Statement
{
  public:
    explicit Return(Expression *expr, yy::location loc);
    void Accept(Visitor *visitor) override;
    Expression *expr;
};

#endif // JAVACOMPILER_RETURN_H
