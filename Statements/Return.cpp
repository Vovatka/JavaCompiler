#include "Return.h"

void Return::Accept(Visitor *visitor) { visitor->Visit(this); }

Return::Return(Expression *expr, yy::location loc) : expr(expr), Statement(loc)
{
}
