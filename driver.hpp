#pragma once
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "Visitors/PrintVisitor.h"
#include "Visitors/SymbolTreeVisitor.h"
#include "parser.hpp"
#include "scanner.hpp"

class Driver
{
  public:
    Driver();

    std::map<std::string, int> variables;

    int parse(const std::string &filename);
    std::string file;
    bool trace_parsing;
    bool trace_scanning;
    yy::location loc;

    friend class Scanner;

    Scanner scanner;
    yy::parser parser;

    Program *program = nullptr;
    void print_tree(const std::string &filename) const;
    int run();
};
