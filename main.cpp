#include <iostream>
#include "SmartBoolArray.h"

int main() {
	SmartBoolArray array(10);
	array[2] = true;
	std::cout << array;

	return 0;
}

