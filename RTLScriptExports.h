// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#pragma once

#include <string>

#ifdef RTLSCRIPT_EXPORTS
#define RTLSCRIPT_API __declspec(dllexport)
#else
#define RTLSCRIPT_API __declspec(dllimport)
#endif

extern "C" RTLSCRIPT_API std::string RTLScriptConvertToFixed(const std::string & text);
