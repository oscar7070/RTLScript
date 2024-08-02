// RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType
#pragma once

#include <string>
#include <vector>

#ifndef RTLSCRIPT_H
#define RTLSCRIPT_H

// RTLScript version.
constexpr auto RTLSCRIPT_VERSION = "1.5";
// RTLScript version number.
constexpr auto RTLSCRIPT_VERSION_NUM = 150;
constexpr auto RTLSCRIPT_STABLE_RELEASE_NAME = "STABLE", RTLSCRIPT_PREVIEW_RELEASE_NAME = "PREVIEW", RTLSCRIPT_BETA_RELEASE_NAME = "BETA";
// RTLScript release type for exemple: STABLE, PREVIEW, BETA.
constexpr auto RTLSCRIPT_RELEASE_TYPE = RTLSCRIPT_STABLE_RELEASE_NAME;

// Properties for ConvertToFixed() function.
struct RTLScriptConverterProperties
{
public:
    bool JoiningArabicLetters = true;
    // Enables: الله
    bool EnableSpecialWordAllahForm = true;
    // Enables: لا
    bool EnableJointLaamAlifForm = true;
    //bool ReverseRTL = true;

    //RTLScriptConverterProperties(bool joiningArabicLetters = true, bool enableSpecialWordAllahForm = true, bool enableJointLaamAlifForm = true, bool reverseRTL = true)
    //{
    //    JoiningArabicLetters = joiningArabicLetters;
    //    EnableSpecialWordAllahForm = enableSpecialWordAllahForm;
    //    EnableJointLaamAlifForm = enableJointLaamAlifForm;
    //    //ReverseRTL = reverseRTL;
    //}
};

const RTLScriptConverterProperties DefaultConverterProperties{ true, true, true }; //, true };

enum ArabicTashkil
{
    AR_TASHKIL_FATHA,      // اَ
    AR_TASHKIL_FATHATAN,   // اً
    AR_TASHKIL_DAMMA,      // اُ
    AR_TASHKIL_DAMMATAN,   // اٌ
    AR_TASHKIL_KASRA,      // اِ
    AR_TASHKIL_KASRATAN,   // اٍ
    AR_TASHKIL_SUKUN,      // اْ
    AR_TASHKIL_SHADDA,     // اّ

    AR_TASHKIL_ALIF_KHANJARIA, // اٰ

    AR_SMALL_HIGH_DOTLESS_HEAD_OF_KHA,// ۡ
};

enum ArabicTashkeel_FarsiNames
{
    FA_TASHKEEL_FATHEH = AR_TASHKIL_FATHA,
    FA_TASHKEEL_TANVIN_NASB = AR_TASHKIL_FATHATAN,
    FA_TASHKEEL_ZAMMEH = AR_TASHKIL_DAMMA,
    FA_TASHKEEL_TANVIN_RAF = AR_TASHKIL_DAMMATAN,
    FA_TASHKEEL_KASREH = AR_TASHKIL_KASRA,
    FA_TASHKEEL_TANVIN_JARR = AR_TASHKIL_KASRATAN,
    FA_TASHKEEL_SOKOON = AR_TASHKIL_SUKUN,
    FA_TASHKEEL_TASHDID = AR_TASHKIL_SHADDA,

    FA_TASHKIL_ALIF_KHANJARA = AR_TASHKIL_ALIF_KHANJARIA,

    FA_TASHKEEL_KHA = AR_SMALL_HIGH_DOTLESS_HEAD_OF_KHA,
};

const size_t Ar_TashkilAllDiacriticsLeanth = 10;
const std::string Ar_TashkilAllDiacritics[Ar_TashkilAllDiacriticsLeanth] =
{
    {"َ"}, // AR_TASHKIL_FATHA,      // اَ
    {"ً"}, // AR_TASHKIL_FATHATAN,   // اً
    {"ُ"}, // AR_TASHKIL_DAMMA,      // اُ
    {"ٌ"}, // AR_TASHKIL_DAMMATAN,   // اٌ
    {"ِ"}, // AR_TASHKIL_KASRA,      // اِ
    {"ٍ"}, // AR_TASHKIL_KASRATAN,   // اٍ
    {"ْ"}, // AR_TASHKIL_SUKUN,      // اْ
    {"ّ"}, // AR_TASHKIL_SHADDA,     // اّ

    {"ٰ"}, // AR_TASHKIL_ALIF_KHANJARIA, // اٰ

    {"ۡ"},// AR_SMALL_HIGH_DOTLESS_HEAD_OF_KHA, // ۡ
};

