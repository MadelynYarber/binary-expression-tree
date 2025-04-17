#include <iostream>
#include "bet.h"

using namespace std;

int main() {
    
    string postfix;
    bool keepGoing = true;

    // Output displayed to user for the first expression
    cout << "Enter the first postfix expression: ";
    getline(cin, postfix);

    BET bet1(postfix);
    
    if (bet1.buildFromPostfix(postfix) == true)
    {
    // Print infix expression
    cout << "Infix Expression: ";
    bet1.printInfixExpression();

    // Print postfix expression
    cout << "Postfix Expression: ";
    bet1.printPostfixExpression();


    // Print the size of the tree
    cout << "Number of nodes: " << bet1.size() << endl;

    // Print the number of leaf nodes
    cout << "Number of leaf nodes: " << bet1.leaf_nodes() << endl;

    BET bet2(bet1);
    cout << "Testing copy constructor: ";
    bet2.printInfixExpression();

    BET bet3;
    bet3 = bet1;
    cout << "Testing assignment operator: ";
    bet3.printInfixExpression();
    }

    while(keepGoing)
    {
        cout << "Enter a postfix expression (or \"quit\" to quit): ";
        getline(cin, postfix);

        if (postfix == "quit")
        {
            //keepGoing == false;
            break;
        }
        if (bet1.buildFromPostfix(postfix))
        {
            BET bet1(postfix);
   
            // Print infix expression
            cout << "Infix Expression: ";
            bet1.printInfixExpression();

            // Print postfix expression 
            cout << "Postfix Expression: ";
            bet1.printPostfixExpression();

            // Print the size of the binary expression tree
            cout << "Number of nodes: " << bet1.size() << endl;

            // Print the number of leaf nodes
            cout << "Number of leaf nodes: " << bet1.leaf_nodes() << endl;
        }
    }
    return 0;
}
