
#ifndef JAVACOMPILER_NOTEXPRESSION_H
#define JAVACOMPILER_NOTEXPRESSION_H

#include "Expressions/Expression.h"

class NotExpression : public Expression
{
  public:
    NotExpression(Expression *expr, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
    Expression *expr;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_NOTEXPRESSION_H
