// RTL type is my fork for FarsiType
#include "RTLType.h"
#include <cstring>
#include <sstream>

const std::vector<std::vector<std::string>> FaAr_AlphabetsAllForms =
{
    {"\u0623", "\ufe83", "\u0623", "\ufe84", "\ufe84"}, // faa_ALEF_HAMZEH_ABOVE, // أ
    {"\u0627", "\ufe8d", "\u0627", "\ufe8e", "\ufe8e"}, // faa_ALEF, // ا
    {"\u0622", "\ufe81", "\u0622", "\ufe82", "\ufe82"}, // faa_ALEF_MAD_ABOVE, // آ
    {"\u0621", "\ufe80", "\u0621", "\u0621", "\u0621"}, // faa_HAMZA, // ء
    {"\u0624", "\ufe85", "\u0624", "\ufe86", "\ufe86"}, // faa_VAAV_HAMZEH_ABOVE, // ؤ
    {"\u0625", "\ufe87", "\u0625", "\ufe88", "\ufe88"}, // faa_ALEF_HAMZEH_BELOW, // إ
    {"\u0626", "\ufe89", "\ufe8b", "\ufe8c", "\ufe8a"}, // faa_YEH_HAMZEH_ABOVE, // ئ
    {"\u0628", "\ufe8f", "\ufe91", "\ufe92", "\ufe90"}, // faa_BEH, // ب
    {"\u067e", "\ufb56", "\ufb58", "\ufb59", "\ufb57"}, // faa_PEH, // پ
    {"\u062A", "\ufe95", "\ufe97", "\ufe98", "\ufe96"}, // faa_TEH, // ت
    {"\u0629", "\ufe93", "\u0629", "\u0629", "\ufe94"}, // faa_TEH_TANIS, // ة
    {"\u062b", "\ufe99", "\ufe9b", "\ufe9c", "\ufe9a"}, // faa_SEH, // ث
    {"\u062c", "\ufe9d", "\ufe9f", "\ufea0", "\ufe9e"}, // faa_JEEM, // ج
    {"\u0686", "\ufb7a", "\ufb7c", "\ufb7d", "\ufb7b"}, // faa_CHEH, // چ
    {"\u062d", "\ufea1", "\ufea3", "\ufea4", "\ufea2"}, // faa_HEH_JEEMY, // ح
    {"\u062e", "\ufea5", "\ufea7", "\ufea8", "\ufea6"}, // faa_KHEH, // خ
    {"\u062f", "\ufea9", "\u062f", "\ufeaa", "\ufeaa"}, // faa_DAAL, // د
    {"\u0630", "\ufeab", "\u0630", "\ufeac", "\ufeac"}, // faa_ZAAL, // ذ
    {"\u0631", "\ufead", "\u0631", "\ufeae", "\ufeae"}, // faa_REH, // ر
    {"\u0632", "\ufeaf", "\u0632", "\ufeb0", "\ufeb0"}, // faa_ZEH, // ز
    {"\u0698", "\ufb8a", "\u0698", "\ufb8b", "\ufb8b"}, // faa_JEH, // ژ
    {"\u0633", "\ufeb1", "\ufeb3", "\ufeb4", "\ufeb2"}, // faa_SEEN, // س
    {"\u0634", "\ufeb5", "\ufeb7", "\ufeb8", "\ufeb6"}, // faa_SHEEN, // ش
    {"\u0635", "\ufeb9", "\ufebb", "\ufebc", "\ufeba"}, // faa_SAAD, // ص
    {"\u0636", "\ufebd", "\ufebf", "\ufec0", "\ufebe"}, // faa_ZAAD, // ض
    {"\u0637", "\ufec1", "\ufec3", "\ufec4", "\ufec2"}, // faa_TAAH, // ط
    {"\u0638", "\ufec5", "\ufec7", "\ufec8", "\ufec6"}, // faa_ZAAH, // ظ
    {"\u0639", "\ufec9", "\ufecb", "\ufecc", "\ufeca"}, // faa_AIN, // ع
    {"\u063a", "\ufecd", "\ufecf", "\ufed0", "\ufece"}, // faa_GHAIN, // غ
    {"\u0641", "\ufed1", "\ufed3", "\ufed4", "\ufed2"}, // faa_FEH, // ف
    {"\u0642", "\ufed5", "\ufed7", "\ufed8", "\ufed6"}, // faa_QAAF, // ق
    {"\u06a9", "\ufed9", "\ufedb", "\ufedc", "\ufeda"}, // faa_KAAF, // ک // I had to change all forms to due to rendering issues in DX faa_KAAF_NO_HEAD | original: u8"\ufb8e", u8"\ufb90", u8"\ufb91", u8"\ufb8f"
    {"\u0643", "\ufed9", "\ufedb", "\ufedc", "\ufeda"}, // faa_KAAF_NO_HEAD, // ك
    {"\u06af", "\ufb92", "\ufb94", "\ufb95", "\ufb93"}, // faa_GAAF, // گ
    {"\u0644", "\ufedd", "\ufedf", "\ufee0", "\ufede"}, // faa_LAAM, // ل
    {"\u0645", "\ufee1", "\ufee3", "\ufee4", "\ufee2"}, // faa_MEEM, // م
    {"\u0646", "\ufee5", "\ufee7", "\ufee8", "\ufee6"}, // faa_NOON, // ن
    {"\u0647", "\ufee9", "\ufeeb", "\ufeec", "\ufeea"}, // faa_HEH, // ه
    {"\u0648", "\ufeed", "\ufeed", "\ufeee", "\ufeee"}, // faa_VAAV, // و
    {"\u06cc", "\ufbfc", "\ufbfe", "\ufbff", "\ufbfd"}, // faa_YEH, // ی
    {"\u064a", "\ufef1", "\ufef3", "\ufef4", "\ufef2"}, // faa_ARABIC_YEH, // ي
    {"\u0649", "\ufeef", "\u0649", "\ufef0", "\ufef0"}, // faa_ALEF_MAKSURA, // ى
    {"\u0640", "\u0640", "\u0640", "\u0640", "\u0640"}, // faa_TATWEEL, // ـ
    {"\ufefb", "\ufefb", "\ufefb", "\ufefc", "\ufefc"}, // faa_LAAM_ALEF, // لا
    {"\ufef7", "\ufef7", "\ufef7", "\ufef8", "\ufef8"}, // faa_LAAM_ALEF_HAMZA_ABOVE, // لأ
};

