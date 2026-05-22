#include "Print.h"

void Print::Accept(Visitor *visitor) { visitor->Visit(this); }

Print::Print(Expression *expr, yy::location loc) : expr(expr), Statement(loc) {}
