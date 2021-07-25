#include "headers/Matrix.hpp"
#include <cassert>
#include <iostream>

void test_initial_values();
void test_operator_add();
void test_add_value_at();
void test_add_matrix();
void test_add_matrix_this();
void test_multiply_matrix();
void test_multiply_matrix_this();
void test_to_string();

int main()
{
    test_initial_values();
    test_operator_add();
    test_add_value_at();
    test_add_matrix();
    test_add_matrix_this();
    test_multiply_matrix();
    test_multiply_matrix_this();
    test_to_string();

    std::cout << "TESTS PASSED" << std::endl;
}

void test_initial_values() {
    Matrix matrix = Matrix(2, 2);
    assert(matrix(0, 0) == 0);
    assert(matrix(0, 1) == 0);
    assert(matrix(1, 0) == 0);
    assert(matrix(1, 1) == 0);
}

void test_operator_add() {
    Matrix matrix = Matrix(2, 2);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    assert(matrix(0, 0) == 1);
    assert(matrix(0, 1) == 2);
    assert(matrix(1, 0) == 3);
    assert(matrix(1, 1) == 4);
}

void test_add_value_at() {

    Matrix matrix = Matrix(2, 2);

    matrix.add_value_at(0, 0, 1);
    matrix.add_value_at(0, 1, 2);
    matrix.add_value_at(1, 0, 3);
    matrix.add_value_at(1, 1, 4);

    assert(matrix(0, 0) == 1);
    assert(matrix(0, 1) == 2);
    assert(matrix(1, 0) == 3);
    assert(matrix(1, 1) == 4);
}

void test_add_matrix() {

    Matrix matrix = Matrix(2, 2);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    Matrix to_add = Matrix(2, 2);

    to_add(0, 0) = 1;
    to_add(0, 1) = 2;
    to_add(1, 0) = 3;
    to_add(1, 1) = 4;

    Matrix result = matrix + to_add;

    assert(matrix(0, 0) == 1);
    assert(matrix(0, 1) == 2);
    assert(matrix(1, 0) == 3);
    assert(matrix(1, 1) == 4);

    assert(result(0, 0) == 2);
    assert(result(0, 1) == 4);
    assert(result(1, 0) == 6);
    assert(result(1, 1) == 8);
}

void test_add_matrix_this() {
    Matrix matrix = Matrix(2, 2);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    Matrix to_add = Matrix(2, 2);

    to_add(0, 0) = 1;
    to_add(0, 1) = 2;
    to_add(1, 0) = 3;
    to_add(1, 1) = 4;

    matrix += to_add;

    assert(matrix(0, 0) == 2);
    assert(matrix(0, 1) == 4);
    assert(matrix(1, 0) == 6);
    assert(matrix(1, 1) == 8);
}

void test_multiply_matrix() {

    Matrix matrix = Matrix(2, 2);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    Matrix result = matrix * 3;
  
    assert(result(0, 0) == 3);
    assert(result(0, 1) == 6);
    assert(result(1, 0) == 9);
    assert(result(1, 1) == 12);
}


void test_multiply_matrix_this() {
    Matrix matrix = Matrix(2, 2);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    matrix *= 2;

    assert(matrix(0, 0) == 2);
    assert(matrix(0, 1) == 4);
    assert(matrix(1, 0) == 6);
    assert(matrix(1, 1) == 8);
}

void test_to_string() {
    Matrix matrix = Matrix(2, 2);
    
    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(1, 0) = 3;
    matrix(1, 1) = 4;

    assert(matrix.to_string().compare("1 2 \n3 4 \n") == 0);
}