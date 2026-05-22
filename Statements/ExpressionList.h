
#ifndef JAVACOMPILER_EXPRESSIONLIST_H
#define JAVACOMPILER_EXPRESSIONLIST_H

#include "Statement.h"
#include <Expressions/Expression.h>
#include <vector>

class ExpressionList : Statement
{
  public:
    explicit ExpressionList(yy::location loc);
    void Accept(Visitor *visitor) override;
    void AddExpression(Expression *expr);
    std::vector<Expression *> expressions;
};

#endif // JAVACOMPILER_EXPRESSIONLIST_H
