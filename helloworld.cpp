#include <iostream>
#include <string.h>
#include <stdio.h>

/** Function Declaration **/
void testcout();
void testcin();

/**
* Main method on hello world
**/
int main(){
	// Adding some comments here
	//testcout();
	testcin();
	return 0;
} 

void testcout(){
	std::cout << "Hello World" << std::endl;
	int y;
	y = 1 + 1;
	// Print y
	std::cout << "Value of y: "<< y << std::endl;
	char putStr []  = "Test Puts";
	puts(putStr);
}

void testcin(){
	std::cout << "Enter a number: " << std::endl;
	int x = 0;
	std::cin >> x;
	std::cout << "Number Entered: " << x << std::endl;
}
	