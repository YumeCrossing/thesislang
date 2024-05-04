// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#include "CLI.h"

#include <string> // for std::string, std::getline
#include <iostream> // for std::cin
#include <fmt/base.h> // for fmt::print

namespace thesis
{

std::istream& REPL::input()
{
    using fmt::print;
    using std::getline, std::cin;

    print("{} ", prompt);
    return getline(cin, line);
}

void REPL::run()
{
    while (input() && line != "exit");
    exit(0);
}

} // namespace thesis
