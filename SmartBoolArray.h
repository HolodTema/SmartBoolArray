
#ifndef SMART_BOOL_ARRAY_H
#define SMART_BOOL_ARRAY_H

class SmartBoolArray final {
public:
	
	SmartBoolArray(int size):
		size_(size)
	{
		capacity_ = size / 8 + 1;
		array_ = new char[capacity_];
	}

	SmartBoolArray(const SmartBoolArray& other) {

	}

	SmartBoolArray(const SmartBoolArray&& other) {

	}

	SmartBoolArray& operator=(SmartBoolArray& other) {

	}

	SmartBoolArray& operator=(SmartBoolArray&& other) noexcept {

	}

	int getSize() {
		return size_;
	}


private:
	int size_;
	int capacity_;
	char* array_;

	void swap(SmartBoolArray& other) noexcept {
		std::swap(array_, other.array_);
		std::swap(capacity_, other.capacity_);
		std::swap(size_, other.size_);
	}

};

#endif
