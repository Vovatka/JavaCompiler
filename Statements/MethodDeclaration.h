#ifndef JAVACOMPILER_METHODDECLARATION_H
#define JAVACOMPILER_METHODDECLARATION_H

#include "FormalsList.h"
#include "Statement.h"
#include "StatementList.h"
#include <Symbols/Type.h>
#include <vector>

class MethodDeclaration : public Statement
{
  public:
    MethodDeclaration(std::string method_name, Type return_type,
                      FormalsList *formals, StatementList *statements,
                      yy::location loc);

    void Accept(Visitor *visitor) override;

    std::string method_name;
    Type return_type;
    FormalsList *formals;
    StatementList *statements;
};

#endif // JAVACOMPILER_METHODDECLARATION_H
