# About

An extremely basic external csgo cheat using Imgui

## Installation

- Download as zip
- Open the .sln file
- Go to your project settings and make sure that your C++ language standard is __ISO C++20__, and you are using a __multi byte character set__
- Build or Debug as "Release x86"


## Info & Contribution

The point of this external is to do a lot of the heavy lifting for you and make it easy to add features, feel free to use as you want, also keep note that, *i'm not responsible for any kind of penality that you may get*

Offsets may need to be updated since the cheat is external, therefore I have made it pretty easy

- go to csgo-external/cheat/globals.h
- look for the namespace "offsets"
- update using [hazedumpers offsets](https://github.com/frk1/hazedumper/blob/master/csgo.hpp)

If your instantly crashing then make sure that you have the proper [runtime](https://aka.ms/vs/17/release/vc_redist.x64.exe) installed

## Credits
- [hazedumper](https://github.com/frk1/hazedumper) for their offsets
- cazz's [memory class](https://github.com/cazzwastaken/pro-bhop/blob/master/cheat/memory.h) & [youtube channel](https://www.youtube.com/@cazz) (the features and base are from his youtube channel after all)
- [stackedit](https://stackedit.io/) for helping me write this

## License

[MIT](https://opensource.org/license/mit/) (2023-)
