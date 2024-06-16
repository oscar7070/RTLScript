// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#pragma once

#include <string>
#include <vector>

#ifndef RTLSCRIPT_H
#define RTLSCRIPT_H

constexpr auto RTLSCRIPT_VERSION = "1.3";
constexpr auto RTLSCRIPT_VERSION_NUM = 130;

enum ArabicTashkeel
{
    AR_TASHKEEL_FATHA,
    AR_TASHKEEL_FATHA_TAN,
    AR_TASHKEEL_DAMMA,
    AR_TASHKEEL_DAMMA_TAN ,
    AR_TASHKEEL_KASRA,
    AR_TASHKEEL_KASRA_TAN,
    AR_TASHKEEL_SUKUN,
    AR_TASHKEEL_SHADDA,
    AR_TASHKEEL_Tashkeel_Count
};

enum ArabicTashkeel_FarsiNames
{
    FA_TASHKEEL_FATHEH = AR_TASHKEEL_FATHA,
    FA_TASHKEEL_TANVIN_NASB = AR_TASHKEEL_FATHA_TAN,
    FA_TASHKEEL_ZAMMEH = AR_TASHKEEL_DAMMA,
    FA_TASHKEEL_TANVIN_RAF= AR_TASHKEEL_DAMMA_TAN,
    FA_TASHKEEL_KASREH = AR_TASHKEEL_KASRA,
    FA_TASHKEEL_TANVIN_JARR = AR_TASHKEEL_KASRA_TAN,
    FA_TASHKEEL_SOKOON = AR_TASHKEEL_SUKUN,
    FA_TASHKEEL_TASHDID = AR_TASHKEEL_SHADDA
};

enum ArabicAlphabet
{
    // Arabic
    Ar_ALEF_HAMZA_ABOVE, // أ
    Ar_ALEF, // ا
    Ar_ALEF_MADDAH_ABOVE, // آ
    Ar_HAMZA, // ء
    Ar_WAW_HAMZA_ABOVE, // ؤ
    Ar_ALEF_HAMZA_BELOW, // إ
    Ar_YEH_HAMZA_ABOVE, // ئ
    Ar_BEH, // ب
    Ar_TEH, // ت
    Ar_TEH_MARBUTA, // ة
    Ar_THEH, // ث
    Ar_JEEM, // ج
    Ar_HAH, // ح
    Ar_KHEH, // خ
    Ar_DAAL, // د
    Ar_THAAL, // ذ
    Ar_REH, // ر
    Ar_ZAIN, // ز
    Ar_SEEN, // س
    Ar_SHEEN, // ش
    Ar_SAAD, // ص
    Ar_DAAD, // ض
    Ar_TAAH, // ط
    Ar_ZAAH, // ظ
    Ar_AIN, // ع
    Ar_GHAIN, // غ
    Ar_FEH, // ف
    Ar_QAAF, // ق
    Ar_KAAF, // ک
    Ar_KAAF_NO_HEAD, // ك
    Ar_LAAM, // ل
    Ar_MEEM, // م
    Ar_NOON, // ن
    Ar_WAW, // و
    Ar_HA, // ه
    Ar_YEH, // ی
    Ar_ARABIC_YEH, // ي
    Ar_ALEF_MAKSURA, // ى
    Ar_TATWEEL, // ـ

    Ar_LAAM_ALEF, // لا
    Ar_LAAM_ALEF_HAMZA_ABOVE, // لأ
    Ar_LAAM_ALEF_HAMZA_BELOW, // لإ
    Ar_LAAM_ALEF_MADDAH_ABOVE, // لآ
    Ar_Allah, // ﷲ

    // Farsi
    ArFa_PEH, // پ
    ArFa_GAAF, // گ
    ArFa_CHEH, // چ
    ArFa_JEH, // ژ

    // Urdu
    ArUr_Te, // ٹ
    ArUr_Dal, // ڈ
    ArUr_Re, // ڑ
    ArUr_NunGhunna, // ں
    ArUr_BariYe, // ے
    ArUr_He, // ھ
    ArUr_Ha, // ہ
};

