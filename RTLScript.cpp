// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#include "RTLScript.h"

#include <sstream>

ArabicLetterForm RTLScript::GetARCharPlace(const std::string prevARChar, const std::string nextARChar)
{
    bool in_previous = false, in_next = false;
    for (auto const& arChar : Ar_AlphabetAllLetters)
    {
        if (prevARChar != RTLSCRIPT_NOT_AR_CHAR || arChar[AR_FORMS_UNICODE] == prevARChar)
            in_previous = true;
        if (nextARChar != RTLSCRIPT_NOT_AR_CHAR || arChar[AR_FORMS_UNICODE] == nextARChar)
            in_next = true;
    }

    if (in_previous && in_next)
        return AR_FORMS_MEDIUM;
    if (in_next)
        return AR_FORMS_BEGINNER;
    if (in_previous)
        return AR_FORMS_FINAL;
    else
        return AR_FORMS_ISOLATED;
}

bool RTLScript::IsArCharBeginner(const std::string arCharacter)
{
    return arCharacter == Ar_AlphabetAllLetters[AR_ALIF_HAMZA_ABOVE][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_ALIF_MADDAH_ABOVE][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_ALIF][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_HAMZA][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_WAW_HAMZA_ABOVE][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_ALIF_HAMZA_BELOW][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_DAAL][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_THAAL][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_REH][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_ZAIN][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_EXT_FA_JEH][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_WAW][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[AR_ALIF_MAKSURA][AR_FORMS_UNICODE];
}

size_t RTLScript::FindARCharIndex(const std::string arCharacter)
{
    for (int i = 0; i < Ar_AlphabetAllLettersLength; i++)
        if (arCharacter == Ar_AlphabetAllLetters[i][AR_FORMS_UNICODE] ||
            arCharacter == Ar_AlphabetAllLetters[i][AR_FORMS_ISOLATED] ||
            arCharacter == Ar_AlphabetAllLetters[i][AR_FORMS_BEGINNER] ||
            arCharacter == Ar_AlphabetAllLetters[i][AR_FORMS_MEDIUM] ||
            arCharacter == Ar_AlphabetAllLetters[i][AR_FORMS_FINAL])
            return i;
        else continue;
    return Ar_AlphabetAllLettersLength;
}

bool RTLScript::IsARChar(const std::string arCharacter)
{
    for (auto const& arChar : Ar_AlphabetAllLetters)
        if (arCharacter == arChar[AR_FORMS_UNICODE] ||
            arCharacter == arChar[AR_FORMS_ISOLATED] ||
            arCharacter == arChar[AR_FORMS_BEGINNER] ||
            arCharacter == arChar[AR_FORMS_MEDIUM] ||
            arCharacter == arChar[AR_FORMS_FINAL])
            return true;
        else continue;
    return false;
}

bool RTLScript::CheckForARChar(const std::string arCharacter, ArabicAlphabet checkFor)
{
    if (arCharacter == Ar_AlphabetAllLetters[checkFor][AR_FORMS_UNICODE] ||
        arCharacter == Ar_AlphabetAllLetters[checkFor][AR_FORMS_ISOLATED] ||
        arCharacter == Ar_AlphabetAllLetters[checkFor][AR_FORMS_BEGINNER] ||
        arCharacter == Ar_AlphabetAllLetters[checkFor][AR_FORMS_MEDIUM] ||
        arCharacter == Ar_AlphabetAllLetters[checkFor][AR_FORMS_FINAL])
        return true;
    return false;
}

int RTLScript::GetCodepointFromString(const std::string str)
{
    if (str.empty()) return -1;

    const unsigned char u0 = str[0];
    if (u0 >= 0 && u0 <= 127) return u0; // ASCII

    if ((u0 & 0xE0) == 0xC0) {
        const unsigned char u1 = str[1] & 0x3F;
        return ((u0 & 0x1F) << 6) | u1;
    }
    if ((u0 & 0xF0) == 0xE0) {
        const unsigned char u1 = str[1] & 0x3F, u2 = str[2] & 0x3F;
        return ((u0 & 0x0F) << 12) | (u1 << 6) | u2;
    }
    if ((u0 & 0xF8) == 0xF0) {
        const unsigned char u1 = str[1] & 0x3F, u2 = str[2] & 0x3F, u3 = str[3] & 0x3F;
        return ((u0 & 0x07) << 18) | (u1 << 12) | (u2 << 6) | u3;
    }
    return -1; // Error
}

bool RTLScript::IsRTL(const int codepoint)
{
    // Arabic (0600–06FF), Hebrew (0590–05FF), Farsi, Urdu and etc.
    return (codepoint >= 0x0590 && codepoint <= 0x08FF) || (codepoint >= 0xFB1D && codepoint <= 0xFEFC);
}

bool RTLScript::IsPunctOrDigit(const int c)
{
    return std::ispunct(c) || std::isdigit(c);
}

std::vector<std::string> RTLScript::ReverseRTLText(const std::string str)
{
    std::vector<std::string> reversedStr;

    std::istringstream wif(str);
    std::string line;

    bool isFirstLine = true;

    while (std::getline(wif, line))
    {
        if (!isFirstLine)
            reversedStr.emplace(reversedStr.end(), std::string() + "\n");

        isFirstLine = false;

        std::vector<std::string> temp;
        bool rtl = false;

        ReverseRTLLine(reversedStr, line, temp, rtl);

        if (temp.size() > 0)
            reversedStr.insert(reversedStr.end(), temp.begin(), temp.end());
    }
    return reversedStr;
}

void RTLScript::ReverseRTLLine(std::vector<std::string>& reversedString, const std::string line,std::vector<std::string>& temp, bool& rtl)
{
    for (int j = 0; j < line.size(); j++)
    {
        const int codepoint = GetCodepointFromString(line.substr(j, 2));
        const bool isRTL = IsRTL(codepoint), isSpace = std::isspace(line[j]), isPunctOrDigitOrSpace = IsPunctOrDigit(line[j]) || isSpace;
        if (isRTL || rtl == true && isPunctOrDigitOrSpace)
        {
            rtl = true;
            if (isPunctOrDigitOrSpace) // To fix a char of count 1. to fix this bug: !?
                temp.emplace(temp.begin(), std::string() + line[j]);
            else
            {
                temp.emplace(temp.begin(), std::string() + line[j] + line[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(j) + 1]);
                j++;
            }
        }
        else
        {
            // Check if there a non RTL text to change the direction.
            if (!isPunctOrDigitOrSpace)
                rtl = false;

            reversedString.emplace(reversedString.end(), std::string() + line[j]);
        }
    }
}

bool RTLScript::CheckForAnyTypeOfLaamAlif(const std::string arCharacter)
{
    if (CheckForARChar(arCharacter, AR_LAAM_ALIF) || CheckForARChar(arCharacter, AR_LAAM_ALIF_HAMZA_ABOVE) ||
        CheckForARChar(arCharacter, AR_LAAM_ALIF_HAMZA_BELOW) || CheckForARChar(arCharacter, AR_LAAM_ALIF_MADDAH_ABOVE))
        return true;
    else
        return false;
}

bool RTLScript::CheckForAnyArabicDiacritic(const std::string arCharacter)
{
    for (size_t i = 0; i < Ar_TashkilAllDiacriticsLength; i++)
        if (arCharacter == Ar_TashkilAllDiacritics[i])
            return true;
    return false;
}

int RTLScript::GetPreviousCharElementIgnoringDiacritic(const std::vector<std::string> text, int element)
{
    const int outElement = element - 1;
    if (outElement < 0)
        return -1;
    else if (!CheckForAnyArabicDiacritic(text[outElement]))
        return outElement;
    else
        return GetPreviousCharElementIgnoringDiacritic(text, outElement);
}

int RTLScript::GetNextCharElementIgnoringDiacritic(const std::vector<std::string> text, int element)
{
    const int outElement = element + 1;
    if (outElement <= text.size() - 1)
    {
        if (!CheckForAnyArabicDiacritic(text[outElement]))
            return outElement;
        else
            return GetNextCharElementIgnoringDiacritic(text, outElement);
    }
    else return -1;
}

std::string RTLScript::GetARCharGlyph(const std::string arCharacter, const std::string prevARChar, const std::string nextARChar)
{
    if (!IsARChar(arCharacter)) return arCharacter;

    const unsigned char arCharPlace = GetARCharPlace(prevARChar, nextARChar);
    const size_t arCharIndex = FindARCharIndex(arCharacter);

    switch (arCharPlace)
    {
    case AR_FORMS_MEDIUM:
        if (IsArCharBeginner(prevARChar))
        {
            if (Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_BEGINNER] == Ar_AlphabetAllLetters[AR_YEH][AR_FORMS_BEGINNER])
                return Ar_AlphabetAllLetters[AR_ARABIC_YEH][AR_FORMS_BEGINNER];

            return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_BEGINNER];
        }
        if (Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_MEDIUM] == Ar_AlphabetAllLetters[AR_YEH][AR_FORMS_MEDIUM])
            return Ar_AlphabetAllLetters[AR_ARABIC_YEH][AR_FORMS_MEDIUM];

        if (CheckForAnyTypeOfLaamAlif(prevARChar))
            return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_BEGINNER];
        else
            return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_MEDIUM];
    case AR_FORMS_BEGINNER:
        if (Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_BEGINNER] == Ar_AlphabetAllLetters[AR_YEH][AR_FORMS_BEGINNER])
            return Ar_AlphabetAllLetters[AR_ARABIC_YEH][AR_FORMS_BEGINNER];

        return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_BEGINNER];
    case AR_FORMS_FINAL:
        if (IsArCharBeginner(prevARChar))
        {
            if (Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_ISOLATED] == Ar_AlphabetAllLetters[AR_YEH][AR_FORMS_ISOLATED])
                return Ar_AlphabetAllLetters[AR_ALIF_MAKSURA][AR_FORMS_ISOLATED];

            return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_ISOLATED];
        }
        if (Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_FINAL] == Ar_AlphabetAllLetters[AR_YEH][AR_FORMS_FINAL])
            return Ar_AlphabetAllLetters[AR_ALIF_MAKSURA][AR_FORMS_FINAL];

        if (CheckForAnyTypeOfLaamAlif(prevARChar))
            return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_ISOLATED];
        else
            return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_FINAL];
    default:
        if (Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_ISOLATED] == Ar_AlphabetAllLetters[AR_YEH][AR_FORMS_ISOLATED])
            return Ar_AlphabetAllLetters[AR_ALIF_MAKSURA][AR_FORMS_ISOLATED];

        return Ar_AlphabetAllLetters[arCharIndex][AR_FORMS_ISOLATED];
    }
}

