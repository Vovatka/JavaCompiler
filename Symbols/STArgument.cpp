#include "STArgument.h"

STArgument::STArgument(Formal *argument)
    : type(argument->type), BaseSymbol(argument->name)
{
}
