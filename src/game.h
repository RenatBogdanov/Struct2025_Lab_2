#pragma once

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdint>

namespace game {

    
    struct Vector2
    {
        uint16_t x;
        uint16_t y;
    };
    

    
    class Game
    {
    private:
        int nodes_;
        int traces_;
        
    public:
        Game();
        ~Game();
    };
    

    
    class RenderGame
    {
    private:
        
    public:
        RenderGame();
        ~RenderGame();
    };
    
    
    
    class Node
    {
    private:
        int number_;
        std::vector<int> transitions_;
        int strength_;
    public:
        Node();
        ~Node();

        void set_number(int number);
        void set_strength(int strength);
        void set_transitions(std::vector<int> transitions);

        int get_number();
        int get_strength();
        std::vector<int> get_transitions();
    };
    

    
    class Hero
    {
    private:
        int strength_;
        int current_strength_;

    public:
        Hero();
        ~Hero();

    };
    
}


#endif