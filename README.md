RTLType is a very simple library for Farsi/Arabic/Hebrew/etc. strings written in C++20.

RTLType is a fork of FarsiType: https://github.com/AmyrAhmady/FarsiType

![RTLTypeLogo](https://github.com/oscar7070/RTLType/assets/56559647/1d01306a-8669-4920-98d4-6554cf16e600)

## Screenshots (using [ImGui](https://github.com/ocornut/imgui) for rendering)
Correct Form:  
![ScreenShot](https://raw.githubusercontent.com/AmyrAhmady/FarsiType/master/screenshots/correctForm.png)
  
Broken:   
![ScreenShot](https://raw.githubusercontent.com/AmyrAhmady/FarsiType/master/screenshots/brokenOne.png)

## About
Hello.  
I decided to do something useful in my free time and I've to admit, I kinda needed a thing like this too!.  
I'm using [ImGui](https://github.com/ocornut/imgui) made by [@ocornut](https://github.com/ocornut/) on a project and I needed to render Farsi texts. Unfortunately I wasn't able to do it for 2 reasons:  
- Farsi/Persian/Arabic, Hebrew languages are RTL which makes them reversed.
- They have 4 forms for each letter, so computer can't find the right one by itself.

So after 3 days of searching for an answer and ways to achieve this, I finally came here with my own library that uses C++11. (I would do it in pure C if it was my choice, but seems like it's not possible in an easy way.)  
Hope you guys find this useful!  
If you found any issue or have any suggestion, feel free to create an issue for it.  
Also, feel free to contribute and make this better for everyone :).  

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
- They exists.