enum ArabicAlphabet_FarsiNames
{
    Fa_ALEF_HAMZEH_ABOVE = Ar_ALEF_HAMZA_ABOVE,
    Fa_ALEF_MAD_ABOVE = Ar_ALEF_MADDAH_ABOVE,
    Fa_HAMZA,
    Fa_VAAV_HAMZEH_ABOVE = Ar_WAW_HAMZA_ABOVE,
    Fa_ALEF_HAMZEH_BELOW = Ar_ALEF_HAMZA_BELOW,
    Fa_YEH_HAMZEH_ABOVE = Ar_YEH_HAMZA_ABOVE,
    Fa_TEH_TANIS = Ar_TEH_MARBUTA,
    Fa_SEH = Ar_THEH,
    Fa_HEH_JEEMY = Ar_HAH,
    Fa_ZAAL = Ar_THAAL,
    Fa_ZEH = Ar_ZAIN,
    Fa_ZAAD = Ar_DAAD,
    Fa_VAAV = Ar_WAW
};

enum ArabicLetterForm
{
    Ar_Forms_Unicode,
    Ar_Forms_Isolated,
    Ar_Forms_Beginner,
    Ar_Forms_Medium,
    Ar_Forms_Final,
};

const std::vector<std::vector<std::string>> Ar_AlphabetAllLetters =
{
    // Arabic
    {"\u0623", "\ufe83", "\u0623", "\ufe84", "\ufe84"}, // Ar_ALEF_HAMZA_ABOVE, // أ
    {"\u0627", "\ufe8d", "\u0627", "\ufe8e", "\ufe8e"}, // Ar_ALEF, // ا
    {"\u0622", "\ufe81", "\u0622", "\ufe82", "\ufe82"}, // Ar_ALEF_MADDAH_ABOVE, // آ
    {"\u0621", "\ufe80", "\u0621", "\u0621", "\u0621"}, // Ar_HAMZA, // ء
    {"\u0624", "\ufe85", "\u0624", "\ufe86", "\ufe86"}, // Ar_WAW_HAMZA_ABOVE, // ؤ
    {"\u0625", "\ufe87", "\u0625", "\ufe88", "\ufe88"}, // Ar_ALEF_HAMZA_BELOW, // إ
    {"\u0626", "\ufe89", "\ufe8b", "\ufe8c", "\ufe8a"}, // Ar_YEH_HAMZA_ABOVE, // ئ
    {"\u0628", "\ufe8f", "\ufe91", "\ufe92", "\ufe90"}, // Ar_BEH, // ب
    {"\u062A", "\ufe95", "\ufe97", "\ufe98", "\ufe96"}, // Ar_TEH, // ت
    {"\u0629", "\ufe93", "\u0629", "\u0629", "\ufe94"}, // Ar_TEH_MARBUTA, // ة
    {"\u062b", "\ufe99", "\ufe9b", "\ufe9c", "\ufe9a"}, // Ar_THEH, // ث
    {"\u062c", "\ufe9d", "\ufe9f", "\ufea0", "\ufe9e"}, // Ar_JEEM, // ج
    {"\u062d", "\ufea1", "\ufea3", "\ufea4", "\ufea2"}, // Ar_HAH, // ح
    {"\u062e", "\ufea5", "\ufea7", "\ufea8", "\ufea6"}, // Ar_KHEH, // خ
    {"\u062f", "\ufea9", "\u062f", "\ufeaa", "\ufeaa"}, // Ar_DAAL, // د
    {"\u0630", "\ufeab", "\u0630", "\ufeac", "\ufeac"}, // Ar_THAAL, // ذ
    {"\u0631", "\ufead", "\u0631", "\ufeae", "\ufeae"}, // Ar_REH, // ر
    {"\u0632", "\ufeaf", "\u0632", "\ufeb0", "\ufeb0"}, // Ar_ZAIN, // ز
    {"\u0633", "\ufeb1", "\ufeb3", "\ufeb4", "\ufeb2"}, // Ar_SEEN, // س
    {"\u0634", "\ufeb5", "\ufeb7", "\ufeb8", "\ufeb6"}, // Ar_SHEEN, // ش
    {"\u0635", "\ufeb9", "\ufebb", "\ufebc", "\ufeba"}, // Ar_SAAD, // ص
    {"\u0636", "\ufebd", "\ufebf", "\ufec0", "\ufebe"}, // Ar_DAAD, // ض
    {"\u0637", "\ufec1", "\ufec3", "\ufec4", "\ufec2"}, // Ar_TAAH, // ط
    {"\u0638", "\ufec5", "\ufec7", "\ufec8", "\ufec6"}, // Ar_ZAAH, // ظ
    {"\u0639", "\ufec9", "\ufecb", "\ufecc", "\ufeca"}, // Ar_AIN, // ع
    {"\u063a", "\ufecd", "\ufecf", "\ufed0", "\ufece"}, // Ar_GHAIN, // غ
    {"\u0641", "\ufed1", "\ufed3", "\ufed4", "\ufed2"}, // Ar_FEH, // ف
    {"\u0642", "\ufed5", "\ufed7", "\ufed8", "\ufed6"}, // Ar_QAAF, // ق
    {"\u06a9", "\ufb8e", "\ufb90", "\ufb91", "\ufb8f"}, // Ar_KAAF, // ک // I had to change all forms to due to rendering issues in DX faa_KAAF_NO_HEAD | original: u8"\ufb8e", u8"\ufb90", u8"\ufb91", u8"\ufb8f"
    {"\u0643", "\ufed9", "\ufedb", "\ufedc", "\ufeda"}, // Ar_KAAF_NO_HEAD, // ك
    {"\u0644", "\ufedd", "\ufedf", "\ufee0", "\ufede"}, // Ar_LAAM, // ل
    {"\u0645", "\ufee1", "\ufee3", "\ufee4", "\ufee2"}, // Ar_MEEM, // م
    {"\u0646", "\ufee5", "\ufee7", "\ufee8", "\ufee6"}, // Ar_NOON, // ن
    {"\u0648", "\ufeed", "\ufeed", "\ufeee", "\ufeee"}, // Ar_WAW, // و
    {"\u0647", "\ufee9", "\ufeeb", "\ufeec", "\ufeea"}, // Ar_HA, // ه
    {"\u06cc", "\ufbfc", "\ufbfe", "\ufbff", "\ufbfd"}, // Ar_YEH, // ی
    {"\u064a", "\ufef1", "\ufef3", "\ufef4", "\ufef2"}, // Ar_ARABIC_YEH, // ي
    {"\u0649", "\ufeef", "\u0649", "\ufef0", "\ufef0"}, // Ar_ALEF_MAKSURA, // ى
    {"\u0640", "\u0640", "\u0640", "\u0640", "\u0640"}, // Ar_TATWEEL, // ـ

    {"\ufefb", "\ufefb", "\ufefb", "\ufefc", "\ufefc"}, // Ar_LAAM_ALEF, // لا
    {"\ufef7", "\ufef7", "\ufef7", "\ufef8", "\ufef8"}, // Ar_LAAM_ALEF_HAMZA_ABOVE, // لأ
    {"\ufef9", "\ufef9", "\ufef9", "\ufefa", "\ufefa"}, // Ar_LAAM_ALEF_HAMZA_BELOW, // لإ
    {"\ufef5", "\ufef5", "\ufef5", "\ufef6", "\ufef6"}, // Ar_LAAM_ALEF_MADDAH_ABOVE, // لآ
    {"\ufdf2", "\ufdf2", "\ufdf2", "\ufdf2", "\ufdf2"}, // Ar_Allah, // ﷲ

    // Farsi
    {"\u067e", "\ufb56", "\ufb58", "\ufb59", "\ufb57"}, // ArFa_PEH, // پ
    {"\u06af", "\ufb92", "\ufb94", "\ufb95", "\ufb93"}, // ArFa_GAAF, // گ
    {"\u0686", "\ufb7a", "\ufb7c", "\ufb7d", "\ufb7b"}, // ArFa_CHEH, // چ
    {"\u0698", "\ufb8a", "\u0698", "\ufb8b", "\ufb8b"}, // ArFa_JEH, // ژ

    // Urdu
    {"\u0679", "\ufb66", "\ufb68", "\ufb69", "\ufb67"}, // ArUr_Te  , // ٹ
    {"\u0688", "\ufb88", "\ufb88", "\ufb89", "\ufb89"}, // ArUr_Dal, // ڈ
    {"\u0691", "\ufb8c", "\ufb8c", "\ufb8d", "\ufb8d"}, // ArUr_Re, // ڑ
    {"\u06ba", "\ufb9e", "\ufb9e", "\ufb9f", "\ufb9f"}, // ArUr_NunGhunna, // ں
    {"\u06d2", "\ufbae", "\ufbae", "\ufbaf", "\ufbaf"}, // ArUr_BariYe, // ے
    {"\u06be", "\ufbaa", "\ufbac", "\ufbad", "\ufbab"}, // ArUr_He, // ھ
    {"\u06c1", "\ufba6", "\ufba8", "\ufba9", "\ufba7"}, // ArUr_Ha, // ہ
};