unsigned char RTLType::GetFACharPlace(const std::string& fa_character, const std::string& prevFAChar, const std::string& nextFAChar)
{
    bool in_previous = false;
    bool in_next = false;
    for (auto const& fachar : FaAr_AlphabetsAllForms)
    {
        if (prevFAChar != "ISNOTFA" || fachar[faa_Unicode] == prevFAChar)
            in_previous = true;
        if (nextFAChar != "ISNOTFA" || fachar[faa_Unicode] == nextFAChar)
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

bool RTLType::IsFACharBeginner(const std::string& fa_character)
{
    return
        fa_character == FaAr_AlphabetsAllForms[faa_ALEF_HAMZEH_ABOVE][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ALEF_HAMZEH_ABOVE][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ALEF_MAD_ABOVE][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ALEF][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_HAMZEH][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_VAAV_HAMZEH_ABOVE][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ALEF_HAMZEH_BELOW][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_DAAL][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ZAAL][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_REH][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ZEH][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_JEH][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_VAAV][faa_Unicode] ||
        fa_character == FaAr_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Unicode]
        ;
}

unsigned char RTLType::FindFACharIndex(const std::string& fa_character)
{
    for (int i = 0; i < FaAr_AlphabetsAllForms.size(); ++i)
    {
        if (fa_character == FaAr_AlphabetsAllForms[i][faa_Unicode] ||
            fa_character == FaAr_AlphabetsAllForms[i][faa_Isolated] ||
            fa_character == FaAr_AlphabetsAllForms[i][faa_Beginner] ||
            fa_character == FaAr_AlphabetsAllForms[i][faa_Medium] ||
            fa_character == FaAr_AlphabetsAllForms[i][faa_Final])
            return i;
        else
            continue;
    }
    return FaAr_AlphabetsAllForms.size();
}

bool RTLType::IsFAChar(const std::string& fa_character)
{
    for (auto const& fachar : FaAr_AlphabetsAllForms)
    {
        if (fa_character == fachar[faa_Unicode] ||
            fa_character == fachar[faa_Isolated] ||
            fa_character == fachar[faa_Beginner] ||
            fa_character == fachar[faa_Medium] ||
            fa_character == fachar[faa_Final])
            return true;
        else continue;
    }
    return false;
}

int RTLType::StringToCodepoint(const std::string& str) {
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

bool RTLType::IsRTL(int codepoint)
{
    // Arabic (0600–06FF), Hebrew (0590–05FF), Farsi and etc.
    return ((codepoint >= 0x0590 && codepoint <= 0x08FF) || (codepoint >= 0xFB1D && codepoint <= 0xFEFC));
}

std::vector<std::string> RTLType::ReverseFAText(const std::string& str)
{
    std::vector<std::string> reversedStr;

    std::istringstream wif(str);
    std::string line;

    while (std::getline(wif, line))
    {
        std::vector<std::string> temp;
        bool rtl = false;
        for (int j = 0; j < line.size(); j++)
        {
            int codepoint = StringToCodepoint(line.substr(j, 2));
            if (IsRTL(codepoint) || rtl == true)
            {
                rtl = true;
                if (std::isspace(line[j]))
                {
                    temp.insert(temp.begin(), std::string() + " ");
                }
                else
                {
                    temp.insert(temp.begin(), std::string() + line[j] + line[j + 1]);
                    j++;
                }
            }
            else
            {
                reversedStr.insert(reversedStr.end(), std::string() + line[j]);
            }

            if (j == line.size() - 1)
            {
                if (temp.size() > 0)
                {
                    reversedStr.insert(reversedStr.end(), temp.begin(), temp.end());
                    temp.clear();
                }
            }
        }
    }
    return reversedStr;
}

std::string RTLType::GetFACharGlyph(const std::string& fa_character, const std::string& prevFAChar, const std::string& nextFAChar)
{
    if (!IsFAChar(fa_character)) return fa_character;

    unsigned char facharPlace;
    unsigned char facharIndex;
    facharPlace = GetFACharPlace(fa_character, prevFAChar, nextFAChar);
    facharIndex = FindFACharIndex(fa_character);

    switch (facharPlace)
    {
    case 3:
        if (IsFACharBeginner(prevFAChar))
        {
            if (FaAr_AlphabetsAllForms[facharIndex][faa_Beginner] == FaAr_AlphabetsAllForms[faa_YEH][faa_Beginner])
            {
                return FaAr_AlphabetsAllForms[faa_ARABIC_YEH][faa_Beginner];
            }
            return FaAr_AlphabetsAllForms[facharIndex][faa_Beginner];
        }
        else
        {
            if (FaAr_AlphabetsAllForms[facharIndex][faa_Medium] == FaAr_AlphabetsAllForms[faa_YEH][faa_Medium])
            {
                return FaAr_AlphabetsAllForms[faa_ARABIC_YEH][faa_Medium];
            }
            return FaAr_AlphabetsAllForms[facharIndex][faa_Medium];
        }
    case 2:
        if (FaAr_AlphabetsAllForms[facharIndex][faa_Beginner] == FaAr_AlphabetsAllForms[faa_YEH][faa_Beginner])
        {
            return FaAr_AlphabetsAllForms[faa_ARABIC_YEH][faa_Beginner];
        }
        return FaAr_AlphabetsAllForms[facharIndex][faa_Beginner];
    case 1:
        if (IsFACharBeginner(prevFAChar))
        {
            if (FaAr_AlphabetsAllForms[facharIndex][faa_Isolated] == FaAr_AlphabetsAllForms[faa_YEH][faa_Isolated])
            {
                return FaAr_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Isolated];
            }
            return FaAr_AlphabetsAllForms[facharIndex][faa_Isolated];
        }
        else
        {
            if (FaAr_AlphabetsAllForms[facharIndex][faa_Final] == FaAr_AlphabetsAllForms[faa_YEH][faa_Final])
            {
                return FaAr_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Final];
            }
            return FaAr_AlphabetsAllForms[facharIndex][faa_Final];
        }
    default:
        if (FaAr_AlphabetsAllForms[facharIndex][faa_Isolated] == FaAr_AlphabetsAllForms[faa_YEH][faa_Isolated])
        {
            return FaAr_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Isolated];
        }
        return FaAr_AlphabetsAllForms[facharIndex][faa_Isolated];
    }
}

std::string RTLType::ConvertToFAGlyphs(const std::string& text)
{
    std::vector<std::string> reversed_text = ReverseFAText(text);
    std::string convertedText;
    std::string previous_fachar, next_fachar;

    for (int i = 0; i < reversed_text.size(); ++i)
    {

        if (!IsFAChar(reversed_text[i]))
        {
            convertedText.append(reversed_text[i]);
            continue;
        }
        if ((i - 1) < 0)
            previous_fachar = "ISNOTFA";
        else
        {
            if (IsFAChar(reversed_text[i - 1]))
                previous_fachar = reversed_text[i - 1];
            else
                previous_fachar = "ISNOTFA";
        }

        if ((i + 1) <= (reversed_text.size() - 1))
        {
            if (IsFAChar(reversed_text[i + 1]))
                next_fachar = reversed_text[i + 1];
            else
                next_fachar = "ISNOTFA";
        }
        else
            next_fachar = "ISNOTFA";

        std::string fa_glyph = GetFACharGlyph(reversed_text[i], next_fachar, previous_fachar);
        convertedText.append(fa_glyph);
    }
    return convertedText;
}
