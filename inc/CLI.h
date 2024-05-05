// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#ifndef _Thesis_CLI
#define _Thesis_CLI

#include "thesis.h"
#include "string_view.h" // for thesis::string_view

#include <iostream> // for std::istream
#include <string> // for std::string
#include <vector> // for std::vector

namespace thesis
{

// TODO: `__DATE__` has two blanks between the month and the day but expected to be one.
constexpr auto app_title(APP_NAME " " APP_VERSION " @(" __DATE__ ", " __TIME__ ") " APP_BUILT_BY);

class Option final
{
private:
    const char* name; // The parameter name
    const char* abbr; // The abbreviated parameter name
    const char* opt; // The optional args
    const char* details; // The detailed information

public:
    Option(const char* name, const char* abbr, const char* opt, const char* details) noexcept:
        name(name), abbr(abbr), opt(opt), details(details) {}
};

class REPL final
{
private:
    std::string line {};
    std::string prompt {'>'};

public:
    REPL() noexcept {}
    std::istream& input();
    void run();

};

class CLI final
{
public:
    using Args = std::vector<string_view>;

private:
    Args args; // The parsed `argv`
    std::vector<Option> opts; // The options
    REPL loop; // The read-eval-print-loop
    const char* executable_path; // The executable file path

public:
    CLI(std::initializer_list<Option> opts, REPL loop) noexcept: opts(opts), loop(loop), args {} {}
    void parse(int argc, const char** argv) noexcept;
    void execute();

    int printHelp() noexcept;
    void printVersion() noexcept;
    void printUnknownArg(string_view) noexcept;
};

} // namespace thesis

#endif
