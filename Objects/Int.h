#ifndef JAVACOMPILER_INT_H
#define JAVACOMPILER_INT_H

#include "Object.h"

class Int : public Object
{
  public:
    explicit Int(int value);
    int ToInt() override;

  private:
    int value_;
};

#endif // JAVACOMPILER_INT_H
