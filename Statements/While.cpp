
#include "While.h"

While::While(Expression *expr, Statement *statement, yy::location loc)
    : expr(expr), statement(statement), Statement(loc)
{
}

void While::Accept(Visitor *visitor) { visitor->Visit(this); }
