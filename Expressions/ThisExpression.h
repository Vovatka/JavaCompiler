
#ifndef JAVACOMPILER_THISEXPRESSION_H
#define JAVACOMPILER_THISEXPRESSION_H

#include "Expression.h"

class ThisExpression : public Expression
{
  public:
    explicit ThisExpression(yy::location loc);
    void Accept(Visitor *visitor) override;
    std::variant<int, std::string> eval() const override;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_THISEXPRESSION_H
