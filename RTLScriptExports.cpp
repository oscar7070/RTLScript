// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#include "RTLScript.h"
#include "RTLScriptExports.h"

const char* RTLScriptConvertToFixed(const char* text, RTLScriptConverterProperties* properties)
{
    return RTLScript::ConvertToFixed(text, properties);
}
