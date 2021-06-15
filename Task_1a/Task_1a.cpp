// Task_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// ������� 5
/*
������ 1.
�) ����� ���� ������� n * n (n=1,...,15).
��������, ������� �� � ������� ��������� ��������,
� ���� �������, �� ������� ������� ���� ��������� ���������.
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
