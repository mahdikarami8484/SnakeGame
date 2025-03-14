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
1. Make sure you are on a Windows machine.
2. Download and install MSYS2 from [official website](www.msys2.org).
3. Open MSYS2 terminal (MSYS MinGW 64-bit or MSYS2 MinGW 32-bit).
4. Update the package manager:
```
pacman -Syu
```
5. Install **make**
- For 64-bit:
```
pacman -S mingw-w64-x86_64-make
```
- For 32-bit:
```
pacman -S mingw-w64-i686-make
```
6. Check the installation:
```
make --version
```
7. Now in the project directory, simply execute:
```
make
```
8. Execute **snake.exe**

**Note**: Bear in mind that this program needs to be executed directly through Command Prompt (cmd.exe). It might not work properly in other environments.

## Contribution
If you have any suggestions or improvements, feel free to submit a pull request (PR).