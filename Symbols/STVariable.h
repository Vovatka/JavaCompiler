#ifndef JAVACOMPILER_STVARIABLE_H
#define JAVACOMPILER_STVARIABLE_H

#include "BaseSymbol.h"
#include "Type.h"
#include <Statements/VarDeclaration.h>

class STVariable : public BaseSymbol
{
  public:
    explicit STVariable(const std::string &name, Type type = Type("int"));
    explicit STVariable(VarDeclaration *var_decl);

    Type type;
};

namespace std
{
template <> struct hash<STVariable>
{
    std::size_t operator()(const STVariable &other) const
    {
        return hash<string>()(other.GetName());
    }
};
} // namespace std

#endif // JAVACOMPILER_STVARIABLE_H
