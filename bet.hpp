//#include "bet.h"

int precedence(string expression);
bool isOperand(string expression);
bool error = false;

int precedence(const string exp) //checks precedence
{
    if (exp == "+" || exp == "-") return 1;
    if (exp == "*" || exp == "/") return 2;
    if (exp == "(" || exp == ")") return 3;
    return 0;
}

bool isOperand(const string exp)
{ 
	for(int i = 0; i < int(exp.size()); i++)
		if(isalnum(exp[i]) == false) // check if its characters or numbers 
			return false;
	return true;
}

BET::BET() //constructor
{
    root = new BinaryNode;
}

BET::BET(const string postfix) //one-parameter constructor
{
    root = new BinaryNode;
    buildFromPostfix(postfix);
}

BET::BET(const BET& x) //copy constructor
{
    root = clone(x.root);
}

BET::~BET() //destructor
{
    makeEmpty(root);
}


bool BET::buildFromPostfix(const string postfix) 
{
    string temp;
    stack<BinaryNode*> myStack;
    stringstream ss(postfix);

    int count = 0; //operands
    int counter = 0; //operators

    if(postfix.empty() == true) //if input is empty, output error message
    {
		cout << "Wrong postfix expression" << endl;
		root = nullptr;
		return false;
	}
    if(empty() == false)
    {
		makeEmpty(root);
    }

    while (ss >> temp)
    {
        BinaryNode *newNode = new BinaryNode(temp);

        if (isOperand(temp) == true)
        {
            count++;
            myStack.push(newNode);
        }
        else if (precedence(temp) != 0)
        {
            counter++;
            if (count < 2) //Not enough operands for an operator
            {
                cout << "Wrong postfix expression" << endl; 
                root = nullptr;
                return false;
            }
            if (count == counter)
            {
                cout << "Wrong postfix expression" << endl;
                root = nullptr;
                //return error = true;
                return false;
            }
            else
            {
            newNode->left = myStack.top();
            myStack.pop();
            newNode->right = myStack.top();
            myStack.pop();
            myStack.push(newNode);
            }
        }
    }
    if (myStack.size() != 1)
    {
        if (count > 1)
        {
            cout << "Wrong postfix expression" << endl;
        }
        root = nullptr;
        return false;
    }
    if (count != counter)
    {
        root = myStack.top();
    }
    return true;  
}

const BET& BET::operator=(const BET& x) // assignment operator
{
    root = clone(x.root);
    return *this;
}

void BET::printInfixExpression() //calls private version
{
    printInfixExpression(root);
    cout << endl;
}

void BET::printPostfixExpression() //calls private version
{
    printPostfixExpression(root);
    cout << endl;
}

size_t BET::size() //calls private version, return number of nodes
{
    return size(root);
}

size_t BET::leaf_nodes() //calls private version, return number of leaf nodes
{
    return leaf_nodes(root);
}

bool BET::empty() //returns true if empty, false if not
{
    if (root == nullptr)
        return true;
    else
        return false;    
}

void BET::printInfixExpression(BinaryNode *n) //call recursively
{
    //Parentheses handling
    bool closedParentheses = false; 

    if (n != nullptr)
    {
        if (n->left == nullptr && n->right == nullptr) 
        {
            cout << n->element << " ";
        }
        else
        {
            if (precedence(n->element) != 0 && precedence(n->right->element) != 0)
            {
                if (precedence(n->element) >= precedence(n->right->element))
                {
                    if (precedence(n->element) == 2)
                    {
                        cout << "( ";
                        closedParentheses = true;
                    }
                }
            }
            printInfixExpression(n->right);

            if (closedParentheses == true)
            {
                cout << ") ";
            }
            closedParentheses = false;
            cout << n->element << " ";
            if (precedence(n->element) != 0 && precedence(n->left->element))
            {
                if (precedence(n->element) >= precedence(n->left->element))
                {
                cout << "( ";
                closedParentheses = true;
                }
            }

            printInfixExpression(n->left);
            if(closedParentheses == true)
            {
                cout << ") ";
                closedParentheses = false;
            }
        }
    }
    
}

void BET::makeEmpty(BinaryNode* &t) //call recursively
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
}

BET::BinaryNode* BET::clone(BinaryNode *t) const //call recursively
{
    if (t == nullptr) //if empty, return
    {
        return nullptr;
    }
    else
        return new BinaryNode(t->element, clone(t->left), clone(t->right)); //else, clone

}

void BET::printPostfixExpression(BinaryNode *n) //call recursively
{
    if (n == nullptr) //if empty, return
    {
        return;
    }
    else if(root->left == nullptr && root->right == nullptr) //check this
    {
        cout << root->element << endl;
    }
    else
    {
        printPostfixExpression(n->right);
        printPostfixExpression(n->left);
        cout << n->element << " ";
    }
}

size_t BET::size(BinaryNode *t) //call recursively
{
    if(t == nullptr) //if empty, return size is 0
    {
        return 0;
    }
    else
    {
        return size(t->left) + size(t->right) + 1;
    }
}

size_t BET::leaf_nodes(BinaryNode* t)
{
    if (t == nullptr)
    {
        return 0;
    }
    else if ((t->left == nullptr) && (t->right == nullptr))
    {
        return 1;
    } 
    else
    {
        return leaf_nodes(t->left) + leaf_nodes(t->right);
    }
}

