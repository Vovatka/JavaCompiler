
#ifndef JAVACOMPILER_LOGICALOREXPRESSION_H
#define JAVACOMPILER_LOGICALOREXPRESSION_H

#include <Expressions/BinaryExpression/LogicalExpression/LogicalExpression.h>
#include <variant>

class LogicalOrExpression : public LogicalExpression
{
  public:
    LogicalOrExpression(Expression *expr1, Expression *expr2, yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_LOGICALOREXPRESSION_H
