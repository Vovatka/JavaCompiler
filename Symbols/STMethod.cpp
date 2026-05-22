#include "STMethod.h"
#include "Statements/FormalsList.h"
#include <Statements/MethodDeclaration.h>

STMethod::STMethod(MethodDeclaration *method)
    : BaseSymbol(method->method_name), return_type(method->return_type),
      method_body(method->statements)
{
    for (Formal *argument : method->formals->formals)
    {
        arguments.emplace_back(argument);
    }
}
