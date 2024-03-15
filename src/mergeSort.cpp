/**
 * @file mergeSort.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 14/03/2024
 */


void merge(int* table, int* left, int* mid, int* right) {
	int* temp = new int[right - left + 1];

	delete[] temp;
}

void mergeSort(int* table, int* left, int* right) {
	if (right <= left) {
		return;
	}

	int* mid = left + (right - left) / 2;

	mergeSort(table, left, mid);
	mergeSort(table, mid + 1, right);

	merge(table, left, mid, right);
}

