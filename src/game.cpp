#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>

#include "game.h"


namespace game {

    
    Game::Game() {

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

    RenderGame::RenderGame() {
    }

    RenderGame::~RenderGame() {
    }

    Node::Node() {
    }

    Node::~Node() {
    }

    void Node::set_number(int number) {
        number_ = number;
    }

    void Node::set_strength(int strength) {
        strength_ = strength;
    }

    void Node::set_transitions(std::vector<int> transitions) {
        transitions_ = transitions;
    }

    int Node::get_number() {
        return number_;
    }

    int Node::get_strength() {
        return strength_;
    }

    std::vector<int> Node::get_transitions() {
        return transitions_;
    }


    ReadFile::ReadFile(Game& Game) : game_(Game) {
        std::fstream inputFile(file_name_);

        uint16_t N;
        inputFile >> N;
        Game.set_count(N);

        uint16_t S;
        inputFile >> S;
        Game.set_strength(S);

        uint16_t T;
        for (uint16_t i = 0; i < N; i++) {
            inputFile >> T;
            Node new_node;
            new_node.set_number(i);
            new_node.set_strength(T);
            Game.add_node(new_node);
        }

        uint16_t Tr;

    }

    ReadFile::~ReadFile() {
    }

}
