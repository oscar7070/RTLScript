// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#include "RTLScript.h"
#include <sstream>

unsigned char RTLScript::GetFACharPlace(const std::string& fa_character, const std::string& prevFAChar, const std::string& nextFAChar)
{
    bool in_previous = false, in_next = false;
    for (auto const& fachar : Ar_AlphabetsAllForms)
    {
        if (prevFAChar != "!AR" || fachar[Ar_Forms_Unicode] == prevFAChar)
            in_previous = true;
        if (nextFAChar != "!AR" || fachar[Ar_Forms_Unicode] == nextFAChar)
            in_next = true;
    }

    if (in_previous && in_next)
        return 3;
    if (in_next)
        return 2;
    if (in_previous)
        return 1;
    else
        return 0;
}

bool RTLScript::IsArCharBeginner(const std::string& ar_character)
{
    return
        ar_character == Ar_AlphabetsAllForms[Ar_ALEF_HAMZEH_ABOVE][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_ALEF_MAD_ABOVE][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_ALEF][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_HAMZEH][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_VAAV_HAMZEH_ABOVE][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_ALEF_HAMZEH_BELOW][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_DAAL][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_ZAAL][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_REH][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_ZEH][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[ArFa_JEH][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_VAAV][Ar_Forms_Unicode] ||
        ar_character == Ar_AlphabetsAllForms[Ar_ALEF_MAKSURA][Ar_Forms_Unicode]
        ;
}

size_t RTLScript::FindARCharIndex(const std::string& ar_character)
{
    for (int i = 0; i < Ar_AlphabetsAllForms.size(); i++)
    {
        if (ar_character == Ar_AlphabetsAllForms[i][Ar_Forms_Unicode] ||
            ar_character == Ar_AlphabetsAllForms[i][Ar_Forms_Isolated] ||
            ar_character == Ar_AlphabetsAllForms[i][Ar_Forms_Beginner] ||
            ar_character == Ar_AlphabetsAllForms[i][Ar_Forms_Medium] ||
            ar_character == Ar_AlphabetsAllForms[i][Ar_Forms_Final])
            return i;
        else
            continue;
    }
    return Ar_AlphabetsAllForms.size();
}

bool RTLScript::IsARChar(const std::string ar_character)
{
    for (auto const& arChar : Ar_AlphabetsAllForms)
    {
        if (ar_character == arChar[Ar_Forms_Unicode] ||
            ar_character == arChar[Ar_Forms_Isolated] ||
            ar_character == arChar[Ar_Forms_Beginner] ||
            ar_character == arChar[Ar_Forms_Medium] ||
            ar_character == arChar[Ar_Forms_Final])
            return true;
        else continue;
    }
    return false;
}

bool RTLScript::CheckForARChar(const std::string& ar_character, ArabicAlphabets checkFor)
{
    for (auto const& arChar : Ar_AlphabetsAllForms)
    {
        if (ar_character == Ar_AlphabetsAllForms[checkFor][Ar_Forms_Unicode] ||
            ar_character == Ar_AlphabetsAllForms[checkFor][Ar_Forms_Isolated] ||
            ar_character == Ar_AlphabetsAllForms[checkFor][Ar_Forms_Beginner] ||
            ar_character == Ar_AlphabetsAllForms[checkFor][Ar_Forms_Medium] ||
            ar_character == Ar_AlphabetsAllForms[checkFor][Ar_Forms_Final])
            return true;
        else continue;
    }
    return false;
}

int RTLScript::StringToCodepoint(const std::string& str)
{
    if (str.empty()) return -1;

    unsigned char u0 = str[0];
    if (u0 >= 0 && u0 <= 127) return u0; // ASCII

    if ((u0 & 0xE0) == 0xC0) {
        unsigned char u1 = str[1] & 0x3F;
        return ((u0 & 0x1F) << 6) | u1;
    }
    if ((u0 & 0xF0) == 0xE0) {
        unsigned char u1 = str[1] & 0x3F;
        unsigned char u2 = str[2] & 0x3F;
        return ((u0 & 0x0F) << 12) | (u1 << 6) | u2;
    }
    if ((u0 & 0xF8) == 0xF0) {
        unsigned char u1 = str[1] & 0x3F;
        unsigned char u2 = str[2] & 0x3F;
        unsigned char u3 = str[3] & 0x3F;
        return ((u0 & 0x07) << 18) | (u1 << 12) | (u2 << 6) | u3;
    }
    return -1; // Error
}

bool RTLScript::IsRTL(int codepoint)
{
    // Arabic (0600–06FF), Hebrew (0590–05FF), Farsi and etc.
    return ((codepoint >= 0x0590 && codepoint <= 0x08FF) || (codepoint >= 0xFB1D && codepoint <= 0xFEFC) || (codepoint >= 0x0600 && codepoint <= 0x06FF));
}

bool RTLScript::IsPunctOrDigit(int c)
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
            int codepoint = StringToCodepoint(line.substr(j, 2));
            bool isRTL = IsRTL(codepoint);
            bool isSpace = std::isspace(line[j]);
            bool isPunctOrDigitOrSpace = IsPunctOrDigit(line[j]) || isSpace;
            if (isRTL || rtl == true && isPunctOrDigitOrSpace)
            {
                rtl = true;
                if (isPunctOrDigitOrSpace) // To fix a char of count 1. to fix this bug: !?
                {
                    temp.insert(temp.begin(), std::string() + line[j]);
                }
                else
                {
                    temp.insert(temp.begin(), std::string() + line[j] + line[j + 1]);
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

std::string RTLScript::GetFaArCharGlyph(const std::string& faAr_character, const std::string& prevFAChar, const std::string& nextFAChar)
{
    if (!IsARChar(faAr_character)) return faAr_character;

    const unsigned char faArCharPlace = GetFACharPlace(faAr_character, prevFAChar, nextFAChar);
    const size_t arCharIndex = FindARCharIndex(faAr_character);

    switch (faArCharPlace)
    {
    case 3:
        if (IsArCharBeginner(prevFAChar))
        {
            if (Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Beginner] == Ar_AlphabetsAllForms[Ar_YEH][Ar_Forms_Beginner])
            {
                return Ar_AlphabetsAllForms[Ar_ARABIC_YEH][Ar_Forms_Beginner];
            }
            return Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Beginner];
        }
        if (Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Medium] == Ar_AlphabetsAllForms[Ar_YEH][Ar_Forms_Medium])
        {
            return Ar_AlphabetsAllForms[Ar_ARABIC_YEH][Ar_Forms_Medium];
        }
        return Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Medium];
    case 2:
        if (Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Beginner] == Ar_AlphabetsAllForms[Ar_YEH][Ar_Forms_Beginner])
        {
            return Ar_AlphabetsAllForms[Ar_ARABIC_YEH][Ar_Forms_Beginner];
        }
        return Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Beginner];
    case 1:
        if (IsArCharBeginner(prevFAChar))
        {
            if (Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Isolated] == Ar_AlphabetsAllForms[Ar_YEH][Ar_Forms_Isolated])
            {
                return Ar_AlphabetsAllForms[Ar_ALEF_MAKSURA][Ar_Forms_Isolated];
            }
            return Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Isolated];
        }
        if (Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Final] == Ar_AlphabetsAllForms[Ar_YEH][Ar_Forms_Final])
        {
            return Ar_AlphabetsAllForms[Ar_ALEF_MAKSURA][Ar_Forms_Final];
        }
        return Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Final];
    default:
        if (Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Isolated] == Ar_AlphabetsAllForms[Ar_YEH][Ar_Forms_Isolated])
        {
            return Ar_AlphabetsAllForms[Ar_ALEF_MAKSURA][Ar_Forms_Isolated];
        }
        return Ar_AlphabetsAllForms[arCharIndex][Ar_Forms_Isolated];
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

