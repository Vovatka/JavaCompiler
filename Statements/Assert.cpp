#include "Assert.h"

Assert::Assert(Expression *expr, yy::location loc) : expr(expr), Statement(loc)
{
}

void Assert::Accept(Visitor *visitor) { visitor->Visit(this); }
