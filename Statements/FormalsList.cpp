#include "FormalsList.h"
#include "Visitors/Visitor.h"

FormalsList::FormalsList(yy::location loc) : BaseElement(loc) {}

void FormalsList::AddFormal(Formal *formal) { formals.push_back(formal); }

void FormalsList::Accept(Visitor *visitor) { visitor->Visit(this); }
