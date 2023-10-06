# About

~~An extremely basic external csgo cheat using imgui and winapi, alongside basic memory reading and writing practices~~

Due to the global release of  [CS2](https://www.counter-strike.net/cs2), CS:GO has been shut down.

So because of this, until widespread knowledge regarding CS2 and its vulnerabilities, this source no longer works, the repo will still be up and [compiled versions](https://github.com/ridhwan2/imgui-external-csgo/releases) are available likewise.

For those curious, this is because the [GetModuleAddress](https://github.com/ridhwan2/imgui-external-csgo/blob/main/cheat/memory.h#L48) and subsequently, [ReadMemory](https://github.com/ridhwan2/imgui-external-csgo/blob/main/cheat/memory.h#L74), and [WriteMemory](https://github.com/ridhwan2/imgui-external-csgo/blob/main/cheat/memory.h#L83) functions no longer work in the memory class, even if these did work, offsets are not easily avaliable. So until cazz updates the memory class there's not much I can do.

## Credits
- [cazz](https://www.youtube.com/@cazz)
- [imgui](https://github.com/ocornut/imgui)
- [hazedumper](https://github.com/frk1/hazedumper)

## License

> [MIT](https://opensource.org/license/mit/) 2023 Ridhwan
> 
> Some parts of the software may be made by other people
