// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#pragma once

#include <string>
#include <vector>

#ifndef RTLSCRIPT_H
#define RTLSCRIPT_H

constexpr auto RTLSCRIPT_VERSION = "1.1";
constexpr auto RTLSCRIPT_VERSION_NUM = 110;

enum FarsiArabicTashkeel_
{
    fat_FATHEH,
    fat_TANVIN_NASB,
    fat_ZAMMEH,
    fat_TANVIN_RAF,
    fat_KASREH,
    fat_TANVIN_JARR,
    fat_SOKOON,
    fat_TASHDID,
    fat_Tashkeel_Count
};

enum FarsiArabicTashkeel_ArabicNames_
{
    fat_FATHA = fat_FATHEH,
    fat_FATHA_TAN = fat_TANVIN_NASB,
    fat_DAMMA = fat_ZAMMEH,
    fat_DAMMA_TAN = fat_TANVIN_RAF,
    fat_KASRA = fat_KASREH,
    fat_KASRA_TAN = fat_TANVIN_JARR,
    fat_SUKUN = fat_SOKOON,
    fat_SHADDA = fat_TASHDID
};

enum FarsiArabicAlphabets_
{
    faAr_ALEF_HAMZEH_ABOVE, // أ
    faAr_ALEF, // ا
    faAr_ALEF_MAD_ABOVE, // آ
    faAr_HAMZEH, // ء
    faAr_VAAV_HAMZEH_ABOVE, // ؤ
    faAr_ALEF_HAMZEH_BELOW, // إ
    faAr_YEH_HAMZEH_ABOVE, // ئ
    faAr_BEH, // ب
    faAr_PEH, // پ
    faAr_TEH, // ت
    faAr_TEH_TANIS, // ة
    faAr_SEH, // ث
    faAr_JEEM, // ج
    faAr_CHEH, // چ
    faAr_HEH_JEEMY, // ح
    faAr_KHEH, // خ
    faAr_DAAL, // د
    faAr_ZAAL, // ذ
    faAr_REH, // ر
    faAr_ZEH, // ز
    faAr_JEH, // ژ
    faAr_SEEN, // س
    faAr_SHEEN, // ش
    faAr_SAAD, // ص
    faAr_ZAAD, // ض
    faAr_TAAH, // ط
    faAr_ZAAH, // ظ
    faAr_AIN, // ع
    faAr_GHAIN, // غ
    faAr_FEH, // ف
    faAr_QAAF, // ق
    faAr_KAAF, // ک
    faAr_KAAF_NO_HEAD, // ك
    faAr_GAAF, // گ
    faAr_LAAM, // ل
    faAr_MEEM, // م
    faAr_NOON, // ن
    faAr_VAAV, // و
    faAr_HEH, // ه
    faAr_YEH, // ی
    faAr_ARABIC_YEH, // ي
    faAr_ALEF_MAKSURA, // ى
    faAr_TATWEEL, // ـ
    faAr_LAAM_ALEF, // لا
    faAr_LAAM_ALEF_HAMZA_ABOVE, // لأ
};

enum FarsiArabicAlphabets_ArabicNames_
{
    faAr_ALEF_HAMZA_ABOVE = faAr_ALEF_HAMZEH_ABOVE,
    faAr_ALEF_MADDA_ABOVE = faAr_ALEF_MAD_ABOVE,
    faAr_HAMZA = faAr_HAMZEH,
    faAr_WAAW_HAMZA_ABOVE = faAr_VAAV_HAMZEH_ABOVE,
    faAr_ALEF_HAMZA_BELOW = faAr_ALEF_HAMZEH_BELOW,
    faAr_YEH_HAMZA_ABOVE = faAr_YEH_HAMZEH_ABOVE,
    faAr_TEH_MARBUTA = faAr_TEH_TANIS,
    faAr_THEH = faAr_SEH,
    faAr_HAH = faAr_HEH_JEEMY,
    faAr_THAAL = faAr_ZAAL,
    faAr_ZAIN = faAr_ZEH,
    faAr_DAAD = faAr_ZAAD,
    faAr_KAAF_ARABIC = faAr_KAAF_NO_HEAD,
    faAr_KEHEH = faAr_KAAF,
    faAr_WAAW = faAr_VAAV
};

