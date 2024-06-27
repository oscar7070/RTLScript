// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#include "RTLScript.h"
#include <sstream>

ArabicLetterForm RTLScript::GetARCharPlace(const std::string& arCharacter, const std::string& prevARChar, const std::string& nextARChar)
{
    bool in_previous = false, in_next = false;
    for (auto const& arChar : Ar_AlphabetAllLetters)
    {
        if (prevARChar != "!AR" || arChar[Ar_Forms_Unicode] == prevARChar)
            in_previous = true;
        if (nextARChar != "!AR" || arChar[Ar_Forms_Unicode] == nextARChar)
            in_next = true;
    }

    if (in_previous && in_next)
        return Ar_Forms_Medium;
    if (in_next)
        return Ar_Forms_Beginner;
    if (in_previous)
        return Ar_Forms_Final;
    else
        return Ar_Forms_Isolated;
}

bool RTLScript::IsArCharBeginner(const std::string& arCharacter)
{
    return arCharacter == Ar_AlphabetAllLetters[Ar_ALIF_HAMZA_ABOVE][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_ALIF_MADDAH_ABOVE][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_ALIF][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_HAMZA][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_WAW_HAMZA_ABOVE][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_ALIF_HAMZA_BELOW][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_DAAL][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_THAAL][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_REH][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_ZAIN][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[ArFa_JEH][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_WAW][Ar_Forms_Unicode] ||
        arCharacter == Ar_AlphabetAllLetters[Ar_ALIF_MAKSURA][Ar_Forms_Unicode];
}

size_t RTLScript::FindARCharIndex(const std::string& arCharacter)
{
    for (int i = 0; i < Ar_AlphabetAllLetters.size(); i++)
    {
        if (arCharacter == Ar_AlphabetAllLetters[i][Ar_Forms_Unicode] ||
            arCharacter == Ar_AlphabetAllLetters[i][Ar_Forms_Isolated] ||
            arCharacter == Ar_AlphabetAllLetters[i][Ar_Forms_Beginner] ||
            arCharacter == Ar_AlphabetAllLetters[i][Ar_Forms_Medium] ||
            arCharacter == Ar_AlphabetAllLetters[i][Ar_Forms_Final])
            return i;
        else
            continue;
    }
    return Ar_AlphabetAllLetters.size();
}

bool RTLScript::IsARChar(const std::string arCharacter)
{
    for (auto const& arChar : Ar_AlphabetAllLetters)
    {
        if (arCharacter == arChar[Ar_Forms_Unicode] ||
            arCharacter == arChar[Ar_Forms_Isolated] ||
            arCharacter == arChar[Ar_Forms_Beginner] ||
            arCharacter == arChar[Ar_Forms_Medium] ||
            arCharacter == arChar[Ar_Forms_Final])
            return true;
        else continue;
    }
    return false;
}

bool RTLScript::CheckForARChar(const std::string& arCharacter, ArabicAlphabet checkFor)
{
    for (auto const& arChar : Ar_AlphabetAllLetters)
    {
        if (arCharacter == Ar_AlphabetAllLetters[checkFor][Ar_Forms_Unicode] ||
            arCharacter == Ar_AlphabetAllLetters[checkFor][Ar_Forms_Isolated] ||
            arCharacter == Ar_AlphabetAllLetters[checkFor][Ar_Forms_Beginner] ||
            arCharacter == Ar_AlphabetAllLetters[checkFor][Ar_Forms_Medium] ||
            arCharacter == Ar_AlphabetAllLetters[checkFor][Ar_Forms_Final])
            return true;
        else continue;
    }
    return false;
}

int RTLScript::StringToCodepoint(const std::string& str)
{
    if (str.empty()) return -1;

    const unsigned char u0 = str[0];
    if (u0 >= 0 && u0 <= 127) return u0; // ASCII

    if ((u0 & 0xE0) == 0xC0) {
        const unsigned char u1 = str[1] & 0x3F;
        return ((u0 & 0x1F) << 6) | u1;
    }
    if ((u0 & 0xF0) == 0xE0) {
        const unsigned char u1 = str[1] & 0x3F;
        const unsigned char u2 = str[2] & 0x3F;
        return ((u0 & 0x0F) << 12) | (u1 << 6) | u2;
    }
    if ((u0 & 0xF8) == 0xF0) {
        const unsigned char u1 = str[1] & 0x3F;
        const unsigned char u2 = str[2] & 0x3F;
        const unsigned char u3 = str[3] & 0x3F;
        return ((u0 & 0x07) << 18) | (u1 << 12) | (u2 << 6) | u3;
    }
    return -1; // Error
}

bool RTLScript::IsRTL(const int codepoint)
{
    // Arabic (0600–06FF), Hebrew (0590–05FF), Farsi, Urdu and etc.
    return ((codepoint >= 0x0590 && codepoint <= 0x08FF) || (codepoint >= 0xFB1D && codepoint <= 0xFEFC));
}

bool RTLScript::IsPunctOrDigit(const int c)
{
    return std::ispunct(c) || std::isdigit(c);
}

std::vector<std::string> RTLScript::ReverseRTLText(const std::string& str)
{
    std::vector<std::string> reversedStr;

    std::istringstream wif(str);
    std::string line;

    bool isFirstLine = true;
    while (std::getline(wif, line))
    {
        if (!isFirstLine)
        {
            reversedStr.insert(reversedStr.end(), std::string() + "\n");
        }
        isFirstLine = false;

        std::vector<std::string> temp;
        bool rtl = false;
        for (int j = 0; j < line.size(); j++)
        {
            const int codepoint = StringToCodepoint(line.substr(j, 2));
            const bool isRTL = IsRTL(codepoint);
            const bool isSpace = std::isspace(line[j]);
            const bool isPunctOrDigitOrSpace = IsPunctOrDigit(line[j]) || isSpace;
            if (isRTL || rtl == true && isPunctOrDigitOrSpace)
            {
                rtl = true;
                if (isPunctOrDigitOrSpace) // To fix a char of count 1. to fix this bug: !?
                {
                    temp.insert(temp.begin(), std::string() + line[j]);
                }
                else
                {
                    temp.insert(temp.begin(), std::string() + line[j] + line[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(j) + 1]);
                    j++;
                }
            }
            else
            {
                // Check if there a non RTL text to change the direction.
                if (!isPunctOrDigitOrSpace)
                {
                    rtl = false;
                }
                reversedStr.insert(reversedStr.end(), std::string() + line[j]);
            }
        }
        if (temp.size() > 0)
        {
            reversedStr.insert(reversedStr.end(), temp.begin(), temp.end());
            temp.clear();
        }
    }
    return reversedStr;
}

bool RTLScript::CheckForAnyTypeOfLaamAlif(const std::string& arCharacter)
{
    if (CheckForARChar(arCharacter, Ar_LAAM_ALIF) ||
        CheckForARChar(arCharacter, Ar_LAAM_ALIF_HAMZA_ABOVE) ||
        CheckForARChar(arCharacter, Ar_LAAM_ALIF_HAMZA_BELOW) ||
        CheckForARChar(arCharacter, Ar_LAAM_ALIF_MADDAH_ABOVE))
        return true;
    else
        return false;
}

std::string RTLScript::GetARCharGlyph(const std::string& arCharacter, const std::string& prevARChar, const std::string& nextARChar)
{
    if (!IsARChar(arCharacter)) return arCharacter;

    const unsigned char arCharPlace = GetARCharPlace(arCharacter, prevARChar, nextARChar);
    const size_t arCharIndex = FindARCharIndex(arCharacter);

    switch (arCharPlace)
    {
    case Ar_Forms_Medium:
        if (IsArCharBeginner(prevARChar))
        {
            if (Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Beginner] == Ar_AlphabetAllLetters[Ar_YEH][Ar_Forms_Beginner])
            {
                return Ar_AlphabetAllLetters[Ar_ARABIC_YEH][Ar_Forms_Beginner];
            }
            return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Beginner];
        }
        if (Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Medium] == Ar_AlphabetAllLetters[Ar_YEH][Ar_Forms_Medium])
        {
            return Ar_AlphabetAllLetters[Ar_ARABIC_YEH][Ar_Forms_Medium];
        }
        if (CheckForAnyTypeOfLaamAlif(prevARChar))
            return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Beginner];
        else
            return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Medium];
    case Ar_Forms_Beginner:
        if (Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Beginner] == Ar_AlphabetAllLetters[Ar_YEH][Ar_Forms_Beginner])
        {
            return Ar_AlphabetAllLetters[Ar_ARABIC_YEH][Ar_Forms_Beginner];
        }
        return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Beginner];
    case Ar_Forms_Final:
        if (IsArCharBeginner(prevARChar))
        {
            if (Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Isolated] == Ar_AlphabetAllLetters[Ar_YEH][Ar_Forms_Isolated])
            {
                return Ar_AlphabetAllLetters[Ar_ALIF_MAKSURA][Ar_Forms_Isolated];
            }
            return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Isolated];
        }
        if (Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Final] == Ar_AlphabetAllLetters[Ar_YEH][Ar_Forms_Final])
        {
            return Ar_AlphabetAllLetters[Ar_ALIF_MAKSURA][Ar_Forms_Final];
        }
        if (CheckForAnyTypeOfLaamAlif(prevARChar))
            return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Isolated];
        else
            return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Final];
    default:
        if (Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Isolated] == Ar_AlphabetAllLetters[Ar_YEH][Ar_Forms_Isolated])
        {
            return Ar_AlphabetAllLetters[Ar_ALIF_MAKSURA][Ar_Forms_Isolated];
        }
        return Ar_AlphabetAllLetters[arCharIndex][Ar_Forms_Isolated];
    }
}

