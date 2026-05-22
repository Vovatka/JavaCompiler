#ifndef JAVACOMPILER_ALLOCEXPRESSION_H
#define JAVACOMPILER_ALLOCEXPRESSION_H

#include "Expression.h"
#include "Symbols/Type.h"

class AllocExpression : public Expression
{
  public:
    AllocExpression(Type type, Expression *size_expr, yy::location loc);

    std::variant<int, std::string> eval() const override;

    Type type;
    Expression *size_expr;

    void Accept(Visitor *visitor) override;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_ALLOCEXPRESSION_H
