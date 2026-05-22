

#ifndef JAVACOMPILER_FIELDINVOCATIONEXPRESSION_H
#define JAVACOMPILER_FIELDINVOCATIONEXPRESSION_H

#include "Expression.h"
#include <string>

class FieldInvokeExpression : public Expression
{
  public:
    FieldInvokeExpression(const std::string &field_name, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;

    std::string field_name;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_FIELDINVOCATIONEXPRESSION_H
