cmake_minimum_required (VERSION 2.6)
project (tictactoe)
add_executable(tictactoe board.cpp simple_ai_player.cpp human_player.cpp game.cpp basic_io.cpp tictactoe.cpp)
