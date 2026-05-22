
#ifndef JAVACOMPILER_MODEXPRESSION_H
#define JAVACOMPILER_MODEXPRESSION_H

#include <Expressions/BinaryExpression/ArithmeticExpressions/ArithmeticExpression.h>

class ModExpression : public ArithmeticExpression
{
  public:
    ModExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_MODEXPRESSION_H
