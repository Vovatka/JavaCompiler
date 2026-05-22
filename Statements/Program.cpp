
#include "Program.h"

void Program::Accept(Visitor *visitor) { visitor->Visit(this); }

Program::Program(MainClass *main_class, ClassDeclarationList *class_decls,
                 yy::location loc)
    : main_class(main_class), class_declarations(class_decls), Statement(loc)
{
}
