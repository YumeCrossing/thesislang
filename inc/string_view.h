// Thesis language
//
// Copyright (c) 2024, Yume Crossing
// All rights reserved.
#ifndef _Thesis_StringView
#define _Thesis_StringView

#include "thesis.h"

#if __cplusplus >= 201703L
#   include <string_view>
#   define _THESIS_STRING_VIEW_NAMESPACE std
#else
#   include <fmt/base.h>
#   define _THESIS_STRING_VIEW_NAMESPACE fmt
#endif

namespace thesis
{

using string_view = _THESIS_STRING_VIEW_NAMESPACE::string_view;

} // namespace thesis

#undef _THESIS_STRING_VIEW_NAMESPACE
#endif
