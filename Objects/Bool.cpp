#include "Bool.h"

Bool::Bool(bool value) : value_(value) {}

int Bool::ToInt() { return static_cast<int>(value_); }
