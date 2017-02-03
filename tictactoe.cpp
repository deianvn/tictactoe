#include "simple_ai_player.hpp"
#include "human_player.hpp"
#include "game.hpp"
#include "basic_io.hpp"

#include <iostream>
#include <memory>

enum class menu_option { quit = 0, human_vs_human = 1, human_vs_cpu = 2, cpu_vs_human = 3, cpu_vs_cpu = 4 };

menu_option menu();

int main()
{
    std::cout << "TIC-TAC-TOE\n\n";
    menu_option res;
    
    while ((res = menu()) != menu_option::quit)
    {
        std::unique_ptr<player> p1, p2;
        
        switch (res)
        {
            case menu_option::human_vs_human:
                p1 = std::make_unique<human_player>('X');
                p2 = std::make_unique<human_player>('O');
                break;
            case menu_option::human_vs_cpu:
                p1 = std::make_unique<human_player>('X');
                p2 = std::make_unique<simple_ai_player>('O');
                break;
            case menu_option::cpu_vs_human:
                p1 = std::make_unique<simple_ai_player>('X');
                p2 = std::make_unique<human_player>('O');
                break;
            case menu_option::cpu_vs_cpu:
                p1 = std::make_unique<simple_ai_player>('X');
                p2 = std::make_unique<simple_ai_player>('O');
                break;
            case menu_option::quit:
                return 0;
        }
        
        game g { *p1, *p2 };
        g.play();
    }
    
    return 0;
}

menu_option menu()
{
    std::cout <<
        "MENU\n\n"
        "0 - Quit\n"
        "1 - Human vs Human\n"
        "2 - Human vs CPU\n"
        "3 - CPU vs Human\n"
        "4 - CPU vs CPU\n"
        "> ";
    
    int res;
    
    while (!next_int(std::cin, res) || res < 0 || res > 4)
    {
        std::cout << "Wrong input! Try again!\n> ";
    }
    
    return static_cast<menu_option>(res);
}
