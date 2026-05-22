
#include "Statement.h"
#include "StatementList.h"
#include <queue>
#ifndef JAVACOMPILER_MAINCLASS_H
#define JAVACOMPILER_MAINCLASS_H

class MainClass : public Statement
{
  public:
    MainClass(StatementList *statements, yy::location loc);
    void Accept(Visitor *visitor) override;
    StatementList *statements;
};

#endif // JAVACOMPILER_MAINCLASS_H
