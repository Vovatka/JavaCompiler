
#ifndef JAVACOMPILER_METHODINVOCATION_H
#define JAVACOMPILER_METHODINVOCATION_H

#include "Expressions/Expression.h"
#include "Statement.h"
#include <string>

class MethodInvocation : public Statement, public Expression
{
  public:
    explicit MethodInvocation(Expression *expr, std::string name,
                              ExpressionList *args, yy::location loc);
    void Accept(Visitor *visitor) override;
    std::variant<int, std::string> eval() const override;
    Expression *class_expr;
    std::string method_name;
    ExpressionList *arguments;

  private:
    Type EvalType(ScopeLayer *scope) override;
};

#endif // JAVACOMPILER_METHODINVOCATION_H
