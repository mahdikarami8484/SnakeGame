# Snake Game in Terminal

This is a simple terminal-based snake game developed using C++.

## Requirements

The game uses the following libraries:
- `windows.h`
- `iostream`
- `map`
- `cstdlib`
- `thread`
- `chrono`
- `random`
- `ctime`

Note: This program is only compatible with Windows because it uses the `Windows.h` library.

## Features

- A terminal-based interface with a menu and gameplay screen.
- The ability to control the snake’s movement using keyboard inputs.
- A basic game loop with frame updates.
- Snake body design added and functioning correctly.
- Player speed and game frame rate adjusted for smoother gameplay (**TODO: Frame rate and player speed issues need further adjustments**).
- Fixed issue with time frame and image jumping (**TODO: Need to resolve the time frame and image jumping problem completely**).

## How to Compile and Run
1. Download and install MSYS2 from [official website](www.msys2.org).
2. Open MSYS2 terminal (MSYS MinGW 64-bit or MSYS2 MinGW 32-bit).
3. Update the package manager:
```
pacman -Syu
```
4. Install **make**
- For 64-bit:
```
pacman -S mingw-w64-x86_64-make
```
- For 32-bit:
```
pacman -S mingw-w64-i686-make
```
5. Check the installation:
```
make --version
```
6. Now in the project directory, simply execute:
```
make
```

## Contribution
If you have any suggestions or improvements, feel free to submit a pull request (PR).