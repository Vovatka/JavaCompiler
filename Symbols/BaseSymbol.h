#ifndef JAVACOMPILER_BASESYMBOL_H
#define JAVACOMPILER_BASESYMBOL_H

#include <memory>
#include <string>
#include <unordered_map>

class BaseSymbol
{
  public:
    bool operator==(const BaseSymbol &other) const;
    bool operator!=(const BaseSymbol &other) const;
    std::string GetName() const;
    explicit BaseSymbol(const std::string &name);

  private:
    std::string name_;
};

namespace std
{
template <> struct hash<BaseSymbol>
{
    std::size_t operator()(const BaseSymbol &other) const
    {
        return hash<string>()(other.GetName());
    }
};

} // namespace std

#endif // JAVACOMPILER_BASESYMBOL_H
