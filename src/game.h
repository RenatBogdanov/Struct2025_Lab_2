#pragma once

#ifndef GAME_H
#define GAME_H



namespace game {
    // Перечисление классов
    class Game;
    class GameRender;
    class ReadFile;
    class Node;
    class Hero;
    
    class Game
    {
    private:
        uint16_t strength_;
        uint16_t current_strength_;
        uint16_t count_;
        std::vector<std::vector<uint16_t >> traces_;
        std::string file_name_ = "input.txt";
        
    public:
        std::vector<Node> nodes_;
        Game();
        ~Game();

        void add_node(Node node);
        void set_count(uint16_t count);
        void set_strength(uint16_t strength);

        uint16_t get_count();
        uint16_t get_strength();

        void ReadFile();
        void RenderGame();
        void FindPath();
    };    

    
       
    class Node
    {
    private:
        uint16_t  number_;
        uint16_t  strength_;
    public:
        std::vector<uint16_t> transitions_;
        Node();
        ~Node();

        void set_number(uint16_t  number);
        void set_strength(uint16_t  strength);
        void set_transition(uint16_t  destination);

        uint16_t  get_number();
        uint16_t  get_strength();
    };
    
    
}


#endif