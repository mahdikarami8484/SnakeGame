# Snake Game in Terminal

  

This is a simple terminal-based snake game developed using C++.

  

## Features

  

- A terminal-based interface with a menu and gameplay screen.

- The ability to control the snake’s movement using keyboard inputs.

- A basic game loop with frame updates.

- Snake body design added and functioning correctly.

- Player speed and game frame rate adjusted for smoother gameplay (**TODO: Frame rate and player speed issues need further adjustments**).

- Fixed issue with time frame and image jumping (**TODO: Need to resolve the time frame and image jumping problem completely**).

  

## How to Compile

 ### Microsoft Windows
1. Download and install MSYS2 from [official website](https://www.msys2.org).

2. Open MSYS2 terminal (MSYS MinGW 64-bit or MSYS2 MinGW 32-bit).

3. Update the package manager:

```bash
pacman -Syu
```

4. Install **make**

- For 64-bit:


```bash
 pacman -S mingw-w64-x86_64-make
```

- For 32-bit:

```bash
pacman -S mingw-w64-i686-make
```

5. Check the installation:

```bash
make --version
```

6. Now in the project directory, simply execute:

```bash
make
```
 ### Linux
Before building the project, ensure that you have the following installed:

- **MinGW-w64**: The cross-compiler for Windows.
- **Make**: A build automation tool.

You can install the necessary tools on Linux using the following commands:

```bash
sudo apt update
sudo apt install mingw-w64 make
```
Now in the project directory, simply execute:
```bash
make
```
## How to run

 **A Windows operating system is required to run this program.**
To run it, just complete the compilation steps first, then enter the build folder and run `snake.exe`


## Contribution

If you have any suggestions or improvements, feel free to submit a pull request.
