/**
 * Created by Filip Dabkowski on 14/03/2024.
 */

#ifndef ALGSSTRUCS_QUICKSORT_H
#define ALGSSTRUCS_QUICKSORT_H

template<typename T>
void quickSort(T* from, T* to,
			   bool (* lessThan)(const T*, const T*),
			   bool (* moreThan)(const T*, const T*)) {
	int length = (to - from) + 1;
	if (length <= 0)
		return;

	T* pPivot = from + length / 2;
	T* pLeft = from;
	T* pRight = to;

	T tempSwap;

	bool atPivot = false;
	while (!atPivot) {
		if (lessThan(pLeft, pPivot)) {
			pLeft++;
		} else if (moreThan(pRight, pPivot)) {
			pRight--;
		} else if (pLeft == pPivot && pRight == pPivot) {
			atPivot = true;
		} else {
			// Swap
			tempSwap = *pLeft;
			*pLeft = *pRight;
			*pRight = tempSwap;

			// Edge cases
			if (pRight == pPivot) {
				pRight--;
				pPivot = pLeft;
			} else if (pLeft == pPivot) {
				pLeft++;
				pPivot = pRight;
			} else {
				pLeft++;
				pRight--;
			}
		}
	}

	if (length > 2) {
		quickSort(from, pPivot, lessThan, moreThan);
		quickSort((pPivot + 1), to, lessThan, moreThan);
	}
}

#endif //ALGSSTRUCS_QUICKSORT_H