/*void RTLScript::CheckForARWordAndReplace(const std::vector<ArabicAlphabets> checkFor, const std::string replaceTo, std::vector<std::string>& text)
{
    const size_t checkForSize = checkFor.size();
    const size_t size = text.size();
    for (size_t i = 0; i < size; i++)
    {
        if (i < (size - checkForSize))
        {
            bool found = false;
            for (size_t c = 0; c < checkForSize; c++)
            {
                if (CheckForARChar(text[i + c], checkFor[c]))
                {
                    found = true;
                    //break;
                }
                else
                {
                    if (found)
                    {
                        found = false;
                    }
                }
            }
            if (found)
            {
                text[i] = replaceTo;
                for (size_t c = 0; c < checkForSize; c++)
                {
                    text.erase(text.begin() + (i + c));
                }
            }
        }
        break;
    }
}*/

std::string RTLScript::ConvertToFixed(const std::string text, RTLScriptConverterProperties* properties)
{
    if (text.size() <= 1)
        return text;

    if (properties == NULL)
        properties = const_cast<RTLScriptConverterProperties*>(&DefaultConverterProperties);

    std::vector<std::string> reversed_text = ReverseRTLText(text);
    std::string convertedText, previousArChar, nextArChar;

    // Change chars to they current form for example: ل + ا = لا
    for (int i = 0; i < reversed_text.size(); i++)
    {
        const int elementPlus1 = i + 1;
        if (properties->EnableSpecialWordAllahForm && i < reversed_text.size() - 3)
            // ﷲ
             if (CheckForARChar(reversed_text[i], AR_HA) && CheckForARChar(reversed_text[elementPlus1], AR_LAAM) && CheckForARChar(reversed_text[i + 2], AR_LAAM) && CheckForARChar(reversed_text[i + 3], AR_ALIF))
             {
                 reversed_text[i] = Ar_AlphabetAllLetters[AR_ALLAH][AR_FORMS_UNICODE];
                 reversed_text.erase(reversed_text.begin() + elementPlus1, reversed_text.begin() + i + 4);
             }

        if (properties->EnableJointLaamAlifForm && i < reversed_text.size() - 1)
             // لا
             if (CheckForARChar(reversed_text[i], AR_ALIF) && CheckForARChar(reversed_text[elementPlus1], AR_LAAM))
             {
                 reversed_text[i] = Ar_AlphabetAllLetters[AR_LAAM_ALIF][AR_FORMS_UNICODE];
                 reversed_text.erase(reversed_text.begin() + elementPlus1);
             }
             
             // لأ
             if (CheckForARChar(reversed_text[i], AR_ALIF_HAMZA_ABOVE) && CheckForARChar(reversed_text[elementPlus1], AR_LAAM))
             {
                 reversed_text[i] = Ar_AlphabetAllLetters[AR_LAAM_ALIF_HAMZA_ABOVE][AR_FORMS_UNICODE];
                 reversed_text.erase(reversed_text.begin() + elementPlus1);
             }
             
             // لإ
             if (CheckForARChar(reversed_text[i], AR_ALIF_HAMZA_BELOW) && CheckForARChar(reversed_text[elementPlus1], AR_LAAM))
             {
                 reversed_text[i] = Ar_AlphabetAllLetters[AR_LAAM_ALIF_HAMZA_BELOW][AR_FORMS_UNICODE];
                 reversed_text.erase(reversed_text.begin() + elementPlus1);
             }
             
             // لآ
             if (CheckForARChar(reversed_text[i], AR_ALIF_MADDAH_ABOVE) && CheckForARChar(reversed_text[elementPlus1], AR_LAAM))
             {
                 reversed_text[i] = Ar_AlphabetAllLetters[AR_LAAM_ALIF_MADDAH_ABOVE][AR_FORMS_UNICODE];
                 reversed_text.erase(reversed_text.begin() + elementPlus1);
             }
    }

    const size_t reversedTextSize = reversed_text.size();
    for (int i = 0; i < reversedTextSize; i++) // i don't know why but if i use <size_t i = 0> it's can crash.
    {
        if (properties->JoiningArabicLetters)
        {
            if (!IsARChar(reversed_text[i]))
            {
                convertedText.append(reversed_text[i]);
                continue;
            }

            const int elementMinus1 = GetPreviousCharElementIgnoringDiacritic(reversed_text, i), elementPlus1 = GetNextCharElementIgnoringDiacritic(reversed_text, i);

            if (elementMinus1 == -1)
                previousArChar = RTLSCRIPT_NOT_AR_CHAR; // !AR is to mark that the char is not Arabic.
            else if (IsARChar(reversed_text[elementMinus1]))
                previousArChar = reversed_text[elementMinus1];
            else
                previousArChar = RTLSCRIPT_NOT_AR_CHAR;

            if (elementPlus1 == -1)
                nextArChar = RTLSCRIPT_NOT_AR_CHAR;
            else if (IsARChar(reversed_text[elementPlus1]))
                nextArChar = reversed_text[elementPlus1];
            else
                nextArChar = RTLSCRIPT_NOT_AR_CHAR;

            std::string arGlyph = GetARCharGlyph(reversed_text[i], nextArChar, previousArChar);
            convertedText.append(arGlyph);
        }
        else
            convertedText.append(reversed_text[i]);
    }
    return convertedText;
}

const char* RTLScript::ConvertToFixed(const char* text, RTLScriptConverterProperties* properties)
{
    return ConvertToFixed(std::string(text), properties).c_str();
}

void RTLScript::ConvertToFixed(const char*& text_begin, const char*& text_end, std::string& newStr, RTLScriptConverterProperties* properties)
{
    newStr = RTLScript::ConvertToFixed(std::string(text_begin, text_end), properties);
    const char* chr = newStr.c_str();
    text_begin = chr;
    text_end = chr + newStr.size();
}
