
#ifndef JAVACOMPILER_TRUEEXPRESSION_H
#define JAVACOMPILER_TRUEEXPRESSION_H

#include "Expressions/Expression.h"

class TrueExpression : public Expression
{
  public:
    TrueExpression(yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_TRUEEXPRESSION_H
