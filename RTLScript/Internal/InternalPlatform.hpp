#pragma once

#ifdef RTL_SCRIPT_PLATFORM_WINDOWS
#ifdef RTL_SCRIPT_EXPORTS
#define RTL_SCRIPT_API __declspec(dllexport)
#else
#define RTL_SCRIPT_API __declspec(dllimport)
#endif
#else
#define RTL_SCRIPT_API
#endif

#define RTL_SCRIPT_SELECTANY_API extern __declspec(selectany)