enum ArabicAlphabet
{
    // Arabic
    AR_ALIF_HAMZA_ABOVE, // أ
    AR_ALIF, // ا
    AR_ALIF_MADDAH_ABOVE, // آ
    AR_HAMZA, // ء
    AR_WAW_HAMZA_ABOVE, // ؤ
    AR_ALIF_HAMZA_BELOW, // إ
    AR_YEH_HAMZA_ABOVE, // ئ
    AR_BEH, // ب
    AR_TEH, // ت
    AR_TEH_MARBUTA, // ة
    AR_THEH, // ث
    AR_JEEM, // ج
    AR_HETH, // ح
    AR_KHA, // خ
    AR_DAAL, // د
    AR_THAAL, // ذ
    AR_REH, // ر
    AR_ZAIN, // ز
    AR_SEEN, // س
    AR_SHEEN, // ش
    AR_SAAD, // ص
    AR_DAAD, // ض
    AR_TAAH, // ط
    AR_ZAAH, // ظ
    AR_AIN, // ع
    AR_GHAIN, // غ
    AR_FEH, // ف
    AR_QAAF, // ق
    AR_KAAF, // ک
    AR_KAAF_NO_HEAD, // ك
    AR_LAAM, // ل
    AR_MEEM, // م
    AR_NOON, // ن
    AR_WAW, // و
    AR_HA, // ه
    AR_YEH, // ی
    AR_ARABIC_YEH, // ي
    AR_ALIF_MAKSURA, // ى
    AR_TATWEEL, // ـ

    // Arabic special chars
    AR_LAAM_ALIF, // لا
    AR_LAAM_ALIF_HAMZA_ABOVE, // لأ
    AR_LAAM_ALIF_HAMZA_BELOW, // لإ
    AR_LAAM_ALIF_MADDAH_ABOVE, // لآ
    AR_ALLAH, // ﷲ

    // Farsi
    AR_EXT_FA_PEH, // پ
    AR_EXT_FA_GAAF, // گ
    AR_EXT_FA_CHEH, // چ
    AR_EXT_FA_JEH, // ژ

    // Urdu
    AR_EXT_UR_TE, // ٹ
    AR_EXT_UR_DAL, // ڈ
    AR_EXT_UR_RE, // ڑ
    AR_EXT_UR_NUNGHUNNA, // ں
    AR_EXT_UR_BARIYE, // ے
    AR_EXT_UR_HE, // ھ
    AR_EXT_UR_HA, // ہ
};

enum ArabicAlphabet_FarsiNames
{
    FA_ALEF_HAMZEH_ABOVE = AR_ALIF_HAMZA_ABOVE,
    FA_ALEF_MAD_ABOVE = AR_ALIF_MADDAH_ABOVE,
    FA_HAMZA,
    FA_VAAV_HAMZEH_ABOVE = AR_WAW_HAMZA_ABOVE,
    FA_ALEF_HAMZEH_BELOW = AR_ALIF_HAMZA_BELOW,
    FA_YEH_HAMZEH_ABOVE = AR_YEH_HAMZA_ABOVE,
    FA_TEH_TANIS = AR_TEH_MARBUTA,
    FA_SEH = AR_THEH,
    FA_HEH_JEEMY = AR_HETH,
    FA_ZAAL = AR_THAAL,
    FA_ZEH = AR_ZAIN,
    FA_ZAAD = AR_DAAD,
    FA_VAAV = AR_WAW
};

enum ArabicLetterForm
{
    AR_FORMS_UNICODE,
    AR_FORMS_ISOLATED,
    AR_FORMS_BEGINNER,
    AR_FORMS_MEDIUM,
    AR_FORMS_FINAL,
};

