
#ifndef JAVACOMPILER_LOGICALANDEXPRESSION_H
#define JAVACOMPILER_LOGICALANDEXPRESSION_H

#include <Expressions/BinaryExpression/LogicalExpression/LogicalExpression.h>
#include <variant>

class LogicalAndExpression : public LogicalExpression
{
  public:
    LogicalAndExpression(Expression *expr1, Expression *expr2,
                         yy::location loc);
    std::variant<int, std::string> eval() const override;
    void Accept(Visitor *visitor) override;
};

#endif // JAVACOMPILER_LOGICALANDEXPRESSION_H
