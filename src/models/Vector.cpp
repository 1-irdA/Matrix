#include "../headers/Vector.hpp"
#include <stdexcept>
#include <string>

Vector::Vector(int size) {
	this->size = size;
	this->values = std::vector<int>(size, 0);
}

int& Vector::get_at(const int col) {
	return this->values[col];
}

void Vector::add_value_at(int col, int to_add) {
	if (col > this->size) {
		throw new std::exception();
	} 
	this->values[col] = to_add;
}

void Vector::add_vector(const Vector& to_add) {
	for (unsigned int i = 0; i < this->values.size(); i++) {
		this->values[i] += to_add.values[i];
	}
}

void Vector::multiply_vector(const int multiple) {
	for (unsigned int i = 0; i < this->values.size(); i++) {
		this->values[i] *= multiple;
	}
}

std::string Vector::to_string() {

	std::string str = "";

	for (int value : this->values)
	{
		str += std::to_string(value) + " ";
	}

	return str;
}