enum HebrewAlphabet
{
    He_ALEF, // א
    He_BET, // ב
    He_GIMEL, // ג
    He_DALET, // ד
    He_HEI, // ה
    He_VAV, // ו
    He_ZAYIN, // ז
    He_CHET, // ח
    He_TET, // ט
    He_YOD, // י
    He_KAF, // כ
    He_KAF_SOFIT, // ך
    He_LAMED, // ל
    He_MEM, // מ
    He_MEM_SOFIT, // ם
    He_NUN, // נ
    He_NUN_SOFIT, // ן
    He_SAMEKH, // ס
    He_AYIN, // ע
    He_PEI, // פ
    He_PEI_SOFIT, // ף
    He_TSADIK, // צ
    He_TSADIK_SOFIT, // ץ
    He_KUF, // ק
    He_RAYSH, // ר
    He_SHIN, // ש
    He_TAV, // ת
};

namespace RTLScript
{
    /// <summary>Get Farsi/Arabic character place in a word for its form, depending its previous and next character.</summary>
    /// <param name="fa_character">Character you want to check its place.</param>
    /// <param name="prevFAChar">Previous character, to check if its connected to fa_character or not.</param>
    /// <param name="nextFAChar">Next character, to check if its connected to fa_character or not.</param>
    /// <returns>Returns an int in type of a char. Possible values: 0- no connection, 1- connected from behind, 2- connected from front, 3- connected from both side.</returns>
    unsigned char GetFACharPlace(const std::string& fa_character, const std::string& prevFAChar, const std::string& nextFAChar);

