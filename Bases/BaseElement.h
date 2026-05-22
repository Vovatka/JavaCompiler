#ifndef JAVACOMPILER_BASEELEMENT_H
#define JAVACOMPILER_BASEELEMENT_H

#include "location.hh"
#include <variant>

class Visitor;
class ScopeLayer;

class BaseElement
{
  public:
    yy::location loc;
    virtual void Accept(Visitor *visitor) = 0;
    explicit BaseElement(yy::location loc) : loc(loc){};
    virtual ~BaseElement() = default;
};

#endif // JAVACOMPILER_BASEELEMENT_H
