/**
 * Created by Filip Dabkowski on 17/03/2024.
 */

#ifndef ALGSSTRUCS_QUICKSORTTEST_H
#define ALGSSTRUCS_QUICKSORTTEST_H

void quicksort(int arrayOfNumbers[], int start_index, int end_index) {
	if (end_index <= start_index) {
		return;
	}

	//calculating middle index
	int temp = (end_index - start_index) / 2;
	int mid_index = start_index + temp;

	int mid_index_value = arrayOfNumbers[start_index];

	//iterating through every element -> moving smaller numbers to the left, moving bigger numbers to the right
	int current_index_left = start_index;
	int current_index_right = end_index;

	while (true) {
		while (arrayOfNumbers[current_index_left] < mid_index_value) //if smaller number on the left, increase index
		{
			current_index_left++;
		}

		while (arrayOfNumbers[current_index_right] > mid_index_value) //if bigger number on the right, decrease index
		{
			current_index_right--;
		}

		//make it impossible for indexes to go on forever
		if (current_index_left < current_index_right) {
			int temp2 = arrayOfNumbers[current_index_left];
			arrayOfNumbers[current_index_left] = arrayOfNumbers[current_index_right];
			arrayOfNumbers[current_index_right] = temp2;
		} else {
			mid_index = current_index_right;
			break;
		}

		current_index_left++;
		current_index_right--;
	}

	quicksort(arrayOfNumbers, start_index, mid_index); //handle quicksort for the left side

	quicksort(arrayOfNumbers, mid_index + 1, end_index); //handle quicksort for the right side
}

#endif //ALGSSTRUCS_QUICKSORTTEST_H
