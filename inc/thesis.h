// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#ifndef _Thesis_Header
#define _Thesis_Header

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

#define APP_NAME "Thesis interpreter"
#define APP_VERSION "0.0.2" // Sync with `version`
#define APP_BUILD_BY "[C++" THESIS_ISO_CPP "]"
#define TARGET_NAME "thesis"

#endif
