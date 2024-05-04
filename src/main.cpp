// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.

#include <string> // for std::string
#include <fmt/base.h> // for fmt::format, fmt::print(ln), fmt::string_view

#include "CLI.h"

#if __cplusplus < 201402L
#    error "There is no support for C++11 at now."
#elif __cplusplus == 201402L
#    define THESIS_ISO_CPP "14"
#elif __cplusplus == 201703L
#    define THESIS_ISO_CPP "17"
#elif __cplusplus == 202002L
#    define THESIS_ISO_CPP "20"
#elif __cplusplus == 202302L
#   define THESIS_ISO_CPP "23"
#endif


namespace thesis
{

using std::string;
using fmt::string_view;

} // namespace thesis


#define APP_NAME "Thesis interpreter"
#define APP_VERSION "0.0.1" // Sync with `version`
#define APP_BUILD_BY "[C++" THESIS_ISO_CPP "]"

constexpr auto title(APP_NAME " " APP_VERSION " @(" __DATE__ ", " __TIME__ ") " APP_BUILD_BY);

int main()
{
    using namespace thesis;

    fmt::println(title);
    fmt::println("Type \"exit\" to exit.");
    
    REPL loop;
    loop.run();
}
