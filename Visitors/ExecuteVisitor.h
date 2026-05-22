#ifndef JAVACOMPILER_EXECUTEVISITOR_H
#define JAVACOMPILER_EXECUTEVISITOR_H

#include "Visitor.h"
#include <Symbols/PhysicalVariable.h>

class ExecuteVisitor : public Visitor
{
  public:
    void Visit(Program *program) override;

    void Visit(MainClass *main_class) override;

    void Visit(StatementList *statements) override;

    void Visit(ClassDeclaration *class_declaration) override;

    void Visit(ClassDeclarationList *class_declaration_list) override;

    void Visit(DeclarationList *statement) override;

    void Visit(Assert *statement) override;

    void Visit(MethodDeclaration *statement) override;

    void Visit(IfElse *statement) override;

    void Visit(While *statement) override;

    void Visit(VarAssignment *statement) override;

    void Visit(Formal *formal) override;

    void Visit(FormalsList *formals_list) override;

    void Visit(Print *statement) override;

    void Visit(Return *statement) override;

    void Visit(ExpressionList *statement) override;

    void Visit(ScopeBlock *statement) override;

    void Visit(MethodInvocation *statement) override;

    void Visit(FieldDeclaration *statement) override;

    void Visit(LocalVarDeclaration *statement) override;

    void Visit(IdentExpression *expression) override;

    void Visit(NumExpression *expression) override;

    void Visit(AddExpression *expression) override;

    void Visit(SubExpression *expression) override;

    PhysicalVariable::PtrType GetRes() const;

    void Visit(MulExpression *expression) override;

    void Visit(DivExpression *expression) override;

    void Visit(ModExpression *expression) override;

    void Visit(IndexExpression *expression) override;

    void Visit(LogicalAndExpression *expression) override;

    void Visit(LogicalOrExpression *expression) override;

    void Visit(GreaterExpression *expression) override;

    void Visit(LessExpression *expression) override;

    void Visit(NotExpression *expression) override;

    void Visit(TrueExpression *expression) override;

    void Visit(FalseExpression *expression) override;

    void Visit(EqualExpression *expression) override;

    void Visit(ThisExpression *expression) override;

    void Visit(LengthExpression *expression) override;

    void Visit(FieldInvokeExpression *expression) override;

    void Visit(AllocExpression *expression) override;

  private:
    bool returning_ = false;
    std::stack<size_t> frame_pointer;
    PhysicalVariable::PtrType rax_;
    std::vector<PhysicalVariable::PtrType> stack_;
};

#endif // JAVACOMPILER_EXECUTEVISITOR_H