constexpr const char* RTLSCRIPT_NOT_AR_CHAR = "!AR";

const size_t Ar_AlphabetAllLettersLeanth = 55;
const std::string Ar_AlphabetAllLetters[Ar_AlphabetAllLettersLeanth][5] =
{
    // Arabic
    {"\u0623", "\ufe83", "\u0623", "\ufe84", "\ufe84"}, // AR_ALIF_HAMZA_ABOVE, // أ
    {"\u0627", "\ufe8d", "\u0627", "\ufe8e", "\ufe8e"}, // AR_ALIF, // ا
    {"\u0622", "\ufe81", "\u0622", "\ufe82", "\ufe82"}, // AR_ALIF_MADDAH_ABOVE, // آ
    {"\u0621", "\ufe80", "\u0621", "\u0621", "\u0621"}, // AR_HAMZA, // ء
    {"\u0624", "\ufe85", "\u0624", "\ufe86", "\ufe86"}, // AR_WAW_HAMZA_ABOVE, // ؤ
    {"\u0625", "\ufe87", "\u0625", "\ufe88", "\ufe88"}, // AR_ALIF_HAMZA_BELOW, // إ
    {"\u0626", "\ufe89", "\ufe8b", "\ufe8c", "\ufe8a"}, // AR_YEH_HAMZA_ABOVE, // ئ
    {"\u0628", "\ufe8f", "\ufe91", "\ufe92", "\ufe90"}, // AR_BEH, // ب
    {"\u062A", "\ufe95", "\ufe97", "\ufe98", "\ufe96"}, // AR_TEH, // ت
    {"\u0629", "\ufe93", "\u0629", "\u0629", "\ufe94"}, // AR_TEH_MARBUTA, // ة
    {"\u062b", "\ufe99", "\ufe9b", "\ufe9c", "\ufe9a"}, // AR_THEH, // ث
    {"\u062c", "\ufe9d", "\ufe9f", "\ufea0", "\ufe9e"}, // AR_JEEM, // ج
    {"\u062d", "\ufea1", "\ufea3", "\ufea4", "\ufea2"}, // AR_HAH, // ح
    {"\u062e", "\ufea5", "\ufea7", "\ufea8", "\ufea6"}, // AR_KHEH, // خ
    {"\u062f", "\ufea9", "\u062f", "\ufeaa", "\ufeaa"}, // AR_DAAL, // د
    {"\u0630", "\ufeab", "\u0630", "\ufeac", "\ufeac"}, // AR_THAAL, // ذ
    {"\u0631", "\ufead", "\u0631", "\ufeae", "\ufeae"}, // AR_REH, // ر
    {"\u0632", "\ufeaf", "\u0632", "\ufeb0", "\ufeb0"}, // AR_ZAIN, // ز
    {"\u0633", "\ufeb1", "\ufeb3", "\ufeb4", "\ufeb2"}, // AR_SEEN, // س
    {"\u0634", "\ufeb5", "\ufeb7", "\ufeb8", "\ufeb6"}, // AR_SHEEN, // ش
    {"\u0635", "\ufeb9", "\ufebb", "\ufebc", "\ufeba"}, // AR_SAAD, // ص
    {"\u0636", "\ufebd", "\ufebf", "\ufec0", "\ufebe"}, // AR_DAAD, // ض
    {"\u0637", "\ufec1", "\ufec3", "\ufec4", "\ufec2"}, // AR_TAAH, // ط
    {"\u0638", "\ufec5", "\ufec7", "\ufec8", "\ufec6"}, // AR_ZAAH, // ظ
    {"\u0639", "\ufec9", "\ufecb", "\ufecc", "\ufeca"}, // AR_AIN, // ع
    {"\u063a", "\ufecd", "\ufecf", "\ufed0", "\ufece"}, // AR_GHAIN, // غ
    {"\u0641", "\ufed1", "\ufed3", "\ufed4", "\ufed2"}, // AR_FEH, // ف
    {"\u0642", "\ufed5", "\ufed7", "\ufed8", "\ufed6"}, // AR_QAAF, // ق
    {"\u06a9", "\ufb8e", "\ufb90", "\ufb91", "\ufb8f"}, // AR_KAAF, // ک
    {"\u0643", "\ufed9", "\ufedb", "\ufedc", "\ufeda"}, // AR_KAAF_NO_HEAD, // ك
    {"\u0644", "\ufedd", "\ufedf", "\ufee0", "\ufede"}, // AR_LAAM, // ل
    {"\u0645", "\ufee1", "\ufee3", "\ufee4", "\ufee2"}, // AR_MEEM, // م
    {"\u0646", "\ufee5", "\ufee7", "\ufee8", "\ufee6"}, // AR_NOON, // ن
    {"\u0648", "\ufeed", "\ufeed", "\ufeee", "\ufeee"}, // AR_WAW, // و
    {"\u0647", "\ufee9", "\ufeeb", "\ufeec", "\ufeea"}, // AR_HA, // ه
    {"\u06cc", "\ufbfc", "\ufbfe", "\ufbff", "\ufbfd"}, // AR_YEH, // ی
    {"\u064a", "\ufef1", "\ufef3", "\ufef4", "\ufef2"}, // AR_ARABIC_YEH, // ي
    {"\u0649", "\ufeef", "\u0649", "\ufef0", "\ufef0"}, // AR_ALIF_MAKSURA, // ى
    {"\u0640", "\u0640", "\u0640", "\u0640", "\u0640"}, // AR_TATWEEL, // ـ

    {"\ufefb", "\ufefb", "\ufefb", "\ufefc", "\ufefc"}, // AR_LAAM_ALIF, // لا
    {"\ufef7", "\ufef7", "\ufef7", "\ufef8", "\ufef8"}, // AR_LAAM_ALIF_HAMZA_ABOVE, // لأ
    {"\ufef9", "\ufef9", "\ufef9", "\ufefa", "\ufefa"}, // AR_LAAM_ALIF_HAMZA_BELOW, // لإ
    {"\ufef5", "\ufef5", "\ufef5", "\ufef6", "\ufef6"}, // AR_LAAM_ALIF_MADDAH_ABOVE, // لآ
    {"\ufdf2", "\ufdf2", "\ufdf2", "\ufdf2", "\ufdf2"}, // AR_ALLAH, // ﷲ

    // Farsi
    {"\u067e", "\ufb56", "\ufb58", "\ufb59", "\ufb57"}, // AR_EXT_FA_PEH, // پ
    {"\u06af", "\ufb92", "\ufb94", "\ufb95", "\ufb93"}, // AR_EXT_FA_GAAF, // گ
    {"\u0686", "\ufb7a", "\ufb7c", "\ufb7d", "\ufb7b"}, // AR_EXT_FA_CHEH, // چ
    {"\u0698", "\ufb8a", "\u0698", "\ufb8b", "\ufb8b"}, // AR_EXT_FA_JEH, // ژ

    // Urdu
    {"\u0679", "\ufb66", "\ufb68", "\ufb69", "\ufb67"}, // AR_EXT_UR_TE  , // ٹ
    {"\u0688", "\ufb88", "\ufb88", "\ufb89", "\ufb89"}, // AR_EXT_UR_DAL, // ڈ
    {"\u0691", "\ufb8c", "\ufb8c", "\ufb8d", "\ufb8d"}, // AR_EXT_UR_RE, // ڑ
    {"\u06ba", "\ufb9e", "\ufb9e", "\ufb9f", "\ufb9f"}, // AR_EXT_UR_NUNGHUNNA, // ں
    {"\u06d2", "\ufbae", "\ufbae", "\ufbaf", "\ufbaf"}, // AR_EXT_UR_BARIYE, // ے
    {"\u06be", "\ufbaa", "\ufbac", "\ufbad", "\ufbab"}, // AR_EXT_UR_HE, // ھ
    {"\u06c1", "\ufba6", "\ufba8", "\ufba9", "\ufba7"}, // AR_EXT_UR_HA, // ہ
};

