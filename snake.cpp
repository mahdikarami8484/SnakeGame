// To do: add game over view 

#include <windows.h>
#include <iostream>
#include <map>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <cmath>

// Default colors
#define DEFAULT_BACKGROUND_COLOR Console::Colors::BLACK
#define DEFAULT_COLOR Console::Colors::WHITE

class Console 
{
    public:

        Console()
        {
            this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        }

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

        struct Info {
            COORD size;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
        };

        HANDLE hConsole;
        Info info;

        void get_info()
        {   
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            
            if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
                int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
                int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
                
                this->info = {static_cast<SHORT>(width), static_cast<SHORT>(height), csbi}; 
            } else {
                std::cerr << "Error retrieving console size!" << std::endl;
            }
        }

        void moveCursor(int x, int y) {
            COORD coord;
            coord.X = x;
            coord.Y = y;

            SetConsoleCursorPosition(hConsole, coord);
        }

        void clear()
        {
            DWORD dwWritten;
            FillConsoleOutputCharacter(hConsole,
                ' ',
                this->info.size.X * this->info.size.Y,
                {0, 0},
                &dwWritten
            );

            FillConsoleOutputAttribute(hConsole, 
                this->info.csbi.wAttributes, 
                this->info.size.X * this->info.size.Y,
                {0, 0}, 
                &dwWritten
            );

            moveCursor(0, 0);
        }

        void write(std::string chars,
            Colors color = WHITE,
            Colors bg = BLACK,
            Text_Attr text_attr = NORMAL,
            bool endline = false,
            COORD pos = {-1, -1}
        ){
            if(pos.X >= 0 && pos.Y > 0)
                moveCursor(pos.X, pos.Y);

            // Set Attribute 
            SetConsoleTextAttribute(
                hConsole, 
                static_cast<WORD>(color) |
                static_cast<WORD>(bg) << 4 |
                static_cast<WORD>(text_attr)
            );

            // Print chars
            std::cout << chars << ((endline) ? "\n" : "");

            // Reset 
            SetConsoleTextAttribute(
                hConsole,
                DEFAULT_COLOR |
                DEFAULT_BACKGROUND_COLOR << 4
            );
        }

};

class Menu_view
{
    private:
        Console* console;
        int* view;

    public:

        Menu_view(Console* console, int* view)
        {
            this->console = console;
            this->view = view; 
        }

        // Menu options
        std::map<int, std::string> menu_options = 
        {
            { 0, "Start Game" },
            { 1, "Creators"},
            { 2, "Meow"}
        };

        int selected_menu_option = 0;

        void show_menu() 
        {
            int start_y = 5;
            int start_x = 0;
            
            Console::Colors color = Console::Colors::RED;
            Console::Colors bg = DEFAULT_BACKGROUND_COLOR;

            for (const auto& pair : this->menu_options) 
            {
                std::string option;
                

                if(this->selected_menu_option == pair.first)
                {
                    option = "  < " + pair.second + " >  ";
                    bg = Console::Colors::GREEN;
                }else 
                {
                    option = "  " + pair.second + "  ";
                    bg = DEFAULT_BACKGROUND_COLOR;
                }

                start_x = (console->info.size.X - option.size()) / 2;
                console->write(option, 
                    color, 
                    bg, 
                    Console::Text_Attr::BRIGHT, 
                    false, 
                    {static_cast<SHORT>(start_x), static_cast<SHORT>(start_y)}
                );

                start_y += 3;
            }
        }

        void handle_selected_option()
        {
            if(this->selected_menu_option == 0) *view = 1;
        }

        void handle_keys()
        {
            if((GetAsyncKeyState(VK_DOWN) & 0x8000) &&
            (this->selected_menu_option < this->menu_options.size() - 1)
            )
            {
                this->selected_menu_option++;
                Sleep(100);
            }

            if((GetAsyncKeyState(VK_UP) & 0x8000) && 
                (this->selected_menu_option > 0) 
            )
            {
                this->selected_menu_option--;
                Sleep(100);
            }

            if(GetAsyncKeyState(VK_RETURN) & 0x8000)
                this->handle_selected_option();
        }

};

class Game_view 
{
    private:

        Console* console;

        std::chrono::steady_clock::time_point lastMoveTime;
        const int moveDelay = 200;

