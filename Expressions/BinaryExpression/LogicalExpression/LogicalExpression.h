
#ifndef JAVACOMPILER_LOGICALEXPRESSION_H
#define JAVACOMPILER_LOGICALEXPRESSION_H

#include <Expressions/BinaryExpression/BinaryExpression.h>

class LogicalExpression : public BinaryExpression
{
  public:
    LogicalExpression(Expression *expr1, Expression *expr2, yy::location loc);

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_LOGICALEXPRESSION_H
