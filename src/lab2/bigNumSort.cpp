/**
 * @file bigNumSort.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 14/03/2024
 */
#include "quickSort.h"
#include <cstdio>
#include <cstddef>

struct BigInt {
	char* digits = nullptr;
	size_t size = 0;

	void addDigit(char digit) {
		if (size == 0) {
			digits = new char[1];
			digits[0] = digit;
			size = 1;
		} else {
			char* newDigits = new char[size + 1];
			for (size_t i = 0; i < size; i++) {
				newDigits[i] = digits[i];
			}
			newDigits[size++] = digit;
			delete[] digits;
			digits = newDigits;
		}
	}

	static bool lessThan(const BigInt* lhs, const BigInt* rhs) {
		if (lhs->size < rhs->size) {
			return true;
		} else if (lhs->size > rhs->size) {
			return false;
		} else {
			for (int i = 0; i < lhs->size; ++i) {
				if (lhs->digits[i] < rhs->digits[i]) {
					return true;
				} else if (lhs->digits[i] > rhs->digits[i]) {
					return false;
				}
			}
			return false;
		}
	}

	static bool moreThan(const BigInt* lhs, const BigInt* rhs) {
		if (lhs->size > rhs->size) {
			return true;
		} else if (lhs->size < rhs->size) {
			return false;
		} else {
			for (int i = 0; i < lhs->size; ++i) {
				if (lhs->digits[i] > rhs->digits[i]) {
					return true;
				 }else if (lhs->digits[i] < rhs->digits[i]) {
					return false;
				}
			}
			return false;
		}
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			printf("%d", digits[i]);
		}
		printf("\n");
	}

	void clear() {
		delete[] digits;
	}
};


int main() {
	int nNumbers;
	scanf("%d\n", &nNumbers);
	auto* table = new BigInt[nNumbers];

	char digit;
	for (int i = 0; i < nNumbers; ++i) {
		while ((digit = (char) getchar()) != '\n') {
			table[i].addDigit((char) (digit - '0'));
		}
	}

	quickSort(table, table+nNumbers-1, BigInt::lessThan, BigInt::moreThan);

	for (int i = 0; i < nNumbers; ++i) {
		table[i].print();
		table[i].clear();
	}
	delete[] table;
	return 0;
}