    /// <summary>Check if given character is a Arabic letter in beginner form or not.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsArCharBeginner(const std::string& ar_character);

    /// <summary>Find vector index of the give character in Ar_AlphabetsAllForms vector</summary>
    /// <param name="fa_character">Character you want get its index.</param>
    /// <returns>Returns an int in type of a char. Possible values: (ِِAr_AlphabetsAllForms array size).</returns>
    size_t FindARCharIndex(const std::string& ar_character);

    /// <summary>Check if given character is a Arabic letter or not.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsARChar(const std::string ar_character);

    /// <summary>Check if given Arabic character is the Arabic letter that you want to check for.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool CheckForARChar(const std::string& ar_character, ArabicAlphabet checkFor);

    /// <summary> String of two chars to Codepoint. </summary>
    /// <param name="str">String to get codepoint from.</param>
    /// <returns>Returns a int value.</returns>
    int StringToCodepoint(const std::string& str);

    /// <summary> Check if the code point is RTL. </summary>
    /// <param name="codepoint">A codepoint of a unicode char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsRTL(const int codepoint);

    /// <summary> Check if the char is punctuation or digit. </summary>
    /// <param name="c">A char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsPunctOrDigit(const int c);

    /// <summary>Reverses Farsi/Arabic/Hebrew... string and returns a vector of std::strings, each of them containing RTL letters with different byte counts.</summary>
    /// <param name="str">Farsi/Arabic/Hebrew... string.</param>
    /// <returns>Returns a vector of std::strings.</returns>
    std::vector<std::string> ReverseRTLText(const std::string& str);

    /// <summary>Get correct unicode of Farsi/Arabic letter depending on its position, previous, and next letters.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <param name="prevFAChar">Previous character, to check if its connected to Ar_character or not.</param>
    /// <param name="nextFAChar">Next character, to check if its connected to Ar_character or not.</param>
    /// <returns>Returns a std::string.</returns>
    std::string GetFaArCharGlyph(const std::string& faAr_character, const std::string& prevFAChar, const std::string& nextFAChar);

    //void CheckForARWordAndReplace(const std::vector<ArabicAlphabets> checkFor, const std::string replaceTo, std::vector<std::string>& text);

    /// <summary>Converts a Farsi/Arabic/Hebrew... string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text">Farsi/Arabic/Hebrew... text.</param>
    /// <returns>Returns a std::string. Fixed Farsi/Arabic/Hebrew... string</returns>
    std::string ConvertToFixed(const std::string& text);

    /// <summary>Converts a Farsi/Arabic/Hebrew... string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text">Farsi/Arabic/Hebrew... text.</param>
    /// <returns>Returns a const char*. Fixed Farsi/Arabic/Hebrew... string</returns>
    const char* ConvertToFixed(const char* text);

    /// <summary>Converts a Farsi/Arabic/Hebrew... string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text_begin">Farsi/Arabic/Hebrew... reference for a text beginning.</param>
    /// <param name="text_end">Farsi/Arabic/Hebrew... reference for a text ending.</param>
    /// <param name="newStr">Farsi/Arabic/Hebrew... reference for new or empty std::string.</param>
    void ConvertToFixed(const char*& text_begin, const char*& text_end, std::string& newStr);
};
#endif
