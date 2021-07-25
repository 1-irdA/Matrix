#include "../headers/Matrix.hpp"
#include <iostream>
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

const Vector& Matrix::get_vect_at(const int row) const {
	return this->vectors[row];
}

void Matrix::add_value_at(const int row, const int col, const int to_add) {
	if (row > this->row && col > this->col) {
		throw new std::exception();
	}
	this->vectors[row].add_value_at(col, to_add);
}

bool Matrix::is_same_size(const Matrix& to_check) {
	return this->get_row() == this->get_col() && to_check.get_row() == to_check.get_row();
}

Matrix& Matrix::add_matrix_on_this(const Matrix& to_add) {

	if (!this->is_same_size(to_add)) {
		throw new std::exception();
	}
	
	for (unsigned int i = 0; i < this->vectors.size(); i++) {
		this->vectors[i].add_vector(to_add.get_vect_at(i));
	}

	return *this;
}

Matrix Matrix::add_matrix(const Matrix& to_add) {

	if (!this->is_same_size(to_add)) {
		throw new std::exception();
	}

	Matrix result = Matrix(to_add.get_row(), to_add.get_col());
	
}

Matrix& Matrix::multiply_matrix(const int multiple) {
	for (unsigned int i = 0; i < this->vectors.size(); i++) {
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

Matrix operator+(Matrix& left, const Matrix& right) {
	return left += right;
}

Matrix operator*(Matrix& to_multiply, const int multiple) {
	return to_multiply *= multiple;
}

Matrix& Matrix::operator+=(const Matrix& to_add) {
	return this->add_matrix(to_add);
}

Matrix& Matrix::operator*=(const int multiple) {
	return this->multiply_matrix(multiple);
}

int& Matrix::operator()(const int row, const int col) {
	if (row > this->get_row() || col > this->get_row()) {
		throw new std::exception();
	}
	return this->vectors[row].get_at(col);
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
	return stream << matrix.to_string();
}
