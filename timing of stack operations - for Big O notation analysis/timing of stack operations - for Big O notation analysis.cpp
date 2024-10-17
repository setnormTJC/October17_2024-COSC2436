// timing of stack operations - for Big O notation analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include<stack> 

#include<chrono> 
#include<string>

using std::cout; 
using std::stack; 
using std::string; 

/*@ param Takes a COPY (by value) so no modification to original*/
void printStack(std::stack<string> theStack)
{
	while (!theStack.empty())
	{
		cout << theStack.top() << "\n";
		theStack.pop(); 
	}
}

int main()
{
	stack<string> oneHundredPlates;
	for (int i = 0; i < 100; ++i)
	{
		oneHundredPlates.push("plate number " + std::to_string(i));
	}

	//printStack(oneHundredPlates);

	//system("pause");

	stack<string> oneMILLIONPlates;
	for (int i = 0; i < 1'000'000; ++i)
	{
		oneMILLIONPlates.push("plate number " + std::to_string(i));
	}

	auto startForOneHundred = std::chrono::high_resolution_clock::now(); 
	oneHundredPlates.pop(); 
	auto endForOneHundred = std::chrono::high_resolution_clock::now();

	string operationName = "pop";
	
	cout << "Time for " << operationName << " on stack of one hundred: "
		<< (endForOneHundred - startForOneHundred).count() << " ns?\n";

	auto startForOneMILLION = std::chrono::high_resolution_clock::now();
	oneMILLIONPlates.pop(); 
	auto endForOneMILLION = std::chrono::high_resolution_clock::now(); 

	cout << "Time for " << operationName << " on a stack of ONE MILLION: "
		<< (endForOneMILLION - startForOneMILLION).count() << " ns?\n";

	//
	//int a = (5 + 2)) /2

}
