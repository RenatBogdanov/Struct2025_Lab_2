#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <set>

#include "game.h"


namespace game {

    
    Game::Game() {
        ReadFile();
        RenderGame();
    }

    Game::~Game() {
    }

    void Game::add_node(Node node)
    {
        nodes_.push_back(node);
    }

    void Game::set_count(uint16_t count)
    {
        count_ = count;
    }

    void Game::set_strength(uint16_t strength)
    {
        strength_ = strength;
    }

    uint16_t Game::get_count()
    {
        return count_;

    }

    uint16_t Game::get_strength()
    {
        return strength_;
    }

    void Game::RenderGame() {
        std::ofstream dotFile("graph.dot", std::ios::out);

        dotFile << "digraph G {\n";
        dotFile << "edge [dir=none];\n";
        std::set<std::pair<uint16_t, uint16_t>> addedEdges;

        for (Node node : nodes_) {
            for (uint16_t transition : node.transitions_) {
                std::pair<uint16_t, uint16_t> edge;
                if (node.get_number()+1 < transition) {
                    edge = {node.get_number()+1, transition};}
                else {
                    edge = {transition, node.get_number()+1}; }
                if (addedEdges.find(edge) == addedEdges.end()) {
                    dotFile << "    " << node.get_number() + 1 << " -> " << transition << ";\n";
                    addedEdges.insert(edge);
                }
                std::cout << edge.first << " " << edge.second << std::endl;
            }
        }


        dotFile << "}\n";
        dotFile.close();

        std::cout << "File graph.dot was created." << std::endl;

        system("dot -Tpng -O graph.dot");

        std::cout << "Graph was rendered." << std::endl;

        const char* imagePath = "graph.dot.png";
        std::string command = "start \"\" \"" + std::string(imagePath) + "\"";
        int result = system(command.c_str());

        std::cout << "Image was opened" << std::endl;
    }


    Node::Node() {}
    Node::~Node() {}

    void Node::set_number(uint16_t  number) {
        number_ = number;
    }

    void Node::set_strength(uint16_t  strength) {
        strength_ = strength;
    }

    void Node::set_transition(uint16_t  destination) {
        transitions_.push_back(destination);
    }

    uint16_t  Node::get_number() {
        return number_;
    }

    uint16_t  Node::get_strength() {
        return strength_;
    }

    void Game::ReadFile() {
        std::fstream inputFile(file_name_);

        uint16_t N;
        inputFile >> N;
        set_count(N);
        std::cout << N << std::endl;

        uint16_t S;
        inputFile >> S;
        set_strength(S);
        std::cout << S << std::endl;
        std::cout << get_strength() << std::endl;

        uint16_t T;
        for (uint16_t i = 0; i < N; i++) {
            inputFile >> T;
            Node new_node;
            new_node.set_number(i);
            new_node.set_strength(T);
            add_node(new_node);
            std::cout << T << std::endl;
            std::cout << nodes_[i].get_number() << std::endl;
        }

        uint16_t X, Y;
        while (inputFile >> X >> Y) {
            std::cout << X << "-" << Y << std::endl;
            nodes_[X-1].set_transition(Y);
            nodes_[Y-1].set_transition(X);
        }

        
        // for (Node node : Game.nodes_) {
        //     for (uint16_t transition : node.transitions_) {
        //         std::pair<uint16_t, uint16_t> edge;
        //         if (node.get_number()+1 < transition) {
        //             edge = {node.get_number()+1, transition};}
        //         else {
        //             edge = {transition, node.get_number()+1}; }
        //         if (Game.addedEdges.find(edge) == Game.addedEdges.end()) {
        //             Game.addedEdges.insert(edge);
        //         }
        //     }
        // }

    }
}