enum FarsiArabicAlphabets_Forms_
{
    faAr_Unicode,
    faAr_Isolated,
    faAr_Beginner,
    faAr_Medium,
    faAr_Final,
};

extern const std::vector<std::vector<std::string>> FaAr_AlphabetsAllForms;

enum HebrewAlphabets_
{
    he_ALEF, // א
    he_BET, // ב
    he_GIMEL, // ג
    he_DALET, // ד
    he_HEI, // ה
    he_VAV, // ו
    he_ZAYIN, // ז
    he_CHET, // ח
    he_TET, // ט
    he_YOD, // י
    he_KAF, // כ
    he_KAF_SOFIT, // ך
    he_LAMED, // ל
    he_MEM, // מ
    he_MEM_SOFIT, // ם
    he_NUN, // נ
    he_NUN_SOFIT, // ן
    he_SAMEKH, // ס
    he_AYIN, // ע
    he_PEI, // פ
    he_PEI_SOFIT, // ף
    he_TSADIK, // צ
    he_TSADIK_SOFIT, // ץ
    he_KUF, // ק
    he_RAYSH, // ר
    he_SHIN, // ש
    he_TAV, // ת
};

namespace RTLScript
{
    /// <summary>Get Farsi/Arabic character place in a word for its form, depending its previous and next character.</summary>
    /// <param name="fa_character">Character you want to check its place.</param>
    /// <param name="prevFAChar">Previous character, to check if its connected to fa_character or not.</param>
    /// <param name="nextFAChar">Next character, to check if its connected to fa_character or not.</param>
    /// <returns>Returns an int in type of a char. Possible values: 0- no connection, 1- connected from behind, 2- connected from front, 3- connected from both side.</returns>
    unsigned char GetFACharPlace(const std::string& fa_character, const std::string& prevFAChar, const std::string& nextFAChar);

    /// <summary>Check if given character is a Farsi/Arabic letter in beginner form or not.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsFACharBeginner(const std::string& fa_character);

    /// <summary>Find vector index of the give character in fa_AlphabetsAllForms vector</summary>
    /// <param name="fa_character">Character you want get its index.</param>
    /// <returns>Returns an int in type of a char. Possible values: 0 to 44 (fa_AlphabetsAllForms array size).</returns>
    size_t FindFACharIndex(const std::string& fa_character);

    /// <summary>Check if given character is a Farsi/Arabic letter or not.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsFAChar(const std::string& fa_character);

    /// <summary> String of two chars to Codepoint. </summary>
    /// <param name="str">String to get codepoint from.</param>
    /// <returns>Returns a int value.</returns>
    int StringToCodepoint(const std::string& str);

    /// <summary> Check if the code point is RTL. </summary>
    /// <param name="codepoint">A codepoint of a unicode char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsRTL(int codepoint);

    /// <summary> Check if the char is punctuation or digit. </summary>
    /// <param name="c">A char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsPunctOrDigit(int c);

    /// <summary>Reverses Farsi/Arabic/Hebrew... string and returns a vector of std::strings, each of them containing RTL letters with different byte counts.</summary>
    /// <param name="str">Farsi/Arabic/Hebrew... string.</param>
    /// <returns>Returns a vector of std::strings.</returns>
    std::vector<std::string> ReverseRTLText(const std::string& str);

    /// <summary>Get correct unicode of Farsi/Arabic letter depending on its position, previous, and next letters.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <param name="prevFAChar">Previous character, to check if its connected to faAr_character or not.</param>
    /// <param name="nextFAChar">Next character, to check if its connected to faAr_character or not.</param>
    /// <returns>Returns a std::string.</returns>
    std::string GetFaArCharGlyph(const std::string& faAr_character, const std::string& prevFAChar, const std::string& nextFAChar);

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
