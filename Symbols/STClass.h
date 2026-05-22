#ifndef JAVACOMPILER_STCLASS_H
#define JAVACOMPILER_STCLASS_H

#include "BaseSymbol.h"
#include "STMethod.h"
#include "STVariable.h"
#include <Statements/ClassDeclaration.h>
#include <vector>

class STClass : public BaseSymbol
{
  public:
    const STVariable *FindFieldByName(const std::string &name) const;

    const STMethod *FindMethodByName(const std::string &name) const;

    explicit STClass(ClassDeclaration *class_);

    Type GetType() const;

    std::unordered_map<std::string, STVariable> fields;

    std::string base_class_name = "";

  private:
    Type type;
    std::unordered_map<std::string, STMethod> methods_;
};

#endif // JAVACOMPILER_STCLASS_H
