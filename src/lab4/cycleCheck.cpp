/**
 * @file cycleCheck.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 25/04/2024
 */
#include <iostream>


void inputMatrix(int matrixSize, int* adjancencyMatrix, bool& flag) {
	for (int j = 0; j < matrixSize; ++j) {
		int bitPointer = 1; // for access to certain bit of matrix
		int inserCount = 0; // count how many connections each inputted vertex has

		// enter bits for the currect row representing connections
		for (int _ = 0; _ < matrixSize; ++_) {
			if (getchar() == '1') {
				adjancencyMatrix[j] |= bitPointer;
				inserCount++;
			}
			bitPointer <<= 1;
		}
		// if vertex has less or more than  2 connections it can not be a cycyle
		if (inserCount != 2) {
			flag = false;
		}
	}
}

void checkForSymetry(int matrixSize, const int* adjancencyMatrix, bool& flag) {
	// check for symetrical matrix
	for (int j = 0; j < matrixSize; ++j) {
		if (adjancencyMatrix[j] & 1 << j) {
			flag = false;
		}
		for (int k = 0; k < j; ++k) {
			if (flag && adjancencyMatrix[j] & 1 << k && !(adjancencyMatrix[k] & 1 << j)) {
				flag = false;
			}
		}
	}
}

void checkForSingleCycle(const int* adjancencyMatrix, int matrixSize, bool& flag) {
	int prevRowColMask = 0;
	int startRow = 0;

	auto* counts = new int[matrixSize];
	for (int i = 0; i < matrixSize; ++i) {
		counts[i] = 0;
	}

	int currentRow = 0;
	for (int _ = 0; _ < matrixSize; ++_) {
		int colMask = 1;
		for (int i = 0; i < matrixSize; ++i) {
			int row = adjancencyMatrix[currentRow];
			if (colMask != prevRowColMask && row & colMask) {
				counts[currentRow] += 1;
				prevRowColMask = 1 << currentRow;
				currentRow = i;
				break;
			}
			colMask <<= 1;
		}
	}

	flag = currentRow == startRow;
	for (int i = 0; i < matrixSize; ++i) {
		if (flag && counts[i] != 1) {
			flag = false;
		}
	}

	delete[] counts;
}

int main() {
	int nExamples;
	std::cin >> nExamples;

	for (int i = 0; i < nExamples; ++i) {
		// input size of the square matrix
		int matrixSize;
		std::cin >> matrixSize;
		getchar(); // skip white character in the input

		// Allocate memery for whole adjancency matrix and fill with zeros
		auto* adjancencyMatrix = new int[matrixSize];
		for (int j = 0; j < matrixSize; ++j) {
			adjancencyMatrix[j] = 0;
		}

		bool flag = true; // if this flagg represents wheather the inputted adjancency matrix is a cycle

		// iterate over rows
		inputMatrix(matrixSize, adjancencyMatrix, flag);

		if (flag) {
			checkForSymetry(matrixSize, adjancencyMatrix, flag);
		}

		if (flag) {
			checkForSingleCycle(adjancencyMatrix, matrixSize, flag);
		}

		if (flag) {
			printf("1\n");
		} else {
			printf("0\n");
		}

		delete[] adjancencyMatrix;
	}
	return 0;
}
