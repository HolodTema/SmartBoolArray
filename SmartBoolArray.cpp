#include "SmartBoolArray.h"

SmartBoolArray& SmartBoolArray::operator=(SmartBoolArray& other) {
	if (&other != this) {

		SmartBoolArray otherCopy(other);
		swap(other);
	}
	return *this;
}

SmartBoolArray& SmartBoolArray::operator=(SmartBoolArray&& other) noexcept {
	size_ = other.size_;
	capacity_ = other.capacity_;
	array_ = other.array_;
	other.array_ = nullptr;
	return *this;
}

bool& SmartBoolArray::operator[](unsigned int index) const {
	if (index >= size_) {
		throw IndexOutOfBoundsException();
	}
	char ch = array_[index / 8];
	unsigned int indexInChar = index - (index / 8) * 8;

	unsigned char multiplier = 128 / (1 << index);

	return ((ch * multiplier) >> (7 - index)) == 1 ? true : false;
}

int SmartBoolArray::getSize() const noexcept {
	return size_;
}

void SmartBoolArray::swap(SmartBoolArray& other) noexcept {
	std::swap(array_, other.array_);
	std::swap(capacity_, other.capacity_);
	std::swap(size_, other.size_);
}

std::ostream& operator<<(std::ostream& os, const SmartBoolArray& array) {
	for (int i = 0; i < array.getSize(); ++i) {
		os << array[i] << " ";
	}
	os << "\n";
	return os;
}



