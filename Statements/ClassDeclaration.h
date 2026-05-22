#ifndef JAVACOMPILER_CLASSDECLARATION_H
#define JAVACOMPILER_CLASSDECLARATION_H

#include "Statement.h"
#include <Visitors/Visitor.h>

class ClassDeclaration : public Statement
{
  public:
    ClassDeclaration(const std::string &class_name,
                     const std::string &base_class_name,
                     DeclarationList *decl_list, yy::location loc);

    void Accept(Visitor *visitor) override;

    std::string class_name;
    std::string base_class_name = "";
    DeclarationList *declaration_list;
};

#endif // JAVACOMPILER_CLASSDECLARATION_H
