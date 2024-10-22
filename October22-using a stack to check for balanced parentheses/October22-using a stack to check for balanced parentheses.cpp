// October22-using a stack to check for balanced parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<stack> 

using std::stack; 
using std::cout; 
using std::string; 

/*this function ASSUMES that the only grouping symbols are parentheses (), and brackets []*/
bool isMatch(char openSymbol, char closeSymbol)
{
    if (openSymbol == '(' && closeSymbol != ')')
    {
        return false; 
    }

    else if (openSymbol == '[' && closeSymbol != ']')
    {
        return false;
    }

    else
    {
        return true; 
    }
}

/*this function ASSUMES that the only grouping symbols are parentheses (), and brackets []*/
bool isBalanced(string expression)
{
    stack<char> openSymbolStack; 
    for (int i = 0; i < expression.length(); ++i) 
    {
        if (expression[i] == '(' or expression[i] == '[')
        {
            openSymbolStack.push(expression[i]);
        }
        
        else if (expression[i] == ')' or expression[i] == ']')
        {
            if (openSymbolStack.empty() == true)
            {
                return false; // ex: our expression is ")"
            }
            else
            {
                char characterAtTopOfStack = openSymbolStack.top(); 
                char currentCharacter = expression[i]; 

                if (isMatch(characterAtTopOfStack, currentCharacter))
                {
                    openSymbolStack.pop(); 
                }

                else
                {
                    return false; //example? "[(5+2])/7"
                }
            }
        }
    } //end for loop 

    if (openSymbolStack.empty() == false)
    {
        return false; //example? "("
    }

    else
    {
        return true; 
    }
}

void printIfIsBalanced(string expression)
{
    cout << "is the expression " << expression << " balanced?\n";

    cout << isBalanced(expression) << "\n";
}

int main()
{
    //int num = sqrt(]
    cout << std::boolalpha;

    string balancedExpression = "[(5+2)/7]";

    string unbalancedExpression1 = "[(5+2)/7";//no matching close bracket ]
    
    string unbalancedExpression2 = "(5+2/7"; //no close symbol at all  

    string unbalancedExpression3 = "5+2)/7"; //no matching open parenthesis

    string unbalancedExpression4 = "[(5+2])/7"; //first close symbol encountered does NOT match
                                                //the last open symbol (on the top of the stack) 

    /*int expression = ((5 + 2) / 7);*/
    
    printIfIsBalanced(balancedExpression); 
    printIfIsBalanced(unbalancedExpression1);
    printIfIsBalanced(unbalancedExpression2);
    printIfIsBalanced(unbalancedExpression3);
    printIfIsBalanced(unbalancedExpression4);

}