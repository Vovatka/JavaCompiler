
#ifndef JAVACOMPILER_LESSEXPRESSION_H
#define JAVACOMPILER_LESSEXPRESSION_H

#include <Expressions/BinaryExpression/ComparisonExpressions/ComparisonExpression.h>

class LessExpression : public ComparisonExpression
{
  public:
    LessExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_LESSEXPRESSION_H
