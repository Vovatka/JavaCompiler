#ifndef JAVACOMPILER_STARGUMENT_H
#define JAVACOMPILER_STARGUMENT_H

#include "BaseSymbol.h"
#include <Statements/Formal.h>

class STArgument : public BaseSymbol
{
  public:
    explicit STArgument(Formal *argument);
    Type type;
};

#endif // JAVACOMPILER_STARGUMENT_H
