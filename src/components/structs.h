#ifndef STRUCTS_H
#define STRUCTS_H

#include<string>
#include<vector>

enum class TokenType{
    Rep = 4, If = 5, Init = 6, Show = 7,
    Equal = 8,
    Plus = 9, Minus = 9,
    Multiply = 10, Divide = 10,
    Number = 11, Identifier = 11,
};

struct Token {
    TokenType type;
    std::string value;
};

struct Node{
    TokenType type;
    std::string value;
    Node* left;
    Node* right;
    int priority;

    Node* initialState; // address to same root node like itself, to have an initialy copy
};

struct LoopNode{
    int isItLoop; // 1 if it is loop
    Node* actualRoot; // use only when isItLoop == 0

    int n;  // number of repetitions, will be changed to track the iterations
    int initial_n; // constant value that will be used if we use same loop again
    std::vector<LoopNode*> roots; // roots or another loop
};

#endif
