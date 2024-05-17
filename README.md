RTLType is a very simple library for Farsi/Arabic/Hebrew/etc. strings written in C++20.

RTLType is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType

![RTLTypeLogo](https://github.com/oscar7070/RTLType/assets/56559647/1d01306a-8669-4920-98d4-6554cf16e600)

## Screenshots (using [ImGui](https://github.com/ocornut/imgui) for rendering)
Correct Form:  
![ScreenShot](https://raw.githubusercontent.com/AmyrAhmady/FarsiType/master/screenshots/correctForm.png)
  
Broken:   
![ScreenShot](https://raw.githubusercontent.com/AmyrAhmady/FarsiType/master/screenshots/brokenOne.png)

## About
Hi, i needed RTL text in my project and i found a beautiful repository named FarsiType(https://github.com/AmyrAhmady/FarsiType) and i decided to improve it for my needs.

## How to use it?
RTLType is very easy to use just call "RTLType::ConvertToFixed":
```
#include "RTLType.h"
#include <iostream>

void main()
{
    auto fixedArabicText = RTLType::ConvertToFixed("أنا أحب الأناناس"); // Convert to fixed text.
    std::cout <<fixedArabicText; // Print the result.
}
```

## Known bugs
- If you wrote in RTL and LTR in the same line it's maybe will be broken.
