
#include "Expressions/Expression.h"
#include "Statement.h"
#include <string>
#ifndef JAVACOMPILER_VARASSIGNMENT_H
#define JAVACOMPILER_VARASSIGNMENT_H

class VarAssignment : public Statement
{
  public:
    VarAssignment(Expression *var_name, Expression *new_value,
                  yy::location loc);
    void Accept(Visitor *visitor) override;
    Expression *var_name;
    Expression *new_value;
};

#endif // JAVACOMPILER_VARASSIGNMENT_H
