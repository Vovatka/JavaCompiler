
#include "Expressions/Expression.h"
#include <variant>
#ifndef JAVACOMPILER_FALSEEXPRESSION_H
#define JAVACOMPILER_FALSEEXPRESSION_H

class FalseExpression : public Expression
{
  public:
    FalseExpression(yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_FALSEEXPRESSION_H
