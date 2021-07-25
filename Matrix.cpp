#include "Matrix.hpp"
#include <ostream>
#include <stdexcept>
#include <string>

Matrix::Matrix(const int row, const int col) {
	this->row = row;
	this->col = col;

	for (int i = 0; i < this->row; i++) {
		this->vectors.push_back(Vector(this->col));
	}
}

const int Matrix::get_row() const {
	return this->row;
}

const int Matrix::get_col() const {
	return this->col;
}

void Matrix::add_value_at(const int row, const int col, const int to_add) {

	if (row > this->row || col > this->col) {
		throw std::out_of_range("Error ! Cannot add value at row : " 
			+ std::to_string(row) 
			+ " col : " 
			+ std::to_string(col));
	}

	this->vectors[row].add_value_at(col, to_add);
}

bool Matrix::is_same_size(Matrix to_check) {
	return this->get_row() == this->get_col() && to_check.get_row() == to_check.get_row();
}

Matrix Matrix::add_matrix(const Matrix& to_add) {

	if (this->is_same_size(to_add)) {
		throw std::exception("Error ! Cannot add 2 matrix with differents sizes");
	}

	for (int i = 0; i < this->vectors.size(); i++) {
		this->vectors[i].add_vector(to_add.vectors[i]);
	}

	return *this;
}

Matrix Matrix::multiply_matrix(const int multiple) {
	for (int i = 0; i < this->vectors.size(); i++) {
		this->vectors[i].multiply_vector(multiple);
	}
	return *this;
}

std::string Matrix::to_string() {

	std::string str = "";

	for (Vector vector : this->vectors) {
		str += vector.to_string() + "\n";
	}

	return str;
}

std::string Matrix::to_string() const {

	std::string str = "";

	for (Vector vector : this->vectors) {
		str += vector.to_string() + "\n";
	}

	return str;
}

Vector Matrix::get_at(const int row) {
	return this->vectors[row];
}

Matrix operator+(Matrix& left, const Matrix& right) {
	return left += right;
}

Matrix operator*(Matrix& to_multiply, const int multiple) {
	return to_multiply *= multiple;
}

Matrix& Matrix::operator+=(const Matrix& to_add) {
	this->add_matrix(to_add);
	return *this;
}

Matrix& Matrix::operator*=(const int multiple) {
	this->multiply_matrix(multiple);
	return *this;
}

int& Matrix::operator()(const int row, const int col) {
	if (row > this->get_row() || col > this->get_row()) {
		throw std::out_of_range("Error ! Cannot access to row : " + std::to_string(row) + " col : " + std::to_string(row));
	}
	return this->vectors[row].get_at(col);
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
	return stream << matrix.to_string();
}