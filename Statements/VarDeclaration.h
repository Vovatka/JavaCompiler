#include "Statement.h"
#include <Symbols/Type.h>
#include <string>

#ifndef JAVACOMPILER_VARDECLARATION_H
#define JAVACOMPILER_VARDECLARATION_H

class VarDeclaration : public Statement
{
  public:
    VarDeclaration(Type type, std::string var_name, yy::location loc);
    std::string var_name;
    Type type;
};

#endif // JAVACOMPILER_VARDECLARATION_H
