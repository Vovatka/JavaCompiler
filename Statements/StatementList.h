#ifndef JAVACOMPILER_STATEMENTS_H
#define JAVACOMPILER_STATEMENTS_H

#include "Statement.h"
#include <vector>

class StatementList : public Statement
{
  public:
    StatementList(yy::location loc);
    void AddStatement(Statement *statement);
    void Accept(Visitor *visitor) override;

    std::vector<Statement *> statements;
};

#endif // JAVACOMPILER_STATEMENTS_H
