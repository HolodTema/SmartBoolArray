#include <iostream>
#include "SmartBoolArray.h"

int main() {
	SmartBoolArray array(10);

	array.set(2, true);
	array.set(8, true);
	array.set(8, false);
	
	std::cout << array;

	return 0;
}

