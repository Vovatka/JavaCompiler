
#include "DivExpression.h"
#include <variant>

DivExpression::DivExpression(Expression *expr1, Expression *expr2,
                             yy::location loc)
    : ArithmeticExpression(expr1, expr2, loc)
{
}

std::variant<int, std::string> DivExpression::eval() const
{
    return std::get<int>(expr1->eval()) / std::get<int>(expr2->eval());
}

void DivExpression::Accept(Visitor *visitor) { visitor->Visit(this); }