#ifndef JAVACOMPILER_SUBEXPRESSION_H
#define JAVACOMPILER_SUBEXPRESSION_H

#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>
#include <variant>

class SubExpression : public ArithmeticExpression
{
  public:
    SubExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_SUBEXPRESSION_H
