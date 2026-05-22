
#include "FalseExpression.h"

FalseExpression::FalseExpression(yy::location loc) : Expression(loc) {}

std::variant<int, std::string> FalseExpression::eval() const { return 0; }

void FalseExpression::Accept(Visitor *visitor) { visitor->Visit(this); }

Type FalseExpression::EvalType(ScopeLayer *scope) { return Type("bool"); }
