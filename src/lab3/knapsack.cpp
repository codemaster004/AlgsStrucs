#include <iostream>

using namespace std;


int max(int a, int b) {
	return a > b ? a : b;
}

int knapsack01Util(int W, const int* wt, const int* val, int n, int** dp) {
	if (n == 0 || W == 0)
		return 0;

	if (dp[n][W] != -1)
		return dp[n][W];

	if (wt[n - 1] > W)
		return dp[n][W] = knapsack01Util(W, wt, val, n - 1, dp);
	return dp[n][W] = max(val[n - 1] + knapsack01Util(W - wt[n - 1], wt, val, n - 1, dp),
	                      knapsack01Util(W, wt, val, n - 1, dp));
}

int knapsack01(int maxWeightCapacity, const int* weights, const int* rewards, int n) {
	auto* dp = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		dp[i] = new int[maxWeightCapacity + 1];
	}
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < maxWeightCapacity + 1; ++j) {
			dp[i][j] = -1;
		}
	}

	int result = knapsack01Util(maxWeightCapacity, weights, rewards, n, dp);
	for (int i = 0; i < n + 1; ++i) {
		delete[] dp[i];
	}
	delete[] dp;
	return result;
}

int retriveFromBit(int mask, const int* table) {
	int totalWeight = 0;

	int check = 1;
	int index = 0;
	while (check <= mask) {
		if (mask & check) {
			totalWeight += table[index];
		}
		index++;
		check <<= 1;
	}

	return totalWeight;
}

int knapsackTest(int combinationMask, int checkMask, const int* packeges, const int* weights, int massLimit, int currentMax) {
	int currentMask = combinationMask & ~checkMask;
	if (retriveFromBit(currentMask, weights) > massLimit) {
		int mask = 1;
		while (mask <= currentMask) {
			if ((currentMask & ~mask) == currentMask) {
				mask <<= 1;
				continue;
			}
			int result = knapsackTest(currentMask, mask, packeges, weights, massLimit, currentMax);
			currentMax = max(currentMax, result);
			mask <<= 1;
		}
		return currentMax;
	}
	return max(retriveFromBit(currentMask, packeges), currentMax);
}

int main___() {
	int n;
	while (cin >> n) {
		auto* rewards = new int[n];
		auto* weights = new int[n];
		for (int i = 0; i < n; ++i) {
			cin >> rewards[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> weights[i];
		}
		int maxWeight;
		cin >> maxWeight;


		cout << knapsack01(maxWeight, weights, rewards, n) << endl;
	}
	// for (int i = 0; i < 500; ++i) {
	// 	int n;
	// 	cin >> n;
	// 	auto* packeges = new int[n];
	// 	auto* weights = new int[n];
	// 	for (int j = 0; j < n; ++j) {
	// 		cin >> packeges[j];
	// 	}
	// 	for (int j = 0; j < n; ++j) {
	// 		cin >> weights[j];
	// 	}
	// 	int massLimit;
	// 	cin >> massLimit;
	//
	// 	int result = -1;
	//
	// 	int mask = (1 << n) - 1;
	// 	for (int i = 0; i <= mask; ++i) {
	// 		if (retriveFromBit(i, weights) <= massLimit) {
	// 			result = max(result, retriveFromBit(i, packeges));
	// 		}
	// 	}
	// 	// cout << retriveMass(mask, weights);
	// 	// int reward = knapsackTest(mask, 0, packeges, weights, massLimit, -1);
	// 	cout << result << endl;
	// 	delete[] packeges;
	// 	delete[] weights;
	// }

	return 0;
}
