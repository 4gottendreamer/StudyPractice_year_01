// Task_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Вариант 5
/*
Задача 1.
а) Пусть дана матрица n * n (n=1,...,15).
Выяснить, имеются ли в матрице ненулевые элементы,
и если имеются, то указать индексы всех ненулевых элементов.
*/

#include <iostream>
#include "Methods.h"

int main()
{
	int matrixDimension;
	std::cout << "Input matrix dimension: ";
	std::cin >> matrixDimension;
	int** A = new int* [matrixDimension];
	for (size_t i = 0; i < matrixDimension; i++) {
		A[i] = new int[matrixDimension];
		for (size_t j = 0; j < matrixDimension; j++) {
			A[i][j] = rand() % 10;
		}
	}

	printMatrix(A, matrixDimension, matrixDimension);
	bool thereIsZero = false;
	for (size_t i = 0; i < matrixDimension; i++) {
		for (size_t j = 0; j < matrixDimension; j++) {
			if (A[i][j] == 0) {
				std::cout << "A[" << i << "][" << j << "] == 0" << std::endl;
				thereIsZero = true;
			}
		}
	}

	if (!thereIsZero) {
		std::cout << "There are no zeroes in the matrix" << std::endl;
	}
}
