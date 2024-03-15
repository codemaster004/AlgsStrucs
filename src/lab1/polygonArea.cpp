/**
 * @file polygonArea.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 29/02/2024
 */
#include <iostream>
#include <vector>

using namespace std;


struct Point {
	int x;
	int y;
};

int det(Point& a, Point& b) {
	return a.x * b.y - b.x * a.y;
}

void calcArea() {

	// Data input.txt
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		vector <Point> points(m / 2);
		for (auto& point: points) {
			cin >> point.x >> point.y;
		}

		// Calculations
		int area = 0;
		for (int j = 0; j < points.size(); ++j) {
			int k = (j + 1) % (int) points.size();
			area += det(points[j], points[k]);
		}
		area = abs(area) / 2;
		cout << area << endl;
	}
}

//int main() {
//	calcArea();
//	return 0;
//}
