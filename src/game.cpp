#include <cstdint>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

#include "game.h"


namespace game {

    
    Game::Game() {
        ReadFile(); // Чтение файла и запись содержимого в поля
        RenderGame(); // Создание изображения графа
        FindPath(); // Поиск путей и вывод в консоль
    }

    Game::~Game() {
    }

    // Добавление узла
    void Game::add_node(Node node) {
        nodes_.push_back(node);
    }

    // Установка количества узлов
    void Game::set_count(uint16_t count) {
        count_ = count;
    }

    // Установка силы персонажа
    void Game::set_strength(uint16_t strength) {
        strength_ = strength;
    }

    // Получение количества узлов
    uint16_t Game::get_count() {
        return count_;

    }

    // Получение силы персонажа
    uint16_t Game::get_strength() {
        return strength_;
    }

    // Создание и открытие изображения графа
    void Game::RenderGame() {
        // Генерация файла graph.dot для последующего преобразования в .png
        std::ofstream dotFile("graph.dot", std::ios::out);

        dotFile << "digraph G {\n";
        dotFile << "edge [dir=none];\n";
        std::set<std::pair<uint16_t, uint16_t>> addedEdges;
        for (Node node : nodes_) {
            // [xlabel="a"]
            dotFile << node.get_number()+1 << " [xlabel=\""<< node.get_strength() << "\"]\n";
        }
        dotFile << "\n";

        for (Node node : nodes_) {
            for (uint16_t transition : node.transitions_) {
                std::pair<uint16_t, uint16_t> edge;
                if (node.get_number()+1 < transition) {
                    edge = {node.get_number()+1, transition};}
                else {
                    edge = {transition, node.get_number()+1}; }
                if (addedEdges.find(edge) == addedEdges.end()) {
                    dotFile <<  node.get_number() + 1 << " -> " << transition << ";\n";
                    addedEdges.insert(edge);
                }
                std::cout << edge.first << " " << edge.second << std::endl;
            }
        }


        dotFile << "}\n";
        dotFile.close();

        // Вызов программы dot для создания изображения графа
        system("dot -Tpng -O graph.dot");

        // Открытие изображения для просмотра
        const char* imagePath = "graph.dot.png";
        std::string command = "start \"\" \"" + std::string(imagePath) + "\"";
        int result = system(command.c_str());
    }

    // Чтение файла input.txt
    void Game::ReadFile() {
        // Открытие файла
        std::fstream inputFile(file_name_);

        // Запись количества залов (узлов)
        uint16_t N;
        inputFile >> N;
        set_count(N);
        std::cout << N << std::endl;

        // Запись силы персонажа
        uint16_t S;
        inputFile >> S;
        set_strength(S);
        std::cout << S << std::endl;
        std::cout << get_strength() << std::endl;

        // Создание узлов
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

        // Запись переходов узлов
        uint16_t X, Y;
        while (inputFile >> X >> Y) {
            std::cout << X << "-" << Y << std::endl;
            nodes_[X-1].set_transition(Y);
            nodes_[Y-1].set_transition(X);
        }
    }

    // Поиск возможных путей
    void Game::FindPath() {

    }

    // Пустые конструкторы и деструкторы для узла
    Node::Node() {}
    Node::~Node() {}

    // Установка номера узла
    void Node::set_number(uint16_t  number) {
        number_ = number;
    }

    // Установка силы узла
    void Node::set_strength(uint16_t  strength) {
        strength_ = strength;
    }

    // Добавление перехода
    void Node::set_transition(uint16_t  destination) {
        transitions_.push_back(destination);
    }

    // Получение номера узла
    uint16_t  Node::get_number() {
        return number_;
    }

    // Получение силы узла
    uint16_t  Node::get_strength() {
        return strength_;
    }

}