        void ground()
        {   
            std::string ground_char = "#";
            for (int i = 2; i < console->info.size.X-1; i++)
            {
                console->write(
                    ground_char,
                    Console::Colors::YELLOW,
                    DEFAULT_BACKGROUND_COLOR,
                    Console::Text_Attr::NORMAL,
                    false,
                    { static_cast<SHORT>(i), static_cast<SHORT>(2) }
                );

                console->write(
                    ground_char,
                    Console::Colors::YELLOW,
                    DEFAULT_BACKGROUND_COLOR,
                    Console::Text_Attr::NORMAL,
                    false,
                    { static_cast<SHORT>(i), static_cast<SHORT>(console->info.size.Y-2) }
                );
            }

            for (int i = 2; i <= console->info.size.Y - 2; i++)
            {
                console->write(
                    ground_char,
                    Console::Colors::YELLOW,
                    DEFAULT_BACKGROUND_COLOR,
                    Console::Text_Attr::NORMAL,
                    false,
                    { static_cast<SHORT>(1), static_cast<SHORT>(i) }
                );

                console->write(
                    ground_char,
                    Console::Colors::YELLOW,
                    DEFAULT_BACKGROUND_COLOR,
                    Console::Text_Attr::NORMAL,
                    false,
                    { static_cast<SHORT>(console->info.size.X-2), static_cast<SHORT>(i) }
                );
            }
        }

        int random(int min, int max)
        {
            std::mt19937 gen(static_cast<unsigned int>(std::time(0))); 

            std::uniform_int_distribution<int> dist(min, max);

            int random_number = dist(gen);
            
            return random_number;
        }

    public:
        struct Player {
            COORD pos;
            COORD last_pos;
            COORD direction;
            COORD max_pos;
            COORD min_pos;
            std::string skin = "o";
        };

        std::vector<Player> player;

        struct Food {
            COORD pos;
            std::string skin;
            bool spawned;
        };

        Food food = {
            {0, 0},
            "*",
            false
        };

        int score = 0;

        Game_view(Console* console){
            this->console = console;

            lastMoveTime = std::chrono::steady_clock::now();

            player.push_back(
                {
                    { 
                        static_cast<SHORT>( (this->console->info.size.X - 1) / 2  ), 
                        static_cast<SHORT>( (this->console->info.size.Y - 1) / 2  )
                    },
                    { static_cast<SHORT>(0), static_cast<SHORT>(0) },
                    { static_cast<SHORT>(1), static_cast<SHORT>(0) },
                    { 
                        static_cast<SHORT>( (this->console->info.size.X - 2) ), 
                        static_cast<SHORT>( (this->console->info.size.Y - 2) )
                    },
                    { static_cast<SHORT>( 2 ), static_cast<SHORT>( 2 )},
                }
            );
        }

        void draw()
        {
            this->ground();
            this->draw_player();
            this->draw_food();
        }

        void draw_player()
        {
            for (size_t i = 0; i < player.size(); i++)
            {
                console->write(
                    this->player[0].skin,
                    Console::Colors::GREEN,
                    DEFAULT_BACKGROUND_COLOR,
                    Console::Text_Attr::NORMAL,
                    false,
                    { static_cast<SHORT>(player[i].pos.X), static_cast<SHORT>(player[i].pos.Y) }
                ); 
            }
        }

        void draw_food()
        {
            console->write(
                this->food.skin,
                Console::Colors::MAGENTA,
                DEFAULT_BACKGROUND_COLOR,
                Console::Text_Attr::NORMAL,
                false,
                { static_cast<SHORT>(food.pos.X), static_cast<SHORT>(food.pos.Y) }
            );
            console->write(
                this->food.skin,
                Console::Colors::MAGENTA,
                DEFAULT_BACKGROUND_COLOR,
                Console::Text_Attr::NORMAL,
                false,
                { static_cast<SHORT>(food.pos.X+1), static_cast<SHORT>(food.pos.Y) }
            );
            console->write(
                this->food.skin,
                Console::Colors::MAGENTA,
                DEFAULT_BACKGROUND_COLOR,
                Console::Text_Attr::NORMAL,
                false,
                { static_cast<SHORT>(food.pos.X+1), static_cast<SHORT>(food.pos.Y+1) }
            );
            console->write(
                this->food.skin,
                Console::Colors::MAGENTA,
                DEFAULT_BACKGROUND_COLOR,
                Console::Text_Attr::NORMAL,
                false,
                { static_cast<SHORT>(food.pos.X), static_cast<SHORT>(food.pos.Y+1) }
            );
        }