enum HebrewAlphabet
{
    HE_ALEF, // א
    HE_BET, // ב
    HE_GIMEL, // ג
    HE_DALET, // ד
    HE_HEI, // ה
    HE_VAV, // ו
    HE_ZAYIN, // ז
    HE_CHET, // ח
    HE_TET, // ט
    HE_YOD, // י
    HE_KAF, // כ
    HE_KAF_SOFIT, // ך
    HE_LAMED, // ל
    HE_MEM, // מ
    HE_MEM_SOFIT, // ם
    HE_NUN, // נ
    HE_NUN_SOFIT, // ן
    HE_SAMEKH, // ס
    HE_AYIN, // ע
    HE_PEI, // פ
    HE_PEI_SOFIT, // ף
    HE_TSADIK, // צ
    HE_TSADIK_SOFIT, // ץ
    HE_KUF, // ק
    HE_RAYSH, // ר
    HE_SHIN, // ש
    HE_TAV, // ת
};

const size_t He_AlphabetAllLettersLeanth = 27;
const std::string He_AlphabetAllLetters[He_AlphabetAllLettersLeanth] =
{
    "א", // HE_ALEF, // א
    "ב", // HE_BET, // ב
    "ג", // HE_GIMEL, // ג
    "ד", // HE_DALET, // ד
    "ה", // HE_HEI, // ה
    "ו", // HE_VAV, // ו
    "ז", // HE_ZAYIN, // ז
    "ח", // HE_CHET, // ח
    "ט", // HE_TET, // ט
    "י", // HE_YOD, // י
    "כ", // HE_KAF, // כ
    "ך", // HE_KAF_SOFIT, // ך
    "ל", // HE_LAMED, // ל
    "מ", // HE_MEM, // מ
    "ם", // HE_MEM_SOFIT, // ם
    "נ", // HE_NUN, // נ
    "ן", // HE_NUN_SOFIT, // ן
    "ס", // HE_SAMEKH, // ס
    "ע", // HE_AYIN, // ע
    "פ", // HE_PEI, // פ
    "ף", // HE_PEI_SOFIT, // ף
    "צ", // HE_TSADIK, // צ
    "ץ", // HE_TSADIK_SOFIT, // ץ
    "ק", // HE_KUF, // ק
    "ר", // HE_RAYSH, // ר
    "ש", // HE_SHIN, // ש
    "ת", // HE_TAV, // ת
};

