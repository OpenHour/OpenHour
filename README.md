# OpenHour
OpenHour is the port of C&C Generals Zero Hour to modern compiler and standard libraries.

## Compilation
What do you need:
- Git
- CMake
- Visual Studio 2022 with C++ and ATL/MFC installed. **You need x86 version!**
- DirectX 8 SDK
- DirectX 9 SDK

1. Clone this repository
2. Download submodules
3. Generate project with CMake. You should set parameters:
    - D3D8_INCLUDE_DIR - point it to your DX 8 SDK include folder
    - D3D8_LIBRARIES - point it to your DX 8 SDK lib folder
    - D3D9_LIBRARIES - point it to your DX 9 SDK lib folder
4. Compile it!
5. ???
6. PROFIT

### NOTE: 
If you get error like this: `error C2146: syntax error : missing ';' before identifier 'PVOID64'`
You need to patch your `winnt.h` file. Just replace `typedef void * POINTER_64 PVOID64;` with `typedef void *PVOID64;`.

## FAQ
- Q: Does it work?
- A: Yeah, somewhat. You may experience bugs and crashes but it can be played.


- Q: I don't want C&C General Zero Hour!
- A: Use commit 4bb4ccb67ef404e1db23ab7fe2768f082dcef4ac. It's the last commit before base game was removed.

## What works
- Game

## What doesn't
- Audio
- Bink videos

## Changes
- Removed STLport dependency
- Removed GameSpy dependency
- Removed Bink dependency
- Removed Miles Audio System dependency
- Removed web browser

## License
This repository and its contents are licensed under the GPL v3 license, with additional terms applied. Please see [LICENSE.md](LICENSE.md) for details.
