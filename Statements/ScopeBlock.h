#ifndef JAVACOMPILER_SCOPEBLOCK_H
#define JAVACOMPILER_SCOPEBLOCK_H

#include "Statement.h"
#include <Statements/StatementList.h>

class ScopeBlock : public Statement
{
  public:
    explicit ScopeBlock(StatementList *statements, yy::location loc);
    void Accept(Visitor *visitor) override;
    StatementList *statements;
};

#endif // JAVACOMPILER_SCOPEBLOCK_H
