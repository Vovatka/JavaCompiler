
#ifndef JAVACOMPILER_CLASSDECLARATIONLIST_H
#define JAVACOMPILER_CLASSDECLARATIONLIST_H

#include "ClassDeclaration.h"
#include "Statement.h"
#include <vector>

class ClassDeclarationList : public Statement
{
  public:
    ClassDeclarationList(yy::location loc);
    void Accept(Visitor *visitor) override;
    void AddClassDeclaration(ClassDeclaration *class_declaration);

    std::vector<ClassDeclaration *> class_declarations;
};

#endif // JAVACOMPILER_CLASSDECLARATIONLIST_H
