
#include "GreaterExpression.h"
#include <variant>

GreaterExpression::GreaterExpression(Expression *expr1, Expression *expr2,
                                     yy::location loc)
    : ComparisonExpression(expr1, expr2, loc)
{
}

std::variant<int, std::string> GreaterExpression::eval() const
{
    return expr1->eval() > expr2->eval();
}

void GreaterExpression::Accept(Visitor *visitor) { visitor->Visit(this); }