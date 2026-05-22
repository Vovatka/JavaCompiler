
#include "ClassDeclaration.h"
#include "Statement.h"
#include <queue>
#ifndef JAVACOMPILER_PROGRAM_H
#define JAVACOMPILER_PROGRAM_H

class Program : public Statement
{
  public:
    explicit Program(MainClass *main_class, ClassDeclarationList *class_decls,
                     yy::location loc);
    void Accept(Visitor *visitor) override;
    MainClass *main_class;
    ClassDeclarationList *class_declarations;
};

#endif // JAVACOMPILER_PROGRAM_H
