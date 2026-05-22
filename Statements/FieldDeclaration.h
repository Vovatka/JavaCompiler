#ifndef JAVACOMPILER_FIELDDECLARATION_H
#define JAVACOMPILER_FIELDDECLARATION_H

#include "VarDeclaration.h"

class FieldDeclaration : public VarDeclaration
{
  public:
    FieldDeclaration(Type type, std::string field_name, yy::location loc);
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_FIELDDECLARATION_H
