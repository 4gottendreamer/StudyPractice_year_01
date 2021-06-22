// Task_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// ������� 5
/*
������ 1.
а) Пусть дана матрица n×n (n = 1,..., 15).
Выяснить, имеются ли в матрице ненулевые элементы,
и если имеются, то указать индексы всех ненулевых элементов.
*/

#include <iostream>
#include <vector>
#include "Methods.h"

int main()
{
	std::vector<std::pair<int, int>> zeroIndices;
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

	printMatrixWithIndices(A, matrixDimension, matrixDimension);

	for (size_t i = 0; i < matrixDimension; i++) {
		for (size_t j = 0; j < matrixDimension; j++) {
			if (A[i][j] == 0) {
				zeroIndices.push_back(std::pair(i,j));
			}
		}
	}
	if (zeroIndices.size()) {
		std::cout << "Indices of zero-value elements:" << std::endl;
		std::cout << "Row\tColumn" << std::endl;
		for (auto idxPair : zeroIndices) {
			std::cout << idxPair.first << '\t' << idxPair.second << std::endl;
		}
	}
	else {
		std::cout << "There are no zero-value elements in the matrix." << std::endl;
	}
	std::cout << "Press Enter" << std::endl;
	std::cin.get();
	std::cin.get();
}