std::string RTLScript::ConvertToFixed(const std::string& text)
{
    std::vector<std::string> reversed_text = ReverseRTLText(text);
    std::string convertedText, previousFaArChar, nextFaArChar;

    // Change chars to they currect form for exemple: ل + ا = لا
    for (int i = 0; i < reversed_text.size(); i++)
    {
        if (i < reversed_text.size() - 3)
        {
            // ﷲ
            if (CheckForARChar(reversed_text[i], Ar_HA) && CheckForARChar(reversed_text[i + 1], Ar_LAAM) && CheckForARChar(reversed_text[i + 2], Ar_LAAM) && CheckForARChar(reversed_text[i + 3], Ar_ALEF))
            {
                reversed_text[i] = Ar_AlphabetsAllForms[Ar_Allah][Ar_Forms_Unicode];
                reversed_text.erase(reversed_text.begin() + i + 1, reversed_text.begin() + i + 4);
            }
        }

        if (i < reversed_text.size() - 1)
        {
            // لا
            if (CheckForARChar(reversed_text[i], Ar_ALEF) && CheckForARChar(reversed_text[i + 1], Ar_LAAM))
            {
                reversed_text[i] = Ar_AlphabetsAllForms[Ar_LAAM_ALEF][Ar_Forms_Unicode];
                reversed_text.erase(reversed_text.begin() + i + 1);
            }

            // لأ
            if (CheckForARChar(reversed_text[i], Ar_ALEF_HAMZEH_ABOVE) && CheckForARChar(reversed_text[i + 1], Ar_LAAM))
            {
                reversed_text[i] = Ar_AlphabetsAllForms[Ar_LAAM_ALEF_HAMZA_ABOVE][Ar_Forms_Unicode];
                reversed_text.erase(reversed_text.begin() + i + 1);
            }
        }
    }

    for (int i = 0; i < reversed_text.size(); i++)
    {
        if (!IsARChar(reversed_text[i]))
        {
            convertedText.append(reversed_text[i]);
            continue;
        }
        if ((i - 1) < 0)
            previousFaArChar = "!AR"; // !AR is to mark that the char is not Arabic or Farsi.
        else
        {
            if (IsARChar(reversed_text[i - 1]))
                previousFaArChar = reversed_text[i - 1];
            else
                previousFaArChar = "!AR";
        }

        if ((i + 1) <= (reversed_text.size() - 1))
        {
            if (IsARChar(reversed_text[i + 1]))
                nextFaArChar = reversed_text[i + 1];
            else
                nextFaArChar = "!AR";
        }
        else
            nextFaArChar = "!AR";

        std::string fa_glyph = GetFaArCharGlyph(reversed_text[i], nextFaArChar, previousFaArChar);
        convertedText.append(fa_glyph);
    }
    return convertedText;
}

const char* RTLScript::ConvertToFixed(const char* text)
{
    return ConvertToFixed(std::string(text)).c_str();
}

void RTLScript::ConvertToFixed(const char*& text_begin, const char*& text_end, std::string& newStr)
{
    newStr = RTLScript::ConvertToFixed(std::string(text_begin, text_end));
    const char* chr = newStr.c_str();
    text_begin = chr;
    text_end = chr + newStr.size();
}
