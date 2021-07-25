#pragma once
#include "Vector.hpp"
#include <ostream>
#include <string>
#include <vector>

class Matrix
{
private:
	int row;

	int col;

	std::vector<Vector> vectors;

public:
	Matrix(int row, int col);

	const int get_col() const;

	const int get_row() const;

	void add_value_at(const int row, const int col, const int to_add);

	bool is_same_size(const Matrix& to_check);

	Matrix& add_matrix(const Matrix& to_add);

	Matrix add_matrix(const Matrix& to_add);

	Matrix& multiply_matrix(const int multiple);

	const Vector& get_vect_at(const int row) const;

	std::string to_string();

	std::string to_string() const;

	friend Matrix operator+(Matrix& left, const Matrix& right);

	friend Matrix operator*(Matrix& to_multiply, const int multiple);

	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

	Matrix& operator+=(const Matrix& to_add);
	
	Matrix& operator*=(const int multiple);

	int& operator()(const int row, const int col);
};
