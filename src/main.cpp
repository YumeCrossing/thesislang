// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#include "thesis.h"
#include "CLI.h"

int main(int argc, const char** argv)
{
    using namespace thesis;
    CLI app
    ({
        {"--help", "-h", "", "Print help message and exit."},
        {"--version", "-v", "", "Print current version and exit."}
    }, {});
    app.parse(argc, argv);
    app.execute();
}
