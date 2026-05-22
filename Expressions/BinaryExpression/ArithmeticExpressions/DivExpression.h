
#ifndef JAVACOMPILER_DIVCLASS_H
#define JAVACOMPILER_DIVCLASS_H

#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>

class DivExpression : public ArithmeticExpression
{
  public:
    DivExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_DIVCLASS_H