        void spawn_food()
        {
            if(food.spawned) return;
            food.pos.X = this->random(player[0].min_pos.X + 1, player[0].max_pos.X - 2);
            food.pos.Y = this->random(player[0].min_pos.Y + 1, player[0].max_pos.Y - 2);
            food.spawned = true;
        }

        void add_body()
        {
            player.push_back(
                {
                    { 
                        static_cast<SHORT>(player.back().last_pos.X), 
                        static_cast<SHORT>(player.back().last_pos.Y)
                    },
                    { static_cast<SHORT>(0), static_cast<SHORT>(0) },
                    { static_cast<SHORT>(0), static_cast<SHORT>(0) },
                    { 
                        static_cast<SHORT>( (this->console->info.size.X - 2) ), 
                        static_cast<SHORT>( (this->console->info.size.Y - 2) )
                    },
                    { static_cast<SHORT>( 2 ), static_cast<SHORT>( 2 )},
                }
            );
        }

        void move_player()
        {
           
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMoveTime).count();
            
            if(
                std::abs(player[0].pos.X - food.pos.X) < 2 &&
                std::abs(player[0].pos.Y - food.pos.Y) < 2
            ) this->eat_food();

            if (elapsed < moveDelay)
                return;

            lastMoveTime = now;

            if( 
                player[0].pos.X >= (player[0].max_pos.X) ||
                player[0].pos.X <= (player[0].min_pos.X) ||
                player[0].pos.Y >= (player[0].max_pos.Y) ||
                player[0].pos.Y <= (player[0].min_pos.Y)
            ) return;

            player[0].pos.X += player[0].direction.X;
            player[0].pos.Y += player[0].direction.Y;

            for (size_t i = 0; i < player.size(); i++) 
            {
                player[i].last_pos = player[i].pos;

                if(i == 0)
                {
                    player[i].pos.X += player[i].direction.X;
                    player[i].pos.Y += player[i].direction.Y;
                    continue;
                }

                player[i].pos = player[i-1].last_pos;  
            }
        }

        void eat_food()
        {
            this->food.spawned = false;
            this->score++;
            this->add_body();
        }

        void handle_keys()
        {
            if((GetAsyncKeyState(VK_DOWN) & 0x8000))
            {
                player[0].direction.Y = 1;
                player[0].direction.X = 0;
            }

            if((GetAsyncKeyState(VK_UP) & 0x8000))
            {
                player[0].direction.Y = -1;
                player[0].direction.X = 0;
            }

            
            if((GetAsyncKeyState(VK_RIGHT) & 0x8000))
            {
                player[0].direction.Y = 0;
                player[0].direction.X = 1;
            }

            if((GetAsyncKeyState(VK_LEFT) & 0x8000))
            {
                player[0].direction.Y = 0;
                player[0].direction.X = -1;
            }
        }
};

// Views 
std::map<int, std::string> views = {
    {0, "Menu"}
};

// fps 
const int targetFPS = 20;
const int frameDelay = 1000 / targetFPS;

int main()
{
    int view = 0;

    Console console = Console();

    // Views 
    Menu_view menu = Menu_view(&console, &view);
    console.get_info();
    Game_view game = Game_view(&console);

    Sleep(500);

    while(true)
    {
        console.get_info();
        console.clear();
        
        if (GetAsyncKeyState('Q') & 0x8000) 
        {
            std::cout << "'Q' key pressed!" << std::endl;
            break;
        }

        // Handle Views
        switch (view)
        {
            case 0:
                /* Menu */
                menu.show_menu();
                menu.handle_keys();
                break;
            case 1:
                /* Game */
                game.spawn_food();
                game.draw();

                std::string score = "Score: " + std::to_string(game.score);
                console.write(
                    score,
                    Console::Colors::RED,
                    Console::Colors::CYAN,
                    Console::Text_Attr::BRIGHT,
                    false,
                    { static_cast<SHORT>(( console.info.size.X - score.size()) / 2 ), 1}
                );

                game.move_player();
                game.handle_keys();
                break;
        }

        /* i dont know why have error ): */
        // std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay));

        Sleep(frameDelay);
    }

    return 0;
}
