#pragma once
#include "Expressions/Expression.h"
#include "Statement.h"
#ifndef JAVACOMPILER_ASSERT_H
#define JAVACOMPILER_ASSERT_H

class Assert : public Statement
{
  public:
    Assert(Expression *expr, yy::location loc);
    void Accept(Visitor *visitor) override;

    Expression *expr;
};

#endif // JAVACOMPILER_ASSERT_H
