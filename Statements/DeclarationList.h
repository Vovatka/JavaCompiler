#ifndef JAVACOMPILER_DECLARATIONS_H
#define JAVACOMPILER_DECLARATIONS_H

#include "FieldDeclaration.h"
#include "MethodDeclaration.h"
#include "Statement.h"
#include <variant>
#include <vector>

class DeclarationList : public Statement
{
  public:
    using var_method_decl_t =
        std::variant<FieldDeclaration *, MethodDeclaration *>;
    DeclarationList(yy::location loc);
    void AddDeclaration(var_method_decl_t decl);

    std::vector<var_method_decl_t> declarations;

    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_DECLARATIONS_H
