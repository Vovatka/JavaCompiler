#ifndef JAVACOMPILER_BOOL_H
#define JAVACOMPILER_BOOL_H

#include "Object.h"

class Bool : public Object
{
  public:
    explicit Bool(bool value);
    int ToInt() override;

  private:
    bool value_;
};

#endif // JAVACOMPILER_BOOL_H
