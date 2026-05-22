#ifndef JAVACOMPILER_FORMALSLIST_H
#define JAVACOMPILER_FORMALSLIST_H

#include "Formal.h"
#include <Bases/BaseElement.h>
#include <vector>

class FormalsList : public BaseElement
{
  public:
    FormalsList(yy::location loc);
    void AddFormal(Formal *formal);
    void Accept(Visitor *visitor) override;

    std::vector<Formal *> formals;
};

#endif // JAVACOMPILER_FORMALSLIST_H
