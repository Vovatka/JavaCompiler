#ifndef JAVACOMPILER_STMETHOD_H
#define JAVACOMPILER_STMETHOD_H

#include "BaseSymbol.h"
#include "STArgument.h"
#include "Statements/MethodDeclaration.h"
#include "Type.h"
#include <string>
#include <vector>

class STMethod : public BaseSymbol
{
  public:
    explicit STMethod(MethodDeclaration *method);
    Type return_type;
    Statement *method_body;
    std::vector<STArgument> arguments;
};

#endif // JAVACOMPILER_STMETHOD_H
