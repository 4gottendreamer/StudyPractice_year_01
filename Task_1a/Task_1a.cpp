// Task_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Вариант 5
/*
Задача 1.
а) Начиная с центра, обойти по спирали все элементы квадратной матрицы n * n,
располагая их в порядке обхода по и против часовой стрелки.
*/

/*
*	1.	Implement class Matrix
*		a. operator>>()
*		b. operator<<()
*/

#include <iostream>
#include "Methods.h"

int main()
{
	std::cout << "Hello World!\n";
	int matrixDimension;
	std::cout << "Input matrix dimension: ";
	std::cin >> matrixDimension;
	int** A = new int* [matrixDimension];
	for (size_t i = 0; i < matrixDimension; i++) {
		A[i] = new int[matrixDimension];
		for (size_t j = 0; j < matrixDimension; j++) {
			A[i][j] = rand() % 1000;
		}
	}
	printMatrix(A, matrixDimension, matrixDimension);

	for (size_t i = 0; i < matrixDimension; i++) {
		A[i] = new int[matrixDimension];
		for (size_t j = 0; j < matrixDimension; j++) {
			A[i][j] = rand() % 100;
		}
	}

	/*
	* Counter clockwise spiral elementwise traversal
	*/
	int idxCenter = matrixDimension % 2 ? (matrixDimension / 2 - 1) : (matrixDimension / 2);

	// Diagonal steps
	for (size_t diagonalCycle = 1; diagonalCycle < idxCenter; ++diagonalCycle) {
		// Down steps
		for (size_t i = idxCenter; i < 2 * diagonalCycle; ++i) {
			for (size_t j = 0; j < diagonalCycle; j++) {
				;
			}
		}
		// Right steps
		// Up steps
		// Left steps
	}
}
