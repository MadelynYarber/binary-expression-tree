#ifndef BET_H
#define BET_H
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

class BET 
{
    struct BinaryNode
    {
        string element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const string& elem = string{}, BinaryNode *l = nullptr, BinaryNode *r = nullptr) : element{elem}, left{l}, right{r} {}
    };

    public:
        BET(); //default constructor
        BET(const string postfix); //one-parameter constructor
        BET(const BET&); //copy constructor
        ~BET(); //destructor

        bool buildFromPostfix(const string postfix); 

        const BET & operator=(const BET &); //assignment operator

        void printInfixExpression();
        void printPostfixExpression();
        size_t size();
        size_t leaf_nodes();
        bool empty();
        
        bool isOperator(const string); //CHECK
        
        private: //all private member functions must be implemented recursively

        void printInfixExpression(BinaryNode *n);
        void makeEmpty(BinaryNode* &t);
        BinaryNode* clone(BinaryNode *t) const;
        void printPostfixExpression(BinaryNode *n);
        size_t size(BinaryNode *t);
        size_t leaf_nodes(BinaryNode *t);
        BinaryNode* root;
};
#include "bet.hpp"
#endif