namespace RTLScript
{
    /// <summary>Get Arabic/Farsi/Urdu character place in a word for its form, depending its previous and next character.</summary>
    /// <param name="arCharacter">Character you want to check its place.</param>
    /// <param name="prevARChar">Previous character, to check if its connected to arCharacter or not.</param>
    /// <param name="nextARChar">Next character, to check if its connected to arCharacter or not.</param>
    /// <returns>Returns an int in type of a char. Possible values: 0- no connection, 1- connected from behind, 2- connected from front, 3- connected from both side.</returns>
    ArabicLetterForm GetARCharPlace(const std::string& arCharacter, const std::string& prevARChar, const std::string& nextARChar);

    /// <summary>Check if given character is a Arabic letter in beginner form or not.</summary>
    /// <param name="arCharacter">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsArCharBeginner(const std::string& arCharacter);

    /// <summary>Find vector index of the give character in Ar_AlphabetsAllForms vector</summary>
    /// <param name="arCharacter">Character you want get its index.</param>
    /// <returns>Returns an int in type of a char. Possible values: (ِِAr_AlphabetsAllForms array size).</returns>
    size_t FindARCharIndex(const std::string& arCharacter);

    /// <summary>Check if given character is a Arabic letter or not.</summary>
    /// <param name="arCharacter">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsARChar(const std::string arCharacter);

    /// <summary>Check if given Arabic character is the Arabic letter that you want to check for.</summary>
    /// <param name="arCharacter">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool CheckForARChar(const std::string arCharacter, ArabicAlphabet checkFor);

