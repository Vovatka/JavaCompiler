
#include "TrueExpression.h"
#include <variant>

TrueExpression::TrueExpression(yy::location loc) : Expression(loc) {}

std::variant<int, std::string> TrueExpression::eval() const { return true; }

void TrueExpression::Accept(Visitor *visitor) { visitor->Visit(this); }

Type TrueExpression::EvalType(ScopeLayer *scope) { return Type("bool"); }
