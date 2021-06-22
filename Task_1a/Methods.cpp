#include "Methods.h"

void printMatrix(int** _Arr, int _Rows, int _Cols) {
	for (size_t i = 0; i < _Rows; i++) {
		for (size_t j = 0; j < _Cols; j++) {
			std::cout << _Arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void printMatrixWithIndices(int** _Arr, int _Rows, int _Cols) {
	for (size_t i = 0; i < _Cols; i++) {
		std::cout << '\t' << i + 1;
	}
	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < _Rows; i++) {
		std::cout << i + 1 << '\t';
		for (size_t j = 0; j < _Cols; j++) {
			std::cout << _Arr[i][j] << '\t';
		}
		std::cout << std::endl << std::endl;
	}
}

void fillMatrix(int** _Arr, int _Rows, int _Cols, int _RandMod) {
	for (size_t i = 0; i < _Rows; i++) {
		_Arr[i] = new int[_Cols];
		for (size_t j = 0; j < _Cols; j++) {
			_Arr[i][j] = rand() % _RandMod;
		}
	}
}

// Clockwise spiral travesal
void printSpiral(int** matrix, int size) {
	int x = 0; // current position; x
	int y = 0; // current position; y
	int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
	int c = 0; // counter
	int s = 1; // chain size

	// starting point
	x = ((int)floor(size / 2.0)) - 1;
	y = ((int)floor(size / 2.0)) - 1;

	for (int k = 1; k <= (size - 1); k++) {
		for (int j = 0; j < (k < (size - 1) ? 2 : 3); j++) {
			for (int i = 0; i < s; i++) {
				std::cout << matrix[x][y] << " ";
				c++;

				switch (d) {
				case 0: ++y; break;
				case 1: ++x; break;
				case 2: --y; break;
				case 3: --x; break;
				}
			}
			d = ++d % 4;
		}
		++s;
	}
}