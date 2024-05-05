// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#include "CLI.h"

#include <string> // for std::string, std::getline
#include <iostream> // for std::cin
#include <fmt/base.h> // for fmt::print

using fmt::print;
using fmt::println;

namespace thesis
{

std::istream& REPL::input()
{
    using std::getline, std::cin;

    print("{} ", prompt);
    return getline(cin, line);
}

void REPL::run()
{
    println("{}", app_title);
    println("Type \"exit\" to exit.");
    // The interactive mode
    while (input() && line != "exit");
    exit(0);
}

void CLI::parse(int argc, const char** argv) noexcept
{
    // The executable file path
    executable_path = argv[0];
    argc--;

    // Convert `const char**` to `std::vector<string_view>`.
    for (int i = 0;argc > 0;argc--,i++)
        args.push_back({argv[i+1]});
}

void CLI::execute()
{
    // If there is no arguments, launch interactive mode.
    if (args.size() == 0)
        return loop.run();

    for (auto arg: args)
    {
        if (arg == "--help" || arg == "-h")
            exit(printHelp());  // Reserved for further `--help` extension.
        else if (arg == "--version" || arg == "-v")
            exit((printVersion(), 0));
        else
            printUnknownArg(arg);
    }
}

int CLI::printHelp() noexcept
{
    println("usage: {} [options] [script]\n"
    "The program is an interpreter of Thesis.",
    TARGET_NAME);
    return 0;
}

void CLI::printVersion() noexcept
{
    println("{}", app_title);
}

void CLI::printUnknownArg(string_view arg) noexcept
{
    println("error: Unknown argument \"{}\" appeared.\n", arg);
    printHelp();
    exit(-1);
}

} // namespace thesis
