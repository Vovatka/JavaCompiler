
#ifndef JAVACOMPILER_NUMEXPRESSION_H
#define JAVACOMPILER_NUMEXPRESSION_H

#include "Expressions/Expression.h"
#include <variant>

class NumExpression : public Expression
{
  public:
    explicit NumExpression(int value, yy::location loc);
    void Accept(Visitor *visitor) override;
    std::variant<int, std::string> eval() const override;

    int GetValue() const;

  private:
    int value_;

    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_NUMEXPRESSION_H