    /// <summary> String of two chars to Codepoint. </summary>
    /// <param name="str">String to get codepoint from.</param>
    /// <returns>Returns a int value.</returns>
    int GetCodepointFromString(const std::string str);

    /// <summary> Check if the code point is RTL. </summary>
    /// <param name="codepoint">A codepoint of a unicode char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsRTL(const int codepoint);

    /// <summary> Check if the char is punctuation or digit. </summary>
    /// <param name="c">A char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsPunctOrDigit(const int c);

    /// <summary>Reverses Arabic/Farsi/Hebrew/Urdu... string and returns a vector of std::strings, each of them containing RTL letters with different byte counts.</summary>
    /// <param name="str">Arabic/Farsi/Hebrew/Urdu... string.</param>
    /// <returns>Returns a vector of std::strings.</returns>
    std::vector<std::string> ReverseRTLText(const std::string& str);

    /// <summary>Checks if the Arabic character is represents any type of LaamAlif.</summary>
    /// <param name="str">A char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool CheckForAnyTypeOfLaamAlif(const std::string arCharacter);

    /// <summary>Checks if the Arabic character is represents any type of arabic diacritic.</summary>
    /// <param name="str">A char.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool CheckForAnyArabicDiacritic(const std::string arCharacter);

    /// <summary>Get's the previous char ignoring diacritic char.</summary>
    /// <param name="str">A char element.</param>
    /// <returns>Returns a int value if the value is -1 nothing found.</returns>
    int GetPreviousCharElementIgnoringDiacritic(const std::vector<std::string> text, int element);

    /// <summary>Get's the next char ignoring diacritic char.</summary>
    /// <param name="str">A char element.</param>
    /// <returns>Returns a int value if the value is -1 nothing found.</returns>
    int GetNextCharElementIgnoringDiacritic(const std::vector<std::string> text, int element);

    /// <summary>Get correct unicode of Arabic/Farsi/Urdu letter depending on its position, previous, and next letters.</summary>
    /// <param name="arCharacter">Character you want to check.</param>
    /// <param name="prevARChar">Previous character, to check if its connected to arCcharacter or not.</param>
    /// <param name="nextARChar">Next character, to check if its connected to arCharacter or not.</param>
    /// <returns>Returns a std::string.</returns>
    std::string GetARCharGlyph(const std::string& arCharacter, const std::string& prevARChar, const std::string& nextARChar);

    //void CheckForARWordAndReplace(const std::vector<ArabicAlphabets> checkFor, const std::string replaceTo, std::vector<std::string>& text);

    /// <summary>Converts a Arabic/Farsi/Urdu/Hebrew... string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text">Arabic/Farsi/Urdu/Hebrew... text.</param>
    /// <returns>Returns a std::string. Fixed Arabic/Farsi/Urdu/Hebrew... string</returns>
    /// <param name="properties">Properties for the converter. if NULL will use default properties.</param>
    std::string ConvertToFixed(const std::string& text, RTLScriptConverterProperties* properties = NULL);

    /// <summary>Converts a Arabic/Farsi/Urdu/Hebrew... string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text">Arabic/Farsi/Urdu/Hebrew... text.</param>
    /// <returns>Returns a const char*. Fixed Arabic/Farsi/Urdu/Hebrew... string</returns>
    /// <param name="properties">Properties for the converter. if NULL will use default properties.</param>
    const char* ConvertToFixed(const char* text, RTLScriptConverterProperties* properties = NULL);

    /// <summary>Converts a Arabic/Farsi/Urdu/Hebrew... string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text_begin">Arabic/Farsi/Urdu/Hebrew... reference for a text beginning.</param>
    /// <param name="text_end">Arabic/Farsi/Urdu/Hebrew... reference for a text ending.</param>
    /// <param name="newStr">Arabic/Farsi/Urdu/Hebrew... reference for new or empty std::string.</param>
    /// <param name="properties">Properties for the converter. if NULL will use default properties.</param>
    void ConvertToFixed(const char*& text_begin, const char*& text_end, std::string& newStr, RTLScriptConverterProperties* properties = NULL);
};
#endif
