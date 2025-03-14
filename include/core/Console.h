// This is a class for manage console window

#ifndef CONSOLE_H
#define CONSOLE_H

// lib 
#include <windows.h>
#include <iostream>

// config
#include "core/Config.h"

class Console 
{
    public:

        // Constructor function
        Console();

        // Enum for text properties
        enum Colors : WORD {
            BLACK = 0x0000,
            BLUE = FOREGROUND_BLUE,
            GREEN = FOREGROUND_GREEN,
            CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
            RED = FOREGROUND_RED,
            MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
            YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
            WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        };

        enum Text_Attr : WORD {
            NORMAL = 0,
            DIM              = 0x0002, // کم‌رنگ
            BRIGHT           = 0x0008, // پررنگ
            UNDERLINE        = 0x8000, // زیرخط
            BLINK            = 0x0010, // چشمک‌زن
            REVERSE_VIDEO    = 0x0200, // معکوس کردن رنگ‌ها
            HIDDEN           = 0x0800  // مخفی
        };


        // Struct for console info
        struct Info {
            COORD size;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
        };


        // Variables 
        HANDLE hConsole;
        Info info;


        // Functions
        void get_info();

        void moveCursor(int x, int y);

        void clear();

        void write(std::string chars,
            Colors color,
            Colors bg,
            Text_Attr text_attr,
            bool endline,
            COORD pos
        );
};


#endif