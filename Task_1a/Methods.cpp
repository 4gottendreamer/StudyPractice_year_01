#include "Methods.h"

void printMatrix(int** _Arr, int _Rows, int _Cols)
{
	for (size_t i = 0; i < _Rows; i++) {
		for (size_t j = 0; j < _Cols; j++) {
			std::cout << _Arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void fillMatrix(int** _Arr, int _Rows, int _Cols, int _RandMod)
{
	for (size_t i = 0; i < _Rows; i++) {
		_Arr[i] = new int[_Cols];
		for (size_t j = 0; j < _Cols; j++) {
			_Arr[i][j] = rand() % _RandMod;
		}
	}
}