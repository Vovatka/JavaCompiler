
#ifndef JAVACOMPILER_INDEXEXPRESSION_H
#define JAVACOMPILER_INDEXEXPRESSION_H

#include "Expression.h"

class IndexExpression : public Expression
{
  public:
    IndexExpression(Expression *inner, Expression *outer, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;

  private:
    Type EvalType(ScopeLayer *scope) override;

  public:
    Expression *inner;
    Expression *outer;
};

#endif // JAVACOMPILER_INDEXEXPRESSION_H
