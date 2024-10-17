// October 17 - part 2 - playing with STD stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<stack>

using std::cout; 
using std::stack; 

int main()
{
	stack<char> palindromeStack;
	palindromeStack.push('H'); 
	palindromeStack.push('a');
	palindromeStack.push('n');
	palindromeStack.push('n');
	palindromeStack.push('a');
	palindromeStack.push('h');

	while (!palindromeStack.empty())
	{
		//be wary of the order of calling top and pop
		//might accidentally pop an EMPTY stack 

		cout << palindromeStack.top(); //prints the top
		palindromeStack.pop(); //removes the top element 
	}




}
