#include "Formal.h"
#include "Visitors/Visitor.h"
#include <utility>

Formal::Formal(Type type, std::string name, yy::location loc)
    : type(std::move(type)), name(std::move(name)), BaseElement(loc)
{
}

void Formal::Accept(Visitor *visitor) { visitor->Visit(this); }
