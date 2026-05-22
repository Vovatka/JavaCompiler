
#ifndef JAVACOMPILER_BINARYEXPRESSION_H
#define JAVACOMPILER_BINARYEXPRESSION_H

#include <Expressions/Expression.h>

class BinaryExpression : public Expression
{
  public:
    BinaryExpression(Expression *expr1, Expression *expr2, yy::location loc);
    Expression *expr1;
    Expression *expr2;
};

#endif // JAVACOMPILER_BINARYEXPRESSION_H
