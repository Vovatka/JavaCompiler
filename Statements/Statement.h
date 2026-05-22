#ifndef JAVACOMPILER_KETWORD_H
#define JAVACOMPILER_KETWORD_H

#include "Bases/BaseElement.h"

class Statement : public BaseElement
{
  public:
    explicit Statement(yy::location loc);
};

#endif // JAVACOMPILER_KETWORD_H
