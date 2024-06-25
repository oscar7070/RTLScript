RTLScript is a very simple library for Farsi/Arabic/Hebrew/Urdu/etc. strings written in C++20.

RTLScript is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType

* Just a logo that i made for fun i Live to make a logos for my Project (: *
![RTLTypeLogo](https://github.com/oscar7070/RTLType/assets/56559647/1d01306a-8669-4920-98d4-6554cf16e600)

## Screenshots (using [ImGui](https://github.com/ocornut/imgui) for rendering through [ExtremeEngine](https://github.com/oscar7070/ExtremeEngine))
Correct Form:  
![ScreenShot](https://github.com/oscar7070/RTLScript/blob/master/screenshots/Fixed.png)
  
Broken:   
![ScreenShot](https://github.com/oscar7070/RTLScript/blob/master/screenshots/Broken.png)

## About
Hi, i needed RTL text in my project and i found a beautiful repository named FarsiType(https://github.com/AmyrAhmady/FarsiType) and i decided to improve it for my needs.

## Features
1. RTLScript have a full support for Arabic, Hebrew, Farsi and Urdu.
2. Support extra symbols like: لا, لأ, لآ, لإ, الله.
2. Very easy to work with it.
3. Support RTL and LTR text in the same line.

## How to use it?
RTLScript is very easy to use just call "RTLScript::ConvertToFixed":
```
#include "RTLScript.h"
#include <iostream>

void main()
{
    auto fixedArabicText = RTLScript::ConvertToFixed("أنا أحب الأناناس"); // Convert to fixed text.
    std::cout <<fixedArabicText; // Print the result.
}
```

## Not working?
First, if it's not working make sure that your project setted to MultiByte or Unicode and not ASCII.

Second, check that you are using /utf-8.

Third, check if your project files saved in utf-8.

Fourth, choose a font that supports that RTL language that you want to use.

## Possible bugs
- If you wrote in RTL and LTR in the same line it's maybe will be broken(but it's very rare i think it's just possible).
