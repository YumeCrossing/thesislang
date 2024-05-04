// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#ifndef _Thesis_CLI
#define _Thesis_CLI

#include <iostream> // for std::istream
#include <string> // for std::string

namespace thesis
{

class REPL final
{

std::string line {};
std::string prompt {'>'};

public:

std::istream& input();

void run();

};

} // namespace thesis


#endif
