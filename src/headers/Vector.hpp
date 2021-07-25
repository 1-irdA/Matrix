#pragma once
#include <string>
#include <vector>

class Vector
{
private:

	int size;

	std::vector<int> values;

public:

	Vector(int size);

	void add_value_at(int col, int to_add);

	int& get_at(const int col);

	void add_vector(const Vector& to_add);

	void multiply_vector(const int multiple);

	std::string to_string();
};

