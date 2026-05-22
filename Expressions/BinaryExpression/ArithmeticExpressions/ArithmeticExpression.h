
#ifndef JAVACOMPILER_ARITHMETICEXPRESSION_H
#define JAVACOMPILER_ARITHMETICEXPRESSION_H

#include <Expressions/BinaryExpression/BinaryExpression.h>

class ArithmeticExpression : public BinaryExpression
{
  public:
    ArithmeticExpression(Expression *expr1, Expression *expr2,
                         yy::location loc);

    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_ARITHMETICEXPRESSION_H
