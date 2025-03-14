// To do: add game over view 
// To do: add a new class for control views

#include <windows.h>
#include <iostream>
#include <map>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>

// Header files
#include "core/Config.h"
#include "core/Console.h"

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
            clear_menu();

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

        void clear_menu() 
        {
            int start_y = 5;
            int start_x = 0;
            
            Console::Colors color = Console::Colors::RED;
            Console::Colors bg = DEFAULT_BACKGROUND_COLOR;

            for (const auto& pair : this->menu_options) 
            {
                std::string option;
                
                option = "  < " + pair.second + " >  ";

                std::string spaces(option.size(), ' ');

                start_x = (console->info.size.X - option.size()) / 2;
                console->write(
                    spaces,
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
            console->clear();
            if(this->selected_menu_option == 0) *view = 1;
        }

        void handle_keys()
        {
            if((GetAsyncKeyState(VK_DOWN) & 0x8000) &&
            (this->selected_menu_option < this->menu_options.size() - 1)
            )
            {
                this->selected_menu_option++;
                show_menu();
                Sleep(100);
            }

            if((GetAsyncKeyState(VK_UP) & 0x8000) && 
                (this->selected_menu_option > 0) 
            )
            {
                this->selected_menu_option--;
                show_menu();
                Sleep(100);
            }

            if(GetAsyncKeyState(VK_RETURN) & 0x8000)
                this->handle_selected_option();
        }

        void update()
        {
            show_menu();
            handle_keys();
        }

};

class Game_view 
{
    private:

        Console* console;

        std::chrono::steady_clock::time_point lastMoveTime;
        const int moveDelay = 200;
        bool started = false;
        
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
        };

        Food food = {
            {0, 0},
            "*",
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

        void start()
        {
            if(started) return;
            this->ground();
            this->spawn_food();
            this->draw_score();
            started = true;
        }

        void draw()
        {
            this->draw_player();
        }

        void draw_score()
        {
            std::string score = "  Score: " + std::to_string(this->score)+"  ";
            console->write(
                    score,
                    Console::Colors::RED,
                    Console::Colors::CYAN,
                    Console::Text_Attr::BRIGHT,
                    false,
                    { static_cast<SHORT>(( console->info.size.X - score.size()) / 2 ), 1}
            );
        }

        void clear_player()
        {
            for (size_t i = 0; i < player.size(); i++)
            {
                console->write(
                    " ",
                    Console::Colors::WHITE,
                    DEFAULT_BACKGROUND_COLOR,
                    Console::Text_Attr::NORMAL,
                    false,
                    { static_cast<SHORT>(player[i].last_pos.X), static_cast<SHORT>(player[i].last_pos.Y) }
                ); 
            }
        }

        void draw_player()
        {
            clear_player();

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
        }

        void spawn_food()
        {
            food.pos.X = this->random(player[0].min_pos.X + 1, player[0].max_pos.X - 2);
            food.pos.Y = this->random(player[0].min_pos.Y + 1, player[0].max_pos.Y - 2);
            draw_food();
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
                player[0].pos.X == food.pos.X &&
                player[0].pos.Y == food.pos.Y
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
            spawn_food();
            this->score++;
            this->draw_score();
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

        void update()
        {
            draw();
            move_player();
            handle_keys();
        }
};

// Views 
std::map<int, std::string> views = {
    {0, "Menu"}
};

// fps 
const int targetFPS = 30;
const int frameDelay = 1000 / targetFPS;

int main()
{
    int view = 0;

    Console console = Console();

    // Views 
    Menu_view menu = Menu_view(&console, &view);
    console.get_info();

    Game_view game = Game_view(&console);

    console.clear();

    Sleep(500);

    while(true)
    {
        console.get_info();
        
        if (GetAsyncKeyState('Q') & 0x8000) 
        {
            console.clear();
            break;
        }

        // Handle Views
        switch (view)
        {
            case 0:
                /* Menu */
                menu.update();
                break;
            case 1:
                /* Game */
                game.start();
                game.update();
                break;
        }

        /* i dont know why have error ): */
        // std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay));

        Sleep(frameDelay);
    }

    return 0;
}
