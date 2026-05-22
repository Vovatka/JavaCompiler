#ifndef JAVACOMPILER_SCOPELAYERTREE_H
#define JAVACOMPILER_SCOPELAYERTREE_H

#include "ScopeLayer.h"

class ScopeLayerTree
{
  public:
    explicit ScopeLayerTree(ScopeLayer *root);

  public:
    ScopeLayer *root_;
};

#endif // JAVACOMPILER_SCOPELAYERTREE_H
