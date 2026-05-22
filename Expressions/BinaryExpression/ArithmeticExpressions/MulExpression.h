
#ifndef JAVACOMPILER_MULEXPRESSION_H
#define JAVACOMPILER_MULEXPRESSION_H

#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>
#include <variant>

class MulExpression : public ArithmeticExpression
{
  public:
    MulExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_MULEXPRESSION_H
