// October17_2024-COSC2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout; 
using std::string; 

void demoInfiniteRecursion()
{
	cout << "?";
	demoInfiniteRecursion(); 
}


void functionD()
{

}

void functionB()
{

}

void functionC()
{
	functionD(); 
}

void functionA()
{
	functionB(); 

	functionC(); 
}

template<typename T> 
class stack
{
	T stackData[]; 

	void pop(); 
	void push(); 
	T top(); 

};

int main()
{

	//demoInfiniteRecursion(); 
	//while (true)
	//{
	//	cout << "?";
	//}
	
	//while (true)
	//{
	//	int* i = new int; //beware of memory leak!
	//	//delete i; //prevents memory leak
	//}
	//FIFO -> first in, first out (first come, first served) [ex: queue/line]

	//LIFO -> last in, first out (ex: STACK) 

	//example related to "stack tracing" 
	functionA();
}
