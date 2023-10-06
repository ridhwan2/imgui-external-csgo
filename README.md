# About

~~An extremely basic external csgo cheat using imgui and winapi, alongside basic memory reading and writing practices~~

Due to the global release of  CS2, CS:GO has been shut down.

So because of this, until widespread knowledge regarding CS2 and its subsequent  vulnerabilities, buy a P2C ;(

## Installation

- Download the source code
- Open the .sln file
- Go to your project settings and make sure that your C++ language standard is `ISO C++20`, and you are using a `multi byte` character set
- Build or Debug as `Release x86`


## Info & Contribution

The point of this external is to do a lot of the heavy lifting for you and make it easy to add features, feel free to use as you want!

Offsets may need to be updated since the cheat is external, therefore I have made it pretty easy

- go to `csgo-external/cheat/globals.h`
- look for the namespace "offsets"
- update using [hazedumpers offsets](https://github.com/frk1/hazedumper/blob/master/csgo.hpp)


## Credits
- [imgui](https://github.com/ocornut/imgui)
- [hazedumper](https://github.com/frk1/hazedumper) for their offsets
- cazz's [memory class](https://github.com/cazzwastaken/pro-bhop/blob/master/cheat/memory.h) & [youtube channel](https://www.youtube.com/@cazz) (some of the features and base are from his youtube channel after all)
- [stackedit](https://stackedit.io/) for helping me write this

## License

> [MIT](https://opensource.org/license/mit/) 2023 Ridhwan
> 
> Some parts of the software may be made by other people, see credits
> for more information
