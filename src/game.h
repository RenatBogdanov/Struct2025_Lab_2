#pragma once

#ifndef GAME_H
#define GAME_H



namespace game {

    class Game;
    class GameRender;
    class ReadFile;
    class Node;
    class Hero;
    

    struct Vector2
    {
        uint16_t x;
        uint16_t y;
    };
    
    
    class Game
    {
    private:
        uint16_t strength_;
        uint16_t current_strength_;
        uint16_t count_;
        std::vector<std::vector<int>> traces_;
        std::vector<Node> nodes_;
        
    public:
        Game();
        ~Game();

        void add_node(Node node);
        void set_count(uint16_t count);
        void set_strength(uint16_t strength);

        uint16_t get_count();
        uint16_t get_strength();
    };

    class ReadFile
    {
        private:
            std::string file_name_ = "input.txt";
            Game& game_;
        public:
            ReadFile(Game& game);
            ~ReadFile();
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
    
    
}


#endif