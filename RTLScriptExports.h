// RTLType is a fork for FarsiType: https://github.com/AmyrAhmady/FarsiType
#pragma once

#include <string>

#ifdef RTLTYPE_EXPORTS
#define RTLTYPE_API __declspec(dllexport)
#else
#define RTLTYPE_API __declspec(dllimport)
#endif

extern "C" RTLTYPE_API std::string ConvertToFixed(const std::string & text);
