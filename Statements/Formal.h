#ifndef JAVACOMPILER_FORMAL_H
#define JAVACOMPILER_FORMAL_H

#include <Bases/BaseElement.h>
#include <Symbols/Type.h>

class Formal : public BaseElement
{
  public:
    explicit Formal(Type type, std::string name, yy::location loc);
    void Accept(Visitor *visitor) override;
    std::string name;
    Type type;
};

#endif // JAVACOMPILER_FORMAL_H
