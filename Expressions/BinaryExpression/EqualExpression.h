
#include "Expressions/Expression.h"
#ifndef JAVACOMPILER_EQUALEXPRESSION_H
#define JAVACOMPILER_EQUALEXPRESSION_H

#include "BinaryExpression.h"

class EqualExpression : public BinaryExpression
{
  public:
    EqualExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_EQUALEXPRESSION_H
