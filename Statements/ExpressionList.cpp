
#include "ExpressionList.h"

ExpressionList::ExpressionList(yy::location loc) : Statement(loc) {}

void ExpressionList::Accept(Visitor *visitor) { visitor->Visit(this); }

void ExpressionList::AddExpression(Expression *expr)
{
    expressions.push_back(expr);
}
