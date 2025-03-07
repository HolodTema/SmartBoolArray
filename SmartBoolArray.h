
#ifndef SMART_BOOL_ARRAY_H
#define SMART_BOOL_ARRAY_H

#include <iostream>
#include "smartBoolArrayExceptions.h"

class SmartBoolArray final {
public:
	
	SmartBoolArray(int size):
		size_(size)
	{
		if (size <= 0) {
			throw InvalidArraySizeException();
		}

		capacity_ = size / 8 + 1;
		array_ = new char[capacity_];
	}

	SmartBoolArray(const SmartBoolArray& other):
   		size_(other.size_),
		capacity_(other.capacity_)
	{
		array_ = new char[capacity_];
		for (int i = 0; i < other.capacity_; ++i) {
			array_[i] = other.array_[i];
		}
	}

	SmartBoolArray(const SmartBoolArray&& other):
		size_(other.size_),
		capacity_(other.capacity_),
		array_(other.array_)
	{

	}

	~SmartBoolArray() {
		delete[] array_;
	}

	SmartBoolArray& operator=(SmartBoolArray& other);

	SmartBoolArray& operator=(SmartBoolArray&& other) noexcept;

	bool& operator[](unsigned int index) const;

	int getSize() const noexcept;

	friend std::ostream& operator<<(std::ostream& os, const SmartBoolArray& array);

private:
	int size_;
	int capacity_;
	char* array_;

	void swap(SmartBoolArray& other) noexcept;

};

#endif