//void RTLScript::CheckForARWordAndReplace(const std::vector<ArabicAlphabets> checkFor, const std::string replaceTo, std::vector<std::string>& text)
//{
//    const size_t checkForSize = checkFor.size();
//    const size_t size = text.size();
//    for (size_t i = 0; i < size; i++)
//    {
//        if (i < (size - checkForSize))
//        {
//            bool found = false;
//            for (size_t c = 0; c < checkForSize; c++)
//            {
//                if (CheckForARChar(text[i + c], checkFor[c]))
//                {
//                    found = true;
//                    //break;
//                }
//                else
//                {
//                    if (found)
//                    {
//                        found = false;
//                    }
//                }
//            }
//            if (found)
//            {
//                text[i] = replaceTo;
//                for (size_t c = 0; c < checkForSize; c++)
//                {
//                    text.erase(text.begin() + (i + c));
//                }
//            }
//        }
//        break;
//    }
//}

std::string RTLScript::ConvertToFixed(const std::string& text, RTLScriptConverterProperties* properties)
{
    if (properties == NULL)
        properties = const_cast<RTLScriptConverterProperties*>(&DefaultConverterProperties);

    std::vector<std::string> reversed_text = ReverseRTLText(text);
    std::string convertedText, previousArChar, nextArChar;

    // Change chars to they currect form for exemple: ل + ا = لا
    for (int i = 0; i < reversed_text.size(); i++)
    {
        const int elementPlus1 = i + 1;
        if (properties->EnableSpecialWordAllahForm)
            if (i < reversed_text.size() - 3)
                // ﷲ
                if (CheckForARChar(reversed_text[i], Ar_HA) && CheckForARChar(reversed_text[elementPlus1], Ar_LAAM) && CheckForARChar(reversed_text[i + 2], Ar_LAAM) && CheckForARChar(reversed_text[i + 3], Ar_ALIF))
                {
                    reversed_text[i] = Ar_AlphabetAllLetters[Ar_Allah][Ar_Forms_Unicode];
                    reversed_text.erase(reversed_text.begin() + elementPlus1, reversed_text.begin() + i + 4);
                }

        if (properties->EnableJointLaamAlifForm)
            if (i < reversed_text.size() - 1)
            {
                // لا
                if (CheckForARChar(reversed_text[i], Ar_ALIF) && CheckForARChar(reversed_text[elementPlus1], Ar_LAAM))
                {
                    reversed_text[i] = Ar_AlphabetAllLetters[Ar_LAAM_ALIF][Ar_Forms_Unicode];
                    reversed_text.erase(reversed_text.begin() + elementPlus1);
                }

                // لأ
                if (CheckForARChar(reversed_text[i], Ar_ALIF_HAMZA_ABOVE) && CheckForARChar(reversed_text[elementPlus1], Ar_LAAM))
                {
                    reversed_text[i] = Ar_AlphabetAllLetters[Ar_LAAM_ALIF_HAMZA_ABOVE][Ar_Forms_Unicode];
                    reversed_text.erase(reversed_text.begin() + elementPlus1);
                }

                // لإ
                if (CheckForARChar(reversed_text[i], Ar_ALIF_HAMZA_BELOW) && CheckForARChar(reversed_text[elementPlus1], Ar_LAAM))
                {
                    reversed_text[i] = Ar_AlphabetAllLetters[Ar_LAAM_ALIF_HAMZA_BELOW][Ar_Forms_Unicode];
                    reversed_text.erase(reversed_text.begin() + elementPlus1);
                }

                // لآ
                if (CheckForARChar(reversed_text[i], Ar_ALIF_MADDAH_ABOVE) && CheckForARChar(reversed_text[elementPlus1], Ar_LAAM))
                {
                    reversed_text[i] = Ar_AlphabetAllLetters[Ar_LAAM_ALIF_MADDAH_ABOVE][Ar_Forms_Unicode];
                    reversed_text.erase(reversed_text.begin() + elementPlus1);
                }
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

            const int elementMinus1 = i - 1;
            if (elementMinus1 < 0)
                previousArChar = "!AR"; // !AR is to mark that the char is not Arabic.
            else
            {
                if (IsARChar(reversed_text[elementMinus1]))
                    previousArChar = reversed_text[elementMinus1];
                else
                    previousArChar = "!AR";
            }

            const int elementPlus1 = i + 1;
            if (elementPlus1 <= (reversedTextSize - 1))
            {
                if (IsARChar(reversed_text[elementPlus1]))
                    nextArChar = reversed_text[elementPlus1];
                else
                    nextArChar = "!AR";
            }
            else
                nextArChar = "!AR";

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
