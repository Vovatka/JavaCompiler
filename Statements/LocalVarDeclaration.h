
#ifndef JAVACOMPILER_LOCALVARDECLARATION_H
#define JAVACOMPILER_LOCALVARDECLARATION_H

#include "VarDeclaration.h"

class LocalVarDeclaration : public VarDeclaration
{
  public:
    LocalVarDeclaration(Type type, std::string var_name, yy::location loc);
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_LOCALVARDECLARATION_H
