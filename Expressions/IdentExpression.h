
#ifndef JAVACOMPILER_IDENTEXPRESSION_H
#define JAVACOMPILER_IDENTEXPRESSION_H

#include "Expressions/Expression.h"
#include <string>

class IdentExpression : public Expression
{
  public:
    explicit IdentExpression(std::string &var_name, yy::location loc);
    void Accept(Visitor *visitor) override;
    std::variant<int, std::string> eval() const override;
    std::string var_name;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_IDENTEXPRESSION_H
