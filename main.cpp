#include <iostream>
#include "SmartBoolArray.h"

int main() {
	//create smart bool array, which uses memory resources more effectively
	SmartBoolArray array(10);

	//use set() method to put values
	array.set(2, true);
	array.set(8, true);
	array.set(8, false);

	//use get() method to get elements
	std::cout << "Element with index 2 is: " << array.get(2) << "\n";

	//print the whole array in console
	std::cout << array;

	//get simple c++ boolean array in dynamic memory from SmartBoolArray:
	bool* simpleArray = array.toBoolArray();
	for (int i = 0; i < array.getSize(); ++i) {
		std::cout << simpleArray[i] << " ";
	}
	std::cout << "\n";
	delete[] simpleArray;
	
	return 0;
}

