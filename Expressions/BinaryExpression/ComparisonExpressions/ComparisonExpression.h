
#ifndef JAVACOMPILER_COMPARISONEXPRESSION_H
#define JAVACOMPILER_COMPARISONEXPRESSION_H

#include <Expressions/BinaryExpression/BinaryExpression.h>

class ComparisonExpression : public BinaryExpression
{
  public:
    ComparisonExpression(Expression *expr1, Expression *expr2,
                         yy::location loc);

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_COMPARISONEXPRESSION